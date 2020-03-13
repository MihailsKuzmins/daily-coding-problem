// Given a list of numbersand a number k, return whether any two numbers from the list add up to k.
// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
// Bonus: Can you do this in one pass?

// Example
// int array[4] = {2, 2, 2, 3};
// const auto size = sizeof(array) / sizeof(*array);
// auto result = problem_one(5, array, size);

#include <set>

using namespace std;

bool problem_one(const int sum, int const numbers[], const unsigned int size)
{
	set<int> set;

	for (unsigned int i = 0; i < size; i++)
	{
		const auto possible_answer = sum - numbers[i];

		for (const auto& item : set)
			if (item == numbers[i])
				return true;

		set.insert(possible_answer);
	}

	return false;
}
