// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.  
// Note: Each term of the sequence of integers will be represented as a string.

// Example:
// auto result = count_and_say(30);

#include <string>
using namespace std;

// recursion
string count_and_say_2(const int n)
{
	if (n < 1 || n > 30)
		throw "Out of range";

	switch (n)
	{
	case 1: return "1";
	}

	const auto prev_number = count_and_say(n - 1);
	string result = "";

	for (auto i = 0, current_count = 1; i < prev_number.length(); i++)
	{
		if (const auto next_index = i + 1; next_index == prev_number.length() || prev_number[i] != prev_number[next_index])
		{
			result.append(to_string(current_count)).append(1, prev_number[i]);
			current_count = 1;
			continue;
		}

		current_count++;
	}

	return result;
}
