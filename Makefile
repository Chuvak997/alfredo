# Compiler
CXX := g++ 

# Compile options
CXXFLAGS := -std=c++20 -Wall

# Build directory
BUILD_DIR := .

# Source directory
SRC_DIR := .

# Linker flags
LDFLAGS := 

# Linker Libraries
LDLIBS := 

# Target executable name
TARGET := $(BUILD_DIR)/alfredo

# Find all cpp files in the source directory
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)

# Object files have the same names as cpp files, but with .o extension
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(TARGET)

# Link the target with all object files
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJECTS) $(LDLIBS)

# Compile each source file to an object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up target
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)