#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "pythonsupport.c"
#include "function_wrapper.c"
#include "__native.h"
#include "__native_internal.h"

static int
HeadlessWindTunnel_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
PyObject *CPyDef___mypyc__HeadlessWindTunnel_setup(PyObject *cpy_r_type);
PyObject *CPyDef_HeadlessWindTunnel(CPyTagged cpy_r_grid_w, CPyTagged cpy_r_grid_h, double cpy_r_density, double cpy_r_flow_speed, double cpy_r_smoke_strength, double cpy_r_gravity, double cpy_r_dt, CPyTagged cpy_r_iterations, double cpy_r_over_relax, CPyTagged cpy_r_inlet_columns, uint32_t cpy_r___bitmap);

static PyObject *
HeadlessWindTunnel_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_HeadlessWindTunnel) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__HeadlessWindTunnel_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_HeadlessWindTunnel_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
HeadlessWindTunnel_traverse(simplified___HeadlessWindTunnelObject *self, visitproc visit, void *arg)
{
    if (CPyTagged_CheckLong(self->_grid_w)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_grid_w));
    }
    if (CPyTagged_CheckLong(self->_grid_h)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_grid_h));
    }
    if (CPyTagged_CheckLong(self->_iterations)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_iterations));
    }
    if (CPyTagged_CheckLong(self->_inlet_columns)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_inlet_columns));
    }
    Py_VISIT(self->_fluid);
    return 0;
}

static int
HeadlessWindTunnel_clear(simplified___HeadlessWindTunnelObject *self)
{
    if (CPyTagged_CheckLong(self->_grid_w)) {
        CPyTagged __tmp = self->_grid_w;
        self->_grid_w = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_grid_h)) {
        CPyTagged __tmp = self->_grid_h;
        self->_grid_h = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_iterations)) {
        CPyTagged __tmp = self->_iterations;
        self->_iterations = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_inlet_columns)) {
        CPyTagged __tmp = self->_inlet_columns;
        self->_inlet_columns = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_fluid);
    return 0;
}

static void
HeadlessWindTunnel_dealloc(simplified___HeadlessWindTunnelObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, HeadlessWindTunnel_dealloc)
    HeadlessWindTunnel_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem HeadlessWindTunnel_vtable[12];
static bool
CPyDef_HeadlessWindTunnel_trait_vtable_setup(void)
{
    CPyVTableItem HeadlessWindTunnel_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_HeadlessWindTunnel_____init__,
        (CPyVTableItem)CPyDef_HeadlessWindTunnel____idx,
        (CPyVTableItem)CPyDef_HeadlessWindTunnel____create_scene,
        (CPyVTableItem)CPyDef_HeadlessWindTunnel___apply_inlet,
        (CPyVTableItem)CPyDef_HeadlessWindTunnel___set_obstacle_circle,
        (CPyVTableItem)CPyDef_HeadlessWindTunnel___set_obstacle_airfoil,
        (CPyVTableItem)CPyDef_HeadlessWindTunnel___step,
        (CPyVTableItem)CPyDef_HeadlessWindTunnel___speed_field,
        (CPyVTableItem)CPyDef_HeadlessWindTunnel___smoke_field,
        (CPyVTableItem)CPyDef_HeadlessWindTunnel___pressure_field,
        (CPyVTableItem)CPyDef_HeadlessWindTunnel___solid_field,
        (CPyVTableItem)CPyDef_HeadlessWindTunnel___export_cell_data,
    };
    memcpy(HeadlessWindTunnel_vtable, HeadlessWindTunnel_vtable_scratch, sizeof(HeadlessWindTunnel_vtable));
    return 1;
}

static bool
CPyDef_HeadlessWindTunnel_coroutine_setup(PyObject *type)
{
    return 1;
}

static PyObject *
HeadlessWindTunnel_get_grid_w(simplified___HeadlessWindTunnelObject *self, void *closure);
static int
HeadlessWindTunnel_set_grid_w(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure);
static PyObject *
HeadlessWindTunnel_get_grid_h(simplified___HeadlessWindTunnelObject *self, void *closure);
static int
HeadlessWindTunnel_set_grid_h(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure);
static PyObject *
HeadlessWindTunnel_get_density(simplified___HeadlessWindTunnelObject *self, void *closure);
static int
HeadlessWindTunnel_set_density(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure);
static PyObject *
HeadlessWindTunnel_get_flow_speed(simplified___HeadlessWindTunnelObject *self, void *closure);
static int
HeadlessWindTunnel_set_flow_speed(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure);
static PyObject *
HeadlessWindTunnel_get_smoke_strength(simplified___HeadlessWindTunnelObject *self, void *closure);
static int
HeadlessWindTunnel_set_smoke_strength(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure);
static PyObject *
HeadlessWindTunnel_get_gravity(simplified___HeadlessWindTunnelObject *self, void *closure);
static int
HeadlessWindTunnel_set_gravity(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure);
static PyObject *
HeadlessWindTunnel_get_dt(simplified___HeadlessWindTunnelObject *self, void *closure);
static int
HeadlessWindTunnel_set_dt(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure);
static PyObject *
HeadlessWindTunnel_get_iterations(simplified___HeadlessWindTunnelObject *self, void *closure);
static int
HeadlessWindTunnel_set_iterations(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure);
static PyObject *
HeadlessWindTunnel_get_over_relax(simplified___HeadlessWindTunnelObject *self, void *closure);
static int
HeadlessWindTunnel_set_over_relax(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure);
static PyObject *
HeadlessWindTunnel_get_inlet_columns(simplified___HeadlessWindTunnelObject *self, void *closure);
static int
HeadlessWindTunnel_set_inlet_columns(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure);
static PyObject *
HeadlessWindTunnel_get_fluid(simplified___HeadlessWindTunnelObject *self, void *closure);
static int
HeadlessWindTunnel_set_fluid(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure);

static PyGetSetDef HeadlessWindTunnel_getseters[] = {
    {"grid_w",
     (getter)HeadlessWindTunnel_get_grid_w, (setter)HeadlessWindTunnel_set_grid_w,
     NULL, NULL},
    {"grid_h",
     (getter)HeadlessWindTunnel_get_grid_h, (setter)HeadlessWindTunnel_set_grid_h,
     NULL, NULL},
    {"density",
     (getter)HeadlessWindTunnel_get_density, (setter)HeadlessWindTunnel_set_density,
     NULL, NULL},
    {"flow_speed",
     (getter)HeadlessWindTunnel_get_flow_speed, (setter)HeadlessWindTunnel_set_flow_speed,
     NULL, NULL},
    {"smoke_strength",
     (getter)HeadlessWindTunnel_get_smoke_strength, (setter)HeadlessWindTunnel_set_smoke_strength,
     NULL, NULL},
    {"gravity",
     (getter)HeadlessWindTunnel_get_gravity, (setter)HeadlessWindTunnel_set_gravity,
     NULL, NULL},
    {"dt",
     (getter)HeadlessWindTunnel_get_dt, (setter)HeadlessWindTunnel_set_dt,
     NULL, NULL},
    {"iterations",
     (getter)HeadlessWindTunnel_get_iterations, (setter)HeadlessWindTunnel_set_iterations,
     NULL, NULL},
    {"over_relax",
     (getter)HeadlessWindTunnel_get_over_relax, (setter)HeadlessWindTunnel_set_over_relax,
     NULL, NULL},
    {"inlet_columns",
     (getter)HeadlessWindTunnel_get_inlet_columns, (setter)HeadlessWindTunnel_set_inlet_columns,
     NULL, NULL},
    {"fluid",
     (getter)HeadlessWindTunnel_get_fluid, (setter)HeadlessWindTunnel_set_fluid,
     NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef HeadlessWindTunnel_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__HeadlessWindTunnel_setup, METH_O, NULL},
    {"__init__",
     (PyCFunction)CPyPy_HeadlessWindTunnel_____init__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__init__($self, grid_w=200, grid_h=100, density=1.0, flow_speed=9.0, smoke_strength=1.0, gravity=0.0, dt=0.08, iterations=30, over_relax=1.9, inlet_columns=3, /)\n--\n\n")},
    {"_idx",
     (PyCFunction)CPyPy_HeadlessWindTunnel____idx,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_idx($self, i, j)\n--\n\n")},
    {"_create_scene",
     (PyCFunction)CPyPy_HeadlessWindTunnel____create_scene,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_create_scene($self)\n--\n\n")},
    {"apply_inlet",
     (PyCFunction)CPyPy_HeadlessWindTunnel___apply_inlet,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("apply_inlet($self)\n--\n\n")},
    {"set_obstacle_circle",
     (PyCFunction)CPyPy_HeadlessWindTunnel___set_obstacle_circle,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("set_obstacle_circle($self, cx, cy, radius, solid=True)\n--\n\n")},
    {"set_obstacle_airfoil",
     (PyCFunction)CPyPy_HeadlessWindTunnel___set_obstacle_airfoil,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("set_obstacle_airfoil($self, naca_code, chord_length, center_x, center_y)\n--\n\n")},
    {"step",
     (PyCFunction)CPyPy_HeadlessWindTunnel___step,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("step($self, steps=1)\n--\n\n")},
    {"speed_field",
     (PyCFunction)CPyPy_HeadlessWindTunnel___speed_field,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("speed_field($self)\n--\n\n")},
    {"smoke_field",
     (PyCFunction)CPyPy_HeadlessWindTunnel___smoke_field,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("smoke_field($self)\n--\n\n")},
    {"pressure_field",
     (PyCFunction)CPyPy_HeadlessWindTunnel___pressure_field,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("pressure_field($self)\n--\n\n")},
    {"solid_field",
     (PyCFunction)CPyPy_HeadlessWindTunnel___solid_field,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("solid_field($self)\n--\n\n")},
    {"export_cell_data",
     (PyCFunction)CPyPy_HeadlessWindTunnel___export_cell_data,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("export_cell_data($self)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_HeadlessWindTunnel_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "HeadlessWindTunnel",
    .tp_new = HeadlessWindTunnel_new,
    .tp_dealloc = (destructor)HeadlessWindTunnel_dealloc,
    .tp_traverse = (traverseproc)HeadlessWindTunnel_traverse,
    .tp_clear = (inquiry)HeadlessWindTunnel_clear,
    .tp_getset = HeadlessWindTunnel_getseters,
    .tp_methods = HeadlessWindTunnel_methods,
    .tp_init = HeadlessWindTunnel_init,
    .tp_basicsize = sizeof(simplified___HeadlessWindTunnelObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("HeadlessWindTunnel(grid_w=200, grid_h=100, density=1.0, flow_speed=9.0, smoke_strength=1.0, gravity=0.0, dt=0.08, iterations=30, over_relax=1.9, inlet_columns=3, /)\n--\n\n"),
};
static PyTypeObject *CPyType_HeadlessWindTunnel_template = &CPyType_HeadlessWindTunnel_template_;

PyObject *CPyDef___mypyc__HeadlessWindTunnel_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    simplified___HeadlessWindTunnelObject *self;
    self = (simplified___HeadlessWindTunnelObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = HeadlessWindTunnel_vtable;
    self->_grid_w = CPY_INT_TAG;
    self->_grid_h = CPY_INT_TAG;
    self->_density = -113.0;
    self->_flow_speed = -113.0;
    self->_smoke_strength = -113.0;
    self->_gravity = -113.0;
    self->_dt = -113.0;
    self->_iterations = CPY_INT_TAG;
    self->_over_relax = -113.0;
    self->_inlet_columns = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef_HeadlessWindTunnel(CPyTagged cpy_r_grid_w, CPyTagged cpy_r_grid_h, double cpy_r_density, double cpy_r_flow_speed, double cpy_r_smoke_strength, double cpy_r_gravity, double cpy_r_dt, CPyTagged cpy_r_iterations, double cpy_r_over_relax, CPyTagged cpy_r_inlet_columns, uint32_t cpy_r___bitmap)
{
    PyObject *self = CPyDef___mypyc__HeadlessWindTunnel_setup((PyObject *)CPyType_HeadlessWindTunnel);
    if (self == NULL)
        return NULL;
    char res = CPyDef_HeadlessWindTunnel_____init__(self, cpy_r_grid_w, cpy_r_grid_h, cpy_r_density, cpy_r_flow_speed, cpy_r_smoke_strength, cpy_r_gravity, cpy_r_dt, cpy_r_iterations, cpy_r_over_relax, cpy_r_inlet_columns, cpy_r___bitmap);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
HeadlessWindTunnel_get_grid_w(simplified___HeadlessWindTunnelObject *self, void *closure)
{
    if (unlikely(self->_grid_w == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'grid_w' of 'HeadlessWindTunnel' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_grid_w);
    PyObject *retval = CPyTagged_StealAsObject(self->_grid_w);
    return retval;
}

static int
HeadlessWindTunnel_set_grid_w(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HeadlessWindTunnel' object attribute 'grid_w' cannot be deleted");
        return -1;
    }
    if (self->_grid_w != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_grid_w);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_grid_w = tmp;
    return 0;
}

static PyObject *
HeadlessWindTunnel_get_grid_h(simplified___HeadlessWindTunnelObject *self, void *closure)
{
    if (unlikely(self->_grid_h == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'grid_h' of 'HeadlessWindTunnel' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_grid_h);
    PyObject *retval = CPyTagged_StealAsObject(self->_grid_h);
    return retval;
}

static int
HeadlessWindTunnel_set_grid_h(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HeadlessWindTunnel' object attribute 'grid_h' cannot be deleted");
        return -1;
    }
    if (self->_grid_h != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_grid_h);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_grid_h = tmp;
    return 0;
}

static PyObject *
HeadlessWindTunnel_get_density(simplified___HeadlessWindTunnelObject *self, void *closure)
{
    PyObject *retval = PyFloat_FromDouble(self->_density);
    return retval;
}

static int
HeadlessWindTunnel_set_density(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HeadlessWindTunnel' object attribute 'density' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_density = tmp;
    return 0;
}

static PyObject *
HeadlessWindTunnel_get_flow_speed(simplified___HeadlessWindTunnelObject *self, void *closure)
{
    PyObject *retval = PyFloat_FromDouble(self->_flow_speed);
    return retval;
}

static int
HeadlessWindTunnel_set_flow_speed(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HeadlessWindTunnel' object attribute 'flow_speed' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_flow_speed = tmp;
    return 0;
}

static PyObject *
HeadlessWindTunnel_get_smoke_strength(simplified___HeadlessWindTunnelObject *self, void *closure)
{
    PyObject *retval = PyFloat_FromDouble(self->_smoke_strength);
    return retval;
}

static int
HeadlessWindTunnel_set_smoke_strength(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HeadlessWindTunnel' object attribute 'smoke_strength' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_smoke_strength = tmp;
    return 0;
}

static PyObject *
HeadlessWindTunnel_get_gravity(simplified___HeadlessWindTunnelObject *self, void *closure)
{
    PyObject *retval = PyFloat_FromDouble(self->_gravity);
    return retval;
}

static int
HeadlessWindTunnel_set_gravity(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HeadlessWindTunnel' object attribute 'gravity' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_gravity = tmp;
    return 0;
}

static PyObject *
HeadlessWindTunnel_get_dt(simplified___HeadlessWindTunnelObject *self, void *closure)
{
    PyObject *retval = PyFloat_FromDouble(self->_dt);
    return retval;
}

static int
HeadlessWindTunnel_set_dt(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HeadlessWindTunnel' object attribute 'dt' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_dt = tmp;
    return 0;
}

static PyObject *
HeadlessWindTunnel_get_iterations(simplified___HeadlessWindTunnelObject *self, void *closure)
{
    if (unlikely(self->_iterations == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'iterations' of 'HeadlessWindTunnel' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_iterations);
    PyObject *retval = CPyTagged_StealAsObject(self->_iterations);
    return retval;
}

static int
HeadlessWindTunnel_set_iterations(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HeadlessWindTunnel' object attribute 'iterations' cannot be deleted");
        return -1;
    }
    if (self->_iterations != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_iterations);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_iterations = tmp;
    return 0;
}

static PyObject *
HeadlessWindTunnel_get_over_relax(simplified___HeadlessWindTunnelObject *self, void *closure)
{
    PyObject *retval = PyFloat_FromDouble(self->_over_relax);
    return retval;
}

static int
HeadlessWindTunnel_set_over_relax(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HeadlessWindTunnel' object attribute 'over_relax' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_over_relax = tmp;
    return 0;
}

static PyObject *
HeadlessWindTunnel_get_inlet_columns(simplified___HeadlessWindTunnelObject *self, void *closure)
{
    if (unlikely(self->_inlet_columns == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'inlet_columns' of 'HeadlessWindTunnel' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_inlet_columns);
    PyObject *retval = CPyTagged_StealAsObject(self->_inlet_columns);
    return retval;
}

static int
HeadlessWindTunnel_set_inlet_columns(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HeadlessWindTunnel' object attribute 'inlet_columns' cannot be deleted");
        return -1;
    }
    if (self->_inlet_columns != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_inlet_columns);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_inlet_columns = tmp;
    return 0;
}

static PyObject *
HeadlessWindTunnel_get_fluid(simplified___HeadlessWindTunnelObject *self, void *closure)
{
    if (unlikely(self->_fluid == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'fluid' of 'HeadlessWindTunnel' undefined");
        return NULL;
    }
    CPy_INCREF(self->_fluid);
    PyObject *retval = self->_fluid;
    return retval;
}

static int
HeadlessWindTunnel_set_fluid(simplified___HeadlessWindTunnelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HeadlessWindTunnel' object attribute 'fluid' cannot be deleted");
        return -1;
    }
    if (self->_fluid != NULL) {
        CPy_DECREF(self->_fluid);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_fluid = tmp;
    return 0;
}
static PyMethodDef module_methods[] = {
    {"save_cell_csv", (PyCFunction)CPyPy_save_cell_csv, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("save_cell_csv(path, cell_data)\n--\n\n") /* docstring */},
    {"save_field_plot", (PyCFunction)CPyPy_save_field_plot, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("save_field_plot(path, speed, smoke, pressure, solid)\n--\n\n") /* docstring */},
    {"build_parser", (PyCFunction)CPyPy_build_parser, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("build_parser()\n--\n\n") /* docstring */},
    {"main", (PyCFunction)CPyPy_main, METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("main()\n--\n\n") /* docstring */},
    {NULL, NULL, 0, NULL}
};

int CPyExec_simplified(PyObject *module)
{
    intern_strings();
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_simplified__internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_simplified__internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_simplified__internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_HeadlessWindTunnel);
    return -1;
}
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "simplified",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    module_methods,
    NULL,
};

PyMODINIT_FUNC PyInit_simplified(void)
{
    PyObject* modname = NULL;
    if (CPyModule_simplified__internal) {
        Py_INCREF(CPyModule_simplified__internal);
        return CPyModule_simplified__internal;
    }
    CPyModule_simplified__internal = PyModule_Create(&module);
    if (unlikely(CPyModule_simplified__internal == NULL))
        goto fail;
    modname = PyUnicode_FromString("simplified");
    if (modname == NULL) CPyError_OutOfMemory();
    if (PyObject_SetItem(PyImport_GetModuleDict(), modname, CPyModule_simplified__internal) < 0)
        goto fail;
    Py_CLEAR(modname);
    if (CPyExec_simplified(CPyModule_simplified__internal) != 0)
        goto fail;
    return CPyModule_simplified__internal;
    fail:
    {
            PyObject *exc_type, *exc_val, *exc_tb;
            PyErr_Fetch(&exc_type, &exc_val, &exc_tb);
            if (modname == NULL) {
                    modname = PyUnicode_FromString("simplified");
                    if (modname == NULL) CPyError_OutOfMemory();
                }
                PyObject_DelItem(PyImport_GetModuleDict(), modname);
                PyErr_Clear();
                Py_DECREF(modname);
                Py_CLEAR(CPyModule_simplified__internal);
                PyErr_Restore(exc_type, exc_val, exc_tb);
        }
        return NULL;
    }
    
char CPyDef_HeadlessWindTunnel_____init__(PyObject *cpy_r_self, CPyTagged cpy_r_grid_w, CPyTagged cpy_r_grid_h, double cpy_r_density, double cpy_r_flow_speed, double cpy_r_smoke_strength, double cpy_r_gravity, double cpy_r_dt, CPyTagged cpy_r_iterations, double cpy_r_over_relax, CPyTagged cpy_r_inlet_columns, uint32_t cpy_r___bitmap) {
    uint32_t cpy_r_r0;
    char cpy_r_r1;
    uint32_t cpy_r_r2;
    char cpy_r_r3;
    uint32_t cpy_r_r4;
    char cpy_r_r5;
    uint32_t cpy_r_r6;
    char cpy_r_r7;
    uint32_t cpy_r_r8;
    char cpy_r_r9;
    uint32_t cpy_r_r10;
    char cpy_r_r11;
    char cpy_r_r12;
    char cpy_r_r13;
    if (cpy_r_grid_w != CPY_INT_TAG) goto CPyL23;
    cpy_r_grid_w = 400;
CPyL2: ;
    if (cpy_r_grid_h != CPY_INT_TAG) goto CPyL24;
    cpy_r_grid_h = 200;
CPyL4: ;
    cpy_r_r0 = cpy_r___bitmap & 1;
    cpy_r_r1 = cpy_r_r0 == 0;
    if (!cpy_r_r1) goto CPyL6;
    cpy_r_density = 1.0;
CPyL6: ;
    cpy_r_r2 = cpy_r___bitmap & 2;
    cpy_r_r3 = cpy_r_r2 == 0;
    if (!cpy_r_r3) goto CPyL8;
    cpy_r_flow_speed = 9.0;
CPyL8: ;
    cpy_r_r4 = cpy_r___bitmap & 4;
    cpy_r_r5 = cpy_r_r4 == 0;
    if (!cpy_r_r5) goto CPyL10;
    cpy_r_smoke_strength = 1.0;
CPyL10: ;
    cpy_r_r6 = cpy_r___bitmap & 8;
    cpy_r_r7 = cpy_r_r6 == 0;
    if (!cpy_r_r7) goto CPyL12;
    cpy_r_gravity = 0.0;
CPyL12: ;
    cpy_r_r8 = cpy_r___bitmap & 16;
    cpy_r_r9 = cpy_r_r8 == 0;
    if (!cpy_r_r9) goto CPyL14;
    cpy_r_dt = 0.08;
CPyL14: ;
    if (cpy_r_iterations != CPY_INT_TAG) goto CPyL25;
    cpy_r_iterations = 60;
CPyL16: ;
    cpy_r_r10 = cpy_r___bitmap & 32;
    cpy_r_r11 = cpy_r_r10 == 0;
    if (!cpy_r_r11) goto CPyL18;
    cpy_r_over_relax = 1.9;
CPyL18: ;
    if (cpy_r_inlet_columns != CPY_INT_TAG) goto CPyL26;
    cpy_r_inlet_columns = 6;
CPyL20: ;
    ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_w = cpy_r_grid_w;
    ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_h = cpy_r_grid_h;
    ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_density = cpy_r_density;
    ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_flow_speed = cpy_r_flow_speed;
    ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_smoke_strength = cpy_r_smoke_strength;
    ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_gravity = cpy_r_gravity;
    ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_dt = cpy_r_dt;
    ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_iterations = cpy_r_iterations;
    ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_over_relax = cpy_r_over_relax;
    ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_inlet_columns = cpy_r_inlet_columns;
    cpy_r_r12 = CPyDef_HeadlessWindTunnel____create_scene(cpy_r_self);
    if (unlikely(cpy_r_r12 == 2)) {
        CPy_AddTraceback("simplified.py", "__init__", 49, CPyStatic_globals);
        goto CPyL22;
    }
    return 1;
CPyL22: ;
    cpy_r_r13 = 2;
    return cpy_r_r13;
CPyL23: ;
    CPyTagged_INCREF(cpy_r_grid_w);
    goto CPyL2;
CPyL24: ;
    CPyTagged_INCREF(cpy_r_grid_h);
    goto CPyL4;
CPyL25: ;
    CPyTagged_INCREF(cpy_r_iterations);
    goto CPyL16;
CPyL26: ;
    CPyTagged_INCREF(cpy_r_inlet_columns);
    goto CPyL20;
}
    
    PyObject *CPyPy_HeadlessWindTunnel_____init__(PyObject *self, PyObject *args, PyObject *kw) {
        PyObject *obj_self = self;
        static const char * const kwlist[] = {"grid_w", "grid_h", "density", "flow_speed", "smoke_strength", "gravity", "dt", "iterations", "over_relax", "inlet_columns", 0};
        PyObject *obj_grid_w = NULL;
        PyObject *obj_grid_h = NULL;
        PyObject *obj_density = NULL;
        PyObject *obj_flow_speed = NULL;
        PyObject *obj_smoke_strength = NULL;
        PyObject *obj_gravity = NULL;
        PyObject *obj_dt = NULL;
        PyObject *obj_iterations = NULL;
        PyObject *obj_over_relax = NULL;
        PyObject *obj_inlet_columns = NULL;
        if (!CPyArg_ParseTupleAndKeywords(args, kw, "|OOOOOOOOOO", "__init__", kwlist, &obj_grid_w, &obj_grid_h, &obj_density, &obj_flow_speed, &obj_smoke_strength, &obj_gravity, &obj_dt, &obj_iterations, &obj_over_relax, &obj_inlet_columns)) {
            return NULL;
        }
        uint32_t __bitmap = 0;
        PyObject *arg_self;
        if (likely(Py_TYPE(obj_self) == CPyType_HeadlessWindTunnel))
            arg_self = obj_self;
        else {
            CPy_TypeError("simplified.HeadlessWindTunnel", obj_self); 
            goto fail;
        }
        CPyTagged arg_grid_w;
        if (obj_grid_w == NULL) {
            arg_grid_w = CPY_INT_TAG;
        } else if (likely(PyLong_Check(obj_grid_w)))
            arg_grid_w = CPyTagged_BorrowFromObject(obj_grid_w);
        else {
            CPy_TypeError("int", obj_grid_w); goto fail;
        }
        CPyTagged arg_grid_h;
        if (obj_grid_h == NULL) {
            arg_grid_h = CPY_INT_TAG;
        } else if (likely(PyLong_Check(obj_grid_h)))
            arg_grid_h = CPyTagged_BorrowFromObject(obj_grid_h);
        else {
            CPy_TypeError("int", obj_grid_h); goto fail;
        }
        double arg_density = -113.0;
        if (obj_density != NULL) {
            __bitmap |= 1 << 0;
            arg_density = PyFloat_AsDouble(obj_density);
            if (arg_density == -1.0 && PyErr_Occurred()) {
                CPy_TypeError("float", obj_density); goto fail;
            }
        }
        double arg_flow_speed = -113.0;
        if (obj_flow_speed != NULL) {
            __bitmap |= 1 << 1;
            arg_flow_speed = PyFloat_AsDouble(obj_flow_speed);
            if (arg_flow_speed == -1.0 && PyErr_Occurred()) {
                CPy_TypeError("float", obj_flow_speed); goto fail;
            }
        }
        double arg_smoke_strength = -113.0;
        if (obj_smoke_strength != NULL) {
            __bitmap |= 1 << 2;
            arg_smoke_strength = PyFloat_AsDouble(obj_smoke_strength);
            if (arg_smoke_strength == -1.0 && PyErr_Occurred()) {
                CPy_TypeError("float", obj_smoke_strength); goto fail;
            }
        }
        double arg_gravity = -113.0;
        if (obj_gravity != NULL) {
            __bitmap |= 1 << 3;
            arg_gravity = PyFloat_AsDouble(obj_gravity);
            if (arg_gravity == -1.0 && PyErr_Occurred()) {
                CPy_TypeError("float", obj_gravity); goto fail;
            }
        }
        double arg_dt = -113.0;
        if (obj_dt != NULL) {
            __bitmap |= 1 << 4;
            arg_dt = PyFloat_AsDouble(obj_dt);
            if (arg_dt == -1.0 && PyErr_Occurred()) {
                CPy_TypeError("float", obj_dt); goto fail;
            }
        }
        CPyTagged arg_iterations;
        if (obj_iterations == NULL) {
            arg_iterations = CPY_INT_TAG;
        } else if (likely(PyLong_Check(obj_iterations)))
            arg_iterations = CPyTagged_BorrowFromObject(obj_iterations);
        else {
            CPy_TypeError("int", obj_iterations); goto fail;
        }
        double arg_over_relax = -113.0;
        if (obj_over_relax != NULL) {
            __bitmap |= 1 << 5;
            arg_over_relax = PyFloat_AsDouble(obj_over_relax);
            if (arg_over_relax == -1.0 && PyErr_Occurred()) {
                CPy_TypeError("float", obj_over_relax); goto fail;
            }
        }
        CPyTagged arg_inlet_columns;
        if (obj_inlet_columns == NULL) {
            arg_inlet_columns = CPY_INT_TAG;
        } else if (likely(PyLong_Check(obj_inlet_columns)))
            arg_inlet_columns = CPyTagged_BorrowFromObject(obj_inlet_columns);
        else {
            CPy_TypeError("int", obj_inlet_columns); goto fail;
        }
        char retval = CPyDef_HeadlessWindTunnel_____init__(arg_self, arg_grid_w, arg_grid_h, arg_density, arg_flow_speed, arg_smoke_strength, arg_gravity, arg_dt, arg_iterations, arg_over_relax, arg_inlet_columns, __bitmap);
        if (retval == 2) {
            return NULL;
        }
        PyObject *retbox = Py_None;
        CPy_INCREF(retbox);
        return retbox;
fail: ;
        CPy_AddTraceback("simplified.py", "__init__", 24, CPyStatic_globals);
        return NULL;
    }
    
CPyTagged CPyDef_HeadlessWindTunnel____idx(PyObject *cpy_r_self, CPyTagged cpy_r_i, CPyTagged cpy_r_j) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    CPyTagged cpy_r_r4;
    CPyTagged cpy_r_r5;
    CPyTagged cpy_r_r6;
    cpy_r_r0 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("simplified.py", "_idx", "HeadlessWindTunnel", "fluid", 52, CPyStatic_globals);
        goto CPyL4;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyStatics[3]; /* 'numY' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("simplified.py", "_idx", 52, CPyStatic_globals);
        goto CPyL4;
    }
    if (likely(PyLong_Check(cpy_r_r2)))
        cpy_r_r3 = CPyTagged_FromObject(cpy_r_r2);
    else {
        CPy_TypeError("int", cpy_r_r2); cpy_r_r3 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "_idx", 52, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r4 = CPyTagged_Multiply(cpy_r_i, cpy_r_r3);
    CPyTagged_DECREF(cpy_r_r3);
    cpy_r_r5 = CPyTagged_Add(cpy_r_r4, cpy_r_j);
    CPyTagged_DECREF(cpy_r_r4);
    return cpy_r_r5;
CPyL4: ;
    cpy_r_r6 = CPY_INT_TAG;
    return cpy_r_r6;
}
    
    PyObject *CPyPy_HeadlessWindTunnel____idx(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        PyObject *obj_self = self;
        static const char * const kwlist[] = {"i", "j", 0};
        static CPyArg_Parser parser = {"OO:_idx", kwlist, 0};
        PyObject *obj_i;
        PyObject *obj_j;
        if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_i, &obj_j)) {
            return NULL;
        }
        PyObject *arg_self;
        if (likely(Py_TYPE(obj_self) == CPyType_HeadlessWindTunnel))
            arg_self = obj_self;
        else {
            CPy_TypeError("simplified.HeadlessWindTunnel", obj_self); 
            goto fail;
        }
        CPyTagged arg_i;
        if (likely(PyLong_Check(obj_i)))
            arg_i = CPyTagged_BorrowFromObject(obj_i);
        else {
            CPy_TypeError("int", obj_i); goto fail;
        }
        CPyTagged arg_j;
        if (likely(PyLong_Check(obj_j)))
            arg_j = CPyTagged_BorrowFromObject(obj_j);
        else {
            CPy_TypeError("int", obj_j); goto fail;
        }
        CPyTagged retval = CPyDef_HeadlessWindTunnel____idx(arg_self, arg_i, arg_j);
        if (retval == CPY_INT_TAG) {
            return NULL;
        }
        PyObject *retbox = CPyTagged_StealAsObject(retval);
        return retbox;
fail: ;
        CPy_AddTraceback("simplified.py", "_idx", 51, CPyStatic_globals);
        return NULL;
    }
    
char CPyDef_HeadlessWindTunnel____create_scene(PyObject *cpy_r_self) {
    double cpy_r_r0;
    CPyTagged cpy_r_r1;
    CPyTagged cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject **cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject **cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject **cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject **cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    CPyTagged cpy_r_r57;
    CPyTagged cpy_r_r58;
    CPyTagged cpy_r_r59;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r60;
    char cpy_r_r61;
    int64_t cpy_r_r62;
    char cpy_r_r63;
    char cpy_r_r64;
    char cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    CPyTagged cpy_r_r69;
    CPyTagged cpy_r_r70;
    CPyTagged cpy_r_r71;
    CPyTagged cpy_r_j;
    int64_t cpy_r_r72;
    char cpy_r_r73;
    int64_t cpy_r_r74;
    char cpy_r_r75;
    char cpy_r_r76;
    char cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    CPyTagged cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    int32_t cpy_r_r84;
    char cpy_r_r85;
    CPyTagged cpy_r_r86;
    CPyTagged cpy_r_r87;
    char cpy_r_r88;
    char cpy_r_r89;
    cpy_r_r0 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_density;
    cpy_r_r1 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_w;
    CPyTagged_INCREF(cpy_r_r1);
    cpy_r_r2 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_h;
    CPyTagged_INCREF(cpy_r_r2);
    cpy_r_r3 = CPyStatic_globals;
    cpy_r_r4 = CPyStatics[4]; /* 'FLUID' */
    cpy_r_r5 = CPyDict_GetItem(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 55, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r6 = PyFloat_FromDouble(cpy_r_r0);
    cpy_r_r7 = CPyTagged_StealAsObject(cpy_r_r1);
    cpy_r_r8 = CPyTagged_StealAsObject(cpy_r_r2);
    cpy_r_r9 = PyFloat_FromDouble(1.0);
    PyObject *cpy_r_r10[4] = {cpy_r_r6, cpy_r_r7, cpy_r_r8, cpy_r_r9};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_Vectorcall(cpy_r_r5, cpy_r_r11, 4, 0);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 55, CPyStatic_globals);
        goto CPyL44;
    }
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r9);
    if (((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid != NULL) {
        CPy_DECREF(((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid);
    }
    ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid = cpy_r_r12;
    cpy_r_r13 = 1;
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 55, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r14 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AttributeError("simplified.py", "_create_scene", "HeadlessWindTunnel", "fluid", 56, CPyStatic_globals);
        goto CPyL42;
    }
    CPy_INCREF(cpy_r_r14);
CPyL4: ;
    cpy_r_r15 = CPyStatics[5]; /* 's' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 56, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r17 = CPyStatics[6]; /* 'fill' */
    cpy_r_r18 = PyFloat_FromDouble(0.0);
    PyObject *cpy_r_r19[2] = {cpy_r_r16, cpy_r_r18};
    cpy_r_r20 = (PyObject **)&cpy_r_r19;
    cpy_r_r21 = PyObject_VectorcallMethod(cpy_r_r17, cpy_r_r20, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 56, CPyStatic_globals);
        goto CPyL45;
    } else
        goto CPyL46;
CPyL6: ;
    CPy_DECREF(cpy_r_r16);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r22 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AttributeError("simplified.py", "_create_scene", "HeadlessWindTunnel", "fluid", 57, CPyStatic_globals);
        goto CPyL42;
    }
    CPy_INCREF(cpy_r_r22);
CPyL7: ;
    cpy_r_r23 = CPyStatics[7]; /* 'm' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_r22, cpy_r_r23);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 57, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r25 = CPyStatics[6]; /* 'fill' */
    cpy_r_r26 = PyFloat_FromDouble(0.0);
    PyObject *cpy_r_r27[2] = {cpy_r_r24, cpy_r_r26};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = PyObject_VectorcallMethod(cpy_r_r25, cpy_r_r28, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 57, CPyStatic_globals);
        goto CPyL47;
    } else
        goto CPyL48;
CPyL9: ;
    CPy_DECREF(cpy_r_r24);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r30 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AttributeError("simplified.py", "_create_scene", "HeadlessWindTunnel", "fluid", 58, CPyStatic_globals);
        goto CPyL42;
    }
    CPy_INCREF(cpy_r_r30);
CPyL10: ;
    cpy_r_r31 = CPyStatics[8]; /* 'u' */
    cpy_r_r32 = CPyObject_GetAttr(cpy_r_r30, cpy_r_r31);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 58, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r33 = CPyStatics[6]; /* 'fill' */
    cpy_r_r34 = PyFloat_FromDouble(0.0);
    PyObject *cpy_r_r35[2] = {cpy_r_r32, cpy_r_r34};
    cpy_r_r36 = (PyObject **)&cpy_r_r35;
    cpy_r_r37 = PyObject_VectorcallMethod(cpy_r_r33, cpy_r_r36, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 58, CPyStatic_globals);
        goto CPyL49;
    } else
        goto CPyL50;
CPyL12: ;
    CPy_DECREF(cpy_r_r32);
    CPy_DECREF(cpy_r_r34);
    cpy_r_r38 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AttributeError("simplified.py", "_create_scene", "HeadlessWindTunnel", "fluid", 59, CPyStatic_globals);
        goto CPyL42;
    }
    CPy_INCREF(cpy_r_r38);
CPyL13: ;
    cpy_r_r39 = CPyStatics[9]; /* 'v' */
    cpy_r_r40 = CPyObject_GetAttr(cpy_r_r38, cpy_r_r39);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 59, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r41 = CPyStatics[6]; /* 'fill' */
    cpy_r_r42 = PyFloat_FromDouble(0.0);
    PyObject *cpy_r_r43[2] = {cpy_r_r40, cpy_r_r42};
    cpy_r_r44 = (PyObject **)&cpy_r_r43;
    cpy_r_r45 = PyObject_VectorcallMethod(cpy_r_r41, cpy_r_r44, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 59, CPyStatic_globals);
        goto CPyL51;
    } else
        goto CPyL52;
CPyL15: ;
    CPy_DECREF(cpy_r_r40);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r46 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AttributeError("simplified.py", "_create_scene", "HeadlessWindTunnel", "fluid", 60, CPyStatic_globals);
        goto CPyL42;
    }
    CPy_INCREF(cpy_r_r46);
CPyL16: ;
    cpy_r_r47 = CPyStatics[10]; /* 'p' */
    cpy_r_r48 = CPyObject_GetAttr(cpy_r_r46, cpy_r_r47);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 60, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r49 = CPyStatics[6]; /* 'fill' */
    cpy_r_r50 = PyFloat_FromDouble(0.0);
    PyObject *cpy_r_r51[2] = {cpy_r_r48, cpy_r_r50};
    cpy_r_r52 = (PyObject **)&cpy_r_r51;
    cpy_r_r53 = PyObject_VectorcallMethod(cpy_r_r49, cpy_r_r52, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 60, CPyStatic_globals);
        goto CPyL53;
    } else
        goto CPyL54;
CPyL18: ;
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r50);
    cpy_r_r54 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AttributeError("simplified.py", "_create_scene", "HeadlessWindTunnel", "fluid", 62, CPyStatic_globals);
        goto CPyL42;
    }
    CPy_INCREF(cpy_r_r54);
CPyL19: ;
    cpy_r_r55 = CPyStatics[11]; /* 'numX' */
    cpy_r_r56 = CPyObject_GetAttr(cpy_r_r54, cpy_r_r55);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 62, CPyStatic_globals);
        goto CPyL42;
    }
    if (likely(PyLong_Check(cpy_r_r56)))
        cpy_r_r57 = CPyTagged_FromObject(cpy_r_r56);
    else {
        CPy_TypeError("int", cpy_r_r56); cpy_r_r57 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r56);
    if (unlikely(cpy_r_r57 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 62, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r58 = CPyTagged_Subtract(cpy_r_r57, 2);
    CPyTagged_DECREF(cpy_r_r57);
    cpy_r_r59 = 2;
    CPyTagged_INCREF(cpy_r_r59);
    cpy_r_i = cpy_r_r59;
    CPyTagged_DECREF(cpy_r_i);
CPyL22: ;
    cpy_r_r60 = cpy_r_r59 & 1;
    cpy_r_r61 = cpy_r_r60 != 0;
    if (cpy_r_r61) goto CPyL24;
    cpy_r_r62 = cpy_r_r58 & 1;
    cpy_r_r63 = cpy_r_r62 != 0;
    if (!cpy_r_r63) goto CPyL25;
CPyL24: ;
    cpy_r_r64 = CPyTagged_IsLt_(cpy_r_r59, cpy_r_r58);
    if (cpy_r_r64) {
        goto CPyL26;
    } else
        goto CPyL55;
CPyL25: ;
    cpy_r_r65 = (Py_ssize_t)cpy_r_r59 < (Py_ssize_t)cpy_r_r58;
    if (!cpy_r_r65) goto CPyL55;
CPyL26: ;
    CPyTagged_INCREF(cpy_r_r59);
    cpy_r_i = cpy_r_r59;
    cpy_r_r66 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AttributeError("simplified.py", "_create_scene", "HeadlessWindTunnel", "fluid", 63, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_INCREF(cpy_r_r66);
CPyL27: ;
    cpy_r_r67 = CPyStatics[3]; /* 'numY' */
    cpy_r_r68 = CPyObject_GetAttr(cpy_r_r66, cpy_r_r67);
    CPy_DECREF(cpy_r_r66);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 63, CPyStatic_globals);
        goto CPyL56;
    }
    if (likely(PyLong_Check(cpy_r_r68)))
        cpy_r_r69 = CPyTagged_FromObject(cpy_r_r68);
    else {
        CPy_TypeError("int", cpy_r_r68); cpy_r_r69 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r68);
    if (unlikely(cpy_r_r69 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 63, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r70 = CPyTagged_Subtract(cpy_r_r69, 2);
    CPyTagged_DECREF(cpy_r_r69);
    cpy_r_r71 = 2;
    CPyTagged_INCREF(cpy_r_r71);
    cpy_r_j = cpy_r_r71;
    CPyTagged_DECREF(cpy_r_j);
CPyL30: ;
    cpy_r_r72 = cpy_r_r71 & 1;
    cpy_r_r73 = cpy_r_r72 != 0;
    if (cpy_r_r73) goto CPyL32;
    cpy_r_r74 = cpy_r_r70 & 1;
    cpy_r_r75 = cpy_r_r74 != 0;
    if (!cpy_r_r75) goto CPyL33;
CPyL32: ;
    cpy_r_r76 = CPyTagged_IsLt_(cpy_r_r71, cpy_r_r70);
    if (cpy_r_r76) {
        goto CPyL34;
    } else
        goto CPyL57;
CPyL33: ;
    cpy_r_r77 = (Py_ssize_t)cpy_r_r71 < (Py_ssize_t)cpy_r_r70;
    if (!cpy_r_r77) goto CPyL57;
CPyL34: ;
    CPyTagged_INCREF(cpy_r_r71);
    cpy_r_j = cpy_r_r71;
    cpy_r_r78 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AttributeError("simplified.py", "_create_scene", "HeadlessWindTunnel", "fluid", 64, CPyStatic_globals);
        goto CPyL58;
    }
    CPy_INCREF(cpy_r_r78);
CPyL35: ;
    cpy_r_r79 = CPyStatics[5]; /* 's' */
    cpy_r_r80 = CPyObject_GetAttr(cpy_r_r78, cpy_r_r79);
    CPy_DECREF(cpy_r_r78);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 64, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r81 = CPyDef_HeadlessWindTunnel____idx(cpy_r_self, cpy_r_i, cpy_r_j);
    CPyTagged_DECREF(cpy_r_j);
    if (unlikely(cpy_r_r81 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 64, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r82 = CPyTagged_StealAsObject(cpy_r_r81);
    cpy_r_r83 = PyFloat_FromDouble(1.0);
    cpy_r_r84 = PyObject_SetItem(cpy_r_r80, cpy_r_r82, cpy_r_r83);
    CPy_DECREF(cpy_r_r80);
    CPy_DECREF(cpy_r_r82);
    CPy_DECREF(cpy_r_r83);
    cpy_r_r85 = cpy_r_r84 >= 0;
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 64, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r86 = CPyTagged_Add(cpy_r_r71, 2);
    CPyTagged_DECREF(cpy_r_r71);
    cpy_r_r71 = cpy_r_r86;
    goto CPyL30;
CPyL39: ;
    cpy_r_r87 = CPyTagged_Add(cpy_r_r59, 2);
    CPyTagged_DECREF(cpy_r_r59);
    cpy_r_r59 = cpy_r_r87;
    goto CPyL22;
CPyL40: ;
    cpy_r_r88 = CPyDef_HeadlessWindTunnel___apply_inlet(cpy_r_self);
    if (unlikely(cpy_r_r88 == 2)) {
        CPy_AddTraceback("simplified.py", "_create_scene", 66, CPyStatic_globals);
        goto CPyL42;
    }
    return 1;
CPyL42: ;
    cpy_r_r89 = 2;
    return cpy_r_r89;
CPyL43: ;
    CPyTagged_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_r2);
    goto CPyL42;
CPyL44: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    goto CPyL42;
CPyL45: ;
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r18);
    goto CPyL42;
CPyL46: ;
    CPy_DECREF(cpy_r_r21);
    goto CPyL6;
CPyL47: ;
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r26);
    goto CPyL42;
CPyL48: ;
    CPy_DECREF(cpy_r_r29);
    goto CPyL9;
CPyL49: ;
    CPy_DecRef(cpy_r_r32);
    CPy_DecRef(cpy_r_r34);
    goto CPyL42;
CPyL50: ;
    CPy_DECREF(cpy_r_r37);
    goto CPyL12;
CPyL51: ;
    CPy_DecRef(cpy_r_r40);
    CPy_DecRef(cpy_r_r42);
    goto CPyL42;
CPyL52: ;
    CPy_DECREF(cpy_r_r45);
    goto CPyL15;
CPyL53: ;
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_r50);
    goto CPyL42;
CPyL54: ;
    CPy_DECREF(cpy_r_r53);
    goto CPyL18;
CPyL55: ;
    CPyTagged_DECREF(cpy_r_r58);
    CPyTagged_DECREF(cpy_r_r59);
    goto CPyL40;
CPyL56: ;
    CPyTagged_DecRef(cpy_r_r58);
    CPyTagged_DecRef(cpy_r_r59);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL42;
CPyL57: ;
    CPyTagged_DECREF(cpy_r_i);
    CPyTagged_DECREF(cpy_r_r70);
    CPyTagged_DECREF(cpy_r_r71);
    goto CPyL39;
CPyL58: ;
    CPyTagged_DecRef(cpy_r_r58);
    CPyTagged_DecRef(cpy_r_r59);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r70);
    CPyTagged_DecRef(cpy_r_r71);
    CPyTagged_DecRef(cpy_r_j);
    goto CPyL42;
CPyL59: ;
    CPyTagged_DecRef(cpy_r_r58);
    CPyTagged_DecRef(cpy_r_r59);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r70);
    CPyTagged_DecRef(cpy_r_r71);
    CPy_DecRef(cpy_r_r80);
    goto CPyL42;
CPyL60: ;
    CPyTagged_DecRef(cpy_r_r58);
    CPyTagged_DecRef(cpy_r_r59);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r70);
    CPyTagged_DecRef(cpy_r_r71);
    goto CPyL42;
}
    
    PyObject *CPyPy_HeadlessWindTunnel____create_scene(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        PyObject *obj_self = self;
        static const char * const kwlist[] = {0};
        static CPyArg_Parser parser = {":_create_scene", kwlist, 0};
        if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
            return NULL;
        }
        PyObject *arg_self;
        if (likely(Py_TYPE(obj_self) == CPyType_HeadlessWindTunnel))
            arg_self = obj_self;
        else {
            CPy_TypeError("simplified.HeadlessWindTunnel", obj_self); 
            goto fail;
        }
        char retval = CPyDef_HeadlessWindTunnel____create_scene(arg_self);
        if (retval == 2) {
            return NULL;
        }
        PyObject *retbox = Py_None;
        CPy_INCREF(retbox);
        return retbox;
fail: ;
        CPy_AddTraceback("simplified.py", "_create_scene", 54, CPyStatic_globals);
        return NULL;
    }
    
char CPyDef_HeadlessWindTunnel___apply_inlet(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    CPyTagged cpy_r_r2;
    CPyTagged cpy_r_r3;
    CPyTagged cpy_r_r4;
    int64_t cpy_r_r5;
    char cpy_r_r6;
    int64_t cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    char cpy_r_r10;
    CPyTagged cpy_r_r11;
    CPyTagged cpy_r_half_height;
    CPyTagged cpy_r_r12;
    CPyTagged cpy_r_r13;
    CPyTagged cpy_r_r14;
    CPyTagged cpy_r_r15;
    CPyTagged cpy_r_r16;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r17;
    char cpy_r_r18;
    int64_t cpy_r_r19;
    char cpy_r_r20;
    char cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    CPyTagged cpy_r_r26;
    CPyTagged cpy_r_r27;
    CPyTagged cpy_r_r28;
    CPyTagged cpy_r_j;
    int64_t cpy_r_r29;
    char cpy_r_r30;
    int64_t cpy_r_r31;
    char cpy_r_r32;
    char cpy_r_r33;
    char cpy_r_r34;
    CPyTagged cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    int32_t cpy_r_r41;
    char cpy_r_r42;
    int64_t cpy_r_r43;
    char cpy_r_r44;
    int64_t cpy_r_r45;
    char cpy_r_r46;
    char cpy_r_r47;
    char cpy_r_r48;
    char cpy_r_r49;
    char cpy_r_r50;
    int64_t cpy_r_r51;
    char cpy_r_r52;
    int64_t cpy_r_r53;
    char cpy_r_r54;
    char cpy_r_r55;
    char cpy_r_r56;
    char cpy_r_r57;
    char cpy_r_r58;
    double cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    int32_t cpy_r_r65;
    char cpy_r_r66;
    double cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    int32_t cpy_r_r73;
    char cpy_r_r74;
    double cpy_r_r75;
    double cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    int32_t cpy_r_r82;
    char cpy_r_r83;
    double cpy_r_r84;
    double cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    int32_t cpy_r_r91;
    char cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    int32_t cpy_r_r98;
    char cpy_r_r99;
    CPyTagged cpy_r_r100;
    CPyTagged cpy_r_r101;
    char cpy_r_r102;
    cpy_r_r0 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_h;
    CPyTagged_INCREF(cpy_r_r0);
    cpy_r_r1 = CPyTagged_Rshift(cpy_r_r0, 2);
    CPyTagged_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 69, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r2 = CPyTagged_Add(cpy_r_r1, 2);
    CPyTagged_DECREF(cpy_r_r1);
    cpy_r_r3 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_h;
    CPyTagged_INCREF(cpy_r_r3);
    cpy_r_r4 = CPyTagged_FloorDivide(cpy_r_r3, 12);
    CPyTagged_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 70, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r5 = cpy_r_r4 & 1;
    cpy_r_r6 = cpy_r_r5 != 0;
    if (cpy_r_r6) goto CPyL4;
    cpy_r_r7 = 8 & 1;
    cpy_r_r8 = cpy_r_r7 != 0;
    if (!cpy_r_r8) goto CPyL5;
CPyL4: ;
    cpy_r_r9 = CPyTagged_IsLt_(8, cpy_r_r4);
    if (cpy_r_r9) {
        goto CPyL6;
    } else
        goto CPyL56;
CPyL5: ;
    cpy_r_r10 = (Py_ssize_t)cpy_r_r4 > (Py_ssize_t)8;
    if (!cpy_r_r10) goto CPyL56;
CPyL6: ;
    cpy_r_r11 = cpy_r_r4;
    goto CPyL8;
CPyL7: ;
    cpy_r_r11 = 8;
CPyL8: ;
    cpy_r_half_height = cpy_r_r11;
    cpy_r_r12 = CPyTagged_Subtract(cpy_r_r2, cpy_r_half_height);
    cpy_r_r13 = CPyTagged_Add(cpy_r_r2, cpy_r_half_height);
    CPyTagged_DECREF(cpy_r_r2);
    CPyTagged_DECREF(cpy_r_half_height);
    cpy_r_r14 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_inlet_columns;
    cpy_r_r15 = CPyTagged_Add(cpy_r_r14, 2);
    cpy_r_r16 = 2;
    CPyTagged_INCREF(cpy_r_r16);
    cpy_r_i = cpy_r_r16;
    CPyTagged_DECREF(cpy_r_i);
CPyL9: ;
    cpy_r_r17 = cpy_r_r16 & 1;
    cpy_r_r18 = cpy_r_r17 != 0;
    if (cpy_r_r18) goto CPyL11;
    cpy_r_r19 = cpy_r_r15 & 1;
    cpy_r_r20 = cpy_r_r19 != 0;
    if (!cpy_r_r20) goto CPyL12;
CPyL11: ;
    cpy_r_r21 = CPyTagged_IsLt_(cpy_r_r16, cpy_r_r15);
    if (cpy_r_r21) {
        goto CPyL13;
    } else
        goto CPyL57;
CPyL12: ;
    cpy_r_r22 = (Py_ssize_t)cpy_r_r16 < (Py_ssize_t)cpy_r_r15;
    if (!cpy_r_r22) goto CPyL57;
CPyL13: ;
    CPyTagged_INCREF(cpy_r_r16);
    cpy_r_i = cpy_r_r16;
    cpy_r_r23 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AttributeError("simplified.py", "apply_inlet", "HeadlessWindTunnel", "fluid", 75, CPyStatic_globals);
        goto CPyL58;
    }
    CPy_INCREF(cpy_r_r23);
CPyL14: ;
    cpy_r_r24 = CPyStatics[3]; /* 'numY' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 75, CPyStatic_globals);
        goto CPyL58;
    }
    if (likely(PyLong_Check(cpy_r_r25)))
        cpy_r_r26 = CPyTagged_FromObject(cpy_r_r25);
    else {
        CPy_TypeError("int", cpy_r_r25); cpy_r_r26 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 75, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r27 = CPyTagged_Subtract(cpy_r_r26, 2);
    CPyTagged_DECREF(cpy_r_r26);
    cpy_r_r28 = 2;
    CPyTagged_INCREF(cpy_r_r28);
    cpy_r_j = cpy_r_r28;
    CPyTagged_DECREF(cpy_r_j);
CPyL17: ;
    cpy_r_r29 = cpy_r_r28 & 1;
    cpy_r_r30 = cpy_r_r29 != 0;
    if (cpy_r_r30) goto CPyL19;
    cpy_r_r31 = cpy_r_r27 & 1;
    cpy_r_r32 = cpy_r_r31 != 0;
    if (!cpy_r_r32) goto CPyL20;
CPyL19: ;
    cpy_r_r33 = CPyTagged_IsLt_(cpy_r_r28, cpy_r_r27);
    if (cpy_r_r33) {
        goto CPyL21;
    } else
        goto CPyL59;
CPyL20: ;
    cpy_r_r34 = (Py_ssize_t)cpy_r_r28 < (Py_ssize_t)cpy_r_r27;
    if (!cpy_r_r34) goto CPyL59;
CPyL21: ;
    CPyTagged_INCREF(cpy_r_r28);
    cpy_r_j = cpy_r_r28;
    cpy_r_r35 = CPyDef_HeadlessWindTunnel____idx(cpy_r_self, cpy_r_i, cpy_r_j);
    if (unlikely(cpy_r_r35 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 76, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r36 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AttributeError("simplified.py", "apply_inlet", "HeadlessWindTunnel", "fluid", 77, CPyStatic_globals);
        goto CPyL61;
    }
    CPy_INCREF(cpy_r_r36);
CPyL23: ;
    cpy_r_r37 = CPyStatics[5]; /* 's' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_r36, cpy_r_r37);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 77, CPyStatic_globals);
        goto CPyL61;
    }
    CPyTagged_INCREF(cpy_r_r35);
    cpy_r_r39 = CPyTagged_StealAsObject(cpy_r_r35);
    cpy_r_r40 = PyFloat_FromDouble(1.0);
    cpy_r_r41 = PyObject_SetItem(cpy_r_r38, cpy_r_r39, cpy_r_r40);
    CPy_DECREF(cpy_r_r38);
    CPy_DECREF(cpy_r_r39);
    CPy_DECREF(cpy_r_r40);
    cpy_r_r42 = cpy_r_r41 >= 0;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 77, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r43 = cpy_r_r12 & 1;
    cpy_r_r44 = cpy_r_r43 != 0;
    if (cpy_r_r44) goto CPyL27;
    cpy_r_r45 = cpy_r_j & 1;
    cpy_r_r46 = cpy_r_r45 != 0;
    if (!cpy_r_r46) goto CPyL28;
CPyL27: ;
    cpy_r_r47 = CPyTagged_IsLt_(cpy_r_j, cpy_r_r12);
    cpy_r_r48 = cpy_r_r47 ^ 1;
    cpy_r_r49 = cpy_r_r48;
    goto CPyL29;
CPyL28: ;
    cpy_r_r50 = (Py_ssize_t)cpy_r_r12 <= (Py_ssize_t)cpy_r_j;
    cpy_r_r49 = cpy_r_r50;
CPyL29: ;
    if (cpy_r_r49) {
        goto CPyL31;
    } else
        goto CPyL62;
CPyL30: ;
    if (cpy_r_r49) {
        goto CPyL36;
    } else
        goto CPyL42;
CPyL31: ;
    cpy_r_r51 = cpy_r_j & 1;
    cpy_r_r52 = cpy_r_r51 != 0;
    if (cpy_r_r52) goto CPyL33;
    cpy_r_r53 = cpy_r_r13 & 1;
    cpy_r_r54 = cpy_r_r53 != 0;
    if (!cpy_r_r54) goto CPyL34;
CPyL33: ;
    cpy_r_r55 = CPyTagged_IsLt_(cpy_r_r13, cpy_r_j);
    cpy_r_r56 = cpy_r_r55 ^ 1;
    cpy_r_r57 = cpy_r_r56;
    goto CPyL35;
CPyL34: ;
    cpy_r_r58 = (Py_ssize_t)cpy_r_j <= (Py_ssize_t)cpy_r_r13;
    cpy_r_r57 = cpy_r_r58;
CPyL35: ;
    CPyTagged_DECREF(cpy_r_j);
    if (!cpy_r_r57) goto CPyL42;
CPyL36: ;
    cpy_r_r59 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_flow_speed;
    cpy_r_r60 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AttributeError("simplified.py", "apply_inlet", "HeadlessWindTunnel", "fluid", 79, CPyStatic_globals);
        goto CPyL63;
    }
    CPy_INCREF(cpy_r_r60);
CPyL37: ;
    cpy_r_r61 = CPyStatics[8]; /* 'u' */
    cpy_r_r62 = CPyObject_GetAttr(cpy_r_r60, cpy_r_r61);
    CPy_DECREF(cpy_r_r60);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 79, CPyStatic_globals);
        goto CPyL63;
    }
    CPyTagged_INCREF(cpy_r_r35);
    cpy_r_r63 = CPyTagged_StealAsObject(cpy_r_r35);
    cpy_r_r64 = PyFloat_FromDouble(cpy_r_r59);
    cpy_r_r65 = PyObject_SetItem(cpy_r_r62, cpy_r_r63, cpy_r_r64);
    CPy_DECREF(cpy_r_r62);
    CPy_DECREF(cpy_r_r63);
    CPy_DECREF(cpy_r_r64);
    cpy_r_r66 = cpy_r_r65 >= 0;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 79, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r67 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_smoke_strength;
    cpy_r_r68 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AttributeError("simplified.py", "apply_inlet", "HeadlessWindTunnel", "fluid", 80, CPyStatic_globals);
        goto CPyL63;
    }
    CPy_INCREF(cpy_r_r68);
CPyL40: ;
    cpy_r_r69 = CPyStatics[7]; /* 'm' */
    cpy_r_r70 = CPyObject_GetAttr(cpy_r_r68, cpy_r_r69);
    CPy_DECREF(cpy_r_r68);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 80, CPyStatic_globals);
        goto CPyL63;
    }
    CPyTagged_INCREF(cpy_r_r35);
    cpy_r_r71 = CPyTagged_StealAsObject(cpy_r_r35);
    cpy_r_r72 = PyFloat_FromDouble(cpy_r_r67);
    cpy_r_r73 = PyObject_SetItem(cpy_r_r70, cpy_r_r71, cpy_r_r72);
    CPy_DECREF(cpy_r_r70);
    CPy_DECREF(cpy_r_r71);
    CPy_DECREF(cpy_r_r72);
    cpy_r_r74 = cpy_r_r73 >= 0;
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 80, CPyStatic_globals);
        goto CPyL63;
    } else
        goto CPyL48;
CPyL42: ;
    cpy_r_r75 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_flow_speed;
    cpy_r_r76 = cpy_r_r75 * 0.25;
    cpy_r_r77 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AttributeError("simplified.py", "apply_inlet", "HeadlessWindTunnel", "fluid", 82, CPyStatic_globals);
        goto CPyL63;
    }
    CPy_INCREF(cpy_r_r77);
CPyL43: ;
    cpy_r_r78 = CPyStatics[8]; /* 'u' */
    cpy_r_r79 = CPyObject_GetAttr(cpy_r_r77, cpy_r_r78);
    CPy_DECREF(cpy_r_r77);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 82, CPyStatic_globals);
        goto CPyL63;
    }
    CPyTagged_INCREF(cpy_r_r35);
    cpy_r_r80 = CPyTagged_StealAsObject(cpy_r_r35);
    cpy_r_r81 = PyFloat_FromDouble(cpy_r_r76);
    cpy_r_r82 = PyObject_SetItem(cpy_r_r79, cpy_r_r80, cpy_r_r81);
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_r80);
    CPy_DECREF(cpy_r_r81);
    cpy_r_r83 = cpy_r_r82 >= 0;
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 82, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r84 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_smoke_strength;
    cpy_r_r85 = cpy_r_r84 * 0.08;
    cpy_r_r86 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AttributeError("simplified.py", "apply_inlet", "HeadlessWindTunnel", "fluid", 83, CPyStatic_globals);
        goto CPyL63;
    }
    CPy_INCREF(cpy_r_r86);
CPyL46: ;
    cpy_r_r87 = CPyStatics[7]; /* 'm' */
    cpy_r_r88 = CPyObject_GetAttr(cpy_r_r86, cpy_r_r87);
    CPy_DECREF(cpy_r_r86);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 83, CPyStatic_globals);
        goto CPyL63;
    }
    CPyTagged_INCREF(cpy_r_r35);
    cpy_r_r89 = CPyTagged_StealAsObject(cpy_r_r35);
    cpy_r_r90 = PyFloat_FromDouble(cpy_r_r85);
    cpy_r_r91 = PyObject_SetItem(cpy_r_r88, cpy_r_r89, cpy_r_r90);
    CPy_DECREF(cpy_r_r88);
    CPy_DECREF(cpy_r_r89);
    CPy_DECREF(cpy_r_r90);
    cpy_r_r92 = cpy_r_r91 >= 0;
    if (unlikely(!cpy_r_r92)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 83, CPyStatic_globals);
        goto CPyL63;
    }
CPyL48: ;
    cpy_r_r93 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AttributeError("simplified.py", "apply_inlet", "HeadlessWindTunnel", "fluid", 84, CPyStatic_globals);
        goto CPyL63;
    }
    CPy_INCREF(cpy_r_r93);
CPyL49: ;
    cpy_r_r94 = CPyStatics[9]; /* 'v' */
    cpy_r_r95 = CPyObject_GetAttr(cpy_r_r93, cpy_r_r94);
    CPy_DECREF(cpy_r_r93);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 84, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r96 = CPyTagged_StealAsObject(cpy_r_r35);
    cpy_r_r97 = PyFloat_FromDouble(0.0);
    cpy_r_r98 = PyObject_SetItem(cpy_r_r95, cpy_r_r96, cpy_r_r97);
    CPy_DECREF(cpy_r_r95);
    CPy_DECREF(cpy_r_r96);
    CPy_DECREF(cpy_r_r97);
    cpy_r_r99 = cpy_r_r98 >= 0;
    if (unlikely(!cpy_r_r99)) {
        CPy_AddTraceback("simplified.py", "apply_inlet", 84, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r100 = CPyTagged_Add(cpy_r_r28, 2);
    CPyTagged_DECREF(cpy_r_r28);
    cpy_r_r28 = cpy_r_r100;
    goto CPyL17;
CPyL52: ;
    cpy_r_r101 = CPyTagged_Add(cpy_r_r16, 2);
    CPyTagged_DECREF(cpy_r_r16);
    cpy_r_r16 = cpy_r_r101;
    goto CPyL9;
CPyL53: ;
    return 1;
CPyL54: ;
    cpy_r_r102 = 2;
    return cpy_r_r102;
CPyL55: ;
    CPyTagged_DecRef(cpy_r_r2);
    goto CPyL54;
CPyL56: ;
    CPyTagged_DECREF(cpy_r_r4);
    goto CPyL7;
CPyL57: ;
    CPyTagged_DECREF(cpy_r_r12);
    CPyTagged_DECREF(cpy_r_r13);
    CPyTagged_DECREF(cpy_r_r15);
    CPyTagged_DECREF(cpy_r_r16);
    goto CPyL53;
CPyL58: ;
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r15);
    CPyTagged_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL54;
CPyL59: ;
    CPyTagged_DECREF(cpy_r_i);
    CPyTagged_DECREF(cpy_r_r27);
    CPyTagged_DECREF(cpy_r_r28);
    goto CPyL52;
CPyL60: ;
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r15);
    CPyTagged_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r27);
    CPyTagged_DecRef(cpy_r_r28);
    CPyTagged_DecRef(cpy_r_j);
    goto CPyL54;
CPyL61: ;
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r15);
    CPyTagged_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r27);
    CPyTagged_DecRef(cpy_r_r28);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r35);
    goto CPyL54;
CPyL62: ;
    CPyTagged_DECREF(cpy_r_j);
    goto CPyL30;
CPyL63: ;
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r15);
    CPyTagged_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r27);
    CPyTagged_DecRef(cpy_r_r28);
    CPyTagged_DecRef(cpy_r_r35);
    goto CPyL54;
CPyL64: ;
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r15);
    CPyTagged_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r27);
    CPyTagged_DecRef(cpy_r_r28);
    goto CPyL54;
}
    
    PyObject *CPyPy_HeadlessWindTunnel___apply_inlet(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        PyObject *obj_self = self;
        static const char * const kwlist[] = {0};
        static CPyArg_Parser parser = {":apply_inlet", kwlist, 0};
        if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
            return NULL;
        }
        PyObject *arg_self;
        if (likely(Py_TYPE(obj_self) == CPyType_HeadlessWindTunnel))
            arg_self = obj_self;
        else {
            CPy_TypeError("simplified.HeadlessWindTunnel", obj_self); 
            goto fail;
        }
        char retval = CPyDef_HeadlessWindTunnel___apply_inlet(arg_self);
        if (retval == 2) {
            return NULL;
        }
        PyObject *retbox = Py_None;
        CPy_INCREF(retbox);
        return retbox;
fail: ;
        CPy_AddTraceback("simplified.py", "apply_inlet", 68, CPyStatic_globals);
        return NULL;
    }
    
char CPyDef_HeadlessWindTunnel___set_obstacle_circle(PyObject *cpy_r_self, CPyTagged cpy_r_cx, CPyTagged cpy_r_cy, CPyTagged cpy_r_radius, char cpy_r_solid) {
    CPyTagged cpy_r_r0;
    int64_t cpy_r_r1;
    char cpy_r_r2;
    int64_t cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    CPyTagged cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    CPyTagged cpy_r_r11;
    CPyTagged cpy_r_r12;
    CPyTagged cpy_r_r13;
    CPyTagged cpy_r_r14;
    int64_t cpy_r_r15;
    char cpy_r_r16;
    int64_t cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    char cpy_r_r20;
    CPyTagged cpy_r_r21;
    CPyTagged cpy_r_r22;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r23;
    char cpy_r_r24;
    int64_t cpy_r_r25;
    char cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
    CPyTagged cpy_r_r29;
    int64_t cpy_r_r30;
    char cpy_r_r31;
    int64_t cpy_r_r32;
    char cpy_r_r33;
    char cpy_r_r34;
    char cpy_r_r35;
    CPyTagged cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    CPyTagged cpy_r_r40;
    CPyTagged cpy_r_r41;
    CPyTagged cpy_r_r42;
    CPyTagged cpy_r_r43;
    int64_t cpy_r_r44;
    char cpy_r_r45;
    int64_t cpy_r_r46;
    char cpy_r_r47;
    char cpy_r_r48;
    char cpy_r_r49;
    CPyTagged cpy_r_r50;
    CPyTagged cpy_r_r51;
    CPyTagged cpy_r_j;
    int64_t cpy_r_r52;
    char cpy_r_r53;
    int64_t cpy_r_r54;
    char cpy_r_r55;
    char cpy_r_r56;
    char cpy_r_r57;
    CPyTagged cpy_r_r58;
    CPyTagged cpy_r_r59;
    CPyTagged cpy_r_r60;
    CPyTagged cpy_r_r61;
    CPyTagged cpy_r_r62;
    CPyTagged cpy_r_r63;
    CPyTagged cpy_r_r64;
    CPyTagged cpy_r_r65;
    int64_t cpy_r_r66;
    char cpy_r_r67;
    int64_t cpy_r_r68;
    char cpy_r_r69;
    char cpy_r_r70;
    char cpy_r_r71;
    char cpy_r_r72;
    CPyTagged cpy_r_r73;
    CPyTagged cpy_r_r74;
    int64_t cpy_r_r75;
    char cpy_r_r76;
    int64_t cpy_r_r77;
    char cpy_r_r78;
    char cpy_r_r79;
    char cpy_r_r80;
    char cpy_r_r81;
    char cpy_r_r82;
    CPyTagged cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    int32_t cpy_r_r89;
    char cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    int32_t cpy_r_r96;
    char cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    int32_t cpy_r_r103;
    char cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    int32_t cpy_r_r110;
    char cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    int32_t cpy_r_r117;
    char cpy_r_r118;
    CPyTagged cpy_r_r119;
    CPyTagged cpy_r_r120;
    char cpy_r_r121;
    if (cpy_r_solid != 2) goto CPyL2;
    cpy_r_solid = 1;
CPyL2: ;
    cpy_r_r0 = CPyTagged_Subtract(cpy_r_cx, cpy_r_radius);
    cpy_r_r1 = cpy_r_r0 & 1;
    cpy_r_r2 = cpy_r_r1 != 0;
    if (cpy_r_r2) goto CPyL4;
    cpy_r_r3 = 2 & 1;
    cpy_r_r4 = cpy_r_r3 != 0;
    if (!cpy_r_r4) goto CPyL5;
CPyL4: ;
    cpy_r_r5 = CPyTagged_IsLt_(2, cpy_r_r0);
    if (cpy_r_r5) {
        goto CPyL6;
    } else
        goto CPyL73;
CPyL5: ;
    cpy_r_r6 = (Py_ssize_t)cpy_r_r0 > (Py_ssize_t)2;
    if (!cpy_r_r6) goto CPyL73;
CPyL6: ;
    cpy_r_r7 = cpy_r_r0;
    goto CPyL8;
CPyL7: ;
    cpy_r_r7 = 2;
CPyL8: ;
    cpy_r_r8 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("simplified.py", "set_obstacle_circle", "HeadlessWindTunnel", "fluid", 87, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_INCREF(cpy_r_r8);
CPyL9: ;
    cpy_r_r9 = CPyStatics[11]; /* 'numX' */
    cpy_r_r10 = CPyObject_GetAttr(cpy_r_r8, cpy_r_r9);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 87, CPyStatic_globals);
        goto CPyL74;
    }
    if (likely(PyLong_Check(cpy_r_r10)))
        cpy_r_r11 = CPyTagged_FromObject(cpy_r_r10);
    else {
        CPy_TypeError("int", cpy_r_r10); cpy_r_r11 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 87, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r12 = CPyTagged_Subtract(cpy_r_r11, 2);
    CPyTagged_DECREF(cpy_r_r11);
    cpy_r_r13 = CPyTagged_Add(cpy_r_cx, cpy_r_radius);
    cpy_r_r14 = CPyTagged_Add(cpy_r_r13, 2);
    CPyTagged_DECREF(cpy_r_r13);
    cpy_r_r15 = cpy_r_r14 & 1;
    cpy_r_r16 = cpy_r_r15 != 0;
    if (cpy_r_r16) goto CPyL13;
    cpy_r_r17 = cpy_r_r12 & 1;
    cpy_r_r18 = cpy_r_r17 != 0;
    if (!cpy_r_r18) goto CPyL14;
CPyL13: ;
    cpy_r_r19 = CPyTagged_IsLt_(cpy_r_r14, cpy_r_r12);
    if (cpy_r_r19) {
        goto CPyL75;
    } else
        goto CPyL76;
CPyL14: ;
    cpy_r_r20 = (Py_ssize_t)cpy_r_r14 < (Py_ssize_t)cpy_r_r12;
    if (cpy_r_r20) {
        goto CPyL75;
    } else
        goto CPyL76;
CPyL15: ;
    cpy_r_r21 = cpy_r_r14;
    goto CPyL17;
CPyL16: ;
    cpy_r_r21 = cpy_r_r12;
CPyL17: ;
    cpy_r_r22 = cpy_r_r7;
    CPyTagged_INCREF(cpy_r_r22);
    cpy_r_i = cpy_r_r22;
    CPyTagged_DECREF(cpy_r_i);
CPyL18: ;
    cpy_r_r23 = cpy_r_r22 & 1;
    cpy_r_r24 = cpy_r_r23 != 0;
    if (cpy_r_r24) goto CPyL20;
    cpy_r_r25 = cpy_r_r21 & 1;
    cpy_r_r26 = cpy_r_r25 != 0;
    if (!cpy_r_r26) goto CPyL21;
CPyL20: ;
    cpy_r_r27 = CPyTagged_IsLt_(cpy_r_r22, cpy_r_r21);
    if (cpy_r_r27) {
        goto CPyL22;
    } else
        goto CPyL77;
CPyL21: ;
    cpy_r_r28 = (Py_ssize_t)cpy_r_r22 < (Py_ssize_t)cpy_r_r21;
    if (!cpy_r_r28) goto CPyL77;
CPyL22: ;
    CPyTagged_INCREF(cpy_r_r22);
    cpy_r_i = cpy_r_r22;
    cpy_r_r29 = CPyTagged_Subtract(cpy_r_cy, cpy_r_radius);
    cpy_r_r30 = cpy_r_r29 & 1;
    cpy_r_r31 = cpy_r_r30 != 0;
    if (cpy_r_r31) goto CPyL24;
    cpy_r_r32 = 2 & 1;
    cpy_r_r33 = cpy_r_r32 != 0;
    if (!cpy_r_r33) goto CPyL25;
CPyL24: ;
    cpy_r_r34 = CPyTagged_IsLt_(2, cpy_r_r29);
    if (cpy_r_r34) {
        goto CPyL26;
    } else
        goto CPyL78;
CPyL25: ;
    cpy_r_r35 = (Py_ssize_t)cpy_r_r29 > (Py_ssize_t)2;
    if (!cpy_r_r35) goto CPyL78;
CPyL26: ;
    cpy_r_r36 = cpy_r_r29;
    goto CPyL28;
CPyL27: ;
    cpy_r_r36 = 2;
CPyL28: ;
    cpy_r_r37 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AttributeError("simplified.py", "set_obstacle_circle", "HeadlessWindTunnel", "fluid", 88, CPyStatic_globals);
        goto CPyL79;
    }
    CPy_INCREF(cpy_r_r37);
CPyL29: ;
    cpy_r_r38 = CPyStatics[3]; /* 'numY' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r37, cpy_r_r38);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 88, CPyStatic_globals);
        goto CPyL79;
    }
    if (likely(PyLong_Check(cpy_r_r39)))
        cpy_r_r40 = CPyTagged_FromObject(cpy_r_r39);
    else {
        CPy_TypeError("int", cpy_r_r39); cpy_r_r40 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 88, CPyStatic_globals);
        goto CPyL79;
    }
    cpy_r_r41 = CPyTagged_Subtract(cpy_r_r40, 2);
    CPyTagged_DECREF(cpy_r_r40);
    cpy_r_r42 = CPyTagged_Add(cpy_r_cy, cpy_r_radius);
    cpy_r_r43 = CPyTagged_Add(cpy_r_r42, 2);
    CPyTagged_DECREF(cpy_r_r42);
    cpy_r_r44 = cpy_r_r43 & 1;
    cpy_r_r45 = cpy_r_r44 != 0;
    if (cpy_r_r45) goto CPyL33;
    cpy_r_r46 = cpy_r_r41 & 1;
    cpy_r_r47 = cpy_r_r46 != 0;
    if (!cpy_r_r47) goto CPyL34;
CPyL33: ;
    cpy_r_r48 = CPyTagged_IsLt_(cpy_r_r43, cpy_r_r41);
    if (cpy_r_r48) {
        goto CPyL80;
    } else
        goto CPyL81;
CPyL34: ;
    cpy_r_r49 = (Py_ssize_t)cpy_r_r43 < (Py_ssize_t)cpy_r_r41;
    if (cpy_r_r49) {
        goto CPyL80;
    } else
        goto CPyL81;
CPyL35: ;
    cpy_r_r50 = cpy_r_r43;
    goto CPyL37;
CPyL36: ;
    cpy_r_r50 = cpy_r_r41;
CPyL37: ;
    cpy_r_r51 = cpy_r_r36;
    CPyTagged_INCREF(cpy_r_r51);
    cpy_r_j = cpy_r_r51;
    CPyTagged_DECREF(cpy_r_j);
CPyL38: ;
    cpy_r_r52 = cpy_r_r51 & 1;
    cpy_r_r53 = cpy_r_r52 != 0;
    if (cpy_r_r53) goto CPyL40;
    cpy_r_r54 = cpy_r_r50 & 1;
    cpy_r_r55 = cpy_r_r54 != 0;
    if (!cpy_r_r55) goto CPyL41;
CPyL40: ;
    cpy_r_r56 = CPyTagged_IsLt_(cpy_r_r51, cpy_r_r50);
    if (cpy_r_r56) {
        goto CPyL42;
    } else
        goto CPyL82;
CPyL41: ;
    cpy_r_r57 = (Py_ssize_t)cpy_r_r51 < (Py_ssize_t)cpy_r_r50;
    if (!cpy_r_r57) goto CPyL82;
CPyL42: ;
    CPyTagged_INCREF(cpy_r_r51);
    cpy_r_j = cpy_r_r51;
    cpy_r_r58 = CPyTagged_Subtract(cpy_r_i, cpy_r_cx);
    cpy_r_r59 = CPyTagged_Subtract(cpy_r_i, cpy_r_cx);
    cpy_r_r60 = CPyTagged_Multiply(cpy_r_r58, cpy_r_r59);
    CPyTagged_DECREF(cpy_r_r58);
    CPyTagged_DECREF(cpy_r_r59);
    cpy_r_r61 = CPyTagged_Subtract(cpy_r_j, cpy_r_cy);
    cpy_r_r62 = CPyTagged_Subtract(cpy_r_j, cpy_r_cy);
    cpy_r_r63 = CPyTagged_Multiply(cpy_r_r61, cpy_r_r62);
    CPyTagged_DECREF(cpy_r_r61);
    CPyTagged_DECREF(cpy_r_r62);
    cpy_r_r64 = CPyTagged_Add(cpy_r_r60, cpy_r_r63);
    CPyTagged_DECREF(cpy_r_r60);
    CPyTagged_DECREF(cpy_r_r63);
    cpy_r_r65 = CPyTagged_Multiply(cpy_r_radius, cpy_r_radius);
    cpy_r_r66 = cpy_r_r64 & 1;
    cpy_r_r67 = cpy_r_r66 != 0;
    if (cpy_r_r67) goto CPyL44;
    cpy_r_r68 = cpy_r_r65 & 1;
    cpy_r_r69 = cpy_r_r68 != 0;
    if (!cpy_r_r69) goto CPyL45;
CPyL44: ;
    cpy_r_r70 = CPyTagged_IsLt_(cpy_r_r65, cpy_r_r64);
    cpy_r_r71 = cpy_r_r70;
    goto CPyL46;
CPyL45: ;
    cpy_r_r72 = (Py_ssize_t)cpy_r_r64 > (Py_ssize_t)cpy_r_r65;
    cpy_r_r71 = cpy_r_r72;
CPyL46: ;
    CPyTagged_DECREF(cpy_r_r64);
    CPyTagged_DECREF(cpy_r_r65);
    if (cpy_r_r71) goto CPyL83;
    cpy_r_r73 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_inlet_columns;
    cpy_r_r74 = CPyTagged_Add(cpy_r_r73, 2);
    cpy_r_r75 = cpy_r_i & 1;
    cpy_r_r76 = cpy_r_r75 != 0;
    if (cpy_r_r76) goto CPyL49;
    cpy_r_r77 = cpy_r_r74 & 1;
    cpy_r_r78 = cpy_r_r77 != 0;
    if (!cpy_r_r78) goto CPyL50;
CPyL49: ;
    cpy_r_r79 = CPyTagged_IsLt_(cpy_r_r74, cpy_r_i);
    cpy_r_r80 = cpy_r_r79 ^ 1;
    cpy_r_r81 = cpy_r_r80;
    goto CPyL51;
CPyL50: ;
    cpy_r_r82 = (Py_ssize_t)cpy_r_i <= (Py_ssize_t)cpy_r_r74;
    cpy_r_r81 = cpy_r_r82;
CPyL51: ;
    CPyTagged_DECREF(cpy_r_r74);
    if (cpy_r_r81) goto CPyL83;
    cpy_r_r83 = CPyDef_HeadlessWindTunnel____idx(cpy_r_self, cpy_r_i, cpy_r_j);
    CPyTagged_DECREF(cpy_r_j);
    if (unlikely(cpy_r_r83 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 93, CPyStatic_globals);
        goto CPyL84;
    }
    if (!cpy_r_solid) goto CPyL66;
    cpy_r_r84 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AttributeError("simplified.py", "set_obstacle_circle", "HeadlessWindTunnel", "fluid", 95, CPyStatic_globals);
        goto CPyL85;
    }
    CPy_INCREF(cpy_r_r84);
CPyL55: ;
    cpy_r_r85 = CPyStatics[5]; /* 's' */
    cpy_r_r86 = CPyObject_GetAttr(cpy_r_r84, cpy_r_r85);
    CPy_DECREF(cpy_r_r84);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 95, CPyStatic_globals);
        goto CPyL85;
    }
    CPyTagged_INCREF(cpy_r_r83);
    cpy_r_r87 = CPyTagged_StealAsObject(cpy_r_r83);
    cpy_r_r88 = PyFloat_FromDouble(0.0);
    cpy_r_r89 = PyObject_SetItem(cpy_r_r86, cpy_r_r87, cpy_r_r88);
    CPy_DECREF(cpy_r_r86);
    CPy_DECREF(cpy_r_r87);
    CPy_DECREF(cpy_r_r88);
    cpy_r_r90 = cpy_r_r89 >= 0;
    if (unlikely(!cpy_r_r90)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 95, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r91 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AttributeError("simplified.py", "set_obstacle_circle", "HeadlessWindTunnel", "fluid", 96, CPyStatic_globals);
        goto CPyL85;
    }
    CPy_INCREF(cpy_r_r91);
CPyL58: ;
    cpy_r_r92 = CPyStatics[7]; /* 'm' */
    cpy_r_r93 = CPyObject_GetAttr(cpy_r_r91, cpy_r_r92);
    CPy_DECREF(cpy_r_r91);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 96, CPyStatic_globals);
        goto CPyL85;
    }
    CPyTagged_INCREF(cpy_r_r83);
    cpy_r_r94 = CPyTagged_StealAsObject(cpy_r_r83);
    cpy_r_r95 = PyFloat_FromDouble(0.0);
    cpy_r_r96 = PyObject_SetItem(cpy_r_r93, cpy_r_r94, cpy_r_r95);
    CPy_DECREF(cpy_r_r93);
    CPy_DECREF(cpy_r_r94);
    CPy_DECREF(cpy_r_r95);
    cpy_r_r97 = cpy_r_r96 >= 0;
    if (unlikely(!cpy_r_r97)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 96, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r98 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AttributeError("simplified.py", "set_obstacle_circle", "HeadlessWindTunnel", "fluid", 97, CPyStatic_globals);
        goto CPyL85;
    }
    CPy_INCREF(cpy_r_r98);
CPyL61: ;
    cpy_r_r99 = CPyStatics[8]; /* 'u' */
    cpy_r_r100 = CPyObject_GetAttr(cpy_r_r98, cpy_r_r99);
    CPy_DECREF(cpy_r_r98);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 97, CPyStatic_globals);
        goto CPyL85;
    }
    CPyTagged_INCREF(cpy_r_r83);
    cpy_r_r101 = CPyTagged_StealAsObject(cpy_r_r83);
    cpy_r_r102 = PyFloat_FromDouble(0.0);
    cpy_r_r103 = PyObject_SetItem(cpy_r_r100, cpy_r_r101, cpy_r_r102);
    CPy_DECREF(cpy_r_r100);
    CPy_DECREF(cpy_r_r101);
    CPy_DECREF(cpy_r_r102);
    cpy_r_r104 = cpy_r_r103 >= 0;
    if (unlikely(!cpy_r_r104)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 97, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r105 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AttributeError("simplified.py", "set_obstacle_circle", "HeadlessWindTunnel", "fluid", 98, CPyStatic_globals);
        goto CPyL85;
    }
    CPy_INCREF(cpy_r_r105);
CPyL64: ;
    cpy_r_r106 = CPyStatics[9]; /* 'v' */
    cpy_r_r107 = CPyObject_GetAttr(cpy_r_r105, cpy_r_r106);
    CPy_DECREF(cpy_r_r105);
    if (unlikely(cpy_r_r107 == NULL)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 98, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r108 = CPyTagged_StealAsObject(cpy_r_r83);
    cpy_r_r109 = PyFloat_FromDouble(0.0);
    cpy_r_r110 = PyObject_SetItem(cpy_r_r107, cpy_r_r108, cpy_r_r109);
    CPy_DECREF(cpy_r_r107);
    CPy_DECREF(cpy_r_r108);
    CPy_DECREF(cpy_r_r109);
    cpy_r_r111 = cpy_r_r110 >= 0;
    if (unlikely(!cpy_r_r111)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 98, CPyStatic_globals);
        goto CPyL84;
    } else
        goto CPyL69;
CPyL66: ;
    cpy_r_r112 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AttributeError("simplified.py", "set_obstacle_circle", "HeadlessWindTunnel", "fluid", 100, CPyStatic_globals);
        goto CPyL85;
    }
    CPy_INCREF(cpy_r_r112);
CPyL67: ;
    cpy_r_r113 = CPyStatics[5]; /* 's' */
    cpy_r_r114 = CPyObject_GetAttr(cpy_r_r112, cpy_r_r113);
    CPy_DECREF(cpy_r_r112);
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 100, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r115 = CPyTagged_StealAsObject(cpy_r_r83);
    cpy_r_r116 = PyFloat_FromDouble(1.0);
    cpy_r_r117 = PyObject_SetItem(cpy_r_r114, cpy_r_r115, cpy_r_r116);
    CPy_DECREF(cpy_r_r114);
    CPy_DECREF(cpy_r_r115);
    CPy_DECREF(cpy_r_r116);
    cpy_r_r118 = cpy_r_r117 >= 0;
    if (unlikely(!cpy_r_r118)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 100, CPyStatic_globals);
        goto CPyL84;
    }
CPyL69: ;
    cpy_r_r119 = CPyTagged_Add(cpy_r_r51, 2);
    CPyTagged_DECREF(cpy_r_r51);
    cpy_r_r51 = cpy_r_r119;
    goto CPyL38;
CPyL70: ;
    cpy_r_r120 = CPyTagged_Add(cpy_r_r22, 2);
    CPyTagged_DECREF(cpy_r_r22);
    cpy_r_r22 = cpy_r_r120;
    goto CPyL18;
CPyL71: ;
    return 1;
CPyL72: ;
    cpy_r_r121 = 2;
    return cpy_r_r121;
CPyL73: ;
    CPyTagged_DECREF(cpy_r_r0);
    goto CPyL7;
CPyL74: ;
    CPyTagged_DecRef(cpy_r_r7);
    goto CPyL72;
CPyL75: ;
    CPyTagged_DECREF(cpy_r_r12);
    goto CPyL15;
CPyL76: ;
    CPyTagged_DECREF(cpy_r_r14);
    goto CPyL16;
CPyL77: ;
    CPyTagged_DECREF(cpy_r_r21);
    CPyTagged_DECREF(cpy_r_r22);
    goto CPyL71;
CPyL78: ;
    CPyTagged_DECREF(cpy_r_r29);
    goto CPyL27;
CPyL79: ;
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r36);
    goto CPyL72;
CPyL80: ;
    CPyTagged_DECREF(cpy_r_r41);
    goto CPyL35;
CPyL81: ;
    CPyTagged_DECREF(cpy_r_r43);
    goto CPyL36;
CPyL82: ;
    CPyTagged_DECREF(cpy_r_i);
    CPyTagged_DECREF(cpy_r_r50);
    CPyTagged_DECREF(cpy_r_r51);
    goto CPyL70;
CPyL83: ;
    CPyTagged_DECREF(cpy_r_j);
    goto CPyL69;
CPyL84: ;
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r50);
    CPyTagged_DecRef(cpy_r_r51);
    goto CPyL72;
CPyL85: ;
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r50);
    CPyTagged_DecRef(cpy_r_r51);
    CPyTagged_DecRef(cpy_r_r83);
    goto CPyL72;
}
    
    PyObject *CPyPy_HeadlessWindTunnel___set_obstacle_circle(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        PyObject *obj_self = self;
        static const char * const kwlist[] = {"cx", "cy", "radius", "solid", 0};
        static CPyArg_Parser parser = {"OOO|O:set_obstacle_circle", kwlist, 0};
        PyObject *obj_cx;
        PyObject *obj_cy;
        PyObject *obj_radius;
        PyObject *obj_solid = NULL;
        if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_cx, &obj_cy, &obj_radius, &obj_solid)) {
            return NULL;
        }
        PyObject *arg_self;
        if (likely(Py_TYPE(obj_self) == CPyType_HeadlessWindTunnel))
            arg_self = obj_self;
        else {
            CPy_TypeError("simplified.HeadlessWindTunnel", obj_self); 
            goto fail;
        }
        CPyTagged arg_cx;
        if (likely(PyLong_Check(obj_cx)))
            arg_cx = CPyTagged_BorrowFromObject(obj_cx);
        else {
            CPy_TypeError("int", obj_cx); goto fail;
        }
        CPyTagged arg_cy;
        if (likely(PyLong_Check(obj_cy)))
            arg_cy = CPyTagged_BorrowFromObject(obj_cy);
        else {
            CPy_TypeError("int", obj_cy); goto fail;
        }
        CPyTagged arg_radius;
        if (likely(PyLong_Check(obj_radius)))
            arg_radius = CPyTagged_BorrowFromObject(obj_radius);
        else {
            CPy_TypeError("int", obj_radius); goto fail;
        }
        char arg_solid;
        if (obj_solid == NULL) {
            arg_solid = 2;
        } else if (unlikely(!PyBool_Check(obj_solid))) {
            CPy_TypeError("bool", obj_solid); goto fail;
        } else
            arg_solid = obj_solid == Py_True;
        char retval = CPyDef_HeadlessWindTunnel___set_obstacle_circle(arg_self, arg_cx, arg_cy, arg_radius, arg_solid);
        if (retval == 2) {
            return NULL;
        }
        PyObject *retbox = Py_None;
        CPy_INCREF(retbox);
        return retbox;
fail: ;
        CPy_AddTraceback("simplified.py", "set_obstacle_circle", 86, CPyStatic_globals);
        return NULL;
    }
    
PyObject *CPyDef_HeadlessWindTunnel___set_obstacle_airfoil(PyObject *cpy_r_self, PyObject *cpy_r_naca_code, double cpy_r_chord_length, double cpy_r_center_x, double cpy_r_center_y) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    cpy_r_r0 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("simplified.py", "set_obstacle_airfoil", "HeadlessWindTunnel", "fluid", 110, CPyStatic_globals);
        goto CPyL4;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyStatic_globals;
    cpy_r_r2 = CPyStatics[12]; /* 'apply_naca_airfoil' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_airfoil", 109, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r4 = PyFloat_FromDouble(cpy_r_chord_length);
    cpy_r_r5 = PyFloat_FromDouble(cpy_r_center_x);
    cpy_r_r6 = PyFloat_FromDouble(cpy_r_center_y);
    PyObject *cpy_r_r7[5] = {cpy_r_r0, cpy_r_naca_code, cpy_r_r4, cpy_r_r5, cpy_r_r6};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = CPyStatics[198]; /* ('naca_code', 'chord_length', 'center_x', 'center_y') */
    cpy_r_r10 = PyObject_Vectorcall(cpy_r_r3, cpy_r_r8, 1, cpy_r_r9);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("simplified.py", "set_obstacle_airfoil", 109, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r6);
    return cpy_r_r10;
CPyL4: ;
    cpy_r_r11 = NULL;
    return cpy_r_r11;
CPyL5: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL4;
CPyL6: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r6);
    goto CPyL4;
}
    
    PyObject *CPyPy_HeadlessWindTunnel___set_obstacle_airfoil(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        PyObject *obj_self = self;
        static const char * const kwlist[] = {"naca_code", "chord_length", "center_x", "center_y", 0};
        static CPyArg_Parser parser = {"OOOO:set_obstacle_airfoil", kwlist, 0};
        PyObject *obj_naca_code;
        PyObject *obj_chord_length;
        PyObject *obj_center_x;
        PyObject *obj_center_y;
        if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_naca_code, &obj_chord_length, &obj_center_x, &obj_center_y)) {
            return NULL;
        }
        PyObject *arg_self;
        if (likely(Py_TYPE(obj_self) == CPyType_HeadlessWindTunnel))
            arg_self = obj_self;
        else {
            CPy_TypeError("simplified.HeadlessWindTunnel", obj_self); 
            goto fail;
        }
        PyObject *arg_naca_code;
        if (likely(PyUnicode_Check(obj_naca_code)))
            arg_naca_code = obj_naca_code;
        else {
            CPy_TypeError("str", obj_naca_code); 
            goto fail;
        }
        double arg_chord_length;
        arg_chord_length = PyFloat_AsDouble(obj_chord_length);
        if (arg_chord_length == -1.0 && PyErr_Occurred()) {
            CPy_TypeError("float", obj_chord_length); goto fail;
        }
        double arg_center_x;
        arg_center_x = PyFloat_AsDouble(obj_center_x);
        if (arg_center_x == -1.0 && PyErr_Occurred()) {
            CPy_TypeError("float", obj_center_x); goto fail;
        }
        double arg_center_y;
        arg_center_y = PyFloat_AsDouble(obj_center_y);
        if (arg_center_y == -1.0 && PyErr_Occurred()) {
            CPy_TypeError("float", obj_center_y); goto fail;
        }
        PyObject *retval = CPyDef_HeadlessWindTunnel___set_obstacle_airfoil(arg_self, arg_naca_code, arg_chord_length, arg_center_x, arg_center_y);
        return retval;
fail: ;
        CPy_AddTraceback("simplified.py", "set_obstacle_airfoil", 102, CPyStatic_globals);
        return NULL;
    }
    
char CPyDef_HeadlessWindTunnel___step(PyObject *cpy_r_self, CPyTagged cpy_r_steps) {
    double cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    CPyTagged cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r__;
    int64_t cpy_r_r10;
    char cpy_r_r11;
    int64_t cpy_r_r12;
    char cpy_r_r13;
    char cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    double cpy_r_r19;
    double cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject **cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject **cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    CPyTagged cpy_r_r36;
    double cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject **cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    double cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    double cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject **cpy_r_r61;
    PyObject *cpy_r_r62;
    char cpy_r_r63;
    CPyTagged cpy_r_r64;
    char cpy_r_r65;
    if (cpy_r_steps != CPY_INT_TAG) goto CPyL27;
    cpy_r_steps = 2;
CPyL2: ;
    cpy_r_r0 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_over_relax;
    cpy_r_r1 = CPyStatic_globals;
    cpy_r_r2 = CPyStatics[17]; /* 'set_over_relaxation' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("simplified.py", "step", 118, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r4 = PyFloat_FromDouble(cpy_r_r0);
    PyObject *cpy_r_r5[1] = {cpy_r_r4};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = PyObject_Vectorcall(cpy_r_r3, cpy_r_r6, 1, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("simplified.py", "step", 118, CPyStatic_globals);
        goto CPyL29;
    } else
        goto CPyL30;
CPyL4: ;
    CPy_DECREF(cpy_r_r4);
    cpy_r_r8 = 0;
    CPyTagged_INCREF(cpy_r_r8);
    cpy_r_r9 = CPyTagged_StealAsObject(cpy_r_r8);
    cpy_r__ = cpy_r_r9;
    CPy_DECREF(cpy_r__);
CPyL5: ;
    cpy_r_r10 = cpy_r_r8 & 1;
    cpy_r_r11 = cpy_r_r10 != 0;
    if (cpy_r_r11) goto CPyL7;
    cpy_r_r12 = cpy_r_steps & 1;
    cpy_r_r13 = cpy_r_r12 != 0;
    if (!cpy_r_r13) goto CPyL8;
CPyL7: ;
    cpy_r_r14 = CPyTagged_IsLt_(cpy_r_r8, cpy_r_steps);
    if (cpy_r_r14) {
        goto CPyL9;
    } else
        goto CPyL31;
CPyL8: ;
    cpy_r_r15 = (Py_ssize_t)cpy_r_r8 < (Py_ssize_t)cpy_r_steps;
    if (!cpy_r_r15) goto CPyL31;
CPyL9: ;
    CPyTagged_INCREF(cpy_r_r8);
    cpy_r_r16 = CPyTagged_StealAsObject(cpy_r_r8);
    cpy_r__ = cpy_r_r16;
    CPy_DECREF(cpy_r__);
    cpy_r_r17 = CPyDef_HeadlessWindTunnel___apply_inlet(cpy_r_self);
    if (unlikely(cpy_r_r17 == 2)) {
        CPy_AddTraceback("simplified.py", "step", 121, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r18 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AttributeError("simplified.py", "step", "HeadlessWindTunnel", "fluid", 122, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_INCREF(cpy_r_r18);
CPyL11: ;
    cpy_r_r19 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_dt;
    cpy_r_r20 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_gravity;
    cpy_r_r21 = CPyStatics[18]; /* 'integrate_g' */
    cpy_r_r22 = PyFloat_FromDouble(cpy_r_r19);
    cpy_r_r23 = PyFloat_FromDouble(cpy_r_r20);
    PyObject *cpy_r_r24[3] = {cpy_r_r18, cpy_r_r22, cpy_r_r23};
    cpy_r_r25 = (PyObject **)&cpy_r_r24;
    cpy_r_r26 = PyObject_VectorcallMethod(cpy_r_r21, cpy_r_r25, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("simplified.py", "step", 122, CPyStatic_globals);
        goto CPyL33;
    } else
        goto CPyL34;
CPyL12: ;
    CPy_DECREF(cpy_r_r18);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r23);
    cpy_r_r27 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AttributeError("simplified.py", "step", "HeadlessWindTunnel", "fluid", 123, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_INCREF(cpy_r_r27);
CPyL13: ;
    cpy_r_r28 = CPyStatics[10]; /* 'p' */
    cpy_r_r29 = CPyObject_GetAttr(cpy_r_r27, cpy_r_r28);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("simplified.py", "step", 123, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r30 = CPyStatics[6]; /* 'fill' */
    cpy_r_r31 = PyFloat_FromDouble(0.0);
    PyObject *cpy_r_r32[2] = {cpy_r_r29, cpy_r_r31};
    cpy_r_r33 = (PyObject **)&cpy_r_r32;
    cpy_r_r34 = PyObject_VectorcallMethod(cpy_r_r30, cpy_r_r33, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("simplified.py", "step", 123, CPyStatic_globals);
        goto CPyL35;
    } else
        goto CPyL36;
CPyL15: ;
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r31);
    cpy_r_r35 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AttributeError("simplified.py", "step", "HeadlessWindTunnel", "fluid", 124, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_INCREF(cpy_r_r35);
CPyL16: ;
    cpy_r_r36 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_iterations;
    CPyTagged_INCREF(cpy_r_r36);
    cpy_r_r37 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_dt;
    cpy_r_r38 = CPyStatics[19]; /* 'incompressibility_solve' */
    cpy_r_r39 = CPyTagged_StealAsObject(cpy_r_r36);
    cpy_r_r40 = PyFloat_FromDouble(cpy_r_r37);
    PyObject *cpy_r_r41[3] = {cpy_r_r35, cpy_r_r39, cpy_r_r40};
    cpy_r_r42 = (PyObject **)&cpy_r_r41;
    cpy_r_r43 = PyObject_VectorcallMethod(cpy_r_r38, cpy_r_r42, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("simplified.py", "step", 124, CPyStatic_globals);
        goto CPyL37;
    } else
        goto CPyL38;
CPyL17: ;
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r39);
    CPy_DECREF(cpy_r_r40);
    cpy_r_r44 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AttributeError("simplified.py", "step", "HeadlessWindTunnel", "fluid", 125, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_INCREF(cpy_r_r44);
CPyL18: ;
    cpy_r_r45 = CPyStatics[20]; /* 'Extrapolate' */
    PyObject *cpy_r_r46[1] = {cpy_r_r44};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = PyObject_VectorcallMethod(cpy_r_r45, cpy_r_r47, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("simplified.py", "step", 125, CPyStatic_globals);
        goto CPyL39;
    } else
        goto CPyL40;
CPyL19: ;
    CPy_DECREF(cpy_r_r44);
    cpy_r_r49 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AttributeError("simplified.py", "step", "HeadlessWindTunnel", "fluid", 126, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_INCREF(cpy_r_r49);
CPyL20: ;
    cpy_r_r50 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_dt;
    cpy_r_r51 = CPyStatics[21]; /* 'advection_vel' */
    cpy_r_r52 = PyFloat_FromDouble(cpy_r_r50);
    PyObject *cpy_r_r53[2] = {cpy_r_r49, cpy_r_r52};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = PyObject_VectorcallMethod(cpy_r_r51, cpy_r_r54, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("simplified.py", "step", 126, CPyStatic_globals);
        goto CPyL41;
    } else
        goto CPyL42;
CPyL21: ;
    CPy_DECREF(cpy_r_r49);
    CPy_DECREF(cpy_r_r52);
    cpy_r_r56 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AttributeError("simplified.py", "step", "HeadlessWindTunnel", "fluid", 127, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_INCREF(cpy_r_r56);
CPyL22: ;
    cpy_r_r57 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_dt;
    cpy_r_r58 = CPyStatics[22]; /* 'advection_smoke' */
    cpy_r_r59 = PyFloat_FromDouble(cpy_r_r57);
    PyObject *cpy_r_r60[2] = {cpy_r_r56, cpy_r_r59};
    cpy_r_r61 = (PyObject **)&cpy_r_r60;
    cpy_r_r62 = PyObject_VectorcallMethod(cpy_r_r58, cpy_r_r61, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("simplified.py", "step", 127, CPyStatic_globals);
        goto CPyL43;
    } else
        goto CPyL44;
CPyL23: ;
    CPy_DECREF(cpy_r_r56);
    CPy_DECREF(cpy_r_r59);
    cpy_r_r63 = CPyDef_HeadlessWindTunnel___apply_inlet(cpy_r_self);
    if (unlikely(cpy_r_r63 == 2)) {
        CPy_AddTraceback("simplified.py", "step", 128, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r64 = CPyTagged_Add(cpy_r_r8, 2);
    CPyTagged_DECREF(cpy_r_r8);
    cpy_r_r8 = cpy_r_r64;
    goto CPyL5;
CPyL25: ;
    return 1;
CPyL26: ;
    cpy_r_r65 = 2;
    return cpy_r_r65;
CPyL27: ;
    CPyTagged_INCREF(cpy_r_steps);
    goto CPyL2;
CPyL28: ;
    CPyTagged_DecRef(cpy_r_steps);
    goto CPyL26;
CPyL29: ;
    CPyTagged_DecRef(cpy_r_steps);
    CPy_DecRef(cpy_r_r4);
    goto CPyL26;
CPyL30: ;
    CPy_DECREF(cpy_r_r7);
    goto CPyL4;
CPyL31: ;
    CPyTagged_DECREF(cpy_r_steps);
    CPyTagged_DECREF(cpy_r_r8);
    goto CPyL25;
CPyL32: ;
    CPyTagged_DecRef(cpy_r_steps);
    CPyTagged_DecRef(cpy_r_r8);
    goto CPyL26;
CPyL33: ;
    CPyTagged_DecRef(cpy_r_steps);
    CPyTagged_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r23);
    goto CPyL26;
CPyL34: ;
    CPy_DECREF(cpy_r_r26);
    goto CPyL12;
CPyL35: ;
    CPyTagged_DecRef(cpy_r_steps);
    CPyTagged_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r31);
    goto CPyL26;
CPyL36: ;
    CPy_DECREF(cpy_r_r34);
    goto CPyL15;
CPyL37: ;
    CPyTagged_DecRef(cpy_r_steps);
    CPyTagged_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r35);
    CPy_DecRef(cpy_r_r39);
    CPy_DecRef(cpy_r_r40);
    goto CPyL26;
CPyL38: ;
    CPy_DECREF(cpy_r_r43);
    goto CPyL17;
CPyL39: ;
    CPyTagged_DecRef(cpy_r_steps);
    CPyTagged_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r44);
    goto CPyL26;
CPyL40: ;
    CPy_DECREF(cpy_r_r48);
    goto CPyL19;
CPyL41: ;
    CPyTagged_DecRef(cpy_r_steps);
    CPyTagged_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r49);
    CPy_DecRef(cpy_r_r52);
    goto CPyL26;
CPyL42: ;
    CPy_DECREF(cpy_r_r55);
    goto CPyL21;
CPyL43: ;
    CPyTagged_DecRef(cpy_r_steps);
    CPyTagged_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r56);
    CPy_DecRef(cpy_r_r59);
    goto CPyL26;
CPyL44: ;
    CPy_DECREF(cpy_r_r62);
    goto CPyL23;
}
    
    PyObject *CPyPy_HeadlessWindTunnel___step(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        PyObject *obj_self = self;
        static const char * const kwlist[] = {"steps", 0};
        static CPyArg_Parser parser = {"|O:step", kwlist, 0};
        PyObject *obj_steps = NULL;
        if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_steps)) {
            return NULL;
        }
        PyObject *arg_self;
        if (likely(Py_TYPE(obj_self) == CPyType_HeadlessWindTunnel))
            arg_self = obj_self;
        else {
            CPy_TypeError("simplified.HeadlessWindTunnel", obj_self); 
            goto fail;
        }
        CPyTagged arg_steps;
        if (obj_steps == NULL) {
            arg_steps = CPY_INT_TAG;
        } else if (likely(PyLong_Check(obj_steps)))
            arg_steps = CPyTagged_BorrowFromObject(obj_steps);
        else {
            CPy_TypeError("int", obj_steps); goto fail;
        }
        char retval = CPyDef_HeadlessWindTunnel___step(arg_self, arg_steps);
        if (retval == 2) {
            return NULL;
        }
        PyObject *retbox = Py_None;
        CPy_INCREF(retbox);
        return retbox;
fail: ;
        CPy_AddTraceback("simplified.py", "step", 117, CPyStatic_globals);
        return NULL;
    }
    
PyObject *CPyDef_HeadlessWindTunnel___speed_field(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    CPyTagged cpy_r_r4;
    CPyTagged cpy_r_r5;
    tuple_T2II cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject **cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    CPyTagged cpy_r_r21;
    CPyTagged cpy_r_r22;
    CPyTagged cpy_r_r23;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r24;
    char cpy_r_r25;
    int64_t cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    CPyTagged cpy_r_r33;
    CPyTagged cpy_r_r34;
    CPyTagged cpy_r_r35;
    CPyTagged cpy_r_j;
    int64_t cpy_r_r36;
    char cpy_r_r37;
    int64_t cpy_r_r38;
    char cpy_r_r39;
    char cpy_r_r40;
    char cpy_r_r41;
    CPyTagged cpy_r_r42;
    CPyTagged cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    CPyTagged cpy_r_r52;
    CPyTagged cpy_r_r53;
    CPyTagged cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    CPyTagged cpy_r_r68;
    CPyTagged cpy_r_r69;
    CPyTagged cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject **cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject **cpy_r_r89;
    PyObject *cpy_r_r90;
    CPyTagged cpy_r_r91;
    CPyTagged cpy_r_r92;
    tuple_T2II cpy_r_r93;
    PyObject *cpy_r_r94;
    int32_t cpy_r_r95;
    char cpy_r_r96;
    CPyTagged cpy_r_r97;
    CPyTagged cpy_r_r98;
    PyObject *cpy_r_r99;
    cpy_r_r0 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("simplified.py", "speed_field", "HeadlessWindTunnel", "fluid", 131, CPyStatic_globals);
        goto CPyL49;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyStatics[3]; /* 'numY' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 131, CPyStatic_globals);
        goto CPyL49;
    }
    if (likely(PyLong_Check(cpy_r_r2)))
        cpy_r_r3 = CPyTagged_FromObject(cpy_r_r2);
    else {
        CPy_TypeError("int", cpy_r_r2); cpy_r_r3 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "speed_field", 131, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r4 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_h;
    CPyTagged_INCREF(cpy_r_r4);
    cpy_r_r5 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_w;
    CPyTagged_INCREF(cpy_r_r5);
    cpy_r_r6.f0 = cpy_r_r4;
    cpy_r_r6.f1 = cpy_r_r5;
    cpy_r_r7 = CPyModule_numpy;
    cpy_r_r8 = CPyStatics[23]; /* 'float32' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 132, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r10 = CPyModule_numpy;
    cpy_r_r11 = CPyStatics[24]; /* 'zeros' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 132, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r13 = PyTuple_New(2);
    if (unlikely(cpy_r_r13 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp1 = CPyTagged_StealAsObject(cpy_r_r6.f0);
    PyTuple_SET_ITEM(cpy_r_r13, 0, __tmp1);
    PyObject *__tmp2 = CPyTagged_StealAsObject(cpy_r_r6.f1);
    PyTuple_SET_ITEM(cpy_r_r13, 1, __tmp2);
    PyObject *cpy_r_r14[2] = {cpy_r_r13, cpy_r_r9};
    cpy_r_r15 = (PyObject **)&cpy_r_r14;
    cpy_r_r16 = CPyStatics[199]; /* ('dtype',) */
    cpy_r_r17 = PyObject_Vectorcall(cpy_r_r12, cpy_r_r15, 1, cpy_r_r16);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 132, CPyStatic_globals);
        goto CPyL52;
    }
    CPy_DECREF(cpy_r_r13);
    CPy_DECREF(cpy_r_r9);
    cpy_r_r18 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AttributeError("simplified.py", "speed_field", "HeadlessWindTunnel", "fluid", 134, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_INCREF(cpy_r_r18);
CPyL7: ;
    cpy_r_r19 = CPyStatics[11]; /* 'numX' */
    cpy_r_r20 = CPyObject_GetAttr(cpy_r_r18, cpy_r_r19);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 134, CPyStatic_globals);
        goto CPyL53;
    }
    if (likely(PyLong_Check(cpy_r_r20)))
        cpy_r_r21 = CPyTagged_FromObject(cpy_r_r20);
    else {
        CPy_TypeError("int", cpy_r_r20); cpy_r_r21 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r21 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "speed_field", 134, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r22 = CPyTagged_Subtract(cpy_r_r21, 2);
    CPyTagged_DECREF(cpy_r_r21);
    cpy_r_r23 = 2;
    CPyTagged_INCREF(cpy_r_r23);
    cpy_r_i = cpy_r_r23;
    CPyTagged_DECREF(cpy_r_i);
CPyL10: ;
    cpy_r_r24 = cpy_r_r23 & 1;
    cpy_r_r25 = cpy_r_r24 != 0;
    if (cpy_r_r25) goto CPyL12;
    cpy_r_r26 = cpy_r_r22 & 1;
    cpy_r_r27 = cpy_r_r26 != 0;
    if (!cpy_r_r27) goto CPyL13;
CPyL12: ;
    cpy_r_r28 = CPyTagged_IsLt_(cpy_r_r23, cpy_r_r22);
    if (cpy_r_r28) {
        goto CPyL14;
    } else
        goto CPyL54;
CPyL13: ;
    cpy_r_r29 = (Py_ssize_t)cpy_r_r23 < (Py_ssize_t)cpy_r_r22;
    if (!cpy_r_r29) goto CPyL54;
CPyL14: ;
    CPyTagged_INCREF(cpy_r_r23);
    cpy_r_i = cpy_r_r23;
    cpy_r_r30 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AttributeError("simplified.py", "speed_field", "HeadlessWindTunnel", "fluid", 135, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_INCREF(cpy_r_r30);
CPyL15: ;
    cpy_r_r31 = CPyStatics[3]; /* 'numY' */
    cpy_r_r32 = CPyObject_GetAttr(cpy_r_r30, cpy_r_r31);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 135, CPyStatic_globals);
        goto CPyL55;
    }
    if (likely(PyLong_Check(cpy_r_r32)))
        cpy_r_r33 = CPyTagged_FromObject(cpy_r_r32);
    else {
        CPy_TypeError("int", cpy_r_r32); cpy_r_r33 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r33 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "speed_field", 135, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r34 = CPyTagged_Subtract(cpy_r_r33, 2);
    CPyTagged_DECREF(cpy_r_r33);
    cpy_r_r35 = 2;
    CPyTagged_INCREF(cpy_r_r35);
    cpy_r_j = cpy_r_r35;
    CPyTagged_DECREF(cpy_r_j);
CPyL18: ;
    cpy_r_r36 = cpy_r_r35 & 1;
    cpy_r_r37 = cpy_r_r36 != 0;
    if (cpy_r_r37) goto CPyL20;
    cpy_r_r38 = cpy_r_r34 & 1;
    cpy_r_r39 = cpy_r_r38 != 0;
    if (!cpy_r_r39) goto CPyL21;
CPyL20: ;
    cpy_r_r40 = CPyTagged_IsLt_(cpy_r_r35, cpy_r_r34);
    if (cpy_r_r40) {
        goto CPyL22;
    } else
        goto CPyL56;
CPyL21: ;
    cpy_r_r41 = (Py_ssize_t)cpy_r_r35 < (Py_ssize_t)cpy_r_r34;
    if (!cpy_r_r41) goto CPyL56;
CPyL22: ;
    CPyTagged_INCREF(cpy_r_r35);
    cpy_r_j = cpy_r_r35;
    cpy_r_r42 = CPyTagged_Multiply(cpy_r_i, cpy_r_r3);
    cpy_r_r43 = CPyTagged_Add(cpy_r_r42, cpy_r_j);
    CPyTagged_DECREF(cpy_r_r42);
    cpy_r_r44 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AttributeError("simplified.py", "speed_field", "HeadlessWindTunnel", "fluid", 137, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_INCREF(cpy_r_r44);
CPyL23: ;
    cpy_r_r45 = CPyStatics[8]; /* 'u' */
    cpy_r_r46 = CPyObject_GetAttr(cpy_r_r44, cpy_r_r45);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 137, CPyStatic_globals);
        goto CPyL57;
    }
    CPyTagged_INCREF(cpy_r_r43);
    cpy_r_r47 = CPyTagged_StealAsObject(cpy_r_r43);
    cpy_r_r48 = PyObject_GetItem(cpy_r_r46, cpy_r_r47);
    CPy_DECREF(cpy_r_r46);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 137, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r49 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AttributeError("simplified.py", "speed_field", "HeadlessWindTunnel", "fluid", 137, CPyStatic_globals);
        goto CPyL58;
    }
    CPy_INCREF(cpy_r_r49);
CPyL26: ;
    cpy_r_r50 = CPyStatics[8]; /* 'u' */
    cpy_r_r51 = CPyObject_GetAttr(cpy_r_r49, cpy_r_r50);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 137, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r52 = CPyTagged_Add(cpy_r_i, 2);
    cpy_r_r53 = CPyTagged_Multiply(cpy_r_r52, cpy_r_r3);
    CPyTagged_DECREF(cpy_r_r52);
    cpy_r_r54 = CPyTagged_Add(cpy_r_r53, cpy_r_j);
    CPyTagged_DECREF(cpy_r_r53);
    cpy_r_r55 = CPyTagged_StealAsObject(cpy_r_r54);
    cpy_r_r56 = PyObject_GetItem(cpy_r_r51, cpy_r_r55);
    CPy_DECREF(cpy_r_r51);
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 137, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r57 = PyNumber_Add(cpy_r_r48, cpy_r_r56);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r56);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 137, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r58 = PyFloat_FromDouble(0.5);
    cpy_r_r59 = PyNumber_Multiply(cpy_r_r58, cpy_r_r57);
    CPy_DECREF(cpy_r_r58);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 137, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r60 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AttributeError("simplified.py", "speed_field", "HeadlessWindTunnel", "fluid", 138, CPyStatic_globals);
        goto CPyL59;
    }
    CPy_INCREF(cpy_r_r60);
CPyL31: ;
    cpy_r_r61 = CPyStatics[9]; /* 'v' */
    cpy_r_r62 = CPyObject_GetAttr(cpy_r_r60, cpy_r_r61);
    CPy_DECREF(cpy_r_r60);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 138, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r63 = CPyTagged_StealAsObject(cpy_r_r43);
    cpy_r_r64 = PyObject_GetItem(cpy_r_r62, cpy_r_r63);
    CPy_DECREF(cpy_r_r62);
    CPy_DECREF(cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 138, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r65 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AttributeError("simplified.py", "speed_field", "HeadlessWindTunnel", "fluid", 138, CPyStatic_globals);
        goto CPyL61;
    }
    CPy_INCREF(cpy_r_r65);
CPyL34: ;
    cpy_r_r66 = CPyStatics[9]; /* 'v' */
    cpy_r_r67 = CPyObject_GetAttr(cpy_r_r65, cpy_r_r66);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 138, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r68 = CPyTagged_Multiply(cpy_r_i, cpy_r_r3);
    cpy_r_r69 = CPyTagged_Add(cpy_r_j, 2);
    cpy_r_r70 = CPyTagged_Add(cpy_r_r68, cpy_r_r69);
    CPyTagged_DECREF(cpy_r_r68);
    CPyTagged_DECREF(cpy_r_r69);
    cpy_r_r71 = CPyTagged_StealAsObject(cpy_r_r70);
    cpy_r_r72 = PyObject_GetItem(cpy_r_r67, cpy_r_r71);
    CPy_DECREF(cpy_r_r67);
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 138, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r73 = PyNumber_Add(cpy_r_r64, cpy_r_r72);
    CPy_DECREF(cpy_r_r64);
    CPy_DECREF(cpy_r_r72);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 138, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r74 = PyFloat_FromDouble(0.5);
    cpy_r_r75 = PyNumber_Multiply(cpy_r_r74, cpy_r_r73);
    CPy_DECREF(cpy_r_r74);
    CPy_DECREF(cpy_r_r73);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 138, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r76 = PyNumber_Multiply(cpy_r_r59, cpy_r_r59);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 139, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r77 = PyNumber_Multiply(cpy_r_r75, cpy_r_r75);
    CPy_DECREF(cpy_r_r75);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 139, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r78 = PyNumber_Add(cpy_r_r76, cpy_r_r77);
    CPy_DECREF(cpy_r_r76);
    CPy_DECREF(cpy_r_r77);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 139, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r79 = CPyModule_numpy;
    cpy_r_r80 = CPyStatics[26]; /* 'sqrt' */
    cpy_r_r81 = CPyObject_GetAttr(cpy_r_r79, cpy_r_r80);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 139, CPyStatic_globals);
        goto CPyL65;
    }
    PyObject *cpy_r_r82[1] = {cpy_r_r78};
    cpy_r_r83 = (PyObject **)&cpy_r_r82;
    cpy_r_r84 = PyObject_Vectorcall(cpy_r_r81, cpy_r_r83, 1, 0);
    CPy_DECREF(cpy_r_r81);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 139, CPyStatic_globals);
        goto CPyL65;
    }
    CPy_DECREF(cpy_r_r78);
    cpy_r_r85 = CPyModule_numpy;
    cpy_r_r86 = CPyStatics[23]; /* 'float32' */
    cpy_r_r87 = CPyObject_GetAttr(cpy_r_r85, cpy_r_r86);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 139, CPyStatic_globals);
        goto CPyL66;
    }
    PyObject *cpy_r_r88[1] = {cpy_r_r84};
    cpy_r_r89 = (PyObject **)&cpy_r_r88;
    cpy_r_r90 = PyObject_Vectorcall(cpy_r_r87, cpy_r_r89, 1, 0);
    CPy_DECREF(cpy_r_r87);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("simplified.py", "speed_field", 139, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_DECREF(cpy_r_r84);
    cpy_r_r91 = CPyTagged_Subtract(cpy_r_j, 2);
    CPyTagged_DECREF(cpy_r_j);
    cpy_r_r92 = CPyTagged_Subtract(cpy_r_i, 2);
    cpy_r_r93.f0 = cpy_r_r91;
    cpy_r_r93.f1 = cpy_r_r92;
    cpy_r_r94 = PyTuple_New(2);
    if (unlikely(cpy_r_r94 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp3 = CPyTagged_StealAsObject(cpy_r_r93.f0);
    PyTuple_SET_ITEM(cpy_r_r94, 0, __tmp3);
    PyObject *__tmp4 = CPyTagged_StealAsObject(cpy_r_r93.f1);
    PyTuple_SET_ITEM(cpy_r_r94, 1, __tmp4);
    cpy_r_r95 = PyObject_SetItem(cpy_r_r17, cpy_r_r94, cpy_r_r90);
    CPy_DECREF(cpy_r_r94);
    CPy_DECREF(cpy_r_r90);
    cpy_r_r96 = cpy_r_r95 >= 0;
    if (unlikely(!cpy_r_r96)) {
        CPy_AddTraceback("simplified.py", "speed_field", 139, CPyStatic_globals);
        goto CPyL67;
    }
    cpy_r_r97 = CPyTagged_Add(cpy_r_r35, 2);
    CPyTagged_DECREF(cpy_r_r35);
    cpy_r_r35 = cpy_r_r97;
    goto CPyL18;
CPyL47: ;
    cpy_r_r98 = CPyTagged_Add(cpy_r_r23, 2);
    CPyTagged_DECREF(cpy_r_r23);
    cpy_r_r23 = cpy_r_r98;
    goto CPyL10;
CPyL48: ;
    return cpy_r_r17;
CPyL49: ;
    cpy_r_r99 = NULL;
    return cpy_r_r99;
CPyL50: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r6.f0);
    CPyTagged_DecRef(cpy_r_r6.f1);
    goto CPyL49;
CPyL51: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r6.f0);
    CPyTagged_DecRef(cpy_r_r6.f1);
    CPy_DecRef(cpy_r_r9);
    goto CPyL49;
CPyL52: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r13);
    goto CPyL49;
CPyL53: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r17);
    goto CPyL49;
CPyL54: ;
    CPyTagged_DECREF(cpy_r_r3);
    CPyTagged_DECREF(cpy_r_r22);
    CPyTagged_DECREF(cpy_r_r23);
    goto CPyL48;
CPyL55: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL49;
CPyL56: ;
    CPyTagged_DECREF(cpy_r_i);
    CPyTagged_DECREF(cpy_r_r34);
    CPyTagged_DECREF(cpy_r_r35);
    goto CPyL47;
CPyL57: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r43);
    goto CPyL49;
CPyL58: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    goto CPyL49;
CPyL59: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r59);
    goto CPyL49;
CPyL60: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r59);
    goto CPyL49;
CPyL61: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r59);
    CPy_DecRef(cpy_r_r64);
    goto CPyL49;
CPyL62: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r75);
    goto CPyL49;
CPyL63: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r76);
    goto CPyL49;
CPyL64: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    goto CPyL49;
CPyL65: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r78);
    goto CPyL49;
CPyL66: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r84);
    goto CPyL49;
CPyL67: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    goto CPyL49;
}
    
    PyObject *CPyPy_HeadlessWindTunnel___speed_field(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        PyObject *obj_self = self;
        static const char * const kwlist[] = {0};
        static CPyArg_Parser parser = {":speed_field", kwlist, 0};
        if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
            return NULL;
        }
        PyObject *arg_self;
        if (likely(Py_TYPE(obj_self) == CPyType_HeadlessWindTunnel))
            arg_self = obj_self;
        else {
            CPy_TypeError("simplified.HeadlessWindTunnel", obj_self); 
            goto fail;
        }
        PyObject *retval = CPyDef_HeadlessWindTunnel___speed_field(arg_self);
        return retval;
fail: ;
        CPy_AddTraceback("simplified.py", "speed_field", 130, CPyStatic_globals);
        return NULL;
    }
    
PyObject *CPyDef_HeadlessWindTunnel___smoke_field(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    tuple_T2II cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    CPyTagged cpy_r_r17;
    CPyTagged cpy_r_r18;
    CPyTagged cpy_r_r19;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r20;
    char cpy_r_r21;
    int64_t cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    CPyTagged cpy_r_r29;
    CPyTagged cpy_r_r30;
    CPyTagged cpy_r_r31;
    CPyTagged cpy_r_j;
    int64_t cpy_r_r32;
    char cpy_r_r33;
    int64_t cpy_r_r34;
    char cpy_r_r35;
    char cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    CPyTagged cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    CPyTagged cpy_r_r44;
    CPyTagged cpy_r_r45;
    tuple_T2II cpy_r_r46;
    PyObject *cpy_r_r47;
    int32_t cpy_r_r48;
    char cpy_r_r49;
    CPyTagged cpy_r_r50;
    CPyTagged cpy_r_r51;
    PyObject *cpy_r_r52;
    cpy_r_r0 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_h;
    CPyTagged_INCREF(cpy_r_r0);
    cpy_r_r1 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_w;
    CPyTagged_INCREF(cpy_r_r1);
    cpy_r_r2.f0 = cpy_r_r0;
    cpy_r_r2.f1 = cpy_r_r1;
    cpy_r_r3 = CPyModule_numpy;
    cpy_r_r4 = CPyStatics[23]; /* 'float32' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("simplified.py", "smoke_field", 144, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r6 = CPyModule_numpy;
    cpy_r_r7 = CPyStatics[24]; /* 'zeros' */
    cpy_r_r8 = CPyObject_GetAttr(cpy_r_r6, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("simplified.py", "smoke_field", 144, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r9 = PyTuple_New(2);
    if (unlikely(cpy_r_r9 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp5 = CPyTagged_StealAsObject(cpy_r_r2.f0);
    PyTuple_SET_ITEM(cpy_r_r9, 0, __tmp5);
    PyObject *__tmp6 = CPyTagged_StealAsObject(cpy_r_r2.f1);
    PyTuple_SET_ITEM(cpy_r_r9, 1, __tmp6);
    PyObject *cpy_r_r10[2] = {cpy_r_r9, cpy_r_r5};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = CPyStatics[199]; /* ('dtype',) */
    cpy_r_r13 = PyObject_Vectorcall(cpy_r_r8, cpy_r_r11, 1, cpy_r_r12);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("simplified.py", "smoke_field", 144, CPyStatic_globals);
        goto CPyL30;
    }
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r5);
    cpy_r_r14 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AttributeError("simplified.py", "smoke_field", "HeadlessWindTunnel", "fluid", 146, CPyStatic_globals);
        goto CPyL31;
    }
    CPy_INCREF(cpy_r_r14);
CPyL4: ;
    cpy_r_r15 = CPyStatics[11]; /* 'numX' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("simplified.py", "smoke_field", 146, CPyStatic_globals);
        goto CPyL31;
    }
    if (likely(PyLong_Check(cpy_r_r16)))
        cpy_r_r17 = CPyTagged_FromObject(cpy_r_r16);
    else {
        CPy_TypeError("int", cpy_r_r16); cpy_r_r17 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "smoke_field", 146, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r18 = CPyTagged_Subtract(cpy_r_r17, 2);
    CPyTagged_DECREF(cpy_r_r17);
    cpy_r_r19 = 2;
    CPyTagged_INCREF(cpy_r_r19);
    cpy_r_i = cpy_r_r19;
    CPyTagged_DECREF(cpy_r_i);
CPyL7: ;
    cpy_r_r20 = cpy_r_r19 & 1;
    cpy_r_r21 = cpy_r_r20 != 0;
    if (cpy_r_r21) goto CPyL9;
    cpy_r_r22 = cpy_r_r18 & 1;
    cpy_r_r23 = cpy_r_r22 != 0;
    if (!cpy_r_r23) goto CPyL10;
CPyL9: ;
    cpy_r_r24 = CPyTagged_IsLt_(cpy_r_r19, cpy_r_r18);
    if (cpy_r_r24) {
        goto CPyL11;
    } else
        goto CPyL32;
CPyL10: ;
    cpy_r_r25 = (Py_ssize_t)cpy_r_r19 < (Py_ssize_t)cpy_r_r18;
    if (!cpy_r_r25) goto CPyL32;
CPyL11: ;
    CPyTagged_INCREF(cpy_r_r19);
    cpy_r_i = cpy_r_r19;
    cpy_r_r26 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AttributeError("simplified.py", "smoke_field", "HeadlessWindTunnel", "fluid", 147, CPyStatic_globals);
        goto CPyL33;
    }
    CPy_INCREF(cpy_r_r26);
CPyL12: ;
    cpy_r_r27 = CPyStatics[3]; /* 'numY' */
    cpy_r_r28 = CPyObject_GetAttr(cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("simplified.py", "smoke_field", 147, CPyStatic_globals);
        goto CPyL33;
    }
    if (likely(PyLong_Check(cpy_r_r28)))
        cpy_r_r29 = CPyTagged_FromObject(cpy_r_r28);
    else {
        CPy_TypeError("int", cpy_r_r28); cpy_r_r29 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "smoke_field", 147, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r30 = CPyTagged_Subtract(cpy_r_r29, 2);
    CPyTagged_DECREF(cpy_r_r29);
    cpy_r_r31 = 2;
    CPyTagged_INCREF(cpy_r_r31);
    cpy_r_j = cpy_r_r31;
    CPyTagged_DECREF(cpy_r_j);
CPyL15: ;
    cpy_r_r32 = cpy_r_r31 & 1;
    cpy_r_r33 = cpy_r_r32 != 0;
    if (cpy_r_r33) goto CPyL17;
    cpy_r_r34 = cpy_r_r30 & 1;
    cpy_r_r35 = cpy_r_r34 != 0;
    if (!cpy_r_r35) goto CPyL18;
CPyL17: ;
    cpy_r_r36 = CPyTagged_IsLt_(cpy_r_r31, cpy_r_r30);
    if (cpy_r_r36) {
        goto CPyL19;
    } else
        goto CPyL34;
CPyL18: ;
    cpy_r_r37 = (Py_ssize_t)cpy_r_r31 < (Py_ssize_t)cpy_r_r30;
    if (!cpy_r_r37) goto CPyL34;
CPyL19: ;
    CPyTagged_INCREF(cpy_r_r31);
    cpy_r_j = cpy_r_r31;
    cpy_r_r38 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AttributeError("simplified.py", "smoke_field", "HeadlessWindTunnel", "fluid", 148, CPyStatic_globals);
        goto CPyL35;
    }
    CPy_INCREF(cpy_r_r38);
CPyL20: ;
    cpy_r_r39 = CPyStatics[7]; /* 'm' */
    cpy_r_r40 = CPyObject_GetAttr(cpy_r_r38, cpy_r_r39);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("simplified.py", "smoke_field", 148, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r41 = CPyDef_HeadlessWindTunnel____idx(cpy_r_self, cpy_r_i, cpy_r_j);
    if (unlikely(cpy_r_r41 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "smoke_field", 148, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r42 = CPyTagged_StealAsObject(cpy_r_r41);
    cpy_r_r43 = PyObject_GetItem(cpy_r_r40, cpy_r_r42);
    CPy_DECREF(cpy_r_r40);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("simplified.py", "smoke_field", 148, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r44 = CPyTagged_Subtract(cpy_r_j, 2);
    CPyTagged_DECREF(cpy_r_j);
    cpy_r_r45 = CPyTagged_Subtract(cpy_r_i, 2);
    cpy_r_r46.f0 = cpy_r_r44;
    cpy_r_r46.f1 = cpy_r_r45;
    cpy_r_r47 = PyTuple_New(2);
    if (unlikely(cpy_r_r47 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp7 = CPyTagged_StealAsObject(cpy_r_r46.f0);
    PyTuple_SET_ITEM(cpy_r_r47, 0, __tmp7);
    PyObject *__tmp8 = CPyTagged_StealAsObject(cpy_r_r46.f1);
    PyTuple_SET_ITEM(cpy_r_r47, 1, __tmp8);
    cpy_r_r48 = PyObject_SetItem(cpy_r_r13, cpy_r_r47, cpy_r_r43);
    CPy_DECREF(cpy_r_r47);
    CPy_DECREF(cpy_r_r43);
    cpy_r_r49 = cpy_r_r48 >= 0;
    if (unlikely(!cpy_r_r49)) {
        CPy_AddTraceback("simplified.py", "smoke_field", 148, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r50 = CPyTagged_Add(cpy_r_r31, 2);
    CPyTagged_DECREF(cpy_r_r31);
    cpy_r_r31 = cpy_r_r50;
    goto CPyL15;
CPyL25: ;
    cpy_r_r51 = CPyTagged_Add(cpy_r_r19, 2);
    CPyTagged_DECREF(cpy_r_r19);
    cpy_r_r19 = cpy_r_r51;
    goto CPyL7;
CPyL26: ;
    return cpy_r_r13;
CPyL27: ;
    cpy_r_r52 = NULL;
    return cpy_r_r52;
CPyL28: ;
    CPyTagged_DecRef(cpy_r_r2.f0);
    CPyTagged_DecRef(cpy_r_r2.f1);
    goto CPyL27;
CPyL29: ;
    CPyTagged_DecRef(cpy_r_r2.f0);
    CPyTagged_DecRef(cpy_r_r2.f1);
    CPy_DecRef(cpy_r_r5);
    goto CPyL27;
CPyL30: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r9);
    goto CPyL27;
CPyL31: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL27;
CPyL32: ;
    CPyTagged_DECREF(cpy_r_r18);
    CPyTagged_DECREF(cpy_r_r19);
    goto CPyL26;
CPyL33: ;
    CPy_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r18);
    CPyTagged_DecRef(cpy_r_r19);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL27;
CPyL34: ;
    CPyTagged_DECREF(cpy_r_i);
    CPyTagged_DECREF(cpy_r_r30);
    CPyTagged_DECREF(cpy_r_r31);
    goto CPyL25;
CPyL35: ;
    CPy_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r18);
    CPyTagged_DecRef(cpy_r_r19);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r30);
    CPyTagged_DecRef(cpy_r_r31);
    CPyTagged_DecRef(cpy_r_j);
    goto CPyL27;
CPyL36: ;
    CPy_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r18);
    CPyTagged_DecRef(cpy_r_r19);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r30);
    CPyTagged_DecRef(cpy_r_r31);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r40);
    goto CPyL27;
CPyL37: ;
    CPy_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r18);
    CPyTagged_DecRef(cpy_r_r19);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r30);
    CPyTagged_DecRef(cpy_r_r31);
    goto CPyL27;
}
    
    PyObject *CPyPy_HeadlessWindTunnel___smoke_field(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        PyObject *obj_self = self;
        static const char * const kwlist[] = {0};
        static CPyArg_Parser parser = {":smoke_field", kwlist, 0};
        if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
            return NULL;
        }
        PyObject *arg_self;
        if (likely(Py_TYPE(obj_self) == CPyType_HeadlessWindTunnel))
            arg_self = obj_self;
        else {
            CPy_TypeError("simplified.HeadlessWindTunnel", obj_self); 
            goto fail;
        }
        PyObject *retval = CPyDef_HeadlessWindTunnel___smoke_field(arg_self);
        return retval;
fail: ;
        CPy_AddTraceback("simplified.py", "smoke_field", 143, CPyStatic_globals);
        return NULL;
    }
    
PyObject *CPyDef_HeadlessWindTunnel___pressure_field(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    tuple_T2II cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    CPyTagged cpy_r_r17;
    CPyTagged cpy_r_r18;
    CPyTagged cpy_r_r19;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r20;
    char cpy_r_r21;
    int64_t cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    CPyTagged cpy_r_r29;
    CPyTagged cpy_r_r30;
    CPyTagged cpy_r_r31;
    CPyTagged cpy_r_j;
    int64_t cpy_r_r32;
    char cpy_r_r33;
    int64_t cpy_r_r34;
    char cpy_r_r35;
    char cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    CPyTagged cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    CPyTagged cpy_r_r44;
    CPyTagged cpy_r_r45;
    tuple_T2II cpy_r_r46;
    PyObject *cpy_r_r47;
    int32_t cpy_r_r48;
    char cpy_r_r49;
    CPyTagged cpy_r_r50;
    CPyTagged cpy_r_r51;
    PyObject *cpy_r_r52;
    cpy_r_r0 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_h;
    CPyTagged_INCREF(cpy_r_r0);
    cpy_r_r1 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_w;
    CPyTagged_INCREF(cpy_r_r1);
    cpy_r_r2.f0 = cpy_r_r0;
    cpy_r_r2.f1 = cpy_r_r1;
    cpy_r_r3 = CPyModule_numpy;
    cpy_r_r4 = CPyStatics[23]; /* 'float32' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("simplified.py", "pressure_field", 153, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r6 = CPyModule_numpy;
    cpy_r_r7 = CPyStatics[24]; /* 'zeros' */
    cpy_r_r8 = CPyObject_GetAttr(cpy_r_r6, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("simplified.py", "pressure_field", 153, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r9 = PyTuple_New(2);
    if (unlikely(cpy_r_r9 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp9 = CPyTagged_StealAsObject(cpy_r_r2.f0);
    PyTuple_SET_ITEM(cpy_r_r9, 0, __tmp9);
    PyObject *__tmp10 = CPyTagged_StealAsObject(cpy_r_r2.f1);
    PyTuple_SET_ITEM(cpy_r_r9, 1, __tmp10);
    PyObject *cpy_r_r10[2] = {cpy_r_r9, cpy_r_r5};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = CPyStatics[199]; /* ('dtype',) */
    cpy_r_r13 = PyObject_Vectorcall(cpy_r_r8, cpy_r_r11, 1, cpy_r_r12);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("simplified.py", "pressure_field", 153, CPyStatic_globals);
        goto CPyL30;
    }
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r5);
    cpy_r_r14 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AttributeError("simplified.py", "pressure_field", "HeadlessWindTunnel", "fluid", 155, CPyStatic_globals);
        goto CPyL31;
    }
    CPy_INCREF(cpy_r_r14);
CPyL4: ;
    cpy_r_r15 = CPyStatics[11]; /* 'numX' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("simplified.py", "pressure_field", 155, CPyStatic_globals);
        goto CPyL31;
    }
    if (likely(PyLong_Check(cpy_r_r16)))
        cpy_r_r17 = CPyTagged_FromObject(cpy_r_r16);
    else {
        CPy_TypeError("int", cpy_r_r16); cpy_r_r17 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "pressure_field", 155, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r18 = CPyTagged_Subtract(cpy_r_r17, 2);
    CPyTagged_DECREF(cpy_r_r17);
    cpy_r_r19 = 2;
    CPyTagged_INCREF(cpy_r_r19);
    cpy_r_i = cpy_r_r19;
    CPyTagged_DECREF(cpy_r_i);
CPyL7: ;
    cpy_r_r20 = cpy_r_r19 & 1;
    cpy_r_r21 = cpy_r_r20 != 0;
    if (cpy_r_r21) goto CPyL9;
    cpy_r_r22 = cpy_r_r18 & 1;
    cpy_r_r23 = cpy_r_r22 != 0;
    if (!cpy_r_r23) goto CPyL10;
CPyL9: ;
    cpy_r_r24 = CPyTagged_IsLt_(cpy_r_r19, cpy_r_r18);
    if (cpy_r_r24) {
        goto CPyL11;
    } else
        goto CPyL32;
CPyL10: ;
    cpy_r_r25 = (Py_ssize_t)cpy_r_r19 < (Py_ssize_t)cpy_r_r18;
    if (!cpy_r_r25) goto CPyL32;
CPyL11: ;
    CPyTagged_INCREF(cpy_r_r19);
    cpy_r_i = cpy_r_r19;
    cpy_r_r26 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AttributeError("simplified.py", "pressure_field", "HeadlessWindTunnel", "fluid", 156, CPyStatic_globals);
        goto CPyL33;
    }
    CPy_INCREF(cpy_r_r26);
CPyL12: ;
    cpy_r_r27 = CPyStatics[3]; /* 'numY' */
    cpy_r_r28 = CPyObject_GetAttr(cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("simplified.py", "pressure_field", 156, CPyStatic_globals);
        goto CPyL33;
    }
    if (likely(PyLong_Check(cpy_r_r28)))
        cpy_r_r29 = CPyTagged_FromObject(cpy_r_r28);
    else {
        CPy_TypeError("int", cpy_r_r28); cpy_r_r29 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "pressure_field", 156, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r30 = CPyTagged_Subtract(cpy_r_r29, 2);
    CPyTagged_DECREF(cpy_r_r29);
    cpy_r_r31 = 2;
    CPyTagged_INCREF(cpy_r_r31);
    cpy_r_j = cpy_r_r31;
    CPyTagged_DECREF(cpy_r_j);
CPyL15: ;
    cpy_r_r32 = cpy_r_r31 & 1;
    cpy_r_r33 = cpy_r_r32 != 0;
    if (cpy_r_r33) goto CPyL17;
    cpy_r_r34 = cpy_r_r30 & 1;
    cpy_r_r35 = cpy_r_r34 != 0;
    if (!cpy_r_r35) goto CPyL18;
CPyL17: ;
    cpy_r_r36 = CPyTagged_IsLt_(cpy_r_r31, cpy_r_r30);
    if (cpy_r_r36) {
        goto CPyL19;
    } else
        goto CPyL34;
CPyL18: ;
    cpy_r_r37 = (Py_ssize_t)cpy_r_r31 < (Py_ssize_t)cpy_r_r30;
    if (!cpy_r_r37) goto CPyL34;
CPyL19: ;
    CPyTagged_INCREF(cpy_r_r31);
    cpy_r_j = cpy_r_r31;
    cpy_r_r38 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AttributeError("simplified.py", "pressure_field", "HeadlessWindTunnel", "fluid", 157, CPyStatic_globals);
        goto CPyL35;
    }
    CPy_INCREF(cpy_r_r38);
CPyL20: ;
    cpy_r_r39 = CPyStatics[10]; /* 'p' */
    cpy_r_r40 = CPyObject_GetAttr(cpy_r_r38, cpy_r_r39);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("simplified.py", "pressure_field", 157, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r41 = CPyDef_HeadlessWindTunnel____idx(cpy_r_self, cpy_r_i, cpy_r_j);
    if (unlikely(cpy_r_r41 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "pressure_field", 157, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r42 = CPyTagged_StealAsObject(cpy_r_r41);
    cpy_r_r43 = PyObject_GetItem(cpy_r_r40, cpy_r_r42);
    CPy_DECREF(cpy_r_r40);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("simplified.py", "pressure_field", 157, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r44 = CPyTagged_Subtract(cpy_r_j, 2);
    CPyTagged_DECREF(cpy_r_j);
    cpy_r_r45 = CPyTagged_Subtract(cpy_r_i, 2);
    cpy_r_r46.f0 = cpy_r_r44;
    cpy_r_r46.f1 = cpy_r_r45;
    cpy_r_r47 = PyTuple_New(2);
    if (unlikely(cpy_r_r47 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp11 = CPyTagged_StealAsObject(cpy_r_r46.f0);
    PyTuple_SET_ITEM(cpy_r_r47, 0, __tmp11);
    PyObject *__tmp12 = CPyTagged_StealAsObject(cpy_r_r46.f1);
    PyTuple_SET_ITEM(cpy_r_r47, 1, __tmp12);
    cpy_r_r48 = PyObject_SetItem(cpy_r_r13, cpy_r_r47, cpy_r_r43);
    CPy_DECREF(cpy_r_r47);
    CPy_DECREF(cpy_r_r43);
    cpy_r_r49 = cpy_r_r48 >= 0;
    if (unlikely(!cpy_r_r49)) {
        CPy_AddTraceback("simplified.py", "pressure_field", 157, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r50 = CPyTagged_Add(cpy_r_r31, 2);
    CPyTagged_DECREF(cpy_r_r31);
    cpy_r_r31 = cpy_r_r50;
    goto CPyL15;
CPyL25: ;
    cpy_r_r51 = CPyTagged_Add(cpy_r_r19, 2);
    CPyTagged_DECREF(cpy_r_r19);
    cpy_r_r19 = cpy_r_r51;
    goto CPyL7;
CPyL26: ;
    return cpy_r_r13;
CPyL27: ;
    cpy_r_r52 = NULL;
    return cpy_r_r52;
CPyL28: ;
    CPyTagged_DecRef(cpy_r_r2.f0);
    CPyTagged_DecRef(cpy_r_r2.f1);
    goto CPyL27;
CPyL29: ;
    CPyTagged_DecRef(cpy_r_r2.f0);
    CPyTagged_DecRef(cpy_r_r2.f1);
    CPy_DecRef(cpy_r_r5);
    goto CPyL27;
CPyL30: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r9);
    goto CPyL27;
CPyL31: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL27;
CPyL32: ;
    CPyTagged_DECREF(cpy_r_r18);
    CPyTagged_DECREF(cpy_r_r19);
    goto CPyL26;
CPyL33: ;
    CPy_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r18);
    CPyTagged_DecRef(cpy_r_r19);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL27;
CPyL34: ;
    CPyTagged_DECREF(cpy_r_i);
    CPyTagged_DECREF(cpy_r_r30);
    CPyTagged_DECREF(cpy_r_r31);
    goto CPyL25;
CPyL35: ;
    CPy_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r18);
    CPyTagged_DecRef(cpy_r_r19);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r30);
    CPyTagged_DecRef(cpy_r_r31);
    CPyTagged_DecRef(cpy_r_j);
    goto CPyL27;
CPyL36: ;
    CPy_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r18);
    CPyTagged_DecRef(cpy_r_r19);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r30);
    CPyTagged_DecRef(cpy_r_r31);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r40);
    goto CPyL27;
CPyL37: ;
    CPy_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r18);
    CPyTagged_DecRef(cpy_r_r19);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r30);
    CPyTagged_DecRef(cpy_r_r31);
    goto CPyL27;
}
    
    PyObject *CPyPy_HeadlessWindTunnel___pressure_field(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        PyObject *obj_self = self;
        static const char * const kwlist[] = {0};
        static CPyArg_Parser parser = {":pressure_field", kwlist, 0};
        if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
            return NULL;
        }
        PyObject *arg_self;
        if (likely(Py_TYPE(obj_self) == CPyType_HeadlessWindTunnel))
            arg_self = obj_self;
        else {
            CPy_TypeError("simplified.HeadlessWindTunnel", obj_self); 
            goto fail;
        }
        PyObject *retval = CPyDef_HeadlessWindTunnel___pressure_field(arg_self);
        return retval;
fail: ;
        CPy_AddTraceback("simplified.py", "pressure_field", 152, CPyStatic_globals);
        return NULL;
    }
    
PyObject *CPyDef_HeadlessWindTunnel___solid_field(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    tuple_T2II cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    CPyTagged cpy_r_r17;
    CPyTagged cpy_r_r18;
    CPyTagged cpy_r_r19;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r20;
    char cpy_r_r21;
    int64_t cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    CPyTagged cpy_r_r29;
    CPyTagged cpy_r_r30;
    CPyTagged cpy_r_r31;
    CPyTagged cpy_r_j;
    int64_t cpy_r_r32;
    char cpy_r_r33;
    int64_t cpy_r_r34;
    char cpy_r_r35;
    char cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    CPyTagged cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    CPyTagged cpy_r_r46;
    CPyTagged cpy_r_r47;
    tuple_T2II cpy_r_r48;
    PyObject *cpy_r_r49;
    int32_t cpy_r_r50;
    char cpy_r_r51;
    CPyTagged cpy_r_r52;
    CPyTagged cpy_r_r53;
    PyObject *cpy_r_r54;
    cpy_r_r0 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_h;
    CPyTagged_INCREF(cpy_r_r0);
    cpy_r_r1 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_grid_w;
    CPyTagged_INCREF(cpy_r_r1);
    cpy_r_r2.f0 = cpy_r_r0;
    cpy_r_r2.f1 = cpy_r_r1;
    cpy_r_r3 = CPyModule_numpy;
    cpy_r_r4 = CPyStatics[23]; /* 'float32' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("simplified.py", "solid_field", 162, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r6 = CPyModule_numpy;
    cpy_r_r7 = CPyStatics[24]; /* 'zeros' */
    cpy_r_r8 = CPyObject_GetAttr(cpy_r_r6, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("simplified.py", "solid_field", 162, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r9 = PyTuple_New(2);
    if (unlikely(cpy_r_r9 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp13 = CPyTagged_StealAsObject(cpy_r_r2.f0);
    PyTuple_SET_ITEM(cpy_r_r9, 0, __tmp13);
    PyObject *__tmp14 = CPyTagged_StealAsObject(cpy_r_r2.f1);
    PyTuple_SET_ITEM(cpy_r_r9, 1, __tmp14);
    PyObject *cpy_r_r10[2] = {cpy_r_r9, cpy_r_r5};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = CPyStatics[199]; /* ('dtype',) */
    cpy_r_r13 = PyObject_Vectorcall(cpy_r_r8, cpy_r_r11, 1, cpy_r_r12);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("simplified.py", "solid_field", 162, CPyStatic_globals);
        goto CPyL31;
    }
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r5);
    cpy_r_r14 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AttributeError("simplified.py", "solid_field", "HeadlessWindTunnel", "fluid", 164, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_INCREF(cpy_r_r14);
CPyL4: ;
    cpy_r_r15 = CPyStatics[11]; /* 'numX' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("simplified.py", "solid_field", 164, CPyStatic_globals);
        goto CPyL32;
    }
    if (likely(PyLong_Check(cpy_r_r16)))
        cpy_r_r17 = CPyTagged_FromObject(cpy_r_r16);
    else {
        CPy_TypeError("int", cpy_r_r16); cpy_r_r17 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "solid_field", 164, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r18 = CPyTagged_Subtract(cpy_r_r17, 2);
    CPyTagged_DECREF(cpy_r_r17);
    cpy_r_r19 = 2;
    CPyTagged_INCREF(cpy_r_r19);
    cpy_r_i = cpy_r_r19;
    CPyTagged_DECREF(cpy_r_i);
CPyL7: ;
    cpy_r_r20 = cpy_r_r19 & 1;
    cpy_r_r21 = cpy_r_r20 != 0;
    if (cpy_r_r21) goto CPyL9;
    cpy_r_r22 = cpy_r_r18 & 1;
    cpy_r_r23 = cpy_r_r22 != 0;
    if (!cpy_r_r23) goto CPyL10;
CPyL9: ;
    cpy_r_r24 = CPyTagged_IsLt_(cpy_r_r19, cpy_r_r18);
    if (cpy_r_r24) {
        goto CPyL11;
    } else
        goto CPyL33;
CPyL10: ;
    cpy_r_r25 = (Py_ssize_t)cpy_r_r19 < (Py_ssize_t)cpy_r_r18;
    if (!cpy_r_r25) goto CPyL33;
CPyL11: ;
    CPyTagged_INCREF(cpy_r_r19);
    cpy_r_i = cpy_r_r19;
    cpy_r_r26 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AttributeError("simplified.py", "solid_field", "HeadlessWindTunnel", "fluid", 165, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_INCREF(cpy_r_r26);
CPyL12: ;
    cpy_r_r27 = CPyStatics[3]; /* 'numY' */
    cpy_r_r28 = CPyObject_GetAttr(cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("simplified.py", "solid_field", 165, CPyStatic_globals);
        goto CPyL34;
    }
    if (likely(PyLong_Check(cpy_r_r28)))
        cpy_r_r29 = CPyTagged_FromObject(cpy_r_r28);
    else {
        CPy_TypeError("int", cpy_r_r28); cpy_r_r29 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "solid_field", 165, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r30 = CPyTagged_Subtract(cpy_r_r29, 2);
    CPyTagged_DECREF(cpy_r_r29);
    cpy_r_r31 = 2;
    CPyTagged_INCREF(cpy_r_r31);
    cpy_r_j = cpy_r_r31;
    CPyTagged_DECREF(cpy_r_j);
CPyL15: ;
    cpy_r_r32 = cpy_r_r31 & 1;
    cpy_r_r33 = cpy_r_r32 != 0;
    if (cpy_r_r33) goto CPyL17;
    cpy_r_r34 = cpy_r_r30 & 1;
    cpy_r_r35 = cpy_r_r34 != 0;
    if (!cpy_r_r35) goto CPyL18;
CPyL17: ;
    cpy_r_r36 = CPyTagged_IsLt_(cpy_r_r31, cpy_r_r30);
    if (cpy_r_r36) {
        goto CPyL19;
    } else
        goto CPyL35;
CPyL18: ;
    cpy_r_r37 = (Py_ssize_t)cpy_r_r31 < (Py_ssize_t)cpy_r_r30;
    if (!cpy_r_r37) goto CPyL35;
CPyL19: ;
    CPyTagged_INCREF(cpy_r_r31);
    cpy_r_j = cpy_r_r31;
    cpy_r_r38 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AttributeError("simplified.py", "solid_field", "HeadlessWindTunnel", "fluid", 166, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_INCREF(cpy_r_r38);
CPyL20: ;
    cpy_r_r39 = CPyStatics[5]; /* 's' */
    cpy_r_r40 = CPyObject_GetAttr(cpy_r_r38, cpy_r_r39);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("simplified.py", "solid_field", 166, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r41 = CPyDef_HeadlessWindTunnel____idx(cpy_r_self, cpy_r_i, cpy_r_j);
    if (unlikely(cpy_r_r41 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "solid_field", 166, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r42 = CPyTagged_StealAsObject(cpy_r_r41);
    cpy_r_r43 = PyObject_GetItem(cpy_r_r40, cpy_r_r42);
    CPy_DECREF(cpy_r_r40);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("simplified.py", "solid_field", 166, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r44 = PyFloat_FromDouble(1.0);
    cpy_r_r45 = PyNumber_Subtract(cpy_r_r44, cpy_r_r43);
    CPy_DECREF(cpy_r_r44);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("simplified.py", "solid_field", 166, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r46 = CPyTagged_Subtract(cpy_r_j, 2);
    CPyTagged_DECREF(cpy_r_j);
    cpy_r_r47 = CPyTagged_Subtract(cpy_r_i, 2);
    cpy_r_r48.f0 = cpy_r_r46;
    cpy_r_r48.f1 = cpy_r_r47;
    cpy_r_r49 = PyTuple_New(2);
    if (unlikely(cpy_r_r49 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp15 = CPyTagged_StealAsObject(cpy_r_r48.f0);
    PyTuple_SET_ITEM(cpy_r_r49, 0, __tmp15);
    PyObject *__tmp16 = CPyTagged_StealAsObject(cpy_r_r48.f1);
    PyTuple_SET_ITEM(cpy_r_r49, 1, __tmp16);
    cpy_r_r50 = PyObject_SetItem(cpy_r_r13, cpy_r_r49, cpy_r_r45);
    CPy_DECREF(cpy_r_r49);
    CPy_DECREF(cpy_r_r45);
    cpy_r_r51 = cpy_r_r50 >= 0;
    if (unlikely(!cpy_r_r51)) {
        CPy_AddTraceback("simplified.py", "solid_field", 166, CPyStatic_globals);
        goto CPyL38;
    }
    cpy_r_r52 = CPyTagged_Add(cpy_r_r31, 2);
    CPyTagged_DECREF(cpy_r_r31);
    cpy_r_r31 = cpy_r_r52;
    goto CPyL15;
CPyL26: ;
    cpy_r_r53 = CPyTagged_Add(cpy_r_r19, 2);
    CPyTagged_DECREF(cpy_r_r19);
    cpy_r_r19 = cpy_r_r53;
    goto CPyL7;
CPyL27: ;
    return cpy_r_r13;
CPyL28: ;
    cpy_r_r54 = NULL;
    return cpy_r_r54;
CPyL29: ;
    CPyTagged_DecRef(cpy_r_r2.f0);
    CPyTagged_DecRef(cpy_r_r2.f1);
    goto CPyL28;
CPyL30: ;
    CPyTagged_DecRef(cpy_r_r2.f0);
    CPyTagged_DecRef(cpy_r_r2.f1);
    CPy_DecRef(cpy_r_r5);
    goto CPyL28;
CPyL31: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r9);
    goto CPyL28;
CPyL32: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL28;
CPyL33: ;
    CPyTagged_DECREF(cpy_r_r18);
    CPyTagged_DECREF(cpy_r_r19);
    goto CPyL27;
CPyL34: ;
    CPy_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r18);
    CPyTagged_DecRef(cpy_r_r19);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL28;
CPyL35: ;
    CPyTagged_DECREF(cpy_r_i);
    CPyTagged_DECREF(cpy_r_r30);
    CPyTagged_DECREF(cpy_r_r31);
    goto CPyL26;
CPyL36: ;
    CPy_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r18);
    CPyTagged_DecRef(cpy_r_r19);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r30);
    CPyTagged_DecRef(cpy_r_r31);
    CPyTagged_DecRef(cpy_r_j);
    goto CPyL28;
CPyL37: ;
    CPy_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r18);
    CPyTagged_DecRef(cpy_r_r19);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r30);
    CPyTagged_DecRef(cpy_r_r31);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r40);
    goto CPyL28;
CPyL38: ;
    CPy_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r18);
    CPyTagged_DecRef(cpy_r_r19);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r30);
    CPyTagged_DecRef(cpy_r_r31);
    goto CPyL28;
}
    
    PyObject *CPyPy_HeadlessWindTunnel___solid_field(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        PyObject *obj_self = self;
        static const char * const kwlist[] = {0};
        static CPyArg_Parser parser = {":solid_field", kwlist, 0};
        if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
            return NULL;
        }
        PyObject *arg_self;
        if (likely(Py_TYPE(obj_self) == CPyType_HeadlessWindTunnel))
            arg_self = obj_self;
        else {
            CPy_TypeError("simplified.HeadlessWindTunnel", obj_self); 
            goto fail;
        }
        PyObject *retval = CPyDef_HeadlessWindTunnel___solid_field(arg_self);
        return retval;
fail: ;
        CPy_AddTraceback("simplified.py", "solid_field", 161, CPyStatic_globals);
        return NULL;
    }
    
PyObject *CPyDef_HeadlessWindTunnel___export_cell_data(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    CPyTagged cpy_r_r8;
    CPyTagged cpy_r_r9;
    CPyTagged cpy_r_r10;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r11;
    char cpy_r_r12;
    int64_t cpy_r_r13;
    char cpy_r_r14;
    char cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    CPyTagged cpy_r_r20;
    CPyTagged cpy_r_r21;
    CPyTagged cpy_r_r22;
    CPyTagged cpy_r_j;
    int64_t cpy_r_r23;
    char cpy_r_r24;
    int64_t cpy_r_r25;
    char cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
    CPyTagged cpy_r_r29;
    CPyTagged cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    CPyTagged cpy_r_r39;
    CPyTagged cpy_r_r40;
    CPyTagged cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject **cpy_r_r49;
    PyObject *cpy_r_r50;
    double cpy_r_r51;
    char cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    CPyTagged cpy_r_r62;
    CPyTagged cpy_r_r63;
    CPyTagged cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject **cpy_r_r72;
    PyObject *cpy_r_r73;
    double cpy_r_r74;
    char cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject **cpy_r_r84;
    PyObject *cpy_r_r85;
    double cpy_r_r86;
    char cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject **cpy_r_r96;
    PyObject *cpy_r_r97;
    double cpy_r_r98;
    char cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject **cpy_r_r108;
    PyObject *cpy_r_r109;
    double cpy_r_r110;
    char cpy_r_r111;
    double cpy_r_r112;
    double cpy_r_r113;
    double cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject **cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject **cpy_r_r125;
    PyObject *cpy_r_r126;
    double cpy_r_r127;
    char cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject **cpy_r_r137;
    PyObject *cpy_r_r138;
    double cpy_r_r139;
    char cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject **cpy_r_r149;
    PyObject *cpy_r_r150;
    double cpy_r_r151;
    char cpy_r_r152;
    tuple_T11IIIFFFFFFFF cpy_r_r153;
    PyObject *cpy_r_r154;
    int32_t cpy_r_r155;
    char cpy_r_r156;
    PyObject *cpy_r_r157;
    CPyTagged cpy_r_r158;
    CPyTagged cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    tuple_T2OO cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    PyObject *cpy_r_r168;
    tuple_T2OO cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    tuple_T2OO cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    tuple_T2OO cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject *cpy_r_r182;
    PyObject *cpy_r_r183;
    tuple_T2OO cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    tuple_T2OO cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    tuple_T2OO cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject *cpy_r_r198;
    tuple_T2OO cpy_r_r199;
    PyObject *cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    tuple_T2OO cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    PyObject *cpy_r_r207;
    PyObject *cpy_r_r208;
    tuple_T2OO cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject *cpy_r_r213;
    tuple_T2OO cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject *cpy_r_r219;
    PyObject *cpy_r_r220;
    PyObject *cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_r223;
    PyObject *cpy_r_r224;
    PyObject *cpy_r_r225;
    PyObject *cpy_r_r226;
    PyObject *cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject **cpy_r_r231;
    PyObject *cpy_r_r232;
    PyObject *cpy_r_r233;
    PyObject *cpy_r_r234;
    cpy_r_r0 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("simplified.py", "export_cell_data", "HeadlessWindTunnel", "fluid", 171, CPyStatic_globals);
        goto CPyL95;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyStatics[3]; /* 'numY' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 171, CPyStatic_globals);
        goto CPyL95;
    }
    if (likely(PyLong_Check(cpy_r_r2)))
        cpy_r_r3 = CPyTagged_FromObject(cpy_r_r2);
    else {
        CPy_TypeError("int", cpy_r_r2); cpy_r_r3 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 171, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r4 = PyList_New(0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 172, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r5 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AttributeError("simplified.py", "export_cell_data", "HeadlessWindTunnel", "fluid", 174, CPyStatic_globals);
        goto CPyL97;
    }
    CPy_INCREF(cpy_r_r5);
CPyL5: ;
    cpy_r_r6 = CPyStatics[11]; /* 'numX' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 174, CPyStatic_globals);
        goto CPyL97;
    }
    if (likely(PyLong_Check(cpy_r_r7)))
        cpy_r_r8 = CPyTagged_FromObject(cpy_r_r7);
    else {
        CPy_TypeError("int", cpy_r_r7); cpy_r_r8 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 174, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r9 = CPyTagged_Subtract(cpy_r_r8, 2);
    CPyTagged_DECREF(cpy_r_r8);
    cpy_r_r10 = 2;
    CPyTagged_INCREF(cpy_r_r10);
    cpy_r_i = cpy_r_r10;
    CPyTagged_DECREF(cpy_r_i);
CPyL8: ;
    cpy_r_r11 = cpy_r_r10 & 1;
    cpy_r_r12 = cpy_r_r11 != 0;
    if (cpy_r_r12) goto CPyL10;
    cpy_r_r13 = cpy_r_r9 & 1;
    cpy_r_r14 = cpy_r_r13 != 0;
    if (!cpy_r_r14) goto CPyL11;
CPyL10: ;
    cpy_r_r15 = CPyTagged_IsLt_(cpy_r_r10, cpy_r_r9);
    if (cpy_r_r15) {
        goto CPyL12;
    } else
        goto CPyL98;
CPyL11: ;
    cpy_r_r16 = (Py_ssize_t)cpy_r_r10 < (Py_ssize_t)cpy_r_r9;
    if (!cpy_r_r16) goto CPyL98;
CPyL12: ;
    CPyTagged_INCREF(cpy_r_r10);
    cpy_r_i = cpy_r_r10;
    cpy_r_r17 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AttributeError("simplified.py", "export_cell_data", "HeadlessWindTunnel", "fluid", 175, CPyStatic_globals);
        goto CPyL99;
    }
    CPy_INCREF(cpy_r_r17);
CPyL13: ;
    cpy_r_r18 = CPyStatics[3]; /* 'numY' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 175, CPyStatic_globals);
        goto CPyL99;
    }
    if (likely(PyLong_Check(cpy_r_r19)))
        cpy_r_r20 = CPyTagged_FromObject(cpy_r_r19);
    else {
        CPy_TypeError("int", cpy_r_r19); cpy_r_r20 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 175, CPyStatic_globals);
        goto CPyL99;
    }
    cpy_r_r21 = CPyTagged_Subtract(cpy_r_r20, 2);
    CPyTagged_DECREF(cpy_r_r20);
    cpy_r_r22 = 2;
    CPyTagged_INCREF(cpy_r_r22);
    cpy_r_j = cpy_r_r22;
    CPyTagged_DECREF(cpy_r_j);
CPyL16: ;
    cpy_r_r23 = cpy_r_r22 & 1;
    cpy_r_r24 = cpy_r_r23 != 0;
    if (cpy_r_r24) goto CPyL18;
    cpy_r_r25 = cpy_r_r21 & 1;
    cpy_r_r26 = cpy_r_r25 != 0;
    if (!cpy_r_r26) goto CPyL19;
CPyL18: ;
    cpy_r_r27 = CPyTagged_IsLt_(cpy_r_r22, cpy_r_r21);
    if (cpy_r_r27) {
        goto CPyL20;
    } else
        goto CPyL100;
CPyL19: ;
    cpy_r_r28 = (Py_ssize_t)cpy_r_r22 < (Py_ssize_t)cpy_r_r21;
    if (!cpy_r_r28) goto CPyL100;
CPyL20: ;
    CPyTagged_INCREF(cpy_r_r22);
    cpy_r_j = cpy_r_r22;
    cpy_r_r29 = CPyTagged_Multiply(cpy_r_i, cpy_r_r3);
    cpy_r_r30 = CPyTagged_Add(cpy_r_r29, cpy_r_j);
    CPyTagged_DECREF(cpy_r_r29);
    cpy_r_r31 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AttributeError("simplified.py", "export_cell_data", "HeadlessWindTunnel", "fluid", 177, CPyStatic_globals);
        goto CPyL101;
    }
    CPy_INCREF(cpy_r_r31);
CPyL21: ;
    cpy_r_r32 = CPyStatics[8]; /* 'u' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_r31, cpy_r_r32);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 177, CPyStatic_globals);
        goto CPyL101;
    }
    CPyTagged_INCREF(cpy_r_r30);
    cpy_r_r34 = CPyTagged_StealAsObject(cpy_r_r30);
    cpy_r_r35 = PyObject_GetItem(cpy_r_r33, cpy_r_r34);
    CPy_DECREF(cpy_r_r33);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 177, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r36 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AttributeError("simplified.py", "export_cell_data", "HeadlessWindTunnel", "fluid", 177, CPyStatic_globals);
        goto CPyL102;
    }
    CPy_INCREF(cpy_r_r36);
CPyL24: ;
    cpy_r_r37 = CPyStatics[8]; /* 'u' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_r36, cpy_r_r37);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 177, CPyStatic_globals);
        goto CPyL102;
    }
    cpy_r_r39 = CPyTagged_Add(cpy_r_i, 2);
    cpy_r_r40 = CPyTagged_Multiply(cpy_r_r39, cpy_r_r3);
    CPyTagged_DECREF(cpy_r_r39);
    cpy_r_r41 = CPyTagged_Add(cpy_r_r40, cpy_r_j);
    CPyTagged_DECREF(cpy_r_r40);
    cpy_r_r42 = CPyTagged_StealAsObject(cpy_r_r41);
    cpy_r_r43 = PyObject_GetItem(cpy_r_r38, cpy_r_r42);
    CPy_DECREF(cpy_r_r38);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 177, CPyStatic_globals);
        goto CPyL102;
    }
    cpy_r_r44 = PyNumber_Add(cpy_r_r35, cpy_r_r43);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 177, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r45 = PyFloat_FromDouble(0.5);
    cpy_r_r46 = PyNumber_Multiply(cpy_r_r45, cpy_r_r44);
    CPy_DECREF(cpy_r_r45);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 177, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r47 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r48[1] = {cpy_r_r46};
    cpy_r_r49 = (PyObject **)&cpy_r_r48;
    cpy_r_r50 = PyObject_Vectorcall(cpy_r_r47, cpy_r_r49, 1, 0);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 177, CPyStatic_globals);
        goto CPyL103;
    }
    CPy_DECREF(cpy_r_r46);
    cpy_r_r51 = PyFloat_AsDouble(cpy_r_r50);
    if (cpy_r_r51 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r50); cpy_r_r51 = -113.0;
    }
    CPy_DECREF(cpy_r_r50);
    cpy_r_r52 = cpy_r_r51 == -113.0;
    if (unlikely(cpy_r_r52)) goto CPyL31;
CPyL30: ;
    cpy_r_r53 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AttributeError("simplified.py", "export_cell_data", "HeadlessWindTunnel", "fluid", 178, CPyStatic_globals);
        goto CPyL101;
    }
    CPy_INCREF(cpy_r_r53);
    goto CPyL32;
CPyL31: ;
    cpy_r_r54 = PyErr_Occurred();
    if (unlikely(cpy_r_r54 != NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 177, CPyStatic_globals);
        goto CPyL101;
    } else
        goto CPyL30;
CPyL32: ;
    cpy_r_r55 = CPyStatics[9]; /* 'v' */
    cpy_r_r56 = CPyObject_GetAttr(cpy_r_r53, cpy_r_r55);
    CPy_DECREF(cpy_r_r53);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 178, CPyStatic_globals);
        goto CPyL101;
    }
    CPyTagged_INCREF(cpy_r_r30);
    cpy_r_r57 = CPyTagged_StealAsObject(cpy_r_r30);
    cpy_r_r58 = PyObject_GetItem(cpy_r_r56, cpy_r_r57);
    CPy_DECREF(cpy_r_r56);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 178, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r59 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AttributeError("simplified.py", "export_cell_data", "HeadlessWindTunnel", "fluid", 178, CPyStatic_globals);
        goto CPyL104;
    }
    CPy_INCREF(cpy_r_r59);
CPyL35: ;
    cpy_r_r60 = CPyStatics[9]; /* 'v' */
    cpy_r_r61 = CPyObject_GetAttr(cpy_r_r59, cpy_r_r60);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 178, CPyStatic_globals);
        goto CPyL104;
    }
    cpy_r_r62 = CPyTagged_Multiply(cpy_r_i, cpy_r_r3);
    cpy_r_r63 = CPyTagged_Add(cpy_r_j, 2);
    cpy_r_r64 = CPyTagged_Add(cpy_r_r62, cpy_r_r63);
    CPyTagged_DECREF(cpy_r_r62);
    CPyTagged_DECREF(cpy_r_r63);
    cpy_r_r65 = CPyTagged_StealAsObject(cpy_r_r64);
    cpy_r_r66 = PyObject_GetItem(cpy_r_r61, cpy_r_r65);
    CPy_DECREF(cpy_r_r61);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 178, CPyStatic_globals);
        goto CPyL104;
    }
    cpy_r_r67 = PyNumber_Add(cpy_r_r58, cpy_r_r66);
    CPy_DECREF(cpy_r_r58);
    CPy_DECREF(cpy_r_r66);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 178, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r68 = PyFloat_FromDouble(0.5);
    cpy_r_r69 = PyNumber_Multiply(cpy_r_r68, cpy_r_r67);
    CPy_DECREF(cpy_r_r68);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 178, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r70 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r71[1] = {cpy_r_r69};
    cpy_r_r72 = (PyObject **)&cpy_r_r71;
    cpy_r_r73 = PyObject_Vectorcall(cpy_r_r70, cpy_r_r72, 1, 0);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 178, CPyStatic_globals);
        goto CPyL105;
    }
    CPy_DECREF(cpy_r_r69);
    cpy_r_r74 = PyFloat_AsDouble(cpy_r_r73);
    if (cpy_r_r74 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r73); cpy_r_r74 = -113.0;
    }
    CPy_DECREF(cpy_r_r73);
    cpy_r_r75 = cpy_r_r74 == -113.0;
    if (unlikely(cpy_r_r75)) goto CPyL42;
CPyL41: ;
    cpy_r_r76 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AttributeError("simplified.py", "export_cell_data", "HeadlessWindTunnel", "fluid", 184, CPyStatic_globals);
        goto CPyL101;
    }
    CPy_INCREF(cpy_r_r76);
    goto CPyL43;
CPyL42: ;
    cpy_r_r77 = PyErr_Occurred();
    if (unlikely(cpy_r_r77 != NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 178, CPyStatic_globals);
        goto CPyL101;
    } else
        goto CPyL41;
CPyL43: ;
    cpy_r_r78 = CPyStatics[5]; /* 's' */
    cpy_r_r79 = CPyObject_GetAttr(cpy_r_r76, cpy_r_r78);
    CPy_DECREF(cpy_r_r76);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 184, CPyStatic_globals);
        goto CPyL101;
    }
    CPyTagged_INCREF(cpy_r_r30);
    cpy_r_r80 = CPyTagged_StealAsObject(cpy_r_r30);
    cpy_r_r81 = PyObject_GetItem(cpy_r_r79, cpy_r_r80);
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_r80);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 184, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r82 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r83[1] = {cpy_r_r81};
    cpy_r_r84 = (PyObject **)&cpy_r_r83;
    cpy_r_r85 = PyObject_Vectorcall(cpy_r_r82, cpy_r_r84, 1, 0);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 184, CPyStatic_globals);
        goto CPyL106;
    }
    CPy_DECREF(cpy_r_r81);
    cpy_r_r86 = PyFloat_AsDouble(cpy_r_r85);
    if (cpy_r_r86 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r85); cpy_r_r86 = -113.0;
    }
    CPy_DECREF(cpy_r_r85);
    cpy_r_r87 = cpy_r_r86 == -113.0;
    if (unlikely(cpy_r_r87)) goto CPyL48;
CPyL47: ;
    cpy_r_r88 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AttributeError("simplified.py", "export_cell_data", "HeadlessWindTunnel", "fluid", 185, CPyStatic_globals);
        goto CPyL101;
    }
    CPy_INCREF(cpy_r_r88);
    goto CPyL49;
CPyL48: ;
    cpy_r_r89 = PyErr_Occurred();
    if (unlikely(cpy_r_r89 != NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 184, CPyStatic_globals);
        goto CPyL101;
    } else
        goto CPyL47;
CPyL49: ;
    cpy_r_r90 = CPyStatics[8]; /* 'u' */
    cpy_r_r91 = CPyObject_GetAttr(cpy_r_r88, cpy_r_r90);
    CPy_DECREF(cpy_r_r88);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 185, CPyStatic_globals);
        goto CPyL101;
    }
    CPyTagged_INCREF(cpy_r_r30);
    cpy_r_r92 = CPyTagged_StealAsObject(cpy_r_r30);
    cpy_r_r93 = PyObject_GetItem(cpy_r_r91, cpy_r_r92);
    CPy_DECREF(cpy_r_r91);
    CPy_DECREF(cpy_r_r92);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 185, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r94 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r95[1] = {cpy_r_r93};
    cpy_r_r96 = (PyObject **)&cpy_r_r95;
    cpy_r_r97 = PyObject_Vectorcall(cpy_r_r94, cpy_r_r96, 1, 0);
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 185, CPyStatic_globals);
        goto CPyL107;
    }
    CPy_DECREF(cpy_r_r93);
    cpy_r_r98 = PyFloat_AsDouble(cpy_r_r97);
    if (cpy_r_r98 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r97); cpy_r_r98 = -113.0;
    }
    CPy_DECREF(cpy_r_r97);
    cpy_r_r99 = cpy_r_r98 == -113.0;
    if (unlikely(cpy_r_r99)) goto CPyL54;
CPyL53: ;
    cpy_r_r100 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AttributeError("simplified.py", "export_cell_data", "HeadlessWindTunnel", "fluid", 186, CPyStatic_globals);
        goto CPyL101;
    }
    CPy_INCREF(cpy_r_r100);
    goto CPyL55;
CPyL54: ;
    cpy_r_r101 = PyErr_Occurred();
    if (unlikely(cpy_r_r101 != NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 185, CPyStatic_globals);
        goto CPyL101;
    } else
        goto CPyL53;
CPyL55: ;
    cpy_r_r102 = CPyStatics[9]; /* 'v' */
    cpy_r_r103 = CPyObject_GetAttr(cpy_r_r100, cpy_r_r102);
    CPy_DECREF(cpy_r_r100);
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 186, CPyStatic_globals);
        goto CPyL101;
    }
    CPyTagged_INCREF(cpy_r_r30);
    cpy_r_r104 = CPyTagged_StealAsObject(cpy_r_r30);
    cpy_r_r105 = PyObject_GetItem(cpy_r_r103, cpy_r_r104);
    CPy_DECREF(cpy_r_r103);
    CPy_DECREF(cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 186, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r106 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r107[1] = {cpy_r_r105};
    cpy_r_r108 = (PyObject **)&cpy_r_r107;
    cpy_r_r109 = PyObject_Vectorcall(cpy_r_r106, cpy_r_r108, 1, 0);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 186, CPyStatic_globals);
        goto CPyL108;
    }
    CPy_DECREF(cpy_r_r105);
    cpy_r_r110 = PyFloat_AsDouble(cpy_r_r109);
    if (cpy_r_r110 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r109); cpy_r_r110 = -113.0;
    }
    CPy_DECREF(cpy_r_r109);
    cpy_r_r111 = cpy_r_r110 == -113.0;
    if (unlikely(cpy_r_r111)) goto CPyL60;
CPyL59: ;
    cpy_r_r112 = cpy_r_r51 * cpy_r_r51;
    cpy_r_r113 = cpy_r_r74 * cpy_r_r74;
    cpy_r_r114 = cpy_r_r112 + cpy_r_r113;
    cpy_r_r115 = CPyModule_numpy;
    cpy_r_r116 = CPyStatics[26]; /* 'sqrt' */
    cpy_r_r117 = CPyObject_GetAttr(cpy_r_r115, cpy_r_r116);
    if (unlikely(cpy_r_r117 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 189, CPyStatic_globals);
        goto CPyL101;
    } else
        goto CPyL61;
CPyL60: ;
    cpy_r_r118 = PyErr_Occurred();
    if (unlikely(cpy_r_r118 != NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 186, CPyStatic_globals);
        goto CPyL101;
    } else
        goto CPyL59;
CPyL61: ;
    cpy_r_r119 = PyFloat_FromDouble(cpy_r_r114);
    PyObject *cpy_r_r120[1] = {cpy_r_r119};
    cpy_r_r121 = (PyObject **)&cpy_r_r120;
    cpy_r_r122 = PyObject_Vectorcall(cpy_r_r117, cpy_r_r121, 1, 0);
    CPy_DECREF(cpy_r_r117);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 189, CPyStatic_globals);
        goto CPyL109;
    }
    CPy_DECREF(cpy_r_r119);
    cpy_r_r123 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r124[1] = {cpy_r_r122};
    cpy_r_r125 = (PyObject **)&cpy_r_r124;
    cpy_r_r126 = PyObject_Vectorcall(cpy_r_r123, cpy_r_r125, 1, 0);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 189, CPyStatic_globals);
        goto CPyL110;
    }
    CPy_DECREF(cpy_r_r122);
    cpy_r_r127 = PyFloat_AsDouble(cpy_r_r126);
    if (cpy_r_r127 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r126); cpy_r_r127 = -113.0;
    }
    CPy_DECREF(cpy_r_r126);
    cpy_r_r128 = cpy_r_r127 == -113.0;
    if (unlikely(cpy_r_r128)) goto CPyL65;
CPyL64: ;
    cpy_r_r129 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AttributeError("simplified.py", "export_cell_data", "HeadlessWindTunnel", "fluid", 190, CPyStatic_globals);
        goto CPyL101;
    }
    CPy_INCREF(cpy_r_r129);
    goto CPyL66;
CPyL65: ;
    cpy_r_r130 = PyErr_Occurred();
    if (unlikely(cpy_r_r130 != NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 189, CPyStatic_globals);
        goto CPyL101;
    } else
        goto CPyL64;
CPyL66: ;
    cpy_r_r131 = CPyStatics[7]; /* 'm' */
    cpy_r_r132 = CPyObject_GetAttr(cpy_r_r129, cpy_r_r131);
    CPy_DECREF(cpy_r_r129);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 190, CPyStatic_globals);
        goto CPyL101;
    }
    CPyTagged_INCREF(cpy_r_r30);
    cpy_r_r133 = CPyTagged_StealAsObject(cpy_r_r30);
    cpy_r_r134 = PyObject_GetItem(cpy_r_r132, cpy_r_r133);
    CPy_DECREF(cpy_r_r132);
    CPy_DECREF(cpy_r_r133);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 190, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r135 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r136[1] = {cpy_r_r134};
    cpy_r_r137 = (PyObject **)&cpy_r_r136;
    cpy_r_r138 = PyObject_Vectorcall(cpy_r_r135, cpy_r_r137, 1, 0);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 190, CPyStatic_globals);
        goto CPyL111;
    }
    CPy_DECREF(cpy_r_r134);
    cpy_r_r139 = PyFloat_AsDouble(cpy_r_r138);
    if (cpy_r_r139 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r138); cpy_r_r139 = -113.0;
    }
    CPy_DECREF(cpy_r_r138);
    cpy_r_r140 = cpy_r_r139 == -113.0;
    if (unlikely(cpy_r_r140)) goto CPyL71;
CPyL70: ;
    cpy_r_r141 = ((simplified___HeadlessWindTunnelObject *)cpy_r_self)->_fluid;
    if (unlikely(cpy_r_r141 == NULL)) {
        CPy_AttributeError("simplified.py", "export_cell_data", "HeadlessWindTunnel", "fluid", 191, CPyStatic_globals);
        goto CPyL101;
    }
    CPy_INCREF(cpy_r_r141);
    goto CPyL72;
CPyL71: ;
    cpy_r_r142 = PyErr_Occurred();
    if (unlikely(cpy_r_r142 != NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 190, CPyStatic_globals);
        goto CPyL101;
    } else
        goto CPyL70;
CPyL72: ;
    cpy_r_r143 = CPyStatics[10]; /* 'p' */
    cpy_r_r144 = CPyObject_GetAttr(cpy_r_r141, cpy_r_r143);
    CPy_DECREF(cpy_r_r141);
    if (unlikely(cpy_r_r144 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 191, CPyStatic_globals);
        goto CPyL101;
    }
    CPyTagged_INCREF(cpy_r_r30);
    cpy_r_r145 = CPyTagged_StealAsObject(cpy_r_r30);
    cpy_r_r146 = PyObject_GetItem(cpy_r_r144, cpy_r_r145);
    CPy_DECREF(cpy_r_r144);
    CPy_DECREF(cpy_r_r145);
    if (unlikely(cpy_r_r146 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 191, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r147 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r148[1] = {cpy_r_r146};
    cpy_r_r149 = (PyObject **)&cpy_r_r148;
    cpy_r_r150 = PyObject_Vectorcall(cpy_r_r147, cpy_r_r149, 1, 0);
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 191, CPyStatic_globals);
        goto CPyL112;
    }
    CPy_DECREF(cpy_r_r146);
    cpy_r_r151 = PyFloat_AsDouble(cpy_r_r150);
    if (cpy_r_r151 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r150); cpy_r_r151 = -113.0;
    }
    CPy_DECREF(cpy_r_r150);
    cpy_r_r152 = cpy_r_r151 == -113.0;
    if (unlikely(cpy_r_r152)) goto CPyL77;
CPyL76: ;
    CPyTagged_INCREF(cpy_r_i);
    cpy_r_r153.f0 = cpy_r_r30;
    cpy_r_r153.f1 = cpy_r_i;
    cpy_r_r153.f2 = cpy_r_j;
    cpy_r_r153.f3 = cpy_r_r86;
    cpy_r_r153.f4 = cpy_r_r98;
    cpy_r_r153.f5 = cpy_r_r110;
    cpy_r_r153.f6 = cpy_r_r51;
    cpy_r_r153.f7 = cpy_r_r74;
    cpy_r_r153.f8 = cpy_r_r127;
    cpy_r_r153.f9 = cpy_r_r139;
    cpy_r_r153.f10 = cpy_r_r151;
    cpy_r_r154 = PyTuple_New(11);
    if (unlikely(cpy_r_r154 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp17 = CPyTagged_StealAsObject(cpy_r_r153.f0);
    PyTuple_SET_ITEM(cpy_r_r154, 0, __tmp17);
    PyObject *__tmp18 = CPyTagged_StealAsObject(cpy_r_r153.f1);
    PyTuple_SET_ITEM(cpy_r_r154, 1, __tmp18);
    PyObject *__tmp19 = CPyTagged_StealAsObject(cpy_r_r153.f2);
    PyTuple_SET_ITEM(cpy_r_r154, 2, __tmp19);
    PyObject *__tmp20 = PyFloat_FromDouble(cpy_r_r153.f3);
    PyTuple_SET_ITEM(cpy_r_r154, 3, __tmp20);
    PyObject *__tmp21 = PyFloat_FromDouble(cpy_r_r153.f4);
    PyTuple_SET_ITEM(cpy_r_r154, 4, __tmp21);
    PyObject *__tmp22 = PyFloat_FromDouble(cpy_r_r153.f5);
    PyTuple_SET_ITEM(cpy_r_r154, 5, __tmp22);
    PyObject *__tmp23 = PyFloat_FromDouble(cpy_r_r153.f6);
    PyTuple_SET_ITEM(cpy_r_r154, 6, __tmp23);
    PyObject *__tmp24 = PyFloat_FromDouble(cpy_r_r153.f7);
    PyTuple_SET_ITEM(cpy_r_r154, 7, __tmp24);
    PyObject *__tmp25 = PyFloat_FromDouble(cpy_r_r153.f8);
    PyTuple_SET_ITEM(cpy_r_r154, 8, __tmp25);
    PyObject *__tmp26 = PyFloat_FromDouble(cpy_r_r153.f9);
    PyTuple_SET_ITEM(cpy_r_r154, 9, __tmp26);
    PyObject *__tmp27 = PyFloat_FromDouble(cpy_r_r153.f10);
    PyTuple_SET_ITEM(cpy_r_r154, 10, __tmp27);
    cpy_r_r155 = PyList_Append(cpy_r_r4, cpy_r_r154);
    CPy_DECREF(cpy_r_r154);
    cpy_r_r156 = cpy_r_r155 >= 0;
    if (unlikely(!cpy_r_r156)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 179, CPyStatic_globals);
        goto CPyL113;
    } else
        goto CPyL78;
CPyL77: ;
    cpy_r_r157 = PyErr_Occurred();
    if (unlikely(cpy_r_r157 != NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 191, CPyStatic_globals);
        goto CPyL101;
    } else
        goto CPyL76;
CPyL78: ;
    cpy_r_r158 = CPyTagged_Add(cpy_r_r22, 2);
    CPyTagged_DECREF(cpy_r_r22);
    cpy_r_r22 = cpy_r_r158;
    goto CPyL16;
CPyL79: ;
    cpy_r_r159 = CPyTagged_Add(cpy_r_r10, 2);
    CPyTagged_DECREF(cpy_r_r10);
    cpy_r_r10 = cpy_r_r159;
    goto CPyL8;
CPyL80: ;
    cpy_r_r160 = CPyStatics[27]; /* 'cell_id' */
    cpy_r_r161 = CPyModule_numpy;
    cpy_r_r162 = CPyStatics[28]; /* 'int32' */
    cpy_r_r163 = CPyObject_GetAttr(cpy_r_r161, cpy_r_r162);
    if (unlikely(cpy_r_r163 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 198, CPyStatic_globals);
        goto CPyL114;
    }
    CPy_INCREF(cpy_r_r160);
    cpy_r_r164.f0 = cpy_r_r160;
    cpy_r_r164.f1 = cpy_r_r163;
    cpy_r_r165 = CPyStatics[29]; /* 'i' */
    cpy_r_r166 = CPyModule_numpy;
    cpy_r_r167 = CPyStatics[28]; /* 'int32' */
    cpy_r_r168 = CPyObject_GetAttr(cpy_r_r166, cpy_r_r167);
    if (unlikely(cpy_r_r168 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 199, CPyStatic_globals);
        goto CPyL115;
    }
    CPy_INCREF(cpy_r_r165);
    cpy_r_r169.f0 = cpy_r_r165;
    cpy_r_r169.f1 = cpy_r_r168;
    cpy_r_r170 = CPyStatics[30]; /* 'j' */
    cpy_r_r171 = CPyModule_numpy;
    cpy_r_r172 = CPyStatics[28]; /* 'int32' */
    cpy_r_r173 = CPyObject_GetAttr(cpy_r_r171, cpy_r_r172);
    if (unlikely(cpy_r_r173 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 200, CPyStatic_globals);
        goto CPyL116;
    }
    CPy_INCREF(cpy_r_r170);
    cpy_r_r174.f0 = cpy_r_r170;
    cpy_r_r174.f1 = cpy_r_r173;
    cpy_r_r175 = CPyStatics[5]; /* 's' */
    cpy_r_r176 = CPyModule_numpy;
    cpy_r_r177 = CPyStatics[23]; /* 'float32' */
    cpy_r_r178 = CPyObject_GetAttr(cpy_r_r176, cpy_r_r177);
    if (unlikely(cpy_r_r178 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 201, CPyStatic_globals);
        goto CPyL117;
    }
    CPy_INCREF(cpy_r_r175);
    cpy_r_r179.f0 = cpy_r_r175;
    cpy_r_r179.f1 = cpy_r_r178;
    cpy_r_r180 = CPyStatics[31]; /* 'u_face' */
    cpy_r_r181 = CPyModule_numpy;
    cpy_r_r182 = CPyStatics[23]; /* 'float32' */
    cpy_r_r183 = CPyObject_GetAttr(cpy_r_r181, cpy_r_r182);
    if (unlikely(cpy_r_r183 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 202, CPyStatic_globals);
        goto CPyL118;
    }
    CPy_INCREF(cpy_r_r180);
    cpy_r_r184.f0 = cpy_r_r180;
    cpy_r_r184.f1 = cpy_r_r183;
    cpy_r_r185 = CPyStatics[32]; /* 'v_face' */
    cpy_r_r186 = CPyModule_numpy;
    cpy_r_r187 = CPyStatics[23]; /* 'float32' */
    cpy_r_r188 = CPyObject_GetAttr(cpy_r_r186, cpy_r_r187);
    if (unlikely(cpy_r_r188 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 203, CPyStatic_globals);
        goto CPyL119;
    }
    CPy_INCREF(cpy_r_r185);
    cpy_r_r189.f0 = cpy_r_r185;
    cpy_r_r189.f1 = cpy_r_r188;
    cpy_r_r190 = CPyStatics[33]; /* 'u_center' */
    cpy_r_r191 = CPyModule_numpy;
    cpy_r_r192 = CPyStatics[23]; /* 'float32' */
    cpy_r_r193 = CPyObject_GetAttr(cpy_r_r191, cpy_r_r192);
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 204, CPyStatic_globals);
        goto CPyL120;
    }
    CPy_INCREF(cpy_r_r190);
    cpy_r_r194.f0 = cpy_r_r190;
    cpy_r_r194.f1 = cpy_r_r193;
    cpy_r_r195 = CPyStatics[34]; /* 'v_center' */
    cpy_r_r196 = CPyModule_numpy;
    cpy_r_r197 = CPyStatics[23]; /* 'float32' */
    cpy_r_r198 = CPyObject_GetAttr(cpy_r_r196, cpy_r_r197);
    if (unlikely(cpy_r_r198 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 205, CPyStatic_globals);
        goto CPyL121;
    }
    CPy_INCREF(cpy_r_r195);
    cpy_r_r199.f0 = cpy_r_r195;
    cpy_r_r199.f1 = cpy_r_r198;
    cpy_r_r200 = CPyStatics[35]; /* 'speed' */
    cpy_r_r201 = CPyModule_numpy;
    cpy_r_r202 = CPyStatics[23]; /* 'float32' */
    cpy_r_r203 = CPyObject_GetAttr(cpy_r_r201, cpy_r_r202);
    if (unlikely(cpy_r_r203 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 206, CPyStatic_globals);
        goto CPyL122;
    }
    CPy_INCREF(cpy_r_r200);
    cpy_r_r204.f0 = cpy_r_r200;
    cpy_r_r204.f1 = cpy_r_r203;
    cpy_r_r205 = CPyStatics[36]; /* 'smoke' */
    cpy_r_r206 = CPyModule_numpy;
    cpy_r_r207 = CPyStatics[23]; /* 'float32' */
    cpy_r_r208 = CPyObject_GetAttr(cpy_r_r206, cpy_r_r207);
    if (unlikely(cpy_r_r208 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 207, CPyStatic_globals);
        goto CPyL123;
    }
    CPy_INCREF(cpy_r_r205);
    cpy_r_r209.f0 = cpy_r_r205;
    cpy_r_r209.f1 = cpy_r_r208;
    cpy_r_r210 = CPyStatics[37]; /* 'pressure' */
    cpy_r_r211 = CPyModule_numpy;
    cpy_r_r212 = CPyStatics[23]; /* 'float32' */
    cpy_r_r213 = CPyObject_GetAttr(cpy_r_r211, cpy_r_r212);
    if (unlikely(cpy_r_r213 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 208, CPyStatic_globals);
        goto CPyL124;
    }
    CPy_INCREF(cpy_r_r210);
    cpy_r_r214.f0 = cpy_r_r210;
    cpy_r_r214.f1 = cpy_r_r213;
    cpy_r_r215 = PyTuple_New(2);
    if (unlikely(cpy_r_r215 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp28 = cpy_r_r164.f0;
    PyTuple_SET_ITEM(cpy_r_r215, 0, __tmp28);
    PyObject *__tmp29 = cpy_r_r164.f1;
    PyTuple_SET_ITEM(cpy_r_r215, 1, __tmp29);
    cpy_r_r216 = PyTuple_New(2);
    if (unlikely(cpy_r_r216 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp30 = cpy_r_r169.f0;
    PyTuple_SET_ITEM(cpy_r_r216, 0, __tmp30);
    PyObject *__tmp31 = cpy_r_r169.f1;
    PyTuple_SET_ITEM(cpy_r_r216, 1, __tmp31);
    cpy_r_r217 = PyTuple_New(2);
    if (unlikely(cpy_r_r217 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp32 = cpy_r_r174.f0;
    PyTuple_SET_ITEM(cpy_r_r217, 0, __tmp32);
    PyObject *__tmp33 = cpy_r_r174.f1;
    PyTuple_SET_ITEM(cpy_r_r217, 1, __tmp33);
    cpy_r_r218 = PyTuple_New(2);
    if (unlikely(cpy_r_r218 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp34 = cpy_r_r179.f0;
    PyTuple_SET_ITEM(cpy_r_r218, 0, __tmp34);
    PyObject *__tmp35 = cpy_r_r179.f1;
    PyTuple_SET_ITEM(cpy_r_r218, 1, __tmp35);
    cpy_r_r219 = PyTuple_New(2);
    if (unlikely(cpy_r_r219 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp36 = cpy_r_r184.f0;
    PyTuple_SET_ITEM(cpy_r_r219, 0, __tmp36);
    PyObject *__tmp37 = cpy_r_r184.f1;
    PyTuple_SET_ITEM(cpy_r_r219, 1, __tmp37);
    cpy_r_r220 = PyTuple_New(2);
    if (unlikely(cpy_r_r220 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp38 = cpy_r_r189.f0;
    PyTuple_SET_ITEM(cpy_r_r220, 0, __tmp38);
    PyObject *__tmp39 = cpy_r_r189.f1;
    PyTuple_SET_ITEM(cpy_r_r220, 1, __tmp39);
    cpy_r_r221 = PyTuple_New(2);
    if (unlikely(cpy_r_r221 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp40 = cpy_r_r194.f0;
    PyTuple_SET_ITEM(cpy_r_r221, 0, __tmp40);
    PyObject *__tmp41 = cpy_r_r194.f1;
    PyTuple_SET_ITEM(cpy_r_r221, 1, __tmp41);
    cpy_r_r222 = PyTuple_New(2);
    if (unlikely(cpy_r_r222 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp42 = cpy_r_r199.f0;
    PyTuple_SET_ITEM(cpy_r_r222, 0, __tmp42);
    PyObject *__tmp43 = cpy_r_r199.f1;
    PyTuple_SET_ITEM(cpy_r_r222, 1, __tmp43);
    cpy_r_r223 = PyTuple_New(2);
    if (unlikely(cpy_r_r223 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp44 = cpy_r_r204.f0;
    PyTuple_SET_ITEM(cpy_r_r223, 0, __tmp44);
    PyObject *__tmp45 = cpy_r_r204.f1;
    PyTuple_SET_ITEM(cpy_r_r223, 1, __tmp45);
    cpy_r_r224 = PyTuple_New(2);
    if (unlikely(cpy_r_r224 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp46 = cpy_r_r209.f0;
    PyTuple_SET_ITEM(cpy_r_r224, 0, __tmp46);
    PyObject *__tmp47 = cpy_r_r209.f1;
    PyTuple_SET_ITEM(cpy_r_r224, 1, __tmp47);
    cpy_r_r225 = PyTuple_New(2);
    if (unlikely(cpy_r_r225 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp48 = cpy_r_r214.f0;
    PyTuple_SET_ITEM(cpy_r_r225, 0, __tmp48);
    PyObject *__tmp49 = cpy_r_r214.f1;
    PyTuple_SET_ITEM(cpy_r_r225, 1, __tmp49);
    cpy_r_r226 = CPyList_Build(11, cpy_r_r215, cpy_r_r216, cpy_r_r217, cpy_r_r218, cpy_r_r219, cpy_r_r220, cpy_r_r221, cpy_r_r222, cpy_r_r223, cpy_r_r224, cpy_r_r225);
    if (unlikely(cpy_r_r226 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 197, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r227 = CPyModule_numpy;
    cpy_r_r228 = CPyStatics[38]; /* 'array' */
    cpy_r_r229 = CPyObject_GetAttr(cpy_r_r227, cpy_r_r228);
    if (unlikely(cpy_r_r229 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 195, CPyStatic_globals);
        goto CPyL125;
    }
    PyObject *cpy_r_r230[2] = {cpy_r_r4, cpy_r_r226};
    cpy_r_r231 = (PyObject **)&cpy_r_r230;
    cpy_r_r232 = CPyStatics[199]; /* ('dtype',) */
    cpy_r_r233 = PyObject_Vectorcall(cpy_r_r229, cpy_r_r231, 1, cpy_r_r232);
    CPy_DECREF(cpy_r_r229);
    if (unlikely(cpy_r_r233 == NULL)) {
        CPy_AddTraceback("simplified.py", "export_cell_data", 195, CPyStatic_globals);
        goto CPyL125;
    }
    CPy_DECREF_NO_IMM(cpy_r_r4);
    CPy_DECREF_NO_IMM(cpy_r_r226);
    return cpy_r_r233;
CPyL95: ;
    cpy_r_r234 = NULL;
    return cpy_r_r234;
CPyL96: ;
    CPyTagged_DecRef(cpy_r_r3);
    goto CPyL95;
CPyL97: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL95;
CPyL98: ;
    CPyTagged_DECREF(cpy_r_r3);
    CPyTagged_DECREF(cpy_r_r9);
    CPyTagged_DECREF(cpy_r_r10);
    goto CPyL80;
CPyL99: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL95;
CPyL100: ;
    CPyTagged_DECREF(cpy_r_i);
    CPyTagged_DECREF(cpy_r_r21);
    CPyTagged_DECREF(cpy_r_r22);
    goto CPyL79;
CPyL101: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r30);
    goto CPyL95;
CPyL102: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r35);
    goto CPyL95;
CPyL103: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r46);
    goto CPyL95;
CPyL104: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r58);
    goto CPyL95;
CPyL105: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r69);
    goto CPyL95;
CPyL106: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r81);
    goto CPyL95;
CPyL107: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r93);
    goto CPyL95;
CPyL108: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r105);
    goto CPyL95;
CPyL109: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r119);
    goto CPyL95;
CPyL110: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r122);
    goto CPyL95;
CPyL111: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r134);
    goto CPyL95;
CPyL112: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r146);
    goto CPyL95;
CPyL113: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r9);
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r21);
    CPyTagged_DecRef(cpy_r_r22);
    goto CPyL95;
CPyL114: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL95;
CPyL115: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r164.f0);
    CPy_DecRef(cpy_r_r164.f1);
    goto CPyL95;
CPyL116: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r164.f0);
    CPy_DecRef(cpy_r_r164.f1);
    CPy_DecRef(cpy_r_r169.f0);
    CPy_DecRef(cpy_r_r169.f1);
    goto CPyL95;
CPyL117: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r164.f0);
    CPy_DecRef(cpy_r_r164.f1);
    CPy_DecRef(cpy_r_r169.f0);
    CPy_DecRef(cpy_r_r169.f1);
    CPy_DecRef(cpy_r_r174.f0);
    CPy_DecRef(cpy_r_r174.f1);
    goto CPyL95;
CPyL118: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r164.f0);
    CPy_DecRef(cpy_r_r164.f1);
    CPy_DecRef(cpy_r_r169.f0);
    CPy_DecRef(cpy_r_r169.f1);
    CPy_DecRef(cpy_r_r174.f0);
    CPy_DecRef(cpy_r_r174.f1);
    CPy_DecRef(cpy_r_r179.f0);
    CPy_DecRef(cpy_r_r179.f1);
    goto CPyL95;
CPyL119: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r164.f0);
    CPy_DecRef(cpy_r_r164.f1);
    CPy_DecRef(cpy_r_r169.f0);
    CPy_DecRef(cpy_r_r169.f1);
    CPy_DecRef(cpy_r_r174.f0);
    CPy_DecRef(cpy_r_r174.f1);
    CPy_DecRef(cpy_r_r179.f0);
    CPy_DecRef(cpy_r_r179.f1);
    CPy_DecRef(cpy_r_r184.f0);
    CPy_DecRef(cpy_r_r184.f1);
    goto CPyL95;
CPyL120: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r164.f0);
    CPy_DecRef(cpy_r_r164.f1);
    CPy_DecRef(cpy_r_r169.f0);
    CPy_DecRef(cpy_r_r169.f1);
    CPy_DecRef(cpy_r_r174.f0);
    CPy_DecRef(cpy_r_r174.f1);
    CPy_DecRef(cpy_r_r179.f0);
    CPy_DecRef(cpy_r_r179.f1);
    CPy_DecRef(cpy_r_r184.f0);
    CPy_DecRef(cpy_r_r184.f1);
    CPy_DecRef(cpy_r_r189.f0);
    CPy_DecRef(cpy_r_r189.f1);
    goto CPyL95;
CPyL121: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r164.f0);
    CPy_DecRef(cpy_r_r164.f1);
    CPy_DecRef(cpy_r_r169.f0);
    CPy_DecRef(cpy_r_r169.f1);
    CPy_DecRef(cpy_r_r174.f0);
    CPy_DecRef(cpy_r_r174.f1);
    CPy_DecRef(cpy_r_r179.f0);
    CPy_DecRef(cpy_r_r179.f1);
    CPy_DecRef(cpy_r_r184.f0);
    CPy_DecRef(cpy_r_r184.f1);
    CPy_DecRef(cpy_r_r189.f0);
    CPy_DecRef(cpy_r_r189.f1);
    CPy_DecRef(cpy_r_r194.f0);
    CPy_DecRef(cpy_r_r194.f1);
    goto CPyL95;
CPyL122: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r164.f0);
    CPy_DecRef(cpy_r_r164.f1);
    CPy_DecRef(cpy_r_r169.f0);
    CPy_DecRef(cpy_r_r169.f1);
    CPy_DecRef(cpy_r_r174.f0);
    CPy_DecRef(cpy_r_r174.f1);
    CPy_DecRef(cpy_r_r179.f0);
    CPy_DecRef(cpy_r_r179.f1);
    CPy_DecRef(cpy_r_r184.f0);
    CPy_DecRef(cpy_r_r184.f1);
    CPy_DecRef(cpy_r_r189.f0);
    CPy_DecRef(cpy_r_r189.f1);
    CPy_DecRef(cpy_r_r194.f0);
    CPy_DecRef(cpy_r_r194.f1);
    CPy_DecRef(cpy_r_r199.f0);
    CPy_DecRef(cpy_r_r199.f1);
    goto CPyL95;
CPyL123: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r164.f0);
    CPy_DecRef(cpy_r_r164.f1);
    CPy_DecRef(cpy_r_r169.f0);
    CPy_DecRef(cpy_r_r169.f1);
    CPy_DecRef(cpy_r_r174.f0);
    CPy_DecRef(cpy_r_r174.f1);
    CPy_DecRef(cpy_r_r179.f0);
    CPy_DecRef(cpy_r_r179.f1);
    CPy_DecRef(cpy_r_r184.f0);
    CPy_DecRef(cpy_r_r184.f1);
    CPy_DecRef(cpy_r_r189.f0);
    CPy_DecRef(cpy_r_r189.f1);
    CPy_DecRef(cpy_r_r194.f0);
    CPy_DecRef(cpy_r_r194.f1);
    CPy_DecRef(cpy_r_r199.f0);
    CPy_DecRef(cpy_r_r199.f1);
    CPy_DecRef(cpy_r_r204.f0);
    CPy_DecRef(cpy_r_r204.f1);
    goto CPyL95;
CPyL124: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r164.f0);
    CPy_DecRef(cpy_r_r164.f1);
    CPy_DecRef(cpy_r_r169.f0);
    CPy_DecRef(cpy_r_r169.f1);
    CPy_DecRef(cpy_r_r174.f0);
    CPy_DecRef(cpy_r_r174.f1);
    CPy_DecRef(cpy_r_r179.f0);
    CPy_DecRef(cpy_r_r179.f1);
    CPy_DecRef(cpy_r_r184.f0);
    CPy_DecRef(cpy_r_r184.f1);
    CPy_DecRef(cpy_r_r189.f0);
    CPy_DecRef(cpy_r_r189.f1);
    CPy_DecRef(cpy_r_r194.f0);
    CPy_DecRef(cpy_r_r194.f1);
    CPy_DecRef(cpy_r_r199.f0);
    CPy_DecRef(cpy_r_r199.f1);
    CPy_DecRef(cpy_r_r204.f0);
    CPy_DecRef(cpy_r_r204.f1);
    CPy_DecRef(cpy_r_r209.f0);
    CPy_DecRef(cpy_r_r209.f1);
    goto CPyL95;
CPyL125: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r226);
    goto CPyL95;
}
    
    PyObject *CPyPy_HeadlessWindTunnel___export_cell_data(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        PyObject *obj_self = self;
        static const char * const kwlist[] = {0};
        static CPyArg_Parser parser = {":export_cell_data", kwlist, 0};
        if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
            return NULL;
        }
        PyObject *arg_self;
        if (likely(Py_TYPE(obj_self) == CPyType_HeadlessWindTunnel))
            arg_self = obj_self;
        else {
            CPy_TypeError("simplified.HeadlessWindTunnel", obj_self); 
            goto fail;
        }
        PyObject *retval = CPyDef_HeadlessWindTunnel___export_cell_data(arg_self);
        return retval;
fail: ;
        CPy_AddTraceback("simplified.py", "export_cell_data", 170, CPyStatic_globals);
        return NULL;
    }
    
char CPyDef_save_cell_csv(PyObject *cpy_r_path, PyObject *cpy_r_cell_data) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject **cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    char cpy_r_r40;
    cpy_r_r0 = CPyStatics[39]; /* 'cell_id,i,j,s,u_face,v_face,u_center,v_center,speed,smoke,pressure' */
    CPy_INCREF(cpy_r_r0);
    cpy_r_r1 = CPyStatics[27]; /* 'cell_id' */
    cpy_r_r2 = PyObject_GetItem(cpy_r_cell_data, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 217, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r3 = CPyStatics[29]; /* 'i' */
    cpy_r_r4 = PyObject_GetItem(cpy_r_cell_data, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 218, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r5 = CPyStatics[30]; /* 'j' */
    cpy_r_r6 = PyObject_GetItem(cpy_r_cell_data, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 219, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r7 = CPyStatics[5]; /* 's' */
    cpy_r_r8 = PyObject_GetItem(cpy_r_cell_data, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 220, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r9 = CPyStatics[31]; /* 'u_face' */
    cpy_r_r10 = PyObject_GetItem(cpy_r_cell_data, cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 221, CPyStatic_globals);
        goto CPyL22;
    }
    cpy_r_r11 = CPyStatics[32]; /* 'v_face' */
    cpy_r_r12 = PyObject_GetItem(cpy_r_cell_data, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 222, CPyStatic_globals);
        goto CPyL23;
    }
    cpy_r_r13 = CPyStatics[33]; /* 'u_center' */
    cpy_r_r14 = PyObject_GetItem(cpy_r_cell_data, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 223, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r15 = CPyStatics[34]; /* 'v_center' */
    cpy_r_r16 = PyObject_GetItem(cpy_r_cell_data, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 224, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r17 = CPyStatics[35]; /* 'speed' */
    cpy_r_r18 = PyObject_GetItem(cpy_r_cell_data, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 225, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r19 = CPyStatics[36]; /* 'smoke' */
    cpy_r_r20 = PyObject_GetItem(cpy_r_cell_data, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 226, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r21 = CPyStatics[37]; /* 'pressure' */
    cpy_r_r22 = PyObject_GetItem(cpy_r_cell_data, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 227, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r23 = CPyList_Build(11, cpy_r_r2, cpy_r_r4, cpy_r_r6, cpy_r_r8, cpy_r_r10, cpy_r_r12, cpy_r_r14, cpy_r_r16, cpy_r_r18, cpy_r_r20, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 216, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r24 = CPyModule_numpy;
    cpy_r_r25 = CPyStatics[40]; /* 'column_stack' */
    cpy_r_r26 = CPyObject_GetAttr(cpy_r_r24, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 215, CPyStatic_globals);
        goto CPyL29;
    }
    PyObject *cpy_r_r27[1] = {cpy_r_r23};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = PyObject_Vectorcall(cpy_r_r26, cpy_r_r28, 1, 0);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 215, CPyStatic_globals);
        goto CPyL29;
    }
    CPy_DECREF_NO_IMM(cpy_r_r23);
    cpy_r_r30 = CPyStatics[41]; /* ',' */
    cpy_r_r31 = CPyStatics[42]; /* '' */
    cpy_r_r32 = CPyStatics[43]; /* '%.6f' */
    cpy_r_r33 = CPyModule_numpy;
    cpy_r_r34 = CPyStatics[44]; /* 'savetxt' */
    cpy_r_r35 = CPyObject_GetAttr(cpy_r_r33, cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 230, CPyStatic_globals);
        goto CPyL30;
    }
    PyObject *cpy_r_r36[6] = {
        cpy_r_path, cpy_r_r29, cpy_r_r30, cpy_r_r0, cpy_r_r31,
        cpy_r_r32
    };
    cpy_r_r37 = (PyObject **)&cpy_r_r36;
    cpy_r_r38 = CPyStatics[200]; /* ('delimiter', 'header', 'comments', 'fmt') */
    cpy_r_r39 = PyObject_Vectorcall(cpy_r_r35, cpy_r_r37, 2, cpy_r_r38);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_cell_csv", 230, CPyStatic_globals);
        goto CPyL30;
    } else
        goto CPyL31;
CPyL16: ;
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r0);
    return 1;
CPyL17: ;
    cpy_r_r40 = 2;
    return cpy_r_r40;
CPyL18: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL17;
CPyL19: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    goto CPyL17;
CPyL20: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r4);
    goto CPyL17;
CPyL21: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r6);
    goto CPyL17;
CPyL22: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r8);
    goto CPyL17;
CPyL23: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r10);
    goto CPyL17;
CPyL24: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r12);
    goto CPyL17;
CPyL25: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r14);
    goto CPyL17;
CPyL26: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r16);
    goto CPyL17;
CPyL27: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r18);
    goto CPyL17;
CPyL28: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_r20);
    goto CPyL17;
CPyL29: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r23);
    goto CPyL17;
CPyL30: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r29);
    goto CPyL17;
CPyL31: ;
    CPy_DECREF(cpy_r_r39);
    goto CPyL16;
}
    
    PyObject *CPyPy_save_cell_csv(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        static const char * const kwlist[] = {"path", "cell_data", 0};
        static CPyArg_Parser parser = {"OO:save_cell_csv", kwlist, 0};
        PyObject *obj_path;
        PyObject *obj_cell_data;
        if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_path, &obj_cell_data)) {
            return NULL;
        }
        PyObject *arg_path = obj_path;
        PyObject *arg_cell_data = obj_cell_data;
        char retval = CPyDef_save_cell_csv(arg_path, arg_cell_data);
        if (retval == 2) {
            return NULL;
        }
        PyObject *retbox = Py_None;
        CPy_INCREF(retbox);
        return retbox;
fail: ;
        CPy_AddTraceback("simplified.py", "save_cell_csv", 213, CPyStatic_globals);
        return NULL;
    }
    
char CPyDef_save_field_plot(PyObject *cpy_r_path, PyObject *cpy_r_speed, PyObject *cpy_r_smoke, PyObject *cpy_r_pressure, PyObject *cpy_r_solid) {
    tuple_T2II cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    tuple_T2OO cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    tuple_T3OOO cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    tuple_T3OOO cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    tuple_T3OOO cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    tuple_T3OOO cpy_r_r28;
    tuple_T4T3OOOT3OOOT3OOOT3OOO cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject **cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    tuple_T3OOO cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject **cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject **cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject **cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject **cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    char cpy_r_r70;
    char cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject **cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject **cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject **cpy_r_r87;
    PyObject *cpy_r_r88;
    char cpy_r_r89;
    cpy_r_r0.f0 = 24;
    cpy_r_r0.f1 = 16;
    cpy_r_r1 = CPyModule_matplotlib___pyplot;
    cpy_r_r2 = CPyStatics[49]; /* 'subplots' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 240, CPyStatic_globals);
        goto CPyL23;
    }
    cpy_r_r4 = CPyStatics[190]; /* 2 */
    cpy_r_r5 = CPyStatics[190]; /* 2 */
    cpy_r_r6 = PyTuple_New(2);
    if (unlikely(cpy_r_r6 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp50 = CPyTagged_StealAsObject(cpy_r_r0.f0);
    PyTuple_SET_ITEM(cpy_r_r6, 0, __tmp50);
    PyObject *__tmp51 = CPyTagged_StealAsObject(cpy_r_r0.f1);
    PyTuple_SET_ITEM(cpy_r_r6, 1, __tmp51);
    cpy_r_r7 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r8[4] = {cpy_r_r4, cpy_r_r5, cpy_r_r6, cpy_r_r7};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[201]; /* ('figsize', 'constrained_layout') */
    cpy_r_r11 = PyObject_Vectorcall(cpy_r_r3, cpy_r_r9, 2, cpy_r_r10);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 240, CPyStatic_globals);
        goto CPyL24;
    }
    CPy_DECREF(cpy_r_r6);
    PyObject *__tmp52;
    if (unlikely(!(PyTuple_Check(cpy_r_r11) && PyTuple_GET_SIZE(cpy_r_r11) == 2))) {
        __tmp52 = NULL;
        goto __LL53;
    }
    __tmp52 = PyTuple_GET_ITEM(cpy_r_r11, 0);
    if (__tmp52 == NULL) goto __LL53;
    __tmp52 = PyTuple_GET_ITEM(cpy_r_r11, 1);
    if (__tmp52 == NULL) goto __LL53;
    __tmp52 = cpy_r_r11;
__LL53: ;
    if (unlikely(__tmp52 == NULL)) {
        CPy_TypeError("tuple[object, object]", cpy_r_r11); cpy_r_r12 = (tuple_T2OO) { NULL, NULL };
    } else {
        PyObject *__tmp54 = PyTuple_GET_ITEM(cpy_r_r11, 0);
        CPy_INCREF(__tmp54);
        PyObject *__tmp55;
        __tmp55 = __tmp54;
        cpy_r_r12.f0 = __tmp55;
        PyObject *__tmp56 = PyTuple_GET_ITEM(cpy_r_r11, 1);
        CPy_INCREF(__tmp56);
        PyObject *__tmp57;
        __tmp57 = __tmp56;
        cpy_r_r12.f1 = __tmp57;
    }
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r12.f0 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 240, CPyStatic_globals);
        goto CPyL22;
    }
    cpy_r_r13 = cpy_r_r12.f0;
    cpy_r_r14 = cpy_r_r12.f1;
    cpy_r_r15 = cpy_r_r13;
    cpy_r_r16 = cpy_r_r14;
    cpy_r_r17 = CPyStatics[52]; /* 'Smoke' */
    cpy_r_r18 = CPyStatics[53]; /* 'gray' */
    CPy_INCREF(cpy_r_smoke);
    CPy_INCREF(cpy_r_r17);
    CPy_INCREF(cpy_r_r18);
    cpy_r_r19.f0 = cpy_r_smoke;
    cpy_r_r19.f1 = cpy_r_r17;
    cpy_r_r19.f2 = cpy_r_r18;
    cpy_r_r20 = CPyStatics[54]; /* 'Speed Magnitude' */
    cpy_r_r21 = CPyStatics[55]; /* 'viridis' */
    CPy_INCREF(cpy_r_speed);
    CPy_INCREF(cpy_r_r20);
    CPy_INCREF(cpy_r_r21);
    cpy_r_r22.f0 = cpy_r_speed;
    cpy_r_r22.f1 = cpy_r_r20;
    cpy_r_r22.f2 = cpy_r_r21;
    cpy_r_r23 = CPyStatics[56]; /* 'Pressure' */
    cpy_r_r24 = CPyStatics[57]; /* 'coolwarm' */
    CPy_INCREF(cpy_r_pressure);
    CPy_INCREF(cpy_r_r23);
    CPy_INCREF(cpy_r_r24);
    cpy_r_r25.f0 = cpy_r_pressure;
    cpy_r_r25.f1 = cpy_r_r23;
    cpy_r_r25.f2 = cpy_r_r24;
    cpy_r_r26 = CPyStatics[58]; /* 'Solid Mask' */
    cpy_r_r27 = CPyStatics[59]; /* 'binary' */
    CPy_INCREF(cpy_r_solid);
    CPy_INCREF(cpy_r_r26);
    CPy_INCREF(cpy_r_r27);
    cpy_r_r28.f0 = cpy_r_solid;
    cpy_r_r28.f1 = cpy_r_r26;
    cpy_r_r28.f2 = cpy_r_r27;
    cpy_r_r29.f0 = cpy_r_r19;
    cpy_r_r29.f1 = cpy_r_r22;
    cpy_r_r29.f2 = cpy_r_r25;
    cpy_r_r29.f3 = cpy_r_r28;
    cpy_r_r30 = PyTuple_New(4);
    if (unlikely(cpy_r_r30 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp58 = PyTuple_New(3);
    if (unlikely(__tmp58 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp59 = cpy_r_r29.f0.f0;
    PyTuple_SET_ITEM(__tmp58, 0, __tmp59);
    PyObject *__tmp60 = cpy_r_r29.f0.f1;
    PyTuple_SET_ITEM(__tmp58, 1, __tmp60);
    PyObject *__tmp61 = cpy_r_r29.f0.f2;
    PyTuple_SET_ITEM(__tmp58, 2, __tmp61);
    PyTuple_SET_ITEM(cpy_r_r30, 0, __tmp58);
    PyObject *__tmp62 = PyTuple_New(3);
    if (unlikely(__tmp62 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp63 = cpy_r_r29.f1.f0;
    PyTuple_SET_ITEM(__tmp62, 0, __tmp63);
    PyObject *__tmp64 = cpy_r_r29.f1.f1;
    PyTuple_SET_ITEM(__tmp62, 1, __tmp64);
    PyObject *__tmp65 = cpy_r_r29.f1.f2;
    PyTuple_SET_ITEM(__tmp62, 2, __tmp65);
    PyTuple_SET_ITEM(cpy_r_r30, 1, __tmp62);
    PyObject *__tmp66 = PyTuple_New(3);
    if (unlikely(__tmp66 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp67 = cpy_r_r29.f2.f0;
    PyTuple_SET_ITEM(__tmp66, 0, __tmp67);
    PyObject *__tmp68 = cpy_r_r29.f2.f1;
    PyTuple_SET_ITEM(__tmp66, 1, __tmp68);
    PyObject *__tmp69 = cpy_r_r29.f2.f2;
    PyTuple_SET_ITEM(__tmp66, 2, __tmp69);
    PyTuple_SET_ITEM(cpy_r_r30, 2, __tmp66);
    PyObject *__tmp70 = PyTuple_New(3);
    if (unlikely(__tmp70 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp71 = cpy_r_r29.f3.f0;
    PyTuple_SET_ITEM(__tmp70, 0, __tmp71);
    PyObject *__tmp72 = cpy_r_r29.f3.f1;
    PyTuple_SET_ITEM(__tmp70, 1, __tmp72);
    PyObject *__tmp73 = cpy_r_r29.f3.f2;
    PyTuple_SET_ITEM(__tmp70, 2, __tmp73);
    PyTuple_SET_ITEM(cpy_r_r30, 3, __tmp70);
    cpy_r_r31 = CPyStatics[60]; /* 'ravel' */
    PyObject *cpy_r_r32[1] = {cpy_r_r16};
    cpy_r_r33 = (PyObject **)&cpy_r_r32;
    cpy_r_r34 = PyObject_VectorcallMethod(cpy_r_r31, cpy_r_r33, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 248, CPyStatic_globals);
        goto CPyL25;
    }
    CPy_DECREF(cpy_r_r16);
    cpy_r_r35 = PyObject_GetIter(cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 248, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r36 = PyObject_GetIter(cpy_r_r30);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 248, CPyStatic_globals);
        goto CPyL27;
    }
CPyL6: ;
    cpy_r_r37 = PyIter_Next(cpy_r_r35);
    if (cpy_r_r37 == NULL) goto CPyL28;
    cpy_r_r38 = PyIter_Next(cpy_r_r36);
    if (cpy_r_r38 == NULL) goto CPyL29;
    PyObject *__tmp74;
    if (unlikely(!(PyTuple_Check(cpy_r_r38) && PyTuple_GET_SIZE(cpy_r_r38) == 3))) {
        __tmp74 = NULL;
        goto __LL75;
    }
    __tmp74 = PyTuple_GET_ITEM(cpy_r_r38, 0);
    if (__tmp74 == NULL) goto __LL75;
    if (likely(PyUnicode_Check(PyTuple_GET_ITEM(cpy_r_r38, 1))))
        __tmp74 = PyTuple_GET_ITEM(cpy_r_r38, 1);
    else {
        __tmp74 = NULL;
    }
    if (__tmp74 == NULL) goto __LL75;
    if (likely(PyUnicode_Check(PyTuple_GET_ITEM(cpy_r_r38, 2))))
        __tmp74 = PyTuple_GET_ITEM(cpy_r_r38, 2);
    else {
        __tmp74 = NULL;
    }
    if (__tmp74 == NULL) goto __LL75;
    __tmp74 = cpy_r_r38;
__LL75: ;
    if (unlikely(__tmp74 == NULL)) {
        CPy_TypeError("tuple[object, str, str]", cpy_r_r38); cpy_r_r39 = (tuple_T3OOO) { NULL, NULL, NULL };
    } else {
        PyObject *__tmp76 = PyTuple_GET_ITEM(cpy_r_r38, 0);
        CPy_INCREF(__tmp76);
        PyObject *__tmp77;
        __tmp77 = __tmp76;
        cpy_r_r39.f0 = __tmp77;
        PyObject *__tmp78 = PyTuple_GET_ITEM(cpy_r_r38, 1);
        CPy_INCREF(__tmp78);
        PyObject *__tmp79;
        if (likely(PyUnicode_Check(__tmp78)))
            __tmp79 = __tmp78;
        else {
            CPy_TypeError("str", __tmp78); 
            __tmp79 = NULL;
        }
        cpy_r_r39.f1 = __tmp79;
        PyObject *__tmp80 = PyTuple_GET_ITEM(cpy_r_r38, 2);
        CPy_INCREF(__tmp80);
        PyObject *__tmp81;
        if (likely(PyUnicode_Check(__tmp80)))
            __tmp81 = __tmp80;
        else {
            CPy_TypeError("str", __tmp80); 
            __tmp81 = NULL;
        }
        cpy_r_r39.f2 = __tmp81;
    }
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r39.f0 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 248, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r40 = cpy_r_r39.f0;
    CPy_INCREF(cpy_r_r40);
    cpy_r_r41 = cpy_r_r39.f1;
    CPy_INCREF(cpy_r_r41);
    cpy_r_r42 = cpy_r_r39.f2;
    CPy_INCREF(cpy_r_r42);
    CPy_DECREF(cpy_r_r39.f0);
    CPy_DECREF(cpy_r_r39.f1);
    CPy_DECREF(cpy_r_r39.f2);
    cpy_r_r43 = CPyStatics[61]; /* 'lower' */
    cpy_r_r44 = CPyStatics[62]; /* 'auto' */
    cpy_r_r45 = CPyStatics[63]; /* 'imshow' */
    PyObject *cpy_r_r46[5] = {cpy_r_r37, cpy_r_r40, cpy_r_r43, cpy_r_r42, cpy_r_r44};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = CPyStatics[202]; /* ('origin', 'cmap', 'aspect') */
    cpy_r_r49 = PyObject_VectorcallMethod(cpy_r_r45, cpy_r_r47, 9223372036854775810ULL, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 249, CPyStatic_globals);
        goto CPyL31;
    }
    CPy_DECREF(cpy_r_r40);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r50 = CPyStatics[67]; /* 'set_title' */
    PyObject *cpy_r_r51[2] = {cpy_r_r37, cpy_r_r41};
    cpy_r_r52 = (PyObject **)&cpy_r_r51;
    cpy_r_r53 = PyObject_VectorcallMethod(cpy_r_r50, cpy_r_r52, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 250, CPyStatic_globals);
        goto CPyL32;
    } else
        goto CPyL33;
CPyL11: ;
    CPy_DECREF(cpy_r_r41);
    cpy_r_r54 = CPyStatics[29]; /* 'i' */
    cpy_r_r55 = CPyStatics[68]; /* 'set_xlabel' */
    PyObject *cpy_r_r56[2] = {cpy_r_r37, cpy_r_r54};
    cpy_r_r57 = (PyObject **)&cpy_r_r56;
    cpy_r_r58 = PyObject_VectorcallMethod(cpy_r_r55, cpy_r_r57, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 251, CPyStatic_globals);
        goto CPyL34;
    } else
        goto CPyL35;
CPyL12: ;
    cpy_r_r59 = CPyStatics[30]; /* 'j' */
    cpy_r_r60 = CPyStatics[69]; /* 'set_ylabel' */
    PyObject *cpy_r_r61[2] = {cpy_r_r37, cpy_r_r59};
    cpy_r_r62 = (PyObject **)&cpy_r_r61;
    cpy_r_r63 = PyObject_VectorcallMethod(cpy_r_r60, cpy_r_r62, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 252, CPyStatic_globals);
        goto CPyL34;
    } else
        goto CPyL36;
CPyL13: ;
    cpy_r_r64 = CPyStatics[70]; /* 'colorbar' */
    cpy_r_r65 = PyFloat_FromDouble(0.85);
    PyObject *cpy_r_r66[4] = {cpy_r_r15, cpy_r_r49, cpy_r_r37, cpy_r_r65};
    cpy_r_r67 = (PyObject **)&cpy_r_r66;
    cpy_r_r68 = CPyStatics[203]; /* ('ax', 'shrink') */
    cpy_r_r69 = PyObject_VectorcallMethod(cpy_r_r64, cpy_r_r67, 9223372036854775810ULL, cpy_r_r68);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 253, CPyStatic_globals);
        goto CPyL37;
    } else
        goto CPyL38;
CPyL14: ;
    CPy_DECREF(cpy_r_r49);
    CPy_DECREF(cpy_r_r37);
    CPy_DECREF(cpy_r_r65);
    goto CPyL6;
CPyL15: ;
    cpy_r_r70 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r70)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 248, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r71 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r71)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 248, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r72 = CPyStatics[73]; /* 'Airfoil Flow Report' */
    cpy_r_r73 = CPyStatics[74]; /* 'suptitle' */
    PyObject *cpy_r_r74[2] = {cpy_r_r15, cpy_r_r72};
    cpy_r_r75 = (PyObject **)&cpy_r_r74;
    cpy_r_r76 = PyObject_VectorcallMethod(cpy_r_r73, cpy_r_r75, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 255, CPyStatic_globals);
        goto CPyL39;
    } else
        goto CPyL40;
CPyL18: ;
    cpy_r_r77 = CPyStatics[75]; /* 'savefig' */
    cpy_r_r78 = CPyStatics[191]; /* 180 */
    PyObject *cpy_r_r79[3] = {cpy_r_r15, cpy_r_path, cpy_r_r78};
    cpy_r_r80 = (PyObject **)&cpy_r_r79;
    cpy_r_r81 = CPyStatics[204]; /* ('dpi',) */
    cpy_r_r82 = PyObject_VectorcallMethod(cpy_r_r77, cpy_r_r80, 9223372036854775810ULL, cpy_r_r81);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 256, CPyStatic_globals);
        goto CPyL39;
    } else
        goto CPyL41;
CPyL19: ;
    cpy_r_r83 = CPyModule_matplotlib___pyplot;
    cpy_r_r84 = CPyStatics[77]; /* 'close' */
    cpy_r_r85 = CPyObject_GetAttr(cpy_r_r83, cpy_r_r84);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 257, CPyStatic_globals);
        goto CPyL39;
    }
    PyObject *cpy_r_r86[1] = {cpy_r_r15};
    cpy_r_r87 = (PyObject **)&cpy_r_r86;
    cpy_r_r88 = PyObject_Vectorcall(cpy_r_r85, cpy_r_r87, 1, 0);
    CPy_DECREF(cpy_r_r85);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("simplified.py", "save_field_plot", 257, CPyStatic_globals);
        goto CPyL39;
    } else
        goto CPyL42;
CPyL21: ;
    CPy_DECREF(cpy_r_r15);
    return 1;
CPyL22: ;
    cpy_r_r89 = 2;
    return cpy_r_r89;
CPyL23: ;
    CPyTagged_DecRef(cpy_r_r0.f0);
    CPyTagged_DecRef(cpy_r_r0.f1);
    goto CPyL22;
CPyL24: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL22;
CPyL25: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r30);
    goto CPyL22;
CPyL26: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r30);
    goto CPyL22;
CPyL27: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r35);
    goto CPyL22;
CPyL28: ;
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r36);
    goto CPyL15;
CPyL29: ;
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_r37);
    goto CPyL15;
CPyL30: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r35);
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_r37);
    goto CPyL22;
CPyL31: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r35);
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_r37);
    CPy_DecRef(cpy_r_r40);
    CPy_DecRef(cpy_r_r41);
    CPy_DecRef(cpy_r_r42);
    goto CPyL22;
CPyL32: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r35);
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_r37);
    CPy_DecRef(cpy_r_r41);
    CPy_DecRef(cpy_r_r49);
    goto CPyL22;
CPyL33: ;
    CPy_DECREF(cpy_r_r53);
    goto CPyL11;
CPyL34: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r35);
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_r37);
    CPy_DecRef(cpy_r_r49);
    goto CPyL22;
CPyL35: ;
    CPy_DECREF(cpy_r_r58);
    goto CPyL12;
CPyL36: ;
    CPy_DECREF(cpy_r_r63);
    goto CPyL13;
CPyL37: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r35);
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_r37);
    CPy_DecRef(cpy_r_r49);
    CPy_DecRef(cpy_r_r65);
    goto CPyL22;
CPyL38: ;
    CPy_DECREF(cpy_r_r69);
    goto CPyL14;
CPyL39: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL22;
CPyL40: ;
    CPy_DECREF(cpy_r_r76);
    goto CPyL18;
CPyL41: ;
    CPy_DECREF(cpy_r_r82);
    goto CPyL19;
CPyL42: ;
    CPy_DECREF(cpy_r_r88);
    goto CPyL21;
}
    
    PyObject *CPyPy_save_field_plot(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        static const char * const kwlist[] = {"path", "speed", "smoke", "pressure", "solid", 0};
        static CPyArg_Parser parser = {"OOOOO:save_field_plot", kwlist, 0};
        PyObject *obj_path;
        PyObject *obj_speed;
        PyObject *obj_smoke;
        PyObject *obj_pressure;
        PyObject *obj_solid;
        if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_path, &obj_speed, &obj_smoke, &obj_pressure, &obj_solid)) {
            return NULL;
        }
        PyObject *arg_path = obj_path;
        PyObject *arg_speed = obj_speed;
        PyObject *arg_smoke = obj_smoke;
        PyObject *arg_pressure = obj_pressure;
        PyObject *arg_solid = obj_solid;
        char retval = CPyDef_save_field_plot(arg_path, arg_speed, arg_smoke, arg_pressure, arg_solid);
        if (retval == 2) {
            return NULL;
        }
        PyObject *retbox = Py_None;
        CPy_INCREF(retbox);
        return retbox;
fail: ;
        CPy_AddTraceback("simplified.py", "save_field_plot", 233, CPyStatic_globals);
        return NULL;
    }
    
PyObject *CPyDef_build_parser(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    tuple_T2OO cpy_r_r12;
    tuple_T2II cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject **cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject **cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject **cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject **cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject **cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject **cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject **cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject **cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject **cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject **cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject **cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject **cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject **cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    tuple_T2OO cpy_r_r122;
    tuple_T2FF cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject **cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject **cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    cpy_r_r0 = CPyStatics[78]; /* ('Run the airfoil simulation and export only the '
                                  'final-state results.') */
    cpy_r_r1 = CPyModule_argparse;
    cpy_r_r2 = CPyStatics[79]; /* 'ArgumentParser' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 261, CPyStatic_globals);
        goto CPyL18;
    }
    PyObject *cpy_r_r4[1] = {cpy_r_r0};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = CPyStatics[205]; /* ('description',) */
    cpy_r_r7 = PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 0, cpy_r_r6);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 261, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r8 = CPyStatics[81]; /* '--resolution' */
    cpy_r_r9 = (PyObject *)&PyLong_Type;
    cpy_r_r10 = CPyStatics[82]; /* 'NX' */
    cpy_r_r11 = CPyStatics[83]; /* 'NY' */
    CPy_INCREF(cpy_r_r10);
    CPy_INCREF(cpy_r_r11);
    cpy_r_r12.f0 = cpy_r_r10;
    cpy_r_r12.f1 = cpy_r_r11;
    cpy_r_r13.f0 = 400;
    cpy_r_r13.f1 = 200;
    cpy_r_r14 = CPyStatics[84]; /* 'add_argument' */
    cpy_r_r15 = CPyStatics[190]; /* 2 */
    cpy_r_r16 = PyTuple_New(2);
    if (unlikely(cpy_r_r16 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp82 = cpy_r_r12.f0;
    PyTuple_SET_ITEM(cpy_r_r16, 0, __tmp82);
    PyObject *__tmp83 = cpy_r_r12.f1;
    PyTuple_SET_ITEM(cpy_r_r16, 1, __tmp83);
    cpy_r_r17 = PyTuple_New(2);
    if (unlikely(cpy_r_r17 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp84 = CPyTagged_StealAsObject(cpy_r_r13.f0);
    PyTuple_SET_ITEM(cpy_r_r17, 0, __tmp84);
    PyObject *__tmp85 = CPyTagged_StealAsObject(cpy_r_r13.f1);
    PyTuple_SET_ITEM(cpy_r_r17, 1, __tmp85);
    PyObject *cpy_r_r18[6] = {cpy_r_r7, cpy_r_r8, cpy_r_r15, cpy_r_r9, cpy_r_r16, cpy_r_r17};
    cpy_r_r19 = (PyObject **)&cpy_r_r18;
    cpy_r_r20 = CPyStatics[206]; /* ('nargs', 'type', 'metavar', 'default') */
    cpy_r_r21 = PyObject_VectorcallMethod(cpy_r_r14, cpy_r_r19, 9223372036854775810ULL, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 264, CPyStatic_globals);
        goto CPyL19;
    } else
        goto CPyL20;
CPyL3: ;
    CPy_DECREF(cpy_r_r16);
    CPy_DECREF(cpy_r_r17);
    cpy_r_r22 = CPyStatics[89]; /* '--hardstep' */
    cpy_r_r23 = (PyObject *)&PyLong_Type;
    cpy_r_r24 = CPyStatics[84]; /* 'add_argument' */
    cpy_r_r25 = CPyStatics[192]; /* 400 */
    PyObject *cpy_r_r26[4] = {cpy_r_r7, cpy_r_r22, cpy_r_r23, cpy_r_r25};
    cpy_r_r27 = (PyObject **)&cpy_r_r26;
    cpy_r_r28 = CPyStatics[207]; /* ('type', 'default') */
    cpy_r_r29 = PyObject_VectorcallMethod(cpy_r_r24, cpy_r_r27, 9223372036854775810ULL, cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 265, CPyStatic_globals);
        goto CPyL21;
    } else
        goto CPyL22;
CPyL4: ;
    cpy_r_r30 = CPyStatics[90]; /* '--min-steps' */
    cpy_r_r31 = (PyObject *)&PyLong_Type;
    cpy_r_r32 = CPyStatics[84]; /* 'add_argument' */
    cpy_r_r33 = CPyStatics[193]; /* 100 */
    PyObject *cpy_r_r34[4] = {cpy_r_r7, cpy_r_r30, cpy_r_r31, cpy_r_r33};
    cpy_r_r35 = (PyObject **)&cpy_r_r34;
    cpy_r_r36 = CPyStatics[207]; /* ('type', 'default') */
    cpy_r_r37 = PyObject_VectorcallMethod(cpy_r_r32, cpy_r_r35, 9223372036854775810ULL, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 266, CPyStatic_globals);
        goto CPyL21;
    } else
        goto CPyL23;
CPyL5: ;
    cpy_r_r38 = CPyStatics[91]; /* '--steady-tol' */
    cpy_r_r39 = (PyObject *)&PyFloat_Type;
    cpy_r_r40 = CPyStatics[84]; /* 'add_argument' */
    cpy_r_r41 = PyFloat_FromDouble(0.0001);
    PyObject *cpy_r_r42[4] = {cpy_r_r7, cpy_r_r38, cpy_r_r39, cpy_r_r41};
    cpy_r_r43 = (PyObject **)&cpy_r_r42;
    cpy_r_r44 = CPyStatics[207]; /* ('type', 'default') */
    cpy_r_r45 = PyObject_VectorcallMethod(cpy_r_r40, cpy_r_r43, 9223372036854775810ULL, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 267, CPyStatic_globals);
        goto CPyL24;
    } else
        goto CPyL25;
CPyL6: ;
    CPy_DECREF(cpy_r_r41);
    cpy_r_r46 = CPyStatics[92]; /* '--iterations' */
    cpy_r_r47 = (PyObject *)&PyLong_Type;
    cpy_r_r48 = CPyStatics[84]; /* 'add_argument' */
    cpy_r_r49 = CPyStatics[194]; /* 30 */
    PyObject *cpy_r_r50[4] = {cpy_r_r7, cpy_r_r46, cpy_r_r47, cpy_r_r49};
    cpy_r_r51 = (PyObject **)&cpy_r_r50;
    cpy_r_r52 = CPyStatics[207]; /* ('type', 'default') */
    cpy_r_r53 = PyObject_VectorcallMethod(cpy_r_r48, cpy_r_r51, 9223372036854775810ULL, cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 268, CPyStatic_globals);
        goto CPyL21;
    } else
        goto CPyL26;
CPyL7: ;
    cpy_r_r54 = CPyStatics[93]; /* '--dt' */
    cpy_r_r55 = (PyObject *)&PyFloat_Type;
    cpy_r_r56 = CPyStatics[84]; /* 'add_argument' */
    cpy_r_r57 = PyFloat_FromDouble(0.08);
    PyObject *cpy_r_r58[4] = {cpy_r_r7, cpy_r_r54, cpy_r_r55, cpy_r_r57};
    cpy_r_r59 = (PyObject **)&cpy_r_r58;
    cpy_r_r60 = CPyStatics[207]; /* ('type', 'default') */
    cpy_r_r61 = PyObject_VectorcallMethod(cpy_r_r56, cpy_r_r59, 9223372036854775810ULL, cpy_r_r60);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 269, CPyStatic_globals);
        goto CPyL27;
    } else
        goto CPyL28;
CPyL8: ;
    CPy_DECREF(cpy_r_r57);
    cpy_r_r62 = CPyStatics[94]; /* '--flow-speed' */
    cpy_r_r63 = (PyObject *)&PyFloat_Type;
    cpy_r_r64 = CPyStatics[84]; /* 'add_argument' */
    cpy_r_r65 = PyFloat_FromDouble(9.0);
    PyObject *cpy_r_r66[4] = {cpy_r_r7, cpy_r_r62, cpy_r_r63, cpy_r_r65};
    cpy_r_r67 = (PyObject **)&cpy_r_r66;
    cpy_r_r68 = CPyStatics[207]; /* ('type', 'default') */
    cpy_r_r69 = PyObject_VectorcallMethod(cpy_r_r64, cpy_r_r67, 9223372036854775810ULL, cpy_r_r68);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 270, CPyStatic_globals);
        goto CPyL29;
    } else
        goto CPyL30;
CPyL9: ;
    CPy_DECREF(cpy_r_r65);
    cpy_r_r70 = CPyStatics[95]; /* '--smoke-strength' */
    cpy_r_r71 = (PyObject *)&PyFloat_Type;
    cpy_r_r72 = CPyStatics[84]; /* 'add_argument' */
    cpy_r_r73 = PyFloat_FromDouble(1.0);
    PyObject *cpy_r_r74[4] = {cpy_r_r7, cpy_r_r70, cpy_r_r71, cpy_r_r73};
    cpy_r_r75 = (PyObject **)&cpy_r_r74;
    cpy_r_r76 = CPyStatics[207]; /* ('type', 'default') */
    cpy_r_r77 = PyObject_VectorcallMethod(cpy_r_r72, cpy_r_r75, 9223372036854775810ULL, cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 271, CPyStatic_globals);
        goto CPyL31;
    } else
        goto CPyL32;
CPyL10: ;
    CPy_DECREF(cpy_r_r73);
    cpy_r_r78 = CPyStatics[96]; /* '--gravity' */
    cpy_r_r79 = (PyObject *)&PyFloat_Type;
    cpy_r_r80 = CPyStatics[84]; /* 'add_argument' */
    cpy_r_r81 = PyFloat_FromDouble(0.0);
    PyObject *cpy_r_r82[4] = {cpy_r_r7, cpy_r_r78, cpy_r_r79, cpy_r_r81};
    cpy_r_r83 = (PyObject **)&cpy_r_r82;
    cpy_r_r84 = CPyStatics[207]; /* ('type', 'default') */
    cpy_r_r85 = PyObject_VectorcallMethod(cpy_r_r80, cpy_r_r83, 9223372036854775810ULL, cpy_r_r84);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 272, CPyStatic_globals);
        goto CPyL33;
    } else
        goto CPyL34;
CPyL11: ;
    CPy_DECREF(cpy_r_r81);
    cpy_r_r86 = CPyStatics[97]; /* '--over-relax' */
    cpy_r_r87 = (PyObject *)&PyFloat_Type;
    cpy_r_r88 = CPyStatics[84]; /* 'add_argument' */
    cpy_r_r89 = PyFloat_FromDouble(1.9);
    PyObject *cpy_r_r90[4] = {cpy_r_r7, cpy_r_r86, cpy_r_r87, cpy_r_r89};
    cpy_r_r91 = (PyObject **)&cpy_r_r90;
    cpy_r_r92 = CPyStatics[207]; /* ('type', 'default') */
    cpy_r_r93 = PyObject_VectorcallMethod(cpy_r_r88, cpy_r_r91, 9223372036854775810ULL, cpy_r_r92);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 273, CPyStatic_globals);
        goto CPyL35;
    } else
        goto CPyL36;
CPyL12: ;
    CPy_DECREF(cpy_r_r89);
    cpy_r_r94 = CPyStatics[98]; /* '--inlet-columns' */
    cpy_r_r95 = (PyObject *)&PyLong_Type;
    cpy_r_r96 = CPyStatics[84]; /* 'add_argument' */
    cpy_r_r97 = CPyStatics[195]; /* 3 */
    PyObject *cpy_r_r98[4] = {cpy_r_r7, cpy_r_r94, cpy_r_r95, cpy_r_r97};
    cpy_r_r99 = (PyObject **)&cpy_r_r98;
    cpy_r_r100 = CPyStatics[207]; /* ('type', 'default') */
    cpy_r_r101 = PyObject_VectorcallMethod(cpy_r_r96, cpy_r_r99, 9223372036854775810ULL, cpy_r_r100);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 274, CPyStatic_globals);
        goto CPyL21;
    } else
        goto CPyL37;
CPyL13: ;
    cpy_r_r102 = CPyStatics[99]; /* '--naca-code' */
    cpy_r_r103 = (PyObject *)&PyUnicode_Type;
    cpy_r_r104 = CPyStatics[100]; /* '2412' */
    cpy_r_r105 = CPyStatics[84]; /* 'add_argument' */
    PyObject *cpy_r_r106[4] = {cpy_r_r7, cpy_r_r102, cpy_r_r103, cpy_r_r104};
    cpy_r_r107 = (PyObject **)&cpy_r_r106;
    cpy_r_r108 = CPyStatics[207]; /* ('type', 'default') */
    cpy_r_r109 = PyObject_VectorcallMethod(cpy_r_r105, cpy_r_r107, 9223372036854775810ULL, cpy_r_r108);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 275, CPyStatic_globals);
        goto CPyL21;
    } else
        goto CPyL38;
CPyL14: ;
    cpy_r_r110 = CPyStatics[101]; /* '--chord-length' */
    cpy_r_r111 = (PyObject *)&PyFloat_Type;
    cpy_r_r112 = CPyStatics[84]; /* 'add_argument' */
    cpy_r_r113 = PyFloat_FromDouble(30.0);
    PyObject *cpy_r_r114[4] = {cpy_r_r7, cpy_r_r110, cpy_r_r111, cpy_r_r113};
    cpy_r_r115 = (PyObject **)&cpy_r_r114;
    cpy_r_r116 = CPyStatics[207]; /* ('type', 'default') */
    cpy_r_r117 = PyObject_VectorcallMethod(cpy_r_r112, cpy_r_r115, 9223372036854775810ULL, cpy_r_r116);
    if (unlikely(cpy_r_r117 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 276, CPyStatic_globals);
        goto CPyL39;
    } else
        goto CPyL40;
CPyL15: ;
    CPy_DECREF(cpy_r_r113);
    cpy_r_r118 = CPyStatics[102]; /* '--center' */
    cpy_r_r119 = (PyObject *)&PyFloat_Type;
    cpy_r_r120 = CPyStatics[103]; /* 'X' */
    cpy_r_r121 = CPyStatics[104]; /* 'Y' */
    CPy_INCREF(cpy_r_r120);
    CPy_INCREF(cpy_r_r121);
    cpy_r_r122.f0 = cpy_r_r120;
    cpy_r_r122.f1 = cpy_r_r121;
    cpy_r_r123.f0 = 70.0;
    cpy_r_r123.f1 = 51.0;
    cpy_r_r124 = CPyStatics[84]; /* 'add_argument' */
    cpy_r_r125 = CPyStatics[190]; /* 2 */
    cpy_r_r126 = PyTuple_New(2);
    if (unlikely(cpy_r_r126 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp86 = cpy_r_r122.f0;
    PyTuple_SET_ITEM(cpy_r_r126, 0, __tmp86);
    PyObject *__tmp87 = cpy_r_r122.f1;
    PyTuple_SET_ITEM(cpy_r_r126, 1, __tmp87);
    cpy_r_r127 = PyTuple_New(2);
    if (unlikely(cpy_r_r127 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp88 = PyFloat_FromDouble(cpy_r_r123.f0);
    PyTuple_SET_ITEM(cpy_r_r127, 0, __tmp88);
    PyObject *__tmp89 = PyFloat_FromDouble(cpy_r_r123.f1);
    PyTuple_SET_ITEM(cpy_r_r127, 1, __tmp89);
    PyObject *cpy_r_r128[6] = {
        cpy_r_r7, cpy_r_r118, cpy_r_r125, cpy_r_r119, cpy_r_r126,
        cpy_r_r127
    };
    cpy_r_r129 = (PyObject **)&cpy_r_r128;
    cpy_r_r130 = CPyStatics[206]; /* ('nargs', 'type', 'metavar', 'default') */
    cpy_r_r131 = PyObject_VectorcallMethod(cpy_r_r124, cpy_r_r129, 9223372036854775810ULL, cpy_r_r130);
    if (unlikely(cpy_r_r131 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 277, CPyStatic_globals);
        goto CPyL41;
    } else
        goto CPyL42;
CPyL16: ;
    CPy_DECREF(cpy_r_r126);
    CPy_DECREF(cpy_r_r127);
    cpy_r_r132 = CPyStatics[105]; /* '--output-dir' */
    cpy_r_r133 = (PyObject *)&PyUnicode_Type;
    cpy_r_r134 = CPyStatics[106]; /* 'outputs' */
    cpy_r_r135 = CPyStatics[84]; /* 'add_argument' */
    PyObject *cpy_r_r136[4] = {cpy_r_r7, cpy_r_r132, cpy_r_r133, cpy_r_r134};
    cpy_r_r137 = (PyObject **)&cpy_r_r136;
    cpy_r_r138 = CPyStatics[207]; /* ('type', 'default') */
    cpy_r_r139 = PyObject_VectorcallMethod(cpy_r_r135, cpy_r_r137, 9223372036854775810ULL, cpy_r_r138);
    if (unlikely(cpy_r_r139 == NULL)) {
        CPy_AddTraceback("simplified.py", "build_parser", 278, CPyStatic_globals);
        goto CPyL21;
    } else
        goto CPyL43;
CPyL17: ;
    return cpy_r_r7;
CPyL18: ;
    cpy_r_r140 = NULL;
    return cpy_r_r140;
CPyL19: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r17);
    goto CPyL18;
CPyL20: ;
    CPy_DECREF(cpy_r_r21);
    goto CPyL3;
CPyL21: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL18;
CPyL22: ;
    CPy_DECREF(cpy_r_r29);
    goto CPyL4;
CPyL23: ;
    CPy_DECREF(cpy_r_r37);
    goto CPyL5;
CPyL24: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r41);
    goto CPyL18;
CPyL25: ;
    CPy_DECREF(cpy_r_r45);
    goto CPyL6;
CPyL26: ;
    CPy_DECREF(cpy_r_r53);
    goto CPyL7;
CPyL27: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r57);
    goto CPyL18;
CPyL28: ;
    CPy_DECREF(cpy_r_r61);
    goto CPyL8;
CPyL29: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r65);
    goto CPyL18;
CPyL30: ;
    CPy_DECREF(cpy_r_r69);
    goto CPyL9;
CPyL31: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r73);
    goto CPyL18;
CPyL32: ;
    CPy_DECREF(cpy_r_r77);
    goto CPyL10;
CPyL33: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r81);
    goto CPyL18;
CPyL34: ;
    CPy_DECREF(cpy_r_r85);
    goto CPyL11;
CPyL35: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r89);
    goto CPyL18;
CPyL36: ;
    CPy_DECREF(cpy_r_r93);
    goto CPyL12;
CPyL37: ;
    CPy_DECREF(cpy_r_r101);
    goto CPyL13;
CPyL38: ;
    CPy_DECREF(cpy_r_r109);
    goto CPyL14;
CPyL39: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r113);
    goto CPyL18;
CPyL40: ;
    CPy_DECREF(cpy_r_r117);
    goto CPyL15;
CPyL41: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r126);
    CPy_DecRef(cpy_r_r127);
    goto CPyL18;
CPyL42: ;
    CPy_DECREF(cpy_r_r131);
    goto CPyL16;
CPyL43: ;
    CPy_DECREF(cpy_r_r139);
    goto CPyL17;
}
    
    PyObject *CPyPy_build_parser(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        static const char * const kwlist[] = {0};
        static CPyArg_Parser parser = {":build_parser", kwlist, 0};
        if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
            return NULL;
        }
        PyObject *retval = CPyDef_build_parser();
        return retval;
fail: ;
        CPy_AddTraceback("simplified.py", "build_parser", 260, CPyStatic_globals);
        return NULL;
    }
    
char CPyDef_main(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject **cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyTagged cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject **cpy_r_r20;
    PyObject *cpy_r_r21;
    CPyTagged cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject **cpy_r_r29;
    PyObject *cpy_r_r30;
    double cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject **cpy_r_r40;
    PyObject *cpy_r_r41;
    double cpy_r_r42;
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject **cpy_r_r49;
    PyObject *cpy_r_r50;
    CPyTagged cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject **cpy_r_r56;
    PyObject *cpy_r_r57;
    double cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject **cpy_r_r65;
    PyObject *cpy_r_r66;
    double cpy_r_r67;
    char cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject **cpy_r_r74;
    PyObject *cpy_r_r75;
    double cpy_r_r76;
    char cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject **cpy_r_r83;
    PyObject *cpy_r_r84;
    double cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject **cpy_r_r92;
    PyObject *cpy_r_r93;
    double cpy_r_r94;
    char cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject **cpy_r_r101;
    PyObject *cpy_r_r102;
    CPyTagged cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject **cpy_r_r112;
    PyObject *cpy_r_r113;
    double cpy_r_r114;
    char cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject **cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject **cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject **cpy_r_r137;
    PyObject *cpy_r_r138;
    CPyTagged cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject **cpy_r_r144;
    PyObject *cpy_r_r145;
    CPyTagged cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject **cpy_r_r151;
    PyObject *cpy_r_r152;
    double cpy_r_r153;
    char cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_previous_speed;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    double cpy_r_r162;
    char cpy_r_r163;
    CPyTagged cpy_r_steps_run;
    CPyTagged cpy_r_r164;
    CPyTagged cpy_r_r165;
    CPyTagged cpy_r_step;
    PyObject *cpy_r_r166;
    int64_t cpy_r_r167;
    char cpy_r_r168;
    int64_t cpy_r_r169;
    char cpy_r_r170;
    char cpy_r_r171;
    char cpy_r_r172;
    char cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_speed;
    PyObject *cpy_r_r175;
    char cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject **cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject **cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject **cpy_r_r192;
    PyObject *cpy_r_r193;
    double cpy_r_r194;
    char cpy_r_r195;
    tuple_T2IF cpy_r_r196;
    PyObject *cpy_r_r197;
    int32_t cpy_r_r198;
    char cpy_r_r199;
    PyObject *cpy_r_r200;
    char cpy_r_r201;
    CPyTagged cpy_r_r202;
    char cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    PyObject *cpy_r_r207;
    PyObject *cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject **cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject *cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject **cpy_r_r220;
    PyObject *cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_r223;
    PyObject *cpy_r_r224;
    PyObject *cpy_r_r225;
    PyObject *cpy_r_r226;
    PyObject *cpy_r_r227;
    PyObject **cpy_r_r229;
    PyObject *cpy_r_r230;
    PyObject *cpy_r_r231;
    PyObject *cpy_r_r232;
    CPyPtr cpy_r_r233;
    CPyPtr cpy_r_r234;
    CPyPtr cpy_r_r235;
    CPyPtr cpy_r_r236;
    CPyPtr cpy_r_r237;
    CPyPtr cpy_r_r238;
    CPyPtr cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    PyObject **cpy_r_r246;
    PyObject *cpy_r_r247;
    PyObject *cpy_r_r248;
    char cpy_r_r249;
    int64_t cpy_r_r250;
    char cpy_r_r251;
    int64_t cpy_r_r252;
    char cpy_r_r253;
    char cpy_r_r254;
    char cpy_r_r255;
    char cpy_r_r256;
    PyObject *cpy_r_r257;
    PyObject *cpy_r_r258;
    PyObject *cpy_r_r259;
    PyObject *cpy_r_r260;
    PyObject *cpy_r_r261;
    PyObject *cpy_r_r262;
    PyObject **cpy_r_r264;
    PyObject *cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject *cpy_r_r267;
    PyObject *cpy_r_r268;
    PyObject *cpy_r_r269;
    PyObject *cpy_r_r270;
    PyObject *cpy_r_r271;
    PyObject **cpy_r_r273;
    PyObject *cpy_r_r274;
    PyObject *cpy_r_r275;
    PyObject *cpy_r_r276;
    CPyPtr cpy_r_r277;
    CPyPtr cpy_r_r278;
    CPyPtr cpy_r_r279;
    CPyPtr cpy_r_r280;
    CPyPtr cpy_r_r281;
    PyObject *cpy_r_r282;
    PyObject *cpy_r_r283;
    PyObject *cpy_r_r284;
    PyObject *cpy_r_r285;
    PyObject *cpy_r_r286;
    PyObject **cpy_r_r288;
    PyObject *cpy_r_r289;
    PyObject *cpy_r_r290;
    char cpy_r_r291;
    PyObject *cpy_r_r292;
    PyObject *cpy_r_r293;
    PyObject *cpy_r_r294;
    PyObject *cpy_r_r295;
    PyObject *cpy_r_r296;
    PyObject *cpy_r_r297;
    PyObject *cpy_r_r298;
    PyObject *cpy_r_r299;
    PyObject *cpy_r_r300;
    PyObject *cpy_r_r301;
    PyObject **cpy_r_r303;
    PyObject *cpy_r_r304;
    PyObject *cpy_r_r305;
    PyObject *cpy_r_r306;
    PyObject **cpy_r_r308;
    PyObject *cpy_r_r309;
    CPyTagged cpy_r_r310;
    int64_t cpy_r_r311;
    char cpy_r_r312;
    char cpy_r_r313;
    char cpy_r_r314;
    char cpy_r_r315;
    PyObject *cpy_r_r316;
    PyObject *cpy_r_r317;
    PyObject *cpy_r_r318;
    PyObject *cpy_r_r319;
    PyObject *cpy_r_r320;
    PyObject *cpy_r_r321;
    PyObject **cpy_r_r323;
    PyObject *cpy_r_r324;
    PyObject *cpy_r_r325;
    PyObject *cpy_r_r326;
    CPyPtr cpy_r_r327;
    CPyPtr cpy_r_r328;
    CPyPtr cpy_r_r329;
    PyObject *cpy_r_r330;
    PyObject *cpy_r_r331;
    PyObject *cpy_r_r332;
    PyObject *cpy_r_r333;
    PyObject *cpy_r_r334;
    PyObject **cpy_r_r336;
    PyObject *cpy_r_r337;
    PyObject *cpy_r_r338;
    PyObject *cpy_r_r339;
    PyObject *cpy_r_r340;
    PyObject *cpy_r_r341;
    PyObject *cpy_r_r342;
    double cpy_r_r343;
    char cpy_r_r344;
    double cpy_r_r345;
    PyObject *cpy_r_r346;
    PyObject *cpy_r_r347;
    PyObject *cpy_r_r348;
    PyObject *cpy_r_r349;
    PyObject *cpy_r_r350;
    PyObject *cpy_r_r351;
    PyObject *cpy_r_r352;
    PyObject *cpy_r_r353;
    char cpy_r_r354;
    PyObject *cpy_r_r355;
    PyObject *cpy_r_r356;
    char cpy_r_r357;
    CPyPtr cpy_r_r358;
    int64_t cpy_r_r359;
    CPyTagged cpy_r_r360;
    char cpy_r_r361;
    PyObject *cpy_r_r362;
    PyObject *cpy_r_r363;
    PyObject *cpy_r_r364;
    PyObject *cpy_r_r365;
    PyObject *cpy_r_r366;
    PyObject *cpy_r_r367;
    PyObject *cpy_r_r368;
    PyObject *cpy_r_r369;
    PyObject **cpy_r_r371;
    PyObject *cpy_r_r372;
    PyObject *cpy_r_r373;
    PyObject *cpy_r_r374;
    PyObject *cpy_r_r375;
    PyObject *cpy_r_r376;
    PyObject *cpy_r_r377;
    PyObject *cpy_r_r378;
    PyObject *cpy_r_r379;
    PyObject *cpy_r_r380;
    PyObject **cpy_r_r382;
    PyObject *cpy_r_r383;
    PyObject *cpy_r_r384;
    PyObject *cpy_r_r385;
    PyObject *cpy_r_r386;
    PyObject *cpy_r_r387;
    PyObject *cpy_r_r388;
    PyObject *cpy_r_r389;
    PyObject *cpy_r_r390;
    PyObject **cpy_r_r392;
    PyObject *cpy_r_r393;
    PyObject *cpy_r_r394;
    PyObject *cpy_r_r395;
    PyObject *cpy_r_r396;
    PyObject *cpy_r_r397;
    PyObject *cpy_r_r398;
    PyObject *cpy_r_r399;
    PyObject **cpy_r_r401;
    PyObject *cpy_r_r402;
    PyObject *cpy_r_r403;
    PyObject *cpy_r_r404;
    CPyPtr cpy_r_r405;
    CPyPtr cpy_r_r406;
    CPyPtr cpy_r_r407;
    PyObject *cpy_r_r408;
    PyObject *cpy_r_r409;
    PyObject *cpy_r_r410;
    PyObject *cpy_r_r411;
    PyObject **cpy_r_r413;
    PyObject *cpy_r_r414;
    PyObject *cpy_r_r415;
    PyObject *cpy_r_r416;
    PyObject *cpy_r_r417;
    double cpy_r_r418;
    char cpy_r_r419;
    char cpy_r_r420;
    PyObject *cpy_r_r421;
    char cpy_r_r422;
    double cpy_r_r423;
    PyObject *cpy_r_r424;
    PyObject *cpy_r_r425;
    PyObject *cpy_r_r426;
    PyObject **cpy_r_r428;
    PyObject *cpy_r_r429;
    PyObject *cpy_r_r430;
    PyObject *cpy_r_r431;
    CPyPtr cpy_r_r432;
    CPyPtr cpy_r_r433;
    CPyPtr cpy_r_r434;
    PyObject *cpy_r_r435;
    PyObject *cpy_r_r436;
    PyObject *cpy_r_r437;
    PyObject *cpy_r_r438;
    PyObject **cpy_r_r440;
    PyObject *cpy_r_r441;
    PyObject *cpy_r_r442;
    PyObject *cpy_r_r443;
    PyObject *cpy_r_r444;
    PyObject *cpy_r_r445;
    PyObject *cpy_r_r446;
    PyObject *cpy_r_r447;
    PyObject **cpy_r_r449;
    PyObject *cpy_r_r450;
    PyObject *cpy_r_r451;
    PyObject **cpy_r_r453;
    PyObject *cpy_r_r454;
    double cpy_r_r455;
    char cpy_r_r456;
    PyObject *cpy_r_r457;
    PyObject *cpy_r_r458;
    PyObject *cpy_r_r459;
    PyObject **cpy_r_r461;
    PyObject *cpy_r_r462;
    PyObject *cpy_r_r463;
    PyObject *cpy_r_r464;
    PyObject *cpy_r_r465;
    CPyPtr cpy_r_r466;
    CPyPtr cpy_r_r467;
    CPyPtr cpy_r_r468;
    PyObject *cpy_r_r469;
    PyObject *cpy_r_r470;
    PyObject *cpy_r_r471;
    PyObject *cpy_r_r472;
    PyObject **cpy_r_r474;
    PyObject *cpy_r_r475;
    PyObject *cpy_r_r476;
    PyObject *cpy_r_r477;
    PyObject *cpy_r_r478;
    PyObject *cpy_r_r479;
    PyObject *cpy_r_r480;
    PyObject *cpy_r_r481;
    PyObject **cpy_r_r483;
    PyObject *cpy_r_r484;
    PyObject *cpy_r_r485;
    PyObject **cpy_r_r487;
    PyObject *cpy_r_r488;
    double cpy_r_r489;
    char cpy_r_r490;
    PyObject *cpy_r_r491;
    PyObject *cpy_r_r492;
    PyObject *cpy_r_r493;
    PyObject **cpy_r_r495;
    PyObject *cpy_r_r496;
    PyObject *cpy_r_r497;
    PyObject *cpy_r_r498;
    PyObject *cpy_r_r499;
    CPyPtr cpy_r_r500;
    CPyPtr cpy_r_r501;
    CPyPtr cpy_r_r502;
    PyObject *cpy_r_r503;
    PyObject *cpy_r_r504;
    PyObject *cpy_r_r505;
    PyObject *cpy_r_r506;
    PyObject **cpy_r_r508;
    PyObject *cpy_r_r509;
    PyObject *cpy_r_r510;
    PyObject *cpy_r_r511;
    PyObject **cpy_r_r513;
    PyObject *cpy_r_r514;
    PyObject *cpy_r_r515;
    PyObject *cpy_r_r516;
    PyObject *cpy_r_r517;
    PyObject *cpy_r_r518;
    PyObject *cpy_r_r519;
    PyObject **cpy_r_r521;
    PyObject *cpy_r_r522;
    char cpy_r_r523;
    cpy_r_r0 = CPyDef_build_parser();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 283, CPyStatic_globals);
        goto CPyL209;
    }
    cpy_r_r1 = CPyStatics[107]; /* 'parse_args' */
    PyObject *cpy_r_r2[1] = {cpy_r_r0};
    cpy_r_r3 = (PyObject **)&cpy_r_r2;
    cpy_r_r4 = PyObject_VectorcallMethod(cpy_r_r1, cpy_r_r3, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 283, CPyStatic_globals);
        goto CPyL210;
    }
    CPy_DECREF(cpy_r_r0);
    cpy_r_r5 = CPyStatics[108]; /* 'resolution' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 285, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r7 = CPyStatics[196]; /* 0 */
    cpy_r_r8 = PyObject_GetItem(cpy_r_r6, cpy_r_r7);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 285, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r9 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r10[1] = {cpy_r_r8};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_Vectorcall(cpy_r_r9, cpy_r_r11, 1, 0);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 285, CPyStatic_globals);
        goto CPyL212;
    }
    CPy_DECREF(cpy_r_r8);
    if (likely(PyLong_Check(cpy_r_r12)))
        cpy_r_r13 = CPyTagged_FromObject(cpy_r_r12);
    else {
        CPy_TypeError("int", cpy_r_r12); cpy_r_r13 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r13 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "main", 285, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r14 = CPyStatics[108]; /* 'resolution' */
    cpy_r_r15 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 285, CPyStatic_globals);
        goto CPyL213;
    }
    cpy_r_r16 = CPyStatics[197]; /* 1 */
    cpy_r_r17 = PyObject_GetItem(cpy_r_r15, cpy_r_r16);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 285, CPyStatic_globals);
        goto CPyL213;
    }
    cpy_r_r18 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r19[1] = {cpy_r_r17};
    cpy_r_r20 = (PyObject **)&cpy_r_r19;
    cpy_r_r21 = PyObject_Vectorcall(cpy_r_r18, cpy_r_r20, 1, 0);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 285, CPyStatic_globals);
        goto CPyL214;
    }
    CPy_DECREF(cpy_r_r17);
    if (likely(PyLong_Check(cpy_r_r21)))
        cpy_r_r22 = CPyTagged_FromObject(cpy_r_r21);
    else {
        CPy_TypeError("int", cpy_r_r21); cpy_r_r22 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r22 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "main", 285, CPyStatic_globals);
        goto CPyL213;
    }
    cpy_r_r23 = CPyStatics[109]; /* 'center' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 286, CPyStatic_globals);
        goto CPyL215;
    }
    cpy_r_r25 = CPyStatics[196]; /* 0 */
    cpy_r_r26 = PyObject_GetItem(cpy_r_r24, cpy_r_r25);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 286, CPyStatic_globals);
        goto CPyL215;
    }
    cpy_r_r27 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r28[1] = {cpy_r_r26};
    cpy_r_r29 = (PyObject **)&cpy_r_r28;
    cpy_r_r30 = PyObject_Vectorcall(cpy_r_r27, cpy_r_r29, 1, 0);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 286, CPyStatic_globals);
        goto CPyL216;
    }
    CPy_DECREF(cpy_r_r26);
    cpy_r_r31 = PyFloat_AsDouble(cpy_r_r30);
    if (cpy_r_r31 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r30); cpy_r_r31 = -113.0;
    }
    CPy_DECREF(cpy_r_r30);
    cpy_r_r32 = cpy_r_r31 == -113.0;
    if (unlikely(cpy_r_r32)) goto CPyL15;
CPyL14: ;
    cpy_r_r33 = CPyStatics[109]; /* 'center' */
    cpy_r_r34 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 286, CPyStatic_globals);
        goto CPyL215;
    } else
        goto CPyL16;
CPyL15: ;
    cpy_r_r35 = PyErr_Occurred();
    if (unlikely(cpy_r_r35 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 286, CPyStatic_globals);
        goto CPyL215;
    } else
        goto CPyL14;
CPyL16: ;
    cpy_r_r36 = CPyStatics[197]; /* 1 */
    cpy_r_r37 = PyObject_GetItem(cpy_r_r34, cpy_r_r36);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 286, CPyStatic_globals);
        goto CPyL215;
    }
    cpy_r_r38 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r39[1] = {cpy_r_r37};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = PyObject_Vectorcall(cpy_r_r38, cpy_r_r40, 1, 0);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 286, CPyStatic_globals);
        goto CPyL217;
    }
    CPy_DECREF(cpy_r_r37);
    cpy_r_r42 = PyFloat_AsDouble(cpy_r_r41);
    if (cpy_r_r42 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r41); cpy_r_r42 = -113.0;
    }
    CPy_DECREF(cpy_r_r41);
    cpy_r_r43 = cpy_r_r42 == -113.0;
    if (unlikely(cpy_r_r43)) goto CPyL20;
CPyL19: ;
    cpy_r_r44 = CPyStatics[110]; /* 'iterations' */
    cpy_r_r45 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 291, CPyStatic_globals);
        goto CPyL215;
    } else
        goto CPyL21;
CPyL20: ;
    cpy_r_r46 = PyErr_Occurred();
    if (unlikely(cpy_r_r46 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 286, CPyStatic_globals);
        goto CPyL215;
    } else
        goto CPyL19;
CPyL21: ;
    cpy_r_r47 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r48[1] = {cpy_r_r45};
    cpy_r_r49 = (PyObject **)&cpy_r_r48;
    cpy_r_r50 = PyObject_Vectorcall(cpy_r_r47, cpy_r_r49, 1, 0);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 291, CPyStatic_globals);
        goto CPyL218;
    }
    CPy_DECREF(cpy_r_r45);
    if (likely(PyLong_Check(cpy_r_r50)))
        cpy_r_r51 = CPyTagged_FromObject(cpy_r_r50);
    else {
        CPy_TypeError("int", cpy_r_r50); cpy_r_r51 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r51 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "main", 291, CPyStatic_globals);
        goto CPyL215;
    }
    cpy_r_r52 = CPyStatics[111]; /* 'dt' */
    cpy_r_r53 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 292, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r54 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r55[1] = {cpy_r_r53};
    cpy_r_r56 = (PyObject **)&cpy_r_r55;
    cpy_r_r57 = PyObject_Vectorcall(cpy_r_r54, cpy_r_r56, 1, 0);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 292, CPyStatic_globals);
        goto CPyL220;
    }
    CPy_DECREF(cpy_r_r53);
    cpy_r_r58 = PyFloat_AsDouble(cpy_r_r57);
    if (cpy_r_r58 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r57); cpy_r_r58 = -113.0;
    }
    CPy_DECREF(cpy_r_r57);
    cpy_r_r59 = cpy_r_r58 == -113.0;
    if (unlikely(cpy_r_r59)) goto CPyL27;
CPyL26: ;
    cpy_r_r60 = CPyStatics[112]; /* 'flow_speed' */
    cpy_r_r61 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r60);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 293, CPyStatic_globals);
        goto CPyL219;
    } else
        goto CPyL28;
CPyL27: ;
    cpy_r_r62 = PyErr_Occurred();
    if (unlikely(cpy_r_r62 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 292, CPyStatic_globals);
        goto CPyL219;
    } else
        goto CPyL26;
CPyL28: ;
    cpy_r_r63 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r64[1] = {cpy_r_r61};
    cpy_r_r65 = (PyObject **)&cpy_r_r64;
    cpy_r_r66 = PyObject_Vectorcall(cpy_r_r63, cpy_r_r65, 1, 0);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 293, CPyStatic_globals);
        goto CPyL221;
    }
    CPy_DECREF(cpy_r_r61);
    cpy_r_r67 = PyFloat_AsDouble(cpy_r_r66);
    if (cpy_r_r67 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r66); cpy_r_r67 = -113.0;
    }
    CPy_DECREF(cpy_r_r66);
    cpy_r_r68 = cpy_r_r67 == -113.0;
    if (unlikely(cpy_r_r68)) goto CPyL31;
CPyL30: ;
    cpy_r_r69 = CPyStatics[113]; /* 'smoke_strength' */
    cpy_r_r70 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 294, CPyStatic_globals);
        goto CPyL219;
    } else
        goto CPyL32;
CPyL31: ;
    cpy_r_r71 = PyErr_Occurred();
    if (unlikely(cpy_r_r71 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 293, CPyStatic_globals);
        goto CPyL219;
    } else
        goto CPyL30;
CPyL32: ;
    cpy_r_r72 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r73[1] = {cpy_r_r70};
    cpy_r_r74 = (PyObject **)&cpy_r_r73;
    cpy_r_r75 = PyObject_Vectorcall(cpy_r_r72, cpy_r_r74, 1, 0);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 294, CPyStatic_globals);
        goto CPyL222;
    }
    CPy_DECREF(cpy_r_r70);
    cpy_r_r76 = PyFloat_AsDouble(cpy_r_r75);
    if (cpy_r_r76 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r75); cpy_r_r76 = -113.0;
    }
    CPy_DECREF(cpy_r_r75);
    cpy_r_r77 = cpy_r_r76 == -113.0;
    if (unlikely(cpy_r_r77)) goto CPyL35;
CPyL34: ;
    cpy_r_r78 = CPyStatics[114]; /* 'gravity' */
    cpy_r_r79 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r78);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 295, CPyStatic_globals);
        goto CPyL219;
    } else
        goto CPyL36;
CPyL35: ;
    cpy_r_r80 = PyErr_Occurred();
    if (unlikely(cpy_r_r80 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 294, CPyStatic_globals);
        goto CPyL219;
    } else
        goto CPyL34;
CPyL36: ;
    cpy_r_r81 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r82[1] = {cpy_r_r79};
    cpy_r_r83 = (PyObject **)&cpy_r_r82;
    cpy_r_r84 = PyObject_Vectorcall(cpy_r_r81, cpy_r_r83, 1, 0);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 295, CPyStatic_globals);
        goto CPyL223;
    }
    CPy_DECREF(cpy_r_r79);
    cpy_r_r85 = PyFloat_AsDouble(cpy_r_r84);
    if (cpy_r_r85 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r84); cpy_r_r85 = -113.0;
    }
    CPy_DECREF(cpy_r_r84);
    cpy_r_r86 = cpy_r_r85 == -113.0;
    if (unlikely(cpy_r_r86)) goto CPyL39;
CPyL38: ;
    cpy_r_r87 = CPyStatics[115]; /* 'over_relax' */
    cpy_r_r88 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r87);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 296, CPyStatic_globals);
        goto CPyL219;
    } else
        goto CPyL40;
CPyL39: ;
    cpy_r_r89 = PyErr_Occurred();
    if (unlikely(cpy_r_r89 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 295, CPyStatic_globals);
        goto CPyL219;
    } else
        goto CPyL38;
CPyL40: ;
    cpy_r_r90 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r91[1] = {cpy_r_r88};
    cpy_r_r92 = (PyObject **)&cpy_r_r91;
    cpy_r_r93 = PyObject_Vectorcall(cpy_r_r90, cpy_r_r92, 1, 0);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 296, CPyStatic_globals);
        goto CPyL224;
    }
    CPy_DECREF(cpy_r_r88);
    cpy_r_r94 = PyFloat_AsDouble(cpy_r_r93);
    if (cpy_r_r94 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r93); cpy_r_r94 = -113.0;
    }
    CPy_DECREF(cpy_r_r93);
    cpy_r_r95 = cpy_r_r94 == -113.0;
    if (unlikely(cpy_r_r95)) goto CPyL43;
CPyL42: ;
    cpy_r_r96 = CPyStatics[116]; /* 'inlet_columns' */
    cpy_r_r97 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r96);
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 297, CPyStatic_globals);
        goto CPyL219;
    } else
        goto CPyL44;
CPyL43: ;
    cpy_r_r98 = PyErr_Occurred();
    if (unlikely(cpy_r_r98 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 296, CPyStatic_globals);
        goto CPyL219;
    } else
        goto CPyL42;
CPyL44: ;
    cpy_r_r99 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r100[1] = {cpy_r_r97};
    cpy_r_r101 = (PyObject **)&cpy_r_r100;
    cpy_r_r102 = PyObject_Vectorcall(cpy_r_r99, cpy_r_r101, 1, 0);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 297, CPyStatic_globals);
        goto CPyL225;
    }
    CPy_DECREF(cpy_r_r97);
    if (likely(PyLong_Check(cpy_r_r102)))
        cpy_r_r103 = CPyTagged_FromObject(cpy_r_r102);
    else {
        CPy_TypeError("int", cpy_r_r102); cpy_r_r103 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r102);
    if (unlikely(cpy_r_r103 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "main", 297, CPyStatic_globals);
        goto CPyL219;
    }
    cpy_r_r104 = CPyDef_HeadlessWindTunnel(cpy_r_r13, cpy_r_r22, 0.0, cpy_r_r67, cpy_r_r76, cpy_r_r85, cpy_r_r58, cpy_r_r51, cpy_r_r94, cpy_r_r103, 62);
    CPyTagged_DECREF(cpy_r_r13);
    CPyTagged_DECREF(cpy_r_r22);
    CPyTagged_DECREF(cpy_r_r51);
    CPyTagged_DECREF(cpy_r_r103);
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 288, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r105 = CPyStatics[13]; /* 'naca_code' */
    cpy_r_r106 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r105);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 300, CPyStatic_globals);
        goto CPyL226;
    }
    cpy_r_r107 = PyObject_Str(cpy_r_r106);
    CPy_DECREF(cpy_r_r106);
    if (unlikely(cpy_r_r107 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 300, CPyStatic_globals);
        goto CPyL226;
    }
    cpy_r_r108 = CPyStatics[14]; /* 'chord_length' */
    cpy_r_r109 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r108);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 301, CPyStatic_globals);
        goto CPyL227;
    }
    cpy_r_r110 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r111[1] = {cpy_r_r109};
    cpy_r_r112 = (PyObject **)&cpy_r_r111;
    cpy_r_r113 = PyObject_Vectorcall(cpy_r_r110, cpy_r_r112, 1, 0);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 301, CPyStatic_globals);
        goto CPyL228;
    }
    CPy_DECREF(cpy_r_r109);
    cpy_r_r114 = PyFloat_AsDouble(cpy_r_r113);
    if (cpy_r_r114 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r113); cpy_r_r114 = -113.0;
    }
    CPy_DECREF(cpy_r_r113);
    cpy_r_r115 = cpy_r_r114 == -113.0;
    if (unlikely(cpy_r_r115)) goto CPyL53;
CPyL52: ;
    cpy_r_r116 = CPyDef_HeadlessWindTunnel___set_obstacle_airfoil(cpy_r_r104, cpy_r_r107, cpy_r_r114, cpy_r_r31, cpy_r_r42);
    CPy_DECREF(cpy_r_r107);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 299, CPyStatic_globals);
        goto CPyL226;
    } else
        goto CPyL229;
CPyL53: ;
    cpy_r_r117 = PyErr_Occurred();
    if (unlikely(cpy_r_r117 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 301, CPyStatic_globals);
        goto CPyL227;
    } else
        goto CPyL52;
CPyL54: ;
    cpy_r_r118 = CPyStatics[117]; /* 'output_dir' */
    cpy_r_r119 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r118);
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 306, CPyStatic_globals);
        goto CPyL226;
    }
    cpy_r_r120 = CPyStatic_globals;
    cpy_r_r121 = CPyStatics[118]; /* 'Path' */
    cpy_r_r122 = CPyDict_GetItem(cpy_r_r120, cpy_r_r121);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 306, CPyStatic_globals);
        goto CPyL230;
    }
    PyObject *cpy_r_r123[1] = {cpy_r_r119};
    cpy_r_r124 = (PyObject **)&cpy_r_r123;
    cpy_r_r125 = PyObject_Vectorcall(cpy_r_r122, cpy_r_r124, 1, 0);
    CPy_DECREF(cpy_r_r122);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 306, CPyStatic_globals);
        goto CPyL230;
    }
    CPy_DECREF(cpy_r_r119);
    cpy_r_r126 = CPyStatics[119]; /* 'mkdir' */
    cpy_r_r127 = 1 ? Py_True : Py_False;
    cpy_r_r128 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r129[3] = {cpy_r_r125, cpy_r_r127, cpy_r_r128};
    cpy_r_r130 = (PyObject **)&cpy_r_r129;
    cpy_r_r131 = CPyStatics[208]; /* ('parents', 'exist_ok') */
    cpy_r_r132 = PyObject_VectorcallMethod(cpy_r_r126, cpy_r_r130, 9223372036854775809ULL, cpy_r_r131);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 307, CPyStatic_globals);
        goto CPyL231;
    } else
        goto CPyL232;
CPyL58: ;
    cpy_r_r133 = CPyStatics[122]; /* 'hardstep' */
    cpy_r_r134 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r133);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 309, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r135 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r136[1] = {cpy_r_r134};
    cpy_r_r137 = (PyObject **)&cpy_r_r136;
    cpy_r_r138 = PyObject_Vectorcall(cpy_r_r135, cpy_r_r137, 1, 0);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 309, CPyStatic_globals);
        goto CPyL233;
    }
    CPy_DECREF(cpy_r_r134);
    if (likely(PyLong_Check(cpy_r_r138)))
        cpy_r_r139 = CPyTagged_FromObject(cpy_r_r138);
    else {
        CPy_TypeError("int", cpy_r_r138); cpy_r_r139 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r138);
    if (unlikely(cpy_r_r139 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "main", 309, CPyStatic_globals);
        goto CPyL231;
    }
    cpy_r_r140 = CPyStatics[123]; /* 'min_steps' */
    cpy_r_r141 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r140);
    if (unlikely(cpy_r_r141 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 310, CPyStatic_globals);
        goto CPyL234;
    }
    cpy_r_r142 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r143[1] = {cpy_r_r141};
    cpy_r_r144 = (PyObject **)&cpy_r_r143;
    cpy_r_r145 = PyObject_Vectorcall(cpy_r_r142, cpy_r_r144, 1, 0);
    if (unlikely(cpy_r_r145 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 310, CPyStatic_globals);
        goto CPyL235;
    }
    CPy_DECREF(cpy_r_r141);
    if (likely(PyLong_Check(cpy_r_r145)))
        cpy_r_r146 = CPyTagged_FromObject(cpy_r_r145);
    else {
        CPy_TypeError("int", cpy_r_r145); cpy_r_r146 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r145);
    if (unlikely(cpy_r_r146 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "main", 310, CPyStatic_globals);
        goto CPyL234;
    }
    cpy_r_r147 = CPyStatics[124]; /* 'steady_tol' */
    cpy_r_r148 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r147);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 311, CPyStatic_globals);
        goto CPyL236;
    }
    cpy_r_r149 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r150[1] = {cpy_r_r148};
    cpy_r_r151 = (PyObject **)&cpy_r_r150;
    cpy_r_r152 = PyObject_Vectorcall(cpy_r_r149, cpy_r_r151, 1, 0);
    if (unlikely(cpy_r_r152 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 311, CPyStatic_globals);
        goto CPyL237;
    }
    CPy_DECREF(cpy_r_r148);
    cpy_r_r153 = PyFloat_AsDouble(cpy_r_r152);
    if (cpy_r_r153 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r152); cpy_r_r153 = -113.0;
    }
    CPy_DECREF(cpy_r_r152);
    cpy_r_r154 = cpy_r_r153 == -113.0;
    if (unlikely(cpy_r_r154)) goto CPyL68;
CPyL67: ;
    cpy_r_r155 = Py_None;
    cpy_r_previous_speed = cpy_r_r155;
    cpy_r_r156 = PyList_New(0);
    if (unlikely(cpy_r_r156 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 313, CPyStatic_globals);
        goto CPyL238;
    } else
        goto CPyL69;
CPyL68: ;
    cpy_r_r157 = PyErr_Occurred();
    if (unlikely(cpy_r_r157 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 311, CPyStatic_globals);
        goto CPyL236;
    } else
        goto CPyL67;
CPyL69: ;
    cpy_r_r158 = CPyModule_time;
    cpy_r_r159 = CPyStatics[125]; /* 'perf_counter' */
    cpy_r_r160 = CPyObject_GetAttr(cpy_r_r158, cpy_r_r159);
    if (unlikely(cpy_r_r160 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 315, CPyStatic_globals);
        goto CPyL239;
    }
    cpy_r_r161 = PyObject_Vectorcall(cpy_r_r160, 0, 0, 0);
    CPy_DECREF(cpy_r_r160);
    if (unlikely(cpy_r_r161 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 315, CPyStatic_globals);
        goto CPyL239;
    }
    cpy_r_r162 = PyFloat_AsDouble(cpy_r_r161);
    if (cpy_r_r162 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r161); cpy_r_r162 = -113.0;
    }
    CPy_DECREF(cpy_r_r161);
    cpy_r_r163 = cpy_r_r162 == -113.0;
    if (unlikely(cpy_r_r163)) goto CPyL73;
CPyL72: ;
    CPyTagged_INCREF(cpy_r_r139);
    cpy_r_steps_run = cpy_r_r139;
    cpy_r_r164 = CPyTagged_Add(cpy_r_r139, 2);
    cpy_r_r165 = 2;
    CPyTagged_INCREF(cpy_r_r165);
    cpy_r_step = cpy_r_r165;
    CPyTagged_DECREF(cpy_r_step);
    goto CPyL74;
CPyL73: ;
    cpy_r_r166 = PyErr_Occurred();
    if (unlikely(cpy_r_r166 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 315, CPyStatic_globals);
        goto CPyL239;
    } else
        goto CPyL72;
CPyL74: ;
    cpy_r_r167 = cpy_r_r165 & 1;
    cpy_r_r168 = cpy_r_r167 != 0;
    if (cpy_r_r168) goto CPyL76;
    cpy_r_r169 = cpy_r_r164 & 1;
    cpy_r_r170 = cpy_r_r169 != 0;
    if (!cpy_r_r170) goto CPyL77;
CPyL76: ;
    cpy_r_r171 = CPyTagged_IsLt_(cpy_r_r165, cpy_r_r164);
    if (cpy_r_r171) {
        goto CPyL78;
    } else
        goto CPyL240;
CPyL77: ;
    cpy_r_r172 = (Py_ssize_t)cpy_r_r165 < (Py_ssize_t)cpy_r_r164;
    if (!cpy_r_r172) goto CPyL240;
CPyL78: ;
    CPyTagged_INCREF(cpy_r_r165);
    cpy_r_step = cpy_r_r165;
    cpy_r_r173 = CPyDef_HeadlessWindTunnel___step(cpy_r_r104, 2);
    if (unlikely(cpy_r_r173 == 2)) {
        CPy_AddTraceback("simplified.py", "main", 319, CPyStatic_globals);
        goto CPyL241;
    }
    cpy_r_r174 = CPyDef_HeadlessWindTunnel___speed_field(cpy_r_r104);
    if (unlikely(cpy_r_r174 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 320, CPyStatic_globals);
        goto CPyL241;
    }
    cpy_r_speed = cpy_r_r174;
    cpy_r_r175 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r176 = cpy_r_previous_speed != cpy_r_r175;
    if (!cpy_r_r176) goto CPyL242;
    cpy_r_r177 = PyNumber_Subtract(cpy_r_speed, cpy_r_previous_speed);
    CPy_DECREF(cpy_r_previous_speed);
    if (unlikely(cpy_r_r177 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 323, CPyStatic_globals);
        goto CPyL243;
    }
    cpy_r_r178 = CPyModule_numpy;
    cpy_r_r179 = CPyStatics[126]; /* 'abs' */
    cpy_r_r180 = CPyObject_GetAttr(cpy_r_r178, cpy_r_r179);
    if (unlikely(cpy_r_r180 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 323, CPyStatic_globals);
        goto CPyL244;
    }
    PyObject *cpy_r_r181[1] = {cpy_r_r177};
    cpy_r_r182 = (PyObject **)&cpy_r_r181;
    cpy_r_r183 = PyObject_Vectorcall(cpy_r_r180, cpy_r_r182, 1, 0);
    CPy_DECREF(cpy_r_r180);
    if (unlikely(cpy_r_r183 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 323, CPyStatic_globals);
        goto CPyL244;
    }
    CPy_DECREF(cpy_r_r177);
    cpy_r_r184 = CPyModule_numpy;
    cpy_r_r185 = CPyStatics[127]; /* 'max' */
    cpy_r_r186 = CPyObject_GetAttr(cpy_r_r184, cpy_r_r185);
    if (unlikely(cpy_r_r186 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 323, CPyStatic_globals);
        goto CPyL245;
    }
    PyObject *cpy_r_r187[1] = {cpy_r_r183};
    cpy_r_r188 = (PyObject **)&cpy_r_r187;
    cpy_r_r189 = PyObject_Vectorcall(cpy_r_r186, cpy_r_r188, 1, 0);
    CPy_DECREF(cpy_r_r186);
    if (unlikely(cpy_r_r189 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 323, CPyStatic_globals);
        goto CPyL245;
    }
    CPy_DECREF(cpy_r_r183);
    cpy_r_r190 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r191[1] = {cpy_r_r189};
    cpy_r_r192 = (PyObject **)&cpy_r_r191;
    cpy_r_r193 = PyObject_Vectorcall(cpy_r_r190, cpy_r_r192, 1, 0);
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 323, CPyStatic_globals);
        goto CPyL246;
    }
    CPy_DECREF(cpy_r_r189);
    cpy_r_r194 = PyFloat_AsDouble(cpy_r_r193);
    if (cpy_r_r194 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r193); cpy_r_r194 = -113.0;
    }
    CPy_DECREF(cpy_r_r193);
    cpy_r_r195 = cpy_r_r194 == -113.0;
    if (unlikely(cpy_r_r195)) goto CPyL89;
CPyL88: ;
    CPyTagged_INCREF(cpy_r_step);
    cpy_r_r196.f0 = cpy_r_step;
    cpy_r_r196.f1 = cpy_r_r194;
    cpy_r_r197 = PyTuple_New(2);
    if (unlikely(cpy_r_r197 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp90 = CPyTagged_StealAsObject(cpy_r_r196.f0);
    PyTuple_SET_ITEM(cpy_r_r197, 0, __tmp90);
    PyObject *__tmp91 = PyFloat_FromDouble(cpy_r_r196.f1);
    PyTuple_SET_ITEM(cpy_r_r197, 1, __tmp91);
    cpy_r_r198 = PyList_Append(cpy_r_r156, cpy_r_r197);
    CPy_DECREF(cpy_r_r197);
    cpy_r_r199 = cpy_r_r198 >= 0;
    if (unlikely(!cpy_r_r199)) {
        CPy_AddTraceback("simplified.py", "main", 324, CPyStatic_globals);
        goto CPyL243;
    } else
        goto CPyL90;
CPyL89: ;
    cpy_r_r200 = PyErr_Occurred();
    if (unlikely(cpy_r_r200 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 323, CPyStatic_globals);
        goto CPyL243;
    } else
        goto CPyL88;
CPyL90: ;
    cpy_r_r201 = cpy_r_step == 4;
    if (cpy_r_r201) goto CPyL93;
    cpy_r_r202 = CPyTagged_Remainder(cpy_r_step, 20);
    if (unlikely(cpy_r_r202 == CPY_INT_TAG)) {
        CPy_AddTraceback("simplified.py", "main", 325, CPyStatic_globals);
        goto CPyL243;
    }
    cpy_r_r203 = cpy_r_r202 == 0;
    CPyTagged_DECREF(cpy_r_r202);
    if (!cpy_r_r203) goto CPyL104;
CPyL93: ;
    cpy_r_r204 = CPyStatics[42]; /* '' */
    cpy_r_r205 = CPyStatics[128]; /* 'step ' */
    cpy_r_r206 = CPyStatics[129]; /* '{:{}}' */
    cpy_r_r207 = CPyStatics[42]; /* '' */
    cpy_r_r208 = CPyStatics[130]; /* 'format' */
    CPyTagged_INCREF(cpy_r_step);
    cpy_r_r209 = CPyTagged_StealAsObject(cpy_r_step);
    PyObject *cpy_r_r210[3] = {cpy_r_r206, cpy_r_r209, cpy_r_r207};
    cpy_r_r211 = (PyObject **)&cpy_r_r210;
    cpy_r_r212 = PyObject_VectorcallMethod(cpy_r_r208, cpy_r_r211, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r212 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 326, CPyStatic_globals);
        goto CPyL247;
    }
    CPy_DECREF(cpy_r_r209);
    if (likely(PyUnicode_Check(cpy_r_r212)))
        cpy_r_r213 = cpy_r_r212;
    else {
        CPy_TypeErrorTraceback("simplified.py", "main", 326, CPyStatic_globals, "str", cpy_r_r212);
        goto CPyL243;
    }
    cpy_r_r214 = CPyStatics[131]; /* '/' */
    cpy_r_r215 = CPyStatics[129]; /* '{:{}}' */
    cpy_r_r216 = CPyStatics[42]; /* '' */
    cpy_r_r217 = CPyStatics[130]; /* 'format' */
    CPyTagged_INCREF(cpy_r_r139);
    cpy_r_r218 = CPyTagged_StealAsObject(cpy_r_r139);
    PyObject *cpy_r_r219[3] = {cpy_r_r215, cpy_r_r218, cpy_r_r216};
    cpy_r_r220 = (PyObject **)&cpy_r_r219;
    cpy_r_r221 = PyObject_VectorcallMethod(cpy_r_r217, cpy_r_r220, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r221 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 326, CPyStatic_globals);
        goto CPyL248;
    }
    CPy_DECREF(cpy_r_r218);
    if (likely(PyUnicode_Check(cpy_r_r221)))
        cpy_r_r222 = cpy_r_r221;
    else {
        CPy_TypeErrorTraceback("simplified.py", "main", 326, CPyStatic_globals, "str", cpy_r_r221);
        goto CPyL249;
    }
    cpy_r_r223 = CPyStatics[132]; /* ' | max_speed_change=' */
    cpy_r_r224 = CPyStatics[129]; /* '{:{}}' */
    cpy_r_r225 = CPyStatics[133]; /* '.6e' */
    cpy_r_r226 = CPyStatics[130]; /* 'format' */
    cpy_r_r227 = PyFloat_FromDouble(cpy_r_r194);
    PyObject *cpy_r_r228[3] = {cpy_r_r224, cpy_r_r227, cpy_r_r225};
    cpy_r_r229 = (PyObject **)&cpy_r_r228;
    cpy_r_r230 = PyObject_VectorcallMethod(cpy_r_r226, cpy_r_r229, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r230 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 326, CPyStatic_globals);
        goto CPyL250;
    }
    CPy_DECREF(cpy_r_r227);
    if (likely(PyUnicode_Check(cpy_r_r230)))
        cpy_r_r231 = cpy_r_r230;
    else {
        CPy_TypeErrorTraceback("simplified.py", "main", 326, CPyStatic_globals, "str", cpy_r_r230);
        goto CPyL251;
    }
    cpy_r_r232 = PyList_New(6);
    if (unlikely(cpy_r_r232 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 326, CPyStatic_globals);
        goto CPyL252;
    }
    cpy_r_r233 = (CPyPtr)((CPyPtr)cpy_r_r232 + offsetof(PyListObject, ob_item));
    cpy_r_r234 = *(CPyPtr *)cpy_r_r233;
    CPy_INCREF(cpy_r_r205);
    *(PyObject * *)cpy_r_r234 = cpy_r_r205;
    cpy_r_r235 = cpy_r_r234 + 8;
    *(PyObject * *)cpy_r_r235 = cpy_r_r213;
    CPy_INCREF(cpy_r_r214);
    cpy_r_r236 = cpy_r_r234 + 16;
    *(PyObject * *)cpy_r_r236 = cpy_r_r214;
    cpy_r_r237 = cpy_r_r234 + 24;
    *(PyObject * *)cpy_r_r237 = cpy_r_r222;
    CPy_INCREF(cpy_r_r223);
    cpy_r_r238 = cpy_r_r234 + 32;
    *(PyObject * *)cpy_r_r238 = cpy_r_r223;
    cpy_r_r239 = cpy_r_r234 + 40;
    *(PyObject * *)cpy_r_r239 = cpy_r_r231;
    cpy_r_r240 = PyUnicode_Join(cpy_r_r204, cpy_r_r232);
    CPy_DECREF_NO_IMM(cpy_r_r232);
    if (unlikely(cpy_r_r240 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 326, CPyStatic_globals);
        goto CPyL243;
    }
    cpy_r_r241 = CPyModule_builtins;
    cpy_r_r242 = CPyStatics[134]; /* 'print' */
    cpy_r_r243 = CPyObject_GetAttr(cpy_r_r241, cpy_r_r242);
    if (unlikely(cpy_r_r243 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 326, CPyStatic_globals);
        goto CPyL253;
    }
    cpy_r_r244 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r245[2] = {cpy_r_r240, cpy_r_r244};
    cpy_r_r246 = (PyObject **)&cpy_r_r245;
    cpy_r_r247 = CPyStatics[209]; /* ('flush',) */
    cpy_r_r248 = PyObject_Vectorcall(cpy_r_r243, cpy_r_r246, 1, cpy_r_r247);
    CPy_DECREF(cpy_r_r243);
    if (unlikely(cpy_r_r248 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 326, CPyStatic_globals);
        goto CPyL253;
    } else
        goto CPyL254;
CPyL103: ;
    CPy_DECREF(cpy_r_r240);
CPyL104: ;
    cpy_r_r249 = cpy_r_r194 < cpy_r_r153;
    if (!cpy_r_r249) goto CPyL255;
    cpy_r_r250 = cpy_r_step & 1;
    cpy_r_r251 = cpy_r_r250 != 0;
    if (cpy_r_r251) goto CPyL107;
    cpy_r_r252 = cpy_r_r146 & 1;
    cpy_r_r253 = cpy_r_r252 != 0;
    if (!cpy_r_r253) goto CPyL108;
CPyL107: ;
    cpy_r_r254 = CPyTagged_IsLt_(cpy_r_step, cpy_r_r146);
    cpy_r_r255 = cpy_r_r254 ^ 1;
    if (cpy_r_r255) {
        goto CPyL256;
    } else
        goto CPyL255;
CPyL108: ;
    cpy_r_r256 = (Py_ssize_t)cpy_r_step >= (Py_ssize_t)cpy_r_r146;
    if (cpy_r_r256) {
        goto CPyL256;
    } else
        goto CPyL255;
CPyL109: ;
    CPyTagged_INCREF(cpy_r_step);
    cpy_r_steps_run = cpy_r_step;
    cpy_r_r257 = CPyStatics[42]; /* '' */
    cpy_r_r258 = CPyStatics[136]; /* 'steady state reached at step ' */
    cpy_r_r259 = CPyStatics[129]; /* '{:{}}' */
    cpy_r_r260 = CPyStatics[42]; /* '' */
    cpy_r_r261 = CPyStatics[130]; /* 'format' */
    cpy_r_r262 = CPyTagged_StealAsObject(cpy_r_step);
    PyObject *cpy_r_r263[3] = {cpy_r_r259, cpy_r_r262, cpy_r_r260};
    cpy_r_r264 = (PyObject **)&cpy_r_r263;
    cpy_r_r265 = PyObject_VectorcallMethod(cpy_r_r261, cpy_r_r264, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r265 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 330, CPyStatic_globals);
        goto CPyL257;
    }
    CPy_DECREF(cpy_r_r262);
    if (likely(PyUnicode_Check(cpy_r_r265)))
        cpy_r_r266 = cpy_r_r265;
    else {
        CPy_TypeErrorTraceback("simplified.py", "main", 330, CPyStatic_globals, "str", cpy_r_r265);
        goto CPyL258;
    }
    cpy_r_r267 = CPyStatics[132]; /* ' | max_speed_change=' */
    cpy_r_r268 = CPyStatics[129]; /* '{:{}}' */
    cpy_r_r269 = CPyStatics[133]; /* '.6e' */
    cpy_r_r270 = CPyStatics[130]; /* 'format' */
    cpy_r_r271 = PyFloat_FromDouble(cpy_r_r194);
    PyObject *cpy_r_r272[3] = {cpy_r_r268, cpy_r_r271, cpy_r_r269};
    cpy_r_r273 = (PyObject **)&cpy_r_r272;
    cpy_r_r274 = PyObject_VectorcallMethod(cpy_r_r270, cpy_r_r273, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r274 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 330, CPyStatic_globals);
        goto CPyL259;
    }
    CPy_DECREF(cpy_r_r271);
    if (likely(PyUnicode_Check(cpy_r_r274)))
        cpy_r_r275 = cpy_r_r274;
    else {
        CPy_TypeErrorTraceback("simplified.py", "main", 330, CPyStatic_globals, "str", cpy_r_r274);
        goto CPyL260;
    }
    cpy_r_r276 = PyList_New(4);
    if (unlikely(cpy_r_r276 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 330, CPyStatic_globals);
        goto CPyL261;
    }
    cpy_r_r277 = (CPyPtr)((CPyPtr)cpy_r_r276 + offsetof(PyListObject, ob_item));
    cpy_r_r278 = *(CPyPtr *)cpy_r_r277;
    CPy_INCREF(cpy_r_r258);
    *(PyObject * *)cpy_r_r278 = cpy_r_r258;
    cpy_r_r279 = cpy_r_r278 + 8;
    *(PyObject * *)cpy_r_r279 = cpy_r_r266;
    CPy_INCREF(cpy_r_r267);
    cpy_r_r280 = cpy_r_r278 + 16;
    *(PyObject * *)cpy_r_r280 = cpy_r_r267;
    cpy_r_r281 = cpy_r_r278 + 24;
    *(PyObject * *)cpy_r_r281 = cpy_r_r275;
    cpy_r_r282 = PyUnicode_Join(cpy_r_r257, cpy_r_r276);
    CPy_DECREF_NO_IMM(cpy_r_r276);
    if (unlikely(cpy_r_r282 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 330, CPyStatic_globals);
        goto CPyL258;
    }
    cpy_r_r283 = CPyModule_builtins;
    cpy_r_r284 = CPyStatics[134]; /* 'print' */
    cpy_r_r285 = CPyObject_GetAttr(cpy_r_r283, cpy_r_r284);
    if (unlikely(cpy_r_r285 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 329, CPyStatic_globals);
        goto CPyL262;
    }
    cpy_r_r286 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r287[2] = {cpy_r_r282, cpy_r_r286};
    cpy_r_r288 = (PyObject **)&cpy_r_r287;
    cpy_r_r289 = CPyStatics[209]; /* ('flush',) */
    cpy_r_r290 = PyObject_Vectorcall(cpy_r_r285, cpy_r_r288, 1, cpy_r_r289);
    CPy_DECREF(cpy_r_r285);
    if (unlikely(cpy_r_r290 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 329, CPyStatic_globals);
        goto CPyL262;
    } else
        goto CPyL263;
CPyL117: ;
    CPy_DECREF(cpy_r_r282);
    goto CPyL128;
CPyL118: ;
    cpy_r_r291 = cpy_r_step == 2;
    if (!cpy_r_r291) goto CPyL255;
    cpy_r_r292 = CPyStatics[128]; /* 'step ' */
    cpy_r_r293 = CPyTagged_Str(cpy_r_step);
    CPyTagged_DECREF(cpy_r_step);
    if (unlikely(cpy_r_r293 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 335, CPyStatic_globals);
        goto CPyL264;
    }
    cpy_r_r294 = CPyStatics[131]; /* '/' */
    cpy_r_r295 = CPyTagged_Str(cpy_r_r139);
    if (unlikely(cpy_r_r295 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 335, CPyStatic_globals);
        goto CPyL265;
    }
    cpy_r_r296 = CPyStatics[137]; /* ' | initializing flow field' */
    cpy_r_r297 = CPyStr_Build(5, cpy_r_r292, cpy_r_r293, cpy_r_r294, cpy_r_r295, cpy_r_r296);
    CPy_DECREF(cpy_r_r293);
    CPy_DECREF(cpy_r_r295);
    if (unlikely(cpy_r_r297 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 335, CPyStatic_globals);
        goto CPyL264;
    }
    cpy_r_r298 = CPyModule_builtins;
    cpy_r_r299 = CPyStatics[134]; /* 'print' */
    cpy_r_r300 = CPyObject_GetAttr(cpy_r_r298, cpy_r_r299);
    if (unlikely(cpy_r_r300 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 335, CPyStatic_globals);
        goto CPyL266;
    }
    cpy_r_r301 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r302[2] = {cpy_r_r297, cpy_r_r301};
    cpy_r_r303 = (PyObject **)&cpy_r_r302;
    cpy_r_r304 = CPyStatics[209]; /* ('flush',) */
    cpy_r_r305 = PyObject_Vectorcall(cpy_r_r300, cpy_r_r303, 1, cpy_r_r304);
    CPy_DECREF(cpy_r_r300);
    if (unlikely(cpy_r_r305 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 335, CPyStatic_globals);
        goto CPyL266;
    } else
        goto CPyL267;
CPyL124: ;
    CPy_DECREF(cpy_r_r297);
CPyL125: ;
    cpy_r_r306 = CPyStatics[138]; /* 'copy' */
    PyObject *cpy_r_r307[1] = {cpy_r_speed};
    cpy_r_r308 = (PyObject **)&cpy_r_r307;
    cpy_r_r309 = PyObject_VectorcallMethod(cpy_r_r306, cpy_r_r308, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r309 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 337, CPyStatic_globals);
        goto CPyL264;
    }
    CPy_DECREF(cpy_r_speed);
    cpy_r_previous_speed = cpy_r_r309;
    cpy_r_r310 = CPyTagged_Add(cpy_r_r165, 2);
    CPyTagged_DECREF(cpy_r_r165);
    cpy_r_r165 = cpy_r_r310;
    goto CPyL74;
CPyL128: ;
    cpy_r_r311 = cpy_r_steps_run & 1;
    cpy_r_r312 = cpy_r_r311 != 0;
    if (!cpy_r_r312) goto CPyL130;
    cpy_r_r313 = CPyTagged_IsEq_(cpy_r_steps_run, cpy_r_r139);
    cpy_r_r314 = cpy_r_r313;
    goto CPyL131;
CPyL130: ;
    cpy_r_r315 = cpy_r_steps_run == cpy_r_r139;
    cpy_r_r314 = cpy_r_r315;
CPyL131: ;
    CPyTagged_DECREF(cpy_r_r139);
    if (!cpy_r_r314) goto CPyL139;
    cpy_r_r316 = CPyStatics[42]; /* '' */
    cpy_r_r317 = CPyStatics[139]; /* 'max steps reached without meeting steady tolerance ' */
    cpy_r_r318 = CPyStatics[129]; /* '{:{}}' */
    cpy_r_r319 = CPyStatics[140]; /* '.1e' */
    cpy_r_r320 = CPyStatics[130]; /* 'format' */
    cpy_r_r321 = PyFloat_FromDouble(cpy_r_r153);
    PyObject *cpy_r_r322[3] = {cpy_r_r318, cpy_r_r321, cpy_r_r319};
    cpy_r_r323 = (PyObject **)&cpy_r_r322;
    cpy_r_r324 = PyObject_VectorcallMethod(cpy_r_r320, cpy_r_r323, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r324 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 340, CPyStatic_globals);
        goto CPyL268;
    }
    CPy_DECREF(cpy_r_r321);
    if (likely(PyUnicode_Check(cpy_r_r324)))
        cpy_r_r325 = cpy_r_r324;
    else {
        CPy_TypeErrorTraceback("simplified.py", "main", 340, CPyStatic_globals, "str", cpy_r_r324);
        goto CPyL269;
    }
    cpy_r_r326 = PyList_New(2);
    if (unlikely(cpy_r_r326 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 340, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r327 = (CPyPtr)((CPyPtr)cpy_r_r326 + offsetof(PyListObject, ob_item));
    cpy_r_r328 = *(CPyPtr *)cpy_r_r327;
    CPy_INCREF(cpy_r_r317);
    *(PyObject * *)cpy_r_r328 = cpy_r_r317;
    cpy_r_r329 = cpy_r_r328 + 8;
    *(PyObject * *)cpy_r_r329 = cpy_r_r325;
    cpy_r_r330 = PyUnicode_Join(cpy_r_r316, cpy_r_r326);
    CPy_DECREF_NO_IMM(cpy_r_r326);
    if (unlikely(cpy_r_r330 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 340, CPyStatic_globals);
        goto CPyL269;
    }
    cpy_r_r331 = CPyModule_builtins;
    cpy_r_r332 = CPyStatics[134]; /* 'print' */
    cpy_r_r333 = CPyObject_GetAttr(cpy_r_r331, cpy_r_r332);
    if (unlikely(cpy_r_r333 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 340, CPyStatic_globals);
        goto CPyL271;
    }
    cpy_r_r334 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r335[2] = {cpy_r_r330, cpy_r_r334};
    cpy_r_r336 = (PyObject **)&cpy_r_r335;
    cpy_r_r337 = CPyStatics[209]; /* ('flush',) */
    cpy_r_r338 = PyObject_Vectorcall(cpy_r_r333, cpy_r_r336, 1, cpy_r_r337);
    CPy_DECREF(cpy_r_r333);
    if (unlikely(cpy_r_r338 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 340, CPyStatic_globals);
        goto CPyL271;
    } else
        goto CPyL272;
CPyL138: ;
    CPy_DECREF(cpy_r_r330);
CPyL139: ;
    cpy_r_r339 = CPyModule_time;
    cpy_r_r340 = CPyStatics[125]; /* 'perf_counter' */
    cpy_r_r341 = CPyObject_GetAttr(cpy_r_r339, cpy_r_r340);
    if (unlikely(cpy_r_r341 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 342, CPyStatic_globals);
        goto CPyL269;
    }
    cpy_r_r342 = PyObject_Vectorcall(cpy_r_r341, 0, 0, 0);
    CPy_DECREF(cpy_r_r341);
    if (unlikely(cpy_r_r342 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 342, CPyStatic_globals);
        goto CPyL269;
    }
    cpy_r_r343 = PyFloat_AsDouble(cpy_r_r342);
    if (cpy_r_r343 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r342); cpy_r_r343 = -113.0;
    }
    CPy_DECREF(cpy_r_r342);
    cpy_r_r344 = cpy_r_r343 == -113.0;
    if (unlikely(cpy_r_r344)) goto CPyL143;
CPyL142: ;
    cpy_r_r345 = cpy_r_r343 - cpy_r_r162;
    cpy_r_r346 = CPyDef_HeadlessWindTunnel___speed_field(cpy_r_r104);
    if (unlikely(cpy_r_r346 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 344, CPyStatic_globals);
        goto CPyL269;
    } else
        goto CPyL144;
CPyL143: ;
    cpy_r_r347 = PyErr_Occurred();
    if (unlikely(cpy_r_r347 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 342, CPyStatic_globals);
        goto CPyL269;
    } else
        goto CPyL142;
CPyL144: ;
    cpy_r_speed = cpy_r_r346;
    cpy_r_r348 = CPyDef_HeadlessWindTunnel___smoke_field(cpy_r_r104);
    if (unlikely(cpy_r_r348 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 345, CPyStatic_globals);
        goto CPyL273;
    }
    cpy_r_r349 = CPyDef_HeadlessWindTunnel___pressure_field(cpy_r_r104);
    if (unlikely(cpy_r_r349 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 346, CPyStatic_globals);
        goto CPyL274;
    }
    cpy_r_r350 = CPyDef_HeadlessWindTunnel___solid_field(cpy_r_r104);
    if (unlikely(cpy_r_r350 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 347, CPyStatic_globals);
        goto CPyL275;
    }
    cpy_r_r351 = CPyDef_HeadlessWindTunnel___export_cell_data(cpy_r_r104);
    CPy_DECREF_NO_IMM(cpy_r_r104);
    if (unlikely(cpy_r_r351 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 348, CPyStatic_globals);
        goto CPyL276;
    }
    cpy_r_r352 = CPyStatics[141]; /* 'airfoil_cells.csv' */
    cpy_r_r353 = PyNumber_TrueDivide(cpy_r_r125, cpy_r_r352);
    if (unlikely(cpy_r_r353 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 350, CPyStatic_globals);
        goto CPyL277;
    }
    cpy_r_r354 = CPyDef_save_cell_csv(cpy_r_r353, cpy_r_r351);
    CPy_DECREF(cpy_r_r353);
    CPy_DECREF(cpy_r_r351);
    if (unlikely(cpy_r_r354 == 2)) {
        CPy_AddTraceback("simplified.py", "main", 350, CPyStatic_globals);
        goto CPyL276;
    }
    cpy_r_r355 = CPyStatics[142]; /* 'airfoil_fields.png' */
    cpy_r_r356 = PyNumber_TrueDivide(cpy_r_r125, cpy_r_r355);
    if (unlikely(cpy_r_r356 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 351, CPyStatic_globals);
        goto CPyL276;
    }
    cpy_r_r357 = CPyDef_save_field_plot(cpy_r_r356, cpy_r_speed, cpy_r_r348, cpy_r_r349, cpy_r_r350);
    CPy_DECREF(cpy_r_r356);
    CPy_DECREF(cpy_r_r349);
    CPy_DECREF(cpy_r_r350);
    if (unlikely(cpy_r_r357 == 2)) {
        CPy_AddTraceback("simplified.py", "main", 351, CPyStatic_globals);
        goto CPyL278;
    }
    cpy_r_r358 = (CPyPtr)((CPyPtr)cpy_r_r156 + offsetof(PyVarObject, ob_size));
    cpy_r_r359 = *(int64_t *)cpy_r_r358;
    cpy_r_r360 = cpy_r_r359 << 1;
    cpy_r_r361 = cpy_r_r360 != 0;
    if (!cpy_r_r361) goto CPyL279;
    cpy_r_r362 = CPyStatics[143]; /* 'residual_history.csv' */
    cpy_r_r363 = PyNumber_TrueDivide(cpy_r_r125, cpy_r_r362);
    if (unlikely(cpy_r_r363 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 355, CPyStatic_globals);
        goto CPyL278;
    }
    cpy_r_r364 = CPyModule_numpy;
    cpy_r_r365 = CPyStatics[144]; /* 'float64' */
    cpy_r_r366 = CPyObject_GetAttr(cpy_r_r364, cpy_r_r365);
    if (unlikely(cpy_r_r366 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 356, CPyStatic_globals);
        goto CPyL280;
    }
    cpy_r_r367 = CPyModule_numpy;
    cpy_r_r368 = CPyStatics[38]; /* 'array' */
    cpy_r_r369 = CPyObject_GetAttr(cpy_r_r367, cpy_r_r368);
    if (unlikely(cpy_r_r369 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 356, CPyStatic_globals);
        goto CPyL281;
    }
    PyObject *cpy_r_r370[2] = {cpy_r_r156, cpy_r_r366};
    cpy_r_r371 = (PyObject **)&cpy_r_r370;
    cpy_r_r372 = CPyStatics[199]; /* ('dtype',) */
    cpy_r_r373 = PyObject_Vectorcall(cpy_r_r369, cpy_r_r371, 1, cpy_r_r372);
    CPy_DECREF(cpy_r_r369);
    if (unlikely(cpy_r_r373 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 356, CPyStatic_globals);
        goto CPyL281;
    }
    CPy_DECREF_NO_IMM(cpy_r_r156);
    CPy_DECREF(cpy_r_r366);
    cpy_r_r374 = CPyStatics[41]; /* ',' */
    cpy_r_r375 = CPyStatics[145]; /* 'step,max_speed_change' */
    cpy_r_r376 = CPyStatics[42]; /* '' */
    cpy_r_r377 = CPyStatics[43]; /* '%.6f' */
    cpy_r_r378 = CPyModule_numpy;
    cpy_r_r379 = CPyStatics[44]; /* 'savetxt' */
    cpy_r_r380 = CPyObject_GetAttr(cpy_r_r378, cpy_r_r379);
    if (unlikely(cpy_r_r380 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 354, CPyStatic_globals);
        goto CPyL282;
    }
    PyObject *cpy_r_r381[6] = {
        cpy_r_r363, cpy_r_r373, cpy_r_r374, cpy_r_r375, cpy_r_r376,
        cpy_r_r377
    };
    cpy_r_r382 = (PyObject **)&cpy_r_r381;
    cpy_r_r383 = CPyStatics[200]; /* ('delimiter', 'header', 'comments', 'fmt') */
    cpy_r_r384 = PyObject_Vectorcall(cpy_r_r380, cpy_r_r382, 2, cpy_r_r383);
    CPy_DECREF(cpy_r_r380);
    if (unlikely(cpy_r_r384 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 354, CPyStatic_globals);
        goto CPyL282;
    } else
        goto CPyL283;
CPyL159: ;
    CPy_DECREF(cpy_r_r363);
    CPy_DECREF(cpy_r_r373);
CPyL160: ;
    cpy_r_r385 = CPyStatics[146]; /* 'steps: ' */
    cpy_r_r386 = CPyTagged_Str(cpy_r_steps_run);
    if (unlikely(cpy_r_r386 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 363, CPyStatic_globals);
        goto CPyL284;
    }
    cpy_r_r387 = CPyStr_Build(2, cpy_r_r385, cpy_r_r386);
    CPy_DECREF(cpy_r_r386);
    if (unlikely(cpy_r_r387 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 363, CPyStatic_globals);
        goto CPyL284;
    }
    cpy_r_r388 = CPyModule_builtins;
    cpy_r_r389 = CPyStatics[134]; /* 'print' */
    cpy_r_r390 = CPyObject_GetAttr(cpy_r_r388, cpy_r_r389);
    if (unlikely(cpy_r_r390 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 363, CPyStatic_globals);
        goto CPyL285;
    }
    PyObject *cpy_r_r391[1] = {cpy_r_r387};
    cpy_r_r392 = (PyObject **)&cpy_r_r391;
    cpy_r_r393 = PyObject_Vectorcall(cpy_r_r390, cpy_r_r392, 1, 0);
    CPy_DECREF(cpy_r_r390);
    if (unlikely(cpy_r_r393 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 363, CPyStatic_globals);
        goto CPyL285;
    } else
        goto CPyL286;
CPyL164: ;
    CPy_DECREF(cpy_r_r387);
    cpy_r_r394 = CPyStatics[42]; /* '' */
    cpy_r_r395 = CPyStatics[147]; /* 'elapsed_seconds: ' */
    cpy_r_r396 = CPyStatics[129]; /* '{:{}}' */
    cpy_r_r397 = CPyStatics[148]; /* '.3f' */
    cpy_r_r398 = CPyStatics[130]; /* 'format' */
    cpy_r_r399 = PyFloat_FromDouble(cpy_r_r345);
    PyObject *cpy_r_r400[3] = {cpy_r_r396, cpy_r_r399, cpy_r_r397};
    cpy_r_r401 = (PyObject **)&cpy_r_r400;
    cpy_r_r402 = PyObject_VectorcallMethod(cpy_r_r398, cpy_r_r401, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r402 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 364, CPyStatic_globals);
        goto CPyL287;
    }
    CPy_DECREF(cpy_r_r399);
    if (likely(PyUnicode_Check(cpy_r_r402)))
        cpy_r_r403 = cpy_r_r402;
    else {
        CPy_TypeErrorTraceback("simplified.py", "main", 364, CPyStatic_globals, "str", cpy_r_r402);
        goto CPyL284;
    }
    cpy_r_r404 = PyList_New(2);
    if (unlikely(cpy_r_r404 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 364, CPyStatic_globals);
        goto CPyL288;
    }
    cpy_r_r405 = (CPyPtr)((CPyPtr)cpy_r_r404 + offsetof(PyListObject, ob_item));
    cpy_r_r406 = *(CPyPtr *)cpy_r_r405;
    CPy_INCREF(cpy_r_r395);
    *(PyObject * *)cpy_r_r406 = cpy_r_r395;
    cpy_r_r407 = cpy_r_r406 + 8;
    *(PyObject * *)cpy_r_r407 = cpy_r_r403;
    cpy_r_r408 = PyUnicode_Join(cpy_r_r394, cpy_r_r404);
    CPy_DECREF_NO_IMM(cpy_r_r404);
    if (unlikely(cpy_r_r408 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 364, CPyStatic_globals);
        goto CPyL284;
    }
    cpy_r_r409 = CPyModule_builtins;
    cpy_r_r410 = CPyStatics[134]; /* 'print' */
    cpy_r_r411 = CPyObject_GetAttr(cpy_r_r409, cpy_r_r410);
    if (unlikely(cpy_r_r411 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 364, CPyStatic_globals);
        goto CPyL289;
    }
    PyObject *cpy_r_r412[1] = {cpy_r_r408};
    cpy_r_r413 = (PyObject **)&cpy_r_r412;
    cpy_r_r414 = PyObject_Vectorcall(cpy_r_r411, cpy_r_r413, 1, 0);
    CPy_DECREF(cpy_r_r411);
    if (unlikely(cpy_r_r414 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 364, CPyStatic_globals);
        goto CPyL289;
    } else
        goto CPyL290;
CPyL170: ;
    CPy_DECREF(cpy_r_r408);
    cpy_r_r415 = CPyStatics[42]; /* '' */
    cpy_r_r416 = CPyStatics[149]; /* 'steps_per_second: ' */
    cpy_r_r417 = CPyStatics[129]; /* '{:{}}' */
    cpy_r_r418 = CPyFloat_FromTagged(cpy_r_steps_run);
    CPyTagged_DECREF(cpy_r_steps_run);
    cpy_r_r419 = cpy_r_r418 == -113.0;
    if (unlikely(cpy_r_r419)) goto CPyL172;
CPyL171: ;
    cpy_r_r420 = cpy_r_r345 == 0.0;
    if (unlikely(cpy_r_r420)) {
        goto CPyL291;
    } else
        goto CPyL175;
CPyL172: ;
    cpy_r_r421 = PyErr_Occurred();
    if (unlikely(cpy_r_r421 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 365, CPyStatic_globals);
        goto CPyL292;
    } else
        goto CPyL171;
CPyL173: ;
    PyErr_SetString(PyExc_ZeroDivisionError, "float division by zero");
    cpy_r_r422 = 0;
    if (unlikely(!cpy_r_r422)) {
        CPy_AddTraceback("simplified.py", "main", 365, CPyStatic_globals);
        goto CPyL209;
    }
    CPy_Unreachable();
CPyL175: ;
    cpy_r_r423 = cpy_r_r418 / cpy_r_r345;
    cpy_r_r424 = CPyStatics[150]; /* '.2f' */
    cpy_r_r425 = CPyStatics[130]; /* 'format' */
    cpy_r_r426 = PyFloat_FromDouble(cpy_r_r423);
    PyObject *cpy_r_r427[3] = {cpy_r_r417, cpy_r_r426, cpy_r_r424};
    cpy_r_r428 = (PyObject **)&cpy_r_r427;
    cpy_r_r429 = PyObject_VectorcallMethod(cpy_r_r425, cpy_r_r428, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r429 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 365, CPyStatic_globals);
        goto CPyL293;
    }
    CPy_DECREF(cpy_r_r426);
    if (likely(PyUnicode_Check(cpy_r_r429)))
        cpy_r_r430 = cpy_r_r429;
    else {
        CPy_TypeErrorTraceback("simplified.py", "main", 365, CPyStatic_globals, "str", cpy_r_r429);
        goto CPyL292;
    }
    cpy_r_r431 = PyList_New(2);
    if (unlikely(cpy_r_r431 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 365, CPyStatic_globals);
        goto CPyL294;
    }
    cpy_r_r432 = (CPyPtr)((CPyPtr)cpy_r_r431 + offsetof(PyListObject, ob_item));
    cpy_r_r433 = *(CPyPtr *)cpy_r_r432;
    CPy_INCREF(cpy_r_r416);
    *(PyObject * *)cpy_r_r433 = cpy_r_r416;
    cpy_r_r434 = cpy_r_r433 + 8;
    *(PyObject * *)cpy_r_r434 = cpy_r_r430;
    cpy_r_r435 = PyUnicode_Join(cpy_r_r415, cpy_r_r431);
    CPy_DECREF_NO_IMM(cpy_r_r431);
    if (unlikely(cpy_r_r435 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 365, CPyStatic_globals);
        goto CPyL292;
    }
    cpy_r_r436 = CPyModule_builtins;
    cpy_r_r437 = CPyStatics[134]; /* 'print' */
    cpy_r_r438 = CPyObject_GetAttr(cpy_r_r436, cpy_r_r437);
    if (unlikely(cpy_r_r438 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 365, CPyStatic_globals);
        goto CPyL295;
    }
    PyObject *cpy_r_r439[1] = {cpy_r_r435};
    cpy_r_r440 = (PyObject **)&cpy_r_r439;
    cpy_r_r441 = PyObject_Vectorcall(cpy_r_r438, cpy_r_r440, 1, 0);
    CPy_DECREF(cpy_r_r438);
    if (unlikely(cpy_r_r441 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 365, CPyStatic_globals);
        goto CPyL295;
    } else
        goto CPyL296;
CPyL181: ;
    CPy_DECREF(cpy_r_r435);
    cpy_r_r442 = CPyStatics[42]; /* '' */
    cpy_r_r443 = CPyStatics[151]; /* 'max_speed: ' */
    cpy_r_r444 = CPyStatics[129]; /* '{:{}}' */
    cpy_r_r445 = CPyModule_numpy;
    cpy_r_r446 = CPyStatics[127]; /* 'max' */
    cpy_r_r447 = CPyObject_GetAttr(cpy_r_r445, cpy_r_r446);
    if (unlikely(cpy_r_r447 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 366, CPyStatic_globals);
        goto CPyL292;
    }
    PyObject *cpy_r_r448[1] = {cpy_r_speed};
    cpy_r_r449 = (PyObject **)&cpy_r_r448;
    cpy_r_r450 = PyObject_Vectorcall(cpy_r_r447, cpy_r_r449, 1, 0);
    CPy_DECREF(cpy_r_r447);
    if (unlikely(cpy_r_r450 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 366, CPyStatic_globals);
        goto CPyL292;
    }
    CPy_DECREF(cpy_r_speed);
    cpy_r_r451 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r452[1] = {cpy_r_r450};
    cpy_r_r453 = (PyObject **)&cpy_r_r452;
    cpy_r_r454 = PyObject_Vectorcall(cpy_r_r451, cpy_r_r453, 1, 0);
    if (unlikely(cpy_r_r454 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 366, CPyStatic_globals);
        goto CPyL297;
    }
    CPy_DECREF(cpy_r_r450);
    cpy_r_r455 = PyFloat_AsDouble(cpy_r_r454);
    if (cpy_r_r455 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r454); cpy_r_r455 = -113.0;
    }
    CPy_DECREF(cpy_r_r454);
    cpy_r_r456 = cpy_r_r455 == -113.0;
    if (unlikely(cpy_r_r456)) goto CPyL186;
CPyL185: ;
    cpy_r_r457 = CPyStatics[148]; /* '.3f' */
    cpy_r_r458 = CPyStatics[130]; /* 'format' */
    cpy_r_r459 = PyFloat_FromDouble(cpy_r_r455);
    PyObject *cpy_r_r460[3] = {cpy_r_r444, cpy_r_r459, cpy_r_r457};
    cpy_r_r461 = (PyObject **)&cpy_r_r460;
    cpy_r_r462 = PyObject_VectorcallMethod(cpy_r_r458, cpy_r_r461, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r462 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 366, CPyStatic_globals);
        goto CPyL298;
    } else
        goto CPyL187;
CPyL186: ;
    cpy_r_r463 = PyErr_Occurred();
    if (unlikely(cpy_r_r463 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 366, CPyStatic_globals);
        goto CPyL299;
    } else
        goto CPyL185;
CPyL187: ;
    CPy_DECREF(cpy_r_r459);
    if (likely(PyUnicode_Check(cpy_r_r462)))
        cpy_r_r464 = cpy_r_r462;
    else {
        CPy_TypeErrorTraceback("simplified.py", "main", 366, CPyStatic_globals, "str", cpy_r_r462);
        goto CPyL299;
    }
    cpy_r_r465 = PyList_New(2);
    if (unlikely(cpy_r_r465 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 366, CPyStatic_globals);
        goto CPyL300;
    }
    cpy_r_r466 = (CPyPtr)((CPyPtr)cpy_r_r465 + offsetof(PyListObject, ob_item));
    cpy_r_r467 = *(CPyPtr *)cpy_r_r466;
    CPy_INCREF(cpy_r_r443);
    *(PyObject * *)cpy_r_r467 = cpy_r_r443;
    cpy_r_r468 = cpy_r_r467 + 8;
    *(PyObject * *)cpy_r_r468 = cpy_r_r464;
    cpy_r_r469 = PyUnicode_Join(cpy_r_r442, cpy_r_r465);
    CPy_DECREF_NO_IMM(cpy_r_r465);
    if (unlikely(cpy_r_r469 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 366, CPyStatic_globals);
        goto CPyL299;
    }
    cpy_r_r470 = CPyModule_builtins;
    cpy_r_r471 = CPyStatics[134]; /* 'print' */
    cpy_r_r472 = CPyObject_GetAttr(cpy_r_r470, cpy_r_r471);
    if (unlikely(cpy_r_r472 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 366, CPyStatic_globals);
        goto CPyL301;
    }
    PyObject *cpy_r_r473[1] = {cpy_r_r469};
    cpy_r_r474 = (PyObject **)&cpy_r_r473;
    cpy_r_r475 = PyObject_Vectorcall(cpy_r_r472, cpy_r_r474, 1, 0);
    CPy_DECREF(cpy_r_r472);
    if (unlikely(cpy_r_r475 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 366, CPyStatic_globals);
        goto CPyL301;
    } else
        goto CPyL302;
CPyL192: ;
    CPy_DECREF(cpy_r_r469);
    cpy_r_r476 = CPyStatics[42]; /* '' */
    cpy_r_r477 = CPyStatics[152]; /* 'mean_smoke: ' */
    cpy_r_r478 = CPyStatics[129]; /* '{:{}}' */
    cpy_r_r479 = CPyModule_numpy;
    cpy_r_r480 = CPyStatics[153]; /* 'mean' */
    cpy_r_r481 = CPyObject_GetAttr(cpy_r_r479, cpy_r_r480);
    if (unlikely(cpy_r_r481 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 367, CPyStatic_globals);
        goto CPyL299;
    }
    PyObject *cpy_r_r482[1] = {cpy_r_r348};
    cpy_r_r483 = (PyObject **)&cpy_r_r482;
    cpy_r_r484 = PyObject_Vectorcall(cpy_r_r481, cpy_r_r483, 1, 0);
    CPy_DECREF(cpy_r_r481);
    if (unlikely(cpy_r_r484 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 367, CPyStatic_globals);
        goto CPyL299;
    }
    CPy_DECREF(cpy_r_r348);
    cpy_r_r485 = (PyObject *)&PyFloat_Type;
    PyObject *cpy_r_r486[1] = {cpy_r_r484};
    cpy_r_r487 = (PyObject **)&cpy_r_r486;
    cpy_r_r488 = PyObject_Vectorcall(cpy_r_r485, cpy_r_r487, 1, 0);
    if (unlikely(cpy_r_r488 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 367, CPyStatic_globals);
        goto CPyL303;
    }
    CPy_DECREF(cpy_r_r484);
    cpy_r_r489 = PyFloat_AsDouble(cpy_r_r488);
    if (cpy_r_r489 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r488); cpy_r_r489 = -113.0;
    }
    CPy_DECREF(cpy_r_r488);
    cpy_r_r490 = cpy_r_r489 == -113.0;
    if (unlikely(cpy_r_r490)) goto CPyL197;
CPyL196: ;
    cpy_r_r491 = CPyStatics[148]; /* '.3f' */
    cpy_r_r492 = CPyStatics[130]; /* 'format' */
    cpy_r_r493 = PyFloat_FromDouble(cpy_r_r489);
    PyObject *cpy_r_r494[3] = {cpy_r_r478, cpy_r_r493, cpy_r_r491};
    cpy_r_r495 = (PyObject **)&cpy_r_r494;
    cpy_r_r496 = PyObject_VectorcallMethod(cpy_r_r492, cpy_r_r495, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r496 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 367, CPyStatic_globals);
        goto CPyL304;
    } else
        goto CPyL198;
CPyL197: ;
    cpy_r_r497 = PyErr_Occurred();
    if (unlikely(cpy_r_r497 != NULL)) {
        CPy_AddTraceback("simplified.py", "main", 367, CPyStatic_globals);
        goto CPyL305;
    } else
        goto CPyL196;
CPyL198: ;
    CPy_DECREF(cpy_r_r493);
    if (likely(PyUnicode_Check(cpy_r_r496)))
        cpy_r_r498 = cpy_r_r496;
    else {
        CPy_TypeErrorTraceback("simplified.py", "main", 367, CPyStatic_globals, "str", cpy_r_r496);
        goto CPyL305;
    }
    cpy_r_r499 = PyList_New(2);
    if (unlikely(cpy_r_r499 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 367, CPyStatic_globals);
        goto CPyL306;
    }
    cpy_r_r500 = (CPyPtr)((CPyPtr)cpy_r_r499 + offsetof(PyListObject, ob_item));
    cpy_r_r501 = *(CPyPtr *)cpy_r_r500;
    CPy_INCREF(cpy_r_r477);
    *(PyObject * *)cpy_r_r501 = cpy_r_r477;
    cpy_r_r502 = cpy_r_r501 + 8;
    *(PyObject * *)cpy_r_r502 = cpy_r_r498;
    cpy_r_r503 = PyUnicode_Join(cpy_r_r476, cpy_r_r499);
    CPy_DECREF_NO_IMM(cpy_r_r499);
    if (unlikely(cpy_r_r503 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 367, CPyStatic_globals);
        goto CPyL305;
    }
    cpy_r_r504 = CPyModule_builtins;
    cpy_r_r505 = CPyStatics[134]; /* 'print' */
    cpy_r_r506 = CPyObject_GetAttr(cpy_r_r504, cpy_r_r505);
    if (unlikely(cpy_r_r506 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 367, CPyStatic_globals);
        goto CPyL307;
    }
    PyObject *cpy_r_r507[1] = {cpy_r_r503};
    cpy_r_r508 = (PyObject **)&cpy_r_r507;
    cpy_r_r509 = PyObject_Vectorcall(cpy_r_r506, cpy_r_r508, 1, 0);
    CPy_DECREF(cpy_r_r506);
    if (unlikely(cpy_r_r509 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 367, CPyStatic_globals);
        goto CPyL307;
    } else
        goto CPyL308;
CPyL203: ;
    CPy_DECREF(cpy_r_r503);
    cpy_r_r510 = CPyStatics[154]; /* 'output_dir: ' */
    cpy_r_r511 = CPyStatics[155]; /* 'resolve' */
    PyObject *cpy_r_r512[1] = {cpy_r_r125};
    cpy_r_r513 = (PyObject **)&cpy_r_r512;
    cpy_r_r514 = PyObject_VectorcallMethod(cpy_r_r511, cpy_r_r513, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r514 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 368, CPyStatic_globals);
        goto CPyL305;
    }
    CPy_DECREF(cpy_r_r125);
    cpy_r_r515 = PyObject_Str(cpy_r_r514);
    CPy_DECREF(cpy_r_r514);
    if (unlikely(cpy_r_r515 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 368, CPyStatic_globals);
        goto CPyL209;
    }
    cpy_r_r516 = CPyStr_Build(2, cpy_r_r510, cpy_r_r515);
    CPy_DECREF(cpy_r_r515);
    if (unlikely(cpy_r_r516 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 368, CPyStatic_globals);
        goto CPyL209;
    }
    cpy_r_r517 = CPyModule_builtins;
    cpy_r_r518 = CPyStatics[134]; /* 'print' */
    cpy_r_r519 = CPyObject_GetAttr(cpy_r_r517, cpy_r_r518);
    if (unlikely(cpy_r_r519 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 368, CPyStatic_globals);
        goto CPyL309;
    }
    PyObject *cpy_r_r520[1] = {cpy_r_r516};
    cpy_r_r521 = (PyObject **)&cpy_r_r520;
    cpy_r_r522 = PyObject_Vectorcall(cpy_r_r519, cpy_r_r521, 1, 0);
    CPy_DECREF(cpy_r_r519);
    if (unlikely(cpy_r_r522 == NULL)) {
        CPy_AddTraceback("simplified.py", "main", 368, CPyStatic_globals);
        goto CPyL309;
    } else
        goto CPyL310;
CPyL208: ;
    CPy_DECREF(cpy_r_r516);
    return 1;
CPyL209: ;
    cpy_r_r523 = 2;
    return cpy_r_r523;
CPyL210: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL209;
CPyL211: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL209;
CPyL212: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r8);
    goto CPyL209;
CPyL213: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r13);
    goto CPyL209;
CPyL214: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r17);
    goto CPyL209;
CPyL215: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r22);
    goto CPyL209;
CPyL216: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r26);
    goto CPyL209;
CPyL217: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r37);
    goto CPyL209;
CPyL218: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r45);
    goto CPyL209;
CPyL219: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r51);
    goto CPyL209;
CPyL220: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r53);
    goto CPyL209;
CPyL221: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r61);
    goto CPyL209;
CPyL222: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r70);
    goto CPyL209;
CPyL223: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r79);
    goto CPyL209;
CPyL224: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r88);
    goto CPyL209;
CPyL225: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r22);
    CPyTagged_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r97);
    goto CPyL209;
CPyL226: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r104);
    goto CPyL209;
CPyL227: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r107);
    goto CPyL209;
CPyL228: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r107);
    CPy_DecRef(cpy_r_r109);
    goto CPyL209;
CPyL229: ;
    CPy_DECREF(cpy_r_r116);
    goto CPyL54;
CPyL230: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r119);
    goto CPyL209;
CPyL231: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    goto CPyL209;
CPyL232: ;
    CPy_DECREF(cpy_r_r132);
    goto CPyL58;
CPyL233: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r134);
    goto CPyL209;
CPyL234: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    goto CPyL209;
CPyL235: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPy_DecRef(cpy_r_r141);
    goto CPyL209;
CPyL236: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    goto CPyL209;
CPyL237: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r148);
    goto CPyL209;
CPyL238: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_previous_speed);
    goto CPyL209;
CPyL239: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_previous_speed);
    CPy_DecRef(cpy_r_r156);
    goto CPyL209;
CPyL240: ;
    CPyTagged_DECREF(cpy_r_r146);
    CPy_DECREF(cpy_r_previous_speed);
    CPyTagged_DECREF(cpy_r_r164);
    CPyTagged_DECREF(cpy_r_r165);
    goto CPyL128;
CPyL241: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_previous_speed);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPyTagged_DecRef(cpy_r_step);
    goto CPyL209;
CPyL242: ;
    CPy_DECREF(cpy_r_previous_speed);
    goto CPyL118;
CPyL243: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPyTagged_DecRef(cpy_r_step);
    CPy_DecRef(cpy_r_speed);
    goto CPyL209;
CPyL244: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPyTagged_DecRef(cpy_r_step);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r177);
    goto CPyL209;
CPyL245: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPyTagged_DecRef(cpy_r_step);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r183);
    goto CPyL209;
CPyL246: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPyTagged_DecRef(cpy_r_step);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r189);
    goto CPyL209;
CPyL247: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPyTagged_DecRef(cpy_r_step);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r209);
    goto CPyL209;
CPyL248: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPyTagged_DecRef(cpy_r_step);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r213);
    CPy_DecRef(cpy_r_r218);
    goto CPyL209;
CPyL249: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPyTagged_DecRef(cpy_r_step);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r213);
    goto CPyL209;
CPyL250: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPyTagged_DecRef(cpy_r_step);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r213);
    CPy_DecRef(cpy_r_r222);
    CPy_DecRef(cpy_r_r227);
    goto CPyL209;
CPyL251: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPyTagged_DecRef(cpy_r_step);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r213);
    CPy_DecRef(cpy_r_r222);
    goto CPyL209;
CPyL252: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPyTagged_DecRef(cpy_r_step);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r213);
    CPy_DecRef(cpy_r_r222);
    CPy_DecRef(cpy_r_r231);
    goto CPyL209;
CPyL253: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPyTagged_DecRef(cpy_r_step);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r240);
    goto CPyL209;
CPyL254: ;
    CPy_DECREF(cpy_r_r248);
    goto CPyL103;
CPyL255: ;
    CPyTagged_DECREF(cpy_r_step);
    goto CPyL125;
CPyL256: ;
    CPyTagged_DECREF(cpy_r_r146);
    CPyTagged_DECREF(cpy_r_steps_run);
    CPyTagged_DECREF(cpy_r_r164);
    CPyTagged_DECREF(cpy_r_r165);
    CPy_DECREF(cpy_r_speed);
    goto CPyL109;
CPyL257: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_r262);
    goto CPyL209;
CPyL258: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    goto CPyL209;
CPyL259: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_r266);
    CPy_DecRef(cpy_r_r271);
    goto CPyL209;
CPyL260: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_r266);
    goto CPyL209;
CPyL261: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_r266);
    CPy_DecRef(cpy_r_r275);
    goto CPyL209;
CPyL262: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_r282);
    goto CPyL209;
CPyL263: ;
    CPy_DECREF(cpy_r_r290);
    goto CPyL117;
CPyL264: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPy_DecRef(cpy_r_speed);
    goto CPyL209;
CPyL265: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r293);
    goto CPyL209;
CPyL266: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_r139);
    CPyTagged_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPyTagged_DecRef(cpy_r_r164);
    CPyTagged_DecRef(cpy_r_r165);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r297);
    goto CPyL209;
CPyL267: ;
    CPy_DECREF(cpy_r_r305);
    goto CPyL124;
CPyL268: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_r321);
    goto CPyL209;
CPyL269: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    goto CPyL209;
CPyL270: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_r325);
    goto CPyL209;
CPyL271: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_r330);
    goto CPyL209;
CPyL272: ;
    CPy_DECREF(cpy_r_r338);
    goto CPyL138;
CPyL273: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    goto CPyL209;
CPyL274: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    goto CPyL209;
CPyL275: ;
    CPy_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r349);
    goto CPyL209;
CPyL276: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r349);
    CPy_DecRef(cpy_r_r350);
    goto CPyL209;
CPyL277: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r349);
    CPy_DecRef(cpy_r_r350);
    CPy_DecRef(cpy_r_r351);
    goto CPyL209;
CPyL278: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    goto CPyL209;
CPyL279: ;
    CPy_DECREF_NO_IMM(cpy_r_r156);
    goto CPyL160;
CPyL280: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r363);
    goto CPyL209;
CPyL281: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r156);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r363);
    CPy_DecRef(cpy_r_r366);
    goto CPyL209;
CPyL282: ;
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r363);
    CPy_DecRef(cpy_r_r373);
    goto CPyL209;
CPyL283: ;
    CPy_DECREF(cpy_r_r384);
    goto CPyL159;
CPyL284: ;
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    goto CPyL209;
CPyL285: ;
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r387);
    goto CPyL209;
CPyL286: ;
    CPy_DECREF(cpy_r_r393);
    goto CPyL164;
CPyL287: ;
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r399);
    goto CPyL209;
CPyL288: ;
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r403);
    goto CPyL209;
CPyL289: ;
    CPy_DecRef(cpy_r_r125);
    CPyTagged_DecRef(cpy_r_steps_run);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r408);
    goto CPyL209;
CPyL290: ;
    CPy_DECREF(cpy_r_r414);
    goto CPyL170;
CPyL291: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    goto CPyL173;
CPyL292: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    goto CPyL209;
CPyL293: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r426);
    goto CPyL209;
CPyL294: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r430);
    goto CPyL209;
CPyL295: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_speed);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r435);
    goto CPyL209;
CPyL296: ;
    CPy_DECREF(cpy_r_r441);
    goto CPyL181;
CPyL297: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r450);
    goto CPyL209;
CPyL298: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r459);
    goto CPyL209;
CPyL299: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r348);
    goto CPyL209;
CPyL300: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r464);
    goto CPyL209;
CPyL301: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r348);
    CPy_DecRef(cpy_r_r469);
    goto CPyL209;
CPyL302: ;
    CPy_DECREF(cpy_r_r475);
    goto CPyL192;
CPyL303: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r484);
    goto CPyL209;
CPyL304: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r493);
    goto CPyL209;
CPyL305: ;
    CPy_DecRef(cpy_r_r125);
    goto CPyL209;
CPyL306: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r498);
    goto CPyL209;
CPyL307: ;
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r503);
    goto CPyL209;
CPyL308: ;
    CPy_DECREF(cpy_r_r509);
    goto CPyL203;
CPyL309: ;
    CPy_DecRef(cpy_r_r516);
    goto CPyL209;
CPyL310: ;
    CPy_DECREF(cpy_r_r522);
    goto CPyL208;
}
    
    PyObject *CPyPy_main(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
        static const char * const kwlist[] = {0};
        static CPyArg_Parser parser = {":main", kwlist, 0};
        if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
            return NULL;
        }
        char retval = CPyDef_main();
        if (retval == 2) {
            return NULL;
        }
        PyObject *retbox = Py_None;
        CPy_INCREF(retbox);
        return retbox;
fail: ;
        CPy_AddTraceback("simplified.py", "main", 282, CPyStatic_globals);
        return NULL;
    }
    
char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r9;
    PyObject **cpy_r_r10;
    void *cpy_r_r12;
    void *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject **cpy_r_r28;
    void *cpy_r_r30;
    void *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject **cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject **cpy_r_r45;
    PyObject **cpy_r_r46;
    PyObject **cpy_r_r47;
    void *cpy_r_r49;
    void *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    char cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    int32_t cpy_r_r74;
    char cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    int32_t cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    char cpy_r_r91;
    char cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    int32_t cpy_r_r106;
    char cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    int32_t cpy_r_r110;
    char cpy_r_r111;
    char cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    char cpy_r_r118;
    char cpy_r_r119;
    char cpy_r_r120;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[156]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 1, CPyStatic_globals);
        goto CPyL33;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[210]; /* ('annotations',) */
    cpy_r_r6 = CPyStatics[158]; /* '__future__' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 1, CPyStatic_globals);
        goto CPyL33;
    }
    CPyModule___future__ = cpy_r_r8;
    CPy_INCREF(CPyModule___future__);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = (PyObject **)&CPyModule_argparse;
    cpy_r_r10 = (PyObject **)&CPyModule_time;
    PyObject **cpy_r_r11[2] = {cpy_r_r9, cpy_r_r10};
    cpy_r_r12 = (void *)&cpy_r_r11;
    int64_t cpy_r_r13[2] = {3, 4};
    cpy_r_r14 = (void *)&cpy_r_r13;
    cpy_r_r15 = CPyStatics[213]; /* (('argparse', 'argparse', 'argparse'),
                                    ('time', 'time', 'time')) */
    cpy_r_r16 = CPyStatic_globals;
    cpy_r_r17 = CPyStatics[161]; /* 'simplified.py' */
    cpy_r_r18 = CPyStatics[162]; /* '<module>' */
    cpy_r_r19 = CPyImport_ImportMany(cpy_r_r15, cpy_r_r12, cpy_r_r16, cpy_r_r17, cpy_r_r18, cpy_r_r14);
    if (!cpy_r_r19) goto CPyL33;
    cpy_r_r20 = CPyStatics[214]; /* ('Path',) */
    cpy_r_r21 = CPyStatics[163]; /* 'pathlib' */
    cpy_r_r22 = CPyStatic_globals;
    cpy_r_r23 = CPyImport_ImportFromMany(cpy_r_r21, cpy_r_r20, cpy_r_r20, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 5, CPyStatic_globals);
        goto CPyL33;
    }
    CPyModule_pathlib = cpy_r_r23;
    CPy_INCREF(CPyModule_pathlib);
    CPy_DECREF(cpy_r_r23);
    cpy_r_r24 = CPyStatics[215]; /* ('Sequence',) */
    cpy_r_r25 = CPyStatics[165]; /* 'typing' */
    cpy_r_r26 = CPyStatic_globals;
    cpy_r_r27 = CPyImport_ImportFromMany(cpy_r_r25, cpy_r_r24, cpy_r_r24, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 6, CPyStatic_globals);
        goto CPyL33;
    }
    CPyModule_typing = cpy_r_r27;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r27);
    cpy_r_r28 = (PyObject **)&CPyModule_matplotlib;
    PyObject **cpy_r_r29[1] = {cpy_r_r28};
    cpy_r_r30 = (void *)&cpy_r_r29;
    int64_t cpy_r_r31[1] = {8};
    cpy_r_r32 = (void *)&cpy_r_r31;
    cpy_r_r33 = CPyStatics[217]; /* (('matplotlib', 'matplotlib', 'matplotlib'),) */
    cpy_r_r34 = CPyStatic_globals;
    cpy_r_r35 = CPyStatics[161]; /* 'simplified.py' */
    cpy_r_r36 = CPyStatics[162]; /* '<module>' */
    cpy_r_r37 = CPyImport_ImportMany(cpy_r_r33, cpy_r_r30, cpy_r_r34, cpy_r_r35, cpy_r_r36, cpy_r_r32);
    if (!cpy_r_r37) goto CPyL33;
    cpy_r_r38 = CPyStatics[167]; /* 'Agg' */
    cpy_r_r39 = CPyModule_matplotlib;
    cpy_r_r40 = CPyStatics[168]; /* 'use' */
    cpy_r_r41 = CPyObject_GetAttr(cpy_r_r39, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 10, CPyStatic_globals);
        goto CPyL33;
    }
    PyObject *cpy_r_r42[1] = {cpy_r_r38};
    cpy_r_r43 = (PyObject **)&cpy_r_r42;
    cpy_r_r44 = PyObject_Vectorcall(cpy_r_r41, cpy_r_r43, 1, 0);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 10, CPyStatic_globals);
        goto CPyL33;
    } else
        goto CPyL34;
CPyL10: ;
    cpy_r_r45 = (PyObject **)&CPyModule_matplotlib___pyplot;
    cpy_r_r46 = (PyObject **)&CPyModule_numpy;
    cpy_r_r47 = (PyObject **)&CPyModule_numpy___typing;
    PyObject **cpy_r_r48[3] = {cpy_r_r45, cpy_r_r46, cpy_r_r47};
    cpy_r_r49 = (void *)&cpy_r_r48;
    int64_t cpy_r_r50[3] = {11, 12, 13};
    cpy_r_r51 = (void *)&cpy_r_r50;
    cpy_r_r52 = CPyStatics[221]; /* (('matplotlib.pyplot', 'matplotlib.pyplot', 'plt'),
                                    ('numpy', 'numpy', 'np'),
                                    ('numpy.typing', 'numpy.typing', 'npt')) */
    cpy_r_r53 = CPyStatic_globals;
    cpy_r_r54 = CPyStatics[161]; /* 'simplified.py' */
    cpy_r_r55 = CPyStatics[162]; /* '<module>' */
    cpy_r_r56 = CPyImport_ImportMany(cpy_r_r52, cpy_r_r49, cpy_r_r53, cpy_r_r54, cpy_r_r55, cpy_r_r51);
    if (!cpy_r_r56) goto CPyL33;
    cpy_r_r57 = CPyStatics[222]; /* ('apply_naca_airfoil',) */
    cpy_r_r58 = CPyStatics[175]; /* 'airfoil' */
    cpy_r_r59 = CPyStatic_globals;
    cpy_r_r60 = CPyImport_ImportFromMany(cpy_r_r58, cpy_r_r57, cpy_r_r57, cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 15, CPyStatic_globals);
        goto CPyL33;
    }
    CPyModule_airfoil = cpy_r_r60;
    CPy_INCREF(CPyModule_airfoil);
    CPy_DECREF(cpy_r_r60);
    cpy_r_r61 = CPyStatics[223]; /* ('FLUID', 'set_over_relaxation') */
    cpy_r_r62 = CPyStatics[176]; /* 'sovler' */
    cpy_r_r63 = CPyStatic_globals;
    cpy_r_r64 = CPyImport_ImportFromMany(cpy_r_r62, cpy_r_r61, cpy_r_r61, cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 16, CPyStatic_globals);
        goto CPyL33;
    }
    CPyModule_sovler = cpy_r_r64;
    CPy_INCREF(CPyModule_sovler);
    CPy_DECREF(cpy_r_r64);
    cpy_r_r65 = CPyModule_numpy___typing;
    cpy_r_r66 = CPyStatics[177]; /* 'NDArray' */
    cpy_r_r67 = CPyObject_GetAttr(cpy_r_r65, cpy_r_r66);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 19, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r68 = CPyModule_numpy;
    cpy_r_r69 = CPyStatics[23]; /* 'float32' */
    cpy_r_r70 = CPyObject_GetAttr(cpy_r_r68, cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 19, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r71 = PyObject_GetItem(cpy_r_r67, cpy_r_r70);
    CPy_DECREF(cpy_r_r67);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 19, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r72 = CPyStatic_globals;
    cpy_r_r73 = CPyStatics[178]; /* 'FloatArray' */
    cpy_r_r74 = CPyDict_SetItem(cpy_r_r72, cpy_r_r73, cpy_r_r71);
    CPy_DECREF(cpy_r_r71);
    cpy_r_r75 = cpy_r_r74 >= 0;
    if (unlikely(!cpy_r_r75)) {
        CPy_AddTraceback("simplified.py", "<module>", 19, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r76 = CPyModule_numpy___typing;
    cpy_r_r77 = CPyStatics[177]; /* 'NDArray' */
    cpy_r_r78 = CPyObject_GetAttr(cpy_r_r76, cpy_r_r77);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 20, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r79 = CPyModule_numpy;
    cpy_r_r80 = CPyStatics[179]; /* 'void' */
    cpy_r_r81 = CPyObject_GetAttr(cpy_r_r79, cpy_r_r80);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 20, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r82 = PyObject_GetItem(cpy_r_r78, cpy_r_r81);
    CPy_DECREF(cpy_r_r78);
    CPy_DECREF(cpy_r_r81);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 20, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r83 = CPyStatic_globals;
    cpy_r_r84 = CPyStatics[180]; /* 'StructuredCellArray' */
    cpy_r_r85 = CPyDict_SetItem(cpy_r_r83, cpy_r_r84, cpy_r_r82);
    CPy_DECREF(cpy_r_r82);
    cpy_r_r86 = cpy_r_r85 >= 0;
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("simplified.py", "<module>", 20, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r87 = NULL;
    cpy_r_r88 = CPyStatics[181]; /* 'simplified' */
    cpy_r_r89 = (PyObject *)CPyType_HeadlessWindTunnel_template;
    cpy_r_r90 = CPyType_FromTemplate(cpy_r_r89, cpy_r_r87, cpy_r_r88);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 23, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r91 = CPyDef_HeadlessWindTunnel_trait_vtable_setup();
    if (unlikely(cpy_r_r91 == 2)) {
        CPy_AddTraceback("simplified.py", "<module>", 23, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r92 = CPyDef_HeadlessWindTunnel_coroutine_setup(cpy_r_r90);
    if (unlikely(cpy_r_r92 == 2)) {
        CPy_AddTraceback("simplified.py", "<module>", 23, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r93 = CPyStatics[182]; /* '__mypyc_attrs__' */
    cpy_r_r94 = CPyStatics[183]; /* 'grid_w' */
    cpy_r_r95 = CPyStatics[184]; /* 'grid_h' */
    cpy_r_r96 = CPyStatics[185]; /* 'density' */
    cpy_r_r97 = CPyStatics[112]; /* 'flow_speed' */
    cpy_r_r98 = CPyStatics[113]; /* 'smoke_strength' */
    cpy_r_r99 = CPyStatics[114]; /* 'gravity' */
    cpy_r_r100 = CPyStatics[111]; /* 'dt' */
    cpy_r_r101 = CPyStatics[110]; /* 'iterations' */
    cpy_r_r102 = CPyStatics[115]; /* 'over_relax' */
    cpy_r_r103 = CPyStatics[116]; /* 'inlet_columns' */
    cpy_r_r104 = CPyStatics[186]; /* 'fluid' */
    cpy_r_r105 = PyTuple_Pack(11, cpy_r_r94, cpy_r_r95, cpy_r_r96, cpy_r_r97, cpy_r_r98, cpy_r_r99, cpy_r_r100, cpy_r_r101, cpy_r_r102, cpy_r_r103, cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 23, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r106 = PyObject_SetAttr(cpy_r_r90, cpy_r_r93, cpy_r_r105);
    CPy_DECREF(cpy_r_r105);
    cpy_r_r107 = cpy_r_r106 >= 0;
    if (unlikely(!cpy_r_r107)) {
        CPy_AddTraceback("simplified.py", "<module>", 23, CPyStatic_globals);
        goto CPyL37;
    }
    CPyType_HeadlessWindTunnel = (PyTypeObject *)cpy_r_r90;
    CPy_INCREF(CPyType_HeadlessWindTunnel);
    cpy_r_r108 = CPyStatic_globals;
    cpy_r_r109 = CPyStatics[187]; /* 'HeadlessWindTunnel' */
    cpy_r_r110 = PyDict_SetItem(cpy_r_r108, cpy_r_r109, cpy_r_r90);
    cpy_r_r111 = cpy_r_r110 >= 0;
    if (unlikely(!cpy_r_r111)) {
        CPy_AddTraceback("simplified.py", "<module>", 23, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r112 = CPy_InitSubclass(cpy_r_r90);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(!cpy_r_r112)) {
        CPy_AddTraceback("simplified.py", "<module>", 23, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r113 = CPyStatic_globals;
    cpy_r_r114 = CPyStatics[188]; /* '__name__' */
    cpy_r_r115 = CPyDict_GetItem(cpy_r_r113, cpy_r_r114);
    if (unlikely(cpy_r_r115 == NULL)) {
        CPy_AddTraceback("simplified.py", "<module>", 371, CPyStatic_globals);
        goto CPyL33;
    }
    if (likely(PyUnicode_Check(cpy_r_r115)))
        cpy_r_r116 = cpy_r_r115;
    else {
        CPy_TypeErrorTraceback("simplified.py", "<module>", 371, CPyStatic_globals, "str", cpy_r_r115);
        goto CPyL33;
    }
    cpy_r_r117 = CPyStatics[189]; /* '__main__' */
    cpy_r_r118 = CPyStr_EqualLiteral(cpy_r_r116, cpy_r_r117, 8);
    CPy_DECREF(cpy_r_r116);
    if (!cpy_r_r118) goto CPyL32;
    cpy_r_r119 = CPyDef_main();
    if (unlikely(cpy_r_r119 == 2)) {
        CPy_AddTraceback("simplified.py", "<module>", 372, CPyStatic_globals);
        goto CPyL33;
    }
CPyL32: ;
    return 1;
CPyL33: ;
    cpy_r_r120 = 2;
    return cpy_r_r120;
CPyL34: ;
    CPy_DECREF(cpy_r_r44);
    goto CPyL10;
CPyL35: ;
    CPy_DecRef(cpy_r_r67);
    goto CPyL33;
CPyL36: ;
    CPy_DecRef(cpy_r_r78);
    goto CPyL33;
CPyL37: ;
    CPy_DecRef(cpy_r_r90);
    goto CPyL33;
}
    
    int CPyGlobalsInit(void)
    {
        static int is_initialized = 0;
        if (is_initialized) return 0;
        
        CPy_Init();
        CPyModule_simplified = Py_None;
        CPyModule_builtins = Py_None;
        CPyModule___future__ = Py_None;
        CPyModule_argparse = Py_None;
        CPyModule_time = Py_None;
        CPyModule_pathlib = Py_None;
        CPyModule_typing = Py_None;
        CPyModule_matplotlib = Py_None;
        CPyModule_matplotlib___pyplot = Py_None;
        CPyModule_numpy = Py_None;
        CPyModule_numpy___typing = Py_None;
        CPyModule_airfoil = Py_None;
        CPyModule_sovler = Py_None;
        if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
            return -1;
        }
        is_initialized = 1;
        return 0;
    }
    
    PyObject *CPyStatics[224];
    const char * const CPyLit_Str[] = {
    "\v\004numY\005FLUID\001s\004fill\001m\001u\001v\001p\004numX\022apply_naca_airfoil\tnaca_code",
    "\005\fchord_length\bcenter_x\bcenter_y\023set_over_relaxation\vintegrate_g",
    "\004\027incompressibility_solve\vExtrapolate\radvection_vel\017advection_smoke",
    "\v\afloat32\005zeros\005dtype\004sqrt\acell_id\005int32\001i\001j\006u_face\006v_face\bu_center",
    "\005\bv_center\005speed\005smoke\bpressure\005array",
    "\001Bcell_id,i,j,s,u_face,v_face,u_center,v_center,speed,smoke,pressure",
    "\n\fcolumn_stack\001,\000\004%.6f\asavetxt\tdelimiter\006header\bcomments\003fmt\bsubplots",
    "\006\afigsize\022constrained_layout\005Smoke\004gray\017Speed Magnitude\aviridis",
    "\t\bPressure\bcoolwarm\nSolid Mask\006binary\005ravel\005lower\004auto\006imshow\006origin",
    "\b\004cmap\006aspect\tset_title\nset_xlabel\nset_ylabel\bcolorbar\002ax\006shrink",
    "\005\023Airfoil Flow Report\bsuptitle\asavefig\003dpi\005close",
    "\001CRun the airfoil simulation and export only the final-state results.",
    "\b\016ArgumentParser\vdescription\f--resolution\002NX\002NY\fadd_argument\005nargs\004type",
    "\a\ametavar\adefault\n--hardstep\v--min-steps\f--steady-tol\f--iterations\004--dt",
    "\005\f--flow-speed\020--smoke-strength\t--gravity\f--over-relax\017--inlet-columns",
    "\b\v--naca-code\0042412\016--chord-length\b--center\001X\001Y\f--output-dir\aoutputs",
    "\a\nparse_args\nresolution\006center\niterations\002dt\nflow_speed\016smoke_strength",
    "\a\agravity\nover_relax\rinlet_columns\noutput_dir\004Path\005mkdir\aparents",
    "\b\bexist_ok\bhardstep\tmin_steps\nsteady_tol\fperf_counter\003abs\003max\005step ",
    "\a\005{:{}}\006format\001/\024 | max_speed_change=\003.6e\005print\005flush",
    "\003\035steady state reached at step \032 | initializing flow field\004copy",
    "\0023max steps reached without meeting steady tolerance \003.1e",
    "\004\021airfoil_cells.csv\022airfoil_fields.png\024residual_history.csv\afloat64",
    "\004\025step,max_speed_change\asteps: \021elapsed_seconds: \003.3f",
    "\006\022steps_per_second: \003.2f\vmax_speed: \fmean_smoke: \004mean\foutput_dir: ",
    "\a\aresolve\bbuiltins\vannotations\n__future__\bargparse\004time\rsimplified.py",
    "\b\b<module>\apathlib\bSequence\006typing\nmatplotlib\003Agg\003use\021matplotlib.pyplot",
    "\n\003plt\005numpy\002np\fnumpy.typing\003npt\aairfoil\006sovler\aNDArray\nFloatArray\004void",
    "\006\023StructuredCellArray\nsimplified\017__mypyc_attrs__\006grid_w\006grid_h\adensity",
    "\004\005fluid\022HeadlessWindTunnel\b__name__\b__main__",
    "",
};
    const char * const CPyLit_Bytes[] = {
    "",
};
    const char * const CPyLit_Int[] = {
    "\b2\000180\000400\000100\00030\0003\0000\0001",
    "",
};
    const double CPyLit_Float[] = {0};
    const double CPyLit_Complex[] = {0};
    const int CPyLit_Tuple[] = {
    26, 4, 13, 14, 15, 16, 1, 25, 4, 45, 46, 47, 48, 2, 50, 51, 3, 64,
    65, 66, 2, 71, 72, 1, 76, 1, 80, 4, 85, 86, 87, 88, 2, 86, 88, 2, 120,
    121, 1, 135, 1, 157, 3, 159, 159, 159, 3, 160, 160, 160, 2, 211, 212,
    1, 118, 1, 164, 3, 166, 166, 166, 1, 216, 3, 169, 169, 170, 3, 171,
    171, 172, 3, 173, 173, 174, 3, 218, 219, 220, 1, 12, 2, 4, 17
};
    const int CPyLit_FrozenSet[] = {0};
    CPyModule *CPyModule_simplified__internal = NULL;
    CPyModule *CPyModule_simplified;
    PyObject *CPyStatic_globals;
    CPyModule *CPyModule_builtins;
    CPyModule *CPyModule___future__;
    CPyModule *CPyModule_argparse;
    CPyModule *CPyModule_time;
    CPyModule *CPyModule_pathlib;
    CPyModule *CPyModule_typing;
    CPyModule *CPyModule_matplotlib;
    CPyModule *CPyModule_matplotlib___pyplot;
    CPyModule *CPyModule_numpy;
    CPyModule *CPyModule_numpy___typing;
    CPyModule *CPyModule_airfoil;
    CPyModule *CPyModule_sovler;
    int CPyExec_simplified(PyObject *module);
    PyTypeObject *CPyType_HeadlessWindTunnel;
    PyObject *CPyDef_HeadlessWindTunnel(CPyTagged cpy_r_grid_w, CPyTagged cpy_r_grid_h, double cpy_r_density, double cpy_r_flow_speed, double cpy_r_smoke_strength, double cpy_r_gravity, double cpy_r_dt, CPyTagged cpy_r_iterations, double cpy_r_over_relax, CPyTagged cpy_r_inlet_columns, uint32_t cpy_r___bitmap);
    char CPyDef_HeadlessWindTunnel_____init__(PyObject *cpy_r_self, CPyTagged cpy_r_grid_w, CPyTagged cpy_r_grid_h, double cpy_r_density, double cpy_r_flow_speed, double cpy_r_smoke_strength, double cpy_r_gravity, double cpy_r_dt, CPyTagged cpy_r_iterations, double cpy_r_over_relax, CPyTagged cpy_r_inlet_columns, uint32_t cpy_r___bitmap);
    PyObject *CPyPy_HeadlessWindTunnel_____init__(PyObject *self, PyObject *args, PyObject *kw);
    CPyTagged CPyDef_HeadlessWindTunnel____idx(PyObject *cpy_r_self, CPyTagged cpy_r_i, CPyTagged cpy_r_j);
    PyObject *CPyPy_HeadlessWindTunnel____idx(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    char CPyDef_HeadlessWindTunnel____create_scene(PyObject *cpy_r_self);
    PyObject *CPyPy_HeadlessWindTunnel____create_scene(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    char CPyDef_HeadlessWindTunnel___apply_inlet(PyObject *cpy_r_self);
    PyObject *CPyPy_HeadlessWindTunnel___apply_inlet(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    char CPyDef_HeadlessWindTunnel___set_obstacle_circle(PyObject *cpy_r_self, CPyTagged cpy_r_cx, CPyTagged cpy_r_cy, CPyTagged cpy_r_radius, char cpy_r_solid);
    PyObject *CPyPy_HeadlessWindTunnel___set_obstacle_circle(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    PyObject *CPyDef_HeadlessWindTunnel___set_obstacle_airfoil(PyObject *cpy_r_self, PyObject *cpy_r_naca_code, double cpy_r_chord_length, double cpy_r_center_x, double cpy_r_center_y);
    PyObject *CPyPy_HeadlessWindTunnel___set_obstacle_airfoil(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    char CPyDef_HeadlessWindTunnel___step(PyObject *cpy_r_self, CPyTagged cpy_r_steps);
    PyObject *CPyPy_HeadlessWindTunnel___step(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    PyObject *CPyDef_HeadlessWindTunnel___speed_field(PyObject *cpy_r_self);
    PyObject *CPyPy_HeadlessWindTunnel___speed_field(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    PyObject *CPyDef_HeadlessWindTunnel___smoke_field(PyObject *cpy_r_self);
    PyObject *CPyPy_HeadlessWindTunnel___smoke_field(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    PyObject *CPyDef_HeadlessWindTunnel___pressure_field(PyObject *cpy_r_self);
    PyObject *CPyPy_HeadlessWindTunnel___pressure_field(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    PyObject *CPyDef_HeadlessWindTunnel___solid_field(PyObject *cpy_r_self);
    PyObject *CPyPy_HeadlessWindTunnel___solid_field(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    PyObject *CPyDef_HeadlessWindTunnel___export_cell_data(PyObject *cpy_r_self);
    PyObject *CPyPy_HeadlessWindTunnel___export_cell_data(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    char CPyDef_save_cell_csv(PyObject *cpy_r_path, PyObject *cpy_r_cell_data);
    PyObject *CPyPy_save_cell_csv(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    char CPyDef_save_field_plot(PyObject *cpy_r_path, PyObject *cpy_r_speed, PyObject *cpy_r_smoke, PyObject *cpy_r_pressure, PyObject *cpy_r_solid);
    PyObject *CPyPy_save_field_plot(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    PyObject *CPyDef_build_parser(void);
    PyObject *CPyPy_build_parser(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    char CPyDef_main(void);
    PyObject *CPyPy_main(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
    char CPyDef___top_level__(void);
