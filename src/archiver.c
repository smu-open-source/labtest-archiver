/**
 * @file archiver.c
 * @brief Implementation of archive functionality
 */

#include "archiver.h"
#include <getopt.h>
#include <unistd.h>

void init_archive_options(ArchiveOptions_t *options) {
    // TODO: Implement this function to initialize archive options
    // with default values
    //
    // Hints:
    // - Set compression_level to DEFAULT_COMPRESSION_LEVEL
    // - Set verbose to false
    // - Initialize any other fields you added to the struct

    (void)options; // Remove this line when implementing
}

void print_archiver_usage(void) {
    printf("Usage: labtest-archiver [OPTIONS]\n\n");
    printf(
        "Archive student lab test submissions into compressed packages.\n\n");
    printf("Options:\n");
    printf("  -l, --level LEVEL      Compression level 0-9 (default: %d)\n",
           DEFAULT_COMPRESSION_LEVEL);
    printf("  -v, --verbose          Enable verbose output\n");
    printf("  -h, --help             Display this help message\n");
    printf("  -V, --version          Display version information\n\n");
}

int parse_archive_args(int argc, char **argv, ArchiveOptions_t *options) {
    if (options == NULL) {
        return ERROR_INVALID_ARGS;
    }

    init_archive_options(options);

    static struct option long_options[] = {{"level", required_argument, 0, 'l'},
                                           {"verbose", no_argument, 0, 'v'},
                                           {"help", no_argument, 0, 'h'},
                                           {"version", no_argument, 0, 'V'},
                                           {0, 0, 0, 0}};

    int opt;
    int option_index = 0;

    while ((opt = getopt_long(argc, argv, "l:vhV", long_options, &option_index))
           != -1) {
        switch (opt) {
            case 'l':
                options->compression_level = atoi(optarg);
                if (options->compression_level < 0
                    || options->compression_level > MAX_COMPRESSION_LEVEL) {
                    fprintf(stderr, "Invalid compression level. Must be 0-%d\n",
                            MAX_COMPRESSION_LEVEL);
                    return ERROR_INVALID_ARGS;
                }
                break;
            case 'v':
                options->verbose = true;
                break;
            case 'h':
                print_archiver_usage();
                exit(SUCCESS);
            case 'V':
                print_version();
                exit(SUCCESS);
            default:
                print_archiver_usage();
                return ERROR_INVALID_ARGS;
        }
    }

    return SUCCESS;
}

void *create_archive(const char *output_path, int compression_level) {
    // TODO: Create a new ZIP archive using miniz
    // TODO: Allocate memory for an archive state structure
    // TODO: Initialize the miniz ZIP writer
    // TODO: Store the compression level
    // TODO: Return the archive state pointer
    //
    // Hints:
    // - Include "miniz.h" at the top of this file
    // - Define a struct to hold: mz_zip_archive zip, compression_level, etc.
    // - Use mz_zip_writer_init_file() to create the ZIP
    // - Check for errors and return NULL if something fails
    // - Example:
    //   mz_zip_archive *zip = malloc(sizeof(mz_zip_archive));
    //   memset(zip, 0, sizeof(mz_zip_archive));
    //   if (!mz_zip_writer_init_file(zip, output_path, 0)) {
    //       free(zip);
    //       return NULL;
    //   }

    (void)output_path;
    (void)compression_level;
    return NULL;
}

int add_file_to_archive(void *archive, const char *file_path,
                        const char *archive_name, bool verbose) {
    // TODO: Add a file to the ZIP archive
    // TODO: Read the file from disk
    // TODO: Compress it and add to the archive
    // TODO: Print progress if verbose is true
    //
    // Hints:
    // - Cast archive back to your archive state struct
    // - Use mz_zip_writer_add_file() from miniz
    // - Parameters: zip, archive_name, file_path, NULL, 0, compression_level
    // - Check the return value - false means error
    // - Print: "Adding: %s\n" if verbose
    // - Handle errors gracefully

    (void)archive;
    (void)file_path;
    (void)archive_name;
    (void)verbose;
    return ERROR_COMPRESSION;
}

int finalize_archive(void *archive, bool verbose) {
    // TODO: Finalize the ZIP archive
    // TODO: Close the file
    // TODO: Free allocated memory
    // TODO: Print summary if verbose
    //
    // Hints:
    // - Call mz_zip_writer_finalize_archive() to finish writing
    // - Call mz_zip_writer_end() to clean up miniz resources
    // - Free your archive state structure
    // - If verbose, print something like: "Archive created successfully\n"

    (void)archive;
    (void)verbose;
    return ERROR_COMPRESSION;
}

int validate_file_list(char **file_list, int file_count) {
    // TODO: Check that all files in the list exist
    // TODO: Print error messages for missing files
    // TODO: Return error if any files are missing
    //
    // Hints:
    // - Loop through file_list from 0 to file_count
    // - Use file_exists() from common.h to check each file
    // - Print error: "Error: File not found: %s\n" for missing files
    // - Return ERROR_FILE_NOT_FOUND if any file is missing
    // - Return SUCCESS if all files exist

    (void)file_list;
    (void)file_count;
    return ERROR_FILE_NOT_FOUND;
}

int create_archive_from_file_list(char **file_list, int file_count,
                                  const char             *output_path,
                                  const ArchiveOptions_t *options) {
    // TODO: This is the main function that creates a ZIP from a file list
    // TODO: Steps:
    //       1. Validate all files exist using validate_file_list()
    //       2. Create the archive using create_archive()
    //       3. Loop through each file and add it using add_file_to_archive()
    //       4. Finalize the archive using finalize_archive()
    //       5. Handle errors at each step
    //
    // Hints:
    // - Check options->verbose to pass verbose flag to functions
    // - For archive_name, you can use the same as file_path (keeps directory
    // structure)
    // - Or strip the path to flatten the archive (your choice!)
    // - Don't forget to check return values and handle errors
    // - If any step fails, clean up and return the error code
    //
    // Example flow:
    //   if (validate_file_list(...) != SUCCESS) return error;
    //   void *archive = create_archive(...);
    //   if (!archive) return error;
    //   for each file:
    //       if (add_file_to_archive(...) != SUCCESS) {
    //           finalize_archive(...);
    //           return error;
    //       }
    //   return finalize_archive(...);

    (void)file_list;
    (void)file_count;
    (void)output_path;
    (void)options;
    return ERROR_COMPRESSION;
}
