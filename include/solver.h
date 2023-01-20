#ifndef __SOLVER__
#define __SOLVER_H__

#include <utility>
#include <string>
#include <vector>

using namespace std;
/**
 * @brief function to evaluate math operation with x, y, and op (+,-,*,/)
 *
 * @param x
 * @param y
 * @param op
 * @param exprX evaluated value of exprX equals float x
 * @param exprY evaluated value of exprX equals float y
 * @return pair<float, string> returns evaluated value and the expression evaluated
 */
pair<float, string> eval(float x, float y, char op, string exprX, string exprY);

/**
 * @brief a recursive function that finds all possible math operations from an array of integers
 *
 * @param arr
 * @return vector<pair<float, string>>
 */
vector<pair<float, string>> solve(vector<int> arr);

/**
 * @brief find all the permutations of input array then returns each permutations that can be operated to result in 24
 *
 * @param input
 * @return vector<string>
 */
vector<string> solveAll(vector<int> input);

#endif