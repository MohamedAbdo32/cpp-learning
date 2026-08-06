#include <iostream>

int main() {
  std::cout << "Hello word \n";
  std::cout << "type the number of the day: \n";
  int day{};
  std::cin >> day ;
  if ( day == 5 ) {
    std::cout << "good choice \n";
  }
  return 0 ;
