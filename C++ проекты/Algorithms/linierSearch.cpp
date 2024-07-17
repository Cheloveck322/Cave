#include <iostream>
#include <utility>

int findX(int seq[], int x, int length)
{
    int min { -1 };
    for (int i { 0 }; i < length; ++i)
    {
        if (seq[i] == x && min == -1)
        {
            min = i;
        }
    }
    return min;
}

int findRightX(int seq[], int x, int length)
{
    int min { -1 };
    for (int i { length - 1 }; i > 0; --i)
    {
        if (seq[i] == x && min == -1)
        {
            min = i;
        }
    }
    return min;
}

int findMax(int seq[], int length)
{
    int min {}; // index of max
    for (int i{ 1 }; i < length; ++i)
    {
        if (seq[i] > seq[min])
        {
            min = i;
        }
    }
    return seq[min];
}

int findMaxIndex(int seq[], int length)
{
    int min {}; // index of max
    for (int i{ 1 }; i < length; ++i)
    {
        if (seq[i] > seq[min])
        {
            min = i;
        }
    }
    return min;
}

template<typename T>
std::pair<T, T> findMaxAndPreMax(T seq[], int length)
{
    std::pair<int, int> pairMaxesIndex{ (seq[0] > seq[1] ? std::pair{ 0, 1 } : std::pair{ 1, 0 }) }; // first - max, second - preMax
    for (int i{ 2 }; i < length; ++i)
    {
        if (seq[pairMaxesIndex.first] < seq[i]) // if current max is less then current element
        {
            pairMaxesIndex.second = pairMaxesIndex.first;
            pairMaxesIndex.first = i;
        }
        else if (seq[pairMaxesIndex.second] < seq[i]) // if current preMax is less then current element
        {
            pairMaxesIndex.second = i;
        }
    }
    return std::pair{ seq[pairMaxesIndex.first], seq[pairMaxesIndex.second] };
}

int findEvenMin(int seq[], int length)
{
    int min { -1 };
    bool flag { false };

    if (length < 1)
        return -1;

    for (int i{}; i < length; ++i)
    {
        if ((!flag || min > seq[i]) && seq[i] % 2 == 0)
        {
            min = seq[i];
            flag = true;
        }
    }
    return min;
}

int main()
{
    int seq[] { 3, 4, 6, 10, 65, 1, 65, 5, 7, 10, 120 };
    int seq1[] { 1, 2, 3, 4, 5, 6, 7, 8, 8, 9 };
    int seq2[] { 1, 3, 5, 7, 9, 11, 13, 15};
    int length { std::size(seq) };
    int length1 { std::size(seq1) };
    int length2 { std::size(seq2) };
    int x { 10 };
    std::pair<int, int> maxes{ findMaxAndPreMax(seq, length) };
    int minEvenNumber { findEvenMin(seq, length) };

    std::cout << "The first left of " << x << " is " << findX(seq, x, length) << '\n';
    std::cout << "The first right of " << x << " is " << findRightX(seq, x, length) << '\n';
    std::cout << "Maximum element of sequence is " << findMax(seq, length) << '\n';
    std::cout << "Maximum is " << maxes.first << " and pre maximum is " << maxes.second << '\n';
    std::cout << "Minimum even number in sequence is " << minEvenNumber << '\n';

    return 0;
}