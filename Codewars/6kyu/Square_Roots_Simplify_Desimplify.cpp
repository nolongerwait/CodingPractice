#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::string simplify(int num)
{
  std::string result = "";
  int former = 1;
	int last = 1;
	bool flag = true;
	if (num == 0 || num == 1)
	{
		former = num;
    result = result + std::to_string(former);
    return result;
	}
	else if (num < 4)
	{
		last = num;
    result = result + "sqrt "  + std::to_string(last);
    return result;
	}
	else
	{
		while (flag)
		{
			for (int i = 2; i <= std::sqrt(num);)
			{
				if (num % (i * i) == 0)
				{
					former *= i;
					num /= (i * i);
					last = num;
					i = 2;
				}
				else
				{
					++i;
					last = num;
				}
			}
			flag = false;
		}
    if (former != 1 && last != 1)
    {
      result = result + std::to_string(former) + " sqrt " + std::to_string(last); 
    }
    else if (former == 1)
    {
      result = result + "sqrt " + std::to_string(last);
    }
    else if (last == 1)
    {
      result = result + std::to_string(former);
    }
    return result;
	}
}

int desimplify(std::string s)
{
  std::istringstream ss(s);
	std::string part = "";
	int result = 1;
	std::vector<std::string> num;
	while (ss >> part)
	{
		num.push_back(part);
	}
	if (num.size() == 1)
	{
		int tmp = std::stoi(num[0]);
		result = result * tmp * tmp;
	}
	else if (num.size() == 2)
	{
		int tmp = std::stoi(num[1]);
		result = result * tmp;
	}
	else
	{
		int tmp1 = std::stoi(num[0]);
		int tmp2 = std::stoi(num[2]);
		result = result * tmp1 * tmp1 * tmp2;
	}
  return result;
}