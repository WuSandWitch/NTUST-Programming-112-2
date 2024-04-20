#include "user.h"

namespace Authenticate
{

	namespace {
		bool isValid() {
			return username.length() == 8;
		}
	}
	
	void inputUserName()
	{
		do
		{
			std::cout << "Enter your username (8 letters only)" << std::endl;
			std::cin >> username;
		} while (!isValid());
	}

	std::string getUserName()
	{
		return username;
	}
}