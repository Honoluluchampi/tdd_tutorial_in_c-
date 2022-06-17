// src
#include <soundex.hpp>

// lib
#include <gmock/gmock.h>

using namespace tdd;

// test series name, test name in the series
TEST(soundex_encording, retain_sole_letter_of_one_letter_word)
{
  Soundex soundex;

  auto encoded = soundex.encode("A");

  // assertino part
  ASSERT_THAT(encoded, testing::Eq("A"));
}

int main(int argc, char** argv) 
{
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}