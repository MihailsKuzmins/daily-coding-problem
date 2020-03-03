// Given a list of numbersand a number k, return whether any two numbers from the list add up to k.
// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
// Bonus: Can you do this in one pass?

// Example
// int array[4] = {2, 2, 2, 3};
// const auto size = sizeof(array) / sizeof(*array);
// auto result = checkHasSum(5, array, size);

#include <vector>

using namespace std;

bool problem_one(int sum, int numbers[], const unsigned int size)
{
    vector<int> vector;

    for (unsigned int i = 0; i < size; i++)
    {
        const auto possible_answer = sum - numbers[i];
        if (possible_answer <= 0)
            continue;

        auto possible_answer_checked = false;
        for (auto item : vector)
        {
            // already checked
            if (item == numbers[i])
            {
                possible_answer_checked = true;
                break;
            }
            else if (item == possible_answer)
                return true;
        }

        if (!possible_answer_checked)
            vector.push_back(numbers[i]);
    }
    
    return false;
}
