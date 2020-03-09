// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
// Example1 Input: 121 Output: true
// Example2 Input: -121 Output: false (From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome)
// Example3 Input: 10 Output: false (Reads 01 from right to left. Therefore it is not a palindrome.)
// Follow up: Coud you solve it without converting the integer to a string?

// Example:
// const auto result = palindrome_number(121);

bool palindrome_number(int number)
{
	if (number == 0)
		return true;
	if (number < 0 || number % 10 == 0)
		return false;

	int right_half = 0;
	while (right_half < number)
	{
		right_half = right_half * 10 + number % 10;
		number /= 10;
	}

	// number if digits is even -> check for equality
	// number if digits is odd -> delete last digit from right_half and compare for equality
	return right_half == number || right_half / 10 == number;
}
