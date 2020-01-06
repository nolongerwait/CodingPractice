#include <string>
#include <sstream>
#include <vector>

class WeightSort
{
public:
    static int weight(const std::string& str);
    static std::string orderWeight(const std::string &strng);
};

int WeightSort::weight(const std::string& str)
{
	int sum = 0;
	long long tmp = std::stoll(str);
	do
	{
		sum += tmp % 10;
	} while (tmp /= 10);
	return sum;
}

std::string WeightSort::orderWeight(const std::string& str)
{
  if (str == "")
  {
    return "";
  }
	std::istringstream ss(str);
	std::vector<std::string> order;
	std::string tmpNum = "";
	while (ss >> tmpNum)
	{
		order.push_back(tmpNum);
	}
	
	for (int i = 0; i < order.size(); ++i)
	{
		for (int j = i + 1; j < order.size(); ++j)
		{
			if (weight(order[i]) > weight(order[j]))
			{
				std::swap(order[i], order[j]);
			}
      if (weight(order[i]) == weight(order[j]))
      {
        if (order[i] > order[j])
        {
          std::swap(order[i], order[j]);
        }
      }
		}
	}

	std::string result = "";
	for (auto it = order.begin(); it != order.end(); ++it)
	{
		result = result + *it + " ";
	}
	result.erase(result.end() - 1, result.end());
	return result;
}