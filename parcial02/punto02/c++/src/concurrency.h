#pragma once
#include "card.h"
#include "line.h"
#include "util.h"

void init();
void deployCardInputBuffer(Card*);
Card* getCardFromInputBuffer();
void deployLineOutputBuffer(Line*);
Line* getLineFromOutputBuffer();
