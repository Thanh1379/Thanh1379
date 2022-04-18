#include <stdio.h>
#include <stdlib.h>
#include <string>

#define N 16
char anpabet[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

void print(int arr[N][N]);
int itSafe(int grid[N][N], int x, int y, int num);
int solveSudoku(int grid[N][N], int x, int y);

int main()
{
    int grid[N][N];
    
    FILE *f;
    
    f = fopen("C:\\Users\\vien thanh\\Documents\\Workspace\\C Programing\\KTLT\\InputFile\\Text1.txt", "r");
    int n;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fscanf(f, "%d", &grid[i][j]);
        }
    }
    
    //print(grid);
    if (solveSudoku(grid, 0, 0) == 1)
    {
        print(grid);
    }
    else
        printf("No solution exists");
    return 0;
}

int itSafe(int grid[N][N], int x, int y, int num) {
    for (int i = 0; i <= 15; i++)
    {
        if (grid[y][i] == num)
        {
            return 0;
        }
    }

    for (int i = 0; i <= 15; i++)
    {
        if (grid[i][x] == num)
        {
            return 0;
        }
    }

    int starx = x - x % 4;
    int stary = y - y % 4;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grid[stary + i][starx + j] == num)
            {
                return 0;
            }
        }
    }

    return 1;
}

void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] > 9)
            {
                printf("%c ", anpabet[arr[i][j] % 10]);
            }
            else
                printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int solveSudoku(int grid[N][N], int x, int y)
{
    if (x == N && y == N - 1)
    {
        return 1;
    }
        
    if (x == N)
    {
        y++;
        x = 0;
    }

    if (grid[y][x] > 0)
    {
        return solveSudoku(grid, x + 1, y);
    }
    for (int num = 1; num <= N; num++)
    {
        if (itSafe(grid, x, y, num) == 1)
        {
            grid[y][x] = num;
            if (solveSudoku(grid, x + 1, y) == 1)
            {
                return 1;
            }
            
        }
        grid[y][x] = 0;
    }

    return 0;
}
