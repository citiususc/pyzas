
#ifndef ZAS_METHODS_H
#define ZAS_METHODS_H

#include "types.h"

PyObject *atomicInt_free_lock_level(PyObject *self, PyObject *arg);

PyObject *atomicLong_free_lock_level(PyObject *self, PyObject *arg);

PyObject *atomicULong_free_lock_level(PyObject *self, PyObject *arg);


int atomicFlag_init(AtomicFlag *self, PyObject *args, PyObject *kwds);

int atomicInt_init(AtomicInt *self, PyObject *args, PyObject *kwds);

int atomicLong_init(AtomicLong *self, PyObject *args, PyObject *kwds);

int atomicULong_init(AtomicULong *self, PyObject *args, PyObject *kwds);


PyObject *atomicInt_load(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicLong_load(AtomicLong *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicULong_load(AtomicULong *self, PyObject *const *args, Py_ssize_t nargs);


PyObject *atomicInt_store(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicLong_store(AtomicLong *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicULong_store(AtomicULong *self, PyObject *const *args, Py_ssize_t nargs);


PyObject *atomicInt_exchange(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicLong_exchange(AtomicLong *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicULong_exchange(AtomicULong *self, PyObject *const *args, Py_ssize_t nargs);


PyObject *atomicInt_fetch_add(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicLong_fetch_add(AtomicLong *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicULong_fetch_add(AtomicULong *self, PyObject *const *args, Py_ssize_t nargs);


PyObject *atomicInt_fetch_sub(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicLong_fetch_sub(AtomicLong *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicULong_fetch_sub(AtomicULong *self, PyObject *const *args, Py_ssize_t nargs);


PyObject *atomicInt_compare_exchange(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicLong_compare_exchange(AtomicLong *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicULong_compare_exchange(AtomicULong *self, PyObject *const *args, Py_ssize_t nargs);


PyObject *atomicFlag_test_and_set(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicFlag_clear(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicFlag_spin_lock(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs);

PyObject *atomicFlag_spin_unlock(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs);

#endif //ZAS_METHODS_H
