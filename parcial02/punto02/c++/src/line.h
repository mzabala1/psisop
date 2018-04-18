#pragma once
#include "card.h"

class Line {
  static int nro;
  int nLine;
public:
  Line(Card& aCard);
  friend std::ostream &operator<<(std::ostream&, const Line);
};
