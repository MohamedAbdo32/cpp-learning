#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <iostream>
#include <cstddef>
#include <string>
#include <string_view>


class Patient {
private :
  int m_id {};
  std::string m_name {};
  int m_age {};
  std::string m_phone {};
  std::string m_detials {};
  static inline int s_idGenerator { 5000 };
public :
  Patient() = default;
  Patient( std::string_view name , int age , std::string_view phone ,
	   std::string_view detials ) ;
  // getter function
  int getId() const { return m_id ; }
  std::string_view getName() const { return m_name ; }
  std::string_view getDetials() const { return m_detials ; }
  int getAge() const { return m_age ; }
  std::string_view getPhone() const { return m_phone ; }
  // setter function
  void setName( std::string_view name ) ;
  void setDetials( std::string_view detials ) ;
  void setAge( int age ) ;
  void setPhone( std::string_view phone );
};

#endif
