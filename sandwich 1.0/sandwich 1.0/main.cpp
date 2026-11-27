#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Sandwich {
private:
	string name;
	string myText;
	string choice;
	vector<string> ingrCousen;
	vector<string> ingr;
	static int number;

public:
	Sandwich(string name)
	{
		this->name = name;
	}

	//setters
	void AddTngredients(string choice)
	{
		ingrCousen.push_back(choice);
	}

	void GetIngr() 
	{
		ofstream MyReadFile("ingr.txt");

		while (getline(MyReadFile, myText)) {
			cout << myText;
		}

		MyReadFile.close();
	}

	void print()
	{
		cout << name;
		for (int i = 0; i < ingrCousen.size(); i++)
		{
			cout << ingrCousen[i] << '\n';
		}
	}
};

void main() {
	vector<Sandwich> sandwiches;
	string choice;
	string name;

	cout << "Sandwich Ascii assembler" << '\n';
	cout << "Create new sandwich: ";

	cin >> name;
	Sandwich sandw(name);
	sandwiches.push_back(sandw);
	cout << '\n';
	cout << "Enter ingrCousenedients : ";

	while (choice != "stop")
	{
		cin >> choice;
		sandw.AddTngredients(choice);
	}

}