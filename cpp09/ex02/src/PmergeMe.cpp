#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <stdexcept>
#include <cmath>
#include <algorithm>

bool PmergeMe::isInputValid(const std::string &input) {
  if (input.empty())
    return false;

  for (size_t i = 0; i < input.length(); i++) {
    if (!isdigit(input[i]))
      return false;
  }

  if (input.length() > 10 || (input.length() > 1 && input[0] == '0'))
    return false;
  long num = std::strtol(input.c_str(), NULL, 10);
  if (num > INT_MAX)
    return false;

  return true;
}

std::vector<int> PmergeMe::inputToVector(char **argv) {
  std::vector<int> v;
  for (int i = 1; argv[i]; i++) {
    if (!isInputValid(argv[i]))
      throw std::runtime_error("Error: Invalid input");
    v.push_back(std::atoi(argv[i]));
  }
  return v;
}

std::list<int> PmergeMe::inputToList(char **argv) {
  std::list<int> l;
  for (int i = 1; argv[i]; i++) {
    if (!isInputValid(argv[i]))
      throw std::runtime_error("Error: Invalid input");
    l.push_back(std::atoi(argv[i]));
  }
  return l;
}

size_t PmergeMe::compareCounter(int add) {
  static size_t count = 0;
  count += add;
  return count;
}

bool PmergeMe::compareSecond(const std::pair<int, int> &a,
                             const std::pair<int, int> &b) {
  return a.second < b.second;
}

bool PmergeMe::compareSecondWithCounter(const std::pair<int, int> &a,
                             const std::pair<int, int> &b) {
  compareCounter(1);
  return compareSecond(a, b);
}

std::pair<int, int> PmergeMe::makeSortedPair(int a, int b) {
  if (a < b)
    return std::make_pair(a, b);
  return std::make_pair(b, a);
}

std::pair<int, int> PmergeMe::makeSortedPairWithCounter(int a, int b) {
  compareCounter(1);
  return makeSortedPair(a, b);
}

void PmergeMe::mergeSort(std::vector<std::pair<int, int> >::iterator first,
                         std::vector<std::pair<int, int> >::iterator last) {
  size_t n = std::distance(first, last);
  if (n <= 1)
    return;
  std::vector<std::pair<int, int> >::iterator mid = first;
  std::advance(mid, n / 2);
  mergeSort(first, mid);
  mergeSort(mid, last);
  std::inplace_merge(first, mid, last, compareSecondWithCounter);
}

void PmergeMe::mergeSort(std::list<std::pair<int, int> >::iterator first,
                         std::list<std::pair<int, int> >::iterator last) {
  size_t n = std::distance(first, last);
  if (n <= 1)
    return;
  std::list<std::pair<int, int> >::iterator mid = first;
  std::advance(mid, n / 2);
  mergeSort(first, mid);
  mergeSort(mid, last);
  std::inplace_merge(first, mid, last, compareSecond);
}

bool PmergeMe::compareWithCounter(int a, int b) {
  compareCounter(1);
  return a < b;
}

void PmergeMe::binaryInsert(std::vector<int> &v,
                            std::vector<int>::iterator first,
                            std::vector<int>::iterator last, int num) {
  std::vector<int>::iterator it = std::lower_bound(first, last, num, compareWithCounter);
  v.insert(it, num);
}

void PmergeMe::binaryInsert(std::list<int> &l,
                            std::list<int>::iterator first,
                            std::list<int>::iterator last, int num) {
  std::list<int>::iterator it = std::lower_bound(first, last, num);
  l.insert(it, num);
}

std::vector<size_t> PmergeMe::insertOrder(size_t size) {
  std::vector<size_t> order;
  size_t tk = 1;
  size_t tk_1 = 1;
  size_t k = 2;
  while (order.size() < size) {
    tk_1 = tk;
    tk = (pow(2, k + 1) + pow(-1, k)) / 3;
    for (size_t i = tk; i >= tk_1 + 1; --i) {
      order.push_back(i);
    }
    k++;
  }
  return order;
}

// see merge_insertion.pdf
void PmergeMe::sort(std::vector<int> &v) {
  std::vector<std::pair<int, int> > pairs;
  int single_num = -1;
  if (v.size() % 2 == 1) {
    single_num = v.back();
    v.pop_back();
  }

  // make pairs
  for (size_t i = 0; i < v.size(); i += 2) {
    pairs.push_back(makeSortedPairWithCounter(v[i], v[i + 1]));
  }

  // merge sort pairs by second element(larger one)
  mergeSort(pairs.begin(), pairs.end());

  std::vector<int> result;
  // add node b1 to result
  if (pairs.size() > 0)
    result.push_back(pairs[0].first);

  // if there is only one number, add it to result
  if (pairs.size() == 0 && single_num != -1)
    result.push_back(single_num);

  // add node a1~an to result
  for (size_t i = 0; i < pairs.size(); i++) {
    result.push_back(pairs[i].second);
  }

  // prepare single_num for insert
  if (single_num != -1)
    pairs.push_back(std::make_pair(single_num, -1));

  // get insert order(3,2;5,4;11,10,9,8,7,6;...;tk,tk-1,...,tk_1+1)
  std::vector<size_t> order = insertOrder(pairs.size());

  // binary insert node b2~bn to result
  size_t insertedCount = 0;
  for (size_t i = 0; i < order.size(); i++) {
    if (order[i] - 1 >= pairs.size())
      continue;
    // insert node bn among b1~an-1
    std::vector<int>::iterator insertStart = result.begin();
    std::vector<int>::iterator insertEnd = result.begin();
    size_t offset = order[i] + insertedCount;
    std::advance(insertEnd, offset);
    binaryInsert(result, insertStart, insertEnd, pairs[order[i] - 1].first);
    insertedCount++;
  }
  v = result;
}

void PmergeMe::sort(std::list<int> &l) {
  std::list<std::pair<int, int> > pairs;
  int single_num = -1;
  if (l.size() % 2 == 1) {
    single_num = l.back();
    l.pop_back();
  }

  // make pairs
  for (std::list<int>::iterator it = l.begin(); it != l.end(); ) {
    int a = *it;
    ++it;
    int b = *it;
    ++it;
    pairs.push_back(makeSortedPair(a, b));
  }

  // merge sort pairs by second element(larger one)
  mergeSort(pairs.begin(), pairs.end());

  std::list<int> result;
  // add node b1 to result
  if (pairs.size() > 0)
    result.push_back(pairs.front().first);

  // if there is only one number, add it to result
  if (pairs.size() == 0 && single_num != -1)
    result.push_back(single_num);

  // add node a1~an to result
  for (std::list<std::pair<int, int> >::iterator it = pairs.begin();
       it != pairs.end(); ++it) {
    result.push_back(it->second);
  }

  // prepare single_num for insert
  if (single_num != -1)
    pairs.push_back(std::make_pair(single_num, -1));

  // get insert order(3,2;5,4;11,10,9,8,7,6;...;tk,tk-1,...,tk_1+1)
  std::vector<size_t> order = insertOrder(pairs.size());

  // binary insert node b2~bn to result
  size_t insertedCount = 0;
  for (size_t i = 0; i < order.size(); i++) {
    if (order[i] - 1 >= pairs.size())
      continue;
    // insert node bn among b1~an-1
    std::list<int>::iterator insertStart = result.begin();
    std::list<int>::iterator insertEnd = result.begin();
    size_t offset = order[i] + insertedCount;
    std::advance(insertEnd, offset);
    std::list<std::pair<int, int> >::iterator it = pairs.begin();
    std::advance(it, order[i] - 1);
    binaryInsert(result, insertStart, insertEnd, it->first);
    insertedCount++;
  }
  l = result;
}
