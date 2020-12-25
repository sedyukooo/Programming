#include <iostream>
#include <locale>

using namespace std;

struct Student
{
    char name[10];
    int group;
    int exams[5];
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int count_students = 2;
    Student* stud = new Student[count_students];
    for (int i = 0; i < count_students; i++)
    {
        cout << "¬ведите фамилию и первую буква имени студента #" << i + 1 << ": ";
        cin >> stud[i].name;
        cout << endl << "¬ведите номер группы студента (целое число)#" << i + 1 << ": ";
        cin >> stud[i].group;
        cout << endl << "¬ведите результаты экзаменов по 5-ти бальной шкале #" << i + 1 << ": "; 
    }



}