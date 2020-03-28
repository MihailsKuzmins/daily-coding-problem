// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

struct TreeNode
{
	const int val;
	TreeNode* left, * right;
	TreeNode(const int value, TreeNode* left = nullptr, TreeNode* right = nullptr)
		: val(value), left(left), right(right) {}
};

// Recursion
TreeNode* convert_sorted_array_to_binary_search_tree(const vector<int>& nums)
{
	return nullptr;
}

TreeNode* helper(const vector<int>& nums, const int start, const int end) noexcept
{
	if (start > end)
		return nullptr;

	const auto current_index = start + (end - start) / 2;
	const auto node = new TreeNode(nums[current_index]);
	node->left = helper(nums, start, current_index - 1);
	node->right = helper(nums, current_index + 1, end);

	return node;
}
