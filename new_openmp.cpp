//
// Created by admin on 2022/1/30.
//
#include <chrono>
#include <vector>
#include <iostream>
#include <atomic>

unsigned long add(const std::vector<int>& vec, int start, int end)
{
	unsigned long res = 0;
	if (vec.size() < end)
	{
		end = vec.size();
	}
	for (unsigned i = start; i < end; ++i)
	{
		res += vec.at(i);
	}
	return res;
}

int main()
{
	using namespace std;
	std::vector<int> coll;
	unsigned long size = 30000000;
	coll.reserve(size);
	for (unsigned i = 0; i < size; ++i)
	{
		coll.push_back(i % 3 >> 5 + 2);
	}

	auto n = coll.size();
	std::atomic_long sum(0);
	auto start = std::chrono::steady_clock::now();
#pragma omp parallel for num_threads(12)
	for (unsigned long i = 0; i < n; i = i + coll.size() / 12)
	{
		add(coll, i, i + coll.size() / 12);
	}
	auto end = std::chrono::steady_clock::now();
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "elapsed time: " << int_ms.count() << "ms\n";
	return 0;
}