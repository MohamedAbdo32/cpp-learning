#include "pricingEngine.hpp"
#include "appoinment.hpp"

int setGetPrice( AppoinmentType type );

void PricingEngine::setPrice ( AppoinmentType type ) {
  m_price = setGetPrice( type ) ;
}

void PricingEngine::setAllPrice ( int price )  {
  m_allPrice = price ;
}
