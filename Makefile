###############################################################
# • ---------- 'cParse' PACKAGE BUILD STRUCTURES ---------- • #
###############################################################

CCOMPILER ?= clang
LIB_NAME = cParse
SEMVAR ?= 0.0.1
# @NOTE: empty to allow for the app to be built in specified directory
PACKAGE_ROOT ?=


# @NOTE: some of the flag variables are empty in order to more easily add
#		 conditional compilation rules
C_STANDARD ?= -std=c99
FLAG_WALL ?= -Wall
FLAG_WERROR ?= -Werror
OPTIMIZATION_LEVEL ?= -O0
CODEGEN_TARGET ?= native
MISC_FLAGS ?= -Wno-unused-variable -Wno-unused-function
INCLUDE ?= /Users/mickey/Desktop/C_Lang/libs/cparse/include
# @COMPLETE[2025-12-18] -- @TODO[2025-12-18]: remove all uses of 'R_ID' as it will ultimately be replaced with 'ID'
R_ID ?= all
# @COMPLETE[2025-12-18] -- @NOTE[2025-12-18]: 'ID' replacing 'R_ID'
ID ?= all
CFLAGS ?= $(OPTIMIZATION_LEVEL) -flto -march=$(CODEGEN_TARGET) $(FLAG_WERROR) $(FLAG_WALL) $(MISC_FLAGS) $(C_STANDARD)


# @NOTE: top level dirs
BUILD_DIR = build
EXAMPLES_DIR = examples
INCLUDE_DIR = include
SOURCE_DIR = source
UTILS_DIR = utils
TESTING_DIR = testing
# FILES_DIR = files


# @NOTE: build dirs for the files and dirs that are generated when building from source
BUILD_EXAMPLES_DIR = $(BUILD_DIR)/examples
BUILD_TESTING_DIR = $(BUILD_DIR)/testing


# @NOTE: lib source/header files realted to the library
LIB_SOURCE_FILES = $(SOURCE_DIR)/parser.c $(SOURCE_DIR)/scanner.c $(SOURCE_DIR)/tensor.c $(SOURCE_DIR)/grammar.c
LIB_HEADER_FILES = $(SOURCE_DIR)/parser.h $(UTILS_DIR)/common.h $(SOURCE_DIR)/scanner.h $(SOURCE_DIR)/tensor.h $(SOURCE_DIR)/grammar.h $(UTILS_DIR)/utils.h
LIB_TARGET = $(LIB_NAME)


# @NOTE: testing files
TESTING_SOURCE_FILES = $(TESTING_DIR)/main.c $(LIB_SOURCE_FILES)
TESTING_HEADER_FILES = $(TESTING_DIR)/testing_utils.h $(TESTING_DIR)/testing_SIMD_matmul.h
TESTING_TARGET = $(BUILD_TESTING_DIR)/testing_$(LIB_NAME)


# @NOTE: prototyping helper-application (using python) 
# PROTOTYPES_DIR = $(FILES_DIR)/prototypes


# @NOTE: files and dirs related to the package's examples
EXAMPLES_PREFIX = example_

EXAMPLES_abcLang_SOURCE_FILES = $(EXAMPLES_DIR)/abcLang/main.c $(LIB_SOURCE_FILES)
EXAMPLES_abcLang_HEADER_FILES =
EXAMPLES_abcLang_TARGET = $(BUILD_EXAMPLES_DIR)/abcLang/$(EXAMPLES_PREFIX)abcLang

EXAMPLES_arithmeticLang_SOURCE_FILES = $(EXAMPLES_DIR)/arithmeticLang/main.c $(LIB_SOURCE_FILES)
EXAMPLES_arithmeticLang_HEADER_FILES =
EXAMPLES_arithmeticLang_TARGET = $(BUILD_EXAMPLES_DIR)/arithmeticLang/$(EXAMPLES_PREFIX)arithmeticLang

EXAMPLES_dateLang_SOURCE_FILES = $(EXAMPLES_DIR)/dateLang/main.c
EXAMPLES_dateLang_HEADER_FILES = 
EXAMPLES_dateLang_TARGET = $(BUILD_EXAMPLES_DIR)/dateLang/$(EXAMPLES_PREFIX)dateLang

EXAMPLES_LitScrip_SOURCE_FILES = $(EXAMPLES_DIR)/LitScrip/main.c $(LIB_SOURCE_FILES)
EXAMPLES_LitScrip_HEADER_FILES =
EXAMPLES_LitScrip_TARGET = $(BUILD_EXAMPLES_DIR)/LitScrip/$(EXAMPLES_PREFIX)LitScrip


# @NOTE: basic compile command
ifeq ($(strip $(INCLUDE)),)
	COMPILE = $(CCOMPILER) $(CFLAGS) -o
else
	COMPILE = $(CCOMPILER) $(CFLAGS) -I$(INCLUDE) -o
endif

# @NOTE: misc commands
BUILD_SUB_PACKAGES = $(TESTING_TARGET) $(BUILD_EXAMPLES_DIR)/abcLang $(BUILD_EXAMPLES_DIR)/arithmeticLang $(BUILD_EXAMPLES_DIR)/dateLang $(BUILD_EXAMPLES_DIR)/LitScrip


# @NOTE: TUI output formatting selections

# @NOTE: ERROR output formatting
ERROR_COLOR_STR = **INVALID**
ERROR_COLOR_NUM = 196
ERROR_OUT_RENDER = \033[38;5;$(ERROR_COLOR_NUM)m$(ERROR_COLOR_STR)\033[0m


# @NOTE: title-line output formatting for 'help' rule (which is the default command, running when invoking with 'make', as opposed to 'make this_thing_or_that_thing', etc.)
rHELP_COLOR_STR = 'cParse' - MAKEFILE COMMANDS
rHELP_COLOR_NUM = 208
rHELP_OUT_RENDER = \033[38;5;$(rHELP_COLOR_NUM)m$(rHELP_COLOR_STR)\033[0m



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
	@echo "\t ________$(rHELP_OUT_RENDER)________  "
	@echo "\t"
	@echo "\t    • all ---------------> creates all package builds including all lib, testing, and example binaries/executables (and supporting file hierarchy)"
	@echo "\t    • lib ---------------> creates all lib related binaries/executables (and supporting file hierarchy) **ONLY**"
	@echo "\t    • tests -------------> creates testing binaries/executables (and supporting file hierarchy) **ONLY**"
	@echo "\t    • examples ----------> creates 'abcLang', 'arithmeticLang', and 'dateLang' example binaries/executables"
	@echo "\t    • abcLang -----------> creates 'abcLang' example binaries/executable (and supporting file hierarchy) **ONLY**"
	@echo "\t    • arithmeticLang ----> creates 'arithmeticLang' example binaries/executable (and supporting file hierarchy) **ONLY**"
	@echo "\t    • dateLang ----------> creates 'dateLang' example binaries/executable (and supporting file hierarchy) **ONLY**"
	@echo "\t    • LitScrip ----------> creates 'LitScrip' example binaries/executable (and supporting file hierarchy) **ONLY**"
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
	@$(COMPILE) $(TESTING_TARGET) $(TESTING_SOURCE_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""


examples: abcLang arithmeticLang dateLang | __create_build_examples_dir


abcLang: $(EXAMPLES_abcLang_SOURCE_FILES) $(EXAMPLES_abcLang_HEADER_FILES) | __create_build_examples_dir
	@mkdir -p $(BUILD_EXAMPLES_DIR)/abcLang
	@echo ""
	@echo "Building 'abcLang' executable..."
	@echo ""
	@$(COMPILE) $(EXAMPLES_abcLang_TARGET) $(EXAMPLES_abcLang_SOURCE_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""


arithmeticLang: $(EXAMPLES_arithmeticLang_SOURCE_FILES) $(EXAMPLES_arithmeticLang_HEADER_FILES) | __create_build_examples_dir
	@mkdir -p $(BUILD_EXAMPLES_DIR)/arithmeticLang
	@echo ""
	@echo "Building 'arithmeticLang' executable..."
	@echo ""
	@$(COMPILE) $(EXAMPLES_arithmeticLang_TARGET) $(EXAMPLES_arithmeticLang_SOURCE_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""


dateLang: $(EXAMPLES_dateLang_SOURCE_FILES) $(EXAMPLES_dateLang_HEADER_FILES) | __create_build_examples_dir
	@mkdir -p $(BUILD_EXAMPLES_DIR)/dateLang
	@echo ""
	@echo "Building 'dateLang' executable..."
	@echo ""
	@$(COMPILE) $(EXAMPLES_dateLang_TARGET) $(EXAMPLES_dateLang_SOURCE_FILES) $(EXAMPLES_dateLang_HEADER_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""

LitScrip: $(EXAMPLES_LitScrip_SOURCE_FILES) $(EXAMPLES_LitScrip_HEADER_FILES) | __create_build_examples_dir
	@mkdir -p $(BUILD_EXAMPLES_DIR)/LitScrip
	@echo ""
	@echo "Building 'LitScrip' executable..."
	@echo ""
	@$(COMPILE) $(EXAMPLES_LitScrip_TARGET) $(EXAMPLES_LitScrip_SOURCE_FILES) $(EXAMPLES_LitScrip_HEADER_FILES)
	@echo ""
	@echo "...**COMPLETE**"
	@echo ""


reset:
	@echo "";
	@if [ "$(ID)" = "all" ]; then \
		echo "Resetting all builds contained in 'build' dir..."; \
		echo ""; \
		rm -r -f $(BUILD_EXAMPLES_DIR); \
		rm -r -f $(BUILD_TESTING_DIR); \
		echo "'$(LIB_NAME)' package has been reset to it's state prior to building with rule '$(ID)'..."; \
		echo ""; \
	elif [ "$(ID)" = "examples" ]; then \
		echo "Resetting 'build/examples' to pre-build state..."; \
		echo ""; \
		rm -r -f $(BUILD_EXAMPLES_DIR); \
		echo "'$(LIB_NAME)' package has been reset to it's state prior to building with rule '$(ID)'..."; \
		echo ""; \
	elif [ "$(ID)" = "tests" ]; then \
		echo "Resetting 'tests' packaging to pre-build state..."; \
		echo ""; \
		rm -r -f $(BUILD_TESTING_DIR); \
		echo "'$(LIB_NAME)' package has been reset to it's state prior to building with rule '$(ID)'..."; \
		echo ""; \
	elif [ "$(ID)" = "abcLang" ]; then \
		echo "Resetting 'abcLang' example to pre-build state..."; \
		echo ""; \
		rm -r -f $(BUILD_EXAMPLES_DIR)/abcLang; \
		echo "'$(LIB_NAME)' package has been reset to it's state prior to building with rule '$(ID)'..."; \
		echo ""; \
	elif [ "$(ID)" = "arithmeticLang" ]; then \
		echo "Resetting 'arithmeticLang' example to pre-build state..."; \
		echo ""; \
		rm -r -f $(BUILD_EXAMPLES_DIR)/arithmeticLang; \
		echo "'$(LIB_NAME)' package has been reset to it's state prior to building with rule '$(ID)'..."; \
		echo ""; \
	elif [ "$(ID)" = "dateLang" ]; then \
		echo "Resetting 'dateLang' example to pre-build state..."; \
		echo ""; \
		rm -r -f $(BUILD_EXAMPLES_DIR)/dateLang; \
		echo "'$(LIB_NAME)' package has been reset to it's state prior to building with rule '$(ID)'..."; \
		echo ""; \
	else \
		echo ""; \
		echo "\t$(ERROR_OUT_RENDER) - INPUT $(ID)' FOR 'ID' flag-variable must be ONE of the following selections\n"; \
		echo "\t\t• all"; \
		echo "\t\t• abcLang"; \
		echo "\t\t• arithmeticLang"; \
		echo "\t\t• dateLang"; \
		echo "\t\t• tests"; \
		echo "\n"; \
	fi
	@echo "";


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
