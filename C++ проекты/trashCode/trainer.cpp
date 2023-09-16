#include <vector>
#include <iostream>



std::vector<int> prime_factors(long n){
  
    std::vector<int> sequence{};
    int divider{2};
  
    while (n > 0)
  {
    if (n % divider == 0)
    {
      sequence.push_back(divider);
      n /= divider;
    }
    else
    {
      ++divider;
    }
  }
  for (int value: sequence)
  {
    std::cout << value << ' ';
  }
  return sequence;
}