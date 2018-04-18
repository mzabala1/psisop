#include <pthread.h>

void* processReader(void *args);
void* processPrinter(void *args);
void* processExecuter(void *args);

int
main(int argc, char *argv[]) {
  pthread_t thReader, thPrinter, thExec;

  pthread_create(&thReader, NULL, processReader, NULL);
  pthread_create(&thPrinter, NULL, processPrinter, NULL);
  pthread_create(&thExec, NULL, processExecuter, NULL);

  void *retVal;
  pthread_join(thReader, &retVal);
  pthread_join(thPrinter, &retVal);
  pthread_join(thExec, &retVal);
  
  return PROCESS_SUCCESS;
}

void*
processReader(void* args) {
  return NULL;
}

void*
processPrinter(void* args) {
  return NULL;
}

void*
processExec(void* args) {
  return NULL;
}
