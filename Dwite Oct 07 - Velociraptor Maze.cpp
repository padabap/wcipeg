#include<cstdio>
#include<queue>
using namespace std;
 
int main()
{
        int r, c, hx, hy, ex, ey, vx, vy, x, y, i, j, count=0; //h=human, e=exit
        char grid[11][11];
		int dist[11][11], dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};
        queue < pair<int, int> > Q;
		bool checkv=false, checkh=false;
 
        for (i=0; i<11; i++)
                for (j=0; j<11; j++)
                {
                        dist[i][j] = 9999;
                        grid[i][j] = '#';
                }
 
       // freopen("test.in", "r", stdin);
        scanf("%d%d", &r, &c);
        for (i=1; i<=r; i++)
        {
                scanf("\n");
                for (j=1; j<=c; j++)               
                {
                        scanf("%c", &grid[i][j]);              
                        if (grid[i][j] == 'H')
                                {
                                        hx = i; hy = j;
                                }
                        else if (grid[i][j] == 'E')
                                {
                                        ex = i; ey = j;
                                }
                        else if (grid[i][j] == 'V')
                                {
                                        vx = i; vy = j;
                                }                      
                }
        }
 
        Q.push(make_pair(ex, ey));
        dist[ex][ey]=0;
        while (!Q.empty())
        {
                x=Q.front().first;
                y=Q.front().second;
                Q.pop();

				for (i=0; i<4; i++)
				{
					if (grid[x+dx[i]][y+dy[i]]!='#')
						if (dist[x+dx[i]][y+dy[i]]==9999)
                        {
                                dist[x+dx[i]][y+dy[i]]=dist[x][y]+1;
                                Q.push(make_pair(x+dx[i], y+dy[i]));
                        }  
				}
		}

		//simulation. 
		while (!(vx == ex && vy == ey && hx==ex && hy==ey))
		{
			count++; //counts h steps
			checkh = false; //checks if we already moved in that time slot
			checkv = false;
			for (i=0; i<4; i++)
			{			
				if (dist[vx+dx[i]][vy+dy[i]] == dist[vx][vy]-1 && checkv==false)
				{
					vx=vx+dx[i];
					vy=vy+dy[i];
					checkv=true; //we move in time slot, will not move again
				}
				if (dist[hx+dx[i]][hy+dy[i]] == dist[hx][hy]-1 && checkh==false)
				{
					hx=hx+dx[i];
					hy=hy+dy[i];
					checkh=true;
				}
			}
			if (hx==vx && hy==vy)
			{
				printf("%d\n", count);
				break;
			}
			else if (hx==ex && hy==ey)
			{
				printf("escape\n");
				break;
			}
			for (i=0; i<4; i++)
			{			
				if (dist[vx+dx[i]][vy+dy[i]] == dist[vx][vy]-1)
				{
					vx=vx+dx[i];
					vy=vy+dy[i];
				}
			}
			if (hx==vx && hy==vy)
			{
				printf("%d\n", count);
				break;
			}
		}
        return 0;
}
