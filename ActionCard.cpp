#include "ActionCard.hpp"
#include "Card.hpp"

ActionCard::ActionCard() {
    this->setType(ACTION_CARD);
    this->setImageData(nullptr);
}

bool ActionCard::isPlayable() {

    int index = (int) this->getInstruction().find(" ") + 1;
    int index2 = (int) this->getInstruction().rfind(" ");

    if (this->getDrawn()) {
        if (this->getInstruction() == "REVERSE HAND" || this->getInstruction() == "SWAP HAND WITH OPPONENT") {
            // we're checking for cards without a number on them
            return true;
        } else if (std::stoi(this->getInstruction().substr(index, index2 - index)) >= 0 && (this->getInstruction().find("DRAW") != -1 || this->getInstruction().find("PLAY") != -1 ) ) {
            // we're checking for the cards with a number to see if they're valid
            return true;
        } 
    } 

    return false;

}

void ActionCard::Print() const {
    std::cout << "Type: " << this->getType() << std::endl;
    std::cout << "Instruction: " << this->getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
    
    if (this->getImageData() == nullptr) {
        std::cout << "No image data" << std::endl;
    } else {
        std::cout << this->getImageData() << std::endl;
    }
}