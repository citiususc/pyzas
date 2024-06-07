
#ifndef ZAS_DOC_H
#define ZAS_DOC_H

#include "types.h"

PyDoc_STRVAR(
        pyzas_doc,
        "Performing python atomic integer operations with the speed and efficiency of a zas!");

PyDoc_STRVAR(
        atomic_flag_doc,
        "An atomic boolean type\n"
        "\n"
        "AtomicFlag(/)");

PyDoc_STRVAR(
        atomic_int_doc,
        "An atomic int type\n"
        "\n"
        "AtomicInt(/, value, *)\n"
        "\n"
        "Parameters\n"
        "----------\n"
        "value : An integer value to initialize the AtomicInt with. Defaults to 0 if not provided");

PyDoc_STRVAR(
        atomic_long_doc,
        "An atomic 64-bytes int type\n"
        "\n"
        "AtomicInt(/, value, *)\n"
        "\n"
        "Parameters\n"
        "----------\n"
        "value : An integer value to initialize the AtomicLong with. Defaults to 0 if not provided");

PyDoc_STRVAR(
        atomic_ulong_doc,
        "An atomic 64-bytes unsigned int type\n"
        "\n"
        "AtomicULong(/, value, *)\n"
        "\n"
        "Parameters\n"
        "----------\n"
        "value : An integer value to initialize the AtomicULong with. Defaults to 0 if not provided");

PyDoc_STRVAR(
        test_and_set_doc,
        "test_and_set(self, /)\n"
        "--\n"
        "\n"
        "Sets the atomic_flag to true and returns the old value\n"
        "\n"
        "Return value\n"
        "----------\n"
        "The old value");

PyDoc_STRVAR(
        clear_doc,
        "clear(self, /)\n"
        "--\n"
        "\n"
        "Sets the atomic_flag to false");

PyDoc_STRVAR(
        spin_lock,
        "spin_lock(self, /)\n"
        "--\n"
        "\n"
        "Causes a thread trying to acquire a lock to simply wait in a loop (\"spin\")");

PyDoc_STRVAR(
        spin_unlock,
        "spin_unlock(self, /)\n"
        "--\n"
        "\n"
        "Releases the lock");

PyDoc_STRVAR(
        free_lock_level_doc,
        "test_and_set(self, /)\n"
        "--\n"
        "\n"
        "Determines if the atomic object is implemented lock-free:\n"
        " - 0 for the built-in atomic types that are never lock-free\n"
        " - 1 for the built-in atomic types that are sometimes lock-free\n"
        " - 2 for the built-in atomic types that are always lock-free");

PyDoc_STRVAR(
        load_doc,
        "load(self, /)\n"
        "--\n"
        "\n"
        "Reads a value from an atomic object");

PyDoc_STRVAR(
        store_doc,
        "store(self, value, /)\n"
        "--\n"
        "\n"
        "Stores a value in an atomic object\n"
        "\n"
        "Parameters\n"
        "----------\n"
        "value : An integer value to store in an atomic object");

PyDoc_STRVAR(
        exchange_doc,
        "exchange(self, value, /)\n"
        "--\n"
        "\n"
        "Atomically replaces the value in an atomic object\n"
        "\n"
        "Parameters\n"
        "----------\n"
        "value : An integer value to replace the current value in an atomic object\n"
        "\n"
        "Return value\n"
        "----------\n"
        "The value held previously by the atomic object");

PyDoc_STRVAR(
        fetch_add_doc,
        "fetch_add(self, value, /)\n"
        "--\n"
        "\n"
        "Performs atomic addition\n"
        "\n"
        "Parameters\n"
        "----------\n"
        "value : An integer to add to the atomic object\n"
        "\n"
        "Return value\n"
        "----------\n"
        "The value immediately preceding the effects of this function");

PyDoc_STRVAR(
        fetch_sub_doc,
        "fetch_sub(self, value, /)\n"
        "--\n"
        "\n"
        "Performs atomic subtraction\n"
        "\n"
        "Parameters\n"
        "----------\n"
        "value : An integer to sub to the atomic object\n"
        "\n"
        "Return value\n"
        "----------\n"
        "The value immediately preceding the effects of this function");

PyDoc_STRVAR(
        compare_exchange_doc,
        "compare_exchange(self, expected, desired/)\n"
        "--\n"
        "\n"
        "Swaps a value with an atomic object if the old value is what is expected, otherwise reads the old value\n"
        "\n"
        "Parameters\n"
        "----------\n"
        "expected : Value expected to be found in the atomic object\n"
        "desired  : Value to store in the atomic object if it is as expected \n"
        "\n"
        "Return value\n"
        "----------\n"
        "The value immediately preceding the effects of this function");

#endif //ZAS_DOC_H
