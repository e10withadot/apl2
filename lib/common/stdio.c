#include "../linux_amd64/stdio.h"

void print(char *val) { print_linux_amd64(val); }

void error(char *msg) { error_linux_amd64(msg); }

int open(char *path, int flags) { open_linux_amd64(path, flags); }

void close(int fd) { close_linux_amd64(fd); }

