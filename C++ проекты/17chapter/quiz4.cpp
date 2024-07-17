#include <iostream>
#include <array>
#include <algorithm>
#include "Random.h"
#include <cassert>

namespace Settings
{
    constexpr int bustScore { 21 };
    constexpr int dealerStop { 17 };

    enum GameResult
    {
        player_wins,
        player_loses,
        result_tie
    };
}

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

struct Player
{
    int score{};
    int countOfAces{};
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

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch {};
        std::cin >> ch;

        switch (ch)
        {
            case 'h':
                return true;
            case 's':
                return false;
        }
    }
}

bool playerTurn(Deck& deck, Player& player)
{
    while (player.score < Settings::bustScore && playerWantsHit())
    {
        Card card { deck.dealCard() };
        player.score += card.value();

        if (card.rank == Card::rank_ace)
        {
            ++player.countOfAces;
        }

        while (player.score > Settings::bustScore && player.countOfAces > 0)
        {
            player.score -= 10;
            --player.countOfAces;
        }

        std::cout << "You were dealt " << card << ".  You now have: " << player.score << '\n';
    }

    if (player.score > Settings::bustScore)
    {
        std::cout << "You went bust!\n";
        return true;
    }

    return false;
}

bool dealerTurn(Deck& deck, Player& dealer)
{
    while (dealer.score < Settings::dealerStop)
    {
        Card dealtCard { deck.dealCard() };
        dealer.score += dealtCard.value();

        if (dealtCard.rank == Card::rank_ace)
        {
            ++dealer.countOfAces;
        }
        
        while (dealer.score > Settings::bustScore && dealer.countOfAces > 0)
        {
            dealer.score -= 10;
            --dealer.countOfAces;
        }

        std::cout << "The dealer flips a " << dealtCard  << ".  They now have: " << dealer.score << '\n';
    }

    if (dealer.score > Settings::bustScore)
    {
        std::cout << "The dealer went bust!\n";
        return true;
    }

    return false;
}

Settings::GameResult playBlackJack()
{
    Deck deck {};
    deck.shuffle();

    Card card { deck.dealCard() };

    Player dealer { card.value() }; 

    if (card.rank == Card::rank_ace)
        ++dealer.countOfAces;

    std::cout << "The dealer is showing " << card << " (" << dealer.score << ")\n";

    card = deck.dealCard();
    Card card1 { deck.dealCard() };

    Player player { card.value() + card1.value() };

    if (card.rank == Card::rank_ace)
        ++player.countOfAces;
    if (card1.rank == Card::rank_ace)
        ++player.countOfAces;

    std::cout << "You are showing " << card << ' ' << card1 << " (" << player.score << ")\n";

    if (playerTurn(deck, player))
        return Settings::player_loses;

    if (dealerTurn(deck, dealer))
        return Settings::player_wins;
    
    if (player.score > dealer.score)
        return Settings::player_wins;
    else if (player.score == dealer.score)
        return Settings::result_tie;
    else 
        return Settings::player_loses;
}

int main()
{
    Settings::GameResult game { playBlackJack() };
    if (game == Settings::player_wins)
        std::cout << "You win!\n";
    else if (game == Settings::player_loses)
        std::cout << "You lose!\n";
    else 
        std::cout << "It's tie!\n";

    return 0;
}