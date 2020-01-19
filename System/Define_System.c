#include <stdio.h>

int main()
{
#ifdef __x86_64__
    printf("This is x86_64 System \n");
#endif
#ifdef __i386__
    printf("This is __i386__ System \n");
#endif
    return 0;
}

