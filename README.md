# PyZas!: A Python library for atomic integer operations

**PyZas** is a Python library designed for performing atomic integer operations with the speed and efficiency of a zas!
(Inspired by the sudden impact sound "zas!"). PyZas ensures your calculations are executed atomically and safely. Perfect 
for scenarios requiring quick, thread-safe manipulations.

## Installation

You can install PyZas via pip:

```bash
pip install pyzas
```
## Usage

The PyZas module implements the following atomic types:

* **AtomicInt**: Basic signed number
* **AtomicLong**:  Signed number of 64 bits
* **AtomicULong**: Unsigned number of 64 bits

The three types implement the following functions:

* **free_lock_level() -> int**: indicates that the given atomic type is native lock-free
* **load() -> int**: reads a value from an atomic object
* **store(int)**: stores a value in an atomic object
* **exchange(int) -> int**: stores a value in an atomic object
* **fetch_add(int) -> int**: atomic addition and returns the value obj held previously
* **fetch_sub(int) -> int**: atomic subtraction and returns the value obj held previously
* **compare_exchange(int,int) -> int**: swaps a value with an atomic object if the old value is what is expected, otherwise reads the old value

Module also implements **AtomicFlag** with support for spinlock:

* **test_and_set() -> bool**: sets an atomic flag to true and returns the old value
* **clear()**: sets an atomic flag to false
* **spin_lock()**: causes a thread trying to acquire a lock to simply wait in a loop ("spin")
* **spin_unlock()**: releases the lock

## Example

```python
import pyzas

n = pyzas.AtomicInt(0)
n.fetch_add(1)
print(n.load())
```