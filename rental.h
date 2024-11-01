
#ifndef RENTAL_H
#define RENTAL_H

#include "file_operations.h"

typedef struct {
    int rentalID;
    int customerID;
    int gameID;
    struct {
        int day, month, year;
    } rentalDate, returnDate;
} Rental;

void add_rental(tof *rentalFile);
int rechercher_rental(tof *tof, int rentalID, Rental *rental);
void printRental(Rental rental);
void display_all_rentals(tof *tof);

#endif
