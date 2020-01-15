#include <stdio.h>

void SwapTwoNumbers(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int a = 10;
	int b = 11;
	printf("Before swape the two numbers is a=%d b= %d \n", a, b);
	SwapTwoNumbers(&a, &b);
	printf("Now the two numbers is a=%d b= %d \n", a, b);
	return 0;
}
