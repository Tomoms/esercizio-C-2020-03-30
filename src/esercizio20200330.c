#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
 * Returns the n-th element of Fibonacci's sequence.
 * Works properly for n <= 93.
 */
unsigned long fibonacci(unsigned int n)
{
	if (n < 2)
		return n;

	unsigned long nums[3] = {0, 1, 1};
	for (unsigned int i = 3; i <= n; i++) {
		nums[0] = nums[1];
		nums[1] = nums[2];
		nums[2] = nums[0] + nums[1];
	}

	return nums[2];
}

int main(int argc, char *argv[])
{
	for (unsigned int i = 0; i < 93; i++) {
		printf("Fibonacci(%u)\t=\t%lu\n", i, fibonacci(i));
	}
	return 0;
}
