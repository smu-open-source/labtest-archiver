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
