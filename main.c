#include "sys-utils.h"
#include <dirent.h>
#include <png.h>
#include <stdio.h>
#include <string.h>
#define PHOTO_COUNT 3954 + 4
#define ENTRY_DIR "../data/collective"

/*
// I'll just include string.h
// however, here's my implementation of strcmp
// (just for reference only)
int strcmp(char* a, char* b)
{
    char return_val = 0;
    int i = 0;
    while (a[i] && b[i] && !return_val)
        return_val = b[i] - a[i++];
    // if it reaches here then it has found a
    // first difference in the string (or ended)
    return return_val;
}
*/

int main(void)
{
    return_png_paths(ENTRY_DIR);
    printf("%d", is_file_extension("asdf//../././../something.png", ".png"));
    return 0;
}