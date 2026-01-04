/*
 * array usually allocate memory before program starts.
 *
 * If programmer allocates memory and frees them when it's running
 * It's called Dynamic Memory Allocation.
 *
 */

/*
 * malloc
 * returns start address of array after allocation.
 * If it's failed, it returns NULL.
 *
 * #include <stdlib.h>
 *
 * void *malloc(size_t size);
 * 
 * size: memory size
 *
 * example;
 * char *ptr = malloc(sizeof(char) * 100);
 */

/*
 * calloc
 *
 * returns start address of array after allocation.
 * if it's failed, it returns NULL.
 * calloc also initialises memories values as 0.
 *
 * #include <stdlib.h>
 *
 * void *calloc(size_t nmemb, size_t size);
 * 
 * nmemb: numbers of array elements
 * size: size of each element
 *
 * char *ptr = calloc(10,20);
 */

/*
 * realloc
 *
 * re-allocated memory and returns address.
 * returns NULL when it's failed.
 *
 * #include <stdlib.h>
 *
 * void *realloc (void *ptr, size_t size);
 *
 * ptr: pointer of memory to reallocate.
 * size: size of memory to allocate.
 *
 * char *ptr, *new;
 * ptr = malloc(sizeof(char) * 100);
 * new = realloc(ptr,100);
 */

/*
 * free
 *
 * free memory allocation.
 *
 * #include <stdlib.h>
 *
 * void free(void *ptr);
 *
 * ptr: address to free.
 */
