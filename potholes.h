/*
  potholes.h - Library created to use in detection potholes using accelorometer .
  Created by Muskan Agarwal March17 2019
  Released into the public domain.
*/


#ifndef potholes_h
#define potholes_h
class potholes
{
  public:
  float buffer[5]; //buffer to store 5 accelaration values to calculate the average
  int buffer_pointer; // To track the index of buffer array
  void add(float number); //To add accelaration values to buffer array
  float get_avg(); // To find the average of values stored in buffer array
  float get_stdev(); // Calculates standard deviation.
  potholes();//constructor of stat class
};
#endif
