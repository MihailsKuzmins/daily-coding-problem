// Given a sorted linked list, delete all duplicates such that each element appear only once.

// Example:
// const auto node = new ListNode(2,
//     new ListNode(2,
//         new ListNode(3,
//             new ListNode(3,
//                 new ListNode(5)))));
//
// const auto result = remove_duplicates_from_sorted_list(node);
// while (result)
// {
//     cout << result->value << endl;
//     auto tmp_node = result;
//     
//     result = result->next;
//     delete tmp_node;
// }

struct Node
{
	const int value;
	Node* next;
	Node(const int value, Node* node = nullptr): value(value), next(node) {}
};

Node* remove_duplicates_from_sorted_list(Node* head)
{
	if (!head)
		return nullptr;

	auto value = head->value;
	auto current_node = head;

	while (current_node->next)
	{
		if (current_node->next->value != value)
		{
			value = current_node->next->value;
			current_node = current_node->next;
		}
		else
		{
			auto tmp_node = current_node->next;
			current_node->next = current_node->next->next;
			delete tmp_node;
		}
	}

	return head;
}
