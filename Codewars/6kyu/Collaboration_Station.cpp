#include <vector>
#include <string>

std::vector<std::string> splitMessage(std::string message, int count)
{
    std::vector<std::string> result;
    for (int i = 0; i < count; ++i)
  	{
  		result.push_back("");
  	}
  	for (int it = 1; it <= count; ++it)
  	{
  		int tmp = 0;
  		for (std::size_t i = 1; i < message.size() + 1; ++i)
  		{
  
  			if (i == tmp * count + it)
  			{
  				result[it - 1] += message[i - 1];
  				++tmp;
  			}
  			else
  			{
  				result[it - 1] += "-";
  			}
  		}
  	 }
    return result;
}