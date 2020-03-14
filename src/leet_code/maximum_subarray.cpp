// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.  
// Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

// Example:
// int arr[] = { -2,1,-3,4,-1,2,1,-5,4 };
// auto size = sizeof(arr) / sizeof(*arr);
// auto result = maximum_subarray(arr, size);

#include <limits>
#include <algorithm>

using namespace std;

int maximum_subarray(const int numbers[], const unsigned int size) noexcept
{
	int result = numeric_limits<int>::min(), current = result;

	for (unsigned int i = 0; i < size; i++)
	{
		// prevent overflow in case `numbers[i]` is negative
		current = current == numeric_limits<int>::min()
			? numbers[i]
			: max(current + numbers[i], numbers[i]);

		if (current > result)
			result = current;
	}

	return result;
}
