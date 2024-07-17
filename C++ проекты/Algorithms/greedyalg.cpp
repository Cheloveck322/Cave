#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>

using Set = std::set<std::string>;
using UMSet = std::unordered_map<std::string, Set>;
using UMSetIterator = UMSet::iterator;

Set greedyAlg(Set& sNeeded, UMSet& stations)
{
    Set final_stations {};
    while (!sNeeded.empty())
    {
        std::string best_station{};
        Set states_covered {};
        for (UMSetIterator it { stations.begin() }; it != stations.end(); ++it)
        {
            Set covered {};
            std::set_intersection(sNeeded.begin(), sNeeded.end(), it->second.begin(), it->second.end(),
                                    std::inserter(covered, covered.end()) );
            if (covered.size() > states_covered.size())
            {
                best_station = it->first;
                states_covered = it->second;
            }
        }
        for (const auto e : states_covered)
            sNeeded.erase(e);
        final_stations.insert(best_station);
    }
    return final_stations;
}

int main()
{
    Set states_needed { "mt", "wa", "or", "id", "nv", "ut", "ca", "az" };

    UMSet stations{};
    stations["kone"] = Set{ "id", "nv", "ut" };
    stations["ktwo"] = Set{ "wa", "id", "mt" };
    stations["kthree"] = Set{ "or", "nv", "ca" };
    stations["kfour"] = Set{ "nv", "ut" };
    stations["kfive"] = Set{ "ca", "az" };

    Set final_stations { greedyAlg(states_needed, stations) };

    for (const auto e : final_stations)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}