#include <iostream>
#include "Professor.h"
#include "Course.h"

int main() {
    Professor prof("Сажнев Александр Михайлович");
    Course course("Объектно-ориентированное программирование", &prof);

    course.addTopic("Классы и объекты");
    course.addTopic("Агрегация профессора");

    std::cout << "Курс: " << course.getName() << "\n";
    if (course.getProfessor()) {
        std::cout << "Преподаватель: " << course.getProfessor()->getName() << "\n";
    }

    return 0;
}