//Description
//猜数字
//小A 和 小B 在玩猜数字。
//小B 每次从 1, 2, 3 中随机选择一个，
//小A 每次也从 1, 2, 3 中选择一个猜。
//他们一共进行三次这个游戏，请返回 小A 猜对了几次？

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int game(int *guess, int guessSize, int *answer, int answerSize)
// {
// 	int count = 0;
// 	for(int i = 0; i < guessSize; i++)
// 	{
// 		guess[i] = rand()%3+1;
// 		answer[i] = rand()%3+1;
// 		if(guess[i] == answer[i])
// 			count++;
// 		else
// 			continue;
// 	}
// 	return count;
// }

int game(int *guess, int guessSize, int *answer, int answerSize)
{
	int count = 0;
	int num ;
	if(guessSize != answerSize)
	{
		num = guessSize<answerSize ? guessSize:answerSize;
		for(int i =0; i<num; i++)
		{
			if(guess[i] == answer[i])
				count++;
			else
				continue;
		}
	}
	else
	{
		for(int i =0; i<guessSize; i++)
		{
			if(guess[i] == answer[i])
				count++;
			else
				continue;
		}
	}
	return count;
}

int main()
{
	srand((unsigned)time(NULL));
	int guessSize = 3;
	int guess[3]={1,2,3};
	int answerSize = 3;
	int answer[3]={1,2,3};
	int count = game(guess, guessSize, answer, answerSize);
	printf("小A：%d,%d,%d\n",answer[0],answer[1],answer[2]);
	printf("小B：%d,%d,%d\n",guess[0],guess[1],guess[2]);
	printf("小A 猜中 %d 次\n",count);
	return 0;
}