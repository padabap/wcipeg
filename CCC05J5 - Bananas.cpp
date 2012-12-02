#include<iostream>
#include<string>
using namespace std;

bool monkey(string x);
bool a(string y);

bool a(string y)
{
	if (y=="A")
		return true;
	else if (y[0]=='B' && y[y.length()-1]=='S' && monkey(y.substr(1, y.length()-2))==true)
		return true;
	else
		return false;
}

bool monkey(string x)
{
	if (a(x)==true)
		return true;
	else
	{
		for (int i=0; i<x.length(); i++)
			if (x[i] == 'N')
				if (a(x.substr(0, i))==true && monkey(x.substr(i+1))==true)
					return true;
	}
	return false;
}

int main()
{
	string word;
	while(1)
	{
		cin >> word;
		if (word == "X")
			break;
		if (monkey(word) == true)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
