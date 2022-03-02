//
// Created by Fushenshen on 2022/2/2.
//
#include <iostream>
#include <omp.h>
#include "tick.h"

void test()
{
	int a = 0;
	clock_t t1 = clock();
	for (int i = 0; i < 100000000; i++)
	{
		a = i + 1;
	}
	clock_t t2 = clock();
	printf("Time = %ld\n", t2 - t1);
}

int main312(int argc, char* argv[])
{
#pragma omp parallel for
	for (int i = 0; i < 10; i++)
	{
		printf("i = %d\n", i);
	}
	return 0;
}

int ma12in()
{
	clock_t t1 = clock();
#pragma omp parallel for
	for (int j = 0; j < 2; j++)
	{
		test();
	}
	clock_t t2 = clock();
	printf("Total time = %ld\n", t2 - t1);
	test();
	return 0;
}

int ma312in()
{
#pragma omp parallel num_threads(4)
	{
		printf("Hello, World!\n");
	}


	int j = 0;
#pragma omp parallel private(j)
	{
#pragma omp for
		for (j = 0; j < 4; j++)
		{
			printf("j = %d, ThreadId = %d\n", j, omp_get_thread_num());
		}

#pragma omp for
		for (j = 0; j < 4; j++)
		{
			printf("j = %d, ThreadId = %d\n", j, omp_get_thread_num());
		}
	}

	return 0;
}

int mai123n(int argc, char* argv[])
{
#pragma omp parallel sections  num_threads(3)
	{
#pragma omp section
		{
			printf("section 1 ThreadId = %d\n", omp_get_thread_num());
		}

#pragma omp section
		{
			printf("section 2 ThreadId = %d\n", omp_get_thread_num());

		}

#pragma omp section
		{
			printf("section 3 ThreadId = %d\n", omp_get_thread_num());

		}
	}
	return 0;
}

int main1231()
{
	int k = 100;
#pragma omp parallel for private(k)
	for (k = 0; k < 10; k++)
	{
		printf("k=%d\n", k);
	}
	printf("last k=%d\n", k);
	return 0;
}

int mai12n()
{
	int i, sum = 100;
#pragma omp parallel for reduction(+:sum)
	for (i = 0; i < 1000; ++i)
	{
		sum += i;
	}
	printf("sum:%d\n", sum);
	return 0;
}

#define COUNT    10000

int m12ain(int argc, char* argv[])
{
	int sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < COUNT; i++)
	{
		sum = sum + i;
	}

	printf("%d\n", sum);

	return 0;
}


int counter = 0;
#pragma omp threadprivate(counter)

int increment_counter()
{
	counter++;
	return (counter);
}

int mai124n(int argc, char* argv[])
{
	int iterator;
#pragma omp parallel sections copyin(counter)
	{
#pragma omp section
		{
			int count1;
			for (iterator = 0; iterator < 100; iterator++)
			{
				count1 = increment_counter();
			}
			printf("count1 = %ld\n", count1);
		}
#pragma omp section
		{
			int count2;
			for (iterator = 0; iterator < 200; iterator++)
			{
				count2 = increment_counter();
			}
			printf("count2 = %ld\n", count2);
		}
	}
	printf("counter = %ld\n", counter);
}

int counter1 = 0;
#pragma omp threadprivate(counter1)

int increment_counter1()
{
	counter1++;
	return (counter1);
}

int main()
{
#pragma omp parallel num_threads(4)
	{
		int count;
#pragma omp single copyprivate(counter1)
		{
			counter = 50;
		}
		count = increment_counter1();
		printf("ThreadId: %ld, count = %ld\n", omp_get_thread_num(), count);
	}
}
