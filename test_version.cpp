#include <gtest/gtest.h>
#include "lib.h"

TEST(test_ip_filtration, ipAddressFromInputStr) 
{
  std::vector<std::string> strs;
  strs.push_back("192.255.255.3\tfdg\tfghd\n");
  strs.push_back("192.255\t");
  strs.push_back("192.255.255");
  strs.push_back("");

  std::vector<std::string> answers;
  answers.push_back("192.255.255.3");
  answers.push_back("192.255");
  answers.push_back("");
  answers.push_back("");

  for(size_t i = 0; i < strs.size(); i++)
  {
    EXPECT_EQ(ipAddressFromInputStr(strs.at(i)), 
              answers.at(i));
  }
}

TEST(test_ip_filtration, ipAdressConstructorFromStr)
{
  std::vector<std::string> strs;
  strs.push_back("192.255.255.3");
  strs.push_back("10.0.0.2");

  std::vector<IPAdress> addressesFromStr;
  for(auto &str : strs)
    addressesFromStr.push_back(IPAdress(str));
  
  std::vector<IPAdress> addressesFromNum;
  addressesFromNum.push_back(IPAdress(192, 255, 255, 3));
  addressesFromNum.push_back(IPAdress(10, 0, 0, 2));

  for(size_t i = 0; i < addressesFromStr.size(); i++)
  {
    EXPECT_EQ(addressesFromStr.at(0).components, 
              addressesFromNum.at(0).components);
  }
}

TEST(test_ip_filtration, IPAdressToStr)
{
  std::vector<std::string> strs;
  strs.push_back("192.255.255.3");
  strs.push_back("192.255.255.2");
  strs.push_back("192.255.255.4");
  strs.push_back("192.255.255.1");
  strs.push_back("192.255.100.1");
  strs.push_back("192.255.125.1");
  strs.push_back("192.255.125.2");
  strs.push_back("192.250.125.2");
  strs.push_back("10.0.0.2");

  std::vector<IPAdress> adresses;
  for(auto &str : strs)
    adresses.push_back(IPAdress(str));

  for(size_t i = 0; i < strs.size(); i++)
  {
    EXPECT_EQ(adresses.at(i).toStr(), 
              strs.at(i));
  }
}

TEST(test_ip_filtration, sortIPAdresses)
{
  std::vector<std::string> strs;
  strs.push_back("192.255.255.3");
  strs.push_back("192.255.255.2");
  strs.push_back("192.255.255.4");
  strs.push_back("192.255.255.1");
  strs.push_back("192.255.100.1");
  strs.push_back("192.255.125.1");
  strs.push_back("192.255.125.2");
  strs.push_back("192.250.125.2");
  strs.push_back("10.0.0.2");

  std::vector<IPAdress> adresses;
  for(auto &str : strs)
    adresses.push_back(IPAdress(str));

  sortIPAdresses(adresses);

  std::vector<std::string> answers;
  answers.push_back("192.255.255.4");
  answers.push_back("192.255.255.3");
  answers.push_back("192.255.255.2");
  answers.push_back("192.255.255.1");
  answers.push_back("192.255.125.2");
  answers.push_back("192.255.125.1");
  answers.push_back("192.255.100.1");
  answers.push_back("192.250.125.2");
  answers.push_back("10.0.0.2");

  for(size_t i = 0; i < strs.size(); i++)
  {
    EXPECT_EQ(adresses.at(i).toStr(), 
              answers.at(i));
  }
}