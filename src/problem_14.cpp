// The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.
// Hint: The basic equation of a circle is x^2 + y^2 = r^2.

// Example:
// auto result = problem_fourteen(1'000'000);

#include <random>
#include <math.h>
using namespace std;

double problem_fourteen(const unsigned int n) noexcept
{
	const double radius_square = 0.25; // r = 0.5, a and b = 1
	double pi_estimated = 0;
	int circle_count = 0;

	const uniform_real_distribution<double> distr(-0.5, 0.5);
	default_random_engine random_enginde;

	for (unsigned int i = 0; i < n; i++)
	{
		const auto x = distr(random_enginde);
		const auto y = distr(random_enginde);

		if (x * x + y * y <= radius_square)
			circle_count++;
	}

	// see below for explanation
	const auto pi = 4 * static_cast<double>(circle_count) / n;
	return round(pi * 1000) / 1000;
}

// Explanation:
// Area (circle) / Area (square) = Points (circle) / Points (square)
// We imagined a square with a length of 1, i.e. d = 1, and r = 0.5 (1 / 2)
// Area (circle) = PI * r^2; Area (square) = l^2, therefore, the left-hand side is as follows:
// (PI * (0.5)^2) / 1^2 => PI * 0.25 / 1 => PI / 4
// Now let us express PI:
// PI = 4 * Points (circe) / Points (square)

// Implementation
// All random numbers we generate are within [-0.5; 0.5], which guarantees that 100% of (x;y) Points
// will be withing the quare. So we need to get a probaility that a Point is within the circle
// Points (circle) / Points (square).
// This probability is compared to the area equations.
