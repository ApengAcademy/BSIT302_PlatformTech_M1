#include "pch.h"
#include <iostream>
#include <thread>       
#include <atomic>       

using namespace std;
atomic<bool> result1(false);
atomic<bool> result2(false);
atomic<bool> result3(false);

atomic<int> counter1(0);
atomic<int> counter2(0);
atomic<int> counter3(0);


void Lotterresult1(int id)
{
	while (!result1) {
		this_thread::yield();
	}
	for (volatile int i = 0; i < 55; ++i)
	{
		++counter1;
		if (counter1 <= 6)
			cout << id + 1 << " ";
	}
}

void Lotterresult2(int id)
{
	while (!result2) {
		this_thread::yield();
	}
	for (volatile int i = 0; i < 55; ++i)
	{
		++counter2;
		if (counter2 <= 6)
			cout << id + 1 << " ";
	}
}

void Lotterresult3(int id)
{
	while (!result3) {
		this_thread::yield();
	}
	for (volatile int i = 0; i < 55; ++i)
	{
		++counter3;
		if (counter3 <= 6)
			cout << id + 1 << " ";
	}
}


int main()
{
	thread threads1[55];
	thread threads2[55];
	thread threads3[55];

	cout << "The Lottery results are the following: \n";
	cout << "\n";
	cout << "The Lottery Result 1:";
	cout << "\n";
	for (int i = 0; i < 55; ++i) threads1[i] = thread(Lotterresult1, i);
	result1 = true;
	for (auto& th1 : threads1) th1.join();
	cout << "\n";

	cout << "\n";
	cout << "The Lottery Result 2: \n";
	for (int i = 0; i < 55; ++i) threads2[i] = thread(Lotterresult2, i);
	result2 = true;
	for (auto& th2 : threads2) th2.join();
	cout << "\n";

	cout << "\n";
	cout << "The Lottery Result 3: \n";
	for (int i = 0; i < 55; ++i) threads3[i] = thread(Lotterresult3, i);
	result3 = true;
	for (auto& th3 : threads3) th3.join();
	cout << "\n";


	return 0;
}

