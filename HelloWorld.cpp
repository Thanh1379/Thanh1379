#include <stdio.h>

void inNhiPhan(int n);

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    inNhiPhan(n);
    
    return 0;
}

void inNhiPhan(int n)
{
    if (n > 0)
    {
        inNhiPhan(n / 2);
        printf("%d", n % 2);
    }
}