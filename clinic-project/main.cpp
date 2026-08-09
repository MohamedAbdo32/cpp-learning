#include <iostream>
#include "validation.hpp"
#include "patient.hpp"
#include "appoinment.hpp"
#include "storage.hpp"

Date setDate() ;
void showDate( const Date& date ) ;
Patient createPatient(const Date& date  ) ;
Appoinment createAppoinment();
Patient* searchPatient( std::string_view name , Storage& store );
void AddToStorage( Storage& store , Patient& patient , Appoinment& appoinment );
void returnToMainMenu( int& num );

void optionOne ( int& choice , const Date& dateShift , Storage& store  );
void optionTwo ( Storage& store , int& choice , const Date& dateShift ) ;
void optionThree ( const Storage& store , const Date& dateShift );

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
  Date dateShift { setDate() };
  Patient p1 { 5001 , "Ahmed" , 25 , "5334534534" , dateShift , "headice problem" };
  Patient p2 { 5002 , "mohamed", 30 , "343434345" , dateShift , "ggdgdfgdvdggdgdf" };
  Patient p3 { 5003 , "Ali" , 50 , "53453535353" ,{ 9 , 10 , 2026 }, "fdgdfggdfgdgdfgd" };
  Appoinment a1 { static_cast<AppoinmentType>(1) };
  Appoinment a2 { static_cast<AppoinmentType>(2) };
  Appoinment a3 { static_cast<AppoinmentType>(3) };
  Storage store ;
  store.AddPatientToArray( p1 ) ;
  store.AddPatientToArray( p2 ) ;
  store.AddPatientToArray( p3 ) ;
  store.AddAppoinmentToArray( a1 );
  store.AddAppoinmentToArray( a2 );
  store.AddAppoinmentToArray( a3 );
  while ( true ) {
    int choice {};
    mainMenu( choice  , dateShift );
    optionOne( choice , dateShift , store ) ;
    optionTwo( store , choice , dateShift ) ;
    optionThree( store , dateShift );
    if ( choice == 5 ) {
      std::cout << " ####################### EXIT PROGRAM ########################\n";
      break;
    }
  }
  return 0;
}
