#include "bits/stdc++.h"
using namespace std;
int main()
{
	//INPUT;
	bool f = false;
	int w = 0, b = 0;
	char c[2], team_red='#',initial_team;
	while (scanf("%s",c)!=EOF)
	{
		if (c[0] != '#')
		{
			if (f==false)
			{
				initial_team = c[0];
				f = true;
			}
			int arr[4];
			for (int i = 0; i<3; i++)
			{
				scanf("%d", &arr[i]);
			}
			w += arr[0];
			b += arr[1];
			if (arr[2] == 1)
			{
				team_red = c[0];
			}
		//	
		}
		else
		{
			//printf("%d %d\n", w, b);
			/*case 1- when team 1 take all their pawns but team 2 not
			   either 2 of them cover red pawn	must */
 
			/*case 2- when team 2 take all their pawn but team 1 not
			   either 2 of them cover red pawn must */
 
			/*case 3- when none of team cover their all 9 pawns*/
 
			/*case 4- when team 1 take all their pawns but team 2 not
			   but none of them cover red pawn*/
 
			/*case 5- when team 2 take all their pawns but team 1 not
			   but none of them cover red pawn*/
 
			/*case 6- when both of them cover their all pawns and none of them 
			   cover red pawn*/
 
			/*case 7- when both of them cover their all pawns but team 1 cover red pawn*/
 
			/*case 8- when both of them cover their all pawns but team 2 cover red pawn*/
 
			/* team 1- A and C     team 2 - B and D */
			if (w == 9 && b != 9 && team_red != '#')
			{
				if (initial_team == 'A' || initial_team == 'C')
				{
					// team 1
					if (team_red == 'A' || team_red == 'C')
						printf("Team-1 win and the point is %d.\n", 9 - b + 5);
					else
					{
						printf("Team-1 win and the point is %d.\n", 9 - b);
					}
				}
				else
				{
					// team 2
					if (team_red == 'B' || team_red == 'D')
						printf("Team-2 win and the point is %d.\n", 9 - b + 5);
					else
					{
						printf("Team-2 win and the point is %d.\n", 9 - b);
					}
				}
			}
			else if (w != 9 && b == 9 && team_red != '#')
			{
				if (initial_team == 'A' || initial_team == 'C')
				{
					// team 1
					if (team_red == 'A' || team_red == 'C')
						printf("Team-2 win and the point is %d.\n", 9 - w );
					else
					{
						printf("Team-2 win and the point is %d.\n", 9 - w + 5);
					}
				}
				else
				{
					// team 2
					if (team_red == 'B' || team_red == 'D')
						printf("Team-1 win and the point is %d.\n", 9 - w);
					else
					{
						printf("Team-1 win and the point is %d.\n", 9 - w + 5);
					}
				}
			}
			else if (w != 9 && b != 9)
			{
				printf("Incomplete game.\n");
			}
			else if (w == 9 && b != 9 && team_red == '#')
			{
				printf("Incomplete game.\n");
			}
			else if (w != 9 && b == 9 && team_red == '#')
			{
				printf("Incomplete game.\n");
			}
			else if (w == 9 && b == 9 && team_red == '#')
			{
				printf("Incomplete game.\n");
			}
			else if (w == 9 && b == 9 && team_red != '#')
			{
				if (team_red == 'A' || team_red == 'C')
					printf("Team-1 win and the point is 5.\n");
				else
				{
					printf("Team-2 win and the point is 5.\n");
				}
			}
			else
			{
				printf("Incomplete game.\n");
			}
			f = false;
			w = 0, b = 0;
			team_red = '#';
		}
	}
	return 0;
} 
