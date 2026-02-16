*This project has been created as part of the 42 curriculum by wkerdad.*

# Get Next Line

## Description
**Get Next Line** is a C programming project from the 42 curriculum. The goal is to implement a function:

```c
char *get_next_line(int fd);
```

that reads and returns the next line from a file descriptor on each call. This function must handle partial reads, return lines including the trailing `\n` when present, and keep state between calls using a static variable. The project focuses on memory management, file I/O, and understanding how static storage can preserve state across function calls.

---

## Instructions

### Requirements
- C language only, compliant with the 42 Norm.
- External functions allowed: `read`, `malloc`, `free`.
- Forbidden: `lseek`, global variables, use of `libft`.

### Compilation
The buffer size is controlled via the `BUFFER_SIZE` macro:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

You can compile **with or without** the `-D BUFFER_SIZE=n`.

### Usage Example
```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## How It Works (Algorithm & Justification)

The core challenge is to **return one line at a time** without losing unread data between calls. This requires:

### 1. Static Buffer
A `static` variable stores leftover data from the previous call. This allows the function to:
- keep unread characters after a newline,
- avoid re-reading the file from the start,
- return correct lines on successive calls.

### 2. Incremental Reading
The function repeatedly calls `read()` into a temporary buffer of size `BUFFER_SIZE` and appends it to the static storage until:
- a newline `\n` is found, or you reach the end of file

### 3. Line Extraction
Once a newline is present:
- split the static buffer into:
  - **line** (to return),
  - **remainder** (kept in static buffer for next call).

If EOF is reached and no newline exists:
- return the remaining buffer as the last line,
- or return `NULL` if nothing remains.

### 4. Memory Safety
Every allocation is checked, and all returned lines must be freed by the caller. The static buffer is freed when no data remains.

### Why This Algorithm?
It satisfies the constraints of:
- reading **as little as possible**,
- returning **exactly one line per call**,
- handling different `BUFFER_SIZE` values,
- supporting `stdin` and file descriptors,
- preserving leftover data without global variables.

---

## Bonus (If Implemented)
Bonus rules allow:
- using **only one static variable**,
- handling **multiple file descriptors simultaneously**.

This can be achieved by storing each FD’s state in a structure or linked list and retrieving the correct buffer per FD.

---

## Resources

### References
- `man 2 read` — Unix system call documentation  
- `man 3 malloc` — memory allocation  
- [42 Get Next Line Subject](https://cdn.intra.42.fr/) (internal)  
- C string handling (e.g. `strchr`, `strlen` style behavior)

### AI Usage
- AI was used to help draft and structure this README.
- No code was generated or copied using AI.
- The algorithm description reflects my own implementation and understanding.

---

## Author
Walid2907
