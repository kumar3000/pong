CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror
CXXLIBS = -lGL -lGLU -lglut

# DIRECTORIES
SRC_DIR = src
BIN_DIR = bin

# FILES
TARGET = $(BIN_DIR)/pong
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# COMPILE
all: $(TARGET)
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -I$(SRC_DIR) $(SRCS) -o $(TARGET) $(CXXLIBS)

clean:
	rm -rf $(TARGET)

run:
	$(BIN_DIR)/pong

.PHONY: all clean run
