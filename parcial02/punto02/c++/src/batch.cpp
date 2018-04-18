#include <pthread.h>
#include "card.h"
#include "line.h"
#include "util.h"
#include "concurrency.h"

void* processReader(void *args);
void* processPrinter(void *args);
void* processExecuter(void *args);

int
main(int argc, char *argv[]) {
  pthread_t thReader, thPrinter, thExec;

  init();
  pthread_create(&thReader, NULL, processReader, NULL);
  pthread_create(&thPrinter, NULL, processPrinter, NULL);
  pthread_create(&thExec, NULL, processExecuter, NULL);

  void *retVal;
  pthread_join(thReader, &retVal);
  pthread_join(thPrinter, &retVal);
  pthread_join(thExec, &retVal);

  return 0;
}

void*
processReader(void* args) {
  for(;;) {
    Card* card = readCard();
    if (card == nullptr) break;
    deployCardInputBuffer(card);
  }
  return NULL;
}

void*
processExecuter(void* args) {
  for (;;) {
    Card* card = getCardFromInputBuffer();
    if (card == nullptr) break;
    Line* line = transformCardToLine(card);
    deployLineOutputBuffer(line);
  }
  return NULL;
}


void*
processPrinter(void* args) {
  for(;;) {
    Line* line = getLineFromOutputBuffer();
    if (line == nullptr) break;
    printLine(line);
  }
  return NULL;
}
