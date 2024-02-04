#include <malloc.h>
#include <stdint.h>
#include <stdio.h>

#include "allocator/linalloc.h"

int main() {
  uint8_t *backing_buffer = alloca(sizeof(uint8_t) * 256);
  Arena a = {0};
  arena_init(&a, backing_buffer, 256);

  for (int i = 0; i < 10; i++) {
    int *x;
    float *f;
    char *str;

    arena_reset(&a);

    x = (int *)arena_alloc(&a, sizeof(int));
    f = (float *)arena_alloc(&a, sizeof(float));
    str = (char *)arena_alloc(&a, sizeof(char));

    *x = 123;
    *f = 987;
    memmove(str, "Hello", 5);

    printf("%p: %d\n", x, *x);
    printf("%p: %f\n", f, *f);
    printf("%p: %s\n", str, str);

    str = arena_resize(&a, str, 10, 17);
    memmove(str + 5, " world ve!", 10);
    printf("%p: %s\n", str, str);
  }

  arena_reset(&a);

  return 0;
}
