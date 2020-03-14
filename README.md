# daily-coding-problem

### leet-code-problems
There is a very nice platform for solving different kinds of problems [LeetCode](https://leetcode.com/). Sometimes I try to solve their problems and publish some solutions [here](src/leet_code). Definitely encourage you to visit their webpage.  
#### Problem 1  
Given a list of numbersand a number *k*, return whether any two numbers from the list add up to *k*.  
For example, given `[10, 15, 3, 7]` and *k* of *17*, return true since *10 + 7* is *17*.  
Bonus: Can you do this in one pass?  

[Solution #1](src/problem_1.cpp)
---

#### Problem 2  
Given an array of integers, return a new array such that each element at index *i* of the new array is the product of all the numbers in the original array except the one at *i*.  
For example, if our input was `[1, 2, 3, 4, 5]`, the expected output would be `[120, 60, 40, 30, 24]`. If our input was `[3, 2, 1]`, the expected output would be `[2, 3, 6]`.  
Follow-up: what if you can't use division?  

[Solution #2](src/problem_2.cpp)
---

#### Problem 3
Given the root to a binary tree, implement `serialize(root)`, which serializes the tree into a string, and `deserialize(s)`, which deserializes the string back into the tree.  
For example, given the following `Node` class.
```python
class Node:
	def __init__(self, val, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right
```
The following test should pass:
```python
node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
```
[Solution #3](src/problem_3.cpp) (only serialisation)
---

#### Problem 4  
Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.  
For example, the input `[3, 4, -1, 1]` should give *2*. The input `[1, 2, 0]` should give *3*.  
You can modify the input array in-place.  

[Solution #4](src/problem_4.cpp)
---

#### Problem 5
`cons(a, b)` constructs a pair, and `car(pair)` and `cdr(pair)` returns the first and last element of that pair. For example, `car(cons(3, 4))` returns *3*, and `cdr(cons(3, 4))` returns *4*.  
Given this implementation of `cons`:
```python
def cons(a, b):
	def pair(f):
		return f(a, b)
	return pair
```
Implement `car` and `cdr`.  

[Solution #5](src/problem_5.cpp)
---

#### Problem 6
An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding `next` and `prev` fields, it holds a field named `both`, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an `add(element)` which adds the element to the end, and a `get(index)` which returns the node at index.  
If using a language that has no pointers (such as Python), you can assume you have access to `get_pointer` and `dereference_pointer` functions that converts between nodes and memory addresses.  

[Solution #6](src/problem_6.cpp)
---

#### Problem 7
Given the mapping *a = 1, b = 2, ... z = 26*, and an encoded message, count the number of ways it can be decoded.  
For example, the message *111* would give *3*, since it could be decoded as *aaa*, *ka*, and *ak*.  
You can assume that the messages are decodable. For example, *001* is not allowed.

[Solution #7](src/problem_7.cpp)
---

#### Problem 8
A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.  
Given the root to a binary tree, count the number of unival subtrees.  
For example, the following tree has *5* unival subtrees:
```
   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
```

[Solution #8](src/problem_8.cpp)
---

#### Problem 10
Implement a job scheduler which takes in a function *f* and an integer *n*, and calls *f* after *n* milliseconds.  

[Solution #10](src/problem_10.cpp)
---

#### Problem 14
The area of a circle is defined as `πr^2`. Estimate π to 3 decimal places using a Monte Carlo method.  
*Hint*: The basic equation of a circle is `x^2 + y^2 = r^2`.

[Solution #14](src/problem_14.cpp)
---
