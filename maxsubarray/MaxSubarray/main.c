#include <stdio.h>
#include <stdlib.h>
int arr[4]={};
int array[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
int *find_max_crossing_subarray(int a[11],int low,int mid,int high,int *re)
{
    int left_sum = -100,max_left=mid;
    int sum = 0;
    int i = 0;
    for(i=mid;i>low;i--)
    {
        sum = sum + a[i];
        if(sum>left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = -100,max_right;
    sum = 0;
    for(i=mid+1;i<high;i++)
    {
        sum = sum + a[i];
        if(sum>right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    *(re+0) = max_left;
    *(re+1)= max_right;
    *(re+2) = left_sum+right_sum;
    return re;
}
int main()
{   int j = 0;
    find_max_crossing_subarray(array,0,7,15,arr);
    for(j = 0;j<4;j++)
    {
        printf("result:%d\n",arr[j]);
    }

    return 0;
}
