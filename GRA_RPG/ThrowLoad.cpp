#include <iostream>
struct MyException : public std::exception
{
	const char* what() const throw ()
	{
		return "Error no load module";
	}
};