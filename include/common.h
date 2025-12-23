/**
 * @file common.h
 * @brief Common definitions and utilities used across the project
 *
 * This header contains common constants, types, and utility functions
 * that are shared between the archiver and grader components.
 */

#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Version information */
#define VERSION_MAJOR 0
#define VERSION_MINOR 1
#define VERSION_PATCH 0

/* Common constants */
#define MAX_PATH_LENGTH     4096
#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE         8192

/* Error codes */
#define SUCCESS                 0
#define ERROR_INVALID_ARGS      -1
#define ERROR_FILE_NOT_FOUND    -2
#define ERROR_MEMORY_ALLOCATION -3
#define ERROR_COMPRESSION       -4
#define ERROR_IO                -5

/**
 * @brief Print version information
 */
void print_version(void);

/**
 * @brief Print error message to stderr
 * @param message Error message to print
 */
void print_error(const char *message);

/**
 * @brief Check if a file exists
 * @param filepath Path to the file
 * @return true if file exists, false otherwise
 */
bool file_exists(const char *filepath);

/**
 * @brief Check if a path is a directory
 * @param path Path to check
 * @return true if path is a directory, false otherwise
 */
bool is_directory(const char *path);

/**
 * @brief Get file size in bytes
 * @param filepath Path to the file
 * @return File size in bytes, or -1 on error
 */
long get_file_size(const char *filepath);

/**
 * @brief Allocate memory with error checking
 * @param size Size in bytes to allocate
 * @return Pointer to allocated memory, or NULL on failure
 */
void *safe_malloc(size_t size);

#endif // COMMON_H
