# PyZas!: A Python library for atomic integer operations

**PyZas** is a Python library designed for performing atomic integer operations with the speed and efficiency of a zas!
(Inspired by the sudden impact sound "zas" spanish onomatopoeia)). PyZas ensures your calculations are executed atomically and safely. Perfect 
for scenarios requiring quick, thread-safe manipulations.

## Installation

You can install PyZas via pip:

```bash
pip install pyzas
```
## Usage

The PyZas module implements the following atomic types:

* **AtomicInt**: An atomic int type
* **AtomicLong**:  An atomic 64-bytes int type
* **AtomicULong**: An atomic 64-bytes unsigned int type

The three types implement the following functions:

* **free_lock_level() -> int**: Determines if the atomic object is implemented lock-free
* **load() -> int**: Reads a value from an atomic object
* **store(int)**: Stores a value in an atomic object
* **exchange(int) -> int**: Atomically replaces the value in an atomic object
* **fetch_add(int) -> int**: Performs atomic addition
* **fetch_sub(int) -> int**: Performs atomic subtraction
* **compare_exchange(int, int) -> int**: Swaps a value with an atomic object if the old value is what is expected, otherwise reads the old value

Module also implements **AtomicFlag** with support for spinlock:

* **test_and_set() -> bool**: sets an atomic flag to true and returns the old value
* **clear()**: Sets the atomic_flag to false
* **spin_lock()**: Causes a thread trying to acquire a lock to simply wait in a loop ("spin")
* **spin_unlock()**: Releases the lock

For more details:

```python
help(pyzas)
```

## Example

```python
import pyzas

n = pyzas.AtomicInt(0)
n.fetch_add(1)
print(n.load())
```