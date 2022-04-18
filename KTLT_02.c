/*
MSSV 21127561
Họ và tên: Nguyễn Đình Viên Thành
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

#define MAX 100

// Khai báo kiểu dữ liệu phân số (PHANSO)
typedef struct 
{
    int tso;
    int mso;
}PHANSO;

//BAI 1

PHANSO nhapPS(); //Nhập phân số
void xuatPS(PHANSO pso);// Xuất phân số
int UCLN(int a, int b);//Tìm ước chung lớn nhất
PHANSO rutgonPS(PHANSO pso);//rút gọn phân số
void tongHaiPS(PHANSO pso1, PHANSO pso2);//Tổng hai phân số
void hieuHaiPS(PHANSO pso1, PHANSO pso2);//Hiệu hai phân số
void tichHaiPS(PHANSO pso1, PHANSO pso2);//Tích hai phân số
void thuongHaiPS(PHANSO pso1, PHANSO pso2);//Thương hai phân số
int TestToiGian(PHANSO pso);//Kiểm tra tối giản
void quyDongHAiPS(PHANSO pso1, PHANSO pso2); //quy đồng hai phân số
void ktPhanSoAmDuong(PHANSO pso); //Kiểm tra phân số âm hay dương
void soSanhHaiPS(PHANSO pso1, PHANSO pso2);//So sánh 2 phân số

//BAI 7

//Nhập/Xuất n phân số
void NHAP(PHANSO ds[], int *n);
void XUAT(PHANSO *ds, int n);
void rutGonMangPS(PHANSO *ds, int n);//Rút gọn mọi phân số
void demSoAmDuong(PHANSO *ds, int n); //Đếm số lượng phân số âm/dương trong mảng
PHANSO timSoNguyenDuongDauTien(PHANSO *ds, int n); //Tìm số nguyên dương đầu tiên có trong mảng
PHANSO timPSLonNhat(PHANSO *ds, int n); //Tìm phân số lớn nhất trong mảng
PHANSO timPSNhoNhat(PHANSO *ds, int n); //Tìm phân số Nhỏ nhất trong mảng
void sawp(PHANSO *a, PHANSO *b); //Hàm dổi chỗ
void sapXepMangTangDan(PHANSO *ds, int n);//Sắp xếp mảng tăng dần
void sapXepMangGiamDan(PHANSO *ds, int n);//Sắp xếp mảng giảm dần

int main()
{
    //BAI 1
    // PHANSO pso1, pso2;

    // pso1 = nhapPS();
    // xuatPS(pso1);
    // pso2 = nhapPS();
    // xuatPS(pso2);
    // pso1 = rutgonPS(pso1);
    // pso2 = rutgonPS(pso2);
    // xuatPS(pso1);
    // xuatPS(pso2);
    // tongHaiPS(pso1, pso2);
    // hieuHaiPS(pso1, pso2);
    // tichHaiPS(pso1, pso2);
    // thuongHaiPS(pso1, pso2);
    // if(TestToiGian(pso1) == 0)
    //     printf("\n%d/%d La phan so toi gian\n", pso1.tso, pso1.mso);
    // else
    //     printf("\n%d/%d La phan so khong toi gian\n", pso1.tso, pso1.mso);
    // if(TestToiGian(pso2) == 0)
    //     printf("\n%d/%d La phan so toi gian\n", pso2.tso, pso2.mso);
    // else
    //     printf("\n%d/%d La phan so khong toi gian\n", pso2.tso, pso2.mso);
    // quyDongHAiPS(pso1, pso2);
    // ktPhanSoAmDuong(pso1);
    // ktPhanSoAmDuong(pso2);
    // soSanhHaiPS(pso1, pso2);

    //BAI 7
    PHANSO ds[MAX];
    int n = 0;

    NHAP(ds, &n);
    XUAT(ds, n);
    rutGonMangPS(ds, n);
    XUAT(ds, n);
    demSoAmDuong(ds, n);
    printf("Phan so duong dau tien: %d/%d\n", timSoNguyenDuongDauTien(ds, n).tso, timSoNguyenDuongDauTien(ds, n).mso);
    printf("Phan so lon nhat trong mang la: %d/%d\n", timPSLonNhat(ds, n).tso, timPSLonNhat(ds, n).mso);
    printf("Phan so nho nhat trong mang la: %d/%d\n", timPSNhoNhat(ds, n).tso, timPSNhoNhat(ds, n).mso);
    sapXepMangTangDan(ds, n);
    XUAT(ds, n);
    sapXepMangGiamDan(ds, n);
    XUAT(ds, n);
    return 0;
}

PHANSO nhapPS() //Nhập phân số
{
    PHANSO temp;
    printf("Nhap tu so: ");
    scanf("%d", &temp.tso);
    printf("Nhap mau so: ");
    scanf("%d", &temp.mso);
    return temp;
}

void xuatPS(PHANSO pso) // Xuất phân số
{
    printf("%d/", pso.tso);
    printf("%d \n", pso.mso);
}

void NHAP(PHANSO ds[], int *n)
{
    printf("Nhap so phan so: ");
    scanf("%d", &*n);
    for(int i = 0; i < *n; ++i)
    {
        ds[i] = nhapPS();
    } 
}

PHANSO rutgonPS(PHANSO pso)//rút gọn phân số
{
    PHANSO temp;
    temp.tso = pso.tso / UCLN(pso.tso, pso.mso);
    temp.mso = pso.mso / UCLN(pso.tso, pso.mso);
    return temp;
}

int UCLN(int a, int b) //Tìm ước chung lớn nhất
{
    if(a == b)
        return a;
    if(a > b)
        return UCLN(a - b, b);
    if(a < b)
        return UCLN(a, b - a);
}

int TestToiGian(PHANSO pso) //Kiểm tra tối giản
{
    if(UCLN(abs(pso.tso), abs(pso.mso)) == 1)
        return 0;
    else
        return 1;
}

void XUAT(PHANSO *ds, int n)
{
    for(int i = 0; i < n; ++i)
    {
        printf("%d/", ds[i].tso);
        printf("%d ", ds[i].mso);
    }
    printf("\n");
}

void tongHaiPS(PHANSO pso1, PHANSO pso2)//Tổng hai phân số
{
    printf(" %d/%d + %d/%d = %d/%d", pso1.tso, pso1.mso, pso2.tso, pso2.mso, pso1.tso * pso2.mso + pso2.tso * pso1.mso, pso1.mso * pso2.mso);
}

void hieuHaiPS(PHANSO pso1, PHANSO pso2) //Hiệu hai phân số
{
    printf(" %d/%d - %d/%d = %d/%d", pso1.tso, pso1.mso, pso2.tso, pso2.mso, pso1.tso * pso2.mso - pso2.tso * pso1.mso, pso1.mso * pso2.mso);
}

void tichHaiPS(PHANSO pso1, PHANSO pso2) //Tích hai phân số
{
    printf(" %d/%d * %d/%d = %d/%d", pso1.tso, pso1.mso, pso2.tso, pso2.mso, pso1.tso * pso2.tso, pso1.mso * pso2.mso);
}

void thuongHaiPS(PHANSO pso1, PHANSO pso2)//Thương hai phân số
{
    printf(" %d/%d / %d/%d = %d/%d", pso1.tso, pso1.mso, pso2.tso, pso2.mso, pso1.tso * pso2.mso, pso1.mso * pso2.tso);
}

void quyDongHAiPS(PHANSO pso1, PHANSO pso2) //quy đồng hai phân số
{
    printf("Sau khi quy dong \n");
    printf("PS1: %d/%d \n", pso1.tso * pso2.mso, pso1.mso * pso2.mso);
    printf("PS2: %d/%d \n", pso2.tso * pso1.mso, pso1.mso * pso2.mso);
}

void ktPhanSoAmDuong(PHANSO pso) //Kiểm tra phân số âm hay dương
{
    if((pso.tso * pso.mso) > 0)
        printf("\n%d/%d La so duong\n", pso.tso, pso.mso);
    else
        printf("\n%d/%d La so am\n", pso.tso, pso.mso);
}

void soSanhHaiPS(PHANSO pso1, PHANSO pso2) //So sánh 2 phân số
{
    if((pso1.tso * pso2.mso) > (pso2.tso * pso1.mso))
        printf("%d/%d > %d/%d", pso1.tso, pso1.mso, pso2.tso, pso2.mso);
    else if((pso1.tso * pso2.mso) == (pso2.tso * pso1.mso))
        printf("%d/%d = %d/%d", pso1.tso, pso1.mso, pso2.tso, pso2.mso);
    else
        printf("%d/%d < %d/%d", pso1.tso, pso1.mso, pso2.tso, pso2.mso);
}

void rutGonMangPS(PHANSO *ds, int n)//Rút gọn mọi phân số
{
    PHANSO temp;
    for(int i = 0; i < n; i++)
    {
        if(TestToiGian(ds[i]) == 0)
        {
            continue;
        }
        else
        {
            temp.mso = ds[i].mso / UCLN(abs(ds[i].tso), abs(ds[i].mso)); 
            temp.tso = ds[i].tso / UCLN(abs(ds[i].tso), abs(ds[i].mso)); 
        }
        ds[i] = temp;
    }
}

void demSoAmDuong(PHANSO *ds, int n) //Đếm số lượng phân số âm/dương trong mảng
{
    int countSD = 0, countSA = 0;
    for(int i = 0; i < n; ++i)
    {
        if((ds[i].tso * ds[i].mso) > 0)
            countSD++;
        else
            countSA++;
    }
    printf("So PS duong: %d\n", countSD);
    printf("So PS am: %d\n", countSA);
}

PHANSO timSoNguyenDuongDauTien(PHANSO *ds, int n) //Tìm số nguyên dương đầu tiên có trong mảng
{
    for(int i = 0; i < n; ++i)
    {
        if((ds[i].tso * ds[i].mso) > 0)
        {
            return ds[i];
            break;
        }
    }
}

PHANSO timPSLonNhat(PHANSO *ds, int n) //Tìm phân số lớn nhất trong mảng
{
    PHANSO temp = ds[0];
    for(int i = 1; i < n; i++)
    {
        if((temp.tso * ds[i].mso) < (ds[i].tso * temp.mso))
            temp = ds[i];
    }
    return temp;
}

PHANSO timPSNhoNhat(PHANSO *ds, int n) //Tìm phân số Nhỏ nhất trong mảng
{
    PHANSO temp = ds[0];
    for(int i = 1; i < n; i++)
    {
        if((temp.tso * ds[i].mso) > (ds[i].tso * temp.mso))
            temp = ds[i];
    }
    return temp;
}

void sawp(PHANSO *a, PHANSO *b) //Hàm dổi chỗ
{
    PHANSO temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sapXepMangTangDan(PHANSO *ds, int n)//Sắp xếp mảng tăng dần
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if((ds[i].tso * ds[j].mso) > (ds[j].tso * ds[i].mso))
                sawp(&ds[i], &ds[j]);
        }
    }
}

void sapXepMangGiamDan(PHANSO *ds, int n)//Sắp xếp mảng giảm dần
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if((ds[i].tso * ds[j].mso) < (ds[j].tso * ds[i].mso))
                sawp(&ds[i], &ds[j]);
        }
    }
}