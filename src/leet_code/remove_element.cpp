// Given an array nums and a value val, remove all instances of that value in-place and return the new length.
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// The order of elements can be changed. It doesn't matter what you leave beyond the new length.

// Example:
// int arr[] = { 0,1,2,2,3,0,4,2 };
// const unsigned int size = sizeof(arr) / sizeof(*arr);
// const auto new_length = remove_element(arr, 2, size);

const unsigned int remove_element(int* numbers, const int remove_value, const unsigned int size)
{
	if (size == 0)
		return 0;

	unsigned int i = 0;
	for (unsigned int j = 0; j < size; j++)
	{
		if (numbers[j] != remove_value)
			numbers[i++] = numbers[j];
	}

	return i;
}
