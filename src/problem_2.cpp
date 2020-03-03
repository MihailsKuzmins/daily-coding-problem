// Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
// For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
// Follow-up: what if you can't use division?

// Example:
// int array[5] = { 1, 2, 3, 4, 5 };
// const auto size = sizeof(array) / sizeof(*array);
//
// auto result = problem_two_2(array, size);
//
// for (unsigned int i = 0; i < size; i++)
//     cout << result[i] << endl;
//
// delete array[];

// Iterating only three times
int* problem_two_1(int* numbers, const unsigned int size)
{
	int* result = new int[size];
	int* cumulative_left = new int[size];
	int* cumulative_right = new int[size];

	cumulative_left[0] = 1;
	cumulative_right[size - 1] = 1;

	for (unsigned int i = 1; i < size; i++)
		cumulative_left[i] = cumulative_left[i - 1] * numbers[i - 1];

	for (unsigned int i = size - 2;; i--)
	{
		cumulative_right[i] = cumulative_right[i + 1] * numbers[i + 1];

		if (i == 0)
			break;
	}

	for (unsigned int i = 0; i < size; i++)
		result[i] = cumulative_left[i] * cumulative_right[i];

	delete[] cumulative_left;
	delete[] cumulative_right;

	return result;
}

// Brutal way, not efficient
int* problem_two_2(int* numbers, const unsigned int size)
{
	int* new_array = new int[size];

	for (unsigned int i = 0; i < size; i++)
	{
		int multiplication = 1;

		for (unsigned int j = 0; j < size; j++)
		{
			if (j == i)
				continue;

			multiplication *= numbers[j];
		}

		new_array[i] = multiplication;
	}

	return new_array;
}
