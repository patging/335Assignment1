#include "Card.hpp"
#include <algorithm>

Card::Card() {
    // KEEP THIS HERE
    // THIS MAY SEEM REDUNDANT
    // BUT IT WILL BREAK IF YOU DONT
    // KEEP IT AS THE NULL POINTER
    this->instruction_ = "";
    this->drawn_ = false;
    this->bitmap_ = nullptr;
}

Card::~Card() {

    if (this->bitmap_ != nullptr) {
        delete[] bitmap_;
        bitmap_ = nullptr;
    }

}

Card::Card(const Card& rhs) {
    // copying CardType
    this->cardType_ = rhs.cardType_;

    // copying drawn data
    this->drawn_ = rhs.getDrawn();

    // copying instruction
    this->instruction_ = rhs.getInstruction();

    // copying bitmap data
    if (rhs.bitmap_ == nullptr) {
        // manually give it null ptr, elsewise copy it over 
        // this is getting too buggy on my side for some reason
        this->bitmap_ = nullptr;
    } else {
        // you can use std copy, but this thing isn't working for me rn :(
        for (int i = 0; i < 80; i++) 
            this->bitmap_[i] = rhs.bitmap_[i];
    }
}

Card& Card::operator=(const Card& rhs) {
    this->cardType_ = rhs.cardType_;
    this->instruction_ = rhs.getInstruction();
    this->drawn_ = rhs.getDrawn();

    this->bitmap_ = new int[80];
    for (int i =0 ; i <80; i++) {
        this->bitmap_[i] = rhs.bitmap_[i];
    }


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
    if (data == nullptr) {
        this->bitmap_ = nullptr;
    } else {
        this->bitmap_ = new int[80];
        for (int i =0;i <80;i++) 
        this->bitmap_[i] = data[i];
    }
}

bool Card::getDrawn() const {
    return this->drawn_;
}

void Card::setDrawn(const bool& drawn) {
    this->drawn_ = drawn;
}