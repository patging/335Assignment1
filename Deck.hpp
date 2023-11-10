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
                CardType&& c = std::move(this->cards_.back());
                c.setDrawn(true); // making it ready to del
                cards_.pop_back(); // popping 
                return std::move(c);
        }

        bool IsEmpty() const {
            return this->cards_.size() == 0;
        }

        void Shuffle() {
            // some random number generator
            std::mt19937 rng(2028358904);
            // running shuffling with said rng
            std::shuffle(this->cards_.begin(), this->cards_.end(), rng);
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
