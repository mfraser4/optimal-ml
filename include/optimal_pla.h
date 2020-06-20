/**
 * TODO: Copyright
 */

#ifndef __OPTIMAL_PLA_H__
#define __OPTIMAL_PLA_H__

#include <glib-object.h>

/**
 * TODO: define PLA errors
 */

/**
 * TODO: PLA options (enum?)
 */

/*
 * Default values
 */
#define OPTIMAL_PLA_DEFAULT_THRESHOLD 0.5
#define OPTIMAL_PLA_DEFAULT_MAX_ITERS 1000

G_BEGIN_DECLS

#define OPTIMAL_TYPE_PLA optimal_pla_get_type ()
G_DECLARE_FINAL_TYPE (OptimalPla, optimal_pla, OPTIMAL, PLA, GObject)

/*
 * Will create optimal_pla_get_type and set optimal_pla_parent_class
 */
G_DEFINE_TYPE (OptimalPla, optimal_pla, G_TYPE_OBJECT)

OptimalPla *optimal_pla_new(guint8 degree);

gboolean optimal_pla_train(OptimalPla *optimal_pla,
                           gdouble **data,
                           gint32 *classifications);

gint32 pla_classify(OptimalPla *optimal_pla, gdouble *data);

void pla_free(OptimalPla *optimal_pla);

G_END_DECLS

#endif __OPTIMAL_PLA_H__