#include <iostream>
#include <ostream>
#include "List.h"
#include <string>
#include <inttypes.h>
#include "DoubleList.h"
using namespace std;

struct Student {
    Student() {};
    Student(string _Name, int _GroupNumber, string _EnterDate, float _Performance) : Name(_Name), GroupNumber(_GroupNumber), EnterDate(_EnterDate), Performance(_Performance) {}
    string Name;
    int GroupNumber;
    string EnterDate;
    double Performance;
    void show() {
        cout << "���: " << Name << endl << "����� ������: " << GroupNumber << endl << "���� �����������: " << EnterDate << endl << "������������: " << Performance << endl;
    }
};

int N;

int main() {

    setlocale(LC_ALL, "Russian");

    /*������� 1*/
    List<Student> l;

    string Name1;
    int GroupNumber1;
    string EnterDate1;
    double Performance1;

    cout << "������� ���������� ��������� ������: "; cin >> N;
    for (int j = 0; j < N; j++) {
        cout << "������� ���: " << endl; cin >> Name1;
        cout << "������� ����� ������: " << endl; cin >> GroupNumber1;
        cout << "������� ���� �����������: " << endl; cin >> EnterDate1;
        cout << "������� ������� ������������ (double): " << endl; cin >> Performance1;
        l.add(Student(Name1, GroupNumber1, EnterDate1, Performance1));
        system("cls");
    }

    cout << "���� ������: " << endl;
    for (int i = 0; i < N; i++) {
        l[i].show();
    }
    cout << endl;

    double max = 0.0;
    size_t index = 0;
    for (size_t i = 0; i < l.Size(); i++) {
        if (l[i].Performance >= max) {
            max = l[i].Performance;
            index = i;
        }
    }
    cout << "������� � ������������� �������������: " << endl;
    l[index].show();
    l.clear();

    /*������� 2*/
    cout << endl;
    cout << endl;
    cout << endl;
    DoubleList<float> dl;
    size_t size = 0;
    cout << "������� ������ ������: ";
    cin >> size;
    cout << "������� ������������������ �����: " << endl;

    for (size_t i = 0; i < size; i++) {
        float temp;
        cin >> temp;
        dl.pushBack(temp);
    }

    float sum = 0;
    for (size_t i = 0; i < dl.Size(); i++) {
        sum += dl[i];
    }

    cout << "������� ��������: " << sum / size << endl;

    dl.clear();
    system("pause");
    return 0;

}
