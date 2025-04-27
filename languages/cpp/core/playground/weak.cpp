#include <iostream>
#include <memory>
#include <vector>

class Observer {
public:
    Observer() { std::cout << "Observer created\n"; }
    ~Observer() { std::cout << "Observer destroyed\n"; }
    void onNotify() { std::cout << "Observer notified\n"; }
};

class Notifier {
public:
    // Hold non-owning references to observers
    std::vector<std::weak_ptr<Observer>> observers;
    
    // Add an observer to the list (stored as a weak pointer)
    void addObserver(const std::shared_ptr<Observer>& obs) {
        observers.push_back(obs);
    }
    
    // Notify all observers that are still alive.
    void notify() {
        for (auto it = observers.begin(); it != observers.end(); ) {
            if (auto obs = it->lock()) { // Try to get a shared_ptr from the weak_ptr.
                obs->onNotify();        // Safe to use the observer.
                ++it;
            } else {
                // The Observer has been destroyed, so remove the dangling weak pointer.
                it = observers.erase(it);
                std::cout << "Removed dangling observer\n";
            }
        }
    }
};

int main() {
    Notifier notifier;
    
    {
        // Create an observer and register it with the notifier.
        auto obs1 = std::make_shared<Observer>();
        notifier.addObserver(obs1);
        std::cout << "First notification:\n";
        notifier.notify(); // Observer is alive, so it is notified.
    } // obs1 goes out of scope and is destroyed here.
    
    std::cout << "\nSecond notification:\n";
    notifier.notify(); // The observer is gone; the weak pointer prevents a dangling reference.
    
    return 0;
}
