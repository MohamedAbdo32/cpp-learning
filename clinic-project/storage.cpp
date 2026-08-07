#include <iostream>
#include "storage.hpp"

void Storage::AddPatientToArray( Patient& patient ) {
  m_patients.push_back( patient );
}
void Storage::AddAppoinmentToArray( Appoinment& appoinment ) {
  m_appoinments.push_back( appoinment ) ;
}
void Storage::DelPatientFromArray() {
  m_patients.pop_back() ;
}
void Storage::DelAppoinmentFromArray() {
  m_appoinments.pop_back();
}
