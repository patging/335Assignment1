#include "ActionCard.hpp"
#include "Card.hpp"

ActionCard::ActionCard() {
    this->setType(ACTION_CARD);
    this->setImageData(nullptr);
}

bool ActionCard::isPlayable() {

    int index = (int) this->getInstruction().find(" ") + 1;
    int index2 = (int) this->getInstruction().rfind(" ") + 1;
    if (std::stoi(this->getInstruction().substr(index, index2 - index)) >= 0) {
        return this->getDrawn();
    }
    
    return false;
}

void ActionCard::Print() const {
    std::cout << "Type: " << this->getType() << std::endl;
    std::cout << "Points: " << this->getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
    
    if (this->getImageData() == nullptr) {
        std::cout << "No image data" << std::endl;
    } else {
        std::cout << this->getImageData() << std::endl;
    }
}