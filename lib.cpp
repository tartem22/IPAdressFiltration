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

void sortIPAdresses(std::vector<IPAdress> adresses)
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
