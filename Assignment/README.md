# File Hierarchy

## Assignment

- `README.md` file describing the content’s organization.
- Two subfolders:

### Part1
- First part of the assignment.
  - Contains:
    - `CMakeLists.txt`: CMake configuration file for Part1.
    - `main.c`: Main code file for the first part.

### Part2
- Second part of the assignment.
  - Contains:
    - `CMakeLists.txt`: CMake configuration file for Part2.
    - `GenSetInterface.c`: Executable file testing the functionality of the Part2.
    - `GenSetLibrary`: Subfolder.
      - Contains:
        - `GenSet.c`: Source code file for GenSet library.
        - `GenSet.h`: Header file for GenSet library.
      - Shared library is generated from `GenSet.c` and `GenSet.h`.
    - `TextFiles`: Subfolder.
      - Contains 6 files testing functionality of export() function:
        - `chars.txt`
        - `doubles.txt`
        - `floats.txt`
        - `ints.txt`
        - `movies.txt`
        - `strings.txt`


