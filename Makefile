CC = gcc

LIBDIR= lib/

CFLAGS = -Wall -Wextra -std=c11 -I$(LIBDIR)common -I$(LIBDIR)linux_amd64 -I$(LIBDIR)universal

TARGET = apl2

SRC = main.c $(LIBDIR)common/stdio.c $(LIBDIR)linux_amd64/stdio.c $(LIBDIR)universal/types.c

OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

clean:
	rm -f *.o *.d $(LIBDIR)*/*.d $(LIBDIR)*/*.o $(TARGET)
