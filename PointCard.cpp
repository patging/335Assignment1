#include "PointCard.hpp"

PointCard::PointCard() {
    this->setType(POINT_CARD);
    this->setDrawn(false);
    this->setInstruction("");
    this->setImageData(nullptr);
}

bool PointCard::isPlayable() {
    return this->getDrawn() && std::stoi(this->getInstruction()) >= 0;
}

void PointCard::Print() const {
    std::cout << "Type: " << this->getType() << std::endl;
    std::cout << "Points: " << this->getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
    
    if (this->getImageData() == nullptr) {
        std::cout << "No image data" << std::endl;
    } else {
        std::cout << this->getImageData() << std::endl;
    }

}