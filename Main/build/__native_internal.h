#ifndef MYPYC_LIBRT_INTERNAL_H
#define MYPYC_LIBRT_INTERNAL_H
#include <Python.h>
#include <CPy.h>
#include "__native.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[224];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_simplified__internal;
extern CPyModule *CPyModule_simplified;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule___future__;
extern CPyModule *CPyModule_argparse;
extern CPyModule *CPyModule_time;
extern CPyModule *CPyModule_pathlib;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_matplotlib;
extern CPyModule *CPyModule_matplotlib___pyplot;
extern CPyModule *CPyModule_numpy;
extern CPyModule *CPyModule_numpy___typing;
extern CPyModule *CPyModule_airfoil;
extern CPyModule *CPyModule_sovler;
extern int CPyExec_simplified(PyObject *module);
extern PyTypeObject *CPyType_HeadlessWindTunnel;
extern PyObject *CPyDef_HeadlessWindTunnel(CPyTagged cpy_r_grid_w, CPyTagged cpy_r_grid_h, double cpy_r_density, double cpy_r_flow_speed, double cpy_r_smoke_strength, double cpy_r_gravity, double cpy_r_dt, CPyTagged cpy_r_iterations, double cpy_r_over_relax, CPyTagged cpy_r_inlet_columns, uint32_t cpy_r___bitmap);
extern char CPyDef_HeadlessWindTunnel_____init__(PyObject *cpy_r_self, CPyTagged cpy_r_grid_w, CPyTagged cpy_r_grid_h, double cpy_r_density, double cpy_r_flow_speed, double cpy_r_smoke_strength, double cpy_r_gravity, double cpy_r_dt, CPyTagged cpy_r_iterations, double cpy_r_over_relax, CPyTagged cpy_r_inlet_columns, uint32_t cpy_r___bitmap);
extern PyObject *CPyPy_HeadlessWindTunnel_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern CPyTagged CPyDef_HeadlessWindTunnel____idx(PyObject *cpy_r_self, CPyTagged cpy_r_i, CPyTagged cpy_r_j);
extern PyObject *CPyPy_HeadlessWindTunnel____idx(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_HeadlessWindTunnel____create_scene(PyObject *cpy_r_self);
extern PyObject *CPyPy_HeadlessWindTunnel____create_scene(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_HeadlessWindTunnel___apply_inlet(PyObject *cpy_r_self);
extern PyObject *CPyPy_HeadlessWindTunnel___apply_inlet(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_HeadlessWindTunnel___set_obstacle_circle(PyObject *cpy_r_self, CPyTagged cpy_r_cx, CPyTagged cpy_r_cy, CPyTagged cpy_r_radius, char cpy_r_solid);
extern PyObject *CPyPy_HeadlessWindTunnel___set_obstacle_circle(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_HeadlessWindTunnel___set_obstacle_airfoil(PyObject *cpy_r_self, PyObject *cpy_r_naca_code, double cpy_r_chord_length, double cpy_r_center_x, double cpy_r_center_y);
extern PyObject *CPyPy_HeadlessWindTunnel___set_obstacle_airfoil(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_HeadlessWindTunnel___step(PyObject *cpy_r_self, CPyTagged cpy_r_steps);
extern PyObject *CPyPy_HeadlessWindTunnel___step(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_HeadlessWindTunnel___speed_field(PyObject *cpy_r_self);
extern PyObject *CPyPy_HeadlessWindTunnel___speed_field(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_HeadlessWindTunnel___smoke_field(PyObject *cpy_r_self);
extern PyObject *CPyPy_HeadlessWindTunnel___smoke_field(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_HeadlessWindTunnel___pressure_field(PyObject *cpy_r_self);
extern PyObject *CPyPy_HeadlessWindTunnel___pressure_field(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_HeadlessWindTunnel___solid_field(PyObject *cpy_r_self);
extern PyObject *CPyPy_HeadlessWindTunnel___solid_field(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_HeadlessWindTunnel___export_cell_data(PyObject *cpy_r_self);
extern PyObject *CPyPy_HeadlessWindTunnel___export_cell_data(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_save_cell_csv(PyObject *cpy_r_path, PyObject *cpy_r_cell_data);
extern PyObject *CPyPy_save_cell_csv(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_save_field_plot(PyObject *cpy_r_path, PyObject *cpy_r_speed, PyObject *cpy_r_smoke, PyObject *cpy_r_pressure, PyObject *cpy_r_solid);
extern PyObject *CPyPy_save_field_plot(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_build_parser(void);
extern PyObject *CPyPy_build_parser(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_main(void);
extern PyObject *CPyPy_main(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
