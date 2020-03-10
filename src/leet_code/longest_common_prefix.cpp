// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
// Example 1: Input: ["flower","flow","flight"] Output: "fl"
// Example 2: Input: ["dog","racecar","car"] Output: "" Explanation: There is no common prefix among the input strings.
// Note: All given inputs are in lowercase letters a-z.

// Example:
// const string words[]{ "flower", "flow", "flight" };
// const auto size = sizeof(words) / sizeof(*words);
//
// const auto result = longest_common_prefix(words, size);

#include <string>
using std::string;

string longest_common_prefix(const string* const words, const unsigned int size)
{
	switch (size)
	{
	case 0: return "";
	case 1: return words[0];
	}

	auto common_prefix_length = 0;
	
	for (auto i = 0; i < words[0].length(); i++)
	{
		const auto check_char = words[0][i];
		const auto check_length = i + 1;
		auto letter_matches = true;

		// No need to check the first word, as the check is based on it
		for (unsigned int j = 1; j < size; j++)
			if (words[j].length() < check_length || words[j][i] != check_char)
			{
				letter_matches = false;
				break;
			}

		if (letter_matches)
			common_prefix_length++;
		else
			break;
	}

	return words[0].substr(0, common_prefix_length);
}
