// Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
// For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
// You can modify the input array in-place.

// Example:
// int array[4] = { -100, -98, -99, 1 };
// const auto size = sizeof(array) / sizeof(*array);
//
// auto result = problem_four(array, size);

unsigned int get_positive_numbers(int* numbers, unsigned int size);

int problem_four(int* numbers, unsigned int size)
{
	const auto positive_index = get_positive_numbers(numbers, size);

	// There are no positive elements in the giver array
	if (positive_index == size)
		return 1;

	int min_value = numbers[positive_index];
	for (unsigned int i = positive_index + 1; i < size; i++)
		if (numbers[i] < min_value)
			min_value = numbers[i];

	// first possible missing element
	min_value++;

	for (unsigned int i = positive_index; i < size; i++)
	{
		bool is_found = false;

		for (unsigned int j = positive_index; j < size; j++)
			if (numbers[j] == min_value)
			{
				is_found = true;
				min_value++;
				break;
			}

		if (!is_found)
			return min_value;
	}

	return min_value;
}

// purpose of this function is to move all positive elements to the right-hand side;
// and all negative to the left-hand side
unsigned int get_positive_numbers(int* numbers, unsigned int size)
{
	unsigned int i = 0, j = size - 1;

	while (i < j)
	{
		// left == positive && right == negative => swap
		if (numbers[i] > 0 && numbers[j] <= 0)
		{
			// swap elements
			numbers[i] += numbers[j];
			numbers[j] = numbers[i] - numbers[j];
			numbers[i] -= numbers[j];

			i++; j--;
		}
		// left == positive && right == positive => keep searching for negative elements on the right-hand side
		else if (numbers[i] > 0)
		{
			j--;
		}
		// left == negative && right in [positive, negative] => negative element is to the left of another element
		// (eigher positive or negative, we don't care), keep searching fo positive elements on the left-hand side
		else
		{
			i++;
		}
	}

	// i and i + 1 is the border between the positive and negative numbers
	return numbers[i] > 0 ? i : i + 1;
}
