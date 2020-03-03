// Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
// For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
// Follow-up: what if you can't use division?

// Example:
// int array[5] = { 1, 2, 3, 4, 5 };
// auto size = sizeof(array) / sizeof(*array);
//
// auto result = problem_two_2(array, size);
//
// for (unsigned int i = 0; i < size; i++)
//     cout << result[i] << endl;
//
// delete array;

// TODO:
int* problem_two_1(int* numbers, unsigned int size)
{
	int* new_array = new int[size];
	return new_array;
}

// Not the besr way
int* problem_two_2(int* numbers, unsigned int size)
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
