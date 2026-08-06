#include <iostream>
#include <cstdlib>
#include <limits>
#include "patient.hpp"
#include "appoinment.hpp"

void ignoreLine() {
  std::cin.ignore( std::numeric_limits< std::streamsize >::max() , '\n' ) ;
}
int checkInt( int min , int max ) {
  while ( true ) {
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
int checkIntPositive() {
  while ( true ) {
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
    if ( input < 0 ) {
      ignoreLine();
      continue;
    }
    ignoreLine() ;
    return input ;
  }
}
double checkDoublePositive() {
  while ( true ) {
    double input {};
    std::cin >> input ;
    if ( !std::cin ) {
      if ( std::cin.eof() ) {
	std::exit(0);
      }
      std::cin.clear();
      ignoreLine();
      continue;
    }
    if ( input > 0 ) {
      ignoreLine();
      continue;
    }
    ignoreLine();
    return input ;
  }
}

void mainMenu( int& choice ) {
  while ( true )  {
    std::cout << " ##########################################################\n";
    std::cout << "                  CLINIC SMART APPOINTMENT SYSTEM          \n";
    std::cout << " ##########################################################\n";
    std::cout << " TYPE THE NUMBER OF THE CHOICE : \n";
    std::cout << " 1) TO ADD NEW PATIENT \n";
    std::cout << " 2) TO EDIT THE PATIENT \n";
    std::cout << " 3) TO SHOW APPOINMENT \n";
    std::cout << " 4) TO HISTORY OF BILLS \n";
    std::cout << " 5) TO EXIT PROGRAM \n";
    choice = checkInt( 1 , 5 ) ;
    break;
  }
}
int main ()  {
  while ( true ) {
    int choice {};
    mainMenu( choice );
    if ( choice == 5 ) {
      std::cout << " ####################### EXIT PROGRAM ########################\n";
      break;
    }
  }
  return 0;
}
