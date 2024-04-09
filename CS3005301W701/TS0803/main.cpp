#include <iostream>
#include <string>
#include <vector>

bool setMemory(int position, std::string type, int memorySize, std::vector<unsigned char>& memory) {
    int            charValue;
    unsigned int   intValue;
    unsigned short shortValue;
    std::string    stringValue;

    if (position >= memorySize || position < 0)
        return false;

    if (type == "String") {
        std::getline(std::cin >> std::ws, stringValue);
        if (position + stringValue.length() + 1 > memorySize) {
            for (int i = position, j = 0; i < memorySize && j < stringValue.length(); i++, j++) {
                if (i >= 0) {
                    memory[i] = (stringValue[j] & 0xFF);
                }
            }
            return false;
        }
        for (int i = 0; i < stringValue.length(); i++) {
            memory[position + i] = stringValue[i];
        }
        memory[position + stringValue.length()] = '\0';
    } else if (type == "int") {
        std::cin >> intValue;
        if (position + 4 > memorySize) {
            for (int i = position, j = 0; i < memorySize && j < 4; i++, j++) {
                if (i >= 0) {
                    memory[i] = (intValue & 0xFF);
                }
                intValue = intValue >> 8;
            }
            return false;
        }
        for (int i = 0; i < 4; i++) {
            memory[position + i] = ((intValue >> (8 * i)) & 0xFF);
        }
    } else if (type == "short") {
        std::cin >> shortValue;
        if (position + 2 > memorySize) {
            for (int i = position, j = 0; i < memorySize && j < 2; i++, j++) {
                if (i >= 0) {
                    memory[i] = (shortValue & 0xFF);
                }
                shortValue = shortValue >> 8;
            }
            return false;
        }
        memory[position]     = (shortValue & 0xFF);
        memory[position + 1] = ((shortValue >> 8) & 0xFF);
    } else if (type == "char") {
        std::cin >> charValue;
        if (position + 1 > memorySize)
            return false;
        memory[position] = (charValue & 0xFF);
    }

    return true;
}

bool getMemory(int position, std::string type, int memorySize, std::vector<unsigned char>& memory) {
    if (position >= memorySize || position < 0)
        return false;

    if (type == "String") {
        if (position + 1 > memorySize)
            return false;
        while (position < memorySize && memory[position] != '\0') {
            std::cout << memory[position++];
        }
        std::cout << '\n';
    } else if (type == "int") {
        if (position + 4 > memorySize)
            return false;

        int sum = 0;
        for (int i = 3; i >= 0; i--) {
            sum |= (memory[position + i] << ((i)*8));
        }

        std::cout << sum << '\n';
    } else if (type == "short") {
        if (position + 2 > memorySize)
            return false;

        int sum = 0;
        sum |= (memory[position + 1] << 8);
        sum |= memory[position];

        std::cout << sum << '\n';
    } else if (type == "char") {
        if (position + 1 > memorySize)
            return false;
        std::cout << int(memory[position]) << '\n';
    }

    return true;
}

int main() {
    int memorySize, n;

    std::cin >> memorySize >> n;
    std::vector<unsigned char> memory(memorySize);

    for (int i = 0; i < n; i++) {
        int         position;
        std::string type, command;
        std::cin >> command >> position >> type;

        bool status = true;

        if (command == "Set")
            status = setMemory(position, type, memorySize, memory);
        else if (command == "Get")
            status = getMemory(position, type, memorySize, memory);

        if (!status)
            std::cout << "Violation Access.\n";
    }
}