//
// Created by break on 2023/11/26.
//

#include "HashTable.h"

HashTable::HashTable(int size) {
    this->table_Size = size;
    this->table.resize(size);
}

void HashTable::insert(const std::string &key, int value) {
    auto idx = hashFunction(key);
    table[idx].emplace_back(key , value);
}

int HashTable::search(const std::string &key) const{
    auto idx = hashFunction(key);
    for(const auto& t : table[idx]){
        if(t.first == key){
            return t.second;
        }
    }
    return -1;
}

int HashTable::hashFunction(const std::string& key) const{
    return static_cast<int>(key.size()) % this->table_Size;
}
