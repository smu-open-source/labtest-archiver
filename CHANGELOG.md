# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Planned
- Miniz library integration for compression
- Full archiver implementation
- Full grader implementation
- Configuration file parsing
- CI/CD pipeline

## [0.1.0] - 2025-12-23

### Added
- Initial project structure and build system
- Basic command-line argument parsing for both tools
- Common utility functions and error handling
- Placeholder implementations for archiver
- Comprehensive project documentation:
  - README.md with setup instructions
  - CONTRIBUTING.md with contribution guidelines
  - DEVELOPMENT.md for developers
  - GETTING_STARTED.md for beginners
- GitHub templates:
  - Issue templates (bug report, feature request, question)
  - Pull request template
- Makefile with multiple build targets
- Project organized with proper C structure:
  - Header files in `include/`
  - Source files in `src/`
  - Documentation in `docs/`

### Project Structure
```
labtest-archiver/
├── include/          # Header files
├── src/              # Source files
├── lib/              # External libraries
├── build/            # Build artifacts
├── bin/              # Compiled binaries
├── docs/             # Documentation
└── .github/          # GitHub templates
```

### Notes
- This is the initial release establishing the project foundation
- Core functionality is stubbed out and ready for implementation
- Designed as an educational project for SMU Open Source Club
- All placeholder functions include TODO comments for contributors

---

## Release Types

- **Added** for new features
- **Changed** for changes in existing functionality
- **Deprecated** for soon-to-be removed features
- **Removed** for now removed features
- **Fixed** for any bug fixes
- **Security** in case of vulnerabilities

## Version Numbers

We use [Semantic Versioning](https://semver.org/):
- MAJOR version for incompatible API changes
- MINOR version for added functionality (backwards compatible)
- PATCH version for backwards compatible bug fixes

[Unreleased]: https://github.com/smu-open-source/labtest-archiver/compare/v0.1.0...HEAD
[0.1.0]: https://github.com/smu-open-source/labtest-archiver/releases/tag/v0.1.0
