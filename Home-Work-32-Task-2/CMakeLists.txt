# CMakeList.txt: проект CMake для Home-Work-32-Task-2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Home-Work-32-Task-2 "Home-Work-32-Task-2.cpp" "Home-Work-32-Task-2.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_link_libraries(Home-Work-32-Task-2 PRIVATE nlohmann_json::nlohmann_json)