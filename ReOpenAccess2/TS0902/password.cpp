#include "password.h"

namespace Authenticate {

    namespace {
        std::string password;
        bool isValid() {
            if (password.length() < 8) return false;

            for (auto i : password) {
                if (!std::isalpha(i)) return true;
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
        } while (!isValid());
    }

    std::string getPassword()
    {
        return password;
    }

    
}

