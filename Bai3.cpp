//KTLT T6 T1-3 Thuong ky 3
// Ho va ten: Nguyen Dinh Vien Thanh
// MSSV: 21127561

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Nhap n: ");
    scanf("%d", &n);

    // int *p = (int *)malloc(n * sizeof(int)); //chay on
    // int *p = (int *)calloc(n, sizeof(int)); //chay on
    int *p = new int[n];

    //Nhap xuat mang
    for (int i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }

    // free(p); //chay on
    delete []p;

    return 0;
}