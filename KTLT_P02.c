#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 100

//Định nghĩa kiểu cấu trúc SINHVIEN
typedef struct 
{
    char HT[MAX];
    int MSSV;
    float dTK;
    float dGK;
    float dCK;
    float dTH;
    float dTB;

}SINHVIEN;

//Hàm
void NHAP(SINHVIEN *A, int *n);// Nhập thông tin sinh viên
void TINHDIEMTB(SINHVIEN *A, int n);//Hàm tính điểm trung bình
void TIMSV(SINHVIEN *A, int n);//Hàm tìm thông tin sv có mssv X;
void swap(SINHVIEN *a, SINHVIEN *b); //Hàm đổi chỗ
void SAPXEPSV(SINHVIEN *A, int n);//Hàm sắp xếp sinh viên theo DTB

int main()
{
    SINHVIEN A[MAX];
    int n = 0;
    
    NHAP(A, &n);
    TINHDIEMTB(A, n);
    printf("STT     HO TEN          MA SINH VIEN    DIEM TB \n");
    for(int i = 0; i < n; i++)
    {
        if(A[i].dTB < 4.0)
        {
            printf("%d\t%s\t%d\t%.2f\n", i + 1, A[i].HT, A[i].MSSV, A[i].dTB);
        }
    }
    TIMSV(A, n);
    printf("\nSTT     HO TEN          MA SV   TK  GK CK TH DTB GHI CHU\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\t%.2f %.2f %.2f %.2f %.2f", i + 1, A[i].HT, A[i].MSSV, A[i].dTK, A[i].dGK, A[i].dCK, A[i].dTH, A[i].dTB);
        if(A[i].dTB < 4.0)
        {
            printf("\tHoc lai\n");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}

void NHAP(SINHVIEN *A, int *n)
{
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &*n);
    for(int i = 0; i < *n; ++i)
    {
        printf("Nhap thong tin hoc sinh thu %d", i + 1);
        printf("Ho va ten: ");
        fflush(stdin);
        gets(A[i].HT);
        printf("MSSV: ");
        scanf("%d", &A[i].MSSV);
        printf("Diem TK: ");
        scanf("%f", &A[i].dTK);
        printf("Diem GK:");
        scanf("%f", &A[i].dGK);
        printf("Diem CK: ");
        scanf("%f", &A[i].dCK);
        printf("Diem TH: ");
        scanf("%f", &A[i].dTH);
    }
}

void TINHDIEMTB(SINHVIEN *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        A[i].dTB = (((2.0 * A[i].dTK + 3.0 * A[i].dGK + 5.0 * A[i].dCK) / 10.0) * 2.0 + A[i].dTH) / 3.0;
    }
}

void TIMSV(SINHVIEN *A, int n)
{
    int i, mssv = 0;

    printf("Nhap MSSV can tim: ");
    scanf("%d", &mssv);
    for(i = 0; i < n; i++)
    {
        if(A[i].MSSV == mssv)
        {
            printf("Ho va ten %s\n", A[i].HT);
            printf("MSSV: %d\n", A[i].MSSV);
            printf("Diem thuong ki: %f\n", A[i].dTK);
            printf("Diem giua ki: %f\n", A[i].dGK);
            printf("Diem cuoi ki: %f\n", A[i].dCK);
            printf("Diem thuc hanh: %f\n", A[i].dTH);
            printf("Diem trung binh: %f\n", A[i].dTB);
            break;
        }
    }
    if(i == n)
    {
        printf("Khong tim thay");
    }
}

void swap(SINHVIEN *a, SINHVIEN *b)
{
    SINHVIEN temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void SAPXEPSV(SINHVIEN *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(A[i].dTB < A[j].dTB)
                swap(&A[i], &A[j]);
        }
    }
}