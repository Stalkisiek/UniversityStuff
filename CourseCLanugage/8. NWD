#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    printf("The NWD is %d\n", a);
    return 0;
}
