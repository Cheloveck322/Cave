#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <ctime>
#include <cassert>
#include <vector>
#include <string>

constexpr int g_maxValueOfGame {21};
constexpr int g_minValueForDealer {17};
constexpr int g_acesMinValue {1};
constexpr int g_acesMaxValue{11};

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


enum class Rank
{
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
    rank_ace,
    total_rank,
};


enum class Suits
{
    clubs, 
    diamonds,
    hearts,
    spades,
    total_suits,
};


struct Card
{
    Rank rank{};
    Suits suits{};
};


using Deck = std::array<Card, 52>;
using Index = Deck::size_type;


void printCard(const Card& card)
{
    switch (card.rank)
    {
    case Rank::rank_2:      std::cout << '2';   break;
    case Rank::rank_3:      std::cout << '3';   break;
    case Rank::rank_4:      std::cout << '4';   break;
    case Rank::rank_5:      std::cout << '5';   break;
    case Rank::rank_6:      std::cout << '6';   break;
    case Rank::rank_7:      std::cout << '7';   break;
    case Rank::rank_8:      std::cout << '8';   break;
    case Rank::rank_9:      std::cout << '9';   break;
    case Rank::rank_10:     std::cout << 'T';   break;
    case Rank::rank_jack:   std::cout << 'J';   break;
    case Rank::rank_queen:  std::cout << 'Q';   break;
    case Rank::rank_king:   std::cout << 'K';   break;
    case Rank::rank_ace:    std::cout << 'A';   break;
    default:
        std::cout << '?';
        break;
    }

    switch (card.suits)
    {
    case Suits::clubs:      std::cout << 'C';   break;
    case Suits::diamonds:   std::cout << 'D';   break;
    case Suits::hearts:     std::cout << 'H';   break;
    case Suits::spades:     std::cout << 'S';   break;
    default:
        std::cout << '?';
        break;
    }
}


Deck createDeck()
{
    Deck deck{};
    Index index{};

    for(int suit{}; suit < static_cast<int>(Suits::total_suits); ++suit)
    {
        for(int rank{}; rank < static_cast<int>(Rank::total_rank); ++rank)
        {
            deck[index].suits = static_cast<Suits>(suit);
            deck[index].rank = static_cast<Rank>(rank);
            ++index;
        }
    }

    return deck;
}


void printDeck(const Deck& deck)
{
    for(Card member : deck)
    {
        printCard(member);
        std::cout << ' ';
    }
    std::cout << '\n';
}


void shuffleDeck(Deck& cardDeck)
{
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(cardDeck.begin(), cardDeck.end(), mt);
}


int getCardValue(const Card& card)
{
    switch (card.rank)
    {
        case Rank::rank_2: return 2;
        case Rank::rank_3: return 3;
        case Rank::rank_4: return 4;
        case Rank::rank_5: return 5;
        case Rank::rank_6: return 6;
        case Rank::rank_7: return 7;
        case Rank::rank_8: return 8;
        case Rank::rank_9: return 9;
        case Rank::rank_10: 
        case Rank::rank_jack:
        case Rank::rank_queen:
        case Rank::rank_king: return 10;
        case Rank::rank_ace: return 11;

        default:
            assert(false && "should never happen");
            return 0;
    }
}


std::string getAnswer(std::string& answer)
{
    while(true)
    {
        std::cout << "What will you do? (hit/stand) ";
        std::cin >> answer;
        ignoreLine();

        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
        }
        else
        {
            if (answer == "hit" || answer == "stand")
                return answer;
            else
                std::cout << "That was invalid input, try again\n";
        }
    }
}


int roundPlayer(const Deck& cardDeck, std::string& answer, int& index, int& player)
{
    for(;;++index)
    {
        if (player > g_maxValueOfGame)
        {
            std::cout << "You busted!\n";
            break;
        }
        getAnswer(answer);
        if(answer == "stand")
            break;
        int cardValue {getCardValue(cardDeck.at(index++))};
        if (cardValue == 11)
        {
            if (player + cardValue > g_maxValueOfGame)
                cardValue = 1;
        }
        player += cardValue;
        std::cout << "You turned up a " << cardValue << " and now has " << player << '\n';
    } 
    return player;
}

int roundDealer(const Deck& cardDeck, int& index, int& dealer)
{
    while (dealer < g_minValueForDealer)
    {
        int cardValue {getCardValue(cardDeck.at(index++))};
        if (cardValue == 11)
        {
            if (dealer + cardValue > g_maxValueOfGame)
                cardValue = 1;
        }
        dealer += cardValue;
        std::cout << "The dealer turned up a " << cardValue << " and now has " << dealer << '\n';
    }
    return dealer;
}

bool playBlackjack(const Deck& cardDeck)
{
    int index{};
    int dealer{getCardValue(cardDeck.at(index++))};
    std::cout << "The dealer is showing: " << dealer << '\n';
    int player{getCardValue(cardDeck.at(index)) + getCardValue(cardDeck.at(index+1))};
    index += 2;
    std::cout << "Your score is " << player << '\n';
    std::string answer{};
    roundPlayer(cardDeck, answer, index, player); //gives to player a card and checks his answer 
    roundDealer(cardDeck, index, dealer); //like for player but to dealer
    
    if(dealer > g_maxValueOfGame)
        return true;
    else if(player <= g_maxValueOfGame && player > dealer)
        return true;
    else if(dealer < g_minValueForDealer)
        return true;
    else 
        return false;
}


int main()
{
    auto cardDeck{createDeck()};
    
    shuffleDeck(cardDeck);

    if(playBlackjack(cardDeck))
        std::cout << "Player wins! Congratulation!!!";
    else
        std::cout << "Dealer wins! Not today, player";

    return 0;
}

