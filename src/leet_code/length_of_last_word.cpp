// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
// If the last word does not exist, return 0.
// Note: A word is defined as a maximal substring consisting of non-space characters only.

// Example:
// const auto result = length_of_last_word("  an ");

#include <string>
using namespace std;

const int length_of_last_word(const string&& phrase) noexcept
{
	unsigned int count = 0;
	bool is_word_found = false;

	for (int i = phrase.length() - 1; i >= 0; i--)
	{
		if (phrase[i] != ' ')
		{
			is_word_found = true;
			count++;
		}
		else if (is_word_found)
			return count;
	}

	return count;
}
