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
  int age { checkIntPositive() };
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

void AddToStorage( Storage& store , Patient& patient , Appoinment& appoinment ) {
  store.AddPatientToArray( patient );
  store.AddAppoinmentToArray( appoinment ) ;
  std::cout << " #################### COMPLATE ADD TO STORAGE ###################### \n" ;
}

void optionOfMenu ( int& choice , const Date& dateShift , Storage& store  ) {
  if ( choice == 1 ) {
    while ( true ) {
      showDate( dateShift ) ;
      Patient patient { createPatient( dateShift ) };
    
      Appoinment appoin { createAppoinment() };

      std::cout << appoin.getPrice() << '\n' ;
      AddToStorage( store , patient , appoin ) ;
    }
  }
}

void mainMenu( int& choice , const Date& dateShift ) {
  while ( true )  {
    std::cout << " ##########################################################\n";
    std::cout << "                  CLINIC SMART APPOINTMENT SYSTEM          \n";
    std::cout << " ##########################################################\n";
    showDate ( dateShift ) ;
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
    Storage store ;
    Date dateShift { setDate() };
    int choice {};
    mainMenu( choice  , dateShift );
    optionOfMenu( choice , dateShift , store ) ;
    if ( choice == 5 ) {
      std::cout << " ####################### EXIT PROGRAM ########################\n";
      break;
    }
  }
  return 0;
}
