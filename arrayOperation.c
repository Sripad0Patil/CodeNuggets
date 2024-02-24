#include<stdio.h>
void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int InsertAtIndex(int arr[], int size, int cap, int index, int element)
{
    if(size>=cap)
    {
        return -1;
    }
    for(int i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    size++;
    arr[index]=element;
    return 1;
}
void deleteAtIndex(int arr[], int size, int index)
{
    for(int i=index;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
}
void sorting(int arr[], int size)
{
    int temp;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int Lsearch(int array[], int size, int element)
{
    for(int i=0;i<size;i++)
    {
        if(array[i]==element)
        {
            return i;
        }
    }
    return -1;
}
int Bsearch(int array[],int size, int element)
{
    int low=0, mid, high=size-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(array[mid]==element)
        {
            return mid;
        }
        if(array[mid]<element)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int array[100]={6,8,9,2,1};
    int size=5;
    int ele = 7;
    printf("Original: ");
    display(array, 5);
    printf("After insertion: ");
    InsertAtIndex(array, size, 100, 3, 7);
    display(array, 6);
    printf("After deletion: ");
    deleteAtIndex(array, 6, 0);
    display(array, 5);
    printf("After sorting: ");
    sorting(array, 5);
    display(array, 5);
    printf("Linear search: ");
    int ls = Lsearch(array, 5, ele);
    printf("%d found at index %d.",ele,ls);
    printf("\nBinary search: ");
    int bs = Bsearch(array, 5, ele);
    printf("%d found at index %d.",ele,bs);



return 0;
    
}
