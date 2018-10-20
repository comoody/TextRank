BIN_PATH = ../bin/
EX_PATH = ./
SRC_PATH = ../src/
FLAGS = -c

################### EXAMPLE ######################
example: example.o TextRanker.o utils.o
	g++ \
	$(BIN_PATH)example.o \
	$(BIN_PATH)TextRanker.o \
	$(BIN_PATH)utils.o \
	-o $(BIN_PATH)example

example.o: $(EX_PATH)/example.cpp
	g++ $(EX_PATH)/example.cpp $(FLAGS) -o $(BIN_PATH)example.o

TextRanker.o: $(SRC_PATH)TextRanker.cpp
	g++ $(SRC_PATH)TextRanker.cpp $(FLAGS) -o $(BIN_PATH)TextRanker.o

utils.o: $(SRC_PATH)utils.cpp
	g++ $(SRC_PATH)utils.cpp $(FLAGS) -o $(BIN_PATH)utils.o

################### DEBUG EXAMPLE ######################
debug: FLAGS += -g

debug: example


clean:
	rm -f $(BIN_PATH)*