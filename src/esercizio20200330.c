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

unsigned long* fibonacci_array(unsigned int n)
{
	unsigned long* ret = calloc(n + 1, sizeof(unsigned long));
	for (unsigned int i = 0; i <= n; i++)
		ret[i] = fibonacci(i);

	return ret;
}

int main(int argc, char *argv[])
{
	for (unsigned int i = 0; i < 93; i++) {
		printf("Fibonacci(%u)\t=\t%lu\n", i, fibonacci(i));
	}

	unsigned int len = 20;
	unsigned long* fib_array = fibonacci_array(len);
	for (int i = 0; i <= len; i++)
		printf("Reading from array - fibonacci(%u)\t=\t%lu\n", i, fib_array[i]);

	return 0;
}
