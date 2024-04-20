#include <iostream>
#include "user.h"
#include "password.h"

int main()
{
    using namespace Authenticate;
    inputUserName();
    inputPassword();
    std::cout << "Your username is " << getUserName() <<
        " and your password is: " <<
        getPassword() << std::endl;
    return 0;
}
