#pragma once
#include <iostream>

class Card {
  static int nro;
  int nCard;
public:
  Card();
  friend std::ostream &operator<<(std::ostream&, const Card); 
};
