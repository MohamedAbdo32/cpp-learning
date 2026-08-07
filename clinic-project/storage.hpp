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

  const std::vector<Patient>& getPatients() const { return m_patients ; }
  const std::vector<Appoinment>& getAppoinments() const { return m_appoinments ; }

  // set function

  void AddPatientToArray( Patient& patient ) ;
  void AddAppoinmentToArray( Appoinment& appoinment ) ;

  void DelPatientFromArray() ;
  void DelAppoinmentFromArray () ;

};

#endif
