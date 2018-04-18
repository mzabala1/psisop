#include <cassert>
#include <iostream>
#include <pthread.h>
#include "bridge.h"
#include "utils.h"
#include "threadArg.h"
#define NDEBUG

void* processWestEast(void* args);
void* processEastWest(void* args);

int
main(int argc, char *argv[]) {
  Bridge* bridge = new Bridge();
  pthread_t we[MAX_THREAD_WE];
  pthread_t ew[MAX_THREAD_EW];

  for (int i = 0, j = 0; i < MAX_THREAD_WE; ++i) {
    ThreadArg *ta = new ThreadArg(bridge, j++);
    pthread_create(&we[i], NULL, processWestEast, ta);
    ta = new ThreadArg(bridge, j++);
    pthread_create(&ew[i], NULL, processEastWest, ta);
  }

  for (int i = 0; i < MAX_THREAD_WE; ++i) {
    void* pRetVal;
    pthread_join(we[i], &pRetVal);
    pthread_join(ew[i], &pRetVal);
  }

  delete bridge;

  return 0;
}

void*
processWestEast(void* args) {
  ThreadArg* ta = static_cast<ThreadArg*>(args);
  
  ta->bridge->enterWest(ta->nCar);
  assert(ta->bridge->getNCarsOnBridge() < 2);
  ta->bridge->leaveEast(ta->nCar);

  return NULL;
}

void*
processEastWest(void* args) {
  ThreadArg* ta = static_cast<ThreadArg*>(args);

  ta->bridge->enterEast(ta->nCar);
  assert(ta->bridge->getNCarsOnBridge() < 2);
  ta->bridge->leaveWest(ta->nCar);

  return NULL;
}
