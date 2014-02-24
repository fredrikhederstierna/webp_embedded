#include <stdio.h>

void * memset(void *__restrict p, int c, size_t n)
{
  char *pb = (char *) p;
  char *pbend = pb + n;
  while (pb != pbend) *pb++ = c;
  return p;
}
void * memcpy(void *__restrict dst, const void *__restrict src, size_t n)
{
  char *s = (char*)src;
  char *d = (char*)dst;
  while (n--)
  {
    *d++ = *s++;
  }
  return dst;
}
int memcmp(const void *buffer1, const void *buffer2, int count)
{
  const unsigned char *p1 = buffer1;
  const unsigned char *p2 = buffer2;
  int i;

  for (i = 0; i < count; i++)
  {
    if (p1[i] < p2[i]) return -1;
    if (p1[i] > p2[i]) return 1;
  }

  return 0;
}
void *memmove(void *v_dst, const void *v_src, size_t c)
{
	const char *src = v_src;
	char *dst = v_dst;

	if (!c)
		return v_dst;

	/* Use memcpy when source is higher than dest */
	if (v_dst <= v_src)
		return memcpy(v_dst, v_src, c);

	/* copy backwards, from end to beginning */
	src += c;
	dst += c;

	/* Simple, byte oriented memmove. */
	while (c--)
		*--dst = *--src;

	return v_dst;
}
