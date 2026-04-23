#ifndef MYPYC_NATIVE_H
#define MYPYC_NATIVE_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T2II
#define MYPYC_DECLARED_tuple_T2II
typedef struct tuple_T2II {
    CPyTagged f0;
    CPyTagged f1;
} tuple_T2II;
#endif

#ifndef MYPYC_DECLARED_tuple_T11IIIFFFFFFFF
#define MYPYC_DECLARED_tuple_T11IIIFFFFFFFF
typedef struct tuple_T11IIIFFFFFFFF {
    CPyTagged f0;
    CPyTagged f1;
    CPyTagged f2;
    double f3;
    double f4;
    double f5;
    double f6;
    double f7;
    double f8;
    double f9;
    double f10;
} tuple_T11IIIFFFFFFFF;
#endif

#ifndef MYPYC_DECLARED_tuple_T2OO
#define MYPYC_DECLARED_tuple_T2OO
typedef struct tuple_T2OO {
    PyObject *f0;
    PyObject *f1;
} tuple_T2OO;
#endif

#ifndef MYPYC_DECLARED_tuple_T3OOO
#define MYPYC_DECLARED_tuple_T3OOO
typedef struct tuple_T3OOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
} tuple_T3OOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T4T3OOOT3OOOT3OOOT3OOO
#define MYPYC_DECLARED_tuple_T4T3OOOT3OOOT3OOOT3OOO
typedef struct tuple_T4T3OOOT3OOOT3OOOT3OOO {
    tuple_T3OOO f0;
    tuple_T3OOO f1;
    tuple_T3OOO f2;
    tuple_T3OOO f3;
} tuple_T4T3OOOT3OOOT3OOOT3OOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T2FF
#define MYPYC_DECLARED_tuple_T2FF
typedef struct tuple_T2FF {
    double f0;
    double f1;
} tuple_T2FF;
#endif

#ifndef MYPYC_DECLARED_tuple_T2IF
#define MYPYC_DECLARED_tuple_T2IF
typedef struct tuple_T2IF {
    CPyTagged f0;
    double f1;
} tuple_T2IF;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    CPyTagged _grid_w;
    CPyTagged _grid_h;
    double _density;
    double _flow_speed;
    double _smoke_strength;
    double _gravity;
    double _dt;
    CPyTagged _iterations;
    double _over_relax;
    CPyTagged _inlet_columns;
    PyObject *_fluid;
} simplified___HeadlessWindTunnelObject;

#endif
