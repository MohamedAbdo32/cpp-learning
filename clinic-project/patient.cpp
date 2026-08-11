#include "patient.hpp"

Patient::Patient( int id , std::string_view name , int age , std::string_view phone  ,
		  std::string_view detials )
: m_id { id } , m_name { name } , m_age { age } , m_phone { phone } 
  , m_detials { detials } {}

void Patient::setName( std::string_view name ) {
  m_name = name ;
}
void Patient::setDetials( std::string_view detials ) {
  m_detials = detials ;
}
void Patient::setAge( int age ) {
  m_age = age ;
}
void Patient::setPhone( std::string_view phone ) {
  m_phone = phone ;
}
