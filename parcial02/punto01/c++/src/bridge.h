#pragma once

class Bridge {
  int nCarsOnBridge, contOeste;
 public:
  Bridge();
  ~Bridge();

  int  getNCarsOnBridge() const;
  void enterWest(int nCar);
  void enterEast(int nCar);
  void leaveWest(int nCar);
  void leaveEast(int nCar);
};
