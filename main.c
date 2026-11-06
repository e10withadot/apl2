#include <sys/syscall.h>
long syscall(long number, ...);

// file open flags
#define READ_ONLY 0
#define WRITE_ONLY 1
#define READ_WRITE 2

// universal
int len_str(char* s) {
    char c;
    int i = 0;
    do {
        c = s[i++];
    } while(c != '\0');
    return i;
}

// linux amd64
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

// common
void print(char *val) {
    print_linux_amd64(val);
}

void error(char *msg) {
    error_linux_amd64(msg);
}

int open(char *path, int flags) {
    open_linux_amd64(path, flags);
}

void close(int fd) {
    close_linux_amd64(fd);
}

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
