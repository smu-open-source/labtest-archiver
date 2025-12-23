# Documentation

Welcome to the LabTest Archiver & Grader documentation!

## For New Contributors

If you're new to this project, start here:

1. **[Getting Started Guide](GETTING_STARTED.md)** - Your first steps with the project
   - Setting up your development environment
   - Building the project
   - Making your first contribution
   - Common issues and solutions

2. **[Contributing Guidelines](../CONTRIBUTING.md)** - How to contribute
   - Development workflow
   - Coding standards
   - Commit guidelines
   - Pull request process

## For Developers

If you're ready to dive into development:

1. **[Development Guide](DEVELOPMENT.md)** - Technical details for developers
   - Project structure explained
   - Building and debugging
   - Code style and conventions
   - Adding new features
   - Testing and performance

2. **[Examples](../examples/)** - Usage examples
   - Basic archiving
   - Basic grading
   - Complete workflows
   - Configuration files

## Project Documentation

- **[README](../README.md)** - Main project overview
  - Features
  - Prerequisites
  - Installation
  - Quick start
  - Usage

- **[CHANGELOG](../CHANGELOG.md)** - Version history
  - Release notes
  - New features
  - Bug fixes
  - Breaking changes

## Quick Reference

### Building the Project

```bash
make              # Build everything
make archiver     # Build only archiver
make grader       # Build only grader
make clean        # Clean build artifacts
make DEBUG=1      # Build with debug symbols
```

### Project Structure

```
labtest-archiver/
├── include/      # Header files (.h)
├── src/          # Source files (.c)
├── lib/          # External libraries
├── build/        # Build artifacts (generated)
├── bin/          # Compiled binaries (generated)
├── docs/         # Documentation (you are here!)
├── examples/     # Usage examples
└── .github/      # GitHub templates
```

### Common Commands

```bash
# Format code
make format

# Run archiver
./bin/labtest-archiver -i <dir> -o <file.zip>

# Run grader
./bin/labtest-grader -i <file.zip> -c <config.json>

# Check for memory leaks
make memcheck-archiver
make memcheck-grader
```

## GitHub Resources

- **[Issue Templates](../.github/ISSUE_TEMPLATE/)** - Report bugs or request features
  - Bug report
  - Feature request
  - Questions

- **[Pull Request Template](../.github/PULL_REQUEST_TEMPLATE.md)** - Submit changes

## Learning Resources

### C Programming

- [Learn C](https://www.learn-c.org/)
- [C Programming Tutorial](https://www.tutorialspoint.com/cprogramming/)
- [GNU C Reference Manual](https://www.gnu.org/software/gnu-c-manual/)

### Git and GitHub

- [GitHub Hello World](https://guides.github.com/activities/hello-world/)
- [Git Basics](https://git-scm.com/book/en/v2/Getting-Started-Git-Basics)
- [First Contributions Guide](https://github.com/firstcontributions/first-contributions)

### Open Source

- [How to Contribute to Open Source](https://opensource.guide/how-to-contribute/)
- [Open Source Best Practices](https://opensource.guide/best-practices/)

## Getting Help

Need help? Here's how to get it:

1. **Check the docs** - You're in the right place!
2. **Search issues** - Someone might have asked already
3. **Ask a question** - Open an issue with the `question` label
4. **Join discussions** - Participate in GitHub discussions
5. **Contact maintainers** - Reach out directly if needed

## Contributing to Documentation

Found a typo? Want to improve our docs? Great!

Documentation improvements are some of the most valuable contributions:
- Fix typos or unclear wording
- Add examples
- Improve explanations
- Translate to other languages
- Add diagrams or visuals

Just submit a pull request with your changes!

## Documentation Standards

When writing or updating documentation:

- Use clear, simple language
- Include examples where helpful
- Keep beginners in mind
- Use proper Markdown formatting
- Check spelling and grammar
- Test all code examples

## Additional Resources

- Project Wiki (if available)
- API Documentation (coming soon)
- Video Tutorials (coming soon)
- Blog Posts (coming soon)

---

**Questions?** Open an issue and we'll help you out!

**Found an error?** Please let us know or submit a fix!

Thank you for being part of the SMU Open Source Club community!
