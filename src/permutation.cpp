#include "../include/permutation.h"
#include <iostream>

void permute(vector<int> &arr, vector<int> &curr, vector<vector<int>> &res, vector<bool> &visited)
{
    if (curr.size() == arr.size())
    {
        res.push_back(curr);
    }

    for (int i = 0; i < arr.size(); i++)
    {

        if (visited[i] || (i > 0 && arr[i] == arr[i - 1] && !visited[i - 1]))
            continue;

        visited[i] = true;

        curr.push_back(arr[i]);

        permute(arr, curr, res, visited);

        visited[i] = false;

        curr.pop_back();
    }
}

vector<vector<int>> getPermutation(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<bool> visited((int)nums.size(), false);
    vector<int> curr;
    // sort the array -- preprocess
    int i, j;
    for (i = 0; i < nums.size() - 1; i++)
        for (j = 0; j < nums.size() - i - 1; j++)
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
    permute(nums, curr, res, visited);
    return res;
}
