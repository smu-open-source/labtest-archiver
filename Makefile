# Makefile for LabTest Archiver & Grader
# Educational open source project by SMU Open Source Club

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -pedantic
INCLUDES := -Iinclude -Ilib/miniz
LDFLAGS :=
LIBS :=

# Directories
SRC_DIR := src
INC_DIR := include
LIB_DIR := lib
BUILD_DIR := build
BIN_DIR := bin

# Source files
COMMON_SRC := $(SRC_DIR)/common.c
ARCHIVER_SRC := $(SRC_DIR)/config.c $(SRC_DIR)/archiver.c $(SRC_DIR)/archiver_main.c
GRADER_SRC := $(SRC_DIR)/grader.c $(SRC_DIR)/grader_main.c

# Object files
COMMON_OBJ := $(BUILD_DIR)/common.o
ARCHIVER_OBJ := $(BUILD_DIR)/config.o $(BUILD_DIR)/archiver.o $(BUILD_DIR)/archiver_main.o
GRADER_OBJ := $(BUILD_DIR)/grader.o $(BUILD_DIR)/grader_main.o

# Binaries
ARCHIVER_BIN := $(BIN_DIR)/labtest-archiver
GRADER_BIN := $(BIN_DIR)/labtest-grader

# Debug build support
ifdef DEBUG
    CFLAGS += -g -O0 -DDEBUG
else
    CFLAGS += -O2
endif

# Default target
.PHONY: all
all: $(ARCHIVER_BIN) $(GRADER_BIN)

# Create necessary directories
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Build archiver binary
$(ARCHIVER_BIN): $(COMMON_OBJ) $(ARCHIVER_OBJ) | $(BIN_DIR)
	@echo "Linking archiver..."
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)
	@echo "Built: $@"

# Build grader binary
$(GRADER_BIN): $(COMMON_OBJ) $(GRADER_OBJ) | $(BIN_DIR)
	@echo "Linking grader..."
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)
	@echo "Built: $@"

# Compile common object
$(BUILD_DIR)/common.o: $(SRC_DIR)/common.c $(INC_DIR)/common.h | $(BUILD_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile config object
$(BUILD_DIR)/config.o: $(SRC_DIR)/config.c $(INC_DIR)/config.h $(INC_DIR)/common.h | $(BUILD_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile archiver objects
$(BUILD_DIR)/archiver.o: $(SRC_DIR)/archiver.c $(INC_DIR)/archiver.h $(INC_DIR)/common.h | $(BUILD_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/archiver_main.o: $(SRC_DIR)/archiver_main.c $(INC_DIR)/archiver.h | $(BUILD_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile grader objects
$(BUILD_DIR)/grader.o: $(SRC_DIR)/grader.c $(INC_DIR)/grader.h $(INC_DIR)/common.h | $(BUILD_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/grader_main.o: $(SRC_DIR)/grader_main.c $(INC_DIR)/grader.h | $(BUILD_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Individual build targets
.PHONY: archiver
archiver: $(ARCHIVER_BIN)

.PHONY: grader
grader: $(GRADER_BIN)

# Clean build artifacts
.PHONY: clean
clean:
	@echo "Cleaning build artifacts..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "Clean complete"

# Rebuild everything
.PHONY: rebuild
rebuild: clean all

# Install binaries (optional)
.PHONY: install
install: all
	@echo "Installing binaries to /usr/local/bin..."
	@install -m 755 $(ARCHIVER_BIN) /usr/local/bin/
	@install -m 755 $(GRADER_BIN) /usr/local/bin/
	@echo "Installation complete"

# Uninstall binaries
.PHONY: uninstall
uninstall:
	@echo "Uninstalling binaries..."
	@rm -f /usr/local/bin/labtest-archiver
	@rm -f /usr/local/bin/labtest-grader
	@echo "Uninstall complete"

# Run archiver (for testing)
.PHONY: run-archiver
run-archiver: $(ARCHIVER_BIN)
	@$(ARCHIVER_BIN) --help

# Run grader (for testing)
.PHONY: run-grader
run-grader: $(GRADER_BIN)
	@$(GRADER_BIN) --help

# Format code (requires clang-format)
.PHONY: format
format:
	@echo "Formatting code..."
	@find $(SRC_DIR) $(INC_DIR) -name '*.c' -o -name '*.h' | xargs clang-format -i
	@echo "Format complete"

# Check for memory leaks (requires valgrind)
.PHONY: memcheck-archiver
memcheck-archiver: $(ARCHIVER_BIN)
	valgrind --leak-check=full --show-leak-kinds=all $(ARCHIVER_BIN) --help

.PHONY: memcheck-grader
memcheck-grader: $(GRADER_BIN)
	valgrind --leak-check=full --show-leak-kinds=all $(GRADER_BIN) --help

# Help target
.PHONY: help
help:
	@echo "LabTest Archiver & Grader - Makefile Help"
	@echo ""
	@echo "Available targets:"
	@echo "  all                - Build both archiver and grader (default)"
	@echo "  archiver           - Build only the archiver"
	@echo "  grader             - Build only the grader"
	@echo "  clean              - Remove all build artifacts"
	@echo "  rebuild            - Clean and rebuild everything"
	@echo "  install            - Install binaries to /usr/local/bin"
	@echo "  uninstall          - Remove installed binaries"
	@echo "  run-archiver       - Build and run archiver with --help"
	@echo "  run-grader         - Build and run grader with --help"
	@echo "  format             - Format code using clang-format"
	@echo "  memcheck-archiver  - Check archiver for memory leaks"
	@echo "  memcheck-grader    - Check grader for memory leaks"
	@echo "  help               - Display this help message"
	@echo ""
	@echo "Build options:"
	@echo "  DEBUG=1            - Build with debug symbols and no optimization"
	@echo ""
	@echo "Examples:"
	@echo "  make                      # Build everything"
	@echo "  make clean                # Clean build files"
	@echo "  make DEBUG=1              # Build with debugging enabled"
	@echo "  make archiver             # Build only archiver"
	@echo ""
