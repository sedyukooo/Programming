#pragma once

using namespace httplib;
using std::string;
using json = nlohmann::json;
using namespace std;
typedef vector<string> webhdata;

class webhook {
public:
	int h();
	int poisk(string val);
	void Send(json state, string user_id);
	void Clear(int id);
	string Get(int id);
	void Push(string val);
	void Sav();
	bool Load();
	webhdata data;
	string GetJSON();
	Hook();
private:
	const string filename = "webhooks.json";
	const string field = "WebHooks";
};

webhook;

void webhook::Send(json state, string user_id) {
	json fulljson;
	fulljson["user_id"] = user_id;
	fulljson["check"] = state;
	for (int i = 0; i < this->data.size(); i++) {
		string url = this->data.at(i);
		Client cli(url.c_str());
		cout << "Post data: " << fulljson << "\n";
		cout << "Sending state to " + url + "...";
		stringstream ss;
		ss << fulljson;
		auto res = cli.Post("/", ss.str(), "application/json");
		if (res) {
			if (res->status == 200) {
				cout << " [OK]\n";
			}
			else {
				cout << " [FAIL]\nStatus code: " << res->status << endl;
			}
		}
		else {
			cout << "[FAIL]\nError code: " << res.error() << endl;
		}
	}
}

int webhook::h() {
	return this->data.size();
}

int webhook::poisk(string val) {
	for (int i = 0; i < this->data.size(); i++) {
		if (this->data.at(i) == val) {
			return i;
		}
	}
	return -1;
}

string webhook::GetJSON() {
	json j;
	j["WebHooks"] = json::array();
	for (int i = 0; i < this->data.size(); i++) {
		j["WebHooks"].push_back(this->data[i]);
	}
	stringstream ss;
	ss << setw(2) << j;
	return ss.str();
}

void webhook::Clear(int id) {
	this->data.erase(this->data.begin() + id);
	this->Sav();
}

string webhook::Get(int id) {
	return this->data.at(id);
}

void webhook::Push(string val) {
	this->data.push_back(val);
	this->Sav();
}

void webhook::Sav() {
	ofstream os(this->filename);
	os << this->GetJSON() << endl;
	os.close();
}

bool webhook::Load() {
	ifstream is(this->filename);
	if (is) {
		json j = json::parse(is);
		for (int i = 0; i < j["WebHooks"].size(); i++) {
			this->data.push_back(j["WebHooks"][i]);
		}
		return true;
	}
	else {
		return false;
	}
	is.close();
}

webhook::webhook() {
	if (!this->Load()) {
		this->Sav();
	}
}