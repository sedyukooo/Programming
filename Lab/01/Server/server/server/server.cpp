#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;
using namespace httplib;
json _json;
int unixtime = 0;
int cache_time_new = 0;
int temp = 0;
int w = 0;
json _json_cache_weth;
json _json_time;

void gen_response(const Request& req, Response& rez) {
	string str;
	ifstream l("Wid.html");                                                    //шаблон виджета 
	Client Cli("http://worldtimeapi.org");										
	auto answer = Cli.Get("/api/timezone/Europe/Simferopol");						
	if (answer) {																	
		if (answer->status == 200) {											
			_json_time = json::parse(answer->body);								//json времени
			unixtime = _json_time["unixtime"].get<int>();
		}
		else {
			cout << "Status code: " << answer->status << endl;
		}
	}
	else {
		auto Error = answer.error();
		cout << "Error code: " << Error << std::endl;
	}
	Client cli("http://api.openweathermap.org");
	auto _answer = cli.Get("/data/2.5/onecall?lat=44.952116&lon=34.102411&lang=ru&units=metric&appid=0083423f4d6d9885477d9ae0b151ab8f");
	if (_answer) {

		if (_answer->status == 200) {
			_json_cache_weth = json::parse(_answer->body);						//json погоды
			cache_time_new = _json_cache_weth["hourly"][_json_cache_weth["hourly"].size() - 1]["dt"].get<int>(); //время из полученного json погоды

			for (int i = _json_cache_weth["hourly"].size(); i > 0; --i) {
				for (int q = 0; q < _json_cache_weth["hourly"].size(); q++) {
					if (cache_time_new > unixtime and _json_cache_weth["hourly"][q]["dt"] <= cache_time_new) {   //сравнение времяени
						temp = _json_cache_weth["hourly"][q]["dt"];												
						cache_time_new = temp;
						w = q;
					}
				}

			}

		}
		else {
			cout << "Status code: " << _answer->status << endl;
		}
	}
	else {
		auto Error = _answer.error();
		cout << "Error code: " << Error << endl;
	}

	_json["description"] = _json_cache_weth["hourly"][w]["weather"][0]["description"];
	_json["temp"] = to_string(_json_cache_weth["hourly"][w]["temp"].get<int>());
	getline(l, str, '\0');
	while (str.find("{hourly[i].temp}") != std::string::npos)
		str.replace(str.find("{hourly[i].temp}"), 16, std::to_string(_json_cache_weth["hourly"][w]["temp"].get<int>()));				//замена значений в виджете
	str.replace(str.find("{hourly[i].weather[0].description}"), 34, _json_cache_weth["hourly"][w]["weather"][0]["description"]);				
	str.replace(str.find("{hourly[i].weather[0].icon}"), 27, _json_cache_weth["hourly"][w]["weather"][0]["icon"]);
	rez.set_content(str, "text/html");
}

void gen_response_raw(const Request& req, Response& rez) {
	Client("http://localhost:3000").Get("/");
	rez.set_content(_json.dump(), "text/json");
}

int main() {
	Server svr;
	svr.Get("/raw", gen_response_raw);
	svr.Get("/", gen_response);
	std::cout << "Start server... OK\n";
	svr.listen("localhost", 3000);
}
