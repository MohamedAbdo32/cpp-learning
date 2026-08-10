#ifndef STORAGE_HPP
#define STORAGE_HPP
#include <vector>
#include "patient.hpp"
#include "appoinment.hpp"

class Storage {
private:
  std::vector<Patient> m_patients {};
  std::vector<Appoinment> m_appoinments {};

public:

  // getter function

  std::vector<Patient>& getPatients() { return m_patients ; }
  std::vector<Appoinment>& getAppoinments()  { return m_appoinments ; }

  const std::vector<Patient>& getConstPatients() const { return m_patients ; }
  const std::vector<Appoinment>& getConstAppoinments() const { return m_appoinments ; }
  
  // set function

  void AddPatientToArray( const Patient& patient ) ;
  void AddAppoinmentToArray( const Appoinment& appoinment ) ;

  void DelPatientFromArray() ;
  void DelAppoinmentFromArray () ;

};

#endif
