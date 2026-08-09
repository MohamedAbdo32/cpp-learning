#ifndef APPOINMENT_HPP
#define APPOINMENT_HPP

enum class AppoinmentType {
  newExamination = 1,
  consultation,
  returnVisit
};
inline std::string_view getTypeName( AppoimentType type ) ;
inline int AppoinmentGetPrice( AppoinmentType type );

class Appoinment {
private:
  AppoinmentType m_type {};
  int m_price {};

public:
  Appoinment( AppoinmentType type );

  // getter function
  AppoinmentType getType() const { return m_type; }
  int getPrice() const { return m_price; }

  // setter function

  void setType( AppoinmentType type ) ;
  void setPrice( AppoinmentType type ) ;

};

#endif
