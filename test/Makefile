BIN_PATH = ../bin/
SRC_PATH = ../src/
TEST_PATH = ./
FLAGS = -c


################### TESTBENCH ######################
testbench: TextRanker.o testbench.o utils.o TestSuite.o TextRankerTest.o UtilsTest.o FailedTestException.o TestReporter.o
	g++ \
	$(BIN_PATH)TextRanker.o \
	$(BIN_PATH)testbench.o \
	$(BIN_PATH)utils.o \
	$(BIN_PATH)TestSuite.o \
	$(BIN_PATH)TextRankerTest.o \
	$(BIN_PATH)UtilsTest.o \
	$(BIN_PATH)FailedTestException.o \
	$(BIN_PATH)TestReporter.o \
	-o $(BIN_PATH)testbench

TextRanker.o: $(SRC_PATH)TextRanker.cpp
	g++ $(SRC_PATH)TextRanker.cpp $(FLAGS) -o $(BIN_PATH)TextRanker.o

testbench.o: testbench.cpp
	g++ testbench.cpp $(FLAGS) -o $(BIN_PATH)testbench.o

utils.o: $(SRC_PATH)utils.cpp
	g++ $(SRC_PATH)utils.cpp $(FLAGS) -o $(BIN_PATH)utils.o

TestSuite.o: $(TEST_PATH)TestSuite.cpp
	g++ $(TEST_PATH)TestSuite.cpp $(FLAGS) -o $(BIN_PATH)TestSuite.o

TextRankerTest.o: $(TEST_PATH)TextRankerTest.cpp
	g++ $(TEST_PATH)TextRankerTest.cpp $(FLAGS) -o $(BIN_PATH)TextRankerTest.o

UtilsTest.o: $(TEST_PATH)UtilsTest.cpp
	g++ $(TEST_PATH)UtilsTest.cpp $(FLAGS) -o $(BIN_PATH)UtilsTest.o

FailedTestException.o: $(TEST_PATH)FailedTestException.cpp
	g++ $(TEST_PATH)FailedTestException.cpp $(FLAGS) -o $(BIN_PATH)FailedTestException.o

TestReporter.o: $(TEST_PATH)TestReporter.cpp
	g++ $(TEST_PATH)TestReporter.cpp $(FLAGS) -o $(BIN_PATH)TestReporter.o

clean:
	rm -f $(BIN_PATH)*


################### DEBUG TESTBENCH ######################
debug: FLAGS += -g

debug: testbench
