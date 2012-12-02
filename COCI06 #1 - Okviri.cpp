#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	string x;
	int i;
	cin >> x;
	
	for (i=0; i<x.length(); i++)
	{
		if ((i+1) % 3 != 0)
			cout << "..#.";
		else
			cout << "..*.";
	}
	cout << '.' << endl;

	for (i=0; i<x.length(); i++)
	{
		if ((i+1) % 3 != 0)
			cout << ".#.#";
		else
			cout << ".*.*";
	}
	cout << '.' << endl;

	for (i=0; i<x.length(); i++)
	{
		if ((i+1) % 3 != 0)
		{
			if (i % 3 == 0 && i != 0)
				cout << "*." << x[i] << ".";
			else
				cout << "#." << x[i] << ".";
		}
		else
			cout << "*." << x[i] << ".";
	}
	if (x.length() % 3 != 0)
		cout << '#';
	else
		cout << '*';
	cout << endl;

	for (i=0; i<x.length(); i++)
	{
		if ((i+1) % 3 != 0)
			cout << ".#.#";
		else
			cout << ".*.*";
	}
	cout << '.' << endl;

	for (i=0; i<x.length(); i++)
	{
		if ((i+1) % 3 != 0)
			cout << "..#.";
		else
			cout << "..*.";
	}
	cout << '.' << endl;
	return 0;
}
