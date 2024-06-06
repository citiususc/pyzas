
#include "types.h"
#include "methods.h"


static struct PyModuleDef pyzas_module = {
        PyModuleDef_HEAD_INIT,
        .m_name = "pyzas",
        .m_doc = "performing python atomic integer operations with the speed and efficiency of a zas!",
        .m_size = -1
};

static PyMethodDef atomicFlag_methods[] = {
        {"test_and_set",             (PyCFunction) atomicFlag_test_and_set,             METH_FASTCALL,
                "sets an atomic flag to true and returns the old value"
        },
        {"clear",            (PyCFunction) atomicFlag_clear,            METH_FASTCALL,
                "sets an atomic flag to false"
        },
        {"spin_lock",         (PyCFunction) atomicFlag_spin_lock,         METH_FASTCALL,
                "causes a thread trying to acquire a lock to simply wait in a loop (\"spin\")"
        },
        {"spin_unlock",        (PyCFunction) atomicFlag_spin_unlock,        METH_FASTCALL,
                "releases the lock"
        },
        {NULL}  /* Sentinel */
};

static PyTypeObject AtomicFlagType = {
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "pyzas.AtomicFlag",
        .tp_doc = PyDoc_STR("Single flag atomic type"),
        .tp_basicsize = sizeof(AtomicFlag),
        .tp_itemsize = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
        .tp_new = atomicFlag_new,
        .tp_init = (initproc) atomicFlag_init,
        .tp_methods = atomicFlag_methods,
};

static PyMethodDef atomicInt_methods[] = {
        {"free_lock_level",  (PyCFunction) atomicInt_free_lock_level,  METH_NOARGS,
                "indicates that the given atomic type is native lock-free"
        },
        {"load",             (PyCFunction) atomicInt_load,             METH_FASTCALL,
                "reads a value from an atomic object"
        },
        {"store",            (PyCFunction) atomicInt_store,            METH_FASTCALL,
                "stores a value in an atomic object"
        },
        {"exchange",         (PyCFunction) atomicInt_exchange,         METH_FASTCALL,
                "stores a value in an atomic object"
        },
        {"fetch_add",        (PyCFunction) atomicInt_fetch_add,        METH_FASTCALL,
                "atomic addition and returns the value obj held previously"
        },
        {"fetch_sub",        (PyCFunction) atomicInt_fetch_sub,        METH_FASTCALL,
                "atomic subtraction and returns the value obj held previously"
        },
        {"compare_exchange", (PyCFunction) atomicInt_compare_exchange, METH_FASTCALL,
                "swaps a value(2) with an atomic object if the old value is what is expected(1), otherwise reads the old value"
        },
        {NULL}  /* Sentinel */
};

static PyTypeObject AtomicIntType = {
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "pyzas.AtomicInt",
        .tp_doc = PyDoc_STR("integer atomic type"),
        .tp_basicsize = sizeof(AtomicInt),
        .tp_itemsize = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
        .tp_new = atomicInt_new,
        .tp_init = (initproc) atomicInt_init,
        .tp_methods = atomicInt_methods,
};

static PyMethodDef atomicLong_methods[] = {
        {"free_lock_level",  (PyCFunction) atomicLong_free_lock_level,  METH_NOARGS,
                "indicates that the given atomic type is native lock-free"
        },
        {"load",             (PyCFunction) atomicLong_load,             METH_FASTCALL,
                "reads a value from an atomic object"
        },
        {"store",            (PyCFunction) atomicLong_store,            METH_FASTCALL,
                "stores a value in an atomic object"
        },
        {"exchange",         (PyCFunction) atomicLong_exchange,         METH_FASTCALL,
                "stores a value in an atomic object"
        },
        {"fetch_add",        (PyCFunction) atomicLong_fetch_add,        METH_FASTCALL,
                "atomic addition and returns the value obj held previously"
        },
        {"fetch_sub",        (PyCFunction) atomicLong_fetch_sub,        METH_FASTCALL,
                "atomic subtraction and returns the value obj held previously"
        },
        {"compare_exchange", (PyCFunction) atomicLong_compare_exchange, METH_FASTCALL,
                "swaps a value(2) with an atomic object if the old value is what is expected(1), otherwise reads the old value"
        },
        {NULL}  /* Sentinel */
};

static PyTypeObject AtomicLongType = {
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "pyzas.AtomicLong",
        .tp_doc = PyDoc_STR("long integer atomic type"),
        .tp_basicsize = sizeof(AtomicLong),
        .tp_itemsize = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
        .tp_new = atomicLong_new,
        .tp_init = (initproc) atomicLong_init,
        .tp_methods = atomicLong_methods,
};

static PyMethodDef atomicULong_methods[] = {
        {"free_lock_level",  (PyCFunction) atomicULong_free_lock_level,  METH_NOARGS,
                "indicates that the given atomic type is native lock-free"
        },
        {"load",             (PyCFunction) atomicULong_load,             METH_FASTCALL,
                "reads a value from an atomic object"
        },
        {"store",            (PyCFunction) atomicULong_store,            METH_FASTCALL,
                "stores a value in an atomic object"
        },
        {"exchange",         (PyCFunction) atomicULong_exchange,         METH_FASTCALL,
                "stores a value in an atomic object"
        },
        {"fetch_add",        (PyCFunction) atomicULong_fetch_add,        METH_FASTCALL,
                "atomic addition and returns the value obj held previously"
        },
        {"fetch_sub",        (PyCFunction) atomicULong_fetch_sub,        METH_FASTCALL,
                "atomic subtraction and returns the value obj held previously"
        },
        {"compare_exchange", (PyCFunction) atomicULong_compare_exchange, METH_FASTCALL,
                "swaps a value(2) with an atomic object if the old value is what is expected(1), otherwise reads the old value"
        },
        {NULL}  /* Sentinel */
};

static PyTypeObject AtomicULongType = {
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "pyzas.AtomicULong",
        .tp_doc = PyDoc_STR("Unsigned Long integer atomic type"),
        .tp_basicsize = sizeof(AtomicULong),
        .tp_itemsize = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
        .tp_new = atomicULong_new,
        .tp_init = (initproc) atomicULong_init,
        .tp_methods = atomicULong_methods,
};

PyMODINIT_FUNC PyInit_pyzas(void) {
    PyObject *m;
    if (PyType_Ready(&AtomicIntType) < 0) {
        return NULL;
    }

    m = PyModule_Create(&pyzas_module);
    if (m == NULL) {
        return NULL;
    }

    if (PyModule_AddObjectRef(m, "AtomicFlag", (PyObject *) &AtomicFlagType) < 0) {
        Py_DECREF(m);
        return NULL;
    }

    if (PyModule_AddObjectRef(m, "AtomicInt", (PyObject *) &AtomicIntType) < 0) {
        Py_DECREF(m);
        return NULL;
    }

    if (PyModule_AddObjectRef(m, "AtomicLong", (PyObject *) &AtomicLongType) < 0) {
        Py_DECREF(m);
        return NULL;
    }

    if (PyModule_AddObjectRef(m, "AtomicULong", (PyObject *) &AtomicULongType) < 0) {
        Py_DECREF(m);
        return NULL;
    }

    return m;
}