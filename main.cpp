#include "lib.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main(int, char **) 
{
	char buf[10240];
	std::cin.read(buf, sizeof(buf));
	std::string input(buf);

	std::vector<std::string> strings = stringToStrings(input);
	std::vector<IPAdress> adresses;
	for(auto &str : strings)
		adresses.push_back(IPAdress(str));
	sortIPAdresses(adresses);
	for(auto &adress: adresses)
		std::cout << adress.toStr() << std::endl;

	std::vector<std::string> filteredAdresses;
	auto it = adresses.begin();
	while(it < adresses.end())
	{
		it = std::find_if(it, adresses.end(), 
		[](decltype(*it) ip){return (ip.components.at(0) == 1);});
		std::cout << it->toStr() << std::endl;
		if(it < adresses.end())
			filteredAdresses.push_back(it->toStr());
		it++;
	}
	for(auto &adress: filteredAdresses)
		std::cout << adress << std::endl;

	return 0;
}
