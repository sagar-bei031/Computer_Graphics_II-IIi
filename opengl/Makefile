BUILD_DIR = build

CC = gcc
CFLAGS = -Wall -Wpedantic
LIB = -lm -lGL -lglut -lGLU

all: $(BUILD_DIR)/triangle $(BUILD_DIR)/cube 

$(BUILD_DIR)/triangle: triangle.c | Makefile $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIB)

$(BUILD_DIR)/cube: cube.c | Makefile $(BUILD_DIR)
	$(CC) $(CFLAGS)  $^ -o $@ $(LIB)

$(BUILD_DIR):
	mkdir $@

clean:
	rm -fR $(BUILD_DIR)

.PHONY: all triangle cube clean
