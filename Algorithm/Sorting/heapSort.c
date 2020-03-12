#include<stdio.h>

void max_Heapify(int A[], int parent_Index, int N)
{
    int left_child_Index, right_child_index, largest_child_Index;
    left_child_Index = 2*parent_Index;
    right_child_index = left_child_Index + 1;
    if(left_child_Index <= N && A[left_child_Index] > A[parent_Index])
    {
        largest_child_Index = left_child_Index;
    }
    else
    {
        largest_child_Index = parent_Index;
    }
    if(right_child_index <= N && A[right_child_index] > A[largest_child_Index])
    {
        largest_child_Index = right_child_index;
    }
    if(largest_child_Index != parent_Index)
    {
        int temp = A[largest_child_Index];
        A[largest_child_Index] = A[parent_Index];
        A[parent_Index] = temp;
        max_Heapify(A, largest_child_Index, N);
    }
}

void build_MaxHeap(int A[], int N)
{
    int i;
    for(i = N/2; i >= 1; i--)
    {
        max_Heapify(A,i, N);
    }
}

void heap_Sort(int A[], int N)
{
    int i, heap_Size;
    heap_Size = N;
    build_MaxHeap(A, N);
    for(i = N; i >= 2; i--)
    {
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        heap_Size--;
        max_Heapify(A, 1, heap_Size);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int N, i;
    int A[10000];
    scanf("%d",&N);
    for(i = 1; i <=N; i++)
    {
        scanf("%d",&A[i]);
    }

    heap_Sort(A, N);

    for(i = 1; i <= N; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}
