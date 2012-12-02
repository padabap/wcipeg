#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream fin ("test.in");

	int n, i, z, count=0;
	double m, x[101], y[101], p1x, p1y, p2x, p2y;
	bool undef=0;

	cin >> n;
	for (i=0; i<n; i++)	
		cin >> x[i] >> y[i];

	for (z=1; z<=5; z++)
	{
		count = 0;
		undef = false;

		cin >> p1x >> p1y >> p2x >> p2y;

		if (p1x == p2x)
			undef = true;
		else
			m = (p2y - p1y) / (p2x - p1x);

		for (i=0; i<n; i++)
		{
			if (undef == true)
			{
				if (x[i] == p1x)
					count ++;
			}
			else if ((m * (x[i] - p1x)) == (y[i] - p1y))
				count++;
		}	

		cout << count << endl;
	}

	return 0;
}
