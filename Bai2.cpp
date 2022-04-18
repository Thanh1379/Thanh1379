// Ho va ten: Nguyen Dinh Vien Thanh
// MSSV: 21127561
#include <stdio.h>

void nhap(int a[10], int n);
void xuat(int a[10], int n);

int main(){
    int a[10], n = 10;

    nhap(a, n);
    xuat(a, n);

    return 0;
}

void nhap(int a[10], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
}

void xuat(int a[10], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
    
}