#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

struct Human 
{
	string surname;
	string name;
	string address;

	Human(string _surname = "unknown", string _name = "unknown", string _address = "unknown")
	{
		surname = _surname;
		name = _name;
		address = _address;
	}

	void setSurname(string _surname)
	{
		surname = _surname;
	}

	friend istream& operator>>(istream& in, Human& human)
	{
		in >> human.surname >> human.name;
		getline(in, human.address, '.');
		return in;
	}

	friend ostream& operator<<(ostream& out, const Human& human)
	{
		out << "Surname: " << human.surname << "; Name: " << human.name << "; Address: " << human.address << endl;
		return out;
	}

	friend bool operator<(const Human& human1, const Human& human2)
	{
		return human1.surname < human2.surname;
	}

};

struct PhoneNumber
{
	string phone_number;

	PhoneNumber(string _phone_number = "+380000000000")
	{
		phone_number = _phone_number;
	}

	friend istream& operator>>(istream& in, PhoneNumber& human)
	{
		in >> human.phone_number;
		return in;
	}

	friend ostream& operator<<(ostream& out, const PhoneNumber& human)
	{
		out << human.phone_number << endl;
		return out;
	}
};

bool isHere(string temp_address, string* address_array, size_t value) 
{
	bool result = false;

	for (size_t i = 0; i < value; i++)
	{
		if (temp_address == address_array[i])
		{
			result = true;
		}
	}

	return result;
}

string* push(string temp_address, string* address_array, size_t value)
{
	string* updated_address_arr = new string[value];

	for (size_t i = 0; i < value; i++)
	{
		updated_address_arr[i] = address_array[i];
	}

	for (size_t i = 0; i < value; i++)
	{
		if (updated_address_arr[i] == "")
		{
			updated_address_arr[i] = temp_address;
			break;
		}
	}

	return updated_address_arr;
}

void main()
{
	fstream in("Data.txt");
	fstream out("Rezult.txt");
	multimap <Human, PhoneNumber> phone_book;

	size_t valur;
	in >> valur;
	for (size_t i = 0; i < valur; i++)
	{
		Human person;
		PhoneNumber phone_number;
		in >> person;
		in >> phone_number;
		phone_book.insert(make_pair(person, phone_number));
	}

	typedef multimap<Human, PhoneNumber>::iterator I;

	cout << "Enter surname: ";
	string temp_surname;
	cin >> temp_surname;
	Human temp_person;
	temp_person.setSurname(temp_surname);
	pair<I, I> temp_pair = phone_book.equal_range(temp_person.surname);
	for (I i = temp_pair.first; i != temp_pair.second; i++) 
	{
		out << i->second;
	}

	string* address_arr = new string[valur];
	for (size_t i = 0; i < valur; i++)
	{
		address_arr[i] = "";
	}

	string temp_address = "";
	for (auto& i : phone_book)
	{
		temp_address = i.first.address;
		if (!isHere(temp_address, address_arr, valur))
		{
			address_arr = push(temp_address, address_arr, valur);
		}
	}

	size_t counter = 0;
	for (size_t i = 0; i < valur; i++)
	{
		if (address_arr[i] != "")
		{
			counter = 0;
			for (auto& j : phone_book)
			{
				if (j.first.address == address_arr[i]) 
				{
					counter++;
				}
			}
			out << address_arr[i] << ": " << counter << endl;
		}
	}
	cout << "Enter phone number: ";
	string temp_phone_number;
	cin >> temp_phone_number;

	for (auto& i : phone_book)
	{
		if (i.second.phone_number == temp_phone_number) 
		{
			out << i.first;
		}
	}
}