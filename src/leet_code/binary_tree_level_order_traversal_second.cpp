// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// Example:
// const auto root = new Node(0,
//     new Node(2,
//         new Node(1,
//             new Node(5),
//                 new Node(1))),
//         new Node(4,
//             new Node(3,
//                 nullptr,
//                 new Node(6)),
//             new Node(-1,
//                 nullptr,
//                 new Node(8))));
//
// const auto result = binary_tree_level_order_traversal_second(root);
// delete root;

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
	const int value;
	const Node* const left, * right;
	Node(const int value, const Node* const left = nullptr, const Node* const right = nullptr)
		: value(value), left(left), right(right) {}
	~Node() { delete left; delete right; }
};

vector<vector<int>> binary_tree_level_order_traversal_second(const Node* const root) noexcept
{
	vector<vector<int>> main_vector;

	if (!root)
		return main_vector;

	queue<const Node*> queue;
	queue.emplace(root);

	while (!queue.empty())
	{
		const auto size = queue.size();
		vector<int> level(size);

		for (auto i = 0; i < size; i++)
		{
			const auto node = queue.front();
			queue.pop();

			level[i] = node->value;

			if (node->left)
				queue.emplace(node->left);
			if (node->right)
				queue.emplace(node->right);
		}

		main_vector.emplace_back(move(level));
	}

	reverse(main_vector.begin(), main_vector.end());
	return main_vector;
}
