#include "Player.hpp"

Player::Player() {
    this->score_ = 0;
    this->opponent_ = nullptr;
    this->actiondeck_ = nullptr;
    this->pointdeck_ = nullptr;
}

Player::~Player() {
    delete this->opponent_;
    delete this->actiondeck_;
    delete this->pointdeck_;
    this->opponent_ = nullptr;
    this->actiondeck_ = nullptr;
    this->pointdeck_ = nullptr;
}

const Hand& Player::getHand() const {
    return this->hand_;
}

void Player::setHand(const Hand& hand) {
    this->hand_= hand;

}

int Player::getScore() const {
    return this->score_;
}

void Player::setScore(const int& score) {
    this->score_ = score;
}

void Player::play(ActionCard&& card) {
    // step 1: determine what the actual type of the card is 
    // step 2: execute the said instruction
    std::string inst = card.getInstruction();
    std::cout << "PLAYING ACTION CARD: " << inst << std::endl;
    if (inst.find("CARD") != -1 ) {
        // we have some card where we either play a card or draw it
        int index = (int) inst.find(" ") + 1;
        int index2 = (int) inst.rfind(" ") ;
        int val = std::stoi(inst.substr(index, index2-index));
        if (card.getInstruction().find("DRAW") != -1) {
            // we have a draw some amount of cards
            std::cout << "DRAW" << val << std::endl;
            
            for (int i = 0; i < val; i++) 
                this->drawPointCard();
            
        } else {
            // instead of drawing, we'll play 
            
            for (int i = 0; i < val; i++)
                this->playPointCard();
            
        }
    } else {
        // meaning we either have reverse hand or swap hand
        if (inst == "REVERSE HAND") {
            // meaning that we have reverse hand
            std::cout << "REVERSE" << std::endl;
            this->hand_.Reverse();
        } else {
            std::cout << "CHANGE HANDS" << std::endl;
            
            Hand tmp = this->hand_;
            this->hand_ = this->opponent_->getHand();
            this->opponent_->setHand(tmp); 
            
        }

    }

}

void Player::drawPointCard() {
    //p.setDrawn(true);
    this->hand_.addCard(this->pointdeck_->Draw());
}

void Player::playPointCard() {
    this->score_ += this->hand_.PlayCard();
}

void Player::setOpponent(Player* opponent) {
    this->opponent_ = opponent;
}

Player* Player::getOpponent() {
    return this->opponent_;
}

void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
    this->actiondeck_ = actiondeck;
}

Deck<ActionCard>* Player::getActionDeck() {
    return this->actiondeck_;
}

void Player::setPointDeck(Deck<PointCard>* pointdeck) {
    this->pointdeck_ = pointdeck;
}

Deck<PointCard>* Player::getPointDeck() {
    return this->pointdeck_;
}