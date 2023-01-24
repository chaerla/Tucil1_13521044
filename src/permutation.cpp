#include "../include/permutation.h"
#include <iostream>

void permute(vector<int> arr, int l, int r, set<vector<int>> &permutations)
{
    if (l == r)
    {
        permutations.insert(arr);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(arr[l], arr[i]);
            permute(arr, l + 1, r, permutations);
            swap(arr[l], arr[i]);
        }
    }
}
