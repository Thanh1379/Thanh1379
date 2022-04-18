#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>

int findSimilarNumber(int *arr);

int main()
{
    int arr[6] = {2, 3, 5, 1, 1, 4};

    printf("KQ la: %d", findSimilarNumber(arr));

}

int findSimilarNumber(int *arr)
{
    int t, r;
    t = arr[0];
    r = arr[0];

    while (0 < 1)
    {
        t = arr[t];
        r = arr[arr[r]];
        if (t == r)
        {
            break;
        }
    }

    int ptr1, ptr2;

    ptr1 = arr[0];
    ptr2 = r;

    while (ptr1 != ptr2)
    {
        ptr1 = arr[ptr1];
        ptr2 = arr[ptr2];
    }
    return ptr1;
    
}