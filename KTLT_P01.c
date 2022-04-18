// #include <stdio.h>
// #include <math.h>

// #define MAX 100

// //Khai báo cấu trúc miêu tả 1 điểm trong tọa độ đề-các(oxy)
// typedef struct 
// {
//     int x;
//     int y;
// }Point;

// // Hàm

// float P1P2(Point P1, Point P2); // Hàm trả về độ dài 2 điểm P1, P2
// float SP1P2P3(Point P1, Point P2, Point P3); // Hàm trả về diện tích 1 tam giác có 3 điểm biết trước
// float S(Point *A, int n); // Hàm trả về diện tich đa giác n đỉnh
// Point NHAPDIEM(); //Hàm nhập 1 điểm
// void NHAP(Point *A, int *n); // Hàm nhập


// int main()
// {
//     Point A[MAX];
//     int n = 0;

//     // Đa giác lồi
//     NHAP(A, &n);
//     printf("Dien tich da giac loi %d dinh: %f", n ,S(A, n));

//     return 0;
// }

// float P1P2(Point P1, Point P2)
// {
//     return sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
// }

// float SP1P2P3(Point P1, Point P2, Point P3)
// {
//     return 0.5 * abs((P2.x - P1.x) * (P2.y - P1.y) - (P3.x - P1.x) * (P3.y - P1.y) );
// }

// float S(Point *A, int n)
// {
//     float s = 0;

//     for(int i = 0; i < (n - 2); ++i)
//     {
//         s += SP1P2P3(A[0], A[i + 1], A[i + 2]);
//     }
//     return s;
// }

// Point NHAPDIEM()
// {
//     Point temp;
//     printf("Nhap x = ");
//     scanf("%d", &temp.x);
//     printf("Nhap y = ");
//     scanf("%d", &temp.y);
//     return temp;
// }

// void NHAP(Point *A, int *n)
// {
//     printf("Nhap so diem: ");
//     scanf("%d", &*n);
//     for(int i = 0; i < *n; ++i)
//     {
//         printf("Nhap diem %d\n", i + 1);
//         A[i] = NHAPDIEM();
//     }
// }

#include <stdio.h>
#include <string.h>

typedef struct 
{
    char ht[100];
}HS;

int main()
{
    HS A[100];
    fflush(stdin);
    gets(A[0].ht);
    puts(A[0].ht);
    return 0;
}