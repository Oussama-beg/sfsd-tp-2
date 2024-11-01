
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <stdio.h>
#include "customer.h"
#include "game.h"
#include "rental.h"

#define MAX_CUSTOMERS 10
#define MAX_GAMES 10
#define MAX_RENTALS 10

typedef struct {
        int blockCount;

    } header;

typedef struct tof {
    FILE *file;
    header header;
} tof ;

typedef struct {
    int count;
    Customer customers[MAX_CUSTOMERS];
} BlocCustomer;

typedef struct {
    int count;
    Game games[MAX_GAMES];
} BlocGame;

typedef struct {
    int count;
    Rental rentals[MAX_RENTALS];
} BlocRental;

tof *open_file(const char *filename, char mode);
void close_file(tof *tof);
void save_to_file(tof *tof, const char *filename);
void load_from_file(tof *tof, const char *filename);
void insert_Customer(tof *tof, int customerID, Customer customer);
void insert_Game(tof *tof, int gameID, Game game);
void insert_rental(tof *tof, int rentalID, Rental rental);
int read_BlocCustomer(tof *tof, BlocCustomer *bloc, int blockNum);
int read_BlocGame(tof *tof, BlocGame *bloc, int blockNum);
int read_BlocRental(tof *tof, BlocRental *bloc, int blockNum);
void write_BlocCustomer(tof *tof, BlocCustomer *bloc, int blockNum);
void write_BlocGame(tof *tof, BlocGame *bloc, int blockNum);
void write_BlocRental(tof *tof, BlocRental *bloc, int blockNum);

#endif
