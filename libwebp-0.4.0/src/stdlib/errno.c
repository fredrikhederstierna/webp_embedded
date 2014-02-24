
// this seems needed for linking with libm since some math funcs sets errno.
static int __err;
int *__errno(void) { return &__err; }
