# Tested on linux only (STM32CubeMX style)

# Target
TARGET = lab

# Debug?
DEBUG = 1

# Optimization
OPT = -O2

# Directories
BUILD_DIR = build

# C Sources
C_SOURCES =

# CXX Sources
CXX_SOURCES = \
src/DDA.cpp \
src/BLA.cpp \
src/MCA.cpp \
src/MEA.cpp \
src/vector2.cpp  \
src/rectangle.cpp \
src/LineClipper.cpp \
lab.cpp

# C Includes
C_INC = \
-Iinc

# CXX Includes
CXX_INC = \
-Iinc

# defines
DEFS =

# Compiler
CC = gcc
CXX = g++

# Compile Flags
CFLAGS = $(C_INC) $(DEFS) $(OPT) -Wall -fdata-sections -ffunction-sections
CXXFLAGS = $(CXX_INC) $(DEFS) $(OPT) -Wall -fdata-sections -ffunction-sections

# Generate Dependencies
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"
CXXFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
CXXFLAGS += -g -gdwarf-2
endif

LIBS = -lc -lstdc++ -lm -lSDL2
LIB_DIR = 
LDFLAGS = $(LIB_DIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(CXX_SOURCES:.cpp=.o)))
vpath %.cpp $(sort $(dir $(CXX_SOURCES)))

# Ensure that 'all' or '$(TARGET)' is the default target
all: $(BUILD_DIR)/$(TARGET)

# Rule for compiling C source files
$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

# Rule for compiling C++ source files
$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR)
	$(CXX) -c $(CXXFLAGS) $< -o $@

# Rule for linking object files
$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Create Build directory if it doesn't exist
$(BUILD_DIR):
	mkdir $@

# Rule for cleaning up
clean:
	-rm -fR $(BUILD_DIR)

# Execute Target
run: $(BUILD_DIR)/$(TARGET)
	./$(BUILD_DIR)/$(TARGET)

.PHONY: all clean run

# Dependencies
-include $(wildcard $(BUILD_DIR)/*.d)