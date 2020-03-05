#include <iostream>
#include <vector>
using namespace std;
class Slution
{
public:
	int maxArea(std::vector<int>& height)
	{
		// int max = 0;
		// for(int i = 0; i <hight.size(); i++)
		// {
		// 	for(int j = i+1; j < hight.size(); j++)
		// 	{
		// 		int tmp = (hight[i]< hight[j])?hight[i]:hight[j];
		// 		int tmp_area = tmp*(j-i);
		// 		max = (max>tmp_area)?max:tmp_area;
		// 	}
		// }
		// return max;
		int i = 0;
		int j = height.size()-1;
		int ret = 0;
		while(i<j)
		{
			int h = min(height[i],height[j]);
			ret = max(ret,h*(j-i));
			if(height[i] < height[j])
				j--;
			else
				i++;
		}
		return ret;
	}
};

int main()
{
	std::vector<int> v;
	for(int i = 0 ; i < 10 ; i++)
	{
		v.push_back(rand()%100);
	}
	int ret = 0;
	Slution slu;
	ret = slu.maxArea(v);
	cout << "maxi is " << ret <<endl;
	return 0;
}