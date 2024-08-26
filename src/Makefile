# src/Makefile

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -I../ -I. -I./layers -MMD -MP

# Linker flags
LDFLAGS = -lopenblas

# Output directory
BUILD_DIR = ../build

# Executable name
TARGET = $(BUILD_DIR)/blaslearn

# Source files
SRCS = $(wildcard *.cxx)

# Object files
OBJS = $(SRCS:%.cxx=$(BUILD_DIR)/%.o)

# Layer source files
LAYER_SRCS = $(wildcard layers/*.cxx)

# Layer object files
LAYER_OBJS = $(LAYER_SRCS:layers/%.cxx=$(BUILD_DIR)/layers/%.o)

# Dependency files
DEPS = $(OBJS:.o=.d) $(LAYER_OBJS:.o=.d)

# Default target
all: $(TARGET)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/layers

# Build target
$(TARGET): $(BUILD_DIR) $(OBJS) $(LAYER_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LAYER_OBJS) $(LDFLAGS)

# Compile source files into object files
$(BUILD_DIR)/%.o: %.cxx | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile layer source files into object files
$(BUILD_DIR)/layers/%.o: layers/%.cxx | $(BUILD_DIR)/layers
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files
-include $(DEPS)

# Clean up build directory
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.d $(TARGET)
	rm -rf $(BUILD_DIR)/layers/*.o $(BUILD_DIR)/layers/*.d

.PHONY: all clean