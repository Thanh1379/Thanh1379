#include "stdio.h"
#include "math.h"
#include "ctype.h"

typedef struct 
{
    int tt[2];
    int dp[2];
}pixel;

void in(int gra[100][100], int n);
int solveArea(pixel *rec, int n);
void movexy(pixel *rec, int n, int *minx, int *maxx, int *miny, int *maxy);
void addx(pixel *rec, int n, int agu);
void addy(pixel *rec, int n, int agu);
void in1(pixel *rec, int n);

int main()
{
    FILE *f;
    
    f = fopen("C:\\Users\\vien thanh\\Documents\\Workspace\\C Programing\\KTLT\\InputFile\\Text1.txt", "r");
    int n;
    
    fscanf(f, "%d", &n);
    printf("%d ", n);
    pixel rec[n];
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            fscanf(f, "%d", rec[i].tt + j);
        }
        for (int j = 0; j < 2; j++)
        {
            fscanf(f, "%d", rec[i].dp + j);
        }
    }
    int minx = rec[0].tt[0], miny = rec[0].tt[1], maxx = rec[0].tt[0], maxy = rec[0].tt[1];
    
    //Tìm MIN MAX
    for (int i = 0; i < n; i++)
    {
        int temp1 = 0, temp2 = 0;
        temp1 = rec[i].tt[0];
        if (maxx < temp1)
        {
            maxx = temp1;
        }
        if (minx > temp1)
        {
            minx = temp1;
        }
        temp1 = rec[i].tt[1];
        if (maxy < temp1)
        {
            maxy = temp1;
        }
        if (miny > temp1)
        {
            miny = temp1;
        }
        temp2 = rec[i].dp[0];
        if (maxx < temp2)
        {
            maxx = temp2;
        }
        if (minx > temp2)
        {
            minx = temp2;
        }
        temp2 = rec[i].dp[1];
        if (maxy < temp2)
        {
            maxy = temp2;
        }
        if (miny > temp2)
        {
            miny = temp2;
        }
    }
    //thử nghiệm
    // maxx = 10;
    // maxy = 9;
    // miny = -2;

    in1(rec, n);
    printf("\n%d %d %d %d\n", maxx, minx, maxy, miny);
    movexy(rec, n, &minx, &maxx, &miny, &maxy);
    printf("\n%d %d %d %d\n", maxx, minx, maxy, miny);
    
    int gra[100][100] = {0};

    for (int p = 0; p < n ; p++)
    {
        for (int i = miny; i < maxy; i++)
        {
            for (int j = minx; j < maxx; j++)
            {
                if(gra[i][j] == 0 && (i >= rec[p].dp[1]) && (i < rec[p].tt[1]) && (j >= rec[p].tt[0]) && (j < rec[p].dp[0]))
                {
                    gra[i][j] = 1;
                }
            }
            
        }
    }
    int area = 0;

    for (int i = miny; i < maxy; i++)
    {
        for (int j = minx; j < maxx; j++)
        {
            if(gra[i][j] == 1)
                area += 1;
        }
    }
    printf("%d", area);
    in(gra, 30);
    in1(rec, n);
    printf("%d ", solveArea(rec, 2));
    fclose(f);

    return 0;
}

void in(int gra[100][100], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", gra[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void in1(pixel *rec, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
           printf("%d ", rec[i].tt[j]);
        }
        for (int j = 0; j < 2; j++)
        {
           printf("%d ", rec[i].dp[j]);
        }
        printf("\n");
    }
    printf("\n");
}

int solveArea(pixel *rec, int n)
{
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        area += (abs(rec[i].dp[1] - rec[i].tt[1]) * abs(rec[i].dp[0] - rec[i].tt[0]));
    }
    return area;
}

void movexy(pixel *rec, int n, int *minx, int *maxx, int *miny, int *maxy)
{
    int temp;
    if(*minx < 0)
    {
        temp = *minx;
        addx(rec, n, temp);
        *minx = 0;
        (*maxx) += abs(temp);
        
    }
    if(*miny < 0)
    {
        temp = *miny;
        addy(rec, n, temp);
        *miny = 0;
        (*maxy) += abs(temp);
    }
}

void addx(pixel *rec, int n, int agu)
{
    for (int i = 0; i < n; i++)
    {
        rec[i].tt[0] += abs(agu);
        rec[i].dp[0] += abs(agu);
    }
    
}

void addy(pixel *rec, int n, int agu)
{
    for (int i = 0; i < n; i++)
    {
        rec[i].tt[1] += abs(agu);
        rec[i].dp[1] += abs(agu);
    }
    
}