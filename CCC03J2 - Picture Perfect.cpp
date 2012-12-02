#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int num, i, max;
	while (true)
	{
		max = 0;
		cin >> num;
		if (num==0)
			break;
		else
		{
			for (i=1; i<=sqrt(double(num)); i++)
				if (num % i == 0)
					if (i > max)
						max = i;
			cout << "Minimum perimeter is ";
			cout << 2 * (max + num/max);
			cout << " with dimensions ";
			cout << max << " x " << num/max << endl;
		}
	}
	return 0;
}
