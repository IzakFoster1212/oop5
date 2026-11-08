#include <iostream>
#include "Professor.h"
#include "Course.h"
#include "Student.h"

int main() {
    Professor prof("Сажнев Александр Михайлович");
    Course course("Объектно-ориентированное программирование", &prof);

    Student student("Руслан");
    student.enroll(&course);
    student.enroll(&course);

    std::cout << "Студент: " << student.getName() << "\n";
    std::cout << "Курсов записано: " << student.getCourses().size() << "\n";

    return 0;
}