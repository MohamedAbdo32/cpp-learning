#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <iostream>
#include <cstddef>
#include <string>
#include <string_view>

struct Date {
  int day {};
  int month {};
  int year {};
};

class Patient {
private :
  int m_id {};
  std::string m_name {};
  int m_age {};
  std::string m_phone {};
  Date m_shortDate {};
  std::string m_detials {};

public :
  Patient( int id , std::string_view name , int age , std::string_view phone , Date m_shortDate ,
	   std::string_view detials ) ;
  // getter function
  int getId() const { return m_id ; }
  std::string_view getName() const { return m_name ; }
  std::string_view getDetials() const { return m_detials ; }
  int getAge() const { return m_age ; }
  Date getDate() const { return m_shortDate ; }
  std::string_view getPhone() const { return m_phone ; }
  // setter function
  void setName( std::string_view name ) ;
  void setDetials( std::string_view detials ) ;
  void setAge( int age ) ;
  void setDate( Date newDate );
  void setPhone( std::string_view phone );
};

#endif
