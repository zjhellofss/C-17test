//
// Created by Fushenshen on 2022/2/2.
//
#include <omp.h>
#include <iostream>
#include "tick.h"

float cpuPI(int num)
{
	float sum = 0.f;
//#pragma omp parallel for shared(num, sum)
//	for (int i = 0; i < num; ++i)
//	{
//		temp = (i + 0.5f) / num;
//#pragma omp atomic
//		sum += 4 / (1 + temp * temp);
//	}

#pragma omp parallel  for default(none) shared(num)  reduction(+:sum)
	for (int i = 0; i < num; ++i)
	{
		float temp = (i + 0.5f) / num;
		temp = 4 / (1 + temp * temp);
		sum += temp;
	}
	return sum / num;
}

int main()
{
	TICK(PI);
	auto pi = cpuPI(1500);
	TOCK(PI);

	printf("PI: %f", pi);
	return 0;
}