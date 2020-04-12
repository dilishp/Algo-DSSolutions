#include "pch.h"
#include <iostream>
#include <queue>
#include <mutex>
#include <thread>

std::mutex mx1;
std::queue<int> productQueue;
std::condition_variable conscond;
int produceCnt = 0;

void producer()
{
	while (true)
	{
		if (produceCnt == 25)
			break;
		std::unique_lock<std::mutex> prodLock(mx1);
		productQueue.push(produceCnt);
		std::cout << "Product Produced : " << produceCnt << std::endl;
		produceCnt++;
		prodLock.unlock();
		conscond.notify_one();
		
	}
}

void consumer()
{
	while (true)
	{
		if (productQueue.empty())
			break;

		std::unique_lock<std::mutex> consLock(mx1);
		conscond.wait(consLock, []() {
			return !productQueue.empty();
		});
		int product = productQueue.front();
		std::cout << "Product Consumed    :" << product<<std::endl;
		productQueue.pop();
		consLock.unlock();
	}

}

void main()
{
	std::thread producerThread(producer);
	std::thread consumerThread(consumer);

	producerThread.join();
	consumerThread.join();

}