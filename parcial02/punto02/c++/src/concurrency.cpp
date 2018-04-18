#include "concurrency.h"
#include <iostream>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

sem_t emptyb1, emptyb2, llb1, llb2, mutexBuffer1, mutexBuffer2;
int cardIn, cardOut, lineIn, lineOut;

void init() {
  sem_init(&emptyb1,0,10);
  sem_init(&emptyb2,0,10);
  sem_init(&llb1,0,0);
  sem_init(&llb2,0,0);
  sem_init(&mutexBuffer1,0,1);
  sem_init(&mutexBuffer2,0,1);
  cardIn = 0;
  cardOut = 0;
  lineIn = 0;
  lineOut = 0;
}
Card* input_buffer[N];
Line* output_buffer[N];

void deployCardInputBuffer(Card* card1) {
  sem_wait(&emptyb1);
  sem_wait(&mutexBuffer1);
  input_buffer[cardIn] = card1;
  cardIn = (cardIn +1 ) % N;
  sem_post(&mutexBuffer1);
  sem_post(&llb1);
}

Card* getCardFromInputBuffer() {
  sem_wait(&llb1);
  sem_wait(&mutexBuffer1);
  Card* card = input_buffer[cardOut];
  cardOut = (cardOut + 1) % N;
  sem_post(&mutexBuffer1);
  sem_post(&emptyb1);
  return card;
}

void deployLineOutputBuffer(Line* line) {
  sem_wait(&emptyb2);
  sem_wait(&mutexBuffer2);
  output_buffer[lineIn] = line;
  lineIn = (lineIn +1 ) % N;
  sem_post(&mutexBuffer2);
  sem_post(&llb2);
}

Line* getLineFromOutputBuffer() {
  sem_wait(&llb2);
  sem_wait(&mutexBuffer2);
  Line* line = output_buffer[lineOut];
  lineOut = (lineOut + 1) % N;
  sem_post(&mutexBuffer2);
  sem_post(&emptyb2);
  return line;
}
