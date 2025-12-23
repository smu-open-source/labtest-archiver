/**
 * @file archiver_main.c
 * @brief Main entry point for the labtest-archiver binary
 *
 * This program archives student lab test submissions into compressed packages.
 *
 * Overall flow:
 * 1. Parse command line arguments (get config file path, output path, options)
 * 2. Parse .LT_FILES config file to get list of files to archive
 * 3. Validate that all required files exist
 * 4. Create ZIP archive with those files
 */

#include "archiver.h"
#include "config.h"

int main(int argc, char **argv) {
    ArchiveOptions_t options;
    int              result;

    // Step 1: Parse command line arguments
    result = parse_archive_args(argc, argv, &options);
    if (result != SUCCESS) {
        return result;
    }

    // TODO: Step 2: Get config file path from command line

    // TODO: Step 3: Parse the config file to get file list

    // TODO: Step 4: Get output path using student ID (prompt them)

    // TODO: Step 5: Create the archive

    // TODO: Step 6: Clean up

    return SUCCESS;
}
