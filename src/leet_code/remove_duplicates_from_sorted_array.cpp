// Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// Example:
// int arr[] = { 0,0,1,1,1,2,2,3,3,4 };
// const unsigned int size = sizeof(arr) / sizeof(*arr);
// const auto new_length = remove_duplicates_from_sorted_array(arr, size);

using namespace std;

const unsigned int remove_duplicates_from_sorted_array(int* numbers, const unsigned int size)
{
	switch (size)
	{
	case 0: return 0;
	}

	unsigned int i = 0;
	for (unsigned int j = 1; j < size; j++)
		if (numbers[i] != numbers[j])
			numbers[++i] = numbers[j];

	return i + 1;
}
