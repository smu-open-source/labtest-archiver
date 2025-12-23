# Development Guide

This guide will help you get started with developing the LabTest Archiver & Grader project.

## Setting Up Your Development Environment

### Prerequisites

Ensure you have the following installed:

- GCC or Clang compiler
- Make
- Git
- Text editor or IDE (VS Code, Vim, etc.)
- Optional: clang-format for code formatting
- Optional: valgrind for memory checking

### Getting the Source Code

```bash
# Clone your forked repository
git clone https://github.com/yourusername/labtest-archiver.git
cd labtest-archiver

# Create your feature branch
git checkout -b feature/your-feature-name
```

## Project Structure Explained

```
labtest-archiver/
├── include/          # Public header files
│   ├── common.h      # Shared utilities and definitions
│   ├── archiver.h    # Archiver API
│   └── grader.h      # Grader API
├── src/              # Implementation files
│   ├── common.c      # Common utilities implementation
│   ├── archiver.c    # Archiver logic
│   ├── grader.c      # Grader logic
│   ├── archiver_main.c  # Archiver entry point
│   └── grader_main.c    # Grader entry point
├── lib/              # External libraries (miniz)
├── build/            # Compiled object files (generated)
├── bin/              # Compiled binaries (generated)
├── docs/             # Documentation
```

## Building the Project

### Basic Build

```bash
# Build everything
make

# Build only the archiver
make archiver

# Build only the grader
make grader
```

### Debug Build

For development, use debug mode to get helpful debugging symbols:

```bash
make DEBUG=1
```

This adds:
- Debug symbols (`-g`)
- No optimization (`-O0`)
- Debug preprocessor flag (`-DDEBUG`)

### Clean Build

Remove all build artifacts:

```bash
make clean
```

Rebuild from scratch:

```bash
make rebuild
```

## Code Style

We follow these C coding standards:

### Naming Conventions

- **Functions**: `snake_case`
- **Variables**: `snake_case`
- **Constants/Macros**: `UPPER_SNAKE_CASE`
- **Types**: `PascalCase_t` (with `_t` suffix)

### Example

```c
#define MAX_BUFFER_SIZE 1024

typedef struct {
    int student_id;
    char name[256];
} Student_t;

int process_student(Student_t *student) {
    // Implementation
}
```

### Formatting

Run clang-format to auto-format your code:

```bash
make format
```

### Header Guards

Always use header guards in `.h` files:

```c
#ifndef FILENAME_H
#define FILENAME_H

// Content here

#endif // FILENAME_H
```

## Adding New Features

### Step-by-Step Process

1. **Create an Issue**: Describe what you want to add
2. **Create a Branch**: `git checkout -b feature/feature-name`
3. **Write Code**: Follow the style guide
4. **Test**: Build and test your changes
5. **Commit**: Write clear commit messages
6. **Push**: Push to your fork
7. **Pull Request**: Submit a PR with description

### Adding a New Function

When adding a new function:

1. **Declare in header** (`include/*.h`):
```c
/**
 * @brief Brief description
 * @param param1 Description of param1
 * @return Description of return value
 */
int my_new_function(int param1);
```

2. **Implement in source** (`src/*.c`):
```c
int my_new_function(int param1) {
    // Validate parameters
    if (param1 < 0) {
        return ERROR_INVALID_ARGS;
    }

    // Implementation

    return SUCCESS;
}
```

3. **Update Makefile if needed**: Add new source files to build

## Testing Your Changes

### Manual Testing

```bash
# Build with debug symbols
make DEBUG=1

# Test the archiver
./bin/labtest-archiver --help

# Test the grader
./bin/labtest-grader --help
```

### Compiler Warnings

Always build with zero warnings:

```bash
make clean && make
# Should see no warnings!
```

## Common Tasks

### Adding Error Codes

1. Define in `include/common.h`:
```c
#define ERROR_NEW_TYPE -6
```

2. Handle in your function:
```c
if (error_condition) {
    print_error("Descriptive error message");
    return ERROR_NEW_TYPE;
}
```

### Adding Command-Line Options

1. Add to `long_options` array in parse functions
2. Add case to switch statement
3. Update usage/help message
4. Document in README

## Performance Considerations

- Use `const` for parameters that shouldn't change
- Avoid unnecessary memory allocations
- Free memory as soon as you're done with it
- Use appropriate buffer sizes

## Documentation

When adding features:

- Update relevant markdown files
- Add code comments for complex logic
- Keep CHANGELOG.md current

## Getting Help

- Read existing code to understand patterns
- Check issues for similar questions
- Ask in PR comments
- Reach out to maintainers

---

Happy coding! Remember: all questions are welcome, especially from beginners.
