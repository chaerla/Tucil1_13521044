#ifndef __UTILS__
#define __UTILS_H__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <time.h>

using namespace std;
/**
 * @brief Get user input, validates it, and maps it to certain value. This function uses sstream to parse user input, so that
 * long inputs are handled as well. e.g. ("A A A A A A A A A")
 *
 * @return vector<int>
 */
vector<int> getInput();

/**
 * @brief generates random cards
 *
 * @return vector<int>
 */
vector<int> randomizeCards();

/**
 * @brief menu
 *
 */
void menu();

void getSolution(int option);

/**
 * @brief saves ans to file as nums[0]_nums[1]_nums[2]_nums[3].txt in output folder
 *
 * @param ans
 * @param nums
 */
void saveToFile(vector<string> ans, vector<int> nums);

#endif