TARGET := ./bin/bin_tree_generator.o
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-result -g
LDFLAGS := 

SRC_DIR := ./src
BIN_DIR := ./bin
OBJ_DIR := ./obj

CPP_SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.cpp')
CPP_OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPP_SRC_FILES))

$(TARGET): $(CPP_OBJ_FILES)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(TARGET)

run: $(TARGET)
	$(TARGET) $(ARGS)

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)