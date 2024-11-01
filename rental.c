
#include "rental.h"
#include <stdio.h>

void add_rental(tof *rentalFile) {
    Rental rental;
    printf("Enter Rental ID: ");
    scanf("%d", &rental.rentalID);
    printf("Enter Customer ID: ");
    scanf("%d", &rental.customerID);
    printf("Enter Game ID: ");
    scanf("%d", &rental.gameID);
    printf("Enter Rental Date (dd mm yyyy): ");
    scanf("%d %d %d", &rental.rentalDate.day, &rental.rentalDate.month, &rental.rentalDate.year);
    printf("Enter Return Date (dd mm yyyy): ");
    scanf("%d %d %d", &rental.returnDate.day, &rental.returnDate.month, &rental.returnDate.year);
    insert_rental(rentalFile, rental.rentalID, rental);
}

int rechercher_rental(tof *tof, int rentalID, Rental *rental) {
    BlocRental block;
    fseek(tof->file, sizeof(Entete), SEEK_SET);

    while (read_BlocRental(tof, &block, tof->header.blockCount)) {
        for (int i = 0; i < block.count; i++) {
            if (block.rentals[i].rentalID == rentalID) {
                *rental = block.rentals[i];
                return 1;
            }
        }
    }
    return 0;
}

void printRental(Rental rental) {
    printf("Rental ID: %d\n", rental.rentalID);
    printf("Customer ID: %d\n", rental.customerID);
    printf("Game ID: %d\n", rental.gameID);
    printf("Rental Date: %02d/%02d/%04d\n", rental.rentalDate.day, rental.rentalDate.month, rental.rentalDate.year);
    printf("Return Date: %02d/%02d/%04d\n", rental.returnDate.day, rental.returnDate.month, rental.returnDate.year);
}

void display_all_rentals(tof *tof) {
    BlocRental block;
    fseek(tof->file, sizeof(Entete), SEEK_SET);

    printf("\n--- All Rentals ---\n");
    while (read_BlocRental(tof, &block, tof->header.blockCount)) {
        for (int i = 0; i < block.count; i++) {
            printRental(block.rentals[i]);
        }
    }
}
