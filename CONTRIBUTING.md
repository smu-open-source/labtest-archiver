# Contributing to LabTest Archiver & Grader

Thank you for your interest in contributing! This document provides guidelines and instructions for contributing to this project.

## Welcome, First-Time Contributors!

This project is specifically designed to be beginner-friendly. If this is your first time contributing to open source, you're in the right place! Don't be afraid to ask questions.

## Table of Contents

- [Getting Started](#getting-started)
- [How to Contribute](#how-to-contribute)
- [Development Workflow](#development-workflow)
- [Coding Standards](#coding-standards)
- [Commit Guidelines](#commit-guidelines)
- [Pull Request Process](#pull-request-process)
- [Issue Guidelines](#issue-guidelines)

## Getting Started

### 1. Fork the Repository

Click the "Fork" button at the top right of the repository page.

### 2. Clone Your Fork

```bash
git clone https://github.com/YOUR-USERNAME/labtest-archiver.git
cd labtest-archiver
```

### 3. Add Upstream Remote

```bash
git remote add upstream https://github.com/ORIGINAL-OWNER/labtest-archiver.git
```

### 4. Build the Project

```bash
make
```

If the build succeeds, you're ready to start contributing!

## How to Contribute

There are many ways to contribute:

- **Report bugs** - Found something that doesn't work? Let us know!
- **Suggest features** - Have an idea? We'd love to hear it!
- **Fix bugs** - Browse our issues and fix something
- **Add features** - Implement new functionality
- **Improve documentation** - Help make our docs better
- **Write tests** - Help us improve code quality

### Good First Issues

Look for issues labeled `good first issue` - these are specifically chosen to be approachable for newcomers.

## Development Workflow

### 1. Create a Branch

Always create a new branch for your work:

```bash
git checkout -b feature/your-feature-name
# or
git checkout -b fix/bug-description
```

Branch naming conventions:
- `feature/feature-name` - for new features
- `fix/bug-description` - for bug fixes
- `docs/description` - for documentation
- `refactor/description` - for code refactoring

### 2. Make Your Changes

- Write clear, readable code
- Follow our [coding standards](#coding-standards)
- Test your changes thoroughly
- Keep commits focused and atomic

### 3. Test Your Changes

Before submitting, ensure:

```bash
# Build the project
make clean && make

# Test both binaries
./bin/labtest-archiver --help
./bin/labtest-grader --help
```

### 4. Commit Your Changes

```bash
git add .
git commit -m "Brief description of your changes"
```

See [Commit Guidelines](#commit-guidelines) for details.

### 5. Push to Your Fork

```bash
git push origin your-branch-name
```

### 6. Create a Pull Request

Go to the original repository and click "New Pull Request". Fill out the PR template with details about your changes.

## Coding Standards

### C Style Guide

We follow these conventions to keep the codebase consistent:

#### Naming Conventions

```c
// Functions: snake_case
int calculate_grade(int score);

// Variables: snake_case
int student_count = 0;

// Constants and macros: UPPER_SNAKE_CASE
#define MAX_STUDENTS 100
const int MAX_FILE_SIZE = 1024;

// Structs and typedefs: PascalCase with _t suffix
typedef struct {
    char name[256];
    int score;
} Student_t;
```

#### Formatting

- **Indentation**: 4 spaces (no tabs)
- **Braces**: K&R style (opening brace on same line)
- **Line length**: Maximum 100 characters
- **Comments**: Use `//` for single-line, `/* */` for multi-line

Example:

```c
int process_file(const char *filename) {
    if (filename == NULL) {
        fprintf(stderr, "Error: filename is NULL\n");
        return -1;
    }

    // Process the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    // ... rest of function

    fclose(fp);
    return 0;
}
```

#### File Organization

**Header files** (`include/*.h`):
```c
#ifndef FILENAME_H
#define FILENAME_H

// Includes
#include <stdio.h>

// Constants
#define MAX_SIZE 256

// Type definitions
typedef struct { ... } MyStruct_t;

// Function declarations
int my_function(int param);

#endif // FILENAME_H
```

**Source files** (`src/*.c`):
```c
// Standard library includes
#include <stdio.h>
#include <stdlib.h>

// Project includes
#include "myheader.h"

// Function implementations
int my_function(int param) {
    // ...
}
```

### Error Handling

Always check return values and handle errors gracefully:

```c
FILE *fp = fopen(filename, "r");
if (fp == NULL) {
    fprintf(stderr, "Error: Failed to open file '%s'\n", filename);
    return -1;
}
```

### Memory Management

- Always `free()` what you `malloc()`
- Set pointers to `NULL` after freeing
- Check for `NULL` before dereferencing pointers

## Commit Guidelines

### Commit Message Format

```
<type>: <subject>

<body (optional)>

<footer (optional)>
```

#### Types

- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Formatting changes (no code change)
- `refactor`: Code refactoring
- `test`: Adding tests
- `chore`: Maintenance tasks

#### Examples

```
feat: Add support for ZIP64 format

Implement ZIP64 format support to handle archives larger than 4GB.
This adds new functions in archiver.c to detect and handle large files.

Closes #42
```

```
fix: Prevent buffer overflow in filename parsing

Add bounds checking when copying filenames to prevent buffer overflow.
Also add unit test to verify the fix.

Fixes #38
```

### Commit Best Practices

- Write clear, descriptive commit messages
- Keep commits atomic (one logical change per commit)
- Commit early and often
- Don't commit commented-out code
- Don't commit binary files or build artifacts

## Pull Request Process

### Before Submitting

- [ ] Code builds successfully with `make`
- [ ] Code follows our style guide
- [ ] Commit messages follow our guidelines
- [ ] You've tested your changes
- [ ] Documentation is updated if needed
- [ ] No unnecessary files are included

### PR Title Format

Similar to commit messages:
```
feat: Add compression level option
fix: Resolve memory leak in grader
docs: Update installation instructions
```

### PR Description

Use the provided template and include:

- **What** changes you made
- **Why** you made them
- **How** to test the changes
- Link to related issues

### Review Process

1. A maintainer will review your PR
2. They may request changes
3. Make requested changes and push to your branch
4. Once approved, a maintainer will merge your PR

### After Merging

Update your local repository:

```bash
git checkout main
git pull upstream main
git push origin main
```

## Issue Guidelines

### Creating an Issue

Use the appropriate issue template:

- **Bug Report** - For reporting bugs
- **Feature Request** - For suggesting new features
- **Question** - For asking questions

### Writing Good Issues

**Bug Reports** should include:
- Clear title
- Steps to reproduce
- Expected behavior
- Actual behavior
- System information (OS, compiler version)
- Error messages or logs

**Feature Requests** should include:
- Clear title
- Problem description
- Proposed solution
- Alternative solutions considered
- Why this would be useful

### Issue Labels

- `bug` - Something isn't working
- `enhancement` - New feature or request
- `documentation` - Improvements to documentation
- `good first issue` - Good for newcomers
- `help wanted` - Extra attention needed
- `question` - Further information requested

## Getting Help

Stuck? Don't hesitate to ask for help:

1. Check existing issues and discussions
2. Ask in the issue comments
3. Reach out to maintainers

## Recognition

Contributors will be recognized in:
- GitHub contributors page

---

Thank you for contributing to LabTest Archiver & Grader!

Questions? Open an issue and we'll help you out.
