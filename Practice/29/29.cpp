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
        cout << "������� ������� � ������ ����� ����� �������� #" << i + 1 << ": ";
        cin >> stud[i].name;
        cout << endl << "������� ����� ������ �������� (����� �����)#" << i + 1 << ": ";
        cin >> stud[i].group;
        cout << endl << "������� ���������� ��������� �� 5-�� ������� ����� #" << i + 1 << ": "; 
    }



}