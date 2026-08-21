#include <iostream>
#include <array>

template <typename T , std::size_t N >
void removeDup( std::array< T , N >& arr) {
  T count {};
  for ( std::size_t i {} ; i < arr.size() - 1 ; ++i ) {
    if ( arr[i] != arr[ i + 1 ] ) {
      ++count ;
    }
  }
  std::cout << count << '\n';
}

int main() {
  
  std::array<int, 10> arr { 1, 2, 2, 3, 4, 4, 5, 5, 5, 6 };
  removeDup( arr ) ;
  return 0;
}
