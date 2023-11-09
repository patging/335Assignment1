/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name
Date
Deck.hpp defines the Deck class.
*/
#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include "Card.hpp"
#include <random>


template <typename CardType>
class Deck 
{
    public:
        Deck(){
            this->cards_.clear();
        }

        ~Deck(){
            this->cards_.clear();
        }
        void AddCard(const CardType& card) {
            this->cards_.push_back(card);
        }

        CardType&& Draw() {
            if (this->IsEmpty()) {
                return;
            }
            CardType&& c =  std::move(this->cards_.back()); // making it ready to del
            c.setDrawn(true);
            cards_.pop_back(); // popping 
            return c;
        }

        bool IsEmpty() const {
            return this->cards_.size() == 0;
        }

        void Shuffle() {
            // some random number generator
            std::mt19937 rng = std::mt19937(2028358904);
            // running shuffling with said rng
            std::shuffle(std::begin(this->cards_), std::end(this->cards_), rng);
        }

        int getSize() const {
            return (int) this->cards_.size();
        }

        std::vector<CardType> getDeck() const {
            return this->cards_;
        }

    private:
        std::vector<CardType> cards_;
};

#include "Deck.cpp"
#endif
