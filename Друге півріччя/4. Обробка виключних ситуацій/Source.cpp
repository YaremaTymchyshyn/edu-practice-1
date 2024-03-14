#include <iostream>
#include <map>
#include <vector>
#include <Windows.h>
#include <stdexcept>
#include <string>
using namespace std;

map<string, string> months = {
	{"01", "ѳ���"},
	{"02", "������"},
	{"03", "�������"},
	{"04", "�����"},
	{"05", "������"},
	{"06", "������"},
	{"07", "�����"},
	{"08", "������"},
	{"09", "�������"},
	{"10", "������"},
	{"11", "���������"},
	{"12", "������"}
};

string convertToDate(string date)
{
	vector<string> words;
	string temporary = "";
	if (date.length() != 10)
	{
		throw invalid_argument("received bad value");
	}
	for (const char i : date)
	{
		if (i != '/')
			temporary += i;
		else
		{
			words.push_back(temporary);
			temporary = "";
		}
	}
	words.push_back(temporary);
	if (stoi(words[0]) > 31 || stoi(words[0]) < 1 || stoi(words[1]) > 12 || stoi(words[1]) < 1 || stoi(words[2]) < 1
		|| (stoi(words[0]) > 28 && words[1] == "02"))
	{
		throw invalid_argument("received bad value");
	}

	string result = words[0] + " " + months[words[1]] + " " + words[2] + "�.";


	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		//cout << convertToDate("");
		cout << convertToDate("20/09/2022") << endl;
		cout << convertToDate("28/02/2022") << endl;
		//cout << convertToDate("01/04/0000") << endl;
		cout << convertToDate("10/13/2022") << endl;
	}
	catch (const std::invalid_argument& e)
	{
		cout << "Error invalid arguments! Try again!";
	}
	catch (...)
	{
		cout << "Unknown error was occupied!";
	};
}