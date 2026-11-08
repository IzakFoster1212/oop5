#include <iostream>
#include <vector>
#include "Professor.h"
#include "Course.h"
#include "Student.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    std::cout << "=== Практическая работа №5: Агрегация и композиция ===\n\n";

    Professor prof1("Ломанов Александр Михайлович");
    Professor prof2("Иванов Иван Иванович");

    Course course1("Объектно-ориентированное программирование", &prof1);
    Course course2("Структуры и алгоритмы обработки данных", &prof2);

    course1.addTopic("Классы, инкапсуляция и конструкторы");
    course1.addTopic("Управление ресурсами: правило трёх");
    course1.addTopic("Композиция и агрегация объектов");

    course2.addTopic("Бинарные деревья поиска (СДП)");
    course2.addTopic("АВЛ-деревья и балансировка");
    course2.addTopic("Б-деревья и дисковые структуры");

    Student student("Руслан");
    student.enroll(&course1);
    student.enroll(&course2);

    student.enroll(&course1);

    std::cout << "--- Список курсов и преподавателей ---\n";
    std::cout << "Курс: " << course1.getName() << "\n";
    std::cout << "Преподаватель: " 
              << (course1.getProfessor() ? course1.getProfessor()->getName() : "Не назначен") << "\n";
    std::cout << "Количество тем: " << course1.getTopics().size() << "\nТемы:\n";
    for (const auto& topic : course1.getTopics()) {
        std::cout << "  - " << topic << "\n";
    }
    std::cout << "\n";

    std::cout << "Курс: " << course2.getName() << "\n";
    std::cout << "Преподаватель: " 
              << (course2.getProfessor() ? course2.getProfessor()->getName() : "Не назначен") << "\n";
    std::cout << "Количество тем: " << course2.getTopics().size() << "\nТемы:\n";
    for (const auto& topic : course2.getTopics()) {
        std::cout << "  - " << topic << "\n";
    }
    std::cout << "\n";

    std::cout << "--- Информация о студенте ---\n";
    std::cout << "Студент: " << student.getName() << "\n";
    std::cout << "Записан на курсы (всего " << student.getCourses().size() << "):\n";
    for (const Course* c : student.getCourses()) {
        std::cout << "  * " << c->getName() << " (Лектор: " 
                  << (c->getProfessor() ? c->getProfessor()->getName() : "—") << ")\n";
    }

    std::cout << "\n=== Завершение main: все объекты удаляются автоматически со стека ===\n";
    return 0;
}