#include <iostream>

///NOTE: Liskov Substitution Principle is satisfied when "is a" relation ship holds

// Base bird class
class IBird {
public:
    virtual void eat() const = 0;
};

class IFlyableBird : public IBird {
public:
    virtual void fly() const = 0;
};

// Regular bird class
class RegularBird : public IBird {
public:
    void eat() const override {
        std::cout << "Regular Bird: Eating..." << std::endl;
    }
};

// Flyable bird class
class FlyableBird : public IFlyableBird {
public:
    void eat() const override {
        std::cout << "Flyable Bird: Eating..." << std::endl;
    }

    void fly() const {
        std::cout << "Flyable Bird: Flying..." << std::endl;
    }
};

// IBird watcher class
class BirdWatcher {
public:
    void watchRegularBird(const IBird& bird) const {
        std::cout << "I Can see that the bird is doing the following actions\n";
        bird.eat();
        std::cout << "------\n";
    }

    void watchFlyableBird(const IFlyableBird& bird) const {
        std::cout << "I Can see that the bird is doing the following actions\n";
        bird.eat();
        bird.fly();
        std::cout << "------\n";
    }
};

int main() {
    RegularBird chicken;
    FlyableBird pigeon;

    BirdWatcher birdWatcher;

    // IBird watcher can watch any bird
    birdWatcher.watchRegularBird(chicken);
    birdWatcher.watchRegularBird(pigeon);
    birdWatcher.watchFlyableBird(pigeon);

    // Regular bird cannot fly
    // But we can still treat it as a bird
    IBird& regularBirdRef = chicken;
    regularBirdRef.eat();

    // Flyable bird can fly and eat
    FlyableBird& flyableBirdRef = pigeon;
    flyableBirdRef.eat();
    flyableBirdRef.fly();

    return 0;
}
