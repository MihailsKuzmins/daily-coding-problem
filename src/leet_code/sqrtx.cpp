// Implement int `sqrt(int x)`.
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

// Example:
// const auto result = sqrtx_1(2147395600);

const int sqrtx_1(const int&& x) noexcept
{
	switch (x)
	{
	case 0: case 1: return x;
	}

	int left = 1, right = x / 2, answer = left;

	while (left <= right)
	{
		const auto middle = left + (right - left) / 2;

		if (x / middle == middle)
			return middle;

		if (x / middle < middle)
			right = middle - 1;
		else
		{
			answer = middle;
			left = middle + 1;
		}
	}

	return answer;
}

// Not efficient
const int sqrtx_2(const int&& x) noexcept
{
	auto i = 1;
	for (; x / i >= i; i++);

	return i - 1;
}
