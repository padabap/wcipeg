#include<iostream>
#include<string>
using namespace std;

int main()
{
	int i, j, shift;
	string key, msg;

	getline(cin, key);
	getline(cin, msg);
	
	i=0;
	do
	{
		if ( (msg[i] < 'A') || (msg[i] > 'Z') )
			msg.erase(i, 1);
		else
			i++;
	}
	while
		(i < msg.length());

	for (i=0; i<key.length(); i++)
	{
		shift = key[i] - 'A';
		j=i;
		do
		{
			if (msg[j] + shift > 'Z')
				msg[j] = msg[j] + shift - 26;
			else
				msg[j] = (msg[j] + shift);
			j=j+key.length();
				
		}
		while 
			(j < msg.length());
	}

	cout << msg << endl;

	return 0;
}
