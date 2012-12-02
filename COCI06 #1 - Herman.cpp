#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	const double pi = 3.141592654;
	double r;
	cin >> r;
	cout << setiosflags(ios::fixed) << setprecision(6) << pi * r * r << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << r * 2 * r << endl;
	return 0;
}
