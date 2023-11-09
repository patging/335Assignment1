#include "Card.hpp"
#include <algorithm>

Card::Card() {
    this->setDrawn(false);
}

Card::~Card() {
    delete &cardType_;
    delete &instruction_;
    delete[] bitmap_;
    bitmap_ = nullptr;
    delete &drawn_;
}

Card::Card(const Card& rhs) {
    // copying CardType
    if ( rhs.getType() == "POINT_CARD" ) {
        this->cardType_ = POINT_CARD;
    } else {
        this->cardType_ = ACTION_CARD;
    }

    // copying drawn data
    this->drawn_ = rhs.getDrawn();

    // copying instruction
    this->instruction_ = rhs.getInstruction();

    // copying bitmap data
    std::copy(rhs.getImageData(), rhs.getImageData() + 80, this->bitmap_+1);
}

Card& Card::operator=(const Card& rhs) {
    return *this;
}

Card::Card(Card&& rhs) {
    this->bitmap_ = std::move(rhs.bitmap_);
    this->cardType_ = std::move(rhs.cardType_);
    this->drawn_ = std::move(rhs.drawn_);
    this->instruction_ = std::move(rhs.instruction_);
}

Card& Card::operator=(Card&& rhs) {
    this->bitmap_ = std::move(rhs.bitmap_);
    this->cardType_ = std::move(rhs.cardType_);
    this->drawn_ = std::move(rhs.drawn_);
    this->instruction_ = std::move(rhs.instruction_);
    return *this;
}

std::string Card::getType() const {
    if ( this->cardType_ == POINT_CARD) {
        return "POINT_CARD";
    } else {
        return "ACTION_CARD";
    }
}

void Card::setType(const CardType& type) {
    this->cardType_ = type;
}

const std::string& Card::getInstruction() const {
    return this->instruction_;
}

void Card::setInstruction(const std::string& instruction) {
    this->instruction_ = instruction;
}

const int* Card::getImageData() const {
    return this->bitmap_;
}

void Card::setImageData(int* data) {
    delete[] this->bitmap_;
    this->bitmap_ = data;
}

bool Card::getDrawn() const {
    return this->drawn_;
}

void Card::setDrawn(const bool& drawn) {
    this->drawn_ = drawn;
}