#ifndef APPOINMENT_HPP
#define APPOINMENT_HPP

enum class AppoinmentType {
  newExamination = 1,
  consultation,
  returnVisit
};
struct Date {
  int day {};
  int month {};
  int year {};
};
struct Time {
  int hour {};
  int minute {};
};
std::string_view getTypeName( AppoinmentType type ) ;
int AppoinmentGetPrice( AppoinmentType type );

class Appoinment {
private:
  AppoinmentType m_type {};
  Date m_date {};
  Time m_time {};
public:
  Appoinment( AppoinmentType type , Date date , Time time  );

  // getter function
  AppoinmentType getType() const { return m_type; }
  Date getDate() const { return m_date ; }
  Time getTime() const { return m_time ; }
  // setter function

  void setType( AppoinmentType type ) ;
  void setDate( Date date ) ;
  void setTime( Time time ) ;

};

#endif
