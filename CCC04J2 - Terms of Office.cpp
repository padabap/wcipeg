#include<iostream>
using namespace std;

int main()
{
	int x, y, curr;
	cin >> x >> y;
	curr = x;
	do
	{
		if ( (curr-x) % 60 == 0)
			cout << "All positions change in year " << curr << endl;
		curr++;
	}
	while (curr <= y);
}
