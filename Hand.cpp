#include "Hand.hpp"
#include <vector>
Hand::Hand() {}

Hand::~Hand() {
    this->cards_.clear();
}

Hand::Hand(const Hand& other) {
    this->cards_ = other.cards_;
}

Hand& Hand::operator=(const Hand& other) {
    this->cards_ = other.getCards();
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
    card.setDrawn(true);
    this->cards_.push_back(card);
}

bool Hand::isEmpty() const {
    return this->cards_.empty();
}
// fix is buggy
void Hand::Reverse() {
    std::vector<PointCard> v;
    int tmp = this->getCards().size();
    for(int i = 0; i < tmp; i++) {
        v.push_back(this->getCards().front());
        this->cards_.pop_front();
    }
    int tmp2 = v.size();
    for(int i = 0; i < tmp2; i++) {
        this->cards_.push_front(v.at(i));
    }
}

int Hand::PlayCard() {
    
    if ( this->cards_.size() == 0 ) {
        throw std::exception();
    } 

    PointCard p = this->cards_.front();

    if (! p.isPlayable()) {
        this->cards_.pop_front();
        throw std::exception();
    }

    this->cards_.pop_front();
    
    return std::stoi(p.getInstruction());

}