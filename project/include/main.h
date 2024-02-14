#pragma once

// Standart Includes
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

// System Includes
#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <sys/user.h>

// My Includes
#include "tracee.h"
#include "tracer.h"

// SYSCALL MAPPING
#define SYS_CUSTOM_write 0x1337
