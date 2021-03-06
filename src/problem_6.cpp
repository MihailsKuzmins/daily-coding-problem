// An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
// If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.

// Example:
// const auto xor_linked_list = new XorLinkedList();
// xor_linked_list->add(1);
// xor_linked_list->add(2);
// xor_linked_list->add(3);
// xor_linked_list->add(4);
//
// const auto result = xor_linked_list->at(2)->get_value();

#include <stdint.h>
#include <functional>
#include <exception>

using namespace std;

template <class T>
struct Node
{
private:
	const T m_value;
	Node<T>* m_xor_node;
	Node<T>* compute_xor(Node<T>* prev_node, Node<T>* next_node) const
	{
		return (Node<T>*)(((uintptr_t)prev_node) ^ ((uintptr_t)next_node));
	}

public:
	Node<T>(const T& value, Node<T>* prev_node, Node<T>* next_node)
		:m_value(value), m_xor_node(compute_xor(prev_node, next_node)) {}

	const T& get_value() const { return m_value; }
	Node<T>* perform_xor(Node<T>* node) const { return compute_xor(m_xor_node, node); }
	void set_node(Node<T>* prev_node, Node<T>* next_node) { m_xor_node = compute_xor(prev_node, next_node); }
};

template <class T>
class XorLinkedList
{
private:
	Node<T>* m_head = nullptr;
	Node<T>* m_tail = nullptr;
	unsigned int m_size = 0;

	void for_each(const function<void(const Node<T>* const)>& func) const;
	Node<T>* get_from_head(const unsigned int&& count) const;
	Node<T>* get_from_tail(const unsigned int&& count) const;

public:
	~XorLinkedList() { for_each([](const Node<T>* const node) { delete node; }); }
	void add(const T& value);
	Node<T>* at(const unsigned int&& index);
};

template <class T>
void XorLinkedList<T>::add(const T& value)
{
	// Last element, {last} ^ nullptr
	Node<T>* new_node = new Node<T>(value, m_tail, nullptr);

	// Set to new: {prev} ^ {new_node}
	if (m_tail)
	{
		auto prev_node = m_tail->perform_xor(nullptr);
		m_tail->set_node(prev_node, new_node);
	}

	if (!m_head)
		m_head = new_node;

	m_tail = new_node;
	m_size++;
}

template <class T>
Node<T>* XorLinkedList<T>::at(const unsigned int&& index)
{
	if (index >= m_size)
		throw out_of_range("Index is greater than size");

	return index < m_size / 2
		? get_from_head(index + 1)
		: get_from_tail(m_size - index);
}

template <class T>
Node<T>* XorLinkedList<T>::get_from_head(const unsigned int&& count) const
{
	Node<T>* current_node = m_head, *prev_node = nullptr, *next_node = nullptr;

	for (unsigned int i = 0; i < count; i++)
	{
		next_node = current_node->perform_xor(prev_node);
		prev_node = current_node;
		current_node = next_node;
	}

	return prev_node;
}

template <class T>
Node<T>* XorLinkedList<T>::get_from_tail(const unsigned int&& count) const
{
	Node<T>* current_node = m_tail, * prev_node = nullptr, * next_node = nullptr;

	for (unsigned int i = 0; i < count; i++)
	{
		prev_node = current_node->perform_xor(next_node);
		next_node = current_node;
		current_node = prev_node;
	}

	return next_node;
}

template <class T>
void XorLinkedList<T>::for_each(const function<void(const Node<T>* const)>& func) const
{
	Node<T>* current_node = m_head, * prev_node = nullptr, * next_node = nullptr;

	while (current_node)
	{
		next_node = current_node->perform_xor(prev_node);
		prev_node = current_node;

		func(current_node);
		current_node = next_node;
	}
}
