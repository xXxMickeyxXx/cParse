########################################################
# • ---------- 'cParse' PACKAGE STRUCTURE ---------- • #
########################################################

CCOMPILER ?= clang
LIB_NAME = cParse
SEMVAR ?= 0.0.1


# @NOTE: some of the flag variables are empty in order to more easily add
#		 conditional compilation rules
C_STANDARD ?= c99
FLAG_WALL = -Wall
FLAG_WERROR = -Werror
OPTIMIZATION_LEVEL ?= -O0
CODEGEN_TARGET ?= native
MISC_FLAGS = -Wno-unused-variable -Wno-unused-function
CFLAGS = $(OPTIMIZATION_LEVEL) -flto -march=$(CODEGEN_TARGET) $(FLAG_WERROR) $(FLAG_WALL) $(MISC_FLAGS) -std=$(C_STANDARD)


# @NOTE: top level dirs
BUILD_DIR = build
EXAMPLES_DIR = examples
INCLUDE_DIR = include
SOURCE_DIR = source
TESTING_DIR = testing


# @NOTE: build root dirs for examples and testing outputs
BUILD_EXAMPLES_DIR = $(BUILD_DIR)/examples
BUILD_TESTING_DIR = $(BUILD_DIR)/testing


# @NOTE: lib source/header files
LIB_SOURCE_FILES = $(SOURCE_DIR)/scanner.c
LIB_HEADER_FILES = $(SOURCE_DIR)/common.h $(SOURCE_DIR)/scanner.h $(SOURCE_DIR)/utils.h
LIB_TARGET = $(LIB_NAME)


# @NOTE: testing files
TESTING_FILE_MAIN = $(TESTING_DIR)/main.c
TESTING_SOURCE_FILES = $(TESTING_FILE_MAIN)
TESTING_TARGET_NAME = testing_$(LIB_NAME)
TESTING_TARGET = $(BUILD_TESTING_DIR)/$(TESTING_TARGET_NAME)





all: $(LIB_TARGET)


$(LIB_TARGET): $(LIB_SOURCE_FILES) $(LIB_HEADER_FILES)
	@echo ""
	@echo "Building cParse lib..."
	@echo ""
	@$(CC) $(CFLAGS) -o $(LIB_TARGET) $(LIB_SOURCE_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""


testing_target: $(TESTING_TARGET_NAME)


$(TESTING_TARGET_NAME): | make_build_dir_for_tests
	@echo ""
	@echo "Building cParse dev testing binary..."
	@echo ""
	@$(CCOMPILER) $(CFLAGS) -o $(TESTING_TARGET) $(TESTING_SOURCE_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""


make_build_dir_for_tests:
	@mkdir -p $(TESTING_BIN_DIR)


delete_builds:
	@rm -r build
	@mkdir -p build



##############################################
# • ---------- MISC INFORMATION ---------- • #
##############################################

# Compiler flags:
#		-Wall: all warnings
#		-Wextra: more warnings
#		-std=c11: use C11 standard
#		-march=native: select target architecture for code generation; 'native' automatically detects architecture of the CPU with which the system is being built on
#		-Wno-unused-variable -Wno-unused-function: supress errors that are generated from variables/functions (respectively) that aren't used
