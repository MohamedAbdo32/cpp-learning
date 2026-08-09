#include <iostream>
#include "patient.hpp"
#include "appoinment.hpp"
#include "storage.hpp"
#include "validation.hpp"



void showDateShiftPatient( const Date& date  , const Storage& store , bool& checkPatient) {
  for ( std::size_t i {}; i < store.getConstPatients().size() ; ++i ) {
    if ( date.day == store.getConstPatients()[i].getDate().day &&
	 date.month == store.getConstPatients()[i].getDate().month &&
	 date.year == store.getConstPatients()[i].getDate().year ) {
      std::cout << " THE NAME IS : " << store.getConstPatients()[i].getName()
		<< " AGE IS : " << store.getConstPatients()[i].getAge()
		<< " PHONE NUMBER : " << store.getConstPatients()[i].getPhone()
		<< " TYPE APPOINMENT : "
		<< getTypeName( store.getConstAppoinments()[i].getType() )
		<< '\n';
      std::cout << "----------------------------------------------------------\n";
    }else {
      checkPatient = false ;
    }
  }
}

void optionThree( const Storage& store , const Date& date ) {
  while( true ) {
    
    bool checkPatient { true };
    showDateShiftPatient( date , store , checkPatient ) ;
    if ( !checkPatient ) {
      std::cout << " THIS DAY IS NOT FOUND , CHECK IT AND TRY AGAIN \n";
      break;
    }
  }

}
