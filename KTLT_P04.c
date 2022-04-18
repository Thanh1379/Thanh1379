#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100


int chess[8][8];
int no = 0;
    int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void horse(int i, int j);
void in(int a[][8], int row, int col);
void xuat() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            printf("%2d ", chess[i][j]);
        printf("\n");
    }
    printf("\n");
}
int KT(int i, int j, int k);

int main()
{
    
    KT(0, 0, 1);
    in(chess, 8, 8);
    return 0;
}



void horse(int i, int j)
{
    ++no;
    chess[i][j] = no;
    for(int k = 0; k < 8; k++)
    {
        if(no == 64)
        {
            xuat();
            exit(0);
        }
        int u = i + x[k];
        int v = j + y[k];
        if(u >= 0 && v >= 0 && u < 8 && v < 8 && chess[u][v] == 0)
        {
            horse(u, v);
        }
    }
    
    --no;
    chess[i][j] = 0;
}
void in(int a[][8], int row, int col)
{
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int KT(int i, int j, int k)
{
    if(i >= 0 && j >= 0 && i <= 7 && j <= 7 && chess[i][j] == 0 )
    {
        chess[i][j] = k;
        if(k == 64)
        {
            in(chess, 8, 8);
            return 0;
            //exit(0);
        }
        
        if(KT(i + 1, j + 2, k + 1) == 1 &&
        KT(i + 1, j - 2, k + 1) == 1 &&
        KT(i + 2, j + 1, k + 1) == 1 &&
        KT(i + 2, j - 1, k + 1) == 1 &&
        KT(i - 1, j + 2, k + 1) == 1 &&
        KT(i - 1, j - 2, k + 1) == 1 &&
        KT(i - 2, j + 1, k + 1) == 1 &&
        KT(i - 2, j - 1, k + 1) == 1 )
        {
            chess[i][j] = 0;
        }
        
    }
    else
    {
        return 1;
    }
}