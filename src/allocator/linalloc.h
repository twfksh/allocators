#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifndef DEFAULT_ALIGNMENT
#define DEFAULT_ALIGNMENT (2 * sizeof(void *))
#endif

typedef struct Arena {
  uint8_t *buf;
  size_t buf_length;
  size_t prev_offset;
  size_t curr_offset;
} Arena;

void arena_init(Arena *a, void *backing_buf, size_t backing_buf_length);
void *arena_alloc_align(Arena *a, size_t size, size_t align);
void *arena_alloc(Arena *a, size_t size);
void *arena_resize_align(Arena *a, void *old_memory, size_t old_size,
                         size_t new_size, size_t align);
void *arena_resize(Arena *a, void *old_memory, size_t old_size,
                   size_t new_size);
void arena_reset(Arena *a);

void arena_free(Arena *a, void *ptr);
