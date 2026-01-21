/**
 * @file archiver.c
 * @brief Implementation of archive functionality
 */

#include "archiver.h"
#include "../lib/miniz/miniz.h"
#include <getopt.h>
#include <unistd.h>
#include <sys/stat.h>

void init_archive_options(ArchiveOptions_t *options) {
    // Implement this function to initialize archive options
    // with default values
    //
    // Hints:
    // - Set compression_level to DEFAULT_COMPRESSION_LEVEL
    // - Set verbose to false
    // - Initialize any other fields you added to the struct

    options -> compression_level = DEFAULT_COMPRESSION_LEVEL;
    options -> verbose = false;
    options -> input_path = NULL;
    options -> output_path = NULL;
}

void print_archiver_usage(void) {
    printf("Usage: labtest-archiver [OPTIONS]\n\n");
    printf(
        "Archive student lab test submissions into compressed packages.\n\n");
    printf("Options:\n");
    printf("  -l, --level LEVEL      Compression level 0-9 (default: %d)\n",
           DEFAULT_COMPRESSION_LEVEL);
    printf("  -v, --verbose          Enable verbose output\n");
    printf("  -i, --input            Path to input file directories\n");
    printf("  -o, --output           Path to output ZIP file\n");
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
                                           {"input", required_argument, 0, 'i'},
                                           {"output", required_argument, 0, '0'},
                                           {"help", no_argument, 0, 'h'},
                                           {"version", no_argument, 0, 'V'},
                                           {0, 0, 0, 0}};

    int opt;
    int option_index = 0;

    while ((opt = getopt_long(argc, argv, "l:i:o:vhV", long_options, &option_index))
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
            case 'i':
                options->input_path = optarg;
                break;
            case 'o':
                options->output_path = optarg;
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

    if (options->output_path == NULL || options->input_path == NULL) {
        printf("Both -i <input> and -o <output> must be specified\n");
        return ERROR_INVALID_ARGS;
    }

    return SUCCESS;
}

archive_state *create_archive(const char *output_path, int compression_level) {
    // Create a new ZIP archive using miniz
    mz_zip_archive *zip = malloc(sizeof(mz_zip_archive));
    memset(zip, 0, sizeof(mz_zip_archive));
    
    // Allocate memory for an archive state structure
    // Initialize the miniz ZIP writer
    if (!mz_zip_writer_init_file(zip, output_path, 0)) {
        free(zip);
        return NULL;
    }

    archive_state *archive = malloc(sizeof(archive_state));
    archive -> zip = zip;
    // Store the compression level
    archive -> compression_level = compression_level;
    // Return the archive state pointer
    return archive;
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
}

int add_file_to_archive(archive_state *archive, const char *file_path,
                        const char *archive_name, bool verbose) {
    
    // Add a file to the ZIP archive
    // Read the file from disk
    // Compress it and add to the archive
    int archive_err_state = mz_zip_writer_add_file(archive -> zip, 
                        archive_name, 
                        file_path, 
                        NULL, 
                        0, 
                        archive -> compression_level);

    // Error handling
    if (!archive_err_state) {
        if (verbose) {
            printf("Error adding: %s\n", file_path);
        }
        return ERROR_COMPRESSION;
    }

    // Print progress if verbose is true
    if (verbose) {
        printf("Adding: %s\n", file_path);
    }
    //
    // Hints:
    // - Cast archive back to your archive state struct
    // - Use mz_zip_writer_add_file() from miniz
    // - Parameters: zip, archive_name, file_path, NULL, 0, compression_level
    // - Check the return value - false means error
    // - Print: "Adding: %s\n" if verbose
    // - Handle errors gracefully

    return SUCCESS;
}

int finalize_archive(archive_state *archive, bool verbose) {
    // Finalize the ZIP archive
    // Close the file
    mz_zip_writer_finalize_archive(archive -> zip);
    mz_zip_writer_end(archive -> zip);
    // Free allocated memory
    free_archive(archive);
    // Print summary if verbose
    if (verbose) {
        printf("Files zipped successfully\n");
    }
    //
    // Hints:
    // - Call mz_zip_writer_finalize_archive() to finish writing
    // - Call mz_zip_writer_end() to clean up miniz resources
    // - Free your archive state structure
    // - If verbose, print something like: "Archive created successfully\n"

    return SUCCESS;
}

int validate_file_list(char **file_list, int file_count) {
    // Check that all files in the list exist
    bool file_missing = false;
    for (int i = 0; i < file_count; i++) {
        char * file = file_list[i];
        struct stat st;
        if (stat(file, &st) != 0) {
            // Print error messages for missing files
            printf("Missing file; %s\n", file);
            file_missing = true;
        }
    }

    // Return error if any files are missing
    if (file_missing) {
        return ERROR_FILE_NOT_FOUND;
    }

    return SUCCESS;
    //
    // Hints:
    // - Loop through file_list from 0 to file_count
    // - Use file_exists() from common.h to check each file
    // - Print error: "Error: File not found: %s\n" for missing files
    // - Return ERROR_FILE_NOT_FOUND if any file is missing
    // - Return SUCCESS if all files exist
}

int create_archive_from_file_list(char **file_list, int file_count,
                                  const char             *output_path,
                                  const ArchiveOptions_t *options) {
    // This is the main function that creates a ZIP from a file list
    // Steps:
    //       1. Validate all files exist using validate_file_list()
    int status; // status variable storing return values
    status = validate_file_list(file_list, file_count);
    if (status != SUCCESS) return status;

    //       2. Create the archive using create_archive()
    archive_state * archive = create_archive(output_path, options -> compression_level);
    if (archive == NULL) {
        free_archive(archive);
        return ERROR_IO;
    }
    //       3. Loop through each file and add it using add_file_to_archive()
    for (int i = 0; i < file_count; i++) {
        status = add_file_to_archive(archive, file_list[i], output_path, options -> verbose);
        if (status != SUCCESS) {
            free_archive(archive);
            return status;
        }
    }
    //       4. Finalize the archive using finalize_archive()
    finalize_archive(archive, options -> verbose);

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

    return SUCCESS;
}

void free_archive(archive_state * archive) {
    free(archive -> zip);
    free(archive);
}
