# PyZas!: A Python library for atomic integer operations

**PyZas** is a Python library designed for performing atomic integer operations with the speed and efficiency of a zas!
(Inspired by the sudden impact sound 'zas', a Spanish onomatopoeia). PyZas ensures your calculations are executed atomically and safely. Perfect 
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

## Performance Test

```python
from multiprocessing.pool import ThreadPool
import threading
import time
import sys

import pyzas.pyzas as pyzas


def main(threads, its):
    e = 0
    atomic_e = pyzas.AtomicInt()
    lock = threading.Lock()

    def test_lock(i):
        nonlocal e
        with lock:
            e = e + 1

    def test_atomic(i):
        atomic_e.fetch_add(1)

    start = time.time()
    with ThreadPool(threads) as p:
        list(p.map(test_lock, range(its)))
    print("Testing with lock", e, time.time() - start)

    start = time.time()
    with ThreadPool(threads) as p:
        list(p.map(test_atomic, range(its)))
    print("Testing atomic   ", atomic_e.load(), time.time() - start)


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print(f"Use: python3 {sys.argv[0]} [threads] [its]", file=sys.stderr)
        exit(-1)
    main(int(sys.argv[1]), int(sys.argv[2]))
```

## Build from sources

Library is built using Poetry:

```bash
poetry build
```

Or to install the library with pip:

```bash
pip install .
```

*PYZAS_CFLAGS* environment variable can be used to add compilation options. 

```bash
export PYZAS_CFLAGS="-O2"
poetry build
```

### Most common errors

#### - Visual Studio still has experimental support for atomics, so we need to enable it to compile the code.

```bash
SET PYZAS_CFLAGS=/std:c11 /experimental:c11atomics
poetry build # or pip install .
```

#### - cp313 version (with GIL) is being compiled instead of the cp313t version (free-threaded)

If your version has been compiled with GIL, even if you have the free-threaded binaries, it's possible that the build 
is done for the GIL version. The build tools are still experimental, and don't have a way to fix the compile  option, 
so we have to do it manually.

```bash
export PYZAS_FIX_GIL=1 # Linux or MacOS
SET PYZAS_FIX_GIL=1 # Windows
```

If you want to install using the wheel, you'll need to add **t** after the version number. For example, 
*pyzas-1.0-cp313-cp313-win_amd64.whl* should be *pyzas-1.0-cp313-cp313t-win_amd64.whl*.

