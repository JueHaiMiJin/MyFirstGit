#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton *Instance()
    {
        if(instance == NULL)
            instance = new Singleton();
        return instance;
    }
    ~Singleton()
    {
        cout << "销毁单例" << endl;
    }
private:
    Singleton()
    {
        cout << "产生单例" << endl;
    }
    static Singleton *instance;
};

Singleton* Singleton::instance = NULL;

int main()
{
    std::cout << "Hello world" << std::endl;
    Singleton *tt = Singleton::Instance();
    delete tt;
    return 0;
}

