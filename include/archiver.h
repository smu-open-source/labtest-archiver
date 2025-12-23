/**
 * @file archiver.h
 * @brief Archive functionality for compressing student submissions
 *
 * This module provides functionality to archive student lab test submissions
 * into compressed packages using the miniz library.
 */

#ifndef ARCHIVER_H
#define ARCHIVER_H

#include "common.h"

/* Archive configuration */
#define DEFAULT_COMPRESSION_LEVEL 6
#define MAX_COMPRESSION_LEVEL     9

/**
 * @brief Archive options structure
 */
typedef struct {
    int  compression_level; /* Compression level (0-9) */
    bool verbose;           /* Verbose output */
    // TODO: Think about what options might be needed for archiving
} ArchiveOptions_t;

/**
 * @brief Initialize archive options with defaults
 * @param options Pointer to options structure
 */
void init_archive_options(ArchiveOptions_t *options);

/**
 * @brief Print usage information for archiver
 */
void print_archiver_usage(void);

/**
 * @brief Parse command line arguments for archiver
 * @param argc Argument count
 * @param argv Argument vector
 * @param options Pointer to options structure to populate
 * @return SUCCESS on success, error code on failure
 */
int parse_archive_args(int argc, char **argv, ArchiveOptions_t *options);

#endif // ARCHIVER_H
