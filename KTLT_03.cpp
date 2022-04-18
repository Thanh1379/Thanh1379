// Họ Và tên: Nguyễn Đình Viên Thành 
// MSSV: 21127561

#include <stdio.h>

// BÀI 1
int AND(int a, int b);
int OR(int a, int b);
int XOR(int a, int b); 
int NOT(int a);
int dichTrai(int a, int i);
int dichPhai(int a, int i);
//BÀI 2
int bitcount(int n);
//BÀI 3
void toHop(int *arr, int n);
int luyThua(int a, int b);

int main()
{
    int arr[15] = {1, 2, 3, 4, 5, 6}, n = 6;

    toHop(arr, n);

    return 0;
}

int AND(int a, int b)
{
    return a & b;
}

int OR(int a, int b)
{
    return a | b;
}
int XOR(int a, int b)
{
    return a ^ b;
}
int NOT(int a)
{
    return ~a;
}
int dichTrai(int a, int i)
{
    return a << i;
}
int dichPhai(int a, int i)
{
    return a >> i;
}

int bitcount(int n)
{
    int cout = 0;
    for (int  i = 0; i < (sizeof(int) * 8); i++)
    {
        if(((n >> i) & 0x1) == 1)
            cout++;
    }
    return cout;
}

void toHop(int *arr, int n)
{
    for (int i = 0; i < luyThua(2, n); i++)
    {
        for (int j = 0; j < (sizeof(int) * 8); j++)
        {
            if(((i >> j) & 0x1) == 1)
            {
                printf("%d ", arr[j]);
            }
        }
        printf("\n");
    }
    
}

int luyThua(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return a * luyThua(a, b - 1);
}