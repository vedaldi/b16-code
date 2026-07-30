#ifndef __probes_hpp__
#define __probes_hpp__

#include <iostream>

// A test class with copy and move constructor and assignment
struct Movable {
    float x;

    Movable() : x{0}
    {
        std::cout << "Movable: Default-constructed" << '\n';
    }

    Movable(float x) : x{x}
    {
        std::cout << "Movable: Constructed from \"" << x << "\"\n";
    }

    Movable(const Movable& m) : x{m.x}
    {
        std::cout << "Movable: Copy-constructed" << '\n';
    }

    Movable(Movable&& m) noexcept : x{m.x}
    {
        m.x = 0;
        std::cout << "Movable: Move-constructed\n";
    }

    Movable& operator=(const Movable& m)
    {
        x = m.x;
        std::cout << "Movable: Copy-assigned\n";
        return *this;
    }

    Movable& operator=(Movable&& m)
    {
        x = m.x;
        m.x = 0;
        std::cout << "Movable: Move-assigned\n";
        return *this;
    }

    ~Movable() { std::cout << "Movable: Destructed\n"; }
};

// A test class with copy constructor and assignment only
struct Copyable {
    float x;

    Copyable() : x{0}
    {
        std::cout << "Copyable: Default-constructed\n";
    }

    Copyable(float x) : x{x}
    {
        std::cout << "Copyable: Constructed from \"" << x << "\"\n";
    }

    Copyable(const Copyable& m) : x{m.x}
    {
        std::cout << "Copyable: Copy-constructed\n";
    }

    Copyable& operator=(const Copyable& m)
    {
        x = m.x;
        std::cout << "Copyable: Copy-assigned\n";
        return *this;
    }

    ~Copyable() { std::cout << "Copyable: Destructed\n"; }
};

inline std::ostream& operator<<(std::ostream& os, const Movable& m)
{
    return os << m.x;
}

inline std::ostream& operator<<(std::ostream& os, const Copyable& c)
{
    return os << c.x;
}

#endif  // __probes_hpp__
