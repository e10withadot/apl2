// file open flags
#define READ_ONLY 0
#define WRITE_ONLY 1
#define READ_WRITE 2

// common
void print(char *val);

void error(char *msg);

int open(char *path, int flags);

void close(int fd);
