## Anti-debug

This Project is about creating a challenging and an extremely hard to debug binary, while leveraging multiple anti-reversing techniques including a custom made anti-debugger.

## Usage
To build the binary run :
```sh
make
```

To clean the object files and dependencies run :
```sh
make clean
```

To clean and rebuild the project run:
```sh
make re
```

## Progress

- :white_check_mark: Implenting the Tracer and the Tracee.
- :white_check_mark: Building a custom libc with modified syscalls.
- :white_large_square: regs/args scrambling.
- :white_large_square: args encrypting.
- :white_large_square: dynamic randomisation of syscall numbers.
- :white_large_square: Compilying `ptrace` code with custom built OLLVM.
