// Given two binary strings, return their sum (also a binary string).
// The input strings are both non-empty and contains only characters 1 or 0.

// Example:
// const auto result = add_binary("1010", "1011");

#include <string>
using namespace std;

const string add_binary(const string&& string_one, const string&& string_two) noexcept
{
	const auto max_length = string_one.length() > string_two.length()
		? string_one.length()
		: string_two.length();

	char carry = 0;
	string result = "";

	const auto max_index_one = string_one.length() - 1, max_index_two = string_two.length() - 1;

	for (auto i = 0; i < max_length; i++)
	{
		const auto one = i <= max_index_one ? string_one[max_index_one - i] : '0';
		const auto two = i <= max_index_two ? string_two[max_index_two - i] : '0';
		const auto sum = one - '0' + two - '0' + carry;

		result.insert(0, to_string(sum % 2));
		carry = sum / 2;
	}

	if (carry)
		result.insert(0, to_string(carry));

	return result;
}
