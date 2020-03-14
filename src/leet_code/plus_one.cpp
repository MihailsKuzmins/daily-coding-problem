// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
// You may assume the integer does not contain any leading zero, except the number 0 itself.

#include <vector>

using namespace std;

vector<char> plus_one(vector<char>& digits) noexcept
{
	char remember = 1;

	for (unsigned int i = digits.size() - 1;; i--)
	{
		if (remember == 0)
			return digits;

		const auto sum = digits[i] + remember;

		digits[i] = sum % 10;
		remember = sum / 10;

		if (i == 0)
			break;
	}

	if (remember)
		digits.insert(begin(digits), remember);

	return digits;
}
