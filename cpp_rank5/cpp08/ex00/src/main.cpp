#include "../inc/easyfind.hpp"
#include "../inc/test.hpp"
#include <iostream>
#include <deque>
#include <list>
#include <vector>

static const int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void testVector()
{
  std::vector<int> v;
  setupContainer(v);
  displayContainer(v, "vector");
  testEasyFind(v, 0);
  testEasyFind(v, -1);
}

void testDeque()
{
  std::deque<int> d;
  setupContainer(d);
  displayContainer(d, "deque");
  testEasyFind(d, 1);
  testEasyFind(d, 11);
}

void testList()
{
  std::list<int> lst;
  setupContainer(lst);
  displayContainer(lst, "list");
  testEasyFind(lst, 2);
  testEasyFind(lst, 13);
}

void testConstVector()
{
  const std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
  displayContainer(v, "const vector");
  testEasyFind(v, 3);
  testEasyFind(v, 17);
}

void testConstDeque()
{
  const std::deque<int> d(arr, arr + sizeof(arr) / sizeof(arr[0]));
  displayContainer(d, "const deque");
  testEasyFind(d, 5);
  testEasyFind(d, 19);
}

void testConstList()
{
  const std::list<int> lst(arr, arr + sizeof(arr) / sizeof(arr[0]));
  displayContainer(lst, "const list");
  testEasyFind(lst, 7);
  testEasyFind(lst, 23);
}

int main()
{
  testVector();
  testDeque();
  testList();
  testConstVector();
  testConstDeque();
  testConstList();
  return 0;
}