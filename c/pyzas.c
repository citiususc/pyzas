
#include "types.h"
#include "methods.h"
#include "doc.h"


struct PyModuleDef pyzas_module = {
        PyModuleDef_HEAD_INIT,
        .m_name = "pyzas",
        .m_doc = pyzas_doc,
        .m_size = -1
};

PyMethodDef atomicFlag_methods[] = {
        {"test_and_set", (PyCFunction) atomicFlag_test_and_set, METH_FASTCALL, test_and_set_doc},
        {"clear",        (PyCFunction) atomicFlag_clear,        METH_FASTCALL, clear_doc},
        {"spin_lock",    (PyCFunction) atomicFlag_spin_lock,    METH_FASTCALL, spin_lock},
        {"spin_unlock",  (PyCFunction) atomicFlag_spin_unlock,  METH_FASTCALL, spin_unlock},
        {NULL}  /* Sentinel */
};

PyTypeObject AtomicFlagType = {
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "pyzas.AtomicFlag",
        .tp_doc = atomic_flag_doc,
        .tp_basicsize = sizeof(AtomicFlag),
        .tp_itemsize = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
        .tp_new = PyType_GenericNew,
        .tp_init = (initproc) atomicFlag_init,
        .tp_methods = atomicFlag_methods,
};

PyMethodDef atomicInt_methods[] = {
        {"free_lock_level",  (PyCFunction) atomicInt_free_lock_level,  METH_NOARGS,   free_lock_level_doc},
        {"load",             (PyCFunction) atomicInt_load,             METH_FASTCALL, load_doc},
        {"store",            (PyCFunction) atomicInt_store,            METH_FASTCALL, store_doc},
        {"exchange",         (PyCFunction) atomicInt_exchange,         METH_FASTCALL, exchange_doc},
        {"fetch_add",        (PyCFunction) atomicInt_fetch_add,        METH_FASTCALL, fetch_add_doc},
        {"fetch_sub",        (PyCFunction) atomicInt_fetch_sub,        METH_FASTCALL, fetch_sub_doc},
        {"compare_exchange", (PyCFunction) atomicInt_compare_exchange, METH_FASTCALL, compare_exchange_doc},
        {NULL}  /* Sentinel */
};

PyTypeObject AtomicIntType = {
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "pyzas.AtomicInt",
        .tp_doc = atomic_int_doc,
        .tp_basicsize = sizeof(AtomicInt),
        .tp_itemsize = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
        .tp_new = PyType_GenericNew,
        .tp_init = (initproc) atomicInt_init,
        .tp_methods = atomicInt_methods,
};

PyMethodDef atomicLong_methods[] = {
        {"free_lock_level",  (PyCFunction) atomicLong_free_lock_level,  METH_NOARGS,   free_lock_level_doc},
        {"load",             (PyCFunction) atomicLong_load,             METH_FASTCALL, load_doc},
        {"store",            (PyCFunction) atomicLong_store,            METH_FASTCALL, store_doc},
        {"exchange",         (PyCFunction) atomicLong_exchange,         METH_FASTCALL, exchange_doc},
        {"fetch_add",        (PyCFunction) atomicLong_fetch_add,        METH_FASTCALL, fetch_add_doc},
        {"fetch_sub",        (PyCFunction) atomicLong_fetch_sub,        METH_FASTCALL, fetch_sub_doc},
        {"compare_exchange", (PyCFunction) atomicLong_compare_exchange, METH_FASTCALL, compare_exchange_doc},
        {NULL}  /* Sentinel */
};

PyTypeObject AtomicLongType = {
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "pyzas.AtomicLong",
        .tp_doc = atomic_long_doc,
        .tp_basicsize = sizeof(AtomicLong),
        .tp_itemsize = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
        .tp_new = PyType_GenericNew,
        .tp_init = (initproc) atomicLong_init,
        .tp_methods = atomicLong_methods,
};

PyMethodDef atomicULong_methods[] = {
        {"free_lock_level",  (PyCFunction) atomicULong_free_lock_level,  METH_NOARGS,   free_lock_level_doc},
        {"load",             (PyCFunction) atomicULong_load,             METH_FASTCALL, load_doc},
        {"store",            (PyCFunction) atomicULong_store,            METH_FASTCALL, store_doc},
        {"exchange",         (PyCFunction) atomicULong_exchange,         METH_FASTCALL, exchange_doc},
        {"fetch_add",        (PyCFunction) atomicULong_fetch_add,        METH_FASTCALL, fetch_add_doc},
        {"fetch_sub",        (PyCFunction) atomicULong_fetch_sub,        METH_FASTCALL, fetch_sub_doc},
        {"compare_exchange", (PyCFunction) atomicULong_compare_exchange, METH_FASTCALL, compare_exchange_doc},
        {NULL}  /* Sentinel */
};

PyTypeObject AtomicULongType = {
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "pyzas.AtomicULong",
        .tp_doc = atomic_ulong_doc,
        .tp_basicsize = sizeof(AtomicULong),
        .tp_itemsize = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
        .tp_new = PyType_GenericNew,
        .tp_init = (initproc) atomicULong_init,
        .tp_methods = atomicULong_methods,
};


PyMODINIT_FUNC PyInit_pyzas(void) {
    PyObject *m;
    if (PyType_Ready(&AtomicFlagType) < 0 || PyType_Ready(&AtomicIntType) < 0 ||
        PyType_Ready(&AtomicLongType) < 0 || PyType_Ready(&AtomicULongType) < 0) {
        return NULL;
    }

    m = PyModule_Create(&pyzas_module);
    if (m == NULL) {
        return NULL;
    }

    #ifdef Py_GIL_DISABLED
    PyUnstable_Module_SetGIL(m, Py_MOD_GIL_NOT_USED);
    #endif

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