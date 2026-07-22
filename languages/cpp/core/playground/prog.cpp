// Would be compiled with: g++ -std=c++17 -o prog prog.cpp
// Question: What is the exact output of this program?

#include <iostream>

struct Obj {
    char id;
    Obj(char c) : id(c)              { std::cout << id << '+'; }
    Obj(const Obj& o) : id(o.id)     { std::cout << id << 'c'; }
    Obj(Obj&& o) : id(o.id)          { std::cout << id << 'm'; }
    ~Obj()                            { std::cout << id << '-'; }
};

Obj make_a()      { return Obj('A'); }
Obj make_b()      { return Obj('B'); }
Obj relay(Obj x)  { return x; }

struct Base {
    virtual void go(int n = 5) { std::cout << "B" << n; }
    virtual ~Base() = default;
};

struct Derived : Base {
    void go(int n = 9) override { std::cout << "D" << n; }
};

int main() {
    Obj a = make_a();
    std::cout << '.';
    Obj b = relay(make_b());
    std::cout << '.';
    Obj c = std::move(a);
    std::cout << '.';

    Derived d;
    Base* p = &d;
    d.go();
    p->go();

    std::cout << '.';
    return 0;
}
