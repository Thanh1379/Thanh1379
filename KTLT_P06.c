#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void standard(char s[]);
int demTu(char s[]);
void xuatTuTrenCacDong(char s[]);
void timChieuDaiLonNhat(char s[]);
void nKiTuDauCuoi(char s[], int n, int pos);

int main()
{
    char name[MAX];

    // fflush(stdin);
    // scanf("%s", &name);
    //printf("%s\n", name);
    fflush(stdin);
    gets(name);
    puts(name);
    strlwr(name);
    name[0] = toupper(name[0]);
    puts(name);
    printf("%d\n", strlen(name));
    standard(name);
    puts(name);
    printf("%d\n", strlen(name));

    int n = strlen(name);
    
    // for (int i = 0; i < n; i++)
    // {
    //     if(name[i] == ' ')
    //     {
    //         for(int j = i; j + 1 < n; j++)
    //         {
    //             name[j] = name[j + 1];
    //         }
    //         name[n - 1] = '\0';
    //         n--;
    //     }
    //     continue;

    // }
    // puts(name);
    printf("%d\n", demTu(name));
    xuatTuTrenCacDong(name);
    timChieuDaiLonNhat(name);
    nKiTuDauCuoi(name, 6, 4);

    return 0;
}

void standard(char s[])
{
    int n = strlen(s);
    
    for(int i = 0; i < n;)
    {
        if(s[i] != ' ')
        {
            break;
        }
        if(s[i] == ' ')
        {
            for(int j = i; j + 1 < n; j++)
            {
                s[j] = s[j + 1];
            }
            s[n - 1] = '\0';
            n--;
        }
        
    }

    strrev(s);
    for(int i = 0; i < n;)
    {
        if(s[i] != ' ')
        {
            break;
        }
        if(s[i] == ' ')
        {
            for(int j = i; j + 1 < n; j++)
            {
                s[j] = s[j + 1];
            }
            s[n - 1] = '\0';
            n--;
        }
        
    }
    strrev(s);
    
}

int demTu(char s[])
{
    int n = strlen(s);
    int count = 1;

    for(int i = 0; i < n; ++i)
    {
        if(s[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

void xuatTuTrenCacDong(char s[])
{
    int n = strlen(s);

    if(demTu(s) == 1)
    {
        puts(s);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if(s[i] == ' ')
                printf("\n");
            else  
                printf("%c", s[i]);
        }
        printf("\n");
    }
    
}

void timChieuDaiLonNhat(char s[])
{
    int n = strlen(s);

    if(demTu(s) == 1)
    {
        printf("1");
        puts(s);
    }
    else
    {
        int temp[MAX], count, add = 0;

        for (int i = 0; i < demTu(s); i++)
        {
            count = 0;
            for(int j = 0 + add; j < n; ++j)
            {
                
                if(s[j] == ' ')
                {
                    break;
                }
                else
                {
                    count++;
                }
            }
            add += count;
            add++;
            temp[i] = count;
        }
        int max = temp[0], voc = 0;

        for (int i = 1; i < demTu(s); i++)
        {
            if(max < temp[i])
            {
                max = temp[i];
                voc = i;
            }
        }
        int pos = voc;

        for (int i = 0; i < voc; i++)
        {
            pos += temp[i];
        }
        
        printf("Max: %d\n", max);

        for (int i = pos; i < (pos + temp[voc]); i++)
        {
            printf("%c", s[i]);
        }
        printf("\n");
    }
}

void nKiTuDauCuoi(char s[], int n, int pos)
{
    //n Ki tu dau tien 
    for (int i = pos; i < (pos + n); i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
    //n Kí tự cuối cùng
    for (int i = (strlen(s) - n); i < strlen(s); i++)
    {
        printf("%c", s[i]);
    }
    
    
}