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
    permute(nums, curr, res, visited);

    // checker
    // for (int i = 0; i < (int)res.size(); i++)
    // {

    //     // Traverse every column
    //     for (auto value : res[i])
    //     {
    //         cout << value << " ";
    //     }

    //     cout << '\n';
    // }
    return res;
}
