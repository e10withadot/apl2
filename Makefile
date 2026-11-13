CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Ilib/common -Ilib/linux_amd64 -Ilib/universal

TARGET = apl2

SRC = main.c lib/common/stdio.c lib/linux_amd64/stdio.c lib/universal/types.c

OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP) $(TARGET)
