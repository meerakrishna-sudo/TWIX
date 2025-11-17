CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -IHeader

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

TARGET = $(BIN_DIR)/twixt.exe

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)
	@echo "Build complete: $(TARGET)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	@echo "Running $(TARGET)"
	$(TARGET)

clean:
	if exist "$(BUILD_DIR)" rmdir /s /q "$(BUILD_DIR)"
	if exist "$(BIN_DIR)" rmdir /s /q "$(BIN_DIR)"
	@echo "Cleaned."

.PHONY: all run clean
