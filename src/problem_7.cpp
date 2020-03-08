// Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
// For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
// You can assume that the messages are decodable. For example, '001' is not allowed.

// Example:
// auto result = problem_seven("111");

#include <string>
#include <memory>

using namespace std;

// idea is to list cumulative numbers of possible encoding ways
int problem_seven(const string& input)
{
	const auto max_number = 26;
	const auto input_length = input.length();

	switch (input_length)
	{
	case 0:
		return 0;
	case 1:
		return input[0] == '0' ? 0 : 1;
	}

	// array of an increased size needs to handle the case when length is two
	// and it will need to check the element at the index -1
	auto arr = make_unique<int[]>(input_length + 1);
	arr[0] = 1;
	arr[1] = input[0] != '0' ? 1 : 0;

	for (int i = 1; i < input_length; i++)
	{
		const int next_index = i + 1;
		
		// always add for a single digit
		arr[next_index] = input[i] != '0' ? arr[i] : 0;
			
		// check for two-digits
		const int prev_index = i - 1;
		switch (input[prev_index])
		{
		case '0':
			break;
		default:
			const auto digits = stoi(input.substr(prev_index, 2));

			if (digits >= 10 && digits <= max_number)
				arr[next_index] += arr[prev_index];
			break;
		}
	}

	return arr[input_length];
}
