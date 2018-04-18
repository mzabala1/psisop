#pragma once
#include "card.h"
#include "line.h"

Card* readCard();
void  printLine(Line*);
Line* transformCardToLine(Card *);

const int N = 10;
