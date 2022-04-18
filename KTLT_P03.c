#include <stdio.h>
#include <math.h>

#define MAX 100
#define breakline printf("\n--------------------------------------\n");
int chess[MAX], no = 1;

void nQueen(int k, int n);
int canPlace(int k, int i);
void screen(int n);

int main()
{
    int n = 8;

    nQueen(1, n);

    return 0;
}

void nQueen(int k, int n)
{
    for(int i = 1; i <= n; i++)//hàng n = 8 => 8 hàng
    {
        if(canPlace(k, i) == 1)
        {
            chess[k] = i;
            if(k == n)
            {
                screen(n);
            }
            else
                nQueen(k + 1, n);
        }
    }
}

int canPlace(int k, int i)
{
    for(int j = 1; j <= k - 1; ++j)
    {
        if((chess[j] == i) || (abs(j - k) == abs(chess[j] - i)))
        {
            return 0;
        }
    }
    return 1;
}

void screen(int n)
{
    breakline;
    printf("Truong hop %d\n", no++);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(chess[j] == i)
            {
                printf("\tQ");
            }
            else
                printf("\t_");
        }
        printf("\n");
    }
    breakline;
}