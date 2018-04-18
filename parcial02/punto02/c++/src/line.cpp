#include "line.h"

int Line::nro = 0;

Line::Line(Card& aCard) :
  nLine(Line::nro++) { }

std::ostream &operator<<(std::ostream& strm, const Line line) {
  strm << "Line: " << line.nLine << std::endl;
}

