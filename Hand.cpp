#include "Hand.hpp"
#include "PointCard.hpp"
/*
    ~Hand()
    
    destructor
*/
Hand::~Hand() {
    this->cards.clear();
}

/*
    Hand(const Hand& other)

    Creates a new hand instance by copying over
    the old deque
*/
Hand::Hand(const Hand& other) {
    std::deque<PointCard> h = other.getCards();
    std::copy(h.begin(),h.end(), this->cards);
}

/*
    Hand::Hand(Hand&& other)

    Move constructor
*/
Hand::Hand(Hand&& other) {
    this->cards = std::move(other.getCards());
}

/*
    Hand& operator=(const Hand& other)

    checks if a hand is equal or not
*/
Hand& Hand::operator=(const Hand& other) {
    return this->cards == other.getCards();
}

/*
    const std::deque<PwointCard>& getCards() const;

    returns the hand
*/
const std::deque<PointCard>& Hand::getCards() const {
    return this->cards;
}

/*
    void addCard(PointCard&& card)

    Adds a card to the internal deque
*/
void Hand::addCard(PointCard&& card) {
    this->cards.push_back(card);
}

/*
    bool isEmpty() const

    returns if the hand is empty
*/
bool Hand::isEmpty() const {
    return this->cards.size() == 0;
}

/*
    void Reverse()

    reverses the hand
*/
void Hand::Reverse() {
    std::reverse(this->cards.begin(), this->cards.end());
}

/*
    int PlayCard();

    Plays the card, but will throw an exception if the hand is empty
*/
int Hand::PlayCard() {
    if ( this->cards.size() == 0 ) {
        throw std::out_of_range("Hand has no more cards");
    }

    PointCard c = this->cards.front();
    this->cards.pop_front();

    return c.getPoints();
}