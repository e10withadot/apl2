#include "lib/common/stdio.h"

// compiler
void parser(char *file) {
    int fd = open(file, READ_ONLY);
    close(fd);
}

void assembler(char *inst) {
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        error("Filename required.");
        return 1;
    }
    return 0;
}
