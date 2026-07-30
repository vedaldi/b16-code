#include "array.hpp"
#include "array_insert_movable.hpp"
#include "utils.hpp"
#include "probes.hpp"

std::vector<Movable> make_test_array()
{ 
    std::cout << "Constructing an array of Movable objects\n";
    auto A = std::vector<Movable>{};
    A.reserve(10);
    A.push_back(Movable{1});
    A.push_back(Movable{2});
    A.push_back(Movable{3});
    print(A, "Constructed array: ");
    std::cout << "\n";
    return A;
}

int main(int argc, char** argv)
{
    {
        auto A = make_test_array();
        auto x = Movable{-1};
        std::cout << "Insertinig object by copy:" << '\n';
        array_insert(A, 0, x);
        print(A, "Array content: ");
    }

    std::cout << "\n";

    {
        auto A = make_test_array();
        auto x = Movable{-1};
        std::cout << "Insertinig object by copying and moving:" << '\n';
        array_insert_movable(A, 0, x);
        print(A, "Array content: ");
    }

    std::cout << "\n";

    {
        auto A = make_test_array();
        auto x = Movable{-1};
        std::cout << "Insertinig object by moving:" << '\n';
        array_insert_movable(A, 0, std::move(x));
        print(A, "Array content: ");
    }

    return 0;
}
