#include "ip_filtration.h"

std::vector<std::string> split(const std::string &str, char d)
{
	std::vector<std::string> r;

	std::string::size_type start = 0;
	std::string::size_type stop = str.find_first_of(d);
	while (stop != std::string::npos)
	{
		r.push_back(str.substr(start, stop - start));

		start = stop + 1;
		stop = str.find_first_of(d, start);
	}

	r.push_back(str.substr(start));

	return r;
}

void sortIPAdresses(std::vector<IpAdress> &adresses)
{
	std::sort(adresses.begin(), adresses.end());
}

std::vector<IpAdress> filterAnyIPAdresses(
	const std::vector<IpAdress> adresses, int val)
{
	std::vector<IpAdress> result;
	std::copy_if(adresses.begin(), adresses.end(),
				 std::back_inserter(result),
				 [val](IpAdress adress)
				 {
					 auto it = std::find(adress.get().begin(),
										 adress.get().end(),
										 val);
					 return it != adress.get().end();
				 });
	return result;
}

std::vector<IpAdress> filterIPAdresses(const std::vector<IpAdress> adresses,
									   int inx, int val)
{
	std::vector<IpAdress> result;
	std::copy_if(adresses.begin(), adresses.end(),
				 std::back_inserter(result),
				 [inx, val](IpAdress adress)
				 {
					 return adress.get().at(inx) == val;
				 });
	return result;
}