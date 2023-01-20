#ifndef __PERMUTATION__
#define __PERMUTATION_H__

#include <utility>
#include <string>
#include <vector>

using namespace std;

void permute(vector<int> &arr, vector<int> &curr, vector<vector<int>> &res, vector<bool> &visited);

vector<vector<int>> getPermutation(vector<int> &arr);

#endif