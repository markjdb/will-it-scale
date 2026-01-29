#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>

#define SIZE (1UL * 1024)

char *testcase_description = "malloc/free of 1kB";

void testcase(unsigned long long *iterations, unsigned long nr)
{
	while (1) {
		void *addr = malloc(SIZE);
		assert(addr != NULL);
		__asm __volatile("" : : "r" (addr) : "memory");
		explicit_bzero(addr, SIZE);
		free(addr);

		(*iterations)++;
	}
}
