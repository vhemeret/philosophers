# 🍝 Philosophers

## 📖 About

"Philosophers" is a project that tackles the classic dining philosophers problem, introducing the basics of threading a process and the concepts of mutexes.

## 🎯 Objectives

- Understand and implement multi-threading
- Learn about mutexes and their use in preventing race conditions
- Solve synchronization problems in concurrent programming
- Simulate the dining philosophers problem

## 🛠️ Features

- Simulate a specified number of philosophers sitting at a round table
- Manage shared resources (forks) between philosophers
- Implement different states for philosophers: eating, thinking, sleeping
- Handle death conditions based on starvation time
- Provide detailed logs of state changes

## 🚀 Usage

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Arguments

- `number_of_philosophers`: The number of philosophers and forks
- `time_to_die` (in milliseconds): Maximum time a philosopher can spend without eating before dying
- `time_to_eat` (in milliseconds): Time it takes for a philosopher to eat
- `time_to_sleep` (in milliseconds): Time a philosopher spends sleeping
- `number_of_times_each_philosopher_must_eat` (optional): If specified, simulation stops when all philosophers have eaten this many times

## ⚙️ Installation

1. Clone the repository:
   ```
   git clone https://github.com/your-username/philosophers.git
   ```
2. Navigate to the project folder:
   ```
   cd philosophers
   ```
3. Compile the project:
   ```
   make
   ```

---

Made with ❤️ as part of the 42 School curriculum.