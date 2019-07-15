#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
/*0:空地
  1：目的的
  2：墙壁
  4：箱子
  8：玩家
  16：箱子到达目的地*/
int map[13][14] = 
  { {0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0},
    {0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0},
    {0, 2, 2, 2, 2, 0, 0, 4, 4, 2, 2, 2, 2, 2},
    {0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2},
    {0, 2, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 2},
    {0, 2, 0, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2},
    {2, 2, 2, 2, 4, 2, 2, 0, 0, 0, 0, 0, 0, 2},
    {2, 0, 0, 0, 4, 0, 2, 0, 0, 0, 8, 0, 0, 2},
    {2, 0, 4, 0, 4, 0, 2, 0, 2, 2, 2, 2, 2, 2},
    {2, 2, 0, 0, 4, 0, 2, 0 ,2, 1, 1, 1, 2, 0},
    {0, 2, 0, 2, 0, 0, 0, 0, 0, 1, 1, 1, 2, 0},
    {0, 2, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 2, 0},
    {0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0}
};
int tarPos[][2] = {
    {9, 9},
    {9, 10},
    {9, 11},
    {10, 9},
    {10, 10},
    {10, 11},
    {11, 8},
    {11, 9},
    {11, 10},
    {11, 11}
}; 
char key = 0;
int row = 0,column = 0;
int oldtype = 0;
int oldboxtype = 0;
void draw()
{
	for(int i = 0;i < sizeof(map)/sizeof(map[0]);i++)
	{
		for(int j = 0;j < sizeof(map[0])/sizeof(map[0][0]);j++)
		 {
		 	switch(map[i][j])
		 	{
		 		case 0:printf("  ");break;
		 		case 1:printf("☆");break;
		 		case 2:printf("■");break;
		 		case 4:printf("▓");break;
		 		case 8:printf("♀");row = i;column = j;break;
		 		case 16:printf("★");break;
			}
		 }
		printf("\n"); 
	}
};
void move(int r,int c)
{
	if(map[row + r][column + c] != 2)
	{
		if(map[row + r][column + c] == 4||map[row + r][column + c] == 16)
		{
			if(map[row + 2*r][column + 2*c] != 4&&map[row + 2*r][column + 2*c] != 2&&map[row + 2*r][column + 2*c] != 16)
			{
				if(map[row + r][column + c] == 16)
				{
					oldboxtype = 1;
				}
				else if(map[row + r][column + c] == 4)
				{
					oldboxtype = 0;
				}
				map[row + r][column + c] = oldboxtype;
				if(map[row + 2*r][column + 2*c] == 1)
				{
					map[row + 2*r][column + 2*c] = 16;
				}
				else
				{
					map[row + 2*r][column + 2*c] = 4;
				}
			}
			else
			{
				return;
			}
		}
		map[row][column] = oldtype;
		oldtype = map[row + r][column + c];
		map[row + r][column + c] = 8;
	}
}
void resultCheck()
{
	bool result = true;
	for(int i = 0;i < sizeof(tarPos)/sizeof(tarPos[0]);i++)
	{
		if(map[tarPos[i][0]][tarPos[i][1]] != 16)
		{
			result = false;
		}
	}
	if(result)
	{
		MessageBox(NULL,TEXT("YOU WIN"),TEXT("GAME OVER"),MB_OK);
		exit(0);
	}
}
int main()
{
	draw();
	while(true)
	{
		key = getch();
		switch(key)
		{
			case 'a':move(0,-1);break;
			case 'd':move(0,1);break;
			case 'w':move(-1,0);break;
			case 's':move(1,0);break;
		}
		resultCheck();
		system("cls");
		draw();
	}
	return 0;
}
