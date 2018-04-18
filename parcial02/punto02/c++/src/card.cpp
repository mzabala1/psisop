#include "card.h"

int Card::nro = 0;

Card::Card() : nCard(Card::nro++) { }

std::ostream &operator<<(std::ostream& strm, const Card card) {
  strm << "Card: " << card.nCard << std::endl;
  return strm;
}
