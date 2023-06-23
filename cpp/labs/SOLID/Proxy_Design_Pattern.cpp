#include <iostream>
#include <string>
#include <memory>

// https://refactoring.guru/design-patterns/proxy

// Abstract Subject
class Image {
public:
    virtual void display() = 0;
};

// Real Subject
class RealImage : public Image {
private:
    std::string filename;

public:
    RealImage(const std::string& filename) : filename(filename) {
        loadFromDisk();
    }

    void display() override {
        std::cout << "Displaying image: " << filename << std::endl;
    }

private:
    void loadFromDisk() {
        std::cout << "Loading image from disk: " << filename << std::endl;
    }
};

// Proxy
class ImageProxy : public Image {
private:
    std::string filename;
    std::unique_ptr<RealImage> realImage;
    std::string password = "passw0rd";

public:
    ImageProxy(const std::string& filename) : filename(filename), realImage(nullptr) {}

    bool authenticate() const {
        // Simulating authentication
        std::string input;
        std::cout << "Enter password: ";
        std::cin >> input;
        return input == password;
    }

    void display() override {
        if (realImage == nullptr) {
            realImage = std::make_unique<RealImage>(filename);
        }

        if(authenticate())
        {
            realImage->display();
        }
        else
        {
            std::cout << "You are NOT authorized to display the image!!\n";
        }
    }


};

int main() {
    // Accessing image through the proxy
    ImageProxy image("image.jpg");

    // Image is loaded only when display() is called
    image.display();
    image.display();

    return 0;
}
