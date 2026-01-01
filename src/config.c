/**
 * @file config.c
 * @brief Implementation of configuration file parsing
 */

#include "config.h"
#include <ctype.h>
#include <dirent.h>
#include <glob.h>
#include <sys/stat.h>

#include <string.h>

int read_config_line(FILE *fp, char *buffer, size_t buffer_size) {
    // TODO: Read a line from the file
    fgets(buffer, buffer_size, fp);
    // TODO: Find the # character and truncate the line there (comments)
    char *hash_loc = strchr(buffer, '#');
    if (hash_loc != NULL) {
        *hash_loc = '\0';
    }
    if (strlen(buffer) == 0) {
        return -1; // ???????
    }
    // TODO: Trim leading and trailing whitespace
    char buffer2[strlen(buffer) + 1];

    char *buffer_ptr = buffer;
    while (isspace(*buffer_ptr)) {
        buffer_ptr++;
    }
    strcpy(buffer2, buffer_ptr);

    buffer_ptr = buffer2 + strlen(buffer2);
    while (buffer_ptr != buffer2
           && (*buffer_ptr == '\0' || isspace(*buffer_ptr))) {
        buffer_ptr--;
    }
    if (*buffer_ptr != '\0') {
        buffer_ptr++;
        *buffer_ptr = '\0';
    }
    strcpy(buffer, buffer2);
    // TODO: Return the length of the cleaned line, or -1 on EOF
    if (feof(fp) == EOF) {
        return -1;
    } else {
        return strlen(buffer);
    }
    //
    // Hints:
    // - Use fgets() to read a line
    // - Use strchr() to find the # character
    // - Use isspace() to check for whitespace characters
    // - Don't forget to handle the case where the line is empty after removing
    // comments

    /*
    (void)fp; // Remove these lines when implementing
    (void)buffer;
    (void)buffer_size;
    return -1;
    */
}

int identify_section(const char *line) {
    // TODO: Check if the line is "required:" or "optional:"
    // TODO: Return 1 for "required:", 2 for "optional:", 0 otherwise
    //
    // Hints:
    // - Use strcmp() to compare strings
    // - Make sure to handle any trailing whitespace

    (void)line; // Remove this line when implementing
    return 0;
}

bool is_indented_line(const char *line) {
    // TODO: Check if the line starts with 2 spaces or a tab
    // TODO: Return true if indented, false otherwise
    //
    // Hints:
    // - Check line[0] and line[1] for spaces
    // - Check line[0] for '\t'

    (void)line; // Remove this line when implementing
    return false;
}

int extract_filename(const char *line, char *filename, size_t filename_size) {
    // TODO: Remove the indentation (skip first 2 spaces or 1 tab)
    // TODO: Copy the remaining text to filename buffer
    // TODO: Remove trailing whitespace from filename
    //
    // Hints:
    // - Use strncpy() or strcpy() to copy strings
    // - Be careful not to overflow the buffer
    // - Check filename_size before copying

    (void)line;
    (void)filename;
    (void)filename_size;
    return ERROR_INVALID_ARGS;
}

bool is_file(const char *path) {
    // TODO: Use stat() to get file information
    // TODO: Check if it's a regular file using S_ISREG() macro
    // TODO: Return true if it's a file, false otherwise
    //
    // Hints:
    // - Include <sys/stat.h>
    // - struct stat st;
    // - stat(path, &st);
    // - S_ISREG(st.st_mode) checks if it's a regular file

    (void)path; // Remove this line when implementing
    return false;
}

bool has_trailing_slash(const char *path) {
    // TODO: Check if the last character of path is '/'
    // TODO: Return true if it has trailing slash, false otherwise
    //
    // Hints:
    // - Use strlen() to get the length
    // - Check path[length-1] == '/'
    // - Handle the case where path is empty

    (void)path; // Remove this line when implementing
    return false;
}

bool validate_required_path(const char *path) {
    // TODO: Check if the path exists (could be file or directory)
    // TODO: Use access() or stat() to check existence
    // TODO: If it doesn't exist, print an error message and return false
    // TODO: If it exists, return true
    //
    // Hints:
    // - access(path, F_OK) returns 0 if path exists
    // - Use fprintf(stderr, ...) to print error messages

    (void)path; // Remove this line when implementing
    return false;
}

int list_directory_files(const char *dir_path, char **file_list, int max_files,
                         int *file_count) {
    // TODO: Open the directory using opendir()
    // TODO: Read each entry using readdir()
    // TODO: For each entry:
    //       - Skip "." and ".."
    //       - Build the full path (dir_path + "/" + entry name)
    //       - If it's a file, add it to file_list using add_file_to_list()
    //       - If it's a directory, recursively call list_directory_files()
    // TODO: Close the directory using closedir()
    //
    // Hints:
    // - Include <dirent.h>
    // - DIR *dir = opendir(dir_path);
    // - struct dirent *entry;
    // - while ((entry = readdir(dir)) != NULL) { ... }
    // - Use stat() to check if entry is a file or directory
    // - Be careful with buffer sizes when building paths

    (void)dir_path;
    (void)file_list;
    (void)max_files;
    (void)file_count;
    return ERROR_IO;
}

int add_file_to_list(char **file_list, int *file_count, int max_files,
                     const char *file_path) {
    // TODO: Check if file_count < max_files (don't overflow the array)
    // TODO: Allocate memory for the file path string using malloc()
    // TODO: Copy the file_path to the allocated memory using strcpy()
    // TODO: Store the pointer in file_list[*file_count]
    // TODO: Increment *file_count
    //
    // Hints:
    // - Use strlen() to get the length of file_path
    // - malloc(strlen(file_path) + 1) to allocate memory (+1 for null
    // terminator)
    // - Check if malloc returns NULL (out of memory)
    // - strcpy(allocated_memory, file_path) to copy the string

    (void)file_list;
    (void)file_count;
    (void)max_files;
    (void)file_path;
    return ERROR_MEMORY_ALLOCATION;
}

bool is_glob_pattern(const char *path) {
    // TODO: Check if the path contains * or ? characters
    // TODO: Return true if it's a glob pattern, false otherwise
    //
    // Hints:
    // - Use strchr() to search for '*' or '?' in the string
    // - if (strchr(path, '*') != NULL || strchr(path, '?') != NULL)

    (void)path; // Remove this line when implementing
    return false;
}

int expand_glob_pattern(const char *pattern, char **file_list, int max_files,
                        int *file_count) {
    // TODO: Use glob() function to expand the pattern
    // TODO: For each matching file:
    //       - Add it to file_list using add_file_to_list()
    // TODO: Free the glob results using globfree()
    //
    // Hints:
    // - Include <glob.h>
    // - glob_t results;
    // - glob(pattern, 0, NULL, &results);
    // - results.gl_pathc is the number of matches
    // - results.gl_pathv is an array of matched paths
    // - for (size_t i = 0; i < results.gl_pathc; i++) { ... }
    // - Don't forget to call globfree(&results) when done
    // - For optional files, no matches is OK (return SUCCESS)

    (void)pattern;
    (void)file_list;
    (void)max_files;
    (void)file_count;
    return SUCCESS;
}

int parse_config_file(const char *config_path, char **file_list, int max_files,
                      int *file_count) {
    // TODO: Open the config file using fopen()
    // TODO: Initialize current_section to track if we're in required/optional
    // TODO: Read the file line by line using read_config_line()
    // TODO: For each line:
    //       - Check if it's a section header using identify_section()
    //       - If it's a section header, update current_section
    //       - If it's an indented line:
    //         * Extract the filename using extract_filename()
    //         * If in required section:
    //           - Validate the path exists using validate_required_path()
    //           - If it fails validation, return error
    //           - If it's a directory, use list_directory_files()
    //           - If it's a file, use add_file_to_list()
    //         * If in optional section:
    //           - Check if it's a glob pattern using is_glob_pattern()
    //           - If glob, use expand_glob_pattern()
    //           - If not glob and exists, add to list
    //           - If doesn't exist, skip (no error)
    // TODO: Close the file using fclose()
    // TODO: Return SUCCESS if everything worked
    //
    // This is the main function that coordinates all the other functions!
    //
    // Hints:
    // - FILE *fp = fopen(config_path, "r");
    // - Use a char buffer[MAX_PATH_LENGTH] for reading lines
    // - Keep track of which section you're in (0=none, 1=required, 2=optional)
    // - Handle errors at each step and clean up properly
    // - Print helpful error messages when things go wrong

    (void)config_path;
    (void)file_list;
    (void)max_files;
    (void)file_count;
    return ERROR_FILE_NOT_FOUND;
}

void free_file_list(char **file_list, int file_count) {
    // TODO: Loop through the file_list array
    // TODO: Free each string using free()
    // TODO: Set each pointer to NULL after freeing (good practice)
    //
    // Hints:
    // - for (int i = 0; i < file_count; i++) { ... }
    // - free(file_list[i]);
    // - file_list[i] = NULL;

    (void)file_list;
    (void)file_count;
}
