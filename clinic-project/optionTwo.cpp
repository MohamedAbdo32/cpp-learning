#include <iostream>
#include "validation.hpp"
#include "patient.hpp"
#include "appoinment.hpp"
#include "storage.hpp"

Date setDate ();
void showDate( const Date& dateShift );
Time setTime () ;
Time checkValidationTime( Storage& store );
void returnToMainMenu( int& num ) ;
Patient* searchPatient( std::string_view info , Storage& store );
void printAppoinmentInfo( const Appoinment& appoinment ) ;
Appoinment* searchAppoinment ( int id , Storage& store ) {
  for ( auto& ele : store.getAppoinments() ) {
    if ( id == ele.getId() ) {
      return &ele ;
    }
  }
  return nullptr ;
}
void getNameToSearch( std::string& info ) {
  std::cout << " TYPE THE NAME OR PHONE OF THE PATIENT TO FIND : ";
  std::getline( std::cin >> std::ws , info ) ;
}
void updatePatient( int& choice, Patient& patient ) {
  if ( choice == 1 ) {
    std::cout << " TYPE THE NEW NAME OF THE PATIENT : ";
    std::string name {};
    std::getline ( std::cin >> std::ws , name ) ;
    patient.setName ( name );
    std::cout << " ##################### COMPLATE UPDATE THE NAME ##################\n";
  }else if ( choice == 2 ) {
    std::cout << " TYPE THE NEW NUMBER OF THE AGE PATIENT : ";
    int age { checkInt( 1 , 300 ) };
    patient.setAge ( age ) ;
    std::cout << " ################### COMPLATE UPDATE THE AGE ######################\n";
  }else if ( choice == 3 ) {
    std::cout << " TYPE THE NEW DETIALS OF THE PATIENT: \n";
    std::string detials {};
    std::getline( std::cin >> std::ws , detials ) ;
    patient.setDetials( detials );
    std::cout << " ################## COMPLATE UPDATE THE DETIALS ####################\n";
  }else if ( choice == 4 ) {
    std::cout << " TYPE THE NEW NUMBER OF THE PHONE OF THE PATIENT: \n";
    std::string phone {};
    std::getline( std::cin >> std::ws , phone ) ;
    patient.setPhone ( phone ) ;
    std::cout << " ################ COMPLATE UPDATE THE PHONE #######################\n";
  }
}
void updateAppoinment( int& choice , Appoinment& appoinment, Storage& store ) {
 if ( choice == 1 ) {
    Date newDate { setDate() };
    appoinment.setDate( newDate ) ;
    std::cout << " ################### COMPLATE UPDATE THE DATE ######################\n";
  }else if ( choice == 2 ) {
    Time newTime { checkValidationTime( store ) };
    appoinment.setTime ( newTime ) ;
    std::cout << " ################# COMPLATE UPDATE THE TIME #######################\n";
 }else if ( choice == 3 ) {
     std::cout << " TYPE THE NUMBER OF THE CHOICE: \n" ;
     std::cout << " 1) NEW EXAMINATION -> 200 SAR \n" ;
     std::cout << " 2) CONSULTATION    -> 150 SAR \n" ;
     std::cout << " 3) RETURN VISTI    -> 100 SAR\n" ;
     int type { checkInt( 1 , 3 ) };
     appoinment.setType( static_cast<AppoinmentType>( type ) );
     std::cout << " ################ COMPLATE UPDATE THE TYPE #######################\n";
 }
}
void updateMenu ( int& optionNum , const Date& dateShift ) {
  std::cout << " ############################################################\n";
  std::cout << "                         UPDATE MENU                         \n";
  std::cout << " ############################################################\n";
  showDate( dateShift ) ;
  std::cout << " TYPE THE NUMBER OF THE OPTION YOU NEED TO EDIT : \n";
  std::cout << " 1) TO UPDATE PATIENT INFO \n";
  std::cout << " 2) TO UPDATE APPOINTMENT INFO \n";
  std::cout << " 3) TO RETURN TO MAIN MENU \n";
  optionNum = checkInt( 1 , 3 );
}
void updateAppoinmentMenu ( int& choice , const Date& date ) {
  std::cout << " #############################################################\n";
  std::cout << "                         UPDATE APPOINTMENT MENU              \n";
  std::cout << " #############################################################\n";
  showDate ( date ) ;
  std::cout << " TYPE THE NUMBER OF THE CHOICE YOU WANT TO UPDATE : \n";
  std::cout << " 1) TO UPDATE THE DATE OF THE APPOINMENT \n";
  std::cout << " 2) TO UPDATE THE TIME OF THE APPOINMENT \n";
  std::cout << " 3) TO UPDATE THE TYPE OF THE APPOINMENT \n";
  std::cout << " 4) TO RETRUN TO UPDATE MENU \n";
  choice = checkInt( 1 , 4 );
}
void appoinmentProcess ( int& choice , const Date& dateShift , Storage& store ) {
  std::cout << " TYPE THE ID NUMBER OF THE APPOINMENT : ";
  int id { checkIntPositive() };
  Appoinment* appoinmentPtr { searchAppoinment( id , store ) };
  if ( appoinmentPtr ) {
    while( true ) {
      Appoinment& appoinment { *appoinmentPtr };
      updateAppoinmentMenu( choice, dateShift );
      updateAppoinment( choice , appoinment, store );
      if ( choice == 4 ) {
	break;
      }
    }
  }else {
    std::cout << " ERROR: NO APPOINMENT WITH THIS ID , CHECK ID AND TRY AGAIN \n";
  }
}
void updatePatientMenu ( int& choice , const Date& dateShift ) {
  std::cout << " #############################################################\n";
  std::cout << "                       UPDATE PATEINT MENU                    \n";
  std::cout << " #############################################################\n";
  showDate( dateShift );
  std::cout << " TYPE THE NEMBER OF THE CHOICE YOU WANT TO UPDATE : \n";
  std::cout << " 1) UPDATE THE NAME OF THE PATIENT \n";
  std::cout << " 2) UPDATE THE AGE OF THE PATIENT \n";
  std::cout << " 3) UPDATE THE DETIALS OF THE PATIENT \n";
  std::cout << " 4) UPDATE THE PHONE OF THE PATIENT \n";
  std::cout << " 5) RETURN TO UPDATE MENU  \n";
  choice = checkInt( 1 , 5 ) ;
}
void patientProcess(int& choice, const Date& dateShift, Storage& store){
  std::string info {};
  getNameToSearch ( info );
  std::cout << '\n';
  Patient* patientPtr { searchPatient( info , store ) };
  if ( patientPtr ) {
    while( true ) {
      Patient& patient { *patientPtr };
      updatePatientMenu( choice , dateShift ) ;
      updatePatient( choice , patient );
      if ( choice == 5 ) {
	break;
      }
    }
  }else {
    std::cout << " THE PATIENT IS NOT IN THE STORAGE , CHECK IT AND TRY AGAIN \n" ; 
  }
}
void updateProcess( int& optionNum , const Date& date , Storage& store ) {
  if ( optionNum == 1 ) {
    int choice {};
    patientProcess( choice , date , store );
  }else if ( optionNum == 2 ) {
    int choice {};
    appoinmentProcess( choice , date , store );
  }
}
void optionEditInfo( Storage& store  , const Date& dateShift ) {
  while (true) {
    int optionNum {};
    updateMenu( optionNum , dateShift );
    updateProcess ( optionNum , dateShift , store );
    if ( optionNum  == 3 ) {
      std::cout << " ################### RETURN TO MAIN MENU ########################\n";
      break;
    }
  }
}

void cancelledAppoinment( Storage& store) {
  std::cout << " TYPE THE ID NUMBER OF THE APPOINMENT : ";
  int id { checkIntPositive() };
  Appoinment* appoinmentPtr { searchAppoinment( id , store ) };
  if ( appoinmentPtr ) {
    Appoinment& appoinment { *appoinmentPtr };
    printAppoinmentInfo(appoinment);
    std::cout << " DO YOU WANT OT CANCEL APPOINMENT IF 1-YES OR 2-NO :";
    int choice { checkInt( 1, 2 )};
    if ( choice == 1 ) {
      if ( appoinment.getStatus() == AppoinmentStatus::cancelled) {
	std::cout << " THE APPOINMENT STATUS IS CANCELLED !!!!\n";
	return ;
      }
      if ( appoinment.getStatus() == AppoinmentStatus::completed ) {
	std::cout << " THE APPOINMENT STATUS WAS COMPLETED YOU CAN NOT CANCELLED IT !!\n";
	return ;
      }
      appoinment.setStatus( AppoinmentStatus::cancelled );
      std::cout <<getStatusName( appoinment.getStatus());
      std::cout << " ################ COMPLETED CANCELLED APPOINMENT ################\n";
    }else {
      return ;
    }
  }else {
    std::cout << " ERROR: NO APPOINMENT WITH THIS ID , CHECK ID AND TRY AGAIN \n";
  }
}
