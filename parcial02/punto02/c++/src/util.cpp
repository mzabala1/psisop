#include "util.h"
#include <iostream>

Card*
readCard() {
  return new Card();
}

void
printLine(Line* line) {
  std::cout << line << std::endl;
}

Line*
transformCardToLine(Card *card) {
  return new Line(*card);
}
