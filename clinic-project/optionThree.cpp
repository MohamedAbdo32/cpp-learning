#include <iostream>
#include "patient.hpp"
#include "appoinment.hpp"
#include "storage.hpp"
#include "validation.hpp"

Date setDate() ;
void showDate( const Date& date ) ;

void showDateShiftPatient( const Date& date  , const Storage& store , bool& checkPatient) {
  for ( std::size_t i {}; i < store.getConstPatients().size() ; ++i ) {
    if ( date.day == store.getConstAppoinments()[i].getDate().day &&
	 date.month == store.getConstAppoinments()[i].getDate().month &&
	 date.year == store.getConstAppoinments()[i].getDate().year ) {
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

void optionThree( int& choice , const Storage& store , const Date& date ){
  if ( choice == 3 ) {
    bool checkPatient { true };
    std::cout << " ####################################################################\n";
    std::cout << "                           THE TABLE OF PATIENTS                     \n";
    std::cout << " ####################################################################\n";
    showDate( date );
    std::cout << '\n';
    showDateShiftPatient( date , store , checkPatient ) ;
    if ( !checkPatient ) {
      std::cout << " TYPE THE DATE YOU NEED TO NOT THE TABLE OF PATIENTS \n";
      Date searchDate { setDate() };
      showDateShiftPatient( searchDate , store , checkPatient ) ;
    }
  }
}
