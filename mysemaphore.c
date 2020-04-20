#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>

static int num[1000];

sem_t sem;
void Readnum()
{
	for(int i = 0; i< 1000; i++)
	{
		printf("Read num is:%d\n",num[i]);
		sem_wait(&sem);
	}
}

void Writenum()
{
	for(int i = 0; i < 1000; i++)
	{
		num[i] = i;
		sem_post(&sem);
		printf("Write num is:%d\n",num[i]);
	}
}

int main(int argc, char const *argv[])
{
	sem_init(&sem, 0, 0);//信号量初始化
	pthread_t read, write;//创建线标识
	pthread_create(&write/*线程表示*/, NULL/*线程属性指针，缺省为NULL*/, (void*)&Writenum/*被创建线程的函数*/, NULL/*线程函数的参数*/);
	pthread_create(&read, NULL,(void*)&Readnum, NULL);
	pthread_join(write, NULL);
	/*
	pthread_create调用成功以后，新线程和老线程谁先执行，谁后执行用户是不知道的，这一块取决与操作系统对线程的调度，
	如果我们需要等待指定线程结束，需要使用pthread_join函数，这个函数实际上类似与多进程编程中的waitpid。 举个例子，
	以下假设 A 线程调用 pthread_join 试图去操作B线程，该函数将A线程阻塞，直到B线程退出，当B线程退出以后,
	A线程会收集B线程的返回码。
	*/
	pthread_join(read, NULL);
	sem_destroy(&sem);//信号量销毁
	return 0;
}