#include "pricingEngine.hpp"

void PricingEngine::setPrice ( AppoinmentType type ) {
  m_price = getTypePrice( type ) ;
}

void PricingEngien::setAllPrice ( int price )  {
  m_allPrice = price ;
}
