#include <vector>
#include <string>

class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloor)
    {
      	std::vector<std::string> result;
      	int length = 2 * nFloor - 1;
      	for (int i = 1; i <= nFloor; ++i)
      	{
      		int blank = (length - i * 2 + 1) / 2;
      		std::string str = "";
      		for (int j = 1; j <= blank; ++j)
      		{
      			str += " ";
      		}
      		for (int j = 1; j <= i; ++j)
      		{
      			str += "*";
      		}
      		for (int j = i - 1; j >= 1; --j)
      		{
      			str += "*";
      		}
      		for (int j = blank; j >= 1; --j)
      		{
      			str += " ";
      		}
      		result.push_back(str);
      	}
        return result;
    }
};