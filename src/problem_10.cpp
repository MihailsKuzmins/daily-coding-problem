// Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.

// Example
// const auto lambda = []() { cout << "done" << endl; };
// problem_ten(lambda, 2000);

#include <functional>
#include <chrono>
#include <thread>

using std::function;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void problem_ten(const function<void()>& f, const int delay_ms)
{
	sleep_for(milliseconds(delay_ms));
	f();
}
