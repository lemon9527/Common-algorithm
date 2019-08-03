/*
题目描述

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
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

	if(isfound)
		printf("nums[%d], nums[%d] \n", i, j);
	else
		printf("not found!");

	return 0;
}
