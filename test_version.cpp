#include <gtest/gtest.h>
#include "lib.h"
#include <iostream>

TEST(test_ip_filtration, sortIPAdresses)
{
  std::vector<std::array<int, 4>> adresses;
  adresses.push_back(std::array<int, 4>{192, 255, 255, 3});
  adresses.push_back(std::array<int, 4>{192, 255, 255, 2});
  adresses.push_back(std::array<int, 4>{192, 255, 255, 4});
  adresses.push_back(std::array<int, 4>{192, 255, 255, 1});
  adresses.push_back(std::array<int, 4>{192, 255, 100, 1});
  adresses.push_back(std::array<int, 4>{192, 255, 125, 1});
  adresses.push_back(std::array<int, 4>{192, 255, 125, 2});
  adresses.push_back(std::array<int, 4>{192, 250, 125, 2});
  adresses.push_back(std::array<int, 4>{10, 0, 0, 2});

  sortIPAdresses(adresses);

  std::vector<std::array<int, 4>> answers;
  answers.push_back(std::array<int, 4>{192, 255, 255, 4});
  answers.push_back(std::array<int, 4>{192, 255, 255, 3});
  answers.push_back(std::array<int, 4>{192, 255, 255, 2});
  answers.push_back(std::array<int, 4>{192, 255, 255, 1});
  answers.push_back(std::array<int, 4>{192, 255, 125, 2});
  answers.push_back(std::array<int, 4>{192, 255, 125, 1});
  answers.push_back(std::array<int, 4>{192, 255, 100, 1});
  answers.push_back(std::array<int, 4>{192, 250, 125, 2});
  answers.push_back(std::array<int, 4>{10, 0, 0, 2});

  EXPECT_EQ(adresses, answers);
}

TEST(test_ip_filtration, filter_first_pos)
{
  std::vector<std::array<int, 4>> adresses;
  adresses.push_back(std::array<int, 4>{192, 255, 255, 3});
  adresses.push_back(std::array<int, 4>{192, 255, 255, 2});
  adresses.push_back(std::array<int, 4>{192, 255, 255, 4});
  adresses.push_back(std::array<int, 4>{112, 255, 255, 1});
  adresses.push_back(std::array<int, 4>{192, 255, 100, 1});
  adresses.push_back(std::array<int, 4>{113, 255, 125, 1});
  adresses.push_back(std::array<int, 4>{192, 255, 125, 2});
  adresses.push_back(std::array<int, 4>{14, 250, 125, 2});
  adresses.push_back(std::array<int, 4>{10, 0, 0, 2});

  std::vector<std::array<int, 4>> result =
      filterIPAdresses(adresses, 0, 192);

  std::vector<std::array<int, 4>> answers;
  answers.push_back(std::array<int, 4>{192, 255, 255, 3});
  answers.push_back(std::array<int, 4>{192, 255, 255, 2});
  answers.push_back(std::array<int, 4>{192, 255, 255, 4});
  answers.push_back(std::array<int, 4>{192, 255, 100, 1});
  answers.push_back(std::array<int, 4>{192, 255, 125, 2});
  
  EXPECT_EQ(result, answers);
}

TEST(test_ip_filtration, filter_second_pos)
{
  std::vector<std::array<int, 4>> adresses;
  adresses.push_back(std::array<int, 4>{192, 255, 255, 3});
  adresses.push_back(std::array<int, 4>{192, 255, 255, 2});
  adresses.push_back(std::array<int, 4>{192, 255, 255, 4});
  adresses.push_back(std::array<int, 4>{192, 250, 125, 2});
  adresses.push_back(std::array<int, 4>{112, 255, 255, 1});
  adresses.push_back(std::array<int, 4>{192, 255, 100, 1});
  adresses.push_back(std::array<int, 4>{113, 255, 125, 1});
  adresses.push_back(std::array<int, 4>{192, 255, 125, 2});
  adresses.push_back(std::array<int, 4>{14, 250, 125, 2});
  adresses.push_back(std::array<int, 4>{10, 0, 0, 2});

  std::vector<std::array<int, 4>> result =
      filterIPAdresses(adresses, 1, 250);

  std::vector<std::array<int, 4>> answers;
  answers.push_back(std::array<int, 4>{192, 250, 125, 2});
  answers.push_back(std::array<int, 4>{14, 250, 125, 2});

  EXPECT_EQ(result, answers);
}

TEST(test_ip_filtration, filter_third_pos)
{
  std::vector<std::array<int, 4>> adresses;
  adresses.push_back(std::array<int, 4>{192, 255, 255, 3});
  adresses.push_back(std::array<int, 4>{192, 255, 255, 2});
  adresses.push_back(std::array<int, 4>{192, 255, 255, 4});
  adresses.push_back(std::array<int, 4>{192, 250, 125, 2});
  adresses.push_back(std::array<int, 4>{112, 255, 255, 1});
  adresses.push_back(std::array<int, 4>{192, 255, 100, 1});
  adresses.push_back(std::array<int, 4>{113, 255, 125, 1});
  adresses.push_back(std::array<int, 4>{192, 255, 125, 2});
  adresses.push_back(std::array<int, 4>{14, 250, 125, 2});
  adresses.push_back(std::array<int, 4>{10, 0, 0, 2});

  std::vector<std::array<int, 4>> result =
      filterIPAdresses(adresses, 2, 125);

  std::vector<std::array<int, 4>> answers;
  answers.push_back(std::array<int, 4>{192, 250, 125, 2});
  answers.push_back(std::array<int, 4>{113, 255, 125, 1});
  answers.push_back(std::array<int, 4>{192, 255, 125, 2});
  answers.push_back(std::array<int, 4>{14, 250, 125, 2});
  EXPECT_EQ(result, answers);
}

TEST(test_ip_filtration, filter_fourth_pos)
{
  std::vector<std::array<int, 4>> adresses;
  adresses.push_back(std::array<int, 4>{192, 255, 255, 3});
  adresses.push_back(std::array<int, 4>{192, 255, 255, 2});
  adresses.push_back(std::array<int, 4>{192, 255, 255, 4});
  adresses.push_back(std::array<int, 4>{192, 250, 125, 2});
  adresses.push_back(std::array<int, 4>{112, 255, 255, 1});
  adresses.push_back(std::array<int, 4>{192, 255, 100, 1});
  adresses.push_back(std::array<int, 4>{113, 255, 125, 1});
  adresses.push_back(std::array<int, 4>{192, 255, 125, 2});
  adresses.push_back(std::array<int, 4>{14, 250, 125, 2});
  adresses.push_back(std::array<int, 4>{10, 0, 0, 2});

  std::vector<std::array<int, 4>> result =
      filterIPAdresses(adresses, 3, 2);

  std::vector<std::array<int, 4>> answers;
  answers.push_back(std::array<int, 4>{192, 255, 255, 2});
  answers.push_back(std::array<int, 4>{192, 250, 125, 2});
  answers.push_back(std::array<int, 4>{192, 255, 125, 2});
  answers.push_back(std::array<int, 4>{14, 250, 125, 2});
  answers.push_back(std::array<int, 4>{10, 0, 0, 2});
  EXPECT_EQ(result, answers);
}

TEST(test_ip_filtration, any_filtration)
{
  std::vector<std::array<int, 4>> adresses;
  adresses.push_back(std::array<int, 4>{192, 255, 255, 3});
  adresses.push_back(std::array<int, 4>{192, 255, 255, 2});
  adresses.push_back(std::array<int, 4>{192, 255, 255, 4});
  adresses.push_back(std::array<int, 4>{192, 250, 125, 2});
  adresses.push_back(std::array<int, 4>{112, 255, 255, 1});
  adresses.push_back(std::array<int, 4>{192, 255, 100, 1});
  adresses.push_back(std::array<int, 4>{113, 255, 125, 1});
  adresses.push_back(std::array<int, 4>{192, 255, 125, 2});
  adresses.push_back(std::array<int, 4>{14, 250, 125, 2});
  adresses.push_back(std::array<int, 4>{10, 0, 0, 2});

  std::vector<std::array<int, 4>> result =
      filterAnyIPAdresses(adresses, 255);

  std::vector<std::array<int, 4>> answers;
  answers.push_back(std::array<int, 4>{192, 255, 255, 3});
  answers.push_back(std::array<int, 4>{192, 255, 255, 2});
  answers.push_back(std::array<int, 4>{192, 255, 255, 4});
  answers.push_back(std::array<int, 4>{112, 255, 255, 1});
  answers.push_back(std::array<int, 4>{192, 255, 100, 1});
  answers.push_back(std::array<int, 4>{113, 255, 125, 1});
  answers.push_back(std::array<int, 4>{192, 255, 125, 2});

  EXPECT_EQ(result, answers);
}