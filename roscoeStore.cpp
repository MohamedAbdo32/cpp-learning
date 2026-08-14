#include <iostream>
#include <array>
#include <string>
#include <string_view>
#include <cassert>
#include <random>
#include <chrono>

namespace Random {
  std::mt19937 generate() {
    std::random_device rd {};
    std::seed_seq ss { static_cast
		       <std::seed_seq::result_type>(
			  std::chrono::steady_clock::now().time_since_epoch().count()),
		       rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    return std::mt19937 { ss };
  }

  std::mt19937 mt { generate() };

  int get( int min , int max ) {
    return std::uniform_int_distribution{ min , max }(mt);
  }
}

namespace Potion {

  enum Type {
    healing,
    mana,
    speed,
    invisibility,
    count,
  };

  std::array<std::string_view , Type::count > potionNames { "healing" , "mana"
							 , "speed" , "invisibility" };
  static_assert( Type::count == std::size( potionNames) );

  std::array<int , Type::count > potionCosts { 20 , 30 , 12 , 50 };

  static_assert( Type::count == std::size( potionCosts ) );

}

class Player {
private :
  std::string m_name {};
  Potion::Type m_potionInventory {};
  int m_goldAmount {};
public :
  Player ( std::string_view name , Potion::Type type , int gold )
    : m_name { name } , m_potionInventory { type } , m_goldAmount { gold } {}
  // getter function
  std::string getName() const { return m_name ; };
  Potion::Type getPotion() const { return m_potionInventory; }
  int getGold() const { return m_goldAmount; }
};

void welcomeSection( std::string& name ) {
  std::cout << "Welcome to Roscoe`s potion emporium! \n";
  std::cout << "Enter your name: ";
  std::getline( std::cin >> std::ws , name );
  std::cout << "Hello, " << name <<", you have "<< Random::get( 80, 120 ) << " gold.";
  std::cout << '\n';
  std::cout << '\n';
}
void endSection() {
  std::cout << '\n';
  std::cout << "Thanks for shopping at Roscoe`s potion emporium! \n";
}

void shop( std::array<std::string_view,Potion::Type::count>& arr1, std::array<int,Potion::Type::count>& arr2){
  std::cout << "Here is our selection for today: \n";
  for ( std::size_t i{}; i < std::size(arr1) ; ++i ) {
    std::cout << i << ") " << arr1[i] << " costs " << arr2[i] << '\n';
  }
}

int main() {
  std::string name {};
  welcomeSection( name );
  shop(Potion::potionNames , Potion::potionCosts );
  endSection();
  
  return 0;
}
