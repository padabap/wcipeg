#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;
bool check(char board[9][9]);

char winner;

int main()
{
	ifstream fin ("test.in");
	int i, j, col, pos[9], row;
	string moves;
	char player, board[9][9];

for (int z=0; z<5; z++)
{
	for (i=0; i<8; i++)
		pos[i]=1;

	for (i=0; i<8; i++)
		for (j=0; j<8; j++)
			board[i][j] = '.';

	cin >> moves;

	player='R';
	for (i=0; i<moves.length(); i++)
	{
		col = int(moves[i])-48;
		row = pos[col];

		board[col][row] = player;
		pos[col]++;

		if (check(board) == true)
			break;

		if (player == 'R')
			player = 'B';
		else
			player = 'R';
	}

	if (winner == 'R')
		cout << "RED-" << i+1 << endl;
	else
		cout << "BLUE-" << i+1 << endl;
	
}
	return 0;
}

bool check(char board[9][9])
{
	int i, j;
	for (i=1; i<8; i++)
		for (j=1; j<8; j++)
		{
			if (board[i][j] == 'B' || board[i][j] == 'R')
			{
				if (board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] == board[i+3][j]) 
				{
					winner = board[i][j];
					return true;
				}
				if (board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] && board[i][j] == board[i][j+3])
				{
					winner = board[i][j];
					return true;
				}
				if (board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j] == board[i+3][j+3])
				{
					winner = board[i][j];
					return true;
				}
				if (board[i][j] == board[i-1][j+1] && board[i][j] == board[i-2][j+2] && board[i][j] == board[i-3][j+3])
				{
					winner = board[i][j];
					return true;
				}
			}
			else
				break;
		}
	return false;
}
