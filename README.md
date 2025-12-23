# LabTest Archiver & Grader

A lightweight toolset for archiving and grading coding lab test submissions, built in C using the miniz compression library.

## About

This project provides two command-line tools designed to streamline the process of collecting and grading student coding assignments:

- **labtest-archiver**: Archive student submissions into compressed packages
- **labtest-grader**: Automatically grade archived submissions based on test criteria

Built as an educational open source project for students learning C programming and collaborative software development.

## Features

- Fast and efficient compression using miniz
- Simple command-line interface
- Beginner-friendly codebase for learning C

## Project Structure

```
labtest-archiver/
├── src/              # Source files (.c)
├── include/          # Header files (.h)
├── lib/              # External libraries (miniz)
├── build/            # Build artifacts (generated)
├── bin/              # Compiled binaries (generated)
├── docs/             # Documentation
└── .github/          # GitHub templates
```

## Prerequisites

Before building this project, you'll need:

- **GCC** or **Clang** compiler
- **Make** build system
- **Git** for version control

### Installing Prerequisites

**On macOS:**
```bash
xcode-select --install
```

**On Linux (Ubuntu/Debian):**
```bash
sudo apt-get update
sudo apt-get install build-essential git
```

**On Linux (Fedora/RHEL):**
```bash
sudo dnf install gcc make git
```

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/yourusername/labtest-archiver.git
cd labtest-archiver
```

### 2. Build the Project

```bash
make
```

This will compile both binaries and place them in the `bin/` directory.

### 3. Run the Tools

**Archive submissions:**
```bash
./bin/labtest-archiver -i <input-directory> -o <output-file.zip>
```

**Grade submissions:**
```bash
./bin/labtest-grader -i <archive-file.zip> -c <config-file>
```

## Building

### Available Make Targets

- `make` or `make all` - Build both binaries
- `make archiver` - Build only the archiver
- `make grader` - Build only the grader
- `make clean` - Remove build artifacts and binaries
- `make rebuild` - Clean and rebuild everything
- `make help` - Show available targets

### Debug Build

For development with debugging symbols:
```bash
make DEBUG=1
```

## Contributing

We welcome contributions from students and developers of all skill levels! This project is specifically designed as a learning opportunity for freshmen and new open source contributors.

Please read our [CONTRIBUTING.md](CONTRIBUTING.md) guide to get started.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Support

If you encounter any issues or have questions:

1. Check the [documentation](docs/)
2. Search [existing issues](https://github.com/yourusername/labtest-archiver/issues)
3. Open a new issue with the appropriate template

## Acknowledgments

- Uses [miniz](https://github.com/richgel999/miniz) for compression
- Created as an educational project for the SMU Open Source Club

## Roadmap

- [ ] Basic archiving functionality
- [ ] Basic grading functionality
- [ ] Configuration file support
- [ ] Parallel processing
- [ ] Detailed grading reports
- [ ] Plugin system for custom graders

---

Made with care by the SMU Open Source Club
