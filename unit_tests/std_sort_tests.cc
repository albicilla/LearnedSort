#include "util.hh"
#include "gtest/gtest.h"
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

extern size_t TEST_SIZE;

TEST(STD_SORT_TEST, StdNormal) {

  // Generate random input
  vector<double> arr;
  random_device rd;
  mt19937 generator(rd());
  normal_distribution<> distribution(0, 1);
  for (int i = 0; i < TEST_SIZE; i++) {
    arr.push_back(distribution(generator));
  }

  // Calculate the checksum
  auto cksm = get_checksum(arr);

  // Sort
  std::sort(arr.begin(), arr.end());

  // Test that it is sorted
  ASSERT_TRUE(std::is_sorted(arr.begin(), arr.end()));

  // Test that the checksum is the same
  ASSERT_EQ(cksm, get_checksum(arr));
}

TEST(STD_SORT_TEST, Lognormal) {

  // Generate random input
  vector<double> arr;
  random_device rd;
  mt19937 generator(rd());
  lognormal_distribution<> distribution(0, 2);
  for (int i = 0; i < TEST_SIZE; i++) {
    arr.push_back(distribution(generator));
  }

  // Calculate the checksum
  auto cksm = get_checksum(arr);

  // Sort
  std::sort(arr.begin(), arr.end());

  // Test that it is sorted
  ASSERT_TRUE(std::is_sorted(arr.begin(), arr.end()));

  // Test that the checksum is the same
  ASSERT_EQ(cksm, get_checksum(arr));
}

TEST(STD_SORT_TEST, UniformReal) {

  // Generate random input
  vector<double> arr;
  random_device rd;
  mt19937 generator(rd());
  uniform_real_distribution<> distribution(-100, 500);
  for (int i = 0; i < TEST_SIZE; i++) {
    arr.push_back(distribution(generator));
  }

  // Calculate the checksum
  auto cksm = get_checksum(arr);

  // Sort
  std::sort(arr.begin(), arr.end());

  // Test that it is sorted
  ASSERT_TRUE(std::is_sorted(arr.begin(), arr.end()));

  // Test that the checksum is the same
  ASSERT_EQ(cksm, get_checksum(arr));
}

TEST(STD_SORT_TEST, UniformInt) {

  // Generate random input
  vector<int> arr;
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<> distribution(-100, 500);
  for (int i = 0; i < TEST_SIZE; i++) {
    arr.push_back(distribution(generator));
  }

  // Calculate the checksum
  auto cksm = get_checksum(arr);

  // Sort
  std::sort(arr.begin(), arr.end());

  // Test that it is sorted
  ASSERT_TRUE(std::is_sorted(arr.begin(), arr.end()));

  // Test that the checksum is the same
  ASSERT_EQ(cksm, get_checksum(arr));
}