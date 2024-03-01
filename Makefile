CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
SRC_FILES = binary_tree_print.c 3-main.c 3-binary_tree_delete.c 0-binary_tree_node.c 2-binary_tree_insert_right.c 0-binary_tree_node.c
TARGET = 3-del

$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(TARGET)

.PHONY: clean

clean:
	rm -f $(TARGET)