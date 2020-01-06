#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
#include <utility>

using namespace std;

vector<string> one_digit {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> two_digit_first {"ten", "eleven", "twelve", "thirteen", "fourtenn", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> two_digit {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

class Dinglemouse
{
public:
    static vector<int> sort(const vector<int> &array)
    {
        vector<pair<string, int>> name_array;
        for(auto i:array)
        {
            string name = to_string(i);
            if(name.length() == 1)
            {
                name_array.push_back(make_pair(name_of_one_digit(name), i));
            }
            else if(name.length() == 2)
            {
                name_array.push_back(make_pair(name_of_two_digit(name), i));
            }
            else
            {
                name_array.push_back(make_pair(name_of_three_digit(name), i));
            }
        }
        std::sort(name_array.begin(), name_array.end(),judge);
        vector<int> result;
        for(auto itor = name_array.begin(); itor != name_array.end(); itor++)
        {
            cout << (*itor).first << " " << (*itor).second << endl;
            result.push_back((*itor).second);
        }
        return result;
    }

    static bool judge(const pair<string,int> a, const pair<string ,int> b)
    {
        return a.first<b.first;
    }

    static string name_of_one_digit(string name)
    {
        return one_digit.at(name[0] - '0');
    }
    
    static string name_of_two_digit(string name)
    {
        int first = name[0] - '0';
        int second = name[1] - '0';
        if(first == 1)
        {
            return two_digit_first.at(second);
        }
        else
        {
            if(second == 0)
            {
                return two_digit.at(first);
            }
            else
            {
                return two_digit.at(first) + "-" + one_digit.at(second);
            }
        }
    }

    static string name_of_three_digit(string name)
    {
        int first = name[0] - '0';
        int second = name[1] - '0';
        int third = name[2] - '0';
        if(second == 0 && third == 0)
        {
            return one_digit.at(first) + " " + "hundred";
        }
        else if(third == 0)
        {
            return one_digit.at(first) + " " + "hundred" + " " + two_digit.at(second);
        }
        else if(second == 1)
        {
            return one_digit.at(first) + " " + "hundred" + " " + two_digit_first.at(third);
        }
        else if(second == 0)
        {
            return one_digit.at(first) + " " + "hundred" + " " + one_digit.at(third);
        }
        else
        {
            return one_digit.at(first) + " " + "hundred" + " " + two_digit.at(second) + "-" + one_digit.at(third);
        }
    }
};