// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

// Example:
// const int arr[] = { 2,7,11,15 };
// const int target = 9;
// const auto size = sizeof(arr) / sizeof(*arr);
// const auto result = sum_two(target, arr, size);

#include <map>

using namespace std;

auto sum_two(const int target, int const numbers[], const unsigned int size)
{
	map<int, unsigned int> map;

	for (unsigned int i = 0; i < size; i++)
	{
		const auto it = map.find(numbers[i]);

		if (it != map.end())
			return new unsigned int[2]{ it->second, i };
		else
			map.insert({ target - numbers[i], i });
	}

	throw "Illegal state. Input must have an answer";
}
