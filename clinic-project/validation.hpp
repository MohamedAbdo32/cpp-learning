#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <limits>
#include <cstdlib>

inline void ignoreLine() {
  std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n' ) ;
}
inline int checkInt( int min , int max ) {
  while( true ) {
    int input {};
    std::cin >> input ;
    if ( !std::cin ) {
      if ( std::cin.eof() ) {
	std::exit(0);
      }
      std::cin.clear();
      ignoreLine();
      continue;
    }
    if ( input < min || input > max ) {
      ignoreLine();
      continue;
    }
    ignoreLine();
    return input ;
  }
}
inline int checkIntPositive() {
  while( true ) {
    int input {};
    std::cin >> input ;
    if ( !std::cin ) {
      if( std::cin.eof() ) {
	std::exit(0);
      }
      std::cin.clear();
      ignoreLine();
      continue;
     }
     if ( input < 0 ) {
       ignoreLine();
       continue;
     }
     ignoreLine();
     return input ;
  }
}
inline double checkDoublePositive() {
  while ( true ) {
    double input {};
    std::cin >> input ;
    if( !std::cin ) {
      if ( std::cin.eof() ) {
	std::exit(0);
      }
      std::cin.clear();
      ignoreLine();
      continue;
    }
    if ( input < 0.0 ) {
      ignoreLine();
      continue;
    }
    ignoreLine();
    return input ;
  }
}

#endif
