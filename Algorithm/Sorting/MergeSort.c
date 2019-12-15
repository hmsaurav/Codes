#include<stdio.h>
int Res[100];

void Merge(int* A, int l, int r)
{
    int i,j,k;
    for(k = l; k <=r; k++)
    {
        Res[k] = A[k];
    }
    int mid = (l + r)/2;
    i = l;
    j = mid + 1;
    for(k = l; k <=r; k++)
    {
        if(i > mid)
        {
            A[k] = Res[j];
            j++;
        }
        else if(j > r)
        {
            A[k] = Res[i];
            i++;
        }
        else if(Res[i] < Res[j])
        {
            A[k] = Res[i];
            i++;
        }
        else
        {
            A[k] = Res[j];
            j++;
        }
    }
}

void MergeSort(int* A, int l, int r)
{
    if(l == r)
    {
        return;
    }
    int mid;
    mid = (l + r)/2;
    MergeSort(A, l, mid);
    MergeSort(A, mid+1, r);
    Merge(A, l, r);
}

int main()
{
    int A[] = {10,9,8,7,6,5,4,3,2,1};
    int n,i;
    n = sizeof(A)/sizeof(int);
    MergeSort(A, 0, n-1);
    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
