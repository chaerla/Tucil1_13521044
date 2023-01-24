#include "../include/permutation.h"
#include "../include/solver.h"
#include <iostream>

pair<float, string> eval(float x, float y, char op, string exprX, string exprY)
{
    switch (op)
    {
    case '+':
        return {x + y, "(" + exprX + "+" + exprY + ")"};
    case '-':
        return {x - y, "(" + exprX + "-" + exprY + ")"};
    case '/':
        return {x / y, "(" + exprX + "/" + exprY + ")"};
    default:
        return {x * y, "(" + exprX + "*" + exprY + ")"};
    }
};

vector<pair<float, string>> solve(vector<int> arr)
{
    vector<pair<float, string>> ans;
    char ops[] = {'+', '-', '*', '/'};
    int size = arr.size();
    if (size == 1)
    {
        return {{(float)arr[0], to_string(arr[0])}};
    }
    if (size == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            if (ops[i] == '/' && arr[1] == 0)
            {
                continue;
            }
            ans.push_back(eval((float)arr[0], (float)arr[1], ops[i], to_string(arr[0]), to_string(arr[1])));
        }
    }
    else
    {
        for (int i = 1; i < size; i++)
        {
            vector<int> left_arr(arr.begin(), arr.begin() + i);
            vector<int> right_arr(arr.begin() + i, arr.end());

            auto left = solve(left_arr);
            auto right = solve(right_arr);

            for (auto l : left)
            {
                for (auto r : right)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (ops[i] == '/' && r.first == 0)
                        {
                            continue;
                        }
                        pair<float, string> temp = eval(l.first, r.first, ops[i], l.second, r.second);
                        if (size == 4 && temp.first == 24)
                        {
                            ans.push_back(temp);
                        }
                        else if (arr.size() != 4)
                        {
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
    }
    return ans;
};

vector<string> solveAll(vector<int> input)
{
    vector<string> ret;
    set<vector<int>> permutations;
    permute(input, 0, input.size() - 1, permutations);
    for (auto n : permutations)
    {
        vector<pair<float, string>> ans = solve(n);
        for (auto i : ans)
        {
            ret.push_back(i.second);
        }
    }
    return ret;
}
