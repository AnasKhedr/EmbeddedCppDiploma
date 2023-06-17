#include <iostream>

// DIP: High-level modules should not depend on low-level modules. Both should depend on abstractions.

// Abstract Logger interface
class Logger {
public:
    virtual void log(const std::string& message) = 0;
};

// Concrete implementation of Logger: ConsoleLogger
class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << "Console Logger: " << message << std::endl;
    }
};

// Concrete implementation of Logger: FileLogger
class FileLogger : public Logger {
public:
    void log(const std::string& message) override {
        // Actual file logging implementation
        std::cout << "File Logger: " << message << std::endl;
    }
};

// Concrete implementation of Logger: FileLogger
class WebLogger : public Logger {
public:
    void log(const std::string& message) override {
        // Actual file logging implementation
        std::cout << "web Logger: " << message << std::endl;
    }
};

// High-level module: Application
class Application {
private:
    Logger& m_logger;

public:
    Application(Logger& logger) : m_logger(logger) {}

    void doSomething() {
        // Some application logic
        m_logger.log("Doing something...");
    }

    void doTask1() {
        // Some application logic
        m_logger.log("Doing Task 1...");
    }

    void doTask2() {
        // Some application logic
        m_logger.log("Doing Task 2...");
    }
};

int main() {
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
    WebLogger webLogger;

    Application appWithConsoleLogger(consoleLogger);
    appWithConsoleLogger.doSomething();
    appWithConsoleLogger.doTask1();

    Application appWithFileLogger(fileLogger);
    appWithFileLogger.doSomething();
    appWithFileLogger.doTask2();

    return 0;
}
