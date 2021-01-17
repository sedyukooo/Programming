#include <iostream>
#include <vector>
#include <fstream>
#include <random>
using namespace std;

ostream& operator<< (ostream& print, const vector<int> vector) {
    print << vector.size() << "\t| ";
    for (auto& i : vector) print << &i << " ";
    return print << "\n";
}

int main() {
    vector<int> vect;
    ofstream file;
    file.open("datawith.txt");
    cout << file.is_open();
    if (file.is_open()) {
        for (int i = 0; i < 64; i++)
        {
            vect.push_back(rand());
            file << vect;
        }
        for (int i = 0; i < 64; i++) {
            vect.pop_back();
            file << vect;
        }
        for (int i = 0; i < 64; i++)
        {
            vect.push_back(rand());
            file << vect;
        }
        for (int i = 0; i < 64; i++) {
            vect.pop_back();
            file << vect;
        }
    }
    file.close();
}