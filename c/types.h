
#ifndef ZAS_TYPES_H
#define ZAS_TYPES_H

#define PY_SSIZE_T_CLEAN

#include <Python.h>
#include <stdatomic.h>

typedef struct {
    PyObject_HEAD
    atomic_flag value;
} AtomicFlag;

typedef struct {
    PyObject_HEAD
    atomic_int value;
} AtomicInt;

typedef struct {
    PyObject_HEAD
    atomic_llong value;
} AtomicLong;

typedef struct {
    PyObject_HEAD
    atomic_ullong value;
} AtomicULong;



#endif //ZAS_TYPES_H
