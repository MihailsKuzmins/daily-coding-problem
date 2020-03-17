// Given two binary trees, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

// Example:
// const auto tree_one = new Node(1,
//     new Node(2));
//
// const auto tree_two = new Node(1,
//     nullptr,
//     new Node(2));
//
// const auto result = same_tree_1(tree_one, tree_two);
//
// delete tree_one;
// delete tree_two;

struct Node
{
	const int value;
	const Node* const left, * right;
	Node(const int value, Node* const left = nullptr, Node* const right = nullptr)
		: value(value), left(left), right(right) {}
	~Node() { delete left; delete right; }

	bool is_equal(const Node* const node) const noexcept
	{
		if (!node)
			return false;

		return value == node->value &&
			static_cast<bool>(left) == static_cast<bool>(node->left) &&
			static_cast<bool>(right) == static_cast<bool>(node->right);
	}
};

// Without recursion
bool same_tree_1(const Node* const tree_one, const Node* const tree_two)
{
	if (!tree_one && !tree_two)
		return true;
	if (!tree_one || !tree_two)
		return false;

	stack<const Node*> stack_one, stack_two;
	const Node* current_one = tree_one, *current_two = tree_two;

	while (current_one || !stack_one.empty())
	{
		while (current_one)
		{
			if (!current_one->is_equal(current_two))
				return false;

			stack_one.push(current_one);
			stack_two.push(current_two);

			current_one = current_one->left;
			current_two = current_two->left;
		}

		current_one = stack_one.top();
		current_two = stack_two.top();

		stack_one.pop();
		stack_two.pop();

		current_one = current_one->right;
		current_two = current_two->right;
	}

	return true;
}

// Recursion
bool same_tree_2(const Node* const node_one, const Node* const node_two)
{
	if (!node_one && !node_two)
		return true;
	if (!node_one || !node_two)
		return false;

	if (node_one->value != node_two->value)
		return false;

	return same_tree(node_one->left, node_two->left) &&
		same_tree(node_one->right, node_two->right);
}
