
#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include <iostream>
#include <string>

using namespace std;

//#include <boost/ref.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <boost/shared_ptr.hpp>

#include <boost/date_time/microsec_time_clock.hpp>
#include <boost/date_time/time_duration.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/posix_time/time_formatters.hpp>
#include <boost/date_time/posix_time/time_parsers.hpp>

//#include <boost/process.hpp>
using namespace boost;
using namespace boost::posix_time;

int add(int a,int b);

int main(int argc,char* argv[])
{

	ptime hvontimestamp = microsec_clock::universal_time();
	
	//thread th(&add);
	
	cout<<to_iso_extended_string(hvontimestamp)<<endl;
	
    cout<<"Hello World!"<<endl;
}

int add(int a,int b)
{
	return a+b;
}
