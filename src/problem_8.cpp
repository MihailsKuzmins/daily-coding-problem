// A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
// Given the root to a binary tree, count the number of unival subtrees.
// For example, the following tree has 5 unival subtrees:
//   0
//  / \
// 1   0
//    / \
//   1   0
//  / \
// 1   1

// Example
// const unique_ptr<Node> node_tree (
//     new Node(0,
//         new Node(1),
//         new Node(0,
//             new Node(1,
//				         new Node(1),
//                 new Node(1)),
//             new Node(0))));
//
// auto result = problem_eight(node_tree.get(), node_tree->value);

#include <memory>
using namespace std;

struct Node
{
	const int value;
	const Node* const child_left, *child_right;

	Node(const int value, const Node* const child_left = nullptr, const Node* const child_right = nullptr)
		:value(value), child_left(child_left), child_right(child_right)
	{}

	constexpr bool is_leaf() const
	{
		return this->child_left == nullptr && this->child_right == nullptr;
	}

	constexpr bool is_value_equal(const Node* const node) const
	{
		return !node || node->value == this->value;
	}

	~Node()
	{
		delete this->child_left;
		delete this->child_right;
	}
};

int problem_eight(const Node* const node, int value)
{
	if (node == nullptr)
		return 0;
	if (node->is_leaf())
		return 1;

	const auto leaf_count = problem_eight(node->child_left, node->value) +
		problem_eight(node->child_right, node->value);

	return node->is_value_equal(node->child_left) && node->is_value_equal(node->child_right)
		? leaf_count + 1
    : leaf_count;
}
