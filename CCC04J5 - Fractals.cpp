#include<iostream>
using namespace std;

int main()
{
	int level, width, z, num_old, num_new, i, j, x, third;
	int oldx[1000], oldy[10000], newx[10000], newy[10000];
	bool output[10000]={0};

	cin >> level >> width >> x;

	oldx[0]=0;		oldy[0]=1;
	oldx[1]=width;	oldy[1]=1;

	num_old = 2;

	for (z=0; z<level; z++)
	{
		newx[0]=oldx[0];
		newy[0]=oldy[0];
		num_new=1;

		for (i=0; i<num_old-1; i++)
		{
			third = (oldx[1] - oldx[0]) / 3;
			if (oldy[i] == oldy[i+1]) //if horizontal line
			{
				if (oldx[i] < oldx[i+1]) //if line goes left to right
				{					
					newx[num_new] = third + oldx[i];
					newy[num_new] = oldy[i];
					num_new = num_new + 1;

					newx[num_new] = third + oldx[i];
					newy[num_new] = third + oldy[i];
					num_new = num_new + 1;

					newx[num_new] = 2*third + oldx[i];
					newy[num_new] = third + oldy[i];
					num_new++;

					newx[num_new] = 2*third + oldx[i];
					newy[num_new] = oldy[i];
					num_new++;

					newx[num_new] = 3*third + oldx[i];
					newy[num_new] = oldy[i];
					num_new++;
				}
				else //line goes right to left
				{
					newx[num_new] = oldx[i] - third;
					newy[num_new] = oldy[i];
					num_new++;

					newx[num_new] = oldx[i] - third;
					newy[num_new] = oldy[i] - third;
					num_new++;

					newx[num_new] = oldx[i] - 2*third;
					newy[num_new] = oldy[i] - third;
					num_new++;

					newx[num_new] = oldx[i] - 2*third;
					newy[num_new] = oldy[i];
					num_new++;

					newx[num_new] = oldx[i] - 3*third;
					newy[num_new] = oldy[i];
					num_new++;
				}
			}
			else //vertical line
			{
				if (oldy[i] < oldy[i+1]) //line goes down to up
				{					
					newx[num_new] = oldx[i];
					newy[num_new] = third + oldy[i];
					num_new = num_new + 1;

					newx[num_new] = oldx[i] - third;
					newy[num_new] = third + oldy[i];
					num_new = num_new + 1;

					newx[num_new] = oldx[i] - third;
					newy[num_new] = 2*third + oldy[i];
					num_new++;

					newx[num_new] = oldx[i];
					newy[num_new] = 2*third + oldy[i];
					num_new++;

					newx[num_new] = oldx[i];
					newy[num_new] = 3*third + oldy[i];
					num_new++;
				}
				else //line goes up to down
				{					
					newx[num_new] = oldx[i];
					newy[num_new] = oldy[i] - third;
					num_new = num_new + 1;

					newx[num_new] = oldx[i] + third;
					newy[num_new] = oldy[i] - third;
					num_new = num_new + 1;

					newx[num_new] = oldx[i] + third;
					newy[num_new] = oldy[i] - 2*third;
					num_new++;

					newx[num_new] = oldx[i];
					newy[num_new] = oldy[i] - 2*third;
					num_new++;

					newx[num_new] = oldx[i];
					newy[num_new] = oldy[i] - 3*third;
					num_new++;
				}
			}
		}

		for (i=0; i<num_new; i++)
		{
			oldx[i]=newx[i];
			oldy[i]=newy[i];
			num_old = num_new;
		}
	}

	//find all y coordinates for x coordinate
	//loop through my "end" points
	for (i=0; i<num_old-1; i++)
		if (oldy[i] == oldy[i+1]) //if horizontal line
		{
			if (oldx[i] < oldx[i+1]) //if line goes left to right
			{
				if (x >= oldx[i] && x <= oldx[i+1])
					//if (output[oldy[i]] == 0)
					{
						//cout << oldy[i] << ' ';
						output[oldy[i]] = 1;
					}
			}
			else
			{
				if (x <= oldx[i] && x >= oldx[i+1])
					//if (output[oldy[i]] == 0)
					{
						//cout << oldy[i] << ' ';
						output[oldy[i]] = 1;
					}
			}
		}
		else //if vertical line
		{
			if (x == oldx[i])
			{/*
				//if (output[oldy[i]] == 0)
				{
					//cout << oldy[i] << ' ';
					output[oldy[i]] = 1;
				}
				//if (output[oldy[i+1]] == 0)
				{
					//cout << oldy[i+1] << ' ';
					output[oldy[i+1]] = 1;
				} */

				for (j=oldy[i]; j<=oldy[i+1]; j++)
					output[j] = 1;
			}
		}

	for (i=0; i<1000; i++)
		if (output[i] == 1)
			cout << i << ' ';

	//for (i=0; i<num_new; i++)
		//cout << newx[i] << ' ' << newy[i] << ' ' << endl;

	return 0;
}
