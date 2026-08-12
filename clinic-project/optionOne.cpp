#include <iostream>
#include "validation.hpp"
#include "patient.hpp"
#include "appoinment.hpp"
#include "storage.hpp"
#include "pricingEngine.hpp"

int setGetPrice( AppoinmentType type );

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
Time setTime() {
  std::cout << " TYPE THE NUMBER OF THE HOUR OF THE APPOINMENT : ";
  int hour { checkInt( 1 , 24 ) };
  std::cout << '\n';

  std::cout << " TYPE THE NUMBER OF THE MINUTE OF THE APPOINMENT : ";
  int minute { checkInt( 0 , 59 ) };
  std::cout << '\n';
  return { hour , minute };
}
Time checkValidationTime( Storage& store ) {
  Time appoinmentTime {};
  while( true ) {
    appoinmentTime = setTime();
    bool checkRepeatTime { false };
    for ( const auto& ele : store.getConstAppoinments() ) {
      if ( appoinmentTime.hour == ele.getTime().hour &&
           appoinmentTime.minute == ele.getTime().minute ) {
        checkRepeatTime = true ;
      }
    }
    if ( checkRepeatTime ) {
      std::cout << " ERROR: This time is already booked , TRY AGAIN !!  \n";
      continue;
    }
    if ( appoinmentTime.hour < 4 || appoinmentTime.hour > 10 ){
      std::cout << "ERROR: This time out of the shift , TRY AGAIN !!  \n";
      continue;
    }
    break;
  }
  return appoinmentTime ;   
}
void showDate( const Date& date ) {
  std::cout << " THE DATE OF THE DAY IS : ";
  std::cout << date.day << " / " ;
  std::cout << date.month << " / " ;
  std::cout << date.year << '\n' ;
}
Patient createPatient() {
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

  return { name , age , phone , detials };
}
Appoinment createAppoinment( const Date& date , Storage& store ) {

  std::cout << " TYPE THE ID OF THE PATIENT TO TAKE APPOINMENT: ";
  int patientId { checkIntPositive() };
  
  Time appoinmentTime { checkValidationTime( store ) };
  
  std::cout << " TYPE THE NUMBER OF THE CHOICE: \n" ;
  std::cout << " 1) NEW EXAMINATION -> 200 SAR \n" ;
  std::cout << " 2) CONSULTATION    -> 150 SAR \n" ;
  std::cout << " 3) RETURN VISTI    -> 100 SAR\n" ;
  int type { checkInt( 1 , 3 ) };
  
  return { patientId ,static_cast<AppoinmentType>( type ), date, appoinmentTime };
}
Patient* searchPatient( std::string_view info, Storage& store ) {
  for( auto& element : store.getPatients() ) {
    if ( element.getName() == info ) {
      return &element ;
    }
    if ( element.getPhone() == info ) {
      return &element ;
    }
  }
  return nullptr;
}
void addToStorage( Storage& store, Appoinment& appoinment , const Patient& patient ) {
  store.AddAppoinmentToArray( appoinment ) ;
  store.AddPatientToArray(patient );
  std::cout << " #################### COMPLATE ADD TO STORAGE ###################### \n" ;
}
void returnToMainMenu( int& num ) {
  std::cout << " TYPE THE NUMBER  of the choice: \n";
  std::cout << " 1) TO RETURN TO MENU \n";
  std::cout << " 2) TO CONTINUE IN THIS CHOICE \n";
  num =  checkInt( 1 , 2 ) ;
}
void paymentBill( Storage & store, const Patient& patient, Appoinment& appoinment
		  , PricingEngine& price  ) {
  while( true ) {
    std::cout << " TYPE THE AMOUNT OF MONEY PATIENT PAY TO ADD TO STORAGE : ";
    int money { checkIntPositive() };
    if ( money >= price.getPrice() ) {
      std::cout << " THE REMANDER IS : " << money - price.getPrice() << '\n';
      addToStorage( store, appoinment, patient ) ;
      price.setAllPrice( price.getPrice() );
      break;
    }else {
      std::cout << " THE MONEY IS NOT ENOGH TO PAY THE BILL , CHECK AND TRY AGEIN : \n";
      std::cout << '\n';
      int num {};
      returnToMainMenu( num );
      if ( num == 1 ) {
	break;
      }
    }
  }
}
    
void printBill ( Storage& store , const Patient& patient , Appoinment& appoinment ,
		 PricingEngine& price  ) {
  std::cout << " ######################################################\n";
  std::cout << "                    THE REPORT OF BILL                 \n";
  std::cout << " ######################################################\n";
  std::cout << " THE ID OF THE PATIENT IS    : " << patient.getId() << '\n';
  std::cout << " THE NAME IS                 : " << patient.getName() << '\n';
  std::cout << " THE AGE IS                  : " << patient.getAge() << '\n';
  std::cout << " THE PHONE NUMBER            : " << patient.getPhone() << '\n';
  std::cout << " THE DATE OF APPOINMENT      : " << appoinment.getDate().day
	    << " / " << appoinment.getDate().month << " / " << appoinment.getDate().year<< '\n';
  std::cout << " THE TIME OF APPOINMENT      : " << appoinment.getTime().hour << " : "
	    << appoinment.getTime().minute << '\n';
  std::cout << " THE TYPE OF APPOINMENT      : "
	    << getTypeName( appoinment.getType() ) << '\n';
  std::cout << " THE ID OF APPOINMENT IS     : " << appoinment.getId() << '\n';
  std::cout << " THE STATUS OF APPOINMENTIS  : " << getStatusName( appoinment.getStatus())<< '\n';
  price.setPrice( appoinment.getType() ) ;
  std::cout << " ----------------------------------------------------------- \n";
  std::cout << " THE PRICE OF THE APPOINMENT : " << price.getPrice() << '\n';
  std::cout << " ----------------------------------------------------------- \n";
  std::cout << '\n';
  paymentBill( store , patient , appoinment , price );
}
void optionMenu(int& optionNum , const Date& dateShift ) {
  std::cout << " ####################################################################\n";
  std::cout << "                              THE ADDATION MENU                      \n";
  std::cout << " ####################################################################\n";
  showDate( dateShift ) ;
  std::cout << " TYPE THE NUMBER OF THE OPTION NUMBER : \n";
  std::cout << " 1) TO ADD NEW PATIENT \n";
  std::cout << " 2) TO ADD NEW APPOINMENT \n";
  std::cout << " 3) TO RETURN TO MAIN MENU \n";
  optionNum = checkInt( 1 , 3 );
}
void optionOne ( int& choice , const Date& dateShift , Storage& store , PricingEngine& price  ) {
  if ( choice == 1 ) {
    while ( true ) {
      Patient patient;
      Appoinment appoinment;
      int optionNum {};
      optionMenu( optionNum , dateShift ) ;

      if ( optionNum == 1 ) {
	patient = createPatient();
      }else if ( optionNum == 2 ) {
	appoinment = createAppoinment( dateShift , store );
      }else if( optionNum  == 3 ) {
        break;
      }
      printBill( store, patient, appoinment , price );
    }
  }
}
