#include <iostream>
#include "validation.hpp"
#include "patient.hpp"
#include "appoinment.hpp"
#include "storage.hpp"
#include <iomanip>
#include <sstream>

int setGetPrice( AppoinmentType type );
void optionEditInfo( Storage& store, const Date& dateShift );
void cancelledAppoinment( Storage& store );
int setGetPrice ( AppoinmentType type ) ;
Date setDate() {
  std::cout << " TYPE THE NUMBER OF THE DAY    : ";
  int day { checkInt( 1 , 31 ) };
  std::cout << '\n';

  std::cout << " TYPE THE NUMBER OF THE MOUNTH : " ;
  int month { checkInt( 1 , 12 ) };
  std::cout << '\n';

  std::cout << " TYPE THE NUMBER OF THE YEAR   : " ;
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
Time checkValidationTime( const Appoinment& appoinment, const Date& date , Storage& store ) {
  Time appoinmentTime {};
  while( true ) {
    appoinmentTime = setTime();
    bool checkRepeatTime { false };
    for( const auto& ele : store.getConstAppoinments() ) {
      if ( appoinment.getId() != ele.getId() ) {
	
	if ( appoinmentTime.hour == ele.getTime().hour &&
	     appoinmentTime.minute == ele.getTime().minute ) {
	  if ( ele.getDate().day == date.day && ele.getDate().month == date.month &&
	       ele.getDate().year == date.year &&
	       ele.getStatus() != AppoinmentStatus::cancelled ) {
	    checkRepeatTime = true ;
	  }
	}
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
Patient* searchPatientById( int id , Storage& store ) {
  for ( auto& element : store.getPatients() ) {
    if ( id == element.getId() ) {
      return &element;
    }
  }
  return nullptr;
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
void createAppoinment(  Appoinment& appoinment , const Date& date , Storage& store ) {
  while ( true ) {

    std::cout << " TYPE THE ID OF THE PATIENT TO TAKE APPOINMENT: ";
    int patientId { checkIntPositive() };
    std::cout << '\n';
    
    Patient* patientPtr { searchPatientById( patientId , store ) };
    
    if ( patientPtr ) {
      
      std::cout << " IS THE DATE IN THE SAME DAY OR BOOKED IN THE DIFFERENT DAY : \n";
      std::cout << " 1) IN THE SAME DATE \n";
      std::cout << " 2) IN THE DIFFERENT DAY \n";
      int isDate { checkInt ( 1 , 2 ) };
      Date appoinmentDate {};
      if ( isDate == 1 ) {
	appoinmentDate = date ;
      }else {
	appoinmentDate = setDate() ;
    }
      
      Time appoinmentTime { checkValidationTime( appoinment, appoinmentDate, store ) };
      
      std::cout << " TYPE THE NUMBER OF THE CHOICE: \n" ;
      std::cout << " 1) NEW EXAMINATION -> 200 SAR \n" ;
      std::cout << " 2) CONSULTATION    -> 150 SAR \n" ;
      std::cout << " 3) RETURN VISTI    -> 100 SAR\n" ;
      int type { checkInt( 1 , 3 ) };
      
      appoinment = { patientId,static_cast<AppoinmentType>( type ),
		     appoinmentDate,appoinmentTime};
      break;
    }else {
      std::cout << " ERROR : NO PATIENT WITH THIS ID , CHECK IT AND TRY AGAIN \n";
      continue;
    }
  }
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
void addToStorage( Storage& store, Appoinment& appoinment) {
  store.AddAppoinmentToArray( appoinment );
  std::cout << " #################### COMPLATE ADD TO STORAGE ###################### \n" ;
}
void returnToMainMenu( int& num ) {
  std::cout << " TYPE THE NUMBER  of the choice: \n";
  std::cout << " 1) TO RETURN TO MENU \n";
  std::cout << " 2) TO CONTINUE IN THIS CHOICE \n";
  num =  checkInt( 1 , 2 ) ;
}
void paymentBill( Appoinment& appoinment ) {
  while( true ) {
    std::cout << " TYPE THE AMOUNT OF MONEY PATIENT PAY TO ADD TO STORAGE : ";
    int money { checkIntPositive() };
    if ( money >= setGetPrice( appoinment.getType() ) ) {
      std::cout << " THE REMANDER IS : " << money - setGetPrice( appoinment.getType() ) << '\n';
      std::cout << '\n';
      std::cout << " THANK YOU FOR PAY THE BILL OF THE PATIENT \n";
      std::cout << '\n';
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

void printPatientInfo( const Patient& patient ) {
  std::cout << " ########################################################\n";
  std::cout << "                     PATIENT INFO                        \n";
  std::cout << " ########################################################\n";
  std::cout << " THE ID  IS       : " << patient.getId() << '\n';
  std::cout << " THE NAME IS      : " << patient.getName() << '\n';
  std::cout << " THE AGE IS       : " << patient.getAge() << '\n';
  std::cout << " THE PHONE NUMBER : " << patient.getPhone() << '\n';
  std::cout << " THE DETIALS      : " << patient.getDetials() << '\n';
}

void printAppoinmentInfo( const Appoinment& appoinment ) {
  std::cout << " #######################################################\n";
  std::cout << "                     THE APPOINTMENT INFO               \n";
  std::cout << " #######################################################\n";
  std::cout << " THE ID OF APPOINMENT     : " << appoinment.getId() << '\n';
  std::cout << " THE DATE OF APPOINMENT   : " << appoinment.getDate().day << " / "
	    << appoinment.getDate().month << " / " << appoinment.getDate().year << '\n';
  std::cout << std::left
	    << std::setw(30) << " THE TIME OF THE APPOINMENT  : ";
  std::ostringstream time ;
  time << std::setfill('0')
       << std::setw(2) << appoinment.getTime().hour << ":"
       << std::setw(2) << appoinment.getTime().minute ;
  std::cout << time.str() << '\n';
  std::cout << " THE STATUS OF APPOINMENT : " << getStatusName( appoinment.getStatus() ) << '\n';
}
  
void printBill ( Storage& store , Appoinment& appoinment ) {
  Patient* patientPtr { searchPatientById( appoinment.getPatientId() , store ) } ;
  if ( patientPtr ) {
    Patient& patient { *patientPtr };
    std::cout << " ######################################################\n";
    std::cout << "                    THE REPORT OF BILL                 \n";
    std::cout << " ######################################################\n";
    std::cout << " THE ID OF THE PATIENT IS    : " << patient.getId() << '\n';
    std::cout << " THE NAME IS                 : " << patient.getName() << '\n';
    std::cout << " THE AGE IS                  : " << patient.getAge() << '\n';
    std::cout << " THE PHONE NUMBER            : " << patient.getPhone() << '\n';
    std::cout << " THE DATE OF APPOINMENT      : " << appoinment.getDate().day
	      << " / "<< appoinment.getDate().month << " / " << appoinment.getDate().year<< '\n';
    std::cout << " THE TIME OF APPOINMENT      : " << appoinment.getTime().hour << " : "
	    << appoinment.getTime().minute << '\n';
    std::cout << " THE TYPE OF APPOINMENT      : "
	      << getTypeName( appoinment.getType() ) << '\n';
    std::cout << " THE ID OF APPOINMENT IS     : " << appoinment.getId() << '\n';
    std::cout << " THE STATUS OF APPOINMENTIS  : "<<getStatusName(appoinment.getStatus())<<'\n';
    std::cout << " ----------------------------------------------------------- \n";
    std::cout << " THE PRICE OF THE APPOINMENT : " << setGetPrice(appoinment.getType() ) << '\n';
    std::cout << " ----------------------------------------------------------- \n";
    std::cout << '\n';
    paymentBill( appoinment );
  }else {
    std::cout << " THE PATIENT IS NOT FOUND CHECK ID PATIENT \n";
  }
}
void optionMenu(int& optionNum , const Date& dateShift ) {
  std::cout << " ####################################################################\n";
  std::cout << "                              THE ADDATION MENU                      \n";
  std::cout << " ####################################################################\n";
  showDate( dateShift ) ;
  std::cout << " TYPE THE NUMBER OF THE OPTION NUMBER : \n";
  std::cout << " 1) TO ADD NEW PATIENT \n";
  std::cout << " 2) TO ADD NEW APPOINMENT \n";
  std::cout << " 3) TO EDIT THE PATIENT INFO AND APPOINMENT \n";
  std::cout << " 4) TO CONCELLED THE APPOINTMENT \n";
  std::cout << " 5) TO RETURN TO MAIN MENU \n";
  optionNum = checkInt( 1 , 5 );
}
void checkInfo( int& check ) {
  std::cout << " CHECK THE INFORMATION AR CORRECT OR NOT \n";
  std::cout << " 1) TO CORRECT \n";
  std::cout << " 2) TO NOT CORRECT AND TRY INPUT INFO AGAIN \n";
  check = checkInt( 1, 2 );
}
void optionOne (int& choice, const Date& dateShift, Storage& store ){
  if ( choice == 1 ) {
    while ( true ) {
      Patient patient;
      Appoinment appoinment;
      int optionNum {};
      optionMenu( optionNum , dateShift ) ;

      if ( optionNum == 1 ) {
	while ( true ){ 
	  patient = createPatient();
	  std::cout << '\n';
	  printPatientInfo( patient ) ;
	  std::cout << '\n';
	  int check{};
	  checkInfo( check );
    
	  if ( check == 1 ) {
	    store.AddPatientToArray( patient ) ;
	    std::cout << " ############### COMPLETE ADD PATIENT TO STORAGE ###########\n";
	    std::cout << '\n';
	    break;
	  }else if ( check == 2 ) {
	    continue ;
	  }
	}
      }else if ( optionNum == 2 ) {
	createAppoinment(appoinment, dateShift , store );
	std::cout << '\n';
	printAppoinmentInfo( appoinment ) ;
	std::cout << '\n';
	int check{};
	checkInfo( check );

	if ( check == 1 ) {
	  store.AddAppoinmentToArray( appoinment ) ;
	  std::cout << " ############# COMPLETE ADD APPOINTMENT TO STORAGE ###########\n";
	  std::cout << '\n';
	  printBill( store , appoinment) ;
	}else if ( check == 2 ) {
	  continue ;
	}
      }else if ( optionNum == 3 ) {
	optionEditInfo( store , dateShift );
      }else if ( optionNum == 4 ) {
	cancelledAppoinment( store );
      }else if( optionNum  == 5 ) {
        break;
      }
    }
  }
}
