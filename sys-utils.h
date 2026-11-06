void return_png_paths(char* path);
char is_file_extension(char* filepath, char* extension);

struct String {
    char length;
    char* contents;
};

struct StringList {
    int length;
    struct String string;
};