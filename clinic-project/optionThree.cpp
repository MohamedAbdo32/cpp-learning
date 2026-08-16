#include <iostream>
#include <iomanip>
#include "patient.hpp"
#include "appoinment.hpp"
#include "storage.hpp"
#include "validation.hpp"
#include <sstream>

Date setDate() ;
void showDate( const Date& date ) ;
Patient* searchPatientById( int id , Storage& store );

std::string_view printName( int id , const Storage& store ) {
  for( const auto& ele : store.getConstPatients() ) {
    if ( id == ele.getId() ) {
      return ele.getName() ;
    }
  }
  return "unkown";
}

void showDateShiftPatient( const Date& date  , const Storage& store , bool& checkPatient) {
  std::cout << std::left << std::setw(10) << "Time"
	    << std::setw(20) << "Patient" << std::setw(20) << "Appointment Type"
	    << std::setw(15) << "Status" << '\n';
  std::cout << " ---------------------------------------------------------------\n";
  for ( std::size_t i {}; i < store.getConstAppoinments().size() ; ++i ) {
    
    if ( date.day == store.getConstAppoinments()[i].getDate().day &&
	 date.month == store.getConstAppoinments()[i].getDate().month &&
	 date.year == store.getConstAppoinments()[i].getDate().year ) {
      int hour { store.getConstAppoinments()[i].getTime().hour };
      int minute { store.getConstAppoinments()[i].getTime().minute };

      std::ostringstream timestring ;
      timestring << std::setfill('0')
	   << std::setw(2) << hour
	   <<":"
	   << std::setw(2) << minute ;
      
      std::cout << std::left
		<< std::setw(10) << timestring.str()
		<< std::setw(20)
		<< printName( store.getConstAppoinments()[i].getPatientId() , store )
		<< std::setw(20) << getTypeName( store.getConstAppoinments()[i].getType() )
		<< std::setw(15) << getStatusName( store.getConstAppoinments()[i].getStatus())
		<< '\n';
    }else {
      checkPatient = false ;
    }
  }
  std::cout << " =====================================================================\n";
}

void optionTable( int& choice , const Storage& store , const Date& date ){
  if ( choice == 2 ) {
    bool checkPatient { true };
    std::cout << " ====================================================================\n";
    std::cout << "                           TODAY`S SCHEDULE                          \n";
    std::cout << " ====================================================================\n";
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
