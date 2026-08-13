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
void optionThree ( int& choice , const Storage& store , const Date& dateShift );
void optionFour ( int& choice , const PricingEngine& price ) ;

void mainMenu( int& choice , const Date& dateShift ) {
  while ( true )  {
    std::cout << " ##########################################################\n";
    std::cout << "                  CLINIC SMART APPOINTMENT SYSTEM          \n";
    std::cout << " ##########################################################\n";
    std::cout << " THE TIME OF SHIFT IS :> 4 : 00 TO 11 : 00 \n";
    showDate ( dateShift ) ;
    std::cout << " TYPE THE NUMBER OF THE CHOICE : \n";
    std::cout << " 1) TO ADD NEW PATIENT & APPOINMENT  \n";
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
  PricingEngine price ;
  while ( true ) {
    int choice {};
    mainMenu( choice  , dateShift );
    optionOne( choice , dateShift , store , price ) ;
    optionThree( choice , store , dateShift );
    optionFour( choice , price ) ;
    if ( choice == 5 ) {
      std::cout << " ####################### EXIT PROGRAM ########################\n";
      break;
    }
  }
  return 0;
}
