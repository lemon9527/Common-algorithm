介绍一下简单的算法：

给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

对于这道题，首先想到的就是暴力方法，即使用两个for循环，遍历两次数组，看有没有和是目标值的。显然这样时间复杂度太大，O(n*n)
#include <stdio.h>
#include <stdbool.h>

#define SIZE 4

int main(void)
{
	int nums[SIZE] = {2, 7, 11, 15};
	int target = 26;
	int number1, number2, complement;
	bool isfound = false;
	int i, j;

	for(i = 0; i < SIZE; i++)
	{
		number1 = nums[i];
		complement = target - number1;

		for(j = 0; j < SIZE; j++)
		{
			if(i!=j && nums[j] == complement)
			{
				isfound = true;
				printf("nums[%d], nums[%d] \n", i, j);
				break;
			}
		}
		if(isfound)
			break;
	}

	return 0;
}

因此需要改良的算法，用到哈希查找的方法。
