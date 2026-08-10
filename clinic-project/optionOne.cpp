#include <iostream>
#include "validation.hpp"
#include "patient.hpp"
#include "appoinment.hpp"
#include "storage.hpp"
#include "shift.hpp"
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
void AddToStorage( Storage& store, const Patient& patient, Appoinment& appoinment ) {
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
void paymentBill( Storage & store, const Patient& patient, Appoinment& appoinment
		  , Shift& shift ) {
  while( true ) {
    std::cout << " TYPE THE AMOUNT OF MONEY PATIENT PAY TO ADD TO STORAGE : ";
    int money { checkIntPositive() };
    if ( money >= appoinment.getPrice() ) {
      std::cout << " THE REMANDER IS : " << money - appoinment.getPrice() << '\n';
      AddToStorage( store , patient , appoinment ) ;
      shift.setBalance( appoinment.getPrice() );
      break;
    }else {
      std::cout << " THE MONEY IS NOT ENOGH TO PAY THE BILL , CHECK AND TRY AGEIN : \n";
      std::cout << '\n';
      int num {};
      returnToMainMenu( num );
      if ( num == 1 ) {
	break;
    }else {
	continue;
      }
    }
  }
}
    
void printBill ( Storage& store , const Patient& patient , Appoinment& appoinment ,
		 Shift& shift ) {
  std::cout << " ######################################################\n";
  std::cout << "                    THE REPORT OF BILL                 \n";
  std::cout << " ######################################################\n";
  std::cout << " THE NAME IS                 : " << patient.getName() << '\n';
  std::cout << " THE AGE IS                  : " << patient.getAge() << '\n';
  std::cout << " THE PHONE NUMBER            : " << patient.getPhone() << '\n';
  std::cout << " THE DATE OF APPOINMENT      : " << patient.getDate().day
	    << " / " << patient.getDate().month << " / " << patient.getDate().year<< '\n';
  std::cout << " THE TYPE OF APPOINMENT      : "
	    << getTypeName( appoinment.getType() ) << '\n';
  std::cout << " ----------------------------------------------------------- \n";
  std::cout << " THE PRICE OF THE APPOINMENT : " << appoinment.getPrice() << '\n';
  std::cout << " ----------------------------------------------------------- \n";
  std::cout << '\n';
  paymentBill( store , patient , appoinment , shift );
}
void optionOne ( int& choice , const Date& dateShift , Storage& store , Shift& shift  ) {
  if ( choice == 1 ) {
    while ( true ) {
      int num {};
      returnToMainMenu( num );
      if( num == 1 ) {
        break;
      }
      showDate( dateShift ) ;
      Patient patient { createPatient( dateShift ) };

      Appoinment appoinment { createAppoinment() };

      printBill( store, patient, appoinment , shift );
    }
  }
}
