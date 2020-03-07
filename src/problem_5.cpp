// cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.
// Given this implementation of cons:
//
// def cons(a, b):
//     def pair(f):
//         return f(a, b)
//         return pair
//
// Implement car and cdr.

// Example
// auto cons_result = cons(3, 4);
// auto car_result = car(cons_result);
// auto cdr_result = cdr(cons_result);

#include <functional>

using namespace std;

function<int (function<int(const int, const int)>)> cons(const int& a, const int& b)
{
	return [&](function<int(const int, const int)> f)
	{
		return f(a, b); 
	};
}

int car(function<int(function<int(const int, const int)>)> f)
{
	return f([](const int arg1, const int arg2)
	{
		return arg1;
	});
}

int cdr(function<int(function<int(const int, const int)>)> f)
{
	return f([](const int arg1, const int arg2)
	{
		return arg2;
	});
}
