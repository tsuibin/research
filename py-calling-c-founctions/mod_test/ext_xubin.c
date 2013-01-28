#include <Python.h>

static PyObject* ext_xubin(PyObject *self, PyObject *args);

static PyObject* ext_xubin(PyObject *self, PyObject *args)
{
    int x = 0;
    int y = 0;
    int z = 0;
    
    if ( !PyArg_ParseTuple(args, "i|i", &x, &y))
        return NULL;

    z = x + y;

    return Py_BuildValue("i", z);


}

static PyMethodDef addMethods[] = 
{
    {"ext_xubin", ext_xubin, METH_VARARGS, "Execute a shell command."},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initext_xubin()
{
    Py_InitModule("ext_xubin", addMethods);
}

