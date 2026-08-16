#include <iostream>
#include "validation.hpp"
#include "patient.hpp"
#include "appoinment.hpp"
#include "storage.hpp"
#include "pricingEngine.hpp"

Date setDate() ;
void showDate( const Date& date ) ;
Patient createPatient(const Date& date  ) ;
Appoinment createAppoinment();
Patient* searchPatient( std::string_view name , Storage& store );
void AddToStorage( Storage& store , Patient& patient , Appoinment& appoinment );
void returnToMainMenu( int& num );

void optionOne (int& choice, const Date& dateShift, Storage& store, PricingEngine& price);
void optionTable ( int& choice , const Storage& store , const Date& dateShift );
void optionSearch( int& choice , Storage& store, const Date& date ) ;

void mainMenu( int& choice , const Date& dateShift ) {
  while ( true )  {
    std::cout << " ##########################################################\n";
    std::cout << "                  CLINIC SMART APPOINTMENT SYSTEM          \n";
    std::cout << " ##########################################################\n";
    std::cout << " THE TIME OF SHIFT IS :> 04 : 00 TO 11 : 00 \n";
    showDate ( dateShift ) ;
    std::cout << " TYPE THE NUMBER OF THE CHOICE : \n";
    std::cout << " 1) TO ADD NEW PATIENT & APPOINMENT OR EDIT INFORMATION  \n";
    std::cout << " 2) TO VIEW TODAY`S SCHEDULE \n";
    std::cout << " 3) TO SEARCH PATIENT \n";
    std::cout << " 4) TO DAILY FINANCIAL REPORT  \n";
    std::cout << " 5) TO EXIT PROGRAM \n";
    choice = checkInt( 1 , 5 ) ;
    break;
  }
}
int main ()  {
  Date dateShift { setDate() };
  Storage store ;
  Patient p1 { "mohamed" , 34 , "0343434344444" , "fsdfd  sfsfsd fsf " };
  Patient p2 { "Ahmed" , 43 , "4345345345" , "ffsdfsf sdfdf " };
  Patient p3 { "omar" , 54 , "23423423423" , "fsfdfsf;kjj eer " };
  Appoinment a1 { 5001 , static_cast<AppoinmentType>(1) , dateShift , { 4 , 0 } };
  Appoinment a2 { 5001 , static_cast<AppoinmentType>(2) , dateShift , { 4 , 30 } };
  Appoinment a3 { 5002 , static_cast<AppoinmentType>(3) , dateShift , { 5 , 0 } };
  Appoinment a4 { 5003 , static_cast<AppoinmentType>(1) , dateShift , { 6 , 30 } };

  store.AddPatientToArray( p1 );
  store.AddPatientToArray( p2 );
  store.AddPatientToArray( p3 );
  store.AddAppoinmentToArray( a1 );
  store.AddAppoinmentToArray( a2 );
  store.AddAppoinmentToArray( a3 );
  store.AddAppoinmentToArray( a4 );
  
  PricingEngine price ;
  while ( true ) {
    int choice {};
    mainMenu( choice  , dateShift );
    optionOne( choice , dateShift , store , price ) ;
    optionTable( choice , store , dateShift );
    optionSearch( choice , store , dateShift ) ;
    if ( choice == 5 ) {
      std::cout << " ####################### EXIT PROGRAM ########################\n";
      break;
    }
  }
  return 0;
}
