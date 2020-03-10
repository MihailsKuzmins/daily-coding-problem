// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
//  1. Open brackets must be closed by the same type of brackets
//  2. Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.
// Example 1: Input: "()" Output: true
// Example 2: Input: "()[]{}" Output: true
// Example 3: Input: "(]" Output: false
// Example 4: Input: "([)]" Output: false
// Example 5: Input: "{[]}" Output: true

// Example:
// const auto result = valid_parentheses("[])");

#include <string>
#include <stack>
using std::string;
using std::stack;

constexpr bool is_opening_parenthesis(const char& parenthesis);
constexpr char get_closing_parenthesis(const char& parenthesis);

bool valid_parentheses(const string& input)
{
	if (input.length() == 0)
		return true;
	if (!is_opening_parenthesis(input[0]))
		return false;

	stack<char> stack;
	stack.push(get_closing_parenthesis(input[0]));

	for (auto i = 1; i < input.length(); i++)
	{
		if (is_opening_parenthesis(input[i]))
			stack.push(get_closing_parenthesis(input[i]));
		else if (stack.size() == 0 || stack.top() != input[i])
			return false;
		else
			stack.pop();
	}

	return stack.size() == 0;
}

constexpr bool is_opening_parenthesis(const char& parenthesis)
{
	switch (parenthesis)
	{
	case '(': case '{': case '[': return true;
	case ')': case '}': case ']': return false;
	}

	throw "Invalid parenthesis";
}

constexpr char get_closing_parenthesis(const char& parenthesis)
{
	switch (parenthesis)
	{
	case '(': return ')';
	case '{': return '}';
	case '[': return ']';
	}

	throw "Invalid parenthesis";
}
