// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
// Note: Bonus points if you could solve it both recursively and iteratively.

// Example:
// const auto node = new Node(7,
//     new Node(-64,
//         new Node(-6,
//             new Node(88),
//             new Node(-44)),
//         new Node(-90,
//             new Node(68),
//             new Node(65))),
//     new Node(-64,
//         new Node(-90,
//             new Node(76),
//             new Node(68)),
//         new Node(-6,
//             new Node(-44),
//             new Node(88))));
//
// const auto result = symmetric_tree_1(node);
// delete node;

#include <stack>
using namespace std;

struct Node
{
	const int value;
	const Node* const left, * right;
    Node(const int value, Node* const left = nullptr, Node* const right = nullptr)
		:  (value), left(left), right(right) {}
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

// With a Stack
bool symmetric_tree_1(const Node* const root)
{
    if (!root)
        return true;

    stack<const Node*> stack_left, stack_right;
    const Node* current_left = root->left, * current_right = root->right;

    if (!current_left && !current_right)
        return true;
    if (!current_left || !current_right)
        return false;

    while (current_left || current_right || !stack_left.empty())
    {
        while (current_left)
        {
            if (!current_left->is_equal(current_right))
                return false;

            stack_left.push(current_left);
            stack_right.push(current_right);

            current_left = current_left->left;
            current_right = current_right->right;
        }

        current_left = stack_left.top();
        current_right = stack_right.top();

        stack_left.pop();
        stack_right.pop();

        current_left = current_left->right;
        current_right = current_right->left;
    }

    return true;
}
