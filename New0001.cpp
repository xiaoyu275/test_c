#include <iostream> 
#include <fstream> 
#include <string> 

#include <vector> 
#include <algorithm> 
#include <iostream> 
#include <ctime>
int ia[ 10 ] = { 
  51, 23, 7, 88, 41, 98, 12, 103, 37, 6 }; 

using namespace std;

string  Get_Current_Date()
{
    time_t nowtime;  
    nowtime = time(NULL); //获取日历时间   
    char tmp[64];   
    strftime(tmp,sizeof(tmp),"%Y-%m-%d %H:%M:%S",localtime(&nowtime));   
	
//    #include <sys/time.h>      //添加头文�?
//       struct timeval tv;    
//       gettimeofday(&tv,NULL);    //该函数在sys/time.h头文件中
//       return tv.tv_sec * 1000 + tv.tv_usec / 1000;  
    return tmp;
}

int main() 
{ 
	// 基于当前系统的当前日�?时间
	time_t now = time(0);
	
	// �?now 转换为字符串形式
	char* dt = ctime(&now);
	
	cout << "本地日期和时间：" << dt << endl;
	
	// �?now 转换�?tm 结构
	tm *gmtm = gmtime(&now);
	dt = asctime(gmtm);
	cout << "UTC 日期和时间："<< dt << endl;

	   cout << "1970 到目前经过秒�?" << now << endl;
 
   tm *ltm = localtime(&now);
 
   // 输出 tm 结构的各个组成部�?
   cout << "�? "<< 1900 + ltm->tm_year << endl;
   cout << "�? "<< 1 + ltm->tm_mon<< endl;
   cout << "�? "<<  ltm->tm_mday << endl;
   cout << "时间: "<< ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;

    // 将当前日期以 20** - ** - ** 格式输出
    cout <<"time: "<< Get_Current_Date().c_str() << endl;
	   
//	vector< int > ivec( 10 );
//	int i= int();//0
//	for(i++;i<10;i++)
//		cout << ivec[i] << endl;
//	double dval=3.6;
//	int ival=5;
//	ival+=static_cast<int>(dval);
//	cout<<"ival:"<<ival<<endl;
	
//  vector< int > vec( ia, ia+10 ); //左闭右开集合
//  
// // 排序数组 
//  sort( vec.begin(), vec.end() ); 
//  
// // 获取�?
// int search_value; 
//  cin >> search_value; 
//  
// // 搜索元素 
// vector<int>::iterator found; 
//  found = find( vec.begin(), vec.end(), search_value ); 
//  if ( found != vec.end() ) 
//    cout << "search_value found!\n" << search_value << endl; 
//  else cout << "search_value not found!\n"; 
//  
// // 反转数组 
//  reverse( vec.begin(), vec.end() ); 
//  for(found =vec.begin();found !=vec.end();found ++)
//	cout<<*found <<endl;
 // ... 
 return 0;
} 

//int main() 
//{ 
//  ofstream outfile( "out_file" ); 
//  ifstream infile( "in_file" ); 
//  if ( ! infile ) { 
//    cerr << "error: unable to open input file!\n"; 
//  return -1; 
// } 
//  if ( ! outfile ) { 
//    cerr << "error: unable to open output file!\n"; 
//  return -2; 
// } 
// string word; 
//  while ( infile >> word ) 
//    outfile << word << ' '; 

// return 0; 
//} 


                       