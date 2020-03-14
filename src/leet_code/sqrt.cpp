// Implement int `sqrt(int x)`.
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

// Example:
// const auto result = sqrt_custom(2147395600);

// TODO: better
const int sqrt_2(const int&& x) noexcept
{
	auto i = 1;
	for (; x / i >= i; i++);

	return i - 1;
}
