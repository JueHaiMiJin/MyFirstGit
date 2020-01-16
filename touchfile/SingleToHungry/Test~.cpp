#include <iostream>
using namespace std;

class Singleton
{
public:
    Singleton();
    ~Singleton();
    char* mun;
};
Singleton::Singleton()
{
    mun = new char[1000];
    cout << "创建单例。。。 " << endl;
}
Singleton::~Singleton()
{
    cout << "析构函数" << endl;
    if(mun != NULL)
        delete[] mun;
    mun = NULL;
}
int main()
{
    int b = 10;
    std::cout << "Hello world" << std::endl;
    //Singleton *tim = new Singleton();
    //delete tim;
    Singleton tim;
    return 0;
}

