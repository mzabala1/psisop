#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "bridge.h"
#include <iostream>

using namespace std;

static void printCar(const char* place, const int nCar) {
  cout << "nCar: " << nCar << place << endl;
}

sem_t mutex, semPrioridad, sc;

Bridge::Bridge() : nCarsOnBridge(0) {
  sem_init(&mutex,0,1);
  sem_init(&semPrioridad,0,1);
  sem_init(&sc,0,1);
  contOeste = 0;
 }
Bridge::~Bridge() { }

void Bridge::enterWest(int nCar) {
  sem_wait(&mutex);
  contOeste++;
  if(contOeste == 1){sem_wait(&semPrioridad);}
  sem_post(&mutex);
  sem_wait(&sc);
  nCarsOnBridge++;
  printCar(" is entering by west ", nCar);
}

void Bridge::enterEast(int nCar) {
  sem_wait(&semPrioridad);
  sem_wait(&sc);
  nCarsOnBridge++;
  printCar(" is entering by east ", nCar);
  sem_post(&semPrioridad);
}

void Bridge::leaveEast(int nCar) {
  sem_wait(&mutex);
  contOeste--;

  if(contOeste == 0) {
    sem_post(&semPrioridad);
  }
  sem_post(&mutex);
  nCarsOnBridge--;
  printCar(" is leaving by east ", nCar);
  sem_post(&sc);
}

void Bridge::leaveWest(int nCar) {
  nCarsOnBridge--;
  printCar(" is leaving by west ", nCar);
  sem_post(&sc);
}

int Bridge::getNCarsOnBridge() const {
  return nCarsOnBridge;
}
