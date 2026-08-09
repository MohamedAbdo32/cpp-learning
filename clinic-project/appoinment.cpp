#include <iostream>
#include "appoinment.hpp"

std::string_view getTypeName( AppoinmentType type ) {
  switch( type ) {
  case AppoinmentType::newExamination : return "NEW EXAMINATION";
  case AppoinmentType::consultation   : return "CONSULTATION" ;
  case AppoinmentType::returnVisit    : return "RETURN VISIT" ;
  default                             : return "UNKNOWN";
  }
}

int setGetPrice( AppoinmentType type ) {
  switch( type ) {
  case AppoinmentType::newExamination : return 200 ;
  case AppoinmentType::consultation   : return 150 ;
  case AppoinmentType::returnVisit    : return 100 ;
  }
  return 0 ;
}

Appoinment::Appoinment( AppoinmentType type ) : m_type { type } {
  m_price = setGetPrice( m_type ) ;
}

void Appoinment::setType( AppoinmentType type ) {
  m_type = type ;
}
void Appoinment::setPrice( AppoinmentType type ) {
  m_price = setGetPrice ( type ) ;
}
