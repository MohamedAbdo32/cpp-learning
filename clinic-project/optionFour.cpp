#include <iostream>
#include "patient.hpp"
#include "appoinment.hpp"
#include "validation.hpp"
#include "storage.hpp"
#include "pricingEngine.hpp"
#include <iomanip>
#include <sstream>

Patient* searchPatient( std::string_view info , Storage& store );
void getNameToSearch ( std::string& info );
int setGetPrice( AppoinmentType type );
void showDate( const Date& date ) ;

void printPatientInfo(const Date& date, Patient& patient , Storage& store ) {
  std::cout << " ========================================================================\n";
  std::cout << "                      THE MEDICAL / VISIT HISTORY                        \n";
  std::cout << " ========================================================================\n";
  showDate(date);
  std::cout << '\n';
  std::cout << "            PATIENT PROFILE \n";
  std::cout << " -------------------------------------------------------------------\n";
  std::cout << " THE ID IS      : " << patient.getId() << '\n';
  std::cout << " THE NAME  IS   : " << patient.getName() << '\n';
  std::cout << " THE AGE IS     : " << patient.getAge() << '\n';
  std::cout << " THE PHONE IS   : " << patient.getPhone() << '\n';
  std::cout << " THE DETIALS IS : " << patient.getDetials() << '\n';
  std::cout << '\n';
  std::cout << "            VISIT HISTORY \n";
  std::cout << " ----------------------------------------------------------------\n";
  for ( std::size_t i {} ; i < store.getConstAppoinments().size() ; ++i ) {
    if ( patient.getId() == store.getConstAppoinments()[i].getPatientId()) {
      std::cout << " Date and Time : "
		<< store.getConstAppoinments()[i].getDate().day << " / "
		<< store.getConstAppoinments()[i].getDate().month << " / "
		<< store.getConstAppoinments()[i].getDate().year ;
      std::cout << " -> " ;
      std::ostringstream time ;
      time << std::setfill('0')
	   << std::setw(2) << store.getConstAppoinments()[i].getTime().hour << ":"
	   << std::setw(2) << store.getConstAppoinments()[i].getTime().minute;
      std::cout << time.str()  << '\n' ;
      std::cout << " Type          : "
		<< getTypeName( store.getConstAppoinments()[i].getType() ) << '\n';
      std::cout << " PRICE         : "
		<< setGetPrice (store.getConstAppoinments()[i].getType()) << '\n';
      std::cout << " STATUS        : "
		<< getStatusName( store.getConstAppoinments()[i].getStatus() )
		<< '\n';
      std::cout << '\n';
    }
  }
}



void optionSearch( int& choice , Storage& store , const Date& date ) {
  if ( choice == 3 ) {
    std::string info {};
    getNameToSearch( info );

    Patient* PatientPtr { searchPatient( info , store ) };

    if ( PatientPtr ) {
      Patient& patient { *PatientPtr };
      printPatientInfo( date, patient , store ) ;

    }else {
      std::cout << " bad \n";
    }

    
  }
}
