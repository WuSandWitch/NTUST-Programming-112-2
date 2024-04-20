#include "user.h"

namespace Authenticate {

namespace {
std::string username;
bool        isValid() {
    if (username.length() != 8)
        return false;

    for (char i: username) {
        if (!isalpha(i))
            return false;
    }
    return true;
}
}  // namespace

void inputUserName() {
    do {
        std::cout << "Enter your username (8 letters only)" << std::endl;
        std::cin >> username;
    } while (!isValid());
}

std::string getUserName() {
    return username;
}
}  // namespace Authenticate