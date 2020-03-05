#include <iostream>
#include <vector>
using namespace std;

class Slution
{
public:
	vector<int> distributeCandies(int candies, int num_people)
	{
		std::vector<int> my_vector(num_people, 0);
		int flag = 0;
		while(candies)
		{
			for(int i = 0; i < num_people; i++)
			{
				int tmp = i + 1 + flag*num_people;
				cout << "noew the candies is " << candies <<" and tmp is " << tmp << endl;
				if(candies > tmp)
				{
					my_vector[i] += tmp;
				}
				else
				{
					my_vector[i] += candies;
					return my_vector;
				}
				candies -= tmp;
			}
			flag++;
		}
		return my_vector;
	}
};

int main()
{
	int num = 4;
	int candies = 60;
	Slution slu;
	std::vector<int> v(num);
	v = slu.distributeCandies(candies, num);
	for(int i = 0; i < num ; i++)
		cout << ' ' << v[i];
	return 0;
}
