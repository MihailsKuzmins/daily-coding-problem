# leet-code-problems

#### Problem "*Two Sum*"
Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.  
You may assume that each input would have **exactly** one solution, and you may not use the same element twice.  
```
Example:  
Given nums = [2, 7, 11, 15], target = 9,  
Because nums[**0**] + nums[**1**] = 2 + 7 = 9,  
return [0, 1].
```
[Solution "*Two Sum*"](two_sum.cpp)
---

#### Problem "*Reverse Integer*"
Given a 32-bit signed integer, reverse digits of an integer.  
**Example 1**:
```
Input: 123
Output: 321
```
**Example 2**:
```
Input: -123
Output: -321
```
**Example 3**:
```
Input: 120
Output: 21
```
**Note**:  
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: `[−231,  231 − 1]`. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.  

[Solution "*Reverse Integer*"](reverse_integer.cpp)
---

#### Problem "*Palindrome Number*"
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward. 
**Example 1**:
```
Input: 121
Output: true
```
**Example 2**:
```
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```
**Example 3**:
```
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```
**Follow up**:  
Coud you solve it without converting the integer to a string? 

[Solution "*Palindrome Number*"](palindrome_number.cpp)
---

#### Problem "*Roman to Integer*"
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.  
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.  

[Solution "*Roman to Integer*"](roman_to_integer.cpp)
---

#### Problem "*Longest Common Prefix*"
Write a function to find the longest common prefix string amongst an array of strings.  
If there is no common prefix, return an empty string `""`.  
**Example 1**:
```
Input: ["flower","flow","flight"]
Output: "fl"
```
**Example 2**:
```
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```
**Note**
All given inputs are in lowercase letters `a-z`.

[Solution "*Longest Common Prefix*"](longest_common_prefix.cpp)
---

#### Problem "*Valid Parentheses*"
Given a string containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.  
An input string is valid if:  
1) Open brackets must be closed by the same type of brackets.
2) Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.  

**Example 1**:
```
Input: "()"
Output: true
```
**Example 2**:
```
Input: "()[]{}"
Output: true
```
**Example 3**:
```
Input: "(]"
Output: false
```
**Example 4**:
```
Input: "([)]"
Output: false
```
**Example 5**:
```
Input: "{[]}"
Output: true
```

[Solution "*Valid Parentheses*"](valid_parentheses.cpp)
---

#### Problem "*Merge Two Sorted Lists*"
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.  
**Example**:
```
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
```

[Solution "*Merge Two Sorted Lists*"](merge_two_sorted_lists.cpp)
---
