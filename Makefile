# @NOTE: Compiler flags:
# @NOTE: -Wall: all warnings
# @NOTE: -Wextra: more warnings
# @NOTE: -std=c11: use C11 standard
# @NOTE: -march=native: select target architecture for code generation; 'native' automatically detects architecture of the CPU with which the system is being built on
# @NOTE: -Wno-unused-variable -Wno-unused-function: supress errors that are generated from variables/functions (respectively) that aren't used


LIB_NAME ?= cParse
CCOMPILER = clang


# @NOTE: some of the flag variables are empty in order to more easily add
#		 conditional compilation rules
C_STANDARD ?= c99
FLAG_WALL = -Wall
FLAG_WERROR = -Werror
# @NOTE: using '?=' ensures the variable has a fallback value ('-O3', which
# 	     indicates aggresive optimizations) if it isn't overrided at runtime
#		 when calling 'make' (such as 'make FLAG_OPTIMZATION_LEVEL="-O0'
# 		 which gives the 'FLAG_OPTIMZATION_LEVEL' variable the value to the
# 		 right of the '=' symbol)
OPTIMIZATION_LEVEL ?= -O0
CODEGEN_TARGET ?= native
MISC_FLAGS = -Wno-unused-variable -Wno-unused-function
CFLAGS = $(OPTIMIZATION_LEVEL) -flto -march=$(CODEGEN_TARGET) $(FLAG_WERROR) $(FLAG_WALL) $(MISC_FLAGS) -std=$(C_STANDARD)


ROOT_DIR ?= $(LIB_NAME)
INCLUDE_DIR = include
LIB_HEADER_FILE = $(INCLUDE_DIR)/$(LIB_NAME).h

SOURCE_DIR = source
SOURCE_FILE_MAIN = $(SOURCE_DIR)/main.c
# create_source_file_main
SOURCE_FILES = 
TESTING_DIR = testing
EXAMPLES_DIR = $(ROOT_DIR)/examples


TESTING_BIN_DIR = $(TESTING_DIR)/bin
TESTING_TARGET = $(TESTING_BIN_DIR)/$(LIB_NAME)


all: testing_$(LIB_NAME)

# $(LIB_NAME): $(TESTING_TARGET) $(SOURCE_FILES) $(LIB_HEADER_FILE) | create_testing_dir create_test_source_file_main create_testing_bin_dir
# $(TESTING_TARGET): $(SOURCE_FILES)
# 	@echo "\n\tBuilding cParse..."
# 	@$(CCOMPILER) $(CFLAGS) -o $(TESTING_TARGET) $(SOURCE_FILES)
# 	@echo "\n\n\t...**COMPLETE**\n"


testing_$(LIB_NAME): create_source_file_main $(TESTING_TARGET) $(SOURCE_FILES) $(LIB_HEADER_FILE) | create_testing_dir create_test_source_file_main create_testing_bin_dir
$(TESTING_TARGET): $(SOURCE_FILES)
	@echo "\n\tBuilding cParse..."
	@$(CCOMPILER) $(CFLAGS) -o $(TESTING_TARGET) $(SOURCE_FILES)
	@echo "\n\n\t...**COMPLETE**\n"

create_testing_dir:
	@mkdir -p $(TESTING_DIR)

create_testing_bin_dir:
	@mkdir -p $(TESTING_BIN_DIR)

create_test_source_file_main:
	@touch $(TESTING_DIR)/main.c

create_source_file_main:
	@touch $(SOURCE_FILE_MAIN)
