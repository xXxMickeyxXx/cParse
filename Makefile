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
EXAMPLES_arithmeticLang_TARGET = $(BUILD_EXAMPLES_DIR)/arithmeticLang/$(EXAMPLES_PREFIX)arithmeticLang
EXAMPLES_dateLang_TARGET = $(BUILD_EXAMPLES_DIR)/dateLang/$(EXAMPLES_PREFIX)dateLang



###############################################################
#      • ---------- Makefile Rules/Commands ---------- •      #
###############################################################

# @TODO: Determine how I should use this so that any lib binary/executable
#		 files that are needed (by the lib, testing, examples, etc.) are
# 		 generated/created/compiled/etc. and if they are, then don't
# 		 re-compile
# @TODO: Determine how to compose this so that it only compiles if the
# 		 lib needs it, and if it doesn't, it doesn't cause an error or run
# .PHONY: $(LIB_TARGET) $(LIB_SOURCE_FILES) $(LIB_HEADER_FILES)
# 	@echo ""
# 	@echo "Building 'cParse' library binaries..."
# 	@echo ""
# 	@$(CCOMPILER) $(CFLAGS) -o $(LIB_TARGET) $(LIB_SOURCE_FILES)
# 	@echo ""
# 	@echo "...**COMPLETE**"
# 	@echo ""


help:
	@echo "\t"
	@echo "\t --------------------------------------------  "
	@echo "\t|                                             |"
	@echo "\t ________'cParse' - MAKEFILE COMMANDS________  "
	@echo "\t"
	@echo "\t    • all ---------------> creates all package builds including all lib, testing, and example binaries/executables (and supporting file hierarchy)"
	@echo "\t    • lib ---------------> creates all lib related binaries/executables (and supporting file hierarchy) ONLY"
	@echo "\t    • tests -------------> creates testing binaries/executables (and supporting file hierarchy) ONLY"
	@echo "\t    • examples ----------> creates 'dateLang' and 'arithmeticLang' example binaries/executables"
	@echo "\t    • arithmeticLang ----> creates 'arithmeticLang' example binaries/executable (and supporting file hierarchy) ONLY"
	@echo "\t    • dateLang ----------> creates 'dateLang' example binaries/executable (and supporting file hierarchy) ONLY"
	@echo "\t    • reset -------------> reverts package back to pre-build state, removing all binaries/executables (and supporting file hierarchy)"
	@echo "\t    • docs --------------> create documentation for lib (and package as a whole)"
	@echo "\t"
	@echo "\t"


all: examples tests $(TESTING_TARGET)


lib:
	@echo ""
	@echo "'lib' makefile rule NOT IMPLEMENTED..."
	@echo ""


tests: $(TESTING_SOURCE_FILES) $(TESTING_HEADER_FILES) | __create_build_testing_dir
	@echo ""
	@echo "Building 'cParse' testing executable..."
	@echo ""
	@$(CCOMPILER) $(CFLAGS) -o $(TESTING_TARGET) $(TESTING_SOURCE_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""


examples: arithmeticLang dateLang | __create_build_examples_dir


arithmeticLang: $(EXAMPLES_arithmeticLang_SOURCE_FILES) $(EXAMPLES_arithmeticLang_HEADER_FILES) | __create_build_examples_dir
	@mkdir -p $(BUILD_EXAMPLES_DIR)/arithmeticLang
	@echo ""
	@echo "Building 'arithmeticLang' executable..."
	@echo ""
	@$(CCOMPILER) $(CFLAGS) -o $(EXAMPLES_arithmeticLang_TARGET) $(EXAMPLES_arithmeticLang_SOURCE_FILES) $(EXAMPLES_arithmeticLang_HEADER_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""


dateLang: $(EXAMPLES_dateLang_SOURCE_FILES) $(EXAMPLES_dateLang_HEADER_FILES) | __create_build_examples_dir
	@mkdir -p $(BUILD_EXAMPLES_DIR)/dateLang
	@echo ""
	@echo "Building 'dateLang' executable..."
	@echo ""
	@$(CCOMPILER) $(CFLAGS) -o $(EXAMPLES_dateLang_TARGET) $(EXAMPLES_dateLang_SOURCE_FILES) $(EXAMPLES_dateLang_HEADER_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""


reset:
	@echo ""
	@echo "Resetting '$(LIB_NAME)' package to pre-build state..."
	@echo ""
	@rm -r -f $(BUILD_EXAMPLES_DIR)
	@rm -r -f $(BUILD_TESTING_DIR)
	@echo ""
	@echo "'$(LIB_NAME)' package has been reset to it's pre-build state..."
	@echo ""


docs:
	@echo ""
	@echo "'docs' makefile rule NOT IMPLEMENTED..."
	@echo ""


###########################################
# • ---------- UTILITY RULES ---------- • #
###########################################

__create_build_examples_dir:
	@mkdir -p $(BUILD_EXAMPLES_DIR)


__create_build_testing_dir:
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
