
//  Ввести речення string_main, яке розбити на дві стрічки string1 і string2 за таким правилом:
// в першу записати всі символи менші k, а в другу - більші. Значення k ввести з клавіатури.

#include<iostream>
#include<random>
#include <string>

using namespace std;

void splitStr(string string_main, string string1, string string2, char element_k);

int main()
{
    string string_main;
    string string1 = "";
    string string2 = "";
    char element_k;
    
    cout << "Enter main string :  ";
    getline(cin, string_main);

    cout << "Enter k element : ";
    cin >> element_k;

    cout << "\n\n\n";

    splitStr(string_main, string1, string2, element_k);
}

void splitStr(string string_main, string string1, string string2, char element_k)
{
    for (char i : string_main)
    {
        if (tolower(i) < element_k)
        {
            string1 += i;
        }
        else
        {
            string2 += i;
        }
    }
    cout << "String 1 is ->    " << string1 << endl;
    cout << "String 2 is ->    " << string2 << endl;
}