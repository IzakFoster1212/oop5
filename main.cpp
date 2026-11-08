#include <iostream>
#include "Course.h"

int main() {
    Course course("Объектно-ориентированное программирование");
    course.addTopic("Классы и объекты");
    course.addTopic("Композиция тем");

    std::cout << "Курс: " << course.getName() << "\n";
    std::cout << "Количество тем: " << course.getTopics().size() << "\n";

    return 0;
}