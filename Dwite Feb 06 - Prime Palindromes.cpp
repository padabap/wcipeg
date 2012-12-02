#include<iostream>
#include<math.h>
using namespace std;
bool palindrome(int x);
bool prime(int x);

int main()
{
	int l, u, i, count=0, z;
for (z=0; z<5; z++)
{
	count = 0;
	cin >> l >> u;

	for (i=l; i<=u; i++)
		if (palindrome(i) == true && prime(i) == true) 
			count++;

	cout << count << endl;
}
	return 0;
}

bool palindrome(int x)
{
	int dig[7], i=0, j=0;
	
	if (x == x % 10)
		return true;

	do
	{
		dig[i] = x % 10;
		x = x / 10;
		i++;
	}
	while (x != x % 10);
	dig[i] = x;

	do
	{
		if (dig[j] != dig[i])
			return false;
		i--;
		j++;
	}
	while (j <= i);

	return true;

}
bool prime(int x)
{
	int i, factors=0;
	for (i=2; i<=sqrt(double(x)); i++)
	{
		if (x % i == 0)
			factors++;
	}
	if (factors == 0)
		return true;
	else
		return false;
}
