// Implement strStr().
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example:
// const auto i = str_str("hello", "ll");

#include <string>
using namespace std;

const int str_str(const string& haystack, const string& needle)
{
	if (!needle.length())
		return 0;

	const int max_length = haystack.length() - needle.length();

	for (auto i = 0; i <= max_length; i++)
	{
		auto is_found = true;
		
		for (auto j = 0; j < needle.length(); j++)
		{
			const int haystack_index = i + j;
			if (haystack[haystack_index] != needle[j])
			{
				is_found = false;
				break;
			}
		}

		if (is_found)
			return i;
	}

	return -1;
}
