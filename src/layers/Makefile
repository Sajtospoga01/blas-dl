CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -I../../ -I. -MMD -MP

# Output directory
BUILD_DIR = ../../build/layers

# Source files
SRCS = $(wildcard *.cxx)

# Object files
OBJS = $(SRCS:%.cxx=$(BUILD_DIR)/%.o)

# Dependency files
DEPS = $(OBJS:.o=.d)

# Default target
all: $(OBJS)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	@echo "Creating build directory"
	@mkdir -p $(BUILD_DIR)

# Compile source files into object files
$(BUILD_DIR)/%.o: %.cxx | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files
-include $(DEPS)

# Clean up build directory
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.d

.PHONY: all clean