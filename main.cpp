#include <iostream>
#include "lib.h"

int main()
{
	try
	{
		std::vector<std::array<int, 4>> ip_pool;

		for (std::string line; std::getline(std::cin, line);)
		{
			std::vector<std::string> v = split(line, '\t');
			std::vector<std::string> parts = split(v.at(0), '.');
			ip_pool.push_back(std::array<int, 4>{stoi(parts.at(0)),
												 stoi(parts.at(1)),
												 stoi(parts.at(2)),
												 stoi(parts.at(3))});
		}

		sortIPAdresses(ip_pool);

		for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
			std::cout << ipArrayToString(*ip) << std::endl;

		std::vector<std::array<int, 4>> filtered_1 =
			filterIPAdresses(ip_pool, 0, 1);

		for (auto ip = filtered_1.cbegin(); ip != filtered_1.cend(); ++ip)
			std::cout << ipArrayToString(*ip) << std::endl;

		std::vector<std::array<int, 4>> filtered_4670 =
			filterIPAdresses(filterIPAdresses(ip_pool, 0, 46), 1, 70);

		for (auto ip = filtered_4670.cbegin(); ip != filtered_4670.cend(); ++ip)
			std::cout << ipArrayToString(*ip) << std::endl;

		std::vector<std::array<int, 4>> filtered_46 = 
			filterAnyIPAdresses(ip_pool, 46);

		for (auto ip = filtered_46.cbegin(); ip != filtered_46.cend(); ++ip)
			std::cout << ipArrayToString(*ip) << std::endl;			
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}