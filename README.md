# Dining-Philosophers-Problem
# Experiment 6: Dining Philosophers Problem

## Aim
To implement the Dining Philosophers Problem using threads and mutex locks in C.

## Description
The Dining Philosophers Problem is a classic Operating Systems problem that demonstrates process synchronization. Philosophers alternate between thinking and eating. Each philosopher needs access to shared forks to eat.

Mutex locks are used to control access to the forks and prevent multiple threads from accessing the same fork simultaneously.

## Algorithm
1. Start the program.
2. Create threads for the philosophers.
3. Initialize mutex locks for the forks.
4. Each philosopher thinks and attempts to pick up the required forks.
5. The philosopher eats after acquiring both forks.
6. Release the forks after eating.
7. Repeat the process and terminate the threads.
8. Stop the program.

## Files
- `experiment6_dining_philosophers.c` — C program.
- `experiment6_dining_philosophers_output.png` — Output screenshot from the lab manual.

## Requirements
- GCC compiler
- Linux operating system
- POSIX threads (`pthread`)

## Compilation
```bash
gcc experiment6_dining_philosophers.c -o experiment6 -pthread
```

## Execution
```bash
./experiment6
```

## Output
Refer to `experiment6_dining_philosophers_output.png` for the output screenshot from the lab manual.

## Result
The Dining Philosophers Problem is implemented using threads and mutex locks to demonstrate process synchronization.
