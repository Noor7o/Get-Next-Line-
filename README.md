*This activity has been created as part of the 42 curriculum by ndwairi.*

## **Description**

The **get_next_line** project is part of the 42 curriculum. The goal is to develop a C function that reads and returns one line at a time from a file descriptor.

The project focuses on file handling, dynamic memory allocation, string manipulation, and static variables.

The function reads input progressively instead of loading the entire file into memory. It supports repeated calls to retrieve consecutive lines.

## **Instructions**

### **Compilation**

Compile the source files from the root of the repository using:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

To compile without specifying `BUFFER_SIZE`, the implementation should define a default value in the header file.

### **Files**

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

All required files must be located at the root of the repository.

## **Algorithm**

The algorithm reads data from a file descriptor in small chunks and stores the data until a complete line is available.

A static variable is used to preserve any leftover data between function calls. This allows the function to continue reading from where the previous call stopped without losing unread characters.

### **Steps**

1. Read a chunk of data using `read()`.
2. Append the data to the previously stored content.
3. Search for a newline character (`\n`).
4. If a newline is found, extract and return the line, including the newline character.
5. Preserve any remaining content for the next call.
6. If the end of the input is reached, return the remaining characters if any.
7. Return `NULL` when no more lines are available or an error occurs.

### **Algorithm Justification**

This approach is suitable because it processes input incrementally and returns a line as soon as enough data has been read. It avoids loading the entire file into memory and preserves unread content between calls.

The buffer size can change, so the algorithm must rely on the actual number of bytes returned by `read()` rather than assuming every read fills the buffer.

### **Complexity**

- **Time complexity:** Depends on the string manipulation strategy. Repeatedly copying accumulated strings may lead to quadratic processing for long lines.
- **Space complexity:** Proportional to the current line, any leftover content, and the temporary read buffer.

## **Resources**

- [Linux manual: read()](https://man7.org/linux/man-pages/man2/read.2.html)
- [Linux manual: malloc()](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [Linux manual: free()](https://man7.org/linux/man-pages/man3/free.3.html)
- [GNU C Preprocessor documentation](https://gcc.gnu.org/onlinedocs/cpp/)
- [C storage duration — cppreference](https://en.cppreference.com/w/c/language/storage_duration)

### **AI Usage**

AI was used to help structure and write this README, explain the general algorithm, describe its justification and complexity, and identify relevant documentation resources.

The actual implementation and its behavior should be verified against the submitted source code. Any additional AI assistance used during coding or debugging should be disclosed accurately.
