
---

### 🔗 Pipex


# Pipex

Welcome to the Pipex project repository! This project is part of the 42 curriculum and involves recreating the functionality of shell pipelines. The program executes a series of commands, connecting them with pipes, similar to how Unix shells handle command chaining.

## Features

- **Command execution**: Runs multiple commands with input/output redirection.
- **Pipe management**: Connects commands using pipes to pass data between them.
- **Error handling**: Provides informative error messages for invalid commands or files.
- **Bonus features**: Includes support for handling multiple pipes and here-documents.

## Technologies Used

- **C**: Core programming language for implementing pipeline logic.
- **Unix system calls**: Utilizes `fork`, `execve`, `pipe`, and `dup2` for process and pipe management.

## Getting Started

To compile and run the program:

```bash
make
./pipex infile "cmd1" "cmd2" outfile
```

Replace infile, cmd1, cmd2, and outfile with appropriate filenames and commands.

i.e.  
./pipex infile.txt "grep 'Hello World'" "wc" outfile.txt  
./pipex file1.txt "cat" "sort" file2.txt

## Usage

The program reads from infile, executes cmd1, pipes its output to cmd2, and writes the final output to outfile.
