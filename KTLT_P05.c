#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100001

float lai_kep(float y, int n);
void  input(int  Q[],  int  *n);
void output(int Q[], int n);
long  sum_rec(int  Q[],  int  n);
int  max_rec(int  Q[],  int  n);
int min_rec(int Q[], int n);
long  sum(int  Q[],  int  n);
int GetRandom(int min,int max);

int main()
{
    int Q[MAX], n = 100000;
    int T[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    input(Q, &n);
    output(Q, n);
    clock_t start = clock();
    printf("Tong day la: %ld %d\n", sum_rec(Q, n), n);
    clock_t end = clock();
    //printf("Gia tri lon nhat cua day la: %d\n", max_rec(Q, n));
    //printf("Gia tri nho nhat cua day la: %d\n", min_rec(Q, n));
    clock_t start_dq = clock();
    printf("Tong day bang phuong phap lap la: %ld \n", sum(Q, n), n);
    clock_t end_dq = clock();
    printf("Thoi gian thuc hien ham sum_rec: %.2f (s)\n", (float)(end - start)/100);
    printf("Thoi gian thuc hien ham sum: %.9f (s)", (float)(end_dq - start_dq)/100);
    
    return 0;
}

float lai_kep(float y, int n)
{
    if(n == 1)
        return y * (1 + 0.1);
    else
    {
        return (1 + 0.1) * lai_kep(y, n - 1);
    }
}

void  input(int  Q[],  int  *n)
{
    srand((unsigned int)time(NULL));
    for(int i = 0; i < *n; ++i)
    {
        Q[i] = GetRandom(1, 100);
    }
}

void output(int Q[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

long  sum_rec(int  Q[],  int  n)
{
    if(n - 1 == 0)
        return Q[0];
    else
        return Q[n - 1] + sum_rec(Q, n - 1);
}

int  max_rec(int  Q[],  int  n)
{
    if(n == 1)
    {
        return Q[0];
    }
    else
    {
        return Q[n - 1] > max_rec(Q, n - 1)?Q[n - 1]:max_rec(Q, n - 1);
    }
}

int min_rec(int Q[], int n)
{
    if(n == 1)
    {
        return Q[0];
    }
    else
    {
        return Q[n - 1] < min_rec(Q, n - 1)?Q[n - 1]:min_rec(Q, n - 1);
    }
}

long  sum(int  Q[],  int  n)
{
    long temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += Q[i];
    }
    return temp;
}

int GetRandom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}