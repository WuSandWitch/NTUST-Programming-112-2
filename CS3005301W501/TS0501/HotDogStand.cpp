#include "HotDogStand.h"

#include <iostream>
#include <string>

HotDogStand::HotDogStand() {
    standId[0]             = '\0';
    this->hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char* id) {
    this->standId = new char[strlen(id) + 1];
    strcpy_s(this->standId, strlen(id) + 1, id);
    this->hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char* id, int amount) {
    this->standId = new char[strlen(id) + 1];
    strcpy_s(this->standId, strlen(id) + 1, id);
    this->hotDogSellAmount = amount;
    totalSellAmount += amount;
}

HotDogStand::~HotDogStand() {
}

void HotDogStand::justSold() {
    hotDogSellAmount += 1;
    totalSellAmount += 1;
}

void HotDogStand::print() {
    std::cout << standId << " " << hotDogSellAmount << '\n';
}

int HotDogStand::thisStandSoldAmount() {
    return hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount() {
    return totalSellAmount;
}

int HotDogStand::totalSellAmount = 0;
