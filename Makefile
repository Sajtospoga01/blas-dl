# Root Makefile

# Default target
all: src/blaslearn

# Call the Makefile in the src directory
src/blaslearn:
	$(MAKE) -C src

# Clean up all build directories
clean:
	$(MAKE) -C src clean

.PHONY: all clean