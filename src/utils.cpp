#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include "../include/utils.h"
#include "../include/solver.h"

using namespace std;
using namespace std::chrono;

vector<int> getInput()
{
    map<string, int> toInt{{"A", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}};
    cout << endl;
    cout << "Input 4 cards (integers 2-9, A, J, K, Q) separated by space." << endl;
    cout << "e. g. \"A J 3 4\"." << endl;
    cout << "Cards: ";
    string input;
    getline(cin, input);
    vector<int> res;
    stringstream ss(input);
    string chr;
    while (ss >> chr)
    {
        auto it = toInt.find(chr);
        if (it != toInt.end())
        {
            res.push_back(it->second);
        }
        else
        {
            cout << chr << " is invalid." << endl;
            cout << "Valid input is integer 2-9, A, Q, K, J" << endl;
            return getInput();
        }
    }
    if (res.size() != 4)
    {
        cout << "Please input exactly 4 cards separated by space." << endl;
        return getInput();
    }
    return res;
}

vector<int> randomizeCards()
{
    srand(time(NULL));
    vector<int> nums;
    cout << "Generated cards: ";
    for (int i = 0; i < 4; i++)
    {
        int num = rand() % 13 + 1;
        nums.push_back(num);
        switch (num)
        {
        case 1:
            cout << "A ";
            break;
        case 11:
            cout << "J ";
            break;
        case 12:
            cout << "Q ";
            break;
        case 13:
            cout << "K ";
            break;
        default:
            cout << num << " ";
            break;
        }
    }
    cout << endl;
    cout << endl;

    return nums;
}

void menu()
{
    string option;
    cout << endl;
    cout << "Menu:\n"
            "1. Randomize cards\n"
            "2. Input cards\n"
            "0. Exit \n"
         << endl;
    cout << "Option (1/2/0): ";
    getline(cin, option);
    if (option == "1")
    {
        getSolution(1);
    }
    else if (option == "2")
    {
        getSolution(2);
    }
    else if (option == "0")
    {
        cout << endl;
        cout << "########################################################" << endl;
        cout << "               Thanks for using 24 Solver               " << endl;
        cout << "########################################################" << endl;
        cout << endl;
    }
    else
    {
        cout << "Unknown input! Please only input 1/2/0" << endl;
        menu();
    }
}

void getSolution(int option)
{
    vector<int> nums;
    if (option == 1)
    {
        nums = randomizeCards();
    }
    else
    {
        nums = getInput();
    }
    auto start = high_resolution_clock::now();
    vector<string> ans = solveAll(nums);
    auto stop = high_resolution_clock::now();
    float duration = (duration_cast<microseconds>(stop - start)).count() / (float)1000;
    int cnt = ans.size();
    int i = 0;
    if (cnt != 0)
    {
        cout << endl;
        cout << ans.size() << " solutions found!" << endl;
        for (auto n : ans)
        {
            // substr is used to removed the first and last unnecessary brackets
            cout << "Solution #" << i + 1 << ": " << n.substr(1, n.size() - 2) << endl;
            i++;
        }
    }
    else
    {
        cout << "No solution found" << endl;
    }
    cout << setprecision(3) << fixed;
    cout << "Execution time: " << duration << " ms" << endl;
    saveToFile(ans, nums);
}

void saveToFile(vector<string> ans, vector<int> nums)
{
    string option;
    cout << endl;
    cout << "Save solutions to file (Y/N)? ";
    getline(cin, option);
    if (option == "N" || option == "n")
    {
        menu();
    }
    else if (option == "Y" || option == "y")
    {
        string filename = "";
        for (auto n : nums)
        {
            filename += to_string(n);
            if (n != nums.back())
            {
                filename += "_";
            }
        }
        filename += ".txt";
        ofstream fout("../output/" + filename);
        if (fout.is_open())
        {
            int cnt = ans.size();
            int i = 0;
            if (cnt != 0)
            {
                fout << ans.size() << " solutions found!" << endl;
                for (auto n : ans)
                {
                    // substr is used to removed the first and last unnecessary brackets
                    fout << "Solution #" << i + 1 << ": " << n.substr(1, n.size() - 2) << endl;
                    i++;
                }
            }
            else
            {
                fout << "No solution found" << endl;
            }
            cout << "Successfully saved to \"output\" folder as " << filename << endl;
        }
        else
        {
            cout << "An error occured. The file was not saved." << endl;
        }
        menu();
    }
    else
    {
        cout << "Input is invalid!" << endl;
        saveToFile(ans, nums);
    }
}