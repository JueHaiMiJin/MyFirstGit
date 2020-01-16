#include <iostream>
using namespace std;

class Signleton
{
private: 
    static Signleton* instence;
    Signleton()
    {
        num = 10;
        cout << "创建单例" << endl;
    }
    int num;

public:
    static Signleton* getInstance()
    {
        if(instence == NULL)
            instence = new Signleton();
        return instence;
    }
    ~Signleton()
    {
        cout << "消除当前单例" << endl;
        if(instence != NULL)
            delete instence;
        instence = NULL;
    }
    void Delete();
};

void Signleton::Delete()
{
    if(instence != NULL)
        instence->~Signleton();
}

Signleton* Signleton::instence = NULL;

int main()
{
    std::cout << "Hello world" << std::endl;
    Signleton* stance = Signleton::getInstance();
    //stance->~Signleton();
    stance->Delete();
    return 0;
}

