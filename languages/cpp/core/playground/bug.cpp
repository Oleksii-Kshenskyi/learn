#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

struct Entry {
    int key;
    std::string label;
    double weight;

    Entry(int k, std::string_view l, double w)
        : key(k), label(l), weight(w) {}
};

static std::string formatLabel(int key) {
    return "item_" + std::to_string(key);
}

static Entry makeEntry(int key, double weight) {
    std::string label = formatLabel(key);
    return Entry(key, label, weight);
}

class Registry {
public:
    void add(int key, double weight) {
        entries_.push_back(makeEntry(key, weight));
    }

    const Entry* find(int key) const {
        auto it = std::find_if(
            entries_.begin(), entries_.end(),
            [key](const Entry& e) { return e.key == key; });
        return (it != entries_.end() ? &*it : nullptr);
    }

    double totalWeight() const {
        double sum = 0.0;
        for (const auto& e : entries_) sum += e.weight;
        return sum;
    }

    void dump() const {
        std::cout << "Registry (" << entries_.size() << " entries):\n";
        for (const auto& e : entries_) {
            std::cout << "  key=" << e.key
                      << " label=" << e.label
                      << " weight=" << e.weight << "\n";
        }
    }

private:
    std::vector<Entry> entries_;
};

int main() {
    Registry reg;
    for (int i = 0; i < 8; ++i) {
        reg.add(i, i * 0.25);
    }

    reg.dump();

    std::cout << "total weight = " << reg.totalWeight() << "\n";

    if (const auto* e = reg.find(3)) {
        std::cout << "found entry: key=" << e->key
                  << " label=" << e->label << "\n";
    }


    return 0;
}
