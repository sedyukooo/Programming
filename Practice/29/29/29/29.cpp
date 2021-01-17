#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include "bozo.hpp"
using namespace std;

struct Students {
    map<string, int> exams;
    string sName;
    int sgroup;
    Studentss(string Name, int group, int math, int phys, int hist, int prog) {
        exams = { {"math", math},{"phys", phys},{"hist", hist},{"prog", prog} };
        sName = Name;
        sgroup = group;
    }
    friend
        ostream& operator<< (ostream& print, const Students& student) {
        auto namelen = max(int(student.sName.length()), 4);
        auto del = string(namelen, '-');
        print << "+-" << del << "-+-------+------+------+------+------+\n"
            << "| Name" << :string(namelen - 4, ' ')
            << " | Group | Math | Phys | Hist | Prog |\n"
            << "+-" << del << "-+-------+------+------+------+------+\n"
            << "| " << student.sName << " |   " << student.sgroup
            << "   |  " << student.exams.at("math")
            << "   |  " << student.exams.at("phys")
            << "   |  " << student.exams.at("hist")
            << "   |  " << student.exams.at("prog") << "   |\n"
            << "+-" << del << "-+-------+------+------+------+------+\n";
        return print;
    }
    bool operator > (const Students& Deb) {
        return sName > Deb.sName;
    }
    bool operator < (const Students& Deb) {
        return sName < Deb.sName;
    }
};
ostream& operator << (ostream& print, const vector<Students>& loxi) {
    auto namelen = loxi.at(0).sName.length();
    for (auto lox = loxi.begin() + 1; lox != loxi.end(); lox++) {
        if (lox->sName.length() > namelen) {
            namelen = lox->sName.length();
        }
    }
    auto del = string(namelen, '-');
    print << "+-" << del << "-+-------+------+------+------+------+\n"
        << "| Name" << string(namelen - 4, ' ')
        << " | Group | Math | Phys | Hist | Prog |\n"
        << "+-" << del << "-+-------+------+------+------+------+\n";
    for (auto student : loxi) {
        print << "| " << student.sName << string(namelen - student.sName.length(), ' ') << " |   " << student.sgroup
            << "   |  " << student.exams.at("math")
            << "   |  " << student.exams.at("phys")
            << "   |  " << student.exams.at("hist")
            << "   |  " << student.exams.at("prog")
            << "   |\n"
            << "+-" << del << "-+-------+------+------+------+------+\n";
    }
    return print;
}
int main() {
    srand(time(0));
    vector<Students> students = {
                                    Students("WhosJoe",      1, 5, 4, 4, 3),
                                    Students("Mathue",       2, 4, 4, 3, 4),
                                    Students("JoJo",         3, 5, 5, 5, 5),
                                    Students("Damedane",     9, 1, 3, 1, 1),
                                    Students("Oama",         3, 3, 3, 3, 3),
                                    Students("Dameyo",       0, 4, 5, 4, 3),
                                    Students("BTSgay",       6, 3, 4, 3, 5),
                                    Students("Dame",         0, 3, 3, 3, 3),
                                    Students("UWUUWU",       5, 4, 3, 3, 1),
                                    Students("Dameyu",       4, 5, 2, 3, 3) };
    vector<Students> dvoeshniki;
    int kolvo = 0;
    for (auto lox : students) {
        for (auto exam : lox.exams) {
            if (exam.second == 2) {
                dvoeshniki.push_back(lox);
                kolvo += 1;
                break;
            }
        }
    }
    if (kolvo) {
        int ktoto = rand() % kolvo;
        cout << Bozosort(dvoeshniki);
        cout << "Explusion\n";
        cout << dvoeshniki[ktoto];
    }
    else {
        cout << "Not found\n";
    }
}