#include <gtest/gtest.h>
#include "ip_filtration.h"
#include <iostream>
#include <algorithm>

TEST(test_ip_filtration, sortIPAdresses)
{
  std::vector<IpAdress> adresses;
  adresses.push_back(IpAdress("192.255.255.3"));
  adresses.push_back(IpAdress("192.255.255.2"));
  adresses.push_back(IpAdress("192.255.255.4"));
  adresses.push_back(IpAdress("192.255.255.1"));
  adresses.push_back(IpAdress("192.255.100.1"));
  adresses.push_back(IpAdress("192.255.125.1"));
  adresses.push_back(IpAdress("192.255.125.2"));
  adresses.push_back(IpAdress("192.250.125.2"));
  adresses.push_back(IpAdress("10.0.0.2"));

  sortIPAdresses(adresses);

  std::vector<IpAdress> answers;
  answers.push_back(IpAdress("192.255.255.4"));
  answers.push_back(IpAdress("192.255.255.3"));
  answers.push_back(IpAdress("192.255.255.2"));
  answers.push_back(IpAdress("192.255.255.1"));
  answers.push_back(IpAdress("192.255.125.2"));
  answers.push_back(IpAdress("192.255.125.1"));
  answers.push_back(IpAdress("192.255.100.1"));
  answers.push_back(IpAdress("192.250.125.2"));
  answers.push_back(IpAdress("10.0.0.2"));

  EXPECT_EQ(adresses, answers);
}

TEST(test_ip_filtration, filter_first_pos)
{
  std::vector<IpAdress> adresses;
  adresses.push_back(IpAdress("192.255.255.3"));
  adresses.push_back(IpAdress("192.255.255.2"));
  adresses.push_back(IpAdress("192.255.255.4"));
  adresses.push_back(IpAdress("112.255.255.1"));
  adresses.push_back(IpAdress("192.255.100.1"));
  adresses.push_back(IpAdress("113.255.125.1"));
  adresses.push_back(IpAdress("192.255.125.2"));
  adresses.push_back(IpAdress("14.250.125.2"));
  adresses.push_back(IpAdress("10.0.0.2"));

  std::vector<IpAdress> result = filterIPAdresses(adresses, 0, 192);

  std::vector<IpAdress> answers;
  answers.push_back(IpAdress("192.255.255.3"));
  answers.push_back(IpAdress("192.255.255.2"));
  answers.push_back(IpAdress("192.255.255.4"));
  answers.push_back(IpAdress("192.255.100.1"));
  answers.push_back(IpAdress("192.255.125.2"));

  EXPECT_EQ(result, answers);
}

TEST(test_ip_filtration, any_filtration)
{
  std::vector<IpAdress> adresses;
  adresses.push_back(IpAdress("192.255.255.3"));
  adresses.push_back(IpAdress("192.255.255.2"));
  adresses.push_back(IpAdress("192.255.255.4"));
  adresses.push_back(IpAdress("192.250.125.2"));
  adresses.push_back(IpAdress("112.255.255.1"));
  adresses.push_back(IpAdress("192.255.100.1"));
  adresses.push_back(IpAdress("113.255.125.1"));
  adresses.push_back(IpAdress("192.255.125.2"));
  adresses.push_back(IpAdress("14.250.125.2"));
  adresses.push_back(IpAdress("10.0.0.2"));

  std::vector<IpAdress> result =
      filterAnyIPAdresses(adresses, 255);

  std::vector<IpAdress> answers;
  answers.push_back(IpAdress("192.255.255.3"));
  answers.push_back(IpAdress("192.255.255.2"));
  answers.push_back(IpAdress("192.255.255.4"));
  answers.push_back(IpAdress("112.255.255.1"));
  answers.push_back(IpAdress("192.255.100.1"));
  answers.push_back(IpAdress("113.255.125.1"));
  answers.push_back(IpAdress("192.255.125.2"));

  EXPECT_EQ(result, answers);
}