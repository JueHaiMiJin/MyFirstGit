#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Slution
{
public:
	std::vector<std::vector<int> > findContinueSequence(int target)
	{
		// std::vector<std::vector<int> > my_ret_vector;
		// int my_target = target;
		// int i = 1;
		// int j = target - 1;
		// while(i != j)
		// {
		// 	if((long long int)(i+j)*(j-i+1)/2 == my_target)
		// 	{
		// 		std::vector<int> tmp;
		// 		for(int k = i ; k <= j; k++)
		// 		{
		// 			tmp.push_back(k);
		// 		}
		// 		my_ret_vector.push_back(tmp);
		// 		i++;
		// 		j = target -1;
		// 	}
		// 	else if((long long int)(i+j)*(j-i)/2 > my_target)
		// 	{
		// 		j--;
		// 	}
		// 	else
		// 	{
		// 		i++;
		// 		j = target -1;
		// 	}
		// }
		// return my_ret_vector;
		vector<vector<int>> res;
        int i = 1; 
        while(target > 0)
        {
            target -= i++;
            if(target > 0 && target % i == 0)
            {
                vector<int> tmp;
                for(int j = 0; j < i; j++) 
                {
                	cout << "the target  is " << target <<"the i is " << i << " the num is " << target / i + j << endl;
                	tmp.push_back(target / i + j);
                }
                res.push_back(tmp);
            }
        }
        reverse(res.begin(), res.end());
        return res;
	}
};

int main()
{
	int num;
	cin >> num;
	Slution slu;
	std::vector<std::vector<int> > res;
	res = slu.findContinueSequence(num);
	for(int i = 0 ; i < res.size(); i++)
	{
		cout << "res is :[";
		for(int j = 0; j <res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << "]" << endl;
	}
	return 0;
}