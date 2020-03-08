// Given a 32-bit signed integer, reverse digits of an integer.
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
// Example 1: Input: 123 Output: 321
// Example 2: Input: -123 Output: -321
// Example 3: Input: 120 Output: 21

// Example:
// const auto result = reverse_integer(1'534'236'469);

#include <climits>

int reverse_integer(const int& number)
{
	const long long multiplier = 10;
	long long result_number = 0;
	long mutable_number = number;

	while (mutable_number != 0)
	{
		result_number = result_number * multiplier + mutable_number % multiplier;
		mutable_number /= multiplier;
	}

	return result_number < INT_MIN || result_number > INT_MAX
		? 0 : static_cast<int>(result_number);
}
