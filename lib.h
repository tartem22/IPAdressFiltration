#ifndef LIB_IPADRESSES
#define LIB_IPADRESSES

#include <string>
#include <vector>
#include <algorithm>

struct IPAdress
{
    IPAdress(int first, int second, int third, int fours)
    {
        components = {first, second, third, fours};
    }
	IPAdress(std::string strAdress)
	{
        components.clear();
		size_t prev = 0;
		size_t next;
		 while( ( next = strAdress.find(".", prev) ) != std::string::npos )
		 {
			components.push_back(std::stoi(strAdress.substr(prev, next - prev)));
			prev = next + 1;
		 }
  	}
    std::string toStr()
    {
        return std::to_string(components.at(0)) + "." + 
                std::to_string(components.at(1)) + "." +  
                std::to_string(components.at(2)) + "." +  
                std::to_string(components.at(3)); 
    }
	std::vector<int> components = {0, 0, 0, 0};
};

std::string ipAddressFromInputStr(std::string inputStr);
void sortIPAdresses(std::vector<IPAdress> adresses);


#endif