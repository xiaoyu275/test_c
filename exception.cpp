#include <iostream>
#include <csignal>
#include <unistd.h>
#include <math.h>


using namespace std;

void signalHandler( int signum )
{
     cout << "Interrupt signal (" << signum << ") received.\n";

     // 清理并关闭
     // 终止程序  

    exit(signum);  

}
void ts()
{
	throw -1;
}
int main(int argc, char * argv [ ])
{
	try
	{
	    // 注册信号 SIGINT 和信号处理程序
     signal(SIGFPE, signalHandler); //SIGINT 
		int i=-10;
		int j=0;
		int a[10];
		//j=sqrt(i);
		cout << "test " <<  j << endl;
		//ts();
		//i=a[10000];
		//i=i/j;
		throw -1;
	}
	catch(exception& ex)//  ...
	{
		cout << "finished11"  <<endl;//<< ex.what() cout << 'exception:' << ' ' << endl;//printf('exception:%s',e);
	}
	cout << "finished" << endl;
		
}



