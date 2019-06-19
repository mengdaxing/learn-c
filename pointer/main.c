
#include <stdio.h>

int main()
{
    int var1 = 1;
    int *ip = &var1;

    printf("%p\n", &var1);
    printf("%p\n", ip);

    return 0;
}
