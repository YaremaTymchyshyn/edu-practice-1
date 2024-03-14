#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class institution
{
protected:
	string name;
	string adress;
	int number;
public:
	institution(string name = "name", string adress = "adress", int num = 0) : name(name), adress(adress), number(num){}
	institution(const institution& inst) : name(inst.name), adress(inst.adress), number(inst.number){}



	string GetName()
	{
		return name;
	}
	void SetName(string n)
	{
		name = n;
	}

	string GetAdress()
	{
		return adress;
	}
	void SetAdress(string a)
	{
		adress = a;
	}

	int GetNumber()
	{
		return number;
	}
	void SetNumber(int m)
	{
		number = m;
	}



	virtual void insert(istream& in)
	{
		in >> name >> adress >> number;
	}
	virtual void print(ostream& out) const
	{
		out << "Institution: " << name << ' ' << adress << ' ' << number << endl;
	}



	friend istream& operator>>(istream& in, institution& inst)
	{
		in >> inst.name >> inst.adress >> inst.number;
		return in;
	}
	friend ostream& operator<<(ostream& out, const institution& inst)
	{
		inst.print(out);
		return out;
	}
};



class school : public institution
{
protected:
	string director;
	int NumberOfPupils;
public:
	school(string name = "name", string adress = "adress", int num = 0, string director = "director", int NumOfPupils = 0) : institution(name, adress, num), director(director), NumberOfPupils(NumOfPupils){}
	school(const school& sch) : institution(sch), director(sch.director), NumberOfPupils(sch.NumberOfPupils){}



	string GetDirector()
	{
		return director;
	}
	void SetDirector(string d)
	{
		director = d;
	}

	int GetNumberOfPupils()
	{
		return NumberOfPupils;
	}
	void SetNumberOfPupils(int p)
	{
		NumberOfPupils = p;
	}



	void insert(istream& in)
	{
		institution::insert(in);
		in >> director >> NumberOfPupils;
	}
	void print(ostream& out)
	{
		out << "School: ";
		institution::print(out);
		out << director << ' ' << NumberOfPupils << endl;
	}



	friend istream& operator>>(istream& in, school& sch)
	{
		in >> sch.name >> sch.adress >> sch.number >> sch.director >> sch.NumberOfPupils;
		return in;
	}
};



class university : public institution
{
protected:
	string rector;
	int NumberOfStudents;
public:
	university(string name = "name", string adress = "adress", int num = 0, string rector = "rector", int NumOfStudents = 0) : institution(name, adress, num), rector(rector), NumberOfStudents(NumOfStudents){}
	university(const university& uni) : institution(uni), rector(uni.rector), NumberOfStudents(uni.NumberOfStudents){}



	string GetRector()
	{
		return rector;
	}
	void SetRector(string r)
	{
		rector = r;
	}

	int GetNumberOfStudents()
	{
		return NumberOfStudents;
	}
	void SetNumberOfStudents(int s)
	{
		NumberOfStudents = s;
	}



	void insert(istream& in)
	{
		institution::insert(in);
		in >> rector >> NumberOfStudents;
	}
	void print(ostream& out)
	{
		out << "University: ";
		institution::print(out);
		out << rector << ' ' << NumberOfStudents << endl;
	}



	friend istream& operator>>(istream& in, university& uni)
	{
		in >> uni.name >> uni.adress >> uni.number >> uni.rector >> uni.NumberOfStudents;
		return in;
	}
};



int main()
{
	ifstream file;
	file.open("text.txt");
	int k;
	file >> k;

	institution** inst = new institution * [k];

	for (int i = 0; i < k; ++i)
	{
		char type;
		file >> type;
		if (type == 'S')
		{
			inst[i] = new school;
			inst[i]->insert(file);
		}
		else if (type == 'U')
		{
			inst[i] = new university;
			inst[i]->insert(file);
		}
	}

	for (int i = 0; i < k; ++i)
	{
		cout << *inst[i];
	}

	cout << "\nSorted by number:\n\n";
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < k - 1 - i; ++j)
		{
			if (inst[j]->GetNumber() > inst[j + 1]->GetNumber())
			{
				swap(inst[j], inst[j + 1]);
			}
		}
	}

	for (int i = 0; i < k; ++i)
	{
		cout << *inst[i];
	}

	cout << "\nSorted by name:\n\n";
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < k - 1 - i; ++j)
		{
			if (inst[j]->GetName() > inst[j + 1]->GetName())
			{
				swap(inst[j], inst[j + 1]);
			}
		}
	}

	for (int i = 0; i < k; ++i)
	{
		cout << *inst[i];
	}

	cout << "\nSorted by adress:\n\n";
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < k - 1 - i; ++j)
		{
			if (inst[j]->GetAdress() > inst[j + 1]->GetAdress())
			{
				swap(inst[j], inst[j + 1]);
			}
		}
	}

	for (int i = 0; i < k; ++i)
	{
		cout << *inst[i];
	}

	return 0;
}