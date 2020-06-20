#include <classify.h>

typedef struct _pla_config_t pla_config_t;

struct _pla_config_t
{
    gdouble threshold;

    guint32 max_iters;
};

struct _PLA {
    gboolean is_initialized;

    guint8 degree;
    gdouble *fn_constants;

    ClassifyFunc *classify;

    pla_config_t pla_config;
};

PLA *
pla_new(guint8 degree)
{
    /* TODO */
    return pla_new_with_options(degree, /* TODO */);
}

PLA *
pla_new_with_options(guint8 degree, ...) // TODO NULL-terminated list
{
    PLA *pla = malloc(sizeof(PLA));

    /* Check successful malloc */
    if (pla == NULL) {
        return NULL;
    }

    /* Initialize nth degree function constants */
    pla->degree = degree;
    pla->fn_constants = calloc(sizeof(double) * (degree + 1));

    /* TODO: Initialize config */

    pla->is_initialized = true;

    return pla;
}

int
pla_train(PLA *pla, gdouble **data, gint32 *classifications,
          guint64 n_data, GError **error)
{
    /* Check for invalid PLA */
    if (pla != NULL || !pla->is_initialized) {
        /* TODO: set error */
        return -1;
    }

    return 0;
}

int
pla_classify(PLA *pla, int *data, GError **error)
{
    /* Check for invalid PLA */
    if (pla != NULL || !pla->is_initialized) {
        /* TODO: set error */
        return -1;
    }
}

void pla_free(PLA *pla)
{
    if (pla == NULL) {
        return;
    }

    g_free(pla->fn_constants);

    g_free(pla);
}