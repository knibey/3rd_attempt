#include <iostream>
#include "library.h"
#include "constants.h"
#include <string>
#include <utility>
#include <cstring>
#include <array>

enum CardSeniority {
    SENIOR_TWO,
    SENIOR_THREE,
    SENIOR_FOUR,
    SENIOR_FIVE,
    SENIOR_SIX,
    SENIOR_SEVEN,
    SENIOR_EIGHT,
    SENIOR_NINE,
    SENIOR_TEN,
    SENIOR_VALET,
    SENIOR_DAMA,
    SENIOR_KING,
    SENIOR_TUZ,
    MAX_SENIORITY
};

enum CardSuit {
    SUIT_TREF,
    SUIT_BUBNA,
    SUIT_CHERVA,
    SUIT_PIKA,
    MAX_SUITS
};

struct Card {
    CardSeniority rank;
    CardSuit suit;
};

void printCard(const Card& card) {
    switch (card.rank) {
    case SENIOR_TWO: std::cout << "2"; break;
    case SENIOR_THREE: std::cout << "3"; break;
    case SENIOR_FOUR: std::cout << "4"; break;
    case SENIOR_FIVE: std::cout << "5"; break;
    case SENIOR_SIX: std::cout << "6"; break;
    case SENIOR_SEVEN: std::cout << "7"; break;
    case SENIOR_EIGHT: std::cout << "8"; break;
    case SENIOR_NINE: std::cout << "9"; break;
    case SENIOR_TEN: std::cout << "10"; break;
    case SENIOR_VALET: std::cout << "V"; break;
    case SENIOR_DAMA: std::cout << "D"; break;
    case SENIOR_KING: std::cout << "K"; break;
    case SENIOR_TUZ: std::cout << "T"; break;
    }

    switch (card.suit) {
    case SUIT_TREF: std::cout << "TR"; break;
    case SUIT_BUBNA: std::cout << "B"; break;
    case SUIT_CHERVA: std::cout << "CH"; break;
    case SUIT_PIKA: std::cout << "P"; break;
    }
}

void printDeck(const std::array<Card, 52>& deck) {
    for (auto const& card : deck) {
        printCard(card);
        std::cout << ' ';
    }

    std::cout << '\n';
}

void swapCard(Card& firstcard, Card& secondcard) {
    Card temp = firstcard;
    firstcard = secondcard;
    secondcard = temp;
}

int getRandomCard(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52>& deck) {
    for (int i = 0; i < 52; ++i) {
        swapCard(deck[i], deck[getRandomCard(1, 51)]);
    }
}

int getCardValue(const Card& card) {
    switch (card.rank) {
    case SENIOR_TWO: return 2;
    case SENIOR_THREE: return 3;
    case SENIOR_FOUR: return 4;
    case SENIOR_FIVE: return 5;
    case SENIOR_SIX: return 6;
    case SENIOR_SEVEN: return 7;
    case SENIOR_EIGHT: return 8;
    case SENIOR_NINE: return 9;
    case SENIOR_TEN: return 10;
    case SENIOR_VALET: return 10;
    case SENIOR_DAMA: return 10;
    case SENIOR_KING: return 10;
    case SENIOR_TUZ: return 11;
    }

    return 0;
}

char getPlayerChoice1() {
    char choice;
    do {
        std::cout << "Do u wanna to hit or to stand? (H/S): ";
        choice = getCharFromUser();
    } while (choice != 'H' && choice != 'h' && choice != 'S' && choice != 's');

    return choice;
}

bool playBlackJack(const std::array<Card, 52> &deck) {
    const Card* cardptr = &deck[0];

    int player_score{ 0 };
    int dealer_score{ 0 };

    dealer_score += getCardValue(*cardptr++);
    std::cout << "The dealer is showing: " << dealer_score << std::endl;

    player_score += getCardValue(*cardptr++);
    player_score += getCardValue(*cardptr++);

    while (1) {
        std::cout << "you have: " << player_score << std::endl;

        if (player_score > 21) {
            return false;
        }

        char choice = getPlayerChoice1();
        if (choice == 'S' || choice == 's') {
            break;
        }

        player_score += getCardValue(*cardptr++);
    }

    while (dealer_score < 17) {
        dealer_score += getCardValue(*cardptr++);
        std::cout << "The dealer now has: " << dealer_score << std::endl;
    }

    if (dealer_score > 21) {
        return true;
    }

    return (player_score > dealer_score);


}

int maintopic6_test7() {
    srand(static_cast<unsigned int>(time(0)));
    rand();

    std::array<Card, 52> deck;

    int card = 0;
    for (int suit = 0; suit < MAX_SUITS; ++suit) {
        for (int rank = 0; rank < MAX_SENIORITY; ++rank) {
            deck[card].suit = static_cast<CardSuit>(suit);
            deck[card].rank = static_cast<CardSeniority>(rank);
            ++card;
        }
    }

    printDeck(deck);

    shuffleDeck(deck);

    printDeck(deck);

    if (playBlackJack(deck)) {
        std::cout << "You win" << std::endl;
    } else {
        std::cout << "You lose" << std::endl;
    }


    return 0;
}