#include "Hand.hpp"

Hand::Hand() {}

Hand::~Hand() {
    this->cards_.clear();
}

Hand::Hand(const Hand& other) {
    this->cards_ = other.cards_;
}

Hand& Hand::operator=(const Hand& other) {
    return *this;
}

Hand::Hand(Hand&& other) {
    this->cards_ = std::move(other.cards_);
}

Hand& Hand::operator=(Hand&& other) {
    this->cards_ = std::move(other.cards_);
    return *this;
}

const std::deque<PointCard>& Hand::getCards() const {
    return this->cards_;
}

void Hand::addCard(PointCard&& card) {
    this->cards_.push_back(card);
}

bool Hand::isEmpty() const {
    return this->cards_.size() == 0;
}

void Hand::Reverse() {
    std::deque<PointCard> tmp;

    for (auto i = this->cards_.rbegin(); i != this->cards_.rend(); ++i ) {
        tmp.push_back(*i);
    }
    this->cards_ = tmp;
}

int Hand::PlayCard() {
    if ( this->cards_.size() == 0 ) {
        throw std::exception();
    } 

    PointCard p = this->cards_.front();

    if (!p.isPlayable()) {
        throw std::exception();
    }

    this->cards_.pop_front();
    
    return std::stoi(p.getInstruction());

}