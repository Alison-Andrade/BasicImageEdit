SRC_DIR=./src
OBJ_DIR=./build
INC_DIR=./include
LIB_DIR=./lib
BIN_DIR=./bin

CC = g++
CPP_FLAGS = -Wall -pedantic -std=c++11 -I$(INC_DIR)
AR = ar

all: ImageSteg
	
BasicImage.a:  $(SRC_DIR)/BMPImage.cpp $(SRC_DIR)/PPMImage.cpp $(SRC_DIR)/Image.cpp $(INC_DIR)/BMPImage.h $(INC_DIR)/PPMImage.h $(INC_DIR)/Image.h 
	@echo "----------------------------------------------------------------------------"
	@echo "------------------ Compilando Bibliotecas Estáticas ------------------------"
	$(CC) $(CPP_FLAGS) -c $(SRC_DIR)/BMPImage.cpp -o $(OBJ_DIR)/BMPImage.o
	$(CC) $(CPP_FLAGS) -c $(SRC_DIR)/PPMImage.cpp -o $(OBJ_DIR)/PPMImage.o
	$(CC) $(CPP_FLAGS) -c $(SRC_DIR)/Image.cpp -o $(OBJ_DIR)/Image.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/Image.o $(OBJ_DIR)/PPMImage.o $(OBJ_DIR)/BMPImage.o
	@echo "----------------------------------------------------------------------------"

BasicImage.so: $(SRC_DIR)/BMPImage.cpp $(SRC_DIR)/PPMImage.cpp $(SRC_DIR)/Image.cpp $(INC_DIR)/BMPImage.h $(INC_DIR)/PPMImage.h $(INC_DIR)/Image.h 
	@echo "----------------------------------------------------------------------------"
	@echo "------------------ Compilando Bibliotecas Dinâmicas ------------------------"
	$(CC) $(CPP_FLAGS) -fPIC -c $(SRC_DIR)/BMPImage.cpp -o $(OBJ_DIR)/BMPImage.o
	$(CC) $(CPP_FLAGS) -fPIC -c $(SRC_DIR)/PPMImage.cpp -o $(OBJ_DIR)/PPMImage.o
	$(CC) $(CPP_FLAGS) -fPIC -c $(SRC_DIR)/Image.cpp -o $(OBJ_DIR)/Image.o
	$(CC) -shared -Wl,-soname,BasicImage.so -o $(LIB_DIR)/$@ $(OBJ_DIR)/Image.o
	@echo "----------------------------------------------------------------------------"

main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/*
	$(CC) $(CPP_FLAGS) -c $< -o $(OBJ_DIR)/$@

ImageSteg: main.o BasicImage.a
	$(CC) $(CPP_FLAGS) -o $(BIN_DIR)/$@ $(OBJ_DIR)/main.o $(LIB_DIR)/BasicImage.a

debug: CPP_FLAGS += -g -O0
debug: ImageSteg

.PHONY: BasicImage.a BasicImage.so main.o ImageSteg all

dir:
	@mkdir bin build doc lib
	@echo "Diretórios criados."

clean:
	@rm bin/* build/* doc/* lib/*
	@echo "Arquivos de compilação deletados."