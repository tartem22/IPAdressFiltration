#ifndef LIB_IPADRESSES
#define LIB_IPADRESSES

#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <iostream>

std::vector<std::string> split(const std::string &str, char d);

class IpAdress
{
public:
	IpAdress(std::string str_view)
	{
		std::vector<std::string> parts = split(str_view, '.');
		_adress = std::array<int, ipAdressLen>{stoi(parts.at(0)),
											   stoi(parts.at(1)),
											   stoi(parts.at(2)),
											   stoi(parts.at(3))};
	}

	auto get() const
	{
		return _adress;
	}

	std::string toString() const
	{
		return std::to_string(_adress.at(0)) + "." + std::to_string(_adress.at(1)) +
			   "." + std::to_string(_adress.at(2)) + "." + std::to_string(_adress.at(3));
	}

	bool operator<(const IpAdress adress) const
	{
		return adress.get() < _adress;
	}

	bool operator==(const IpAdress adress) const
	{
		return _adress == adress.get();
	}

private:
	static const int ipAdressLen = 4;
	std::array<int, ipAdressLen> _adress;
};

void sortIPAdresses(std::vector<IpAdress> &adresses);
std::vector<IpAdress> filterAnyIPAdresses(
	const std::vector<IpAdress> adresses, int val);
std::vector<IpAdress> filterIPAdresses(
	const std::vector<IpAdress> adresses, int inx, int val);

#endif