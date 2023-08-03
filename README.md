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

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```
**Technical Skills Highlight:**

* **Threading and Mutex Management:** The programmer skillfully manages multiple threads (representing philosophers) and ensures thread safety using mutexes, preventing deadlocks and data races.
  * **Dynamic Memory Allocation:** Efficiently allocates memory for the philosopher and fork structures using `malloc`, ensuring proper memory management to avoid leaks.
  * **Time Management:** Implements functions to accurately track the simulation timeline, crucial for preventing philosopher starvation and ensuring smooth execution.
  * **Command-line Argument Handling:** Skillfully parses and processes command-line arguments, validating and extracting required parameters for the simulation.
  * **Debugging and Error Handling:** Implements error handling mechanisms and provides informative error messages, aiding in debugging and improving reliability.

**Soft Skills Highlight:**

- **Problem Solving:** Tackles the "Dining Philosophers Problem" with a thoughtful and well-designed approach, delivering an efficient and deadlock-free solution.
- **Organization and Code Structure:** The code is well-organized, with functions for specific tasks, improving code readability and maintainability. Separating responsibilities into functions enhances code modularity.
- **Communication:** Accompanies code with clear comments and informative print statements, showcasing effective communication and facilitating understanding.
- **Organization and Code Structure:** Follows a structured organization, using functions to separate responsibilities and improve code readability.
- **Time Management and Planning:** Demonstrates good time management and planning skills, crucial for managing threads, mutexes, and time-sensitive operations.x
- **Attention to Detail:** Pays careful attention to handling edge cases, validating input parameters, and ensuring accurate time calculations, resulting in a reliable and robust simulation.



## Disclaimer

This simulation is solely for educational purposes and aims to demonstrate synchronization and thread management concepts. The scenario and philosophy presented do not reflect real-life situations!


