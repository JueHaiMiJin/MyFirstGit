#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Slution
{
public:
	int nun;
};

int main(int argc, char const *argv[])
{
	std::map<string, int> my_map;
	my_map["MyMap"] = 12;
	my_map["MySecond"] = 13;
	my_map["MyThird"] = 14;
	my_map["MyThird"] = 15;
	my_map.insert(std::pair<string, int> ("MyFurth",16));
	std::map<string, int>::iterator iter = my_map.begin();
	for(iter = my_map.begin(); iter != my_map.end(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}
	cout << "The size of MyMap is : " << my_map.size() << endl;
	if(my_map.empty())
	{
		cout << "MyMap is empty \n";
	}
	else
	{
		cout << "MyMap is not empty \n";
	}
	cout << "using the [] , now the my_map[\"MyThird\"] is :" << my_map["MyThird"] << endl; 
	my_map.clear();
	my_map.emplace("MyFifth" , 17);
	my_map.emplace("MySixth" , 18);
	my_map.emplace("MySeventh" , 19);
	cout << "try other display way :";
	for(auto& MyMap : my_map)
		cout << '[' << MyMap.first << ":" << MyMap.second << ']';
	cout << '\n';
	cout << "----------------------------------------------------------!\n";
	std::map<string,int>::iterator it;
	it = my_map.find("MySixth");
	if(it != my_map.end())
		{
			cout << "the res is :" << it->first <<":" << it->second << endl;
			my_map.erase(it);
		}
	cout << "after rease the sixth is:";
	for(auto& x:my_map)
		cout << "[" << x.first << ":" << x.second <<']';
	cout << '\n';

	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	vector<int>::iterator itt;
	for(itt = v.begin();itt != v.end();++itt)
	{
		cout << ' ' << *itt ;
	}
	cout << '\n';
	cout <<' ';

	return 0;
}