#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

# define MAX 100

typedef struct KTLT_P07
{
    char HoLot[30];
    char Ten[30];
    char NgaySinh[9];
    char NoiSinh[40];
    float D_WIN;
    float D_WORD;
    float D_EXCEL;
    float TONGDIEM;
    char X_LOAI[20];

}HOCVIEN;

void nhapThongTin(HOCVIEN *SV, int *n);
void nhapDiemThi(HOCVIEN *SV, int n);
void inThongTin(HOCVIEN *SV, int n);
void xuLiDuLieu(HOCVIEN *SV, int n);
void inKetQuaThi(HOCVIEN *SV, int n);

int main()
{
    HOCVIEN SV[MAX];
    int choise;
    int n = 0;

    printf("1_Nhap Thong Tin Sinh Vien \n");
    printf("2_NHap Diem \n");
    printf("3_In Ket Qua Thi\n");
    printf("4_Exit\n");
    while(1)
    {
        
        printf("Nhap Lua Chon: ");
        scanf("%d", &choise);

        if(choise < 0 || choise > 4)
            printf("Nhap Sai Vui Long Nhap Lai!!!\n");
        else
        {
            switch (choise)
            {
            case 1:
                nhapThongTin(SV, &n);
                inThongTin(SV, n);
                break;
            case 2:
                nhapDiemThi(SV, n);
                xuLiDuLieu(SV, n);
                break;
            case 3:
                inKetQuaThi(SV, n);
                break;
            case 4:
                exit(0);
                break;
            }
        }
    }
}

void nhapThongTin(HOCVIEN *SV, int *n)
{
    printf("Nhap So Luong SV: ");
    scanf("%d", &*n);
    for (int i = 0; i < *n; i++)
    {
        printf("\nNhap sinh vien thu %d \n", i + 1);
        printf("Nhap Ho Lot: ");
        fflush(stdin); 
        gets(SV[i].HoLot);
        printf("Nhap Ten: ");
        gets(SV[i].Ten);
        printf("Nhap ngay sinh: ");
        gets(SV[i].NgaySinh);
        printf("Nhap noi sinh: ");
        gets(SV[i].NoiSinh);
    }
    printf("\n");
}

void nhapDiemThi(HOCVIEN *SV, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap sinh vien thu %d \n", i + 1);
        fflush(stdin);
        printf("Nhap Diem Window: ");
        scanf("%f", &SV[i].D_WIN);
        printf("Nhap Diem Word: ");
        scanf("%f", &SV[i].D_WORD);
        printf("Nhap Diem Excel: ");
        scanf("%f", &SV[i].D_EXCEL);
    }
    printf("\n");
}

void inThongTin(HOCVIEN *SV, int n)
{
    printf(" STT\tHO VA TEN\tNGAY SINH\tNOI SINH\tGHI CHU\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", i + 1);
        printf("\t%s", SV[i].HoLot);
        printf(" %s", SV[i].Ten);
        printf("\t%s", SV[i].NgaySinh);
        printf("\t%s", SV[i].NoiSinh);
        printf("\t--------");
        printf("\n");
    }
    
}

void xuLiDuLieu(HOCVIEN *SV, int n)
{
    for (int i = 0; i < n; i++)
    {
        SV[i].TONGDIEM = SV[i].D_EXCEL + SV[i].D_WIN + SV[i].D_WORD;
        if(SV[i].TONGDIEM >= 24.0)
            strcpy(SV[i].X_LOAI, "Gioi");
        else if(SV[i].TONGDIEM < 24.0 && SV[i].TONGDIEM >= 18.0)
            strcpy(SV[i].X_LOAI, "Kha");
        else if(SV[i].TONGDIEM < 18.0 && SV[i].TONGDIEM >= 15.0)
            strcpy(SV[i].X_LOAI, "T.Binh");
        else
            strcpy(SV[i].X_LOAI, "Yeu");
    }
    
}

void inKetQuaThi(HOCVIEN *SV, int n)
{
    printf(" STT\tHO VA TEN\tDIEM TONG\tXEP LOAI\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", i + 1);
        printf("\t%s", SV[i].HoLot);
        printf(" %s", SV[i].Ten);
        printf("\t%.2f", SV[i].TONGDIEM);
        printf("\t%s", SV[i].X_LOAI);
        printf("\n");
    }
    
}