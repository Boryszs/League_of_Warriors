#include <iostream>
#include <string>
using namespace std;
struct MyException : public std::exception
{
	string error;

	MyException(string err)
	{
		error = err;
	}
	const string what() throw ()
	{
		return error;
	}
};