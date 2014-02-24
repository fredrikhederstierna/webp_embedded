
/* func can be NULL, in which case no function information is given.  */
void __assert_func(const char *file,
                   int line,
                   const char *func,
                   const char *failedexpr)
{
  /*
    fiprintf(stderr,
	   "assertion \"%s\" failed: file \"%s\", line %d%s%s\n",
	   failedexpr, file, line,
	   func ? ", function: " : "", func ? func : "");*/
  while (1);
  /* NOTREACHED */
}
