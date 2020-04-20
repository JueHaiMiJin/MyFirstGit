#include <iostream>
#include <vector>
using namespace std;
class Slution
{
public:
	bool canThreePartsEqualSum(vector<int>& A) 
	{
		if(A.size() <3 ||A.size() > 5000)
		{
			cout << " fale return  " << endl;
            return false;
		}
        int middle = 0;
        int sum = 0;
        int num1 = 0,num2 = 0;
        for(int i = 0 ; i < A.size(); i++)
        {
            sum += A[i];
            cout << " sum is:" << sum << endl;
        }
        if((sum/3 != 0) && (sum%3 == 0) || sum == 0)
        {
            middle = sum / 3;
        }
        else
            return false;
        cout << "sum is :" << sum << " and middle is : "<< middle << endl;
        int front = 0;
        int rear = A.size()-1;
        while(front < rear)
        {
        	if(num1 != middle )
        	{
        		if(num1+A[front] != middle)
            	{   
               		num1 += A[front]; 
                	front++;
                	cout << "the front is:" << front << " and the num1 is:" << num1 <<endl;   
            	}
            	else
            	{
            		num1+=A[front];
            		cout << "Now the num1 is:" << num1 << endl;
            	}
        	}
            if(num2 != middle)
            {
            	if(num2+A[rear] != middle && num2 != middle)
            	{
                	num2 += A[rear];
                	rear--;
                	cout <<"the rear is:" << rear << " and the num2 is:" << num2 <<endl;
            	}
            	else
            	{
            		num2+=A[rear];
            		cout << "Now the num2 is:" << num2 << endl;
            	}
            }
            if(num1 == middle && num2 ==middle)
                return true;
        }
        cout << "num1 is ：" << num1 << " num2 is:" << num2 <<endl;
        if(num1 == middle && num2 ==middle && num1 == num2)
                return true;
        else
            return false;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> v={1,-1,1,-1};
	Slution slu;
	bool myret = slu.canThreePartsEqualSum(v);
	cout << " Myresult is :" << myret << endl; 
	return 0;
}