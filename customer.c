
#include "customer.h"
#include <stdio.h>

void add_customer(tof *customerFile) {
    Customer customer;
    printf("Enter Customer ID: ");
    scanf("%d", &customer.customerID);
    printf("Enter First Name: ");
    scanf("%s", customer.firstName);
    printf("Enter Last Name: ");
    scanf("%s", customer.lastName);
    printf("Enter Contact Info: ");
    scanf("%s", customer.contactInfo);
    insert_Customer(customerFile, customer.customerID, customer);
}

int rechercher_Customer(tof *tof, int customerID, Customer *customer) {
    BlocCustomer block;
    fseek(tof->file, sizeof(Entete), SEEK_SET);

    while (read_BlocCustomer(tof, &block, tof->header.blockCount)) {
        for (int i = 0; i < block.count; i++) {
            if (block.customers[i].customerID == customerID) {
                *customer = block.customers[i];
                return 1;
            }
        }
    }
    return 0;
}

void printCustomer(Customer customer) {
    printf("Customer ID: %d\n", customer.customerID);
    printf("Name: %s %s\n", customer.firstName, customer.lastName);
    printf("Contact Info: %s\n", customer.contactInfo);
}
