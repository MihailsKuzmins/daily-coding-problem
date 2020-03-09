#include <string>
using std::string;

constexpr int roman_char_to_int(const char& roman_char)
{
	switch (roman_char)
	{
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	default: throw "Invalid roman char";
	}
}

int roman_to_integer(const string& roman)
{
	int result = 0;
	const auto roman_length = roman.length();
	const auto last_index = roman_length - 1;

	for (int i = 0; i < roman_length; i++)
	{
		auto current_number = roman_char_to_int(roman[i]);

		if (i < last_index)
		{
			const int next_index = i + 1;
			const auto next_number = roman_char_to_int(roman[next_index]);

			if (next_number > current_number)
			{
				result += next_number - current_number;
				i++;
				continue;
			}
		}
		
		result += current_number;
	}

	return result;
}
