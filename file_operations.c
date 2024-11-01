
#include "file_operations.h"
#include <stdlib.h>
#include <string.h>

tof *open_file(const char *filename, char mode) {
    tof *tof = (tof *)malloc(sizeof(tof));
    tof->file = fopen(filename, (mode == 'N' || mode == 'n') ? "wb+" : "rb+");
    if (!tof->file) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }

    // Initialize header, but don't read or write unless load/save is called
    tof->header.blockCount = 0;
    tof->header.recordCount = 0;

    return tof;
}

void close_file(tof *tof) {
    if (tof->file) {
        fclose(tof->file);
    }
    free(tof);
}

void save_to_file(tof *tof, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error saving to file");
        return;
    }

    fwrite(&tof->header, sizeof(tof->header), 1, file);

    // Save customers
    for (int i = 0; i < tof->header.blockCount; i++) {
        BlocCustomer customerBlock;
        if (read_BlocCustomer(tof, &customerBlock, i)) {
            fwrite(&customerBlock, sizeof(BlocCustomer), 1, file);
        }
    }

    fclose(file);
}

void load_from_file(tof *tof, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error loading from file");
        return;
    }

    fread(&tof->header, sizeof(tof->header), 1, file);

    // Load customers
    for (int i = 0; i < tof->header.blockCount; i++) {
        BlocCustomer customerBlock;
        fread(&customerBlock, sizeof(BlocCustomer), 1, file);
        write_BlocCustomer(tof, &customerBlock, i);
    }

    fclose(file);
}

// Other functions to manage customer, game, and rental blocks..
