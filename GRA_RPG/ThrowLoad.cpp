#include <iostream>
#include <string>
using namespace std;

/// Struct to service exception.
struct MyException : public std::exception
{
	/// Text error message.
	string error;

	/// Constructor Struct MyException
	/// <param name="err"> - Message error</param>
	MyException(string err)
	{
		error = err;
	}

	/// Show message error.
	/// <returns>message error</returns>
	const string what() throw ()
	{
		return error;
	}
};