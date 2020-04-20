#include <iostream>
#include <string>
#include <string.h>
#include <thread>
#include <list>
#include <mutex>
using namespace std;

class MyStu
{
private:
	MyStu(){};
	static  MyStu* stu;
	list<int> mylist;
	mutex mtx;
public:
	void print()
	{
		cout << "I have create the std object\n";
	}
	static MyStu* GetInstence()
	{
		if(stu == NULL)
			stu = new MyStu();
		return stu;
	}
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
	}
};

MyStu* MyStu::stu = NULL;

int main(int argc, char* argv[])
{
	MyStu *newproject = MyStu::GetInstence();
    newproject->print();
    thread pread(newproject->ReadList,newproject);
    thread pwrite(newproject->WriteList,newproject);
    pread.join();
    pwrite.join();
	return 0;
}
