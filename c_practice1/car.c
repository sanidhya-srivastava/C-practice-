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
int numCars = 10;

// Function to display the menu options
void displayMenu() {
  printf("\n--- Car Rental System ---\n");
  printf("1. Rent Car\n");
  printf("2. Return Car\n");
  printf("3. Display Cars\n");
  printf("4. Exit\n");
  printf("-------------------------\n");
  printf("Enter your choice: ");
}

// Function to rent a car
void rentCar() {
  int carId;
  printf("Enter Car ID: ");
  scanf("%d", &carId);

  int i;
  for (i = 0; i < numCars; i++) { //loop to rent a car and check if car is already rented
    if (cars[i].carId == carId) {
      if (cars[i].isRented) {
        printf("Car is already rented!\n");
        return;
      } else {
        cars[i].isRented = 1;
        printf("Car rented successfully!\n");
        return;
      }
    }
  }

  printf("Car not found!\n");
}

// Function to return a rented car
void returnCar() {
  int carId;
  int numberOfHours;
  int totalPrice;

  printf("Enter Car ID: ");
  scanf("%d", &carId);

  int i;
  for (i = 0; i < numCars; i++) {
    if (cars[i].carId == carId) {
      if (cars[i].isRented) {
        printf("Enter number of hours: ");
        scanf("%d", &numberOfHours);

        totalPrice = numberOfHours * cars[i].carPricePerHour;

        printf("Total price: %d rupees\n", totalPrice);

        cars[i].isRented = 0;

        return;
      } else {
        printf("Car is not rented !\n");
        return;
      }
    }
  }

  printf("Car not found!\n");
}

// Function to display all cars
void displayCars() {
  printf("\n--- Car List ---\n");
  printf("ID\tModel\tType\trate/hour\tAvailability\n");
  int i;
  for (i = 0; i < numCars; i++) {
    printf("%d\t%s\t%s\t%d rupees\t", cars[i].carId, cars[i].carModel, cars[i].carType, cars[i].carPricePerHour);
    if (cars[i].isRented) {
      printf("Rented\n");
    } else {
      printf("Available\n");
    }
  }
  printf("-----------------\n");
}
int main() {
    Car cars[100];
    int numCars = 0;
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                rentCar();
                break;
            case 2:
                returnCar();
                break;
            case 3:
                displayCars();
                break;
            case 4:
                printf("Thank you for using the Car Rental System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (1);
    
    return 0;
}