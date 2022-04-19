#include "lib.h"

std::string ipAddressFromInputStr(std::string inputStr)
{
	std::string res = "";
	size_t delimeterPos = 0;
	if( (delimeterPos = inputStr.find("\t", 0)) != std::string::npos)
	{
		res = inputStr.substr(0, delimeterPos);
	}
	return res;
}

std::vector<std::string> stringToStrings(std::string buf)
{
	std::vector<std::string> strings;
	size_t prev = 0;
	size_t next;
	while( ( next = buf.find("\n", prev) ) != std::string::npos )
	{
		strings.push_back(buf.substr(prev, next - prev));
		prev = next + 1;
	}
	// strings.push_back(buf.substr(prev, buf.size()));
	return strings;
}

void sortIPAdresses(std::vector<IPAdress> &adresses)
{
		std::sort(adresses.begin(), adresses.end(),
			 [](IPAdress &first, IPAdress &second){
				 for(int i = 0; i < 4; i++)
				 {
					 	if(first.components.at(i) != second.components.at(i))
						{
							if(first.components.at(i) > second.components.at(i))
								return true;
							else
								return false;
						}
				 }
				 return false;
			 });
}
