/*
判断一个数字是不是回文数字
*/

#include <iostream>
#include <string>

using namespace std;

class Slution
{
public:
    bool isPalindrome(int x)
    {
	int my_x = x;
        if(x < 0)
	    return false;
	long long int res = 0;
        while(my_x)
        {
	    int tmp = my_x % 10;
	    res = res*10 + tmp;
	    my_x = my_x / 10;
	}
        if(res == x)
	    return true;
        else
	    return false;
    }
};

int main()
{
    int x = 121;
    cin >> x;
    Slution slu;
    bool ret = slu.isPalindrome(x);
    if(ret == true)
    	cout << "the result is : true " <<endl;
    else
    	cout << "the result is : false " <<endl;
    return 0;
}
