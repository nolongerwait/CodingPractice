#include <string>

std::string pattern(int n)
{
  if (n < 1)
  {
    return "";
  }
  else
  {
    std::string result = "";
    int total = 2 * n - 1;
    for (int i = 1; i <= n; ++i)
    {
      int blank = (total - (2 * i - 1)) / 2;
      //former blank
      for (int it = 1; it <= blank; ++it)
      {
        result += " ";
      }
      //former number 1-i
      for (int it = 1; it <= i; ++it)
      {
        result += std::to_string(it%10);
      }
      //latter number i-1 - 1
      for (int it = i - 1; it >= 1; --it)
      { 
        result += std::to_string(it%10);
      }
      //latter blank
      for (int it = blank; it >=1; --it)
      {
        result += " ";
      }
      result += "\n";
    }
    //latter
    for (int i = n - 1; i >= 1; --i)
    {
      int blank = (total - (2 * i - 1)) / 2;
      //former blank
      for (int it = 1; it <= blank; ++it)
      {
        result += " ";
      }
      //former number 1-i
      for (int it = 1; it <= i; ++it)
      {
        result += std::to_string(it%10);
      }
      //latter number i-1 - 1
      for (int it = i - 1; it >= 1; --it)
      { 
        result += std::to_string(it%10);
      }
      //latter blank
      for (int it = blank; it >=1; --it)
      {
        result += " ";
      }
      result += "\n";
    }
    result.erase(result.end()-1, result.end());
    return result;
  }
}