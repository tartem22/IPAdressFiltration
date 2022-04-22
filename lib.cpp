#include "lib.h"

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

std::string ipArrayToString(const std::array<int, 4> ipArray)
{
	return std::to_string(ipArray.at(0)) + "." + std::to_string(ipArray.at(1)) +
		   "." + std::to_string(ipArray.at(2)) + "." + std::to_string(ipArray.at(3));
}

void sortIPAdresses(std::vector<std::array<int, 4>> &adresses)
{
	std::sort(adresses.begin(), adresses.end(),
			  [](decltype(*adresses.begin()) &first,
				 decltype(*adresses.begin()) &second)
			  {
				  for (int i = 0; i < 4; i++)
				  {
					  if (first.at(i) != second.at(i))
					  {
						  if (first.at(i) > second.at(i))
							  return true;
						  else
							  return false;
					  }
				  }
				  return false;
			  });
}

std::vector<std::array<int, 4>> filterIPAdresses(
	const std::vector<std::array<int, 4>> adresses, int inx, int val)
{
	std::vector<std::array<int, 4>> res;
	auto it = adresses.begin();
	while (it < adresses.end())
	{
		it = std::find_if(it, adresses.end(),
						  [inx, val](decltype(*it) ip)
						  { return (ip.at(inx) == val); });
		if (it < adresses.end())
			res.push_back(*it);
		it++;
	}
	return res;
}

std::vector<std::array<int, 4>> filterAnyIPAdresses(
	const std::vector<std::array<int, 4>> adresses, int val)
{
	std::vector<std::array<int, 4>> res;
	auto it = adresses.begin();
	while (it < adresses.end())
	{
		it = std::find_if(it, adresses.end(),
						  [val](decltype(*it) ip)
						  { return (ip.at(0) == val or
									ip.at(1) == val or
									ip.at(2) == val or
									ip.at(3) == val);});
		if (it < adresses.end())
			res.push_back(*it);
		it++;
	}
	return res;
}