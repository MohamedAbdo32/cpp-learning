#include <iostream>
#include "patient.hpp"
#include "appoinment.hpp"
#include "validation.hpp"
#include "storage.hpp"
#include "shift.hpp"

void returnToMainMenu( int& num );

void printMoneyReport( const Shift& shift  )  {
  std::cout << " ################################################################\n";
  std::cout << "                         THE BALANCE REPORT                      \n";
  std::cout << " ################################################################\n";
  std::cout << " THE BALANCE OF CLINIC ALL DAY IS : " << shift.getAllPrice()  << '\n';
  std::cout << " ----------------------------------------------------------------\n";
}




void optionFour( int& choice , const Shift& shift  ) {
  if ( choice == 4 ) {
    while( true ) {
      int num {};
      returnToMainMenu( num );
      if( num == 1 ) {
	break;
      }
      printMoneyReport( shift ) ;
    }
  }
}
