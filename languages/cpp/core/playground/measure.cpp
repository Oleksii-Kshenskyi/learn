#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <utility>

struct Thing {
    int thingval;

    Thing(int thingval) : thingval(thingval) {}

    Thing(const Thing& other) : thingval(other.thingval) {}

    Thing(Thing&& other) : thingval(other.thingval) {}
};

void mlnthings_c() {
    Thing torig(35);
    for(int i = 0; i < 1000000000; i++) {
        Thing tnew(torig);
        tnew.thingval;
    }
}

void mlnthings_m() {
    Thing torig(35);
    for(int i = 0; i < 1000000000; i++) {
        Thing tnew(std::move(torig));
        tnew.thingval;
    }
}

int main() {
    mlnthings_m();
    return 0;
}
