
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "file_operations.h"

#define MAX_NAME_LENGTH 50
#define MAX_CONTACT_LENGTH 100

typedef struct {
    int customerID;
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char contactInfo[MAX_CONTACT_LENGTH];
} Customer;

void add_customer(tof *customerFile);
int rechercher_Customer(tof *tof, int customerID, Customer *customer);
void printCustomer(Customer customer);

#endif
