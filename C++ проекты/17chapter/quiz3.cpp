#include <iostream>
#include <array>
#include <algorithm>
#include "Random.h"
#include <cassert>

struct Card
{
    enum Ranks 
    {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_ranks
    };

    enum Suits
    {
        suit_clubs,
        suit_diamonds, 
        suit_heart,
        suit_spade,

        max_suits
    };

    static constexpr std::array<Ranks, max_ranks> allRanks { rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king };
    static constexpr std::array<Suits, max_suits> allSuits { suit_clubs, suit_diamonds, suit_heart, suit_spade };

    Ranks rank{};
    Suits suit{};

    friend std::ostream& operator<<(std::ostream& out, const Card &card)
    {
        static constexpr std::array rankNames { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
        static constexpr std::array suitNames { 'C', 'D', 'H', 'S'};

        out << rankNames[card.rank] << suitNames[card.suit];
        return out;
    }    

    int value() const
    {
        static constexpr std::array rankValue { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
        return rankValue[rank];
    }
};

class Deck
{
private:
    std::array<Card, 52> m_cards{};
    std::size_t m_nextCardIndex { 0 };

public:
    explicit Deck()
    {
        std::size_t count { };
        for (auto suit : Card::allSuits)
            for (auto rank : Card::allRanks)
            {
                m_cards[count++] = Card{ rank, suit };
            }           
    }

    Card dealCard()
    {
        assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards");
        return m_cards[m_nextCardIndex++];
    }

    void shuffle()
    {
        std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
        m_nextCardIndex = 0;
    }
};

int main()
{
    Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    return 0;
}