// Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.
// For example, given the following Node class
//
// class Node:
//     def __init__(self, val, left=None, right=None):
//         self.val = val
//         self.left = left
//         self.right = right
//
// The following test should pass:
// node = Node('root', Node('left', Node('left.left')), Node('right'))
// assert deserialize(serialize(node)).left.left.val == 'left.left'

// Example
// auto root =
//     new Node("root",
//         new Node("left",
//             new Node("left.left"),
//             new Node("left.right")),
//         new Node("right"));
//
// NodeSerialiser serialiser(root);
// std::cout << serialiser.pre_oder();

#include <string>
#include <functional>

using namespace std;

struct Node
{
	const string value;
	const Node* child_left, *child_right;

	Node(const string value, const Node* const child_left = nullptr, const Node* const child_right = nullptr): value(value), child_left(child_left), child_right(child_right)
	{}
};

class NodeSerialiser
{
private:
	const Node* m_root;
	void for_each_inverse(const Node* const node, const function<void (const Node* const node)> f) const;
	string pre_order_internal(const Node* const node) const;
	string in_order_internal(const Node* const node) const;
	string post_order_internal(const Node* const node) const;
public:
	NodeSerialiser(const Node* const root) :m_root(root) {};
	~NodeSerialiser();
	string pre_oder() const { return this->pre_order_internal(this->m_root); };
	string in_order() const { return this->in_order_internal(this->m_root); };
	string post_order() const { return this->post_order_internal(this->m_root); };
};

void NodeSerialiser::for_each_inverse(const Node* const node, const function<void (const Node* const node)> f) const
{
	if (node == nullptr)
		return;

	this->for_each_inverse(node->child_left, f);
	this->for_each_inverse(node->child_right, f);
	
	// IMPORTANT for the destructor
	f(node);
}

string NodeSerialiser::pre_order_internal(const Node* const node) const
{
	if (node == nullptr)
		return "{}";

	return ("{value=\"" + node->value + "\",left=")
		.append(this->pre_order_internal(node->child_left))
		.append(",right=")
		.append(this->pre_order_internal(node->child_right))
		.append("}");
}

string NodeSerialiser::in_order_internal(const Node* const node) const
{
	if (node == nullptr)
		return "{}";

	return static_cast<string>("{left=")
		.append(this->in_order_internal(node->child_left))
		.append(",value=\"" + node->value + "\",right=")
		.append(this->in_order_internal(node->child_right))
		.append("}");
}

string NodeSerialiser::post_order_internal(const Node* const node) const
{
	if (node == nullptr)
		return "{}";

	return static_cast<string>("{left=")
		.append(this->post_order_internal(node->child_left))
		.append(",right=")
		.append(this->post_order_internal(node->child_right))
		.append(",value=\"" + node->value + "\"}");
}

NodeSerialiser::~NodeSerialiser()
{
	const auto deleteFunc = [](const Node* const node)
	{
		delete node;
	};

	this->for_each_inverse(this->m_root, deleteFunc);
}
