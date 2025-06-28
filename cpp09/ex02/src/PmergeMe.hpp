#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <list>
#include <string>
#include <vector>

class PmergeMe {
public:
  static void sort(std::vector<int> &v);
  static void sort(std::list<int> &l);
  static std::vector<int> inputToVector(char **argv);
  static std::list<int> inputToList(char **argv);
  static void mergeSort(std::vector<std::pair<int, int> >::iterator first,
                        std::vector<std::pair<int, int> >::iterator last);
  static bool compareSecond(const std::pair<int, int> &a,
                            const std::pair<int, int> &b);
  static std::pair<int, int> makeSortedPair(int a, int b);
  static void binaryInsert(std::vector<int> &v,
                           std::vector<int>::iterator first,
                           std::vector<int>::iterator last, int num);
  static std::vector<size_t> insertOrder(size_t size);

private:
  static bool isInputValid(const std::string &input);

  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
};

#endif
