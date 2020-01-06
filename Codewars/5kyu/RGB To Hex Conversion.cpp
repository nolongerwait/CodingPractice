#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b);
};

std::string dec2hex(int i)
{
    if(i < 0)
    {
        i = 0;
    }
    if(i > 255)
    {
        i = 255;
    }
    std::stringstream ss;
    std::string s_temp;
    ss << std::hex << i;
    ss >> s_temp;
    std::string s(2 - s_temp.size(), '0');
    s += s_temp;

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

std::string RGBToHex::rgb(int r, int g, int b)
{
    std::string rHex = dec2hex(r);
    std::string gHex = dec2hex(g);
    std::string bHex = dec2hex(b);

    return rHex + gHex + bHex;
}