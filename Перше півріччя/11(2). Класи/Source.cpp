// Source.cpp : This file contains the 'main' function. Program execution begins and ends here.
//
// Створити клас ФАКУЛЬТЕТ з наступними полями: назва, кількість студентів та прізвище декана.
// Включити в нього необхідні конструктори та методи доступу до полів класу.
// Перевантажити операції введення та виведення в потік.
// Включити функції сортування за різними критеріями та пошуку за назвою.
// Вхідні дані зчитувати з текстового файлу. Програма повинна містити меню для перевірки всіх можливостей.

#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

class Faculty {
protected:
    string name;
    int students_am;
    string surname;
public:
    Faculty() {
        name = "";
        students_am = 10000000;
        surname = "";
    }

    Faculty(string _name, int _students_am, string _surname) {
        name = _name;
        students_am = _students_am;
        surname = _surname;
    }

    Faculty(const Faculty& a) {
        name = a.name;
        students_am = a.students_am;
        surname = a.surname;
    }

    ~Faculty() {};

    friend istream& operator>>(istream& in, Faculty& a) {
        in >> a.name;
        in >> a.students_am;
        in >> a.surname;
        return in;
    }

    friend ostream& operator<<(ostream& out, Faculty& a) {
        out << "name: " << a.name << "  students_am: " << a.students_am << " surname: " << a.surname;
        return out;
    }

    friend bool operator <(const Faculty& a, Faculty b) {
        return a.students_am < b.students_am;
    }

    bool isSmallerByName(Faculty& b) {
        return getName() < b.getName();
    }

    bool isSmallerBySurname(Faculty& b) {
        return getSurname() < b.getSurname();
    }

    int getStudents_am() {
        return students_am;
    }

    string getName() {
        return name;
    }

    string getSurname() {
        return surname;
    }
};


template <typename T>
T* read_file(string file_name, int n) {
    ifstream myfile(file_name);
    if (myfile.is_open()) {
        T* c = new T[n];
        for (int i = 0; i < n; i++) {
            myfile >> c[i];
        }
        return c;
    }
    else cout << "Unable to open file";
}

void sort(Faculty* arr, int n) {
    string field;
    cout << "Enter field for sort (name, students_am, surname): ";
    cin >> field;
    if (field == "name") {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (arr[i].isSmallerByName(arr[j])) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
    else if (field == "surname") {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (arr[i].isSmallerBySurname(arr[j])) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
    else {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (arr[i] < arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
}

void search(Faculty* arr, int n) {
    string field;
    cout << "Enter field for search: ";
    cin >> field;
    bool b = false;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i].getName() == field || arr[i].getSurname() == field || to_string(arr[i].getStudents_am()) == field) {
            cout << arr[i] << "\n";
            b = true;
        }
    }
    if (!b)
        cout << "There's no such faculties\n";
}


int main()
{
    int n = 7;
    Faculty* faculties = read_file<Faculty>("Data.txt", n);
    cout << "All Faculties:\n";
    for (int i = 0; i < n; i++) {
        cout << faculties[i] << "\n";
    }

    int task;
    bool b = true;
    while (b) {
        cout << "Enter num of task:\n\t1 - sort;\n\t2 - search;\n\t3 - exit;\n";
        cin >> task;
        switch (task) {
        case 1:
            sort(faculties, n);
            for (int i = 0; i < n; i++) cout << faculties[i] << "\n";
            break;
        case 2:
            search(faculties, n);
            break;
        case 3:
            cout << "GOOD BYE\n";
            b = false;
        default:
            cout << "Wrong task num!\n";
        }
    }
}
