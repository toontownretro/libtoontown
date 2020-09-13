#include "toontownsymbols.h"

#ifndef new_to_old_hpr
void compose_matrix_new_hpr(FLOATNAME(LMatrix3) &mat, const FLOATNAME(LVecBase3) &scale, const FLOATNAME(LVecBase3) &shear, const FLOATNAME(LVecBase3) &hpr, CoordinateSystem cs) {
    mat =
        FLOATNAME(LMatrix3)::scale_shear_mat(scale, shear, cs) *
        FLOATNAME(LMatrix3)::rotate_mat_normaxis(hpr[2], FLOATNAME(LVector3)::forward(cs), cs) *
        FLOATNAME(LMatrix3)::rotate_mat_normaxis(hpr[1], FLOATNAME(LVector3)::right(cs), cs) *
        FLOATNAME(LMatrix3)::rotate_mat_normaxis(hpr[0], FLOATNAME(LVector3)::up(cs), cs);
}

/**
 * Converts the HPR as represented in the new, correct
 * representation to the old, broken way.  Returns the
 * old HPR.  Useful only for backporting.
 *
 * This function is provided to ease transition from old systems that relied
 * on Panda's original broken HPR calculation.
 */
FLOATNAME(LVecBase3) new_to_old_hpr(const FLOATNAME(LVecBase3) &new_hpr) {
  FLOATNAME(LMatrix3) mat;
  compose_matrix_new_hpr(mat, 
                         FLOATNAME(LVecBase3)(1.0f, 1.0f, 1.0f),
                         FLOATNAME(LVecBase3)::zero(),
                         new_hpr);

  FLOATNAME(LVecBase3) old_scale;
  FLOATNAME(LVecBase3) old_shear;
  FLOATNAME(LVecBase3) old_hpr;

  decompose_matrix_old_hpr(mat, old_scale, old_shear, old_hpr);
  return old_hpr;
}
#endif