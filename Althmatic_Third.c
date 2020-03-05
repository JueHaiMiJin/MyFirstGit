//力扣团队买了一个可编程机器人，机器人初始位置在原点(0, 0)。小伙伴事先给机器人输入一串指令command，机器人就会无限循环这条指令的步骤进行移动。指令有两种：

//U: 向y轴正方向移动一格
//R: 向x轴正方向移动一格。
//不幸的是，在 xy 平面上还有一些障碍物，他们的坐标用obstacles表示。机器人一旦碰到障碍物就会被损毁。

//给定终点坐标(x, y)，返回机器人能否完好地到达终点。如果能，返回true；否则返回false。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool robot(char* command, int **obstacles, int obstaclesSize, int *obstaclesColSize, int x, int y)
{
	int R_x = 0;
	int R_y = 0;
	int flag = 1;
	int command_lenth = strlen(command);
	while(1)
	{
		int i =0;
		for ( i = 0; i < command_lenth; ++i)
		{
			if('U' == command[i])
				R_x++;
			else
				R_y++;
			if(R_x == obstacles[0][0] || R_y == obstacles[0][1])
			{
				return false;
			}
		}
		if(R_x == x && R_y == y)
			return true;
		if(R_x > x || R_y > y)
			return false;
	}
}

int main()
{
	char *command="URR";
	int obstacles[1][2]={{2,2}};
	int x = 3;
	int y = 2;
	robot(command,obstacles,)
	return 0;
}