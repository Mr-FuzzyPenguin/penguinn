#include "sys-utils.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>

// Ill use strcmp from string.h but here's my implementation
// char strcmp(char* a, char* b)
// {
//     char return_val = 0;
//     int i = 0;
//     while (a[i] && b[i] && !return_val) {
//         return_val += a[i] - b[i];
//         i++;
//     }
//     // if it reaches here then it has reached the end of a string
//     return return_val;
// }

// this merely looks at the file extension.
// *** IT DOES NOT look at the magic bytes. ***
// *** IT DOES NOT verify the inside using libpng ***

char is_file(char* path)
{
    return !opendir(path);
}

char is_file_extension(char* filepath, char* extension)
{
    int filepath_idx = 0;
    int extension_idx = 0;
    // while string is not ended
    while (filepath[filepath_idx]) {
        extension_idx = (filepath[filepath_idx++] == extension[extension_idx]) ? extension_idx + 1 : 0;
    }

    // check if reached end of string and extension is also 0
    if (filepath[filepath_idx] == 0 && extension[extension_idx] == 0)
        return 1;
    else
        return 0;
}

// TODO: Learn how the flip to use libpng
void return_png_paths(char* path)
{
    // opendir() returns a pointer of DIR type.
    DIR* dr = opendir(path);

    // Directory entry iterator
    struct dirent* dir_iterator = readdir(dr);

    // opendir returns NULL if couldn't open directory
    if (dr == NULL) {
        return;
    }

    // while still some files in the directory pointer
    while (dir_iterator != NULL) {
        // create a buffer of size 35 (which is decently large enough)
        char full_relative_path[35] = "\0";
        char extension[5] = "\0";

        snprintf(full_relative_path, 35, "%s/%s", path, dir_iterator->d_name);

        // acquire the file extension from the relative path
        sscanf(full_relative_path, "../%*[^.].%s", extension);

        // test if a file or not and it is a PNG
        if (is_file(full_relative_path) && !strcmp(extension, "png")) {
            puts(full_relative_path);
        }

        // read next directory entry
        dir_iterator = readdir(dr);
    }
}