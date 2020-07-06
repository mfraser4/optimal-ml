#include "optimal_pla.h"

typedef struct {

} OptimalPlaPrivate;

enum {
    PROP_POLY_FUNCTION = 1,
    PROP_CLASSIFY_FUNC,
    PROP_MAX_ITERS,
    N_PROPERTIES
};

/*******************************************************************************
 * OptimalPla GObject methods                                                  *
 ******************************************************************************/

static GParamSpec *obj_properties[N_PROPERTIES] = { NULL, };

static void
viewer_file_set_property (GObject      *object,
                          guint         property_id,
                          const GValue *value,
                          GParamSpec   *pspec)
{
    OptimalPla *self = OPTIMAL_PLA(object);

    switch ((OptimalPlaProperty) property_id) {
        case PROP_POLY_FUNCTION:
            /* Setting new polynomial fn degree clears existing one */
            g_clear_pointer(&self->gv, gsl_vector_free);
            self->gv = g_value_get_pointer(value);
            break;

        case PROP_ZOOM_LEVEL:
            self->zoom_level = g_value_get_uint (value);
            g_print ("zoom level: %u\n", self->zoom_level);
            break;

        default:
            /* We don't have any other property... */
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
            break;
    }
}

static void
optimal_pla_get_property (GObject    *object,
                          guint       property_id,
                          GValue     *value,
                          GParamSpec *pspec)
{
    OptimalPla *self = OPTIMAL_PLA(object);

    switch ((OptimalPlaProperty) property_id) {
        case PROP_POLY_FUNCTION:
            g_value_set_pointer(value, self->gv);
            break;

        case PROP_ZOOM_LEVEL:
            g_value_set_uint (value, self->zoom_level);
            break;

        default:
            /* We don't have any other property... */
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
            break;
    }
}

static void
optimal_pla_class_init(OptimalPlaClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS(klass);

    object_class->set_property = optimal_pla_set_property;
    object_class->get_property = optimal_pla_get_property;

    /* TODO: install properties */
    obj_properties[PROP_FILENAME] =
        g_param_spec_string("filename",
                            "Filename",
                            "Name of the file to load and display from.",
                            NULL  /* default value */,
                            G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);

    obj_properties[PROP_ZOOM_LEVEL] =
        g_param_spec_uint("zoom-level",
                          "Zoom level",
                          "Zoom level to view the file at.",
                          0  /* minimum value */,
                          10 /* maximum value */,
                          2  /* default value */,
                          G_PARAM_READWRITE);

    g_object_class_install_properties(object_class,
                                      N_PROPERTIES,
                                      obj_properties);
}

static void
optimal_pla_init(OptimalPla *self)
{
    self->classify = classify_binary;

    /* Set config to default values */
    self->optimal_pla_config.threshold = OPTIMAL_PLA_DEFAULT_THRESHOLD;
    self->optimal_pla_config.max_iters = OPTIMAL_PLA_DEFAULT_MAX_ITERS;
}

static void
optimal_pla_dispose(GObject *gobject)
{
    OptimalPla *self = OPTIMAL_PLA(gobject);
    OptimalPlaPrivate *priv = optimal_pla_get_instance_private(self);

    g_clear_pointer(&self->gv, gsl_vector_free);

    G_OBJECT_CLASS(optimal_pla_parent_class)->dispose(gobject);
}

static void
viewer_file_finalize (GObject *gobject)
{
    G_OBJECT_CLASS(viewer_file_parent_class)->finalize(gobject);
}

/*******************************************************************************
 * Header methods                                                              *
 ******************************************************************************/

OptimalPla *
optimal_pla_new(size_t degree)
{
    /* Vector should be degree + 1 to account for c_0 */
    gsl_vector *gv = gsl_vector_calloc(degree + 1);
    return optimal_pla_new_with_vector(gv);
}

OptimalPla *
optimal_pla_new_rand_range(size_t degree,
                           gdouble rand_start,
                           gdouble rand_stop)
{

}

OptimalPla *
optimal_pla_new_with_vector(gsl_vector *gv)
{
    g_return_val_if_fail(gv != NULL, NULL);

    return g_object_new(OPTIMAL_TYPE_PLA,
                        OPTIMAL_PLA_POLY_FUNCTION, gv,
                        NULL);
}

gboolean
optimal_pla_train_rand(OptimalPla *pla,
                       gsl_matrix *matrix,
                       gdouble     rand_start,
                       gdouble     rand_stop,
                       GError    **error)
{

}

gboolean
optimal_pla_train(OptimalPla *pla,
                  gsl_matrix *matrix,
                  GError    **error)
{
    gboolean params_are_valid = pla != NULL &&
                                data != NULL &&
                                classifications != NULL;

    g_return_val_if_fail(params_are_valid, FALSE);

    return TRUE;
}

gint32
optimal_pla_classify(OptimalPla *pla,
                     gint32     *data,
                     GError    **error)
{
    g_return_val_if_fail(pla != NULL && data !=NULL && error != NULL, 0);
}