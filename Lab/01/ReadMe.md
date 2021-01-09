<p align="center">МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ<br>
Федеральное государственное автономное образовательное учреждение высшего образования<br>
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"<br>
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ<br>
Кафедра компьютерной инженерии и моделирования</p>
<br>
<h3 align="center">Отчёт по лабораторной работе № 1<br> по дисциплине "Программирование"</h3>
<br><br>
<p>студента 1 курса группы ИВТ-б-о-202(1)<br>
Седюко Дмитрий Витальевич<br>
направления подготовки 09.03.01 "Информатика вычесительна техника"</p>
<br><br>
<table>
<tr><td>Научный руководитель<br> старший преподаватель кафедры<br> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br><br>
<p align="center">Симферополь, 2020</p>
___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


### Цель работы:

1. Закрепить навыки разработки многофайловыx приложений.
2. Изучить способы работы с API web-сервиса.
3. Изучить процесс сериализации/десериализации данных в/из json.
4. Получить базовое представление о сетевом взаимодействии приложений.

### Постановка задачи
Разработать сервис предоставляющий данные о погоде в городе Симферополе. Источник данных о погоде: http://openweathermap.org/. В состав сервиса входит: серверное приложение на языке С++ и клиентское приложение на языке Python.

Серверное приложение предназначено для обслуживания клиентских приложений и сокращение количества запросов к сервису openweathermap.org. Сервер должен обеспечивать получение данных в формате JSON и виде html виджета.

Клиентское приложение должно иметь графический интерфейс отображающий сведения о погоде и возможность обновления данных по требованию пользователя.
### Ход работы
Для начала нам потребуется получить все необходимые запросы, к которым мы будем обращаться на сервера openweathermap.org и worldtimeapi.org. Для этого:
1. Зарегистрировался на сайте http://openweathermap.org/ . В разделе My API Keys получил свой API ключ для получения данных с сайта: **5451b8e4772aeb1df9110a2bffe2cec4**
2. Составил запрос для получения прогноза погоды: http://api.openweathermap.org//data/2.5/onecall?lat=44.952116&lon=34.102411&lang=ru&units=metric&appid=5451b8e4772aeb1df9110a2bffe2cec4

При вводе данного запроса в строку браузера получаем json ответ с нужной нам информацией о погоде (Рис. 1)

![](https://github.com/sedyukooo/Programming/blob/master/Lab/01/Pictures/01.jpg?raw=true)

3. Составил запрос для получения времени в Симферополе: http://worldtimeapi.org/api/timezone/Europe/Simferopol

При вводе данного запроса получаем json ответ с нужной нам информацией о времени (Рис. 2)

![Рис. 2 - json ответо времени](https://github.com/sedyukooo/Programming/blob/master/Lab/01/Pictures/02.jpg?raw=true)

4. Код сервера на языке С++ (Рис. 3):

```#include <iostream>
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
```

![Рис. 3 - html виджет](https://github.com/sedyukooo/Programming/blob/master/Lab/01/Pictures/03.jpg?raw=true)

5. Сделал клиенское приложение с графическим интерфейсом на языке Python (Рис. 4):



```
from tkinter import *
from tkinter.font import BOLD
import requests
import json

def reload_data(event=None):
	try:
		response = requests.get('http://localhost:3000/raw').content.decode("utf8")
		cache = json.loads(response)

		desc.config(text=str(cache["description"]))
		temp.config(text=str(cache["temp"]) + "°C")
	except requests.exceptions.ConnectionError:
		pass

root = Tk()
root.title("Погода")
root.pack_propagate()
root.bind("<Button-1>", reload_data)

top_frame =    Frame(root, bg="coral")
middle_frame = Frame(root, bg="ghost white")
bottom_frame = Frame(root, bg="coral", width=200, height=50)

top_frame.pack(side=TOP, fill=X)
middle_frame.pack(expand=True, fill=BOTH)
bottom_frame.pack(side=BOTTOM, fill=X)

city = Label(top_frame, font=("Times New Roman", 14), text="Симферополь", bg="coral")
desc = Label(top_frame, font=("Times New Roman", 14), bg="coral")
temp = Label(middle_frame, font=("Times New Roman", 48), bg="ghost white")

city.pack(pady=0)
desc.pack(pady=0)
temp.pack(expand=True)

root.mainloop()
```

![Рис. 4 - Интерфейс клиенского приложения](https://github.com/sedyukooo/Programming/blob/master/Lab/01/Pictures/04.jpg?raw=true)

### Вывод:
Разработал серверное и клиенсткое приложение, для этого использовал библиоетки json и cpp-httplib. Научился работать с API. Разобрался в сетевом взаимодействии приложений, принципе работы Req запросов.
