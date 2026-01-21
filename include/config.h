/**
 * @file config.h
 * @brief Configuration file parsing for .LT_FILES
 *
 * This module handles parsing of .LT_FILES configuration files that specify
 * which files should be included in the archive.
 *
 * Config file format:
 * - Lines starting with # are comments
 * - required: section lists files that MUST exist
 * - optional: section lists files to include if they exist
 * - Files are indented with 2 spaces or tab
 * - Directories can have trailing / to indicate they're directories
 * - Optional section supports glob patterns (e.g., *.txt)
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "common.h"

/* Maximum number of files that can be specified in config */
#define MAX_CONFIG_FILES 1000

/**
 * TODO: Define own structs here to represent:
 * - A config file entry (filename, whether it's required, etc.)
 * - A parsed config file (lists of required and optional files)
 * - A file list result (array of file paths to archive)
 *
 * Think about what data you need to store for each section of the config.
 */
typedef struct {
    char ** include_single;
    char ** include_all;
} required_files;

/**
 * @brief Read a line from the config file and strip comments
 *
 * @param fp File pointer to read from
 * @param buffer Buffer to store the line
 * @param buffer_size Size of the buffer
 * @return Number of characters read, or -1 on EOF
 */
int read_config_line(FILE *fp, char *buffer, size_t buffer_size);

/**
 * @brief Check if a line is a section header (required: or optional:)
 *
 * @param line The line to check
 * @return 1 for required, 2 for optional, 0 otherwise
 */
int identify_section(const char *line);

/**
 * @brief Check if a line is indented (part of a section)
 *
 * @param line The line to check
 * @return true if indented, false otherwise
 */
bool is_indented_line(const char *line);

/**
 * @brief Extract the filename from an indented line
 *
 * @param line The indented line
 * @param filename Buffer to store the extracted filename
 * @param filename_size Size of the filename buffer
 * @return SUCCESS on success, error code on failure
 */
int extract_filename(const char *line, char *filename, size_t filename_size);

/**
 * @brief Check if a path points to a file that exists
 *
 * @param path Path to check
 * @return true if file exists, false otherwise
 */
bool is_file(const char *path);

/**
 * @brief Check if a path has a trailing slash
 *
 * @param path Path to check
 * @return true if has trailing slash, false otherwise
 */
bool has_trailing_slash(const char *path);

/**
 * @brief Validate that a required file exists
 *
 * @param path Path to validate
 * @return true if exists, false otherwise
 */
bool validate_required_path(const char *path);

/**
 * @brief List all files in a directory recursively
 *
 * @param dir_path Directory path to traverse
 * @param file_list Array to store found file paths (output)
 * @param max_files Maximum number of files that can be stored
 * @param file_count Current count of files in the list (input/output)
 * @return SUCCESS on success, error code on failure
 */
int list_directory_files(const char *dir_path, char **file_list, int max_files,
                         int *file_count);

/**
 * @brief Add a single file path to the file list
 *
 * @param file_list Array to store file paths
 * @param file_count Current count of files (input/output)
 * @param max_files Maximum number of files
 * @param file_path File path to add
 * @return SUCCESS on success, error code on failure
 */
int add_file_to_list(char **file_list, int *file_count, int max_files,
                     const char *file_path);

/**
 * @brief Check if a path contains a glob pattern (*, ?, etc.)
 *
 * @param path Path to check
 * @return true if contains glob pattern, false otherwise
 */
bool is_glob_pattern(const char *path);

/**
 * @brief Expand a glob pattern and add matching files to the list
 *
 * @param pattern Glob pattern (e.g., "*.txt")
 * @param file_list Array to store matching file paths
 * @param max_files Maximum number of files
 * @param file_count Current count of files (input/output)
 * @return SUCCESS on success, error code on failure
 */
int expand_glob_pattern(const char *pattern, char **file_list, int max_files,
                        int *file_count);

/**
 * @brief Parse a .LT_FILES configuration file
 *
 * @param config_path Path to the .LT_FILES config file
 * @param file_list Array to store file paths to archive (output)
 * @param max_files Maximum number of files
 * @param file_count Number of files found (output)
 * @return SUCCESS on success, error code on failure
 */
int parse_config_file(const char *config_path, const char *base_dir, char **file_list, int max_files,
                      int *file_count);

/**
 * @brief Free memory allocated for the file list
 *
 * @param file_list Array of file paths to free
 * @param file_count Number of files in the list
 */
void free_file_list(char **file_list, int file_count);

#endif // CONFIG_H
