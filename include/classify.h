/**
 * Methods for classification
 */
enum Classifications
{
    CLASSIFICATIONS_BINARY,
};

typedef int (ClassifyFunc) (double);

/*
 * A set of common classification functions
 */
inline int classify_binary(float val);