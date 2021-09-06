TARGET := ./bin/multiplication_table.o
TEST_TARGET := ./bin/test.o
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-result -g
LDFLAGS := 

SRC_DIR := ./src
TEST_DIR := ./test
BIN_DIR := ./bin
OBJ_DIR := ./obj

CPP_SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.cpp')
CPP_OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/src/%.o, $(CPP_SRC_FILES))

GTEST_LDFLAGS := -lgtest -pthread
TEST_SRC_FILES := $(shell find $(TEST_DIR) -type f -name '*.cpp')
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/test/%.o, $(TEST_SRC_FILES))

$(TARGET): $(CPP_OBJ_FILES)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(TEST_TARGET): $(TEST_OBJ_FILES)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(GTEST_LDFLAGS)

$(OBJ_DIR)/src/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/test/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(TARGET) $(TEST_TARGET)

run: $(TARGET)
	$(TARGET)

test: $(TEST_TARGET)
	$(TEST_TARGET)

test.sh: $(TARGET)
	$(TEST_DIR)/test.sh

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)
	find . -type f -name '*.tmp' -exec rm -f {} \;