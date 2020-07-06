/**
 * TODO: Copyright
 */

#ifndef __OPTIMAL_PLA_H__
#define __OPTIMAL_PLA_H__

#include <glib-object.h>
#include <gerror.h>

#include "classify.h"

#define OPTIMAL_PLA_DEGREE          "degree"
#define OPTIMAL_PLA_POLY_FUNC       "poly-func"
#define OPTIMAL_PLA_CLASSIFY_FUNC   "classify-func"

/*
 * Default values
 */
#define OPTIMAL_PLA_DEFAULT_THRESHOLD 0.5
#define OPTIMAL_PLA_DEFAULT_MAX_ITERS 1000

G_BEGIN_DECLS

#define OPTIMAL_TYPE_PLA optimal_pla_get_type()
G_DEFINE_TYPE_WITH_PRIVATE(OptimalPla, optimal_pla, GObject)

struct {
    gdouble threshold;

    guint32 max_iters;
} optimal_pla_config_t;

struct _OptimalPla {
    GObject parent_instance;

    gsl_vector *gv;

    ClassifyFunc *classify;

    optimal_pla_config_t optimal_pla_config;
};

/**
 * TODO: define PLA errors
 */

OptimalPla *optimal_pla_new(size_t degree);

gboolean optimal_pla_train(OptimalPla *optimal_pla,
                           gdouble **data,
                           gint32 *classifications);

gint32 pla_classify(OptimalPla *optimal_pla, gdouble *data);

void pla_free(OptimalPla *optimal_pla);

G_END_DECLS

#endif /* __OPTIMAL_PLA_H__ */