// printNumber(x) outputs "x", where x is an integer.
#include <functional>
#include <iostream>
#include <condition_variable>
#include <mutex>


using namespace std;

int n = 10;
int cnt = 0;
std::mutex m;
std::condition_variable cond;

void zero(function<void(int)> printNumber) {
	while (cnt < n)
	{
		std::unique_lock<std::mutex> ul(m);
		cond.wait(ul, [&]() {
			return ((cnt % 2) == 0) || (cnt >= n);
		});
		if (cnt < n)
		{
			printNumber(0);
			++cnt;
		}
		ul.unlock();
		cond.notify_all();
	}
}

void even(std::function<void(int)> printNumber) {
	int evenCount = 3;
	int evenNumber = 2;
	while (cnt < n)
	{
		std::unique_lock<std::mutex> ul(m);
		cond.wait(ul, [&]() {
			return (cnt == evenCount) || (cnt >= n);
		});
		if (cnt < n)
		{
			printNumber(evenNumber);
			evenNumber += 2;
			evenCount += 4;
			++cnt;
		}
		ul.unlock();
		cond.notify_all();

	}

}

void odd(function<void(int)> printNumber) {
	int oddCount = 1;
	int oddNumber = 1;
	while (cnt < n)
	{
		std::unique_lock<std::mutex> ul(m);
		cond.wait(ul, [&]() {
			return (cnt == oddCount) || (cnt >= n);
		});
		if (cnt < n)
		{
			printNumber(oddNumber);
			oddNumber += 2;
			oddCount += 4;
			++cnt;
		}
		ul.unlock();
		cond.notify_all();
	}
}

int main()
{
	auto fn = [&](int num) {cout << num;};
	thread t1(zero, fn);
	thread t2(odd, fn);
	thread t3(even, fn);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}