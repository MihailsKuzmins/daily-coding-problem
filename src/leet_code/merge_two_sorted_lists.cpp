// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
// Example: Input: 1->2->4, 1->3->4 Output: 1->1->2->3->4->4

// Example:
// auto list_one = new Node(1,
//     new Node(2,
//         new Node(4)));
//
// auto list_two = new Node(1,
//     new Node(3,
//         new Node(4)));
//
// auto merged_list = merge_two_lists(list_one, list_two);

using namespace std;

struct Node
{
	const int value;
	Node* next;

	Node(const int value, Node* next = nullptr): value(value), next(next)
	{}

	~Node()
	{
		delete this->next;
	}
};

Node* merge_two_lists_1(Node* list_one, Node* list_two)
{
	if (!list_one)
		return list_two;
	if (!list_two)
		return list_one;

	Node* start_node = nullptr;

	auto move_start_node = [&](Node*& next_node)
	{
		start_node = next_node;
		next_node = next_node->next;
	};

	if (list_one->value > list_two->value)
		move_start_node(list_two);
	else
		move_start_node(list_one);

	Node* end_node = start_node;

	auto move_end_node = [&](Node*& next_node)
	{
		end_node = end_node->next = next_node;
		next_node = next_node->next;
	};

	while (true)
	{
		if (!list_one)
		{
			end_node->next = list_two;
			break;
		}
		if (!list_two)
		{
			end_node->next = list_one;
			break;
		}

		if (list_one->value > list_two->value)
			move_end_node(list_two);
		else
			move_end_node(list_one);
	}

	return start_node;
}
