#include "user.h"

namespace Authenticate {
	
	namespace {
		std::string username;
		bool isValid() {
			if (username.length() != 8) return false;

			for (auto i : username) {
				if (!std::isalpha(i)) return false;
			}
			return true;
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

