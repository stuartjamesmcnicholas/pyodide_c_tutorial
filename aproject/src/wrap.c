#include <Python.h>
#include <stdio.h>
#include <stddef.h>

static PyObject *method_printf(PyObject *self, PyObject *args) {
    char *str, *filename = NULL;
    int bytes_copied = -1;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "s", &str, &filename)) {
        return NULL;
    }

    printf("%s\n",str);

    return PyLong_FromLong(bytes_copied);
}

static PyMethodDef PrintfMethods[] = {
    {"printf", method_printf, METH_VARARGS, "Python interface for printf C library function"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef printfmodule = {
    PyModuleDef_HEAD_INIT,
    "printf",
    "Python interface for the printf C library function",
    -1,
    PrintfMethods
};

PyMODINIT_FUNC PyInit_mymodule(void) {
    return PyModule_Create(&printfmodule);
}


