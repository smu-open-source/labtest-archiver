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

#include "../include/archiver.h"
#include "../include/config.h"

int main(int argc, char **argv) {
    ArchiveOptions_t options;
    int              result;

    // Step 1: Parse command line arguments
    result = parse_archive_args(argc, argv, &options);
    if (result != SUCCESS) {
        return result;
    }

    ArchiverFILES files;
    char LT_FILE_path[MAX_PATH_LENGTH];
    strcpy(LT_FILE_path, options.input_path);
    strcat(LT_FILE_path, "/.LT_FILES");
    files.LT_FILES_path = LT_FILE_path;

    char *file_list[MAX_CONFIG_FILES];
    int file_count = 0;
    files.file_list = file_list;
    files.file_count = &file_count;
    // TODO: Step 2: Get config file path from command line
    printf(
        "%s\n", files.LT_FILES_path
    );

    parse_config_file(files.LT_FILES_path, options.input_path, files.file_list, MAX_CONFIG_FILES, files.file_count);
        
    // printf("%i\n", *(files.file_count));
    // for (int i = 0; i < *(files.file_count); i++) {
    //     printf("%s\n", (files.file_list)[i]);
    // }
    // TODO: Step 3: Parse the config file to get file list
    create_archive_from_file_list(files.file_list, 
                                    *(files.file_count), 
                                    options.output_path, 
                                    &options);
    
    
    // TODO: Step 4: Get output path using student ID (prompt them)

    // TODO: Step 5: Create the archive

    // TODO: Step 6: Clean up

    return SUCCESS;
}
