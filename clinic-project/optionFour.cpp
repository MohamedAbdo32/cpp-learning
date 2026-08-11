#include <iostream>
#include "patient.hpp"
#include "appoinment.hpp"
#include "validation.hpp"
#include "storage.hpp"
#include "pricingEngine.hpp"

void returnToMainMenu( int& num );

void printMoneyReport( const PricingEngine& price  )  {
  std::cout << " ################################################################\n";
  std::cout << "                         THE BALANCE REPORT                      \n";
  std::cout << " ################################################################\n";
  std::cout << " THE BALANCE OF CLINIC ALL DAY IS : " << price.getAllPrice()  << '\n';
  std::cout << " ----------------------------------------------------------------\n";
}




void optionFour( int& choice , const PricingEngine& price  ) {
  if ( choice == 4 ) {
    while( true ) {
      int num {};
      returnToMainMenu( num );
      if( num == 1 ) {
	break;
      }
      printMoneyReport( price ) ;
    }
  }
}
