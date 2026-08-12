#ifndef APPOINMENT_HPP
#define APPOINMENT_HPP

enum class AppoinmentType {
  newExamination = 1,
  consultation,
  returnVisit
};
enum class AppoinmentStatus {
  booked = 1 ,
  waitting ,
  completed ,
  cancelled ,
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
std::string_view getStatusName( AppoinmentStatus status ) ;
std::string_view getTypeName( AppoinmentType type ) ;
int AppoinmentGetPrice( AppoinmentType type );

class Appoinment {
private:
  int m_id {};
  int m_patientId{};
  AppoinmentType m_type {};
  Date m_date {};
  Time m_time {};
  AppoinmentStatus m_status { AppoinmentStatus::booked };
  static inline int s_idGenerator { 7000 };
public:
  Appoinment() = default;
  Appoinment( int patientId , AppoinmentType type , Date date , Time time );

  // getter function
  AppoinmentType getType() const { return m_type; }
  int getId() const { return m_id ; }
  int getPatientId() const { return m_patientId; }
  Date getDate() const { return m_date ; }
  Time getTime() const { return m_time ; }
  AppoinmentStatus getStatus() const { return m_status ; }
  // setter function

  void setType( AppoinmentType type ) ;
  void setDate( Date date ) ;
  void setTime( Time time ) ;
  void setStatus ( AppoinmentStatus status ) ;
  

};

#endif
