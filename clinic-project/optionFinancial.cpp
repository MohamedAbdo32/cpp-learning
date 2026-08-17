#include <iostream>
#include "patient.hpp"
#include "appoinment.hpp"
#include "storage.hpp"
#include "validation.hpp"
#include "pricingEngine.hpp"
#include <iomanip>
#include <sstream>

void showDate( const Date& date );
std::string_view printName( int id , const Storage& store );
std::string_view getTypeName( AppoinmentType type ) ;
int setGetPrice ( AppoinmentType type );

void printReport( const Date& date , const Storage& store ) {
  std::cout << " ======================================================================\n";
  std::cout << "                           DAILY FINANCIAL REPORT                      \n";
  std::cout << " ======================================================================\n";
  showDate( date ) ;
  std::cout << "          --------------------------------------------- \n";
  std::cout << "                          COMPLETED VISITS              \n";
  std::cout << "          --------------------------------------------- \n";
  std::cout << '\n';
  std::cout << std::left
	    << std::setw(10) << " PATIENT"
	    << std::setw(20) << " APPOINTMENT TIME"
	    << std::setw(20) << " TYPE"
	    << std::setw(10) << " PRICE" << '\n';
  std::cout << " ----------------------------------------------------------------------\n";
  int counter {};
  int allBalance {};
  for ( std::size_t i {}; i < store.getConstAppoinments().size() ; ++i ) {
    std::ostringstream time ;
    time << std::setfill('0')
	 << std::setw(2) << store.getConstAppoinments()[i].getTime().hour << ":"
	 << std::setw(2) << store.getConstAppoinments()[i].getTime().minute ;
    std::cout << " ";
    std::cout << std::left
	      << std::setw(10)
	      << printName(store.getConstAppoinments()[i].getPatientId() , store )
	      << std::setw(20) << time.str()
	      << std::setw(20) << getTypeName( store.getConstAppoinments()[i].getType() )
	      << setGetPrice ( store.getConstAppoinments()[i].getType() )
	      << " SAR" << '\n';
    ++counter;
    allBalance += setGetPrice ( store.getConstAppoinments()[i].getType() );
  }
  std::cout << " -----------------------------------------------------------------------\n";
  std::cout << '\n';
  std::cout << " NUMBER OF COMPLETED VISITS : " << counter << '\n';
  std::cout << " TOTAL COLLECTED            : " << allBalance << '\n';
  std::cout << '\n';
  std::cout << '\n';
  std::cout << " -----------------------------------------------------------------------\n";
  std::cout << "                              OTHER APPOINTMENTS                        \n";
  std::cout << " -----------------------------------------------------------------------\n";
  std::cout << '\n';
  std::cout << std::left
	    << std::setw(20) << " PATIENT"
	    << std::setw(20) << "TIME"
	    << std::setw(20) << "STATUS" << '\n';
  std::cout << " -----------------------------------------------------------------------\n";
  for ( std::size_t i {}; i < store.getConstAppoinments().size() ; ++i ) {
    if ( getStatusName( store.getConstAppoinments()[i].getStatus() ) == "BOOKED" ||
	 getStatusName( store.getConstAppoinments()[i].getStatus() ) == "WAITING" ||
	 getStatusName( store.getConstAppoinments()[i].getStatus() ) == "CANCELLED" ) {
      std::ostringstream time;
      time << std::setfill('0')
	   << std::setw(2) << store.getConstAppoinments()[i].getTime().hour << ":"
	   << std::setw(2) << store.getConstAppoinments()[i].getTime().minute;
      std::cout << " " ;
      std::cout << std::left
		<< std::setw(20)
		<< printName( store.getConstAppoinments()[i].getPatientId() , store )
		<< std::setw(20) << time.str()
		<< std::setw(20)
		<<getStatusName( store.getConstAppoinments()[i].getStatus() ) << '\n';
    }
  }
  std::cout << " -------------------------------------------------------------------------\n";
}


void optionFinancial( int& choice , const Storage& store , const Date& date ) {

  if( choice == 4 ) {
    printReport( date , store );
  }

}










//======================================================================
  //                     DAILY FINANCIAL REPORT
  //======================================================================
  //THE DATE OF THE DAY IS : 17 / 8 / 2026

  //----------------------------------------------------------------------
  //                COMPLETED VISITS
  //----------------------------------------------------------------------

  //Patient        Appointment Time     Type              Price/
  //----------------------------------------------------------------------
  //mohamed        04:00                NEW EXAMINATION   200 SAR
  //Ahmed          05:00                CONSULTATION      150 SAR
  //omar           06:30                RETURN VISIT      100 SAR
  //----------------------------------------------------------------------

  //NUMBER OF COMPLETED VISITS : 3
  //TOTAL COLLECTED            : 450 SAR


  //----------------------------------------------------------------------
  //                OTHER APPOINTMENTS
  //----------------------------------------------------------------------

  //Patient        Time       Status
  //----------------------------------------------------------------------
  //Ali            07:00      BOOKED
  //Sara           08:00      WAITING
  //Khaled         09:00      CANCELLED
  //----------------------------------------------------------------------


  //======================================================================
  //                     FINANCIAL SUMMARY/
  //======================================================================

  //COMPLETED VISITS  : 3
  //BOOKED VISITS     : 1
  //WAITING VISITS    : 1
  //CANCELLED VISITS  : 1

  //TOTAL COLLECTED   : 450 SAR

  //======================================================================

