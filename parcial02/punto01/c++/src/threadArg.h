#pragma once
#include "bridge.h"

struct ThreadArg {
  ThreadArg(Bridge* bridge, int nCar);
  Bridge* bridge;
  int nCar;
};
