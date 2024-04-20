#include "password.h"

namespace Authenticate
{
    namespace {
        bool isValid() {
            if (password.length() < 8) return false;

            for (char i : password) {
                if (!std::isalpha(i)) {
                    return true;
                }
            }
            return false;
        }
    }

    void inputPassword()
    {
        do
        {
            std::cout << "Enter your password (at least 8 characters " <<
                "and at least one non-letter)" << std::endl;
            std::cin >> password;
        } while (!  isValid());
    }

    std::string getPassword()
    {
        return password;
    }
}

