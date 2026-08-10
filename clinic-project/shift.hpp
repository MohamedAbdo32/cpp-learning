#ifndef SHIFT_HPP
#define SHIFT_HPP

#include <iostream>

class Shift {
private:
  int m_allPrice {};

public :

  // getter function

  int getAllPrice () const { return m_allPrice ; }

  // setter function

  void setBalance ( int amount ) {
    m_allPrice += amount ;
  }
};

#endif
