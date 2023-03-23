#include <iostream>
#include <array>
#include <ctime> // дл€ time()
#include <cstdlib> // дл€ rand() ≥ srand()
#include <cassert>

class Card {
public:
	enum CardSuit
	{
		SUIT_CLUB,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_SPADE,
		MAX_SUITS
	};

	enum CardRank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANKS
	};

private:
	CardSuit m_suit;
	CardRank m_rank;

public:
	Card(CardRank rank = MAX_RANKS, CardSuit suit = MAX_SUITS) : m_rank(rank), m_suit(suit) {}

	void printCard() const
	{
		switch (m_rank)
		{
		case RANK_2:		std::cout << '2'; break;
		case RANK_3:		std::cout << '3'; break;
		case RANK_4:		std::cout << '4'; break;
		case RANK_5:		std::cout << '5'; break;
		case RANK_6:		std::cout << '6'; break;
		case RANK_7:		std::cout << '7'; break;
		case RANK_8:		std::cout << '8'; break;
		case RANK_9:		std::cout << '9'; break;
		case RANK_10:		std::cout << 'T'; break;
		case RANK_JACK:		std::cout << 'J'; break;
		case RANK_QUEEN:	std::cout << 'Q'; break;
		case RANK_KING:		std::cout << 'K'; break;
		case RANK_ACE:		std::cout << 'A'; break;
		}

		switch (m_suit)
		{
		case SUIT_CLUB:		std::cout << 'C'; break;
		case SUIT_DIAMOND:	std::cout << 'D'; break;
		case SUIT_HEART:	std::cout << 'H'; break;
		case SUIT_SPADE:	std::cout << 'S'; break;
		}
	}

	int getCardValue() const
	{
		switch (m_rank)
		{
		case RANK_2:		return 2;
		case RANK_3:		return 3;
		case RANK_4:		return 4;
		case RANK_5:		return 5;
		case RANK_6:		return 6;
		case RANK_7:		return 7;
		case RANK_8:		return 8;
		case RANK_9:		return 9;
		case RANK_10:		return 10;
		case RANK_JACK:		return 10;
		case RANK_QUEEN:	return 10;
		case RANK_KING:		return 10;
		case RANK_ACE:		return 11;
		}

		return 0;
	}
};

class Deck {
private:
	std::array<Card, 52> m_deck;
	int m_CardIndex{ 0 };

	static void swapCard(Card& a, Card& b)
	{
		Card temp = a;
		a = b;
		b = temp;
	}

	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		// –≥вном≥рно розпод≥л€Їмо рандомне число в нашому д≥апазон≥
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

public:
	Deck() {
		int card = 0;
		for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
			for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
			{
				m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
				++card;
			}
	}

	void printDeck() const
	{
		for (const auto& card : m_deck)
		{
			card.printCard();
			std::cout << ' ';
		}

		std::cout << '\n';
	}

	void shuffleDeck() {
		// ѕеребираЇмо кожну карту в колод≥
		for (int index = 0; index < 52; ++index)
		{
			// ¬ибираЇмо будь-€ку випадкову карту
			int swapIndex = getRandomNumber(0, 51);
			// ћ≥н€Їмо м≥сц€ми з нашою поточною картою
			swapCard(m_deck[index], m_deck[swapIndex]);
		}
		m_CardIndex = 0;
	}

	const Card& dealCard() {
		assert(m_CardIndex < 52);
		return m_deck[m_CardIndex++];
	}


};

char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

bool playBlackjack(Deck &deck)
{
	int playerTotal = 0;
	int dealerTotal = 0;

	// ƒилер отримуЇ одну карту
	dealerTotal += deck.dealCard().getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// √равець отримуЇ дв≥ карти
	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();

	// √равець починаЇ
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += deck.dealCard().getCardValue();

		// ƒивимос€, чи гравець не програв
		if (playerTotal > 21)
			return false;
	}

	// якщо гравець не програв (у нього не б≥льше 21 очка), тод≥ дилер отримуЇ карти до тих п≥р, поки у нього в п≥дсумку буде не менше 17 очк≥в
	while (dealerTotal < 17)
	{
		dealerTotal += deck.dealCard().getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// якщо у дилера б≥льше 21 очка, то в≥н програв, а гравець виграв
	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // використовуЇмо системний годинник в €кост≥ стартового значенн€
	rand(); // користувачам Visual Studio: скидаЇмо перше згенероване (випадкове) число

	Deck deck;

	deck.shuffleDeck();

	if (playBlackjack(deck))
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";

	return 0;
}

/*
enum CardSuit
{
	SUIT_CLUB,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPADE,
	MAX_SUITS
};

enum CardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANKS
};

struct Card
{
	CardRank rank;
	CardSuit suit;
};

void printCard(const Card& card)
{
	switch (card.rank)
	{
	case RANK_2:		std::cout << '2'; break;
	case RANK_3:		std::cout << '3'; break;
	case RANK_4:		std::cout << '4'; break;
	case RANK_5:		std::cout << '5'; break;
	case RANK_6:		std::cout << '6'; break;
	case RANK_7:		std::cout << '7'; break;
	case RANK_8:		std::cout << '8'; break;
	case RANK_9:		std::cout << '9'; break;
	case RANK_10:		std::cout << 'T'; break;
	case RANK_JACK:		std::cout << 'J'; break;
	case RANK_QUEEN:	std::cout << 'Q'; break;
	case RANK_KING:		std::cout << 'K'; break;
	case RANK_ACE:		std::cout << 'A'; break;
	}

	switch (card.suit)
	{
	case SUIT_CLUB:		std::cout << 'C'; break;
	case SUIT_DIAMOND:	std::cout << 'D'; break;
	case SUIT_HEART:	std::cout << 'H'; break;
	case SUIT_SPADE:	std::cout << 'S'; break;
	}
}

void printDeck(const std::array<Card, 52> deck)
{
	for (const auto& card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}

	std::cout << '\n';
}

void swapCard(Card& a, Card& b)
{
	Card temp = a;
	a = b;
	b = temp;
}

// √енеруЇмо випадкове число м≥ж min ≥ max (включно).
// ѕрипускаЇтьс€, що srand() вже викликали
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// –≥вном≥рно розпод≥л€Їмо рандомне число в нашому д≥апазон≥
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52>& deck)
{
	// ѕеребираЇмо кожну карту в колод≥
	for (int index = 0; index < 52; ++index)
	{
		// ¬ибираЇмо будь-€ку випадкову карту
		int swapIndex = getRandomNumber(0, 51);
		// ћ≥н€Їмо м≥сц€ми з нашою поточною картою
		swapCard(deck[index], deck[swapIndex]);
	}
}

int getCardValue(const Card& card)
{
	switch (card.rank)
	{
	case RANK_2:		return 2;
	case RANK_3:		return 3;
	case RANK_4:		return 4;
	case RANK_5:		return 5;
	case RANK_6:		return 6;
	case RANK_7:		return 7;
	case RANK_8:		return 8;
	case RANK_9:		return 9;
	case RANK_10:		return 10;
	case RANK_JACK:		return 10;
	case RANK_QUEEN:	return 10;
	case RANK_KING:		return 10;
	case RANK_ACE:		return 11;
	}

	return 0;
}

char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

bool playBlackjack(const std::array<Card, 52> deck)
{
	const Card* cardPtr = &deck[0];

	int playerTotal = 0;
	int dealerTotal = 0;

	// ƒилер отримуЇ одну карту
	dealerTotal += getCardValue(*cardPtr++);
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// √равець отримуЇ дв≥ карти
	playerTotal += getCardValue(*cardPtr++);
	playerTotal += getCardValue(*cardPtr++);

	// √равець починаЇ
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += getCardValue(*cardPtr++);

		// ƒивимос€, чи гравець не програв
		if (playerTotal > 21)
			return false;
	}

	// якщо гравець не програв (у нього не б≥льше 21 очка), тод≥ дилер отримуЇ карти до тих п≥р, поки у нього в п≥дсумку буде не менше 17 очк≥в
	while (dealerTotal < 17)
	{
		dealerTotal += getCardValue(*cardPtr++);
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// якщо у дилера б≥льше 21 очка, то в≥н програв, а гравець виграв
	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // використовуЇмо системний годинник в €кост≥ стартового значенн€
	rand(); // користувачам Visual Studio: скидаЇмо перше згенероване (випадкове) число

	std::array<Card, 52> deck;

	// «вичайно, можна було б ≥н≥ц≥ал≥зувати кожну карту окремо, але нав≥що? јдже Ї цикли!
	int card = 0;
	for (int suit = 0; suit < MAX_SUITS; ++suit)
		for (int rank = 0; rank < MAX_RANKS; ++rank)
		{
			deck[card].suit = static_cast<CardSuit>(suit);
			deck[card].rank = static_cast<CardRank>(rank);
			++card;
		}

	shuffleDeck(deck);

	if (playBlackjack(deck))
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";

	return 0;
}*/