/**
 * @file common.c
 * @brief Implementation of common utility functions
 */

#include "common.h"
#include <errno.h>
#include <sys/stat.h>

void print_version(void) {
    printf("LabTest Archiver & Grader v%d.%d.%d\n", VERSION_MAJOR,
           VERSION_MINOR, VERSION_PATCH);
    printf("An educational open source project by SMU Open Source Club\n");
}

void print_error(const char *message) {
    if (message != NULL) {
        fprintf(stderr, "Error: %s\n", message);
    }
}

bool file_exists(const char *filepath) {
    if (filepath == NULL) {
        return false;
    }

    struct stat st;
    return (stat(filepath, &st) == 0);
}

bool is_directory(const char *path) {
    if (path == NULL) {
        return false;
    }

    struct stat st;
    if (stat(path, &st) != 0) {
        return false;
    }

    return S_ISDIR(st.st_mode);
}

long get_file_size(const char *filepath) {
    if (filepath == NULL) {
        return -1;
    }

    struct stat st;
    if (stat(filepath, &st) != 0) {
        return -1;
    }

    return (long)st.st_size;
}

void *safe_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        print_error("Memory allocation failed");
        return NULL;
    }
    return ptr;
}
