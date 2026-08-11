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
  int m_id {};
  AppoinmentType m_type {};
  Date m_date {};
  Time m_time {};
  static inline int s_idGenerator { 5000 };
public:
  Appoinment( AppoinmentType type , Date date , Time time  );

  // getter function
  AppoinmentType getType() const { return m_type; }
  int getId() const { return m_id ; }
  Date getDate() const { return m_date ; }
  Time getTime() const { return m_time ; }
  // setter function

  void setType( AppoinmentType type ) ;
  void setDate( Date date ) ;
  void setTime( Time time ) ;

};

#endif
