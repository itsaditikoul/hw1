#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("7");
  dat.push_front("8");
  dat.push_back("9");

  std::cout << dat.get(0) << " "
            << dat.get(1) << " "
            << dat.get(2) << std::endl;

  std::cout << "front: " <<dat.front() << std::endl; //8
  std::cout << "back: " << dat.back() << std::endl; //9
  std::cout << "size: " << dat.size() << std::endl; //3

  dat.pop_front();
  dat.pop_back();
  std::cout << "after pops, size: " << dat.size() << std::endl; //1
  std::cout << "remaining: " << dat.front() << std::endl; //7
  return 0;
  
}
