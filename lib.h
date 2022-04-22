#ifndef LIB_IPADRESSES
#define LIB_IPADRESSES

#include <string>
#include <vector>
#include <array>
#include <algorithm>

std::vector<std::string> split(const std::string &str, char d);
std::string ipArrayToString(const std::array<int, 4> ipArray);
void sortIPAdresses(std::vector<std::array<int, 4>> &adresses);
std::vector<std::array<int, 4>> filterIPAdresses(
	const std::vector<std::array<int, 4>> adresses, int inx, int val);
std::vector<std::array<int, 4>> filterAnyIPAdresses(
	const std::vector<std::array<int, 4>> adresses, int val);

#endif