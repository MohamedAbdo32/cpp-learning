#include <iostream>
#include "validation.hpp"
#include "patient.hpp"
#include "appoinment.hpp"
#include "storage.hpp"

Date setDate() {
  std::cout << " TYPE THE NUMBER OF THE DAY OF THE SHIFT: ";
  int day { checkInt( 1 , 31 ) };
  std::cout << '\n';

  std::cout << " TYPE THE NUMBER OF THE MOUNTH OF THE SHIFT: " ;
  int month { checkInt( 1 , 12 ) };
  std::cout << '\n';

  std::cout << " TYPE THE NUMBER OF THE YEAR OF THE SHIFT: " ;
  int year { checkInt( 2000 , 9999 )  } ;
  std::cout << '\n';
  return { day , month , year };
}
void showDate( const Date& date ) {
  std::cout << " THE DATE OF THE DAY IS : ";
  std::cout << date.day << " / " ;
  std::cout << date.month << " / " ;
  std::cout << date.year << '\n' ;
}
Patient createPatient(const Date& date  ) {
  std::cout << " TYPE THE NUMBER OF THE ID OF PATIENT: " ;
  int id { checkIntPositive() };
  std::cout << '\n';

  std::cout << " TYPE THE NAME OF THE PATIENT: " ;
  std::string name {};
  std::getline( std::cin >> std::ws , name ) ;
  std::cout << '\n';

  std::cout << " TYPE THE NUMBER OF AGE OF PATIENT: " ;
  int age { checkInt( 1 , 300 ) };
  std::cout << '\n';

  std::cout << " TYPE THE NUMBER OF THE PHONE OF THE PATINET: ";
  std::string phone {};
  std::cin >> phone ;
  std::cout << '\n';

  std::cout << " TYPE THE DETAILS OF THE PATINET: ";
  std::string detials {};
  std::getline( std::cin >> std::ws , detials ) ;

  return { id , name , age , phone , date , detials };
}
Appoinment createAppoinment() {
  std::cout << " TYPE THE NUMBER OF THE CHOICE: \n " ;
  std::cout << " 1) NEW EXAMINATION \n " ;
  std::cout << " 2) CONSULTATION \n " ;
  std::cout << " 3) RETURN VISTI \n " ;
  int type { checkInt( 1 , 3 ) };

  return { static_cast<AppoinmentType>( type ) };
}
Patient* searchPatient( std::string_view name , Storage& store ) {
  for( auto& element : store.getPatients() ) {
    if ( element.getName() == name ) {
      return &element ;
    }
  }
  return nullptr;
}
void AddToStorage( Storage& store , Patient& patient , Appoinment& appoinment ) {
  store.AddPatientToArray( patient );
  store.AddAppoinmentToArray( appoinment ) ;
  std::cout << " #################### COMPLATE ADD TO STORAGE ###################### \n" ;
}
void returnToMainMenu( int& num ) {
  std::cout << " TYPE THE NUMBER  of the choice: \n";
  std::cout << " 1) TO RETURN TO MENU \n";
  std::cout << " 2) TO CONTINUE IN THIS CHOICE \n";
  num =  checkInt( 1 , 2 ) ;
}
void optionOne ( int& choice , const Date& dateShift , Storage& store  ) {
  if ( choice == 1 ) {
    while ( true ) {
      int num {};
      returnToMainMenu( num );
      if( num == 1 ) {
        break;
      }
      showDate( dateShift ) ;
      Patient patient { createPatient( dateShift ) };

      Appoinment appoin { createAppoinment() };

      std::cout << appoin.getPrice() << '\n' ;
      AddToStorage( store , patient , appoin ) ;
    }
  }
}
