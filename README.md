# daily-coding-problem

#### Problem 1  
Given a list of numbersand a number k, return whether any two numbers from the list add up to k.  
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.  
Bonus: Can you do this in one pass?  

[Solution #1](src/problem_1.cpp)
---

#### Problem 2  
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.  
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].  
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
For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.  
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
