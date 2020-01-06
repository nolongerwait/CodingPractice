#include <cmath>
#include <vector>
#include <string>

class CaesarCipher
{
  public:
    static std::vector<std::string> movingShift(const std::string &s, int shift);
    static std::string demovingShift(std::vector<std::string> &s, int shift);
};

std::vector<std::string> CaesarCipher::movingShift(const std::string &s, int shift)
{
    // encode the string
    std::string encode_str = s;
    for(int i = 0; i < encode_str.length(); i++)
    {
        if(encode_str[i] >= 'a' && encode_str[i] <= 'z')
        {
            encode_str[i] = (encode_str[i] - 'a' + shift) % 26 + 'a';
        }
        if(encode_str[i] >= 'A' && encode_str[i] <= 'Z')
        {
            encode_str[i] = (encode_str[i] - 'A' + shift) % 26 + 'A';
        }
        shift++;
    }

    // divided by 5 parts
    int cut = ceil(encode_str.length() / 5.0);

    std::vector<std::string> encode;
    for(int i = 0; i < 5; i++)
    {
        encode.push_back(encode_str.substr(0 + i * cut, cut));
    }

    return encode;
}

std::string CaesarCipher::demovingShift(std::vector<std::string> &s, int shift)
{
    // splice the string
    std::string decode_str = "";
    for(auto itor:s)
    {
        decode_str += itor;
    }

    // decode the string
    for(int i = 0; i < decode_str.length(); i++)
    {
        if(decode_str[i] >= 'a' && decode_str[i] <= 'z')
        {
            decode_str[i] = (decode_str[i] - 'a' - shift) > 0 ? ((decode_str[i] - 'a' - shift) % 26 + 'a') : ((decode_str[i] - 'a' - shift + 26) % 26 + 'a');
        }
        if(decode_str[i] >= 'A' && decode_str[i] <= 'Z')
        {
            decode_str[i] = (decode_str[i] - 'A' - shift) > 0 ? ((decode_str[i] - 'A' - shift) % 26 + 'A') : ((decode_str[i] - 'A' - shift + 26) % 26 + 'A');
        }
        shift = (++shift) % 26;
    }

    return decode_str;
}