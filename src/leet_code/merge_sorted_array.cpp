// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// Example:
// vector<int> v1{ -1,0,1,1,0,0,0,0,0 }, v2{ -1,0,2,2,3 };
// merge_sorted_array(v1, 4, v2, 5);

#include <vector>
using namespace std;

void merge_sorted_array(vector<int>& numbers_one, const unsigned int size_one, const vector<int>& numbers_two, const unsigned int size_two) noexcept
{
	int i = size_one - 1, j = size_two - 1, max_index = size_one + size_two - 1;

	while (max_index >= 0)
	{
		if (j < 0 || (i >= 0 && numbers_one[i] > numbers_two[j]))
			numbers_one[max_index--] = numbers_one[i--];
		else
			numbers_one[max_index--] = numbers_two[j--];
	}
}
