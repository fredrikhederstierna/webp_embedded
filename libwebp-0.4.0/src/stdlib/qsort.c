/*
 * Code adapted from uClibc-0.9.30.3
 *
 * It is therefore covered by the GNU LESSER GENERAL PUBLIC LICENSE
 * Version 2.1, February 1999
 *
 * Wolfgang Denk <wd@denx.de>
 */

/* This code is derived from a public domain shell sort routine by
 * Ray Gardner and found in Bob Stout's snippets collection.  The
 * original code is included below in an #if 0/#endif block.
 *
 * I modified it to avoid the possibility of overflow in the wgap
 * calculation, as well as to reduce the generated code size with
 * bcc and gcc. */

#include <assert.h>
#include <stdio.h>
#include <string.h>

void qsort(void  *base,
           size_t nel,
           size_t width,
           int (*comp)(const void *, const void *))
{
  size_t wgap, i, j, k;
  char tmp;

  if ((nel > 1) && (width > 0)) {
    assert(nel <= ((size_t)(-1)) / width); /* check for overflow */
    wgap = 0;
    do {
      wgap = 3 * wgap + 1;
    } while (wgap < (nel-1)/3);
    /* From the above, we know that either wgap == 1 < nel or */
    /* ((wgap-1)/3 < (int) ((nel-1)/3) <= (nel-1)/3 ==> wgap <  nel. */
    wgap *= width;                  /* So this can not overflow if wnel doesn't. */
    nel *= width;                   /* Convert nel to 'wnel' */
    do {
      i = wgap;
      do {
        j = i;
        do {
          register char *a;
          register char *b;
          
          j -= wgap;
          a = j + ((char *)base);
          b = a + wgap;
          if ((*comp)(a, b) <= 0) {
            break;
          }
          k = width;
          do {
            tmp = *a;
            *a++ = *b;
            *b++ = tmp;
          } while (--k);
        } while (j >= wgap);
        i += width;
      } while (i < nel);
      wgap = (wgap - width)/3;
    } while (wgap);
  }
}

static int __strcmp(const char *s1, const char *s2) {
  int ret = 0;
  while (!(ret = *(unsigned char *) s1 - *(unsigned char *) s2) && *s2) ++s1, ++s2;
  if (ret < 0)
    ret = -1;
  else if (ret > 0)
    ret = 1;
  return ret;
}

int strcmp_compar(const void *p1, const void *p2)
{
  return __strcmp(*(const char **)p1, *(const char **)p2);
}
