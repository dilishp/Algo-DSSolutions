#include "pch.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex m;
condition_variable cnd;
int previousThreadId;

void print(int threadID)
{

	for (size_t i = 0; i < 20; i++)
	{
		unique_lock<std::mutex> ul(m);
		cnd.wait(ul, [&]()->bool {
			if (threadID != previousThreadId)
				return true;
			else
				return false;
		});
		previousThreadId = threadID;
		cout << "Thread # " << threadID << " Executing...\n";
		ul.unlock();
		cnd.notify_one();

	}
}

int main()
{
	thread t[2];
	for (size_t i = 0; i < 2; i++)
	{
		t[i] = thread(print, i);
	}

	for (size_t i = 0; i < 2; i++)
	{
		t[i].join();
	}
	return 0;
}

//Pthread Version
// Example program
//#include <iostream>
//#include <pthread.h>
//
//
//int count;
//int turn = 0; // Shared variable used to implement strict alternation
//int previous_arg = 1;
//pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
//
//void* myFunction(void* arg)
//{
//	int actual_arg = *((int*)arg);
//
//	for (unsigned int i = 0; i < 10; ++i) {
//
//		// TODO:
//		// Make sure that the thread waits for its turn
//		// before it enters the critical region.
//		//
//		// HINT: The thread ID is stored in actual_arg
//
//
//
//		// Beginning of the critical region
//		pthread_mutex_lock(&lock);
//		while (previous_arg == actual_arg)
//			pthread_cond_wait(&cond, &lock);
//		previous_arg = actual_arg;
//		count++;
//		std::cout << "Thread #" << actual_arg << " count = " << count << std::endl;
//		pthread_mutex_unlock(&lock);
//		pthread_cond_signal(&cond);
//
//		// End of the critical region
//
//
//
//		// TODO:
//		// Make sure that the other thread gets a turn
//		//
//		// HINT: There are only two threads: 0 and 1
//		// You can use the C++ NOT operator (!)
//		// to toggle back and forth.
//
//
//	}
//
//	pthread_exit(NULL);
//}
//
//
//// HINT: It is not necessary to make any changes in main()
//int main()
//{
//	int rc[2];
//	pthread_t ids[2];
//	int args[2];
//
//	count = 0;
//	for (unsigned int i = 0; i < 2; ++i) {
//		args[i] = i;
//		rc[i] = pthread_create(&ids[i], NULL, myFunction, (void*)&args[i]);
//	}
//
//	for (unsigned int i = 0; i < 2; ++i) {
//		pthread_join(ids[i], NULL);
//	}
//
//	std::cout << "Final count = " << count << std::endl;
//	pthread_exit(NULL);
//}
