#pragma once

#include <string>
#include <vector>

class Professor;

class Course {
private:
    std::string name_;
    std::vector<std::string> topics_;
    Professor* professor_;

public:
    Course(const std::string& name, Professor* prof = nullptr);
    void addTopic(const std::string& topic);
    const std::string& getName() const;
    const std::vector<std::string>& getTopics() const;
    const Professor* getProfessor() const;
    ~Course() = default;
};