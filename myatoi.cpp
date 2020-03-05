#include <iostream>
#include <string>

using namespace std;

class Slution
{
public:
    int myAtoi(string str)
    {
        int flag = 0;
        int num = 0;
        int i = 0;
        while(i < str.length())
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                break;
            }
            i++;
        }
        for(int j = 0; j < i ; j++)
        {
            if(str[j] >= 'A' && str[j] <= 'z')
            {
                return 0;
            }
        }
        if(i == 0)
        {
            flag = 1;
        }
        else
        {
            if(str[i-1] == '+' && str[i-2] != '+' && str[i-2] != '-')
            {
                flag = 1;
            }
            
            else if(str[i-1] == '-' && str[i-2] != '+' && str[i-2] != '-')
            {
                flag = 0;
            }
            else if(str[i-1] == ' ')
            {
                flag = 1;
            }
            else if(str[i-1] != '+' || str[i-1] != '-' || str[i-1] != ' ')
            {
                return 0;
            }
        }
        for(int j = i ; j < str.length(); j++)
        {
            if(str[j] < '0' || str[j] >'9')
            {
                break;
            }
            if(num > 214748364 || (num == 214748364 && str[j] > '0') )
            {
                if(flag == 1)
                    return 2147483648;
                else
                    return -2147483648;
            }
            num = num*10+str[j]-'0';
        }
        if(flag == 1)
            return num;
        else
            return -num;
    }
};

int main()
{
    string str;
    cin >> str;
    Slution tq;
    int num;
    num = tq.myAtoi(str);
    cout << "result : " << num << endl;
    return 0;
}
