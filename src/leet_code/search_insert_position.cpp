// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You may assume no duplicates in the array.
// Example 1: Input: [1,3,5,6], 5 Output: 2
// Example 2: Input: [1,3,5,6], 2 Output: 1
// Example 3: Input: [1,3,5,6], 7 Output: 4
// Example 4: Input: [1,3,5,6], 0 Output: 0

// Example:
// int array[] = { 1,3,5,6 };
// unsigned int size = sizeof(array) / sizeof(*array);
// auto result = search_insert_position(22, array, size);

const unsigned int search_insert_position(const int target, const int numbers[], const unsigned int size)
{
	unsigned int i = 0;
	int left = 0, right = size - 1;

	while (right >= left)
	{
		i = left + (right - left) / 2;

		if (target > numbers[i])
			left = i + 1;
		else
			right = i - 1;
	}

	return left;
}
