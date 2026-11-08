#pragma once

#include <string>

class Professor {
private:
    std::string name_;

public:
    explicit Professor(const std::string& name);
    const std::string& getName() const;
    ~Professor() = default;
};