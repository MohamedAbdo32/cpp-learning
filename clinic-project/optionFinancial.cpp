#include <iostream>
#include "patient.hpp"
#include "appoinment.hpp"
#include "storage.hpp"
#include "validation.hpp"
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
  int countCompleted {};
  int allBalance {};
  for ( std::size_t i {}; i < store.getConstAppoinments().size() ; ++i ) {
    if ( store.getConstAppoinments()[i].getStatus() == AppoinmentStatus::completed  &&
	 date.day == store.getConstAppoinments()[i].getDate().day && date.month ==
	 store.getConstAppoinments()[i].getDate().month && date.year ==
	 store.getConstAppoinments()[i].getDate().year ) {
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
      ++countCompleted;
      allBalance += setGetPrice ( store.getConstAppoinments()[i].getType() );
    }
  }
  std::cout << " -----------------------------------------------------------------------\n";
  std::cout << '\n';
  std::cout << " NUMBER OF COMPLETED VISITS : " << countCompleted << '\n';
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
    if ( date.day == store.getConstAppoinments()[i].getDate().day && date.month ==
	 store.getConstAppoinments()[i].getDate().month && date.year ==
	 store.getConstAppoinments()[i].getDate().year &&
	 ( store.getConstAppoinments()[i].getStatus() == AppoinmentStatus::booked ||
	 store.getConstAppoinments()[i].getStatus() == AppoinmentStatus::waitting ||
	   store.getConstAppoinments()[i].getStatus() == AppoinmentStatus::cancelled) ) {
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
  std::cout << '\n';
  std::cout << " =========================================================================\n";
  std::cout << "                          FINANCIAL SUMMARY                               \n";
  std::cout << " =========================================================================\n";
  int countBooked {};
  int countWaiting {};
  int countCancelled {};
  for ( std::size_t i {}; i < store.getConstAppoinments().size() ; ++i ) {
    if (  ( date.day == store.getConstAppoinments()[i].getDate().day && date.month ==
	 store.getConstAppoinments()[i].getDate().month
	 && date.year == store.getConstAppoinments()[i].getDate().year )
       && store.getConstAppoinments()[i].getStatus() == AppoinmentStatus::booked){
      ++countBooked ;
    }
    if ( ( date.day == store.getConstAppoinments()[i].getDate().day
	   && date.month == store.getConstAppoinments()[i].getDate().month
	   && date.year == store.getConstAppoinments()[i].getDate().year) &&
	 store.getConstAppoinments()[i].getStatus() == AppoinmentStatus::waitting){
      ++countWaiting ;
    }
    if ( ( date.day == store.getConstAppoinments()[i].getDate().day
	   && date.month == store.getConstAppoinments()[i].getDate().month
	   && date.year == store.getConstAppoinments()[i].getDate().year ) &&
	 store.getConstAppoinments()[i].getStatus() == AppoinmentStatus::cancelled ){
      ++countCancelled ;
    }
  }
    std::cout << " COMPLETED VISITED : " << countCompleted << '\n';
    std::cout << " BOOKED VISITED    : " << countBooked << '\n';
    std::cout << " WAITING VISITED   : " << countWaiting << '\n';
    std::cout << " CANCELLED VISITED : " << countCancelled << '\n';
    std::cout << '\n';
    std::cout << " TOTAL COLLECTED   : " << allBalance << '\n';
    std::cout << '\n';
    std::cout << " =======================================================================\n";
    std::cout << '\n';
}
  


void optionFinancial( int& choice , const Storage& store , const Date& date ) {

  if( choice == 4 ) {
    printReport( date , store );
  }

}
