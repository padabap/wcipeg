#include<iostream>
#include<string>
using namespace std;

int main()
{
	string noun[5], adj[5];
	int n, m, i, j;
	cin >> n >> m;

	for (i=0; i<n; i++)
		cin >> adj[i];

	for (i=0; i<m; i++)
		cin >> noun[i];
	
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			cout << adj[i] << " as " << noun[j] << endl;
	return 0;
}
