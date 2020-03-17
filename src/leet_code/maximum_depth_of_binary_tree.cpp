// Given a binary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

struct Node
{
	const int value;
	const Node* const left, * right;

	Node(const int value, const Node* const left = nullptr, const Node* const right = nullptr)
		: value(value), left(left), right(right) {}
	~Node() { delete left; delete right; }
};

unsigned int maximum_depth_of_binary_tree(const Node* const root) noexcept
{
	if (!root)
		return 0;

	const auto left = maximum_depth_of_binary_tree(root->left);
	const auto right = maximum_depth_of_binary_tree(root->right);

	return left > right
		? left + 1
		: right + 1;
}
