#include<iostream>
using namespace std;

int main()
{
	int dice, square = 1;
	do
	{
		cin >> dice;
		if (dice == 0)
			cout << "You Quit!" << endl;
		else if (square + dice == 100)
		{
			cout << "You are now on square 100" << endl;
			cout << "You Win!" << endl;
		}
		else if (square + dice < 100)
		{
			square = square + dice;
			if (square == 54)
				square = 19;
			else if (square == 90)
				square = 48;
			else if (square == 99)
				square = 77;
			else if (square == 9)
				square = 34;
			else if (square == 40)
				square = 64;
			else if (square == 67)
				square = 86;
			cout << "You are now on square " << square << endl;
		}
		else
			cout << "You are now on square " << square << endl;
	}
	while ((dice != 0) && (dice+square != 100));
	return 0;
}
