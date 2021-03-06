# leet-code-problems

#### Problem "*Two Sum*"
Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.  
You may assume that each input would have **exactly** one solution, and you may not use the same element twice.  

[Solution "*Two Sum*"](two_sum.cpp)
---

#### Problem "*Reverse Integer*"
Given a 32-bit signed integer, reverse digits of an integer.  
**Note**:  
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: `[−231,  231 − 1]`. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.  

[Solution "*Reverse Integer*"](reverse_integer.cpp)
---

#### Problem "*Palindrome Number*"
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward. 
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

[Solution "*Valid Parentheses*"](valid_parentheses.cpp)
---

#### Problem "*Merge Two Sorted Lists*"
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.  

[Solution "*Merge Two Sorted Lists*"](merge_two_sorted_lists.cpp)
---

#### Problem "*Remove Duplicates from Sorted Array*"
Given a sorted array nums, remove the duplicates **in-place** such that each element appear only once and return the new length.  
Do not allocate extra space for another array, you must do this by **modifying the input array** in-place with O(1) extra memory.  

[Solution "*Remove Duplicates from Sorted Array*"](remove_duplicates_from_sorted_array.cpp)
---

#### Problem "*Remove Element*"
Given an array nums and a value val, remove all instances of that value **in-place** and return the new length.  
Do not allocate extra space for another array, you must do this by **modifying the input array** in-place with O(1) extra memory.  
The order of elements can be changed. It doesn't matter what you leave beyond the new length.  

[Solution "*Remove Element*"](remove_element.cpp)
---

#### Problem "*Implement strStr()*"
Implement `strStr()`.  
Return the index of the first occurrence of needle in haystack, or **-1** if needle is not part of haystack.  

[Solution "*Implement strStr()*"](str_str.cpp)
---

#### Problem "*Search Insert Position*"
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.  
You may assume no duplicates in the array.  

[Solution "*Search Insert Position*"](search_insert_position.cpp)
---

#### Problem "*Count and Say*"
Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.  
Note: Each term of the sequence of integers will be represented as a string.  

[Solution "*Count and Say*"](count_and_say.cpp)
---

#### Problem "*Maximum Subarray*"
Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.  
**Follow up**:  
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.  

[Solution "*Maximum Subarray*"](maximum_subarray.cpp)
---

#### Problem "*Length of Last Word*"
Given a string s consists of upper/lower-case alphabets and empty space characters `' '`, return the length of last word (last word means the last appearing word if we loop from left to right) in the string.  
If the last word does not exist, return 0.  
**Note**: A word is defined as a **maximal substring** consisting of non-space characters only.

[Solution "*Length of Last Word*"](length_of_last_word.cpp)
---

#### Problem "*Plus One*"
Given a **non-empty** array of digits representing a non-negative integer, plus one to the integer.  
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.  
You may assume the integer does not contain any leading zero, except the number 0 itself.  

[Solution "*Plus One*"](plus_one.cpp)
---

#### Problem "*Add Binary*"
Given two binary strings, return their sum (also a binary string).  
The input strings are both **non-empty** and contains only characters `1` or `0`.

[Solution "*Add Binary*"](add_binary.cpp)
---

#### Problem "*Sqrt(x)*"
Implement `int sqrt(int x)`.  
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.  
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.  

[Solution "*Sqrt(x)*"](sqrtx.cpp)
---

#### Problem "*Climbing Stairs*"
You are climbing a stair case. It takes n steps to reach to the top.  
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?  
**Note**: Given *n* will be a positive integer.  

[Solution "*Climbing Stairs*"](climbing_stairs.cpp)
---

#### Problem "*Remove Duplicates from Sorted List*"
Given a sorted linked list, delete all duplicates such that each element appear only *once*.  

[Solution "*Remove Duplicates from Sorted List*"](remove_duplicates_from_sorted_list.cpp)
---

#### Problem "*Merge Sorted Array*"
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.  
**Note**:
- The number of elements initialized in *nums1* and *nums2* are *m* and *n* respectively.
- You may assume that *nums1* has enough space (size that is greater or equal to *m* + *n*) to hold additional elements from *nums2*.

[Solution "*Merge Sorted Array*"](merge_sorted_array.cpp)
---

#### Problem "*Same Tree*"
Given two binary trees, write a function to check if they are the same or not.  
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.  

[Solution "*Same Tree*"](same_tree.cpp)
---

#### Problem "*Symmetric Tree*"
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).  
**Note**: Bonus points if you could solve it both recursively and iteratively.

[Solution "*Symmetric Tree*"](symmetric_tree.cpp)
---

#### Problem "*Maximum Depth of Binary Tree*"
Given a binary tree, find its maximum depth.  
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.  
**Note**: A leaf is a node with no children.

[Solution "*Maximum Depth of Binary Tree*"](maximum_depth_of_binary_tree.cpp)
---
