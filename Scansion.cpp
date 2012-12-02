#include<iostream>
#include<string>
#include<cstring>
using namespace std;

	string line;
	string feet[19]={"00", "01", "10", "11", "000", "001", "010", "011", "100", "101", "110", "111", "0001", "0010", "0011", "0100", "0110", "1000", "1001"};
	int a[10001], y;

int main()
{
	memset(a, 0, sizeof(a));
	a[0]=1;
	cin >> line;

	for (int x=1; x<=line.length(); x++)
		for (int i=0; i<19; i++)
		{
			y = feet[i].length();
			if (y>x)
				break;
			if (line.substr(x-y, y)==feet[i])
				a[x] = (a[x] + a[x-y]) % 10007;
		}

		cout << a[line.length()] << endl;
	return 0;
}
/*
go(001001)

go(0010) + go(001) + go(00)


go(0010)
=go(00) + go('') */
