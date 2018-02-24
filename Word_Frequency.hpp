/**
 * Name:Junjie Chen
 * Date:12/6/2017
 *
 */

#ifndef A6_STRINGSTORE_HPP
#define A6_STRINGSTORE_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <forward_list>

using namespace std;
class StringStore {
    std::unordered_map<std::string, size_t>store_string;

public:

    void insert(const std::string&);
    size_t getFrequency(const std::string&) const;
    bool removeString(const std::string&);
    std::pair<std::string,size_t> getMaxFrequency()const ;
    std::vector<std::pair<std::string,size_t>> getTopKFrequency(size_t k) const;
};

#endif //A6_STRINGSTORE_HPP
