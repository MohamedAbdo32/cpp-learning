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
std::string_view getStatusName( AppoinmentStatus status ) {
  switch( status ) {
  case AppoinmentStatus::booked    : return "BOOKED";
  case AppoinmentStatus::waitting  : return "WAITING";
  case AppoinmentStatus::completed : return "COMPLETED";
  case AppoinmentStatus::cancelled : return "CANCELLED";
  default                          : return "UNKNOWN";
  }
}

Appoinment::Appoinment( int patientId ,  AppoinmentType type , Date date , Time time )
  : m_patientId { patientId } , m_type { type } , m_date { date } , m_time { time }  {
  m_id = ++s_idGenerator;
}

void Appoinment::setType( AppoinmentType type ) {
  m_type = type ;
}
void Appoinment::setDate( Date date ) {
  m_date = date ;
}
void Appoinment::setTime( Time time ) {
  m_time = time ;
}
void Appoinment::setStatus( AppoinmentStatus status ) {
  m_status = status ;
}
