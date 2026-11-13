#include <sys/syscall.h>
#include "../universal/types.h"

long syscall(long number, ...);

void error_linux_amd64(char *msg) {
    syscall(SYS_write, 2, msg, len_str(msg));
    syscall(SYS_exit, 1);
}

void print_linux_amd64(char *val) {
    if (syscall(SYS_write, 1, val, len_str(val)) < 0)
        error_linux_amd64("print_linux_amd64: Failed to write to stdout.");
}

int open_linux_amd64(char *path, int flags) {
    int fd = syscall(SYS_open, path, flags);
    if (fd < 0) error_linux_amd64("open_linux_amd64: Failed to open file.");
    return fd;
}

char* read_linux_amd64(int fd) {
    char *out;
    int ind = syscall(SYS_read, fd, out, 1);
    while(ind > 0) {
    }
}

void close_linux_amd64(int fd) {
    if (syscall(SYS_close, fd) == -1) error_linux_amd64("close_linux_amd64: Failed to close file.");
}

