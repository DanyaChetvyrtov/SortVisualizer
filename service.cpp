#include "service.h"


void ShellSort(int* mass, int n)
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}

void GnomeSort(int* arr, int n)
{
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            std::swap(arr[index], arr[index - 1]);
            index--;
        }
    }
    return;
}

void fillArray(row* user_array, int* array_from_file, int array_size) {

    for (int i = 0; i < array_size; i++) {
        user_array[i].x = i;
        user_array[i].y = array_from_file[i];
    }
}

void shellSortStep(row* rows, int size, int &step, int &i, int &j) {
    if (step > 0) {
        if (i < size) {
            int tmp = rows[i].y;
            for (j = i; j >= step && tmp < rows[j - step].y; j -= step) {
                rows[j].y = rows[j - step].y;
            }
            rows[j].y = tmp;
            i++;
        }
        else {
            i = step;
            step /= 2;
        }
    }
}

void gnomSortStep(row* rows, int& i, int size) {
    if(i < size){
        if (rows[i - 1].y <= rows[i].y) {
            i++;
        }
        else {
            std::swap(rows[i - 1].y, rows[i].y);
            if (i > 1) {
                i--;
            }
        }
    }
}

// Для выключения окна SFML
void exit(RenderWindow& window, Event& event) {
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed)
            window.close();
    }
}

void toDraw(RenderWindow& window, RectangleShape& rectangle, row* rows, int array_size, int i, int j) {

    window.clear(Color::White);

    for (int k = 0; k < array_size; k++) {
        rectangle.setSize(Vector2f(800.0 / array_size, rows[k].y));
        rectangle.setPosition(Vector2f((800.0 / array_size) * k, 600));
        rectangle.setRotation(180);
        rectangle.setFillColor(Color(0, 0, 0));
        if (k == i || k == j){
            rectangle.setFillColor(Color::Red);
        }
        window.draw(rectangle);
    }

    window.display();
}

void mainPart(int mode, int* arrayFromFile, int arraySize) {

    RenderWindow window(VideoMode(800, 600), "shellSort");
    RectangleShape rectangle;
    Event event;

    row* rows = new row[arraySize];

    fillArray(rows, arrayFromFile, arraySize);

    int step = arraySize / 2;
    int j = 0;
    int i;

    switch (mode) {
    case 1:
        i = step;
        break;
    case 2:
        i = 1;
        break;
    }

    while (window.isOpen()) {
        // Условие выхода
        exit(window, event);

        // Шаг сортировки
        switch (mode) {
        case 1:
            shellSortStep(rows, arraySize, step, i, j);
            break;
        case 2:
            gnomSortStep(rows, i, arraySize);
            break;
        }

        // Отрисовка
        toDraw(window, rectangle, rows, arraySize, i, j);
    }

    delete[] rows;
    rows = nullptr;
}

int countIntegers(const std::string &input) {
    std::stringstream ss(input);
    std::string temp;
    int count = 0;

    while (ss >> temp) {
        char* end;
        std::strtol(temp.c_str(), &end, 10);
        if (*end == '\0') {
            ++count;
        }
    }

    return count;
}

int* extractNumbers(const std::string &input, int &count) {
    std::stringstream ss(input);
    std::string temp;
    int number;
    count = 0;

    // Сначала подсчитаем количество чисел
    std::stringstream ssCount(input);
    while (ssCount >> temp) {
        char* end;
        std::strtol(temp.c_str(), &end, 10);
        if (*end == '\0') {
            ++count;
        }
    }

    // Выделим память под массив чисел
    int* numbers = new int[count];
    int index = 0;

    // Извлекаем числа и заполняем массив
    while (ss >> temp) {
        char* end;
        number = std::strtol(temp.c_str(), &end, 10);
        if (*end == '\0') {
            numbers[index++] = number;
        }
    }

    return numbers;
}

std::string arrayToString(int* array, int size) {
    if (array == nullptr || size <= 0) {
        return "";
    }

    std::ostringstream oss;
    for (int i = 0; i < size; ++i) {
        oss << array[i];
        if (i < size - 1) {
            oss << " ";
        }
    }

    return oss.str();
}
