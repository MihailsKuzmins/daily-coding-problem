// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Note: Given n will be a positive integer.

// Example:
// const auto result = climbing_stairs(4);

// It's the Fibonacci sequence
const int climbing_stairs(const unsigned int&& n) noexcept
{
	unsigned int current = 1, next = 2;
	for (unsigned int i = 1; i < n; i++)
	{
		next += current;
		current = next - current;
	}

	return current;
}
