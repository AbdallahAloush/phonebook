CC = gcc
CFLAGS = -Wall -Wextra -std=c17
SRCDIR = src
BINDIR = bin

# List of source files
SOURCES = $(wildcard $(SRCDIR)/*.c)
# List of object files to be created
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SOURCES))

# The final executable
EXECUTABLE = main

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to build object files
$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BINDIR)/*.o $(EXECUTABLE)
