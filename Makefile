# Compiler 
CC = cc
# Compiler flags
CFLAGS = -Wall -g

# Source files
SRCS = algorithm_comparison.c levenshtein_distance.c
# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)
# Link with external libraries
LIBS =    

# Default target
all: match

# Rule to build the final executable
match: $(OBJS)
	$(CC) $(CFLAGS) -o match $(OBJS) $(LIBS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f match $(OBJS)

# Phony targets
.PHONY: all clean