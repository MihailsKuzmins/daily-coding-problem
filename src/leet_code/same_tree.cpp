// Given two binary trees, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

struct Node
{
	const int value;
	const Node* const left, * const right;

	Node(const int value, const Node* const left = nullptr, const Node* const right = nullptr)
		: value(value), left(left), right(right) {}

	~Node()
	{
		delete left;
		delete right;
	}
};

// Recursion
bool same_tree_1(const Node* const node_one, const Node* const node_two)
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
