# Philosophers with Threads and Mutexes

## Introduction

Welcome to the Philosophers Simulation! This program simulates a classic synchronization problem known as the "Dining Philosophers Problem." The goal is to implement a solution using threads and mutexes to ensure that the philosophers can eat without experiencing deadlocks or starvation.

## Problem Description

The simulation involves one or more philosophers sitting at a round table. In the center of the table, there is a large bowl of spaghetti. The philosophers have three activities: eating, thinking, and sleeping. They alternate between these activities, ensuring that they do not eat, think, or sleep simultaneously.

## Rules and Constraints

- Each philosopher is represented as a thread.
- There is one fork between each pair of philosophers. If there are several philosophers, each philosopher has a fork on their left side and another on their right side.
- To avoid duplication of forks, the state of each fork must be protected using a mutex.
- The philosophers must follow the specified time intervals for eating, sleeping, and thinking.
- If a philosopher does not start eating within `time_to_die` milliseconds after their last meal or the beginning of the simulation, they die of starvation.
- The simulation stops either when a philosopher dies (if `number_of_times_each_philosopher_must_eat` is not provided) or when all philosophers have eaten at least `number_of_times_each_philosopher_must_eat` times.

## Program Execution

The program should be executed with the following command-line arguments:

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: The number of philosophers, which also corresponds to the number of forks.
- `time_to_die`: Time in milliseconds. If a philosopher doesn't start eating within this time after their last meal, they die.
- `time_to_eat`: Time in milliseconds for a philosopher to eat. During this time, they must hold two forks.
- `time_to_sleep`: Time in milliseconds for a philosopher to sleep.
- `number_of_times_each_philosopher_must_eat` (optional): If provided, the simulation stops when all philosophers have eaten at least this many times.

## Log Format

The program should display the state changes of the philosophers in the following format:

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

Replace `timestamp_in_ms` with the current timestamp in milliseconds and `X` with the philosopher number.

## Implementation

- Your implementation should adhere to the global rules specified earlier.
- Use the provided Makefile to compile the program.
- External functions such as `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, and `pthread_mutex_unlock` are allowed.
- You are not allowed to use the Libft library.

## Bonus Part (Optional)

If you choose to attempt the bonus part, you should follow the same rules and constraints mentioned in the mandatory part but extend your implementation with additional features or optimizations.

## Disclaimer

This simulation is solely for educational purposes and aims to demonstrate synchronization and thread management concepts. The scenario and philosophy presented do not reflect real-life situations. Please ensure that philosophers avoid dying!

Enjoy the challenge and have fun implementing the Philosophers Simulation with threads and mutexes!