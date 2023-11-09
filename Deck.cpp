// #include "Deck.hpp"

// template <typename CardType>
// Deck<CardType>::Deck(){
//     this->cards_.clear();
// }

// template <typename CardType>
// Deck<CardType>::~Deck(){
//     this->cards_.clear();
// }
// template <typename CardType>
// void Deck<CardType>::AddCard(const CardType& card) {
//     this->cards_.push_back(card);
// }

// template <typename CardType>
// CardType&& Deck<CardType>::Draw() {
//     if (this->IsEmpty()) {
//         return;
//     }
//     CardType&& c =  std::move(this->cards_.back()); // making it ready to del
//     c.setDrawn(true);
//     cards_.pop_back(); // popping 
//     return c;
//  }

// template <typename CardType>
// bool Deck<CardType>::IsEmpty() const {
//     return this->cards_.size() == 0;
// }

// template <typename CardType>
// void Deck<CardType>::Shuffle() {
//     // some random number generator
//     std::mt19937 rng = std::mt19937(2028358904);
//     // running shuffling with said rng
//     std::shuffle(std::begin(this->cards_), std::end(this->cards_), rng);
// }

// template <typename CardType>
// int Deck<CardType>::getSize() const {
//     return (int) this->cards_.size();
// }

// template <typename CardType>
// std::vector<CardType> Deck<CardType>::getDeck() const {
//     return this->cards_;
// }