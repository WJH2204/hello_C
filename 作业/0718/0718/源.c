#include <stdio.h>
#include <stdlib.h>

int compar(const void* p1, const void* p2)
{
    return (*(int*)p1 - *(int*)p2);
}

int dichotomy(int* nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;
    int middle = numsSize / 2;
    while (left < right)
    {
        if (nums[middle] > middle)
        {
            right = middle - 1;
            middle = (left + right) / 2;
        }
        else
        {
            left = middle + 1;
            middle = (left + right) / 2;
        }
    }
    return (nums[middle] - 1);
}


int missingNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compar);
    int ret = dichotomy(int* nums, int numsSize);
    return ret;
}

int main()
{
    int nums[9] = { 0,1,2,3,4,6,7,8,9 };
    printf("%d", missingNumber(nums, 9));
    return 0;
}