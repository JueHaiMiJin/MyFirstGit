#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "创建了一个单例对象" << endl;
    }
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
    ~Singleton()
    {
        cout << "销毁一个单例对象" << endl;
    }
    static Singleton* instance;

public:
    static Singleton* getInstance();
        
private:
    class Garbo
    {
    public:
        Garbo(){}
        ~Garbo()
        {
            if(instance != NULL)
            {
                delete instance;
                instance = NULL;
            }
        }
    
    };
    static Garbo _garbo;
};

Singleton* Singleton::instance = NULL;
Singleton::Garbo Singleton::_garbo;

Singleton* Singleton::getInstance()
{
    if(instance == NULL)
    {
        instance = new Singleton();
    }
    return instance;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    Singleton* instance1 = Singleton::getInstance();
    return 0;
}

