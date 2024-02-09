CC = clang
CFLAGS = -Wall -Wextra -std=c99
SRCDIR = src
BINDIR = bin

# List of source files
SOURCES = $(wildcard $(SRCDIR)/*.c)
# List of object files to be created
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SOURCES))

# The final executable
EXECUTABLE = main

.PHONY: all clean create_bin_dir

all: create_bin_dir $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to build object files
$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Target to create the bin directory if it does not exist
create_bin_dir:
	@mkdir -p $(BINDIR)

clean:
	rm -f $(BINDIR)/*.o $(EXECUTABLE)
