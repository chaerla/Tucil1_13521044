#ifndef __PERMUTATION__
#define __PERMUTATION_H__

#include <string>
#include <set>
#include <vector>

using namespace std;

void permute(vector<int> arr, int l, int r, set<vector<int>> &permutations);

#endif