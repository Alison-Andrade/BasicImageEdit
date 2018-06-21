SRC_DIR = ./src
OBJ_DIR = ./build
INC_DIR = ./include
LIB_DIR = ./lib
BIN_DIR = ./bin

CC = g++
CPP_FLAGS = -Wall -pedantic -std=c++11 -I$(INC_DIR)
AR = ar

all:
	$(CC) $(CPP_FLAGS) -o $(BIN_DIR)/BasicImageEdit $(SRC_DIR)/*