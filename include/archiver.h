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
#include "miniz.h"

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

/*
 */

typedef struct {
    mz_zip_archive *zip;
    int             compression_level;
} archive_state;

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

/**
 * TODO: Should define own structs here to represent:
 * - ZIP archive state/handle (to track the archive being created)
 * - File entry information (filename, size, compression status)
 *
 * Look at the miniz documentation to understand what you need to track.
 */

/**
 * @brief Create a new ZIP archive
 *
 * @param output_path Path where the ZIP file will be created
 * @param compression_level Compression level (0-9)
 * @return Pointer to archive state, or NULL on failure
 */
archive_state *create_archive(const char *output_path, int compression_level);

/**
 * @brief Add a single file to the archive
 *
 * @param archive Pointer to archive state (from create_archive)
 * @param file_path Path to the file on disk
 * @param archive_name Path/name of file inside the ZIP archive
 * @param verbose Print progress messages if true
 * @return SUCCESS on success, error code on failure
 */
int add_file_to_archive(archive_state *archive, const char *file_path,
                        const char *archive_name, bool verbose);

/**
 * @brief Finalize and close the archive
 *
 * @param archive Pointer to archive state
 * @param verbose Print summary if true
 * @return SUCCESS on success, error code on failure
 */
int finalize_archive(archive_state *archive, bool verbose);

/**
 * @brief Validate that all files in the list exist
 *
 * @param file_list Array of file paths to validate
 * @param file_count Number of files in the list
 * @return SUCCESS if all files exist, error code otherwise
 */
int validate_file_list(char **file_list, int file_count);

/**
 * @brief Create a ZIP archive from a list of files
 *
 * @param file_list Array of file paths to archive
 * @param file_count Number of files to archive
 * @param output_path Path for the output ZIP file
 * @param options Archive options (compression level, verbose, etc.)
 * @return SUCCESS on success, error code on failure
 */
int create_archive_from_file_list(char **file_list, int file_count,
                                  const char             *output_path,
                                  const ArchiveOptions_t *options);

/**
 * @brief free the archive state pointer
 *
 * @param archive pointer to the archive state pointer
 */
void free_archive(archive_state *archive);

#endif // ARCHIVER_H
