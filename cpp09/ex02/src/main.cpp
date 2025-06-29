#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>
#include <algorithm>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <array of integers>" << std::endl;
    return 1;
  }

  if (argc > 20000) {
    std::cerr << "Error: the number of elements is too large" << std::endl;
    return 1;
  }

  try {
    std::vector<int> v = PmergeMe::inputToVector(argv);
    std::vector<int> v_copy = v;
    std::list<int> l = PmergeMe::inputToList(argv);
    std::cout << "Before: ";
    for (int i = 1; i < argc; i++) {
      std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

    struct timeval start, end1, end2;
    gettimeofday(&start, NULL);
    PmergeMe::sort(v);
    gettimeofday(&end1, NULL);
    PmergeMe::sort(l);
    gettimeofday(&end2, NULL);

    // check if the result is correct
    std::sort(v_copy.begin(), v_copy.end());
    std::list<int>::iterator it = l.begin();
    for (size_t i = 0; i < v.size(); i++) {
      if (v[i] != v_copy[i]) {
        throw std::runtime_error("Error: sort(vector) is not correct");
      }
      if (*it != v_copy[i]) {
        throw std::runtime_error("Error: sort(list) is not correct");
      }
      ++it;
    }

    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); i++) {
      std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    double time1 =
        (end1.tv_sec - start.tv_sec) * 1000000 + (end1.tv_usec - start.tv_usec);
    double time2 =
        (end2.tv_sec - end1.tv_sec) * 1000000 + (end2.tv_usec - end1.tv_usec);
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::vector : " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::list : " << time2 << " us" << std::endl;

    std::cout << "Number of comparisons: " << PmergeMe::compareCounter()
              << std::endl;

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
