#include "Player.hpp"

Player::Player() {
    this->score_ = 0;
}

Player::~Player() {
    delete this->opponent_;
    delete this->actiondeck_;
    delete this->pointdeck_;
}

const Hand& Player::getHand() const {
    return this->hand_;
}

void Player::setHand(const Hand& hand) {
    this->hand_ = hand;
}

int Player::getScore() const {
    return this->score_;
}

void Player::setScore(const int& score) {
    this->score_ = score;
}

void Player::play(ActionCard&& card) {

}

void Player::drawPointCard() {
    PointCard p = this->pointdeck_->Draw();
    p.setDrawn(true);
    this->opponent_->hand_.addCard(std::move(p));
}

void Player::playPointCard() {
    PointCard p = this->pointdeck_->Draw();
    this->score_ += std::stoi(p.getInstruction());
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