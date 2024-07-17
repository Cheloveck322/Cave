#include <iostream>
#include <vector>
#include "Random.h"
#include <string_view>
#include <algorithm>

namespace Settings
{
    constexpr int g_countOfGuesses { 6 };
}

namespace WordList
{
    using namespace std::literals::string_view_literals;
    std::vector words{ "broccoli"sv, "account"sv, "almost"sv, "spaghetti"sv, "opinion"sv, "beautiful"sv, "distance"sv, "luggage"sv};

    std::string_view getRandomWord()
    {
        return words[Random::get<std::size_t>(0, words.size() - 1)];
    }
}

class Session
{
private:
    std::string_view m_word{ WordList::getRandomWord() };
    std::vector<bool> m_guessedLetters { std::vector<bool>(26) };
    int m_countLeftWrongGuess { Settings::g_countOfGuesses };

    std::size_t toIndex(char c) const { return static_cast<std::size_t>((c % 32) - 1); }

public:
    std::string_view getWord() const { return m_word; }

    int wrongGuessesLeft() const { return m_countLeftWrongGuess; }
    void removeGuess() { --m_countLeftWrongGuess; }

    bool isLetterGuessed(char c) const { return m_guessedLetters[toIndex(c)]; }
    void setLetterGuessed(char c) { m_guessedLetters[toIndex(c)] = true; }   

    bool isLetterInWord(char c) const
    {
        for (const auto& e : m_word)
        {
            if (e == c)
                return true;
        }
        return false;
    } 

    bool won()
    {
        for (auto c : m_word)
        {
            if (!(isLetterGuessed(c)))
                return false;
        }

        return true;
    }
};

void draw(const Session& game)
    {
        std::cout << '\n';

        std::cout << "The word: ";
        for (const auto& letter : game.getWord())
        {
            if (game.isLetterGuessed(letter))
            {
                std::cout << letter;
            }
            else 
            {
                std::cout << '_';
            }
        }

        std::cout << "   Wrong guesses: ";
        for (int i { 0 }; i < game.wrongGuessesLeft(); ++i)
        {
            std::cout << '+';
        }

        for (char c = 'a'; c < 'z'; ++c)
            if (!(game.isLetterInWord(c)) && game.isLetterGuessed(c))
                std::cout << c;
        
        std::cout << '\n';
    }

char getGuess(const Session& s)
{
    while(true)
    {
        std::cout << "Enter your next letter: ";
        char input{};
        std::cin >> input;

        if (!std::cin || !(input >= 'a' && input <= 'z'))
        {
            if (std::cin.eof()) 
                exit(0);

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "That wasn't a valid input.  Try again.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        if (s.isLetterGuessed(input))
        {
            std::cout << "You already guessed that.  Try again.\n";
            continue;
        }

        return input;
    }
}

void handleGuess(Session& s, char c)
{
    s.setLetterGuessed(c);

    if (s.isLetterInWord(c))
    {
        std::cout << "Yes, '" << c << "' is in the word!\n";
        return;
    }
    std::cout << "No, '" << c << "' is not in the word!\n";
    s.removeGuess();
}

int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n";

    Session s{};

    while (!s.won() && s.wrongGuessesLeft()) 
    {
        draw(s);
        char c { getGuess(s) };
        handleGuess(s, c);
    }

    draw(s);

    return 0;
}