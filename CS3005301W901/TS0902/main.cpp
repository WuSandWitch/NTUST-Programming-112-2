#include <iostream>

#include "password.h"
#include "user.h"

int main() {
    using namespace Authenticate;
    inputUserName();
    inputPassword();
    std::cout << "Your username is " << getUserName() << " and your password is: " << getPassword() << std::endl;
    return 0;
}
