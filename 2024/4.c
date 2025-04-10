#include <stdio.h>
int average(int nums[], int start, int end) {
    if (start == end)
        return nums[start];
    int mid = (start + end) / 2;
    int leftAvg = average(nums, start, mid);
    int rightAvg = average(nums, mid + 1, end);
    return (leftAvg & rightAvg) + ((leftAvg ^ rightAvg) >> 1);
}

int main(void)
{
    int num[]={0,1,2,3,4,5,6,7,8,9};
    printf("%d\n",average(num,4,6));
    return 0;
}