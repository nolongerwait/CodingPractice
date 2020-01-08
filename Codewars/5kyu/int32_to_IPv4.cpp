#include <string>

std::string uint32_to_ip(uint32_t ip)
{
    unsigned short ip1, ip2, ip3, ip4;
  	ip1 = ip & 0xff;
  	ip2 = (ip >> 8) & 0xff;
  	ip3 = (ip >> 16) & 0xff;
  	ip4 = (ip >> 24) & 0xff;
  	std::string str = std::to_string((int)ip4) + "." + std::to_string((int)ip3) + "." + std::to_string((int)ip2) + "." + std::to_string((int)ip1);
    
    return str;
}