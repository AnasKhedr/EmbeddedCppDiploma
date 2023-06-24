#include <iostream>

class MyClass {
private:
    int privateData;

    // Declaration of FriendClass as a friend
    friend class FriendClass;   // class can access all member including private
    // Declaration of the friend function
    friend void friendFunction(const MyClass& obj); // function can access all member including private

public:
    MyClass() : privateData(0) {}

    int getPrivateData() const {
        return privateData;
    }
};

class FriendClass {
public:
    void accessPrivateData(const MyClass& obj)
    {
        std::cout << "[accessPrivateData] private data of MyClass from FriendClass: " << obj.privateData << std::endl;
    }
};

// Definition of the friend function
void friendFunction(const MyClass& obj) {
    std::cout << "[friendFunction] The private data of MyClass is: " << obj.privateData << std::endl;
}

int main() {
    MyClass obj;
    FriendClass friendObj;

    friendObj.accessPrivateData(obj);
    friendFunction(obj);

    return 0;
}
