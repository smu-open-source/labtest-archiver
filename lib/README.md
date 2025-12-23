# External Libraries

This directory contains third-party libraries used by the project.

## miniz

**Version**: 3.1.0
**License**: MIT
**Source**: https://github.com/richgel999/miniz
**Location**: `lib/miniz/`
**Files**: `miniz.h`, `miniz.c`

## Adding New Libraries

If you need to add another library:

1. Create a subdirectory: `lib/library-name/`
2. Add the source files
3. Update this README with:
   - Version and source
   - License information
   - Why it's included
   - How to update it
4. Update the Makefile if needed
5. Update `.gitignore` if there are build artifacts

## Build artifacts

The `lib/` directory should contain **source code only**. Any compiled files (`.o`, `.a`, etc.) should go in `build/` and are already ignored by git.
