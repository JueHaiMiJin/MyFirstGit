#include <iostream>
#include <mutex>
#include <thread>
#include <list>
using namespace std;

class Mythread{
private:
	list<int> mylist;
	mutex mtx;
public:
	Mythread(){};
	void WriteList()
	{
		mtx.lock();
		for(int i = 0; i < 1000; i++)
		{
			cout << "write list :"<< i <<endl;
			mylist.push_back(i);
		}
		mtx.unlock();
	}
	void ReadList()
	{
		mtx.lock();
		for(int i = 0; i < 1000; i++)
		{
			if(!mylist.empty())
			{
				cout<<"Read:" << mylist.front()<< endl;
				mylist.pop_front();
			}
			else
			{
				cout << "Message List is empty\n";
			}
		}
		mtx.unlock();
	}
};

int main(int argc, char const *argv[])
{
	Mythread mythread;
	thread pread(&Mythread::ReadList, &mythread);
	thread pwrite(&Mythread::WriteList, &mythread);
	pwrite.join();
	pread.join();
	return 0;
}