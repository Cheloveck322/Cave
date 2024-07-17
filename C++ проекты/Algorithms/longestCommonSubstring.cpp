#include <iostream>
#include <memory>
#include <string>

void printGraph(const std::unique_ptr<std::unique_ptr<int[]>[]>& graph, int lengthA, int lengthB)
{
    for (int i{}; i < lengthA; ++i)
    {
        for (int j{}; j < lengthB; ++j)
        {
            std::cout << graph[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int longestCommonSubstring(const std::string& a, const std::string& b)
{
    auto graph { std::make_unique<std::unique_ptr<int[]>[]>(a.size() + 1) };
    int answer {};
    for (int i{}; i <= a.size(); ++i)
    {
        graph[i] = std::make_unique<int[]>(b.size() + 1);
    }

    for (int i{ 1 }; i <= a.size(); ++i)
    {
        for (int j{ 1 }; j <= b.size(); ++j)
        {
            if (a[i-1] == b[j-1])
            {
                graph[i][j] = graph[i-1][j-1] + 1;
            }
            else 
            {
                graph[i][j] = 0;
            }
            answer = std::max(answer, graph[i][j]);
        }
    }

    return answer;
}

int main()
{
    std::string a { "blue" };
    std::string b { "clues" };

    int longest { longestCommonSubstring(a, b) };

    std::cout << "The longest common substring is " << longest << '\n';

    return 0;
}