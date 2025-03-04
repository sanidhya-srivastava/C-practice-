#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // structure car that stores information about the car
  int carId;
  char carModel[20];
  char carType[20];
  int carPricePerHour;
  int isRented;
} Car;

// an array with car that stores values of cars
Car cars[] = {
  {1111, "swift", "Sedan", 300, 0},
  {2222, "accord", "Sedan", 350, 0},
  {3333, "kwid", "sedan", 250, 0},
  {4444, "creta", "compact", 600, 0},
  {5555, "bullero", "suv", 800, 0},
  {6666, "scorpio", "suv", 900, 0},
  {7777, "thar", "suv", 850, 0},
  {8888, "duster", "compact", 500, 0},
  {9999, "Corolla", "Sedan", 450, 0},
  {1010, "Civic", "Sedan", 400, 0}
};

// Number of pre-stored cars
int numCars = sizeof(cars) / sizeof(cars[0]);
void main()
{
    printf("%d",numCars);
}