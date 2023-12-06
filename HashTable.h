//
// Created by break on 2023/11/26.
//

#ifndef UNTITLED1_HASHTABLE_H
#define UNTITLED1_HASHTABLE_H

#include <list>
#include <vector>
#include <string>

class HashTable {
private:
    int table_Size;
    std::vector<std::list<std::pair<std::string , int>>> table;
public:
    HashTable(int size);
    void insert(const std::string& key , int value);
    int search(const std::string& key) const;
    int hashFunction(const std::string& key) const;

};


#endif //UNTITLED1_HASHTABLE_H
