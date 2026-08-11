#ifndef PRICINGENGINE_HPP
#define PRICINGENGINE_HPP

#include <iostream>
#include "appoinment.hpp"

class PricingEngine {
private :
  int m_price {};
  int m_allPrice {};

public :

  // getter function
  int getPrice() const { return m_price ; }
  int getAllPrice () const { return m_allPrice ; }

  // setter function

  void setPrice ( AppoinmentType type ) ;
  void setAllPrice ( int price ) ;

};

#endif
