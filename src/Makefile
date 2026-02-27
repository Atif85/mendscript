CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

TARGET = $(BIN_DIR)/mend
SRCS = main.c $(wildcard frontend/*.c) $(wildcard backend/*.c)
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# OS Detection
ifeq ($(OS),Windows_NT)
    MKDIR = if not exist $(subst /,\,$(1)) mkdir $(subst /,\,$(1))
    RM = rmdir /s /q
    FIX_PATH = $(subst /,\,$(1))
    TARGET := $(TARGET).exe
else
    MKDIR = mkdir -p $(1)
    RM = rm -rf
    FIX_PATH = $(1)
endif

all: prepare $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o: %.c
	@$(call MKDIR,$(dir $@))
	$(CC) $(CFLAGS) -c $< -o $@

prepare:
	@$(call MKDIR,$(OBJ_DIR)/frontend)
	@$(call MKDIR,$(OBJ_DIR)/backend)
	@$(call MKDIR,$(BIN_DIR))

clean:
	$(RM) $(BUILD_DIR)

.PHONY: all prepare clean