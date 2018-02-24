/**
* Name:Junjie Chen
* Date:12/6/2017
*
*/
#include "a6.hpp"
using namespace std;

void StringStore::insert(const std::string&newaddstring)
{
    unordered_map<std::string, size_t>::iterator it;
    it = store_string.find(newaddstring);
    if (it == store_string.end()){
        store_string.insert(std::pair<std::string,size_t>(newaddstring, 1));
        return;
    }
    else{
        ++it->second;
        return;
    }
}

size_t StringStore::getFrequency(const std::string &findstring) const {
    unordered_map<std::string, size_t>temp = store_string;
    unordered_map<std::string, size_t>::iterator it;
    it = temp.find(findstring);
    if (it != temp.end()){
        return it->second;
    }
    return 0;
}
bool StringStore::removeString(const std::string &removestring) {
    unordered_map<std::string, size_t>::iterator it;
    it = store_string.find(removestring);
    if (it != store_string.end()){
        store_string.erase(removestring);
        return true;
    }
    return false;
}

std::pair<std::string, size_t> StringStore::getMaxFrequency() const {
    if (store_string.empty())
        return std::pair<std::string, size_t>("", 0);
    auto max=store_string.begin();
    for (auto it = store_string.begin(); it != store_string.end(); ++it)
    {
        if (it->second > max->second)
            max = it;
    }
    return *max;
}
std::vector<std::pair<std::string, size_t>> StringStore::getTopKFrequency(size_t k) const {
    std::unordered_map<std::string, size_t>temp = store_string;
    std::vector<std::pair<std::string, size_t>> temp2;
    if (!store_string.empty())
    {
        for (size_t i = 0; i < k; i++){
            auto max = temp.begin();
            for (auto it = temp.begin(); it != temp.end(); ++it)
            {
                if (it->second > max->second)
                    max = it;
            }
            temp2.push_back(*max);
            temp.erase(max->first);
        }
    }
    return temp2;
}
