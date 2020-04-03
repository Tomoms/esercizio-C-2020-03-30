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

/*
 * Fills an array with the first n + 1 values of
 * Fibonacci's sequence.
 * Returns a pointer to the first element of the array.
 */
unsigned long* fibonacci_array(unsigned int n)
{
	unsigned long* ret = calloc(n + 1, sizeof(unsigned long));
	if (ret == NULL) {
		perror("calloc() failed\n");
		exit(EXIT_FAILURE);
	}

	for (unsigned int i = 0; i <= n; i++)
		ret[i] = fibonacci(i);

	return ret;
}

unsigned long* array_copy(unsigned long* ptr, int size)
{
	unsigned long* ret = calloc(size, sizeof(unsigned long));
	if (ret == NULL) {
		perror("calloc() failed\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size; i++)
		ret[i] = ptr[i];

	return ret;
}

// unsigned long swapper
void swap(unsigned long* ptr1, unsigned long* ptr2)
{
	unsigned long tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

// Makes use of swap() to perform an in-place inversion of an array
void array_reverse(unsigned long* ptr, int size)
{
	int i = 0, j = size - 1;
	while (i < j) {
		swap(&ptr[i], &ptr[j]);
		i++;
		j--;
	}
}

void bubble_sort(unsigned long* array, int size)
{
	int n = size, new_n;
	while (n > 1) {
		new_n = 0;
		for (int i = 1; i < n; i++) {
			if (array[i - 1] > array[i]) {
				swap(&array[i - 1], &array[i]);
				new_n = i;
			}
		}
		n = new_n;
	}
}

int main(int argc, char *argv[])
{
	int n = 39;
	unsigned long* fibonacci_result = fibonacci_array(n);
	unsigned long* fibonacci_result_copy = array_copy(fibonacci_result, n + 1);
	array_reverse(fibonacci_result_copy, n + 1);
	bubble_sort(fibonacci_result_copy, n + 1);

	for (int i = 0; i <= n; i++) {
		printf("Original:\t%lu\n", fibonacci_result[i]);
		printf("Manipulated:\t%lu\n", fibonacci_result_copy[i]);
	}

	return 0;
}
