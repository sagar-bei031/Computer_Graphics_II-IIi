# Target
TARGET = mydrawing

# Directories
BUILD_DIR = Build
INC_DIR = Inc
SRC_DIR = Src

# Source files
C_SOURCES := $(wildcard $(SRC_DIR)/*.c)
C_OBJS := $(C_SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CXX_SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
CXX_OBJS := $(CXX_SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Compiler and flags
CC = gcc
CXX = g++

# Flags
OPT = -O2
CFLAGS = -Wall -I$(INC_DIR) -MMD -MP $(OPT)
CXXFLAGS = -Wall -I$(INC_DIR) -MMD -MP $(OPT)
LDFLAGS = -lSDL2 -lm

# Create Build directory if it doesn't exist
$(shell mkdir -p $(BUILD_DIR))

# Rule for compiling C source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for compiling C++ source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule for linking object files
$(BUILD_DIR)/$(TARGET): $(C_OBJS) $(CXX_OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Ensure that 'all' or '$(TARGET)' is the default target
all: $(TARGET)

# Rule for cleaning up
clean:
	-rm -fR $(BUILD_DIR)

run:
	./$(BUILD_DIR)/$(TARGET)

.PHONY: all clean run
