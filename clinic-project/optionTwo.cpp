#include <iostream>
#include "validation.hpp"
#include "patient.hpp"
#include "appoinment.hpp"
#include "storage.hpp"
void returnToMainMenu( int& num ) ;
Patient* searchPatient( std::string_view name , Storage& store );
void optionTwo( Storage& store , int& choice ) {
  if ( choice == 2 ) {
    while( true ) {
      int num {};
      returnToMainMenu( num );
      if ( num == 1 ) {
	break;
      }
      std::cout << '\n';
      std::cout << " TYPE THE NAME OF THE PATIENT TO SEE IT: ";
      std::string name {};
      std::getline( std::cin >> std::ws , name ) ;
      std::cout << '\n';
      Patient* patient { searchPatient( name , store ) };
      std::cout << '\n';
      if ( patient ) {
	Patient& thePatient { *patient };
	std::cout << thePatient.getName() ;
	std::cout << thePatient.getId() ;
      }else {
	std::cout << " THE PATIENT IS NOT IN THE STORAGE , CHECK IT AND TRY AGAIN \n";
      }
    }
  }
}
