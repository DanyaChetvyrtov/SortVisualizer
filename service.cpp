#include "service.h"


void fillArray(row* user_array, int array_size) {
    srand(time(0));

    for (int i = 0; i < array_size; i++) {
        user_array[i].x = i;
        user_array[i].y = 1 + rand() % 550;
    }
}

void shellSortStep(row* rows, int &step, int &i, int &j) {
    if (step > 0) {
        if (i < ARRAY_SIZE) {
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

void gnomSortStep(row* rows, int& i) {
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


void exit(RenderWindow& window, Event& event) {
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed)
            window.close();
    }
}

void toDraw(RenderWindow& window, RectangleShape& rectangle, row* rows, int i, int j = 0) {

    window.clear(Color::Black);

    for (int k = 0; k < ARRAY_SIZE; k++) {
        rectangle.setSize(Vector2f(2, rows[k].y));
        rectangle.setPosition(Vector2f(k, 600));
        rectangle.setRotation(180);
        rectangle.setFillColor(Color(0, 70, 40));
        if (k == i || k == j)
            rectangle.setFillColor(Color::Red);
        window.draw(rectangle);
    }

    window.display();
}



void mainPart(int mode) {

    RenderWindow window(VideoMode(800, 600), "shellSort");
    RectangleShape rectangle;
    Event event;

    row* rows = new row[ARRAY_SIZE];

    bool isCreated = false;

    int step = ARRAY_SIZE / 2;
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

        // Заполнение массива
        if (!isCreated) {
            fillArray(rows, ARRAY_SIZE);
            isCreated = true;
        }

        // Шаг сортировки
        switch (mode) {
        case 1:
            shellSortStep(rows, step, i, j);
            break;
        case 2:
            gnomSortStep(rows, i);
            break;
        }

        // Отрисовка
        toDraw(window, rectangle, rows, i, j);
    }
    delete[] rows;
    rows = nullptr;
}
