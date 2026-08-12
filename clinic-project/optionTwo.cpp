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
void updatePatient( int& choice, Patient& patient, Appoinment& appoinment, Storage& store ) {
  if ( choice == 1 ) {
    std::cout << " TYPE THE NEW NAME OF THE PATIENT : ";
    std::string name {};
    std::getline ( std::cin >> std::ws , name ) ;
    patient.setName ( name );
    std::cout << " ##################### COMPLATE UPDATE THE NAME #####################\n";
  }else if ( choice == 2 ) {
    std::cout << " TYPE THE NEW NUMBER OF THE AGE PATIENT : ";
    int age { checkInt( 1 , 300 ) };
    patient.setAge ( age ) ;
    std::cout << " ################### COMPLATE UPDATE THE AGE ########################\n";
  }else if ( choice == 3 ) {
    Date newDate { setDate() };
    appoinment.setDate( newDate ) ;
    std::cout << " ################### COMPLATE UPDATE THE DATE ######################\n";
  }else if ( choice == 4 ) {
    Time newTime { checkValidationTime( store ) };
    appoinment.setTime ( newTime ) ;
    std::cout << " ################# COMPLATE UPDATE THE TIME ###########################\n";
  }else if ( choice == 5 ) {
    std::cout << " TYPE THE NEW DETIALS OF THE PATIENT: \n";
    std::string detials {};
    std::getline( std::cin >> std::ws , detials ) ;
    patient.setDetials( detials );
    std::cout << " ################### COMPLATE UPDATE THE DETIALS ####################\n";
  }else if ( choice == 6 ) {
    std::cout << " TYPE THE NEW NUMBER OF THE PHONE OF THE PATIENT: \n";
    std::string phone {};
    std::getline( std::cin >> std::ws , phone ) ;
    patient.setPhone ( phone ) ;
    std::cout << " ################ COMPLATE UPDATE THE PHONE #######################\n";
  }
}
void updatePatientMenu ( int& choice , const Date& dateShift ) {
  
  std::cout << " #############################################################\n";
  std::cout << "                       UPDATE MENU                            \n";
  std::cout << " #############################################################\n";
  showDate( dateShift );
  std::cout << " TYPE THE NEMBER OF THE CHOICE YOU WANT TO UPDATE : \n";
  std::cout << " 1) UPDATE THE NAME OF THE PATIENT \n";
  std::cout << " 2) UPDATE THE AGE OF THE PATIENT \n";
  std::cout << " 3) UPDATE THE DATE OF THE APPOINMENT \n" ;
  std::cout << " 4) UPDATE THE TIME OF THE APPOINMENT \n";
  std::cout << " 5) UPDATE THE DETIALS OF THE PATIENT \n";
  std::cout << " 6) UPDATE THE PHONE OF THE PATIENT \n";
  std::cout << " 7) RETURN TO MAIN MENU \n";
  choice = checkInt( 1 , 7 ) ;
}
void patientCheck( Patient* patient , int& choice , const Date& dateShift , Storage& store ) {
  if ( patient ) {
    Patient& editPatient { *patient };
    
    Appoinment* appoinmentPtr { searchAppoinment( editPatient.getId() , store ) };
    
    if ( appoinmentPtr ) {
      updatePatientMenu( choice , dateShift ) ;
      
      Appoinment& appoinment { *appoinmentPtr };
      
      updatePatient( choice , editPatient , appoinment , store );
    }else {
      std::cout << " THE PATIENT IS NOT HAVE ANY APPOINMENT IN THE STORAGE \n";
    }
  }else {
    std::cout << " THE PATIENT IS NOT IN THE STORAGE , CHECK IT AND TRY AGAIN \n" ;
  }
}
void optionTwo( Storage& store , int& choice , const Date& dateShift ) {
  if ( choice == 2 ) {
    int num {};
    returnToMainMenu( num );
    if ( num == 1 ) {
      return ;
      std::cout << " ######################### RETURN TO MAIN MENU ####################\n";
    }
    std::string info {};
    getNameToSearch( info );
    std::cout << '\n';
    Patient* patient { searchPatient( info , store ) };
    while( true ) {
      int choice {};
      patientCheck( patient , choice , dateShift , store );
      if ( choice == 7 ) {
	std::cout << " ################### RETURN TO MAIN MENU ########################\n";
	break;
      }
    }
  }
}

