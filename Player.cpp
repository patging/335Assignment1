#include "Player.hpp"

Player::Player() {
  this->score_ = 0;
  this->opponent_ = nullptr;
  this->actiondeck_ = nullptr;
  this->pointdeck_ = nullptr;
}

Player::~Player() {
  this->opponent_ = nullptr;
  this->actiondeck_ = nullptr;
  this->pointdeck_ = nullptr;
}

const Hand &Player::getHand() const { return this->hand_; }

void Player::setHand(const Hand &hand) { this->hand_ = hand; }

int Player::getScore() const { return this->score_; }

void Player::setScore(const int &score) { this->score_ = score; }

void Player::play(ActionCard &&card) {
  // step 1: determine what the actual type of the card is
  // step 2: execute the said instruction
  std::string inst = card.getInstruction();
  // immediate matches
  if (inst.find("REVERSE HAND") != -1) {
    // do the reverse
    this->hand_.Reverse();
  } else if (inst.find("SWAP HAND WITH OPPONENT") != -1) {
    // conduct the swap
    Hand tmp = Hand(this->hand_);
    this->hand_ = this->opponent_->getHand();
    this->opponent_->setHand(tmp);
  } else {
    // grabbing parsing data
    int index = (int)inst.find(" ") + 1;
    int index2 = (int)inst.rfind(" ");

    if (inst.find("DRAW") != -1 && inst.find("CARD(S)") != -1) {
      int val = std::stoi(inst.substr(index, index2 - index));
      // draw for val # of times
      for (int i = 0; i < val; i++) {
        this->drawPointCard();
      }
    } else if (inst.find("PLAY") != -1 && inst.find("CARD(S)") != -1) {
      int val = std::stoi(inst.substr(index, index2 - index));
      // then play for val # of times
      for (int i = 0; i < val; i++) {
        this->playPointCard();
      }
    }
  }
}

void Player::drawPointCard() {
  PointCard p = this->pointdeck_->Draw();
  this->hand_.addCard(std::move(p));
}

void Player::playPointCard() { this->score_ += this->hand_.PlayCard(); }

void Player::setOpponent(Player *opponent) { this->opponent_ = opponent; }

Player *Player::getOpponent() { return this->opponent_; }

void Player::setActionDeck(Deck<ActionCard> *actiondeck) {
  this->actiondeck_ = actiondeck;
}

Deck<ActionCard> *Player::getActionDeck() { return this->actiondeck_; }

void Player::setPointDeck(Deck<PointCard> *pointdeck) {
  this->pointdeck_ = pointdeck;
}

Deck<PointCard> *Player::getPointDeck() { return this->pointdeck_; }