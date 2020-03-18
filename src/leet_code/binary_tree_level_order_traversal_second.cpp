// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

struct Node
{
	const int value;
	const Node* const left, * right;
	Node(const int value, const Node* const left = nullptr, const Node* const right = nullptr)
		: value(value), left(left), right(right) {}
	~Node() { delete left; delete right; }
};

vector<vector<int>> binary_tree_level_order_traversal_second(const Node* const root)
{
	vector<vector<int>> main_vector;

	if (!root)
		return main_vector;

	stack<const Node*> stack;
	const Node* current = root;

	while (!stack.empty() || current)
	{
		while (current)
		{
			cout << current->value << endl;

			stack.push(current);
			current = current->left;
		}

		current = stack.top();
		stack.pop();

		current = current->right;
	}

	return main_vector;
}

void run_same_tree()
{
	const auto root = new Node(3,
		new Node(9),
		new Node(20,
			new Node(15),
			new Node(7)));

	const auto result = binary_tree_level_order_traversal_second(root);

	delete root;
}
