#include <string>
#include <vector>

class DirReduction
{
public:
    static bool judge(std::string strF, std::string strL);
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr);
};

bool DirReduction::judge(std::string strF, std::string strL)
{
	if (strF == "NORTH")
	{
		if (strL == "SOUTH")
			return true;
		else
			return false;
	}
	if (strF == "SOUTH")
	{
		if (strL == "NORTH")
			return true;
		else
			return false;
	}
	if (strF == "EAST")
	{
		if (strL == "WEST")
			return true;
		else
			return false;
	}
	if (strF == "WEST")
	{
		if (strL == "EAST")
			return true;
		else
			return false;
	}
}

std::vector<std::string> DirReduction::dirReduc(std::vector<std::string> &arr)
{
  std::vector<std::string> result;
	result.push_back(*(arr.begin()));
	for (auto it = arr.begin() + 1; it != arr.end(); ++it)
	{
		result.push_back(*it);
		if (result.size() < 2)
		{
			continue;
		}
		if (judge(*(result.end() - 2), *(result.end() - 1)))
		{
			result.pop_back();
			result.pop_back();
		}
	}
  return result;
}