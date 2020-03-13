// An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
// If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.

// Example:
// const auto xor_linked_list = new XorLinkedList();
// xor_linked_list->add(1);
// xor_linked_list->add(2);
// xor_linked_list->add(3);
// xor_linked_list->add(4);

#include <stdint.h>
#include <functional>

using namespace std;

struct Node
{
private:
	const int m_value;
	Node* m_xor_node;
	Node* compute_xor(Node* prev_node, Node* next_node) const
	{
		return (Node*)(((uintptr_t)prev_node) ^ ((uintptr_t)next_node));
	}

public:
	Node(const int value, Node* prev_node, Node* next_node)
		:m_value(value), m_xor_node(this->compute_xor(prev_node, next_node)) {}

	int get_value() const { return this->m_value; }
	Node* perform_xor(Node* node) const { return this->compute_xor(this->m_xor_node, node);; }
	void set_node(Node* prev_node, Node* next_node) { this->m_xor_node = this->compute_xor(prev_node, next_node); }
};

class XorLinkedList
{
private:
	Node* m_tail = nullptr;

public:
	~XorLinkedList() { this->for_each_reverse([](const Node* const node) { delete node; }); }
	void add(int value);
	void for_each_reverse(const function<void (const Node* const)> func) const;
};

void XorLinkedList::add(int value)
{
	// Last element, {last} ^ nullptr
	Node* new_node = new Node(value, this->m_tail, nullptr);

	// Set to new: {prev} ^ {new_node}
	if (this->m_tail != nullptr)
	{
		auto prev_node = this->m_tail->perform_xor(nullptr);
		this->m_tail->set_node(prev_node, new_node);
	}

	this->m_tail = new_node;
}

void XorLinkedList::for_each_reverse(const function<void(const Node* const)> func) const
{
	Node* current = this->m_tail, * next_node = nullptr, * prev_node = nullptr;

	while (current != nullptr)
	{
		prev_node = current->perform_xor(next_node);
		next_node = current;

		func(current);
		current = prev_node;
	}
}
