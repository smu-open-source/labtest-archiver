# Getting Started Guide

Welcome to the LabTest Archiver & Grader project! This guide will help you make your first contribution.

## For Complete Beginners

Don't worry if you're new to:
- C programming
- Git and GitHub
- Open source
- Command line

We've all been there! This project is designed to help you learn.

## Step 1: Set Up Your Environment

### On macOS

```bash
# Install Xcode Command Line Tools (includes GCC)
xcode-select --install
```

### On Linux (Ubuntu/Debian)

```bash
# Install build tools
sudo apt-get update
sudo apt-get install build-essential git
```

### On Windows

We recommend using WSL (Windows Subsystem for Linux):
1. Install WSL2
2. Follow the Linux instructions above

## Step 2: Get the Code

### Fork the Repository

1. Go to the GitHub repository page
2. Click the "Fork" button in the top right
3. This creates your own copy

### Clone Your Fork

```bash
# Replace YOUR-USERNAME with your GitHub username
git clone https://github.com/YOUR-USERNAME/labtest-archiver.git
cd labtest-archiver
```

### Add Upstream Remote

```bash
git remote add upstream https://github.com/ORIGINAL-OWNER/labtest-archiver.git
```

## Step 3: Build the Project

```bash
# Build everything
make

# You should see output like:
# Compiling src/common.c...
# Compiling src/archiver.c...
# ...
# Built: bin/labtest-archiver
# Built: bin/labtest-grader
```

If you see errors, check:
- Do you have GCC installed? Run `gcc --version`
- Are you in the project directory? Run `pwd`

## Step 4: Test the Build

```bash
# Test the archiver
./bin/labtest-archiver --help

# Test the grader
./bin/labtest-grader --help
```

You should see help messages. Congrats, it works!

## Step 5: Explore the Code

### Start with the Headers

Open `include/common.h` in your editor:

```bash
# Using your favorite editor:
code include/common.h      # VS Code
vim include/common.h       # Vim
nano include/common.h      # Nano
```

Read through the comments to understand what each function does.

### Look at the Implementation

Open `src/common.c` to see how functions are implemented.

### Understand the Main Flow

Check out `src/archiver_main.c` - it's short and shows the main program flow.

## Step 6: Find Something to Work On

### Look for "Good First Issue" Labels

On GitHub, filter issues by the `good first issue` label. These are:
- Well-defined
- Not too complex
- Good for learning

### Start with Documentation

Not comfortable with code yet? Try:
- Fixing typos
- Improving README
- Writing tutorials

### Start with Simple TODOs

Search the code for `TODO` comments:

```bash
grep -r "TODO" src/ include/
```

These are placeholders for features that need implementation.

## Step 7: Make Your First Change

### Create a Branch

```bash
# Create and switch to a new branch
git checkout -b fix/my-first-fix
```

### Make a Small Change

Let's add a simple feature - a new function in `common.c`:

1. Open `include/common.h`
2. Add a function declaration:
```c
/**
 * @brief Say hello to a user
 * @param name User's name
 */
void say_hello(const char *name);
```

3. Open `src/common.c`
4. Implement the function:
```c
void say_hello(const char *name) {
    if (name != NULL) {
        printf("Hello, %s! Welcome to LabTest Archiver!\n", name);
    }
}
```

5. Build to test:
```bash
make clean && make
```

### Commit Your Change

```bash
# Stage your changes
git add include/common.h src/common.c

# Commit with a message
git commit -m "feat: Add say_hello function for user greeting"

# Push to your fork
git push origin fix/my-first-fix
```

## Step 8: Create a Pull Request

1. Go to your fork on GitHub
2. Click "Pull Requests" tab
3. Click "New Pull Request"
4. Click "Create Pull Request"
5. Fill in the template:
   - Describe what you changed
   - Why you changed it
   - How to test it
6. Submit!

## Common Issues and Solutions

### "make: command not found"

Install build tools (see Step 1).

### "Permission denied"

Make sure files are executable:
```bash
chmod +x bin/labtest-archiver
```

### Compilation Errors

Read the error message carefully. Common issues:
- Missing semicolon
- Undefined function (forgot to include header?)
- Type mismatch

### Git Conflicts

```bash
# Update your branch with latest changes
git checkout main
git pull upstream main
git checkout your-branch
git rebase main
```

## Learning Resources

### C Programming

- [Learn C](https://www.learn-c.org/)
- [C Programming Tutorial](https://www.tutorialspoint.com/cprogramming/)
- Our `docs/DEVELOPMENT.md` guide

### Git and GitHub

- [GitHub Hello World](https://guides.github.com/activities/hello-world/)
- [Git Basics](https://git-scm.com/book/en/v2/Getting-Started-Git-Basics)
- [How to Make a Pull Request](https://www.freecodecamp.org/news/how-to-make-your-first-pull-request-on-github/)

### Command Line

- [Command Line Crash Course](https://developer.mozilla.org/en-US/docs/Learn/Tools_and_testing/Understanding_client-side_tools/Command_line)
- [Linux Command Line Basics](https://ubuntu.com/tutorials/command-line-for-beginners)

## Getting Help

### In the Code

- Read comments in header files
- Check `docs/` directory

### From the Community

- Open an issue with the `question` label
- Ask in your PR comments
- Reach out to maintainers

### Remember

- **No question is too basic**
- **Making mistakes is how we learn**
- **Everyone was a beginner once**
- **The community is here to help**

## Next Steps

After your first contribution:

1. **Tackle bigger issues**: Look for issues without the `good first issue` label
2. **Add features**: Implement TODO items
3. **Help others**: Answer questions from other beginners
4. **Review PRs**: Learn by reading others' code
5. **Write documentation**: Share what you learned

## Celebrate!

You're now an open source contributor!

Every contribution, no matter how small, makes a difference. Thank you for being part of the SMU Open Source Club community.

---

Questions? Open an issue and we'll help you out!
