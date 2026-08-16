#include <iostream>
#include "patient.hpp"
#include "appoinment.hpp"
#include "validation.hpp"
#include "storage.hpp"
#include "pricingEngine.hpp"

Patient* searchPatient( std::string_view info , Storage& store );
void getNameToSearch ( std::string& info );
void showDate( const Date& date ) ;

void printPatientInfo(const Date& date, Patient& patient ) {
  std::cout << " ========================================================================\n";
  std::cout << "                          THE PATIENT INFORMATION                        \n";
  std::cout << " ========================================================================\n";
  showDate( date );
  std::cout << " THE ID IS : " << patient.getId() << '\n';
  std::cout << " THE NAME  IS : " << patient.getName() << '\n';
  std::cout << " THE AGE IS : " << patient.getAge() << '\n';
  std::cout << " THE PHONE IS : " << patient.getPhone() << '\n';
  std::cout << " THE DETIALS IS : " << patient.getDetials() << '\n';
  std::cout << " ----------------------------------------------------------------\n";
  
}



void optionSearch( int& choice , Storage& store , const Date& date ) {
  if ( choice == 3 ) {
    std::string info {};
    getNameToSearch( info );

    Patient* PatientPtr { searchPatient( info , store ) };

    if ( PatientPtr ) {
      Patient& patient { *PatientPtr };
      printPatientInfo( date, patient ) ;

    }else {
      std::cout << " bad \n";
    }

    
  }
}
