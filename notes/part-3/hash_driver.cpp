#include "hash.hpp"
#include <iostream>
#include <string>

constexpr size_t num_chains = 31;

struct HashFunction {
    size_t operator()(const std::string &str)
    {
        size_t value = 0;
        for (auto c : str) { value += c; }
        return value % num_chains;
    }
};

int main(int agrc, char **argv)
{
    HashTable<std::string, int, HashFunction> hash_table{num_chains};

    int value = 0;
    for (auto key : {"Apple", "Apricots", "Avocado", "Banana", "Blackberries",
                     "Blackcurrant", "Blueberries", "Breadfruit", "Cantaloupe",
                     "Carambola", "Cherimoya", "Cherries", "Clementine"}) {
        hash_table.insert(key, value++);
    }

    hash_table.print();

    std::cout << "'Carambola' is the " << *hash_table.get("Carambola")
              << "-th fruit\n";

    std::cout << "Retrieving 'Beans' results in the pointer value "
              << hash_table.get("Beans") << "\n";
    return 0;
}
