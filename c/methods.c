
#include "methods.h"

// to ONLY debug in python 3.12 because 3.13 is still beta
#if PY_MINOR_VERSION < 13
    int PyLong_AsInt(PyObject *obj){
        return (int) PyLong_AsLong(obj);
    }
#endif


PyObject *atomicInt_free_lock_level(PyObject *self, PyObject *arg) {
    return PyLong_FromLong(ATOMIC_INT_LOCK_FREE);
}

PyObject *atomicLong_free_lock_level(PyObject *self, PyObject *arg) {
    return PyLong_FromLong(ATOMIC_LLONG_LOCK_FREE);
}

PyObject *atomicULong_free_lock_level(PyObject *self, PyObject *arg) {
    return PyLong_FromLong(ATOMIC_LLONG_LOCK_FREE);
}


int atomicFlag_init(AtomicFlag *self, PyObject *args, PyObject *kwds) {
    atomic_flag_clear(&self->value);
    return 0;
}

int atomicInt_init(AtomicInt *self, PyObject *args, PyObject *kwds) {
    int tmp = 0;
    if (!PyArg_ParseTuple(args, "|i", args, &tmp)) {
        return -1;
    }

    atomic_store(&self->value, tmp);
    return 0;
}

int atomicLong_init(AtomicLong *self, PyObject *args, PyObject *kwds) {
    long long int tmp = 0;
    if (!PyArg_ParseTuple(args, "|L", args, &tmp)) {
        return -1;
    }

    atomic_store(&self->value, tmp);
    return 0;
}

int atomicULong_init(AtomicULong *self, PyObject *args, PyObject *kwds) {
    unsigned long long int tmp = 0;
    if (!PyArg_ParseTuple(args, "|K", args, &tmp)) {
        return -1;
    }

    atomic_store(&self->value, tmp);
    return 0;
}


PyObject *atomicInt_load(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs) {
    return PyLong_FromLong(atomic_load(&self->value));
}

PyObject *atomicLong_load(AtomicLong *self, PyObject *const *args, Py_ssize_t nargs) {
    return PyLong_FromLongLong(atomic_load(&self->value));
}

PyObject *atomicULong_load(AtomicULong *self, PyObject *const *args, Py_ssize_t nargs) {
    return PyLong_FromUnsignedLongLong(atomic_load(&self->value));
}


PyObject *atomicInt_store(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 0) {
        atomic_store(&self->value, PyLong_AsInt(args[0]));
    }
    Py_RETURN_NONE;
}

PyObject *atomicLong_store(AtomicLong *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 0) {
        atomic_store(&self->value, PyLong_AsLongLong(args[0]));
    }
    Py_RETURN_NONE;
}

PyObject *atomicULong_store(AtomicULong *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 0) {
        atomic_store(&self->value, PyLong_AsUnsignedLongLong(args[0]));
    }
    Py_RETURN_NONE;
}

PyObject *atomicInt_exchange(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 0) {
        return PyLong_FromLong(atomic_exchange(&self->value, PyLong_AsInt(args[0])));
    }
    Py_RETURN_NONE;
}

PyObject *atomicLong_exchange(AtomicLong *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 0) {
        return PyLong_FromLongLong(atomic_exchange(&self->value, PyLong_AsLongLong(args[0])));
    }
    Py_RETURN_NONE;
}

PyObject *atomicULong_exchange(AtomicULong *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 0) {
        return PyLong_FromUnsignedLongLong(atomic_exchange(&self->value, PyLong_AsUnsignedLongLong(args[0])));
    }
    Py_RETURN_NONE;
}


PyObject *atomicInt_fetch_add(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 0) {
        return PyLong_FromLong(atomic_fetch_add(&self->value, PyLong_AsInt(args[0])));
    }
    Py_RETURN_NONE;
}

PyObject *atomicLong_fetch_add(AtomicLong *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 0) {
        return PyLong_FromLongLong(atomic_fetch_add(&self->value, PyLong_AsLongLong(args[0])));
    }
    Py_RETURN_NONE;
}

PyObject *atomicULong_fetch_add(AtomicULong *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 0) {
        return PyLong_FromUnsignedLongLong(atomic_fetch_add(&self->value, PyLong_AsUnsignedLongLong(args[0])));
    }
    Py_RETURN_NONE;
}


PyObject *atomicInt_fetch_sub(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 0) {
        return PyLong_FromLong(atomic_fetch_sub(&self->value, PyLong_AsInt(args[0])));
    }
    Py_RETURN_NONE;
}

PyObject *atomicLong_fetch_sub(AtomicLong *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 0) {
        return PyLong_FromLongLong(atomic_fetch_sub(&self->value, PyLong_AsLongLong(args[0])));
    }
    Py_RETURN_NONE;
}

PyObject *atomicULong_fetch_sub(AtomicULong *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 0) {
        return PyLong_FromUnsignedLongLong(atomic_fetch_sub(&self->value, PyLong_AsUnsignedLongLong(args[0])));
    }
    Py_RETURN_NONE;
}

PyObject *atomicInt_compare_exchange(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 1) {
        int tmp = PyLong_AsInt(args[0]);
        return PyLong_FromLong(atomic_compare_exchange_strong(&self->value, &tmp, PyLong_AsInt(args[0])));
    }
    Py_RETURN_NONE;
}

PyObject *atomicLong_compare_exchange(AtomicLong *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 1) {
        long long int tmp = PyLong_AsLongLong(args[0]);
        return PyLong_FromLongLong(atomic_compare_exchange_strong(&self->value, &tmp, PyLong_AsLongLong(args[0])));
    }
    Py_RETURN_NONE;
}

PyObject *atomicULong_compare_exchange(AtomicULong *self, PyObject *const *args, Py_ssize_t nargs) {
    if (nargs > 1) {
        unsigned long long int tmp = PyLong_AsUnsignedLongLong(args[0]);
        return PyLong_FromUnsignedLongLong(
                atomic_compare_exchange_strong(&self->value, &tmp, PyLong_AsUnsignedLongLong(args[0])));
    }
    Py_RETURN_NONE;
}


PyObject *atomicFlag_test_and_set(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs){
    return PyBool_FromLong(atomic_flag_test_and_set(&self->value));
}

PyObject *atomicFlag_clear(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs){
    atomic_flag_clear(&self->value);
    Py_RETURN_NONE;
}

PyObject *atomicFlag_spin_lock(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs){
    while(atomic_flag_test_and_set(&self->value));
    Py_RETURN_NONE;
}

PyObject *atomicFlag_spin_unlock(AtomicInt *self, PyObject *const *args, Py_ssize_t nargs){
    atomic_flag_clear(&self->value);
    Py_RETURN_NONE;
}
