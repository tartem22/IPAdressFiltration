#include <iostream>
#include "ip_filtration.h"

int main()
{
	try
	{
		std::vector<IpAdress> ip_pool;
		ip_pool.reserve(128);

		for (std::string line; std::getline(std::cin, line);)
		{
			std::vector<std::string> v = split(line, '\t');
			ip_pool.push_back(IpAdress(v.at(0)));
		}

		sortIPAdresses(ip_pool);

		for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
			std::cout << ip->toString() << std::endl;

		std::vector<IpAdress> filtered_1 =
			filterIPAdresses(ip_pool, 0, 1);

		for (auto ip = filtered_1.cbegin(); ip != filtered_1.cend(); ++ip)
			std::cout << ip->toString() << std::endl;

		std::vector<IpAdress> filtered_4670 =
			filterIPAdresses(filterIPAdresses(ip_pool, 0, 46), 1, 70);

		for (auto ip = filtered_4670.cbegin(); ip != filtered_4670.cend(); ++ip)
			std::cout << ip->toString() << std::endl;

		std::vector<IpAdress> filtered_46 = 
			filterAnyIPAdresses(ip_pool, 46);

		for (auto ip = filtered_46.cbegin(); ip != filtered_46.cend(); ++ip)
			std::cout << ip->toString() << std::endl;			
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}