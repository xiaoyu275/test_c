
#include <iostream>
#include "linux_list.h"
#include "dual_link_list.h"

using namespace std;
using namespace DTlib;

//test

int main(int argc, char* argv[])//int main()
{
	DualCirleList<int> dl;
	for(int i=0;i<5;i++)
		{
		dl.insert(0,i);
		dl.insert(0,5);
		}
	cout<<"begin"<<endl;
	dl.move(dl.length()-1);
	while(dl.find(5)!=-1)
		{
		if(dl.current()==5)
			{
			cout<<dl.current()<<endl;
			dl.remove(dl.find(dl.current()));
			}
		else
			{
			dl.prev();
			}
		}
	cout<<"end"<<endl;
	for(int i=0;i<dl.length();i++)//for(dl.move(0);!dl.end();dl.next())
		cout <<dl.get(i)<<endl;
	std::cin.get();//»ògetchar()system("pause");
	return 0;
}
