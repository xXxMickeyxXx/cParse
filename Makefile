###############################################################
# • ---------- 'cParse' PACKAGE BUILD STRUCTURES ---------- • #
###############################################################

CCOMPILER ?= clang
LIB_NAME = cParse
SEMVAR ?= 0.0.1
PACKAGE_ROOT ?=  # @NOTE: empty to allow for the app to be built in specified directory


# @NOTE: some of the flag variables are empty in order to more easily add
#		 conditional compilation rules
C_STANDARD ?= -std=c99
FLAG_WALL ?= -Wall
FLAG_WERROR ?= -Werror
OPTIMIZATION_LEVEL ?= -O0
CODEGEN_TARGET ?= native
MISC_FLAGS ?= -Wno-unused-variable -Wno-unused-function
CFLAGS ?= $(OPTIMIZATION_LEVEL) -flto -march=$(CODEGEN_TARGET) $(FLAG_WERROR) $(FLAG_WALL) $(MISC_FLAGS) $(C_STANDARD)


# @NOTE: top level dirs
BUILD_DIR = build
EXAMPLES_DIR = examples
INCLUDE_DIR = include
SOURCE_DIR = source
TESTING_DIR = testing


# @NOTE: build dirs for the files and dirs that are generated when building from source
BUILD_EXAMPLES_DIR = $(BUILD_DIR)/examples
BUILD_TESTING_DIR = $(BUILD_DIR)/testing


# @NOTE: lib source/header files realted to the library
LIB_SOURCE_FILES = $(SOURCE_DIR)/scanner.c
LIB_HEADER_FILES = $(SOURCE_DIR)/common.h $(SOURCE_DIR)/scanner.h $(SOURCE_DIR)/utils.h
LIB_TARGET = $(LIB_NAME)



# @NOTE: testing files
TESTING_SOURCE_FILES = $(TESTING_DIR)/main.c
TESTING_HEADER_FILES ?= 
TESTING_TARGET = $(BUILD_TESTING_DIR)/testing_$(LIB_NAME)


# @NOTE: files and dirs related to the package's examples
EXAMPLES_PREFIX = example_
EXAMPLES_arithmeticLang_SOURCE_FILES = $(EXAMPLES_DIR)/arithmeticLang/main.c
EXAMPLES_arithmeticLang_HEADER_FILES = 
EXAMPLES_dateLang_SOURCE_FILES = $(EXAMPLES_DIR)/dateLang/main.c
EXAMPLES_dateLang_HEADER_FILES = 
EXAMPLES_arithmeticLang_TARGET = $(BUILD_EXAMPLES_DIR)/$(EXAMPLES_PREFIX)arithmeticLang
EXAMPLES_dateLang_TARGET = $(BUILD_EXAMPLES_DIR)/$(EXAMPLES_PREFIX)dateLang



###################################################################
#      • ---------- Makefile Rules and Commands ---------- •      #
###################################################################


help:
	@echo " -----------------------  "
	@echo "|                        |"
	@echo " ________OPTIONS________  "
	@echo ""
	@echo "    • all - creates all "
	@echo ""
	@echo ""


all: examples $(TESTING_TARGET)


# @TODO: Determine how to compose this so that it only compiles if the
# 		 lib needs it, and if it doesn't, it doesn't cause an error or run
.PHONY: $(LIB_TARGET) $(LIB_SOURCE_FILES) $(LIB_HEADER_FILES)
	@echo ""
	@echo "Building 'cParse' library binaries..."
	@echo ""
	@$(CCOMPILER) $(CFLAGS) -o $(LIB_TARGET) $(LIB_SOURCE_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""


$(TESTING_TARGET): $(TESTING_SOURCE_FILES) $(TESTING_HEADER_FILES) | create_build_testing_dir
	@echo ""
	@echo "Building 'cParse' testing..."
	@echo ""
	@$(CCOMPILER) $(CFLAGS) -o $(TESTING_TARGET) $(TESTING_SOURCE_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""


examples: arithmeticLang dateLang | create_build_examples_dir


arithmeticLang: | create_build_examples_dir
	@echo ""
	@echo "Building 'aritheticLang' executable..."
	@echo ""
	@$(CCOMPILER) $(CFLAGS) -o $(EXAMPLES_arithmeticLang_TARGET) $(EXAMPLES_arithmeticLang_SOURCE_FILES) $(EXAMPLES_arithmeticLang_HEADER_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""


dateLang: | create_build_examples_dir
	@echo ""
	@echo "Building 'aritheticLang' executable..."
	@echo ""
	@$(CCOMPILER) $(CFLAGS) -o $(EXAMPLES_dateLang_TARGET) $(EXAMPLES_arithmeticLang_SOURCE_FILES) $(EXAMPLES_dateLang_HEADER_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""


create_build_dirs: | create_build_testing_dir create_build_examples_dir create_build_testing_dir


create_build_examples_dir:
	@mkdir -p $(BUILD_EXAMPLES_DIR)


create_build_testing_dir:
	@mkdir -p $(BUILD_TESTING_DIR)



##############################################
# • ---------- MISC INFORMATION ---------- • #
##############################################

# Compiler flags:
#		-Wall: all warnings
#		-Wextra: more warnings
#		-std=c11: use C11 standard
#		-march=native: select target architecture for code generation; 'native' automatically detects architecture of the CPU with which the system is being built on
#		-Wno-unused-variable -Wno-unused-function: supress errors that are generated from variables/functions (respectively) that aren't used
