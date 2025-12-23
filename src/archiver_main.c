/**
 * @file archiver_main.c
 * @brief Main entry point for the labtest-archiver binary
 *
 * This program archives student lab test submissions into compressed packages.
 */

#include "archiver.h"

int main(int argc, char **argv) {
    ArchiveOptions_t options;
    int              result;

    // Parse command line arguments
    result = parse_archive_args(argc, argv, &options);
    if (result != SUCCESS) {
        return result;
    }

    // TODO: Implement archiving logic here

    return SUCCESS;
}
