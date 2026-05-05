#include "Star.cpp"
#include "turtle.h"
#include "Triangle.cpp"
#include "Rectangle.cpp"
#include "Square.cpp"
#include "Drawable.cpp"
#include "Line.cpp"

void playlist(int count, Drawable** arr);

int main(int argc, char *argv[])
{
    srand(time(nullptr));
    rand();

    Turtle *tp = new Turtle;
    tp->init();

    Drawable** objArr = new Drawable*[argc - 1];
    Drawable** ptr = objArr;
    int count = 0;


    for (int i = 0; i < argc - 1; i++) {
        try {
            srand(stoi(*(argv + i + 1)));
            rand();
            cout << "Parsed " << stoi(*(argv + i + 1)) << " First: " << rand() << " " << rand() << endl;
        } catch (invalid_argument e) {
            string input = toLowerCase(*(argv + i + 1));

            cout << endl << input << endl;
            if (input == "square") {
                (*(ptr++)) = (new Square());
            } else if (input == "rectangle") {
                (*(ptr++)) = (new Rectangle());
            } else if (input == "star") {
                (*(ptr++)) = (new Star());
            } else if (input == "triangle") {
                (*(ptr++)) = (new Triangle());
            } else if (input == "line") {
                (*(ptr++)) = (new Line());
            } else {
                break;
            }
            (*(ptr-1))->SetTurtle(tp);
            cout << "Created Shape!" << endl  << *(objArr + count) << endl;
            count++;
        }
    }

    playlist(count, objArr);


    waitKey(30000);
    delete[] objArr;
    delete tp;
    return 0;
}

void playlist(int count, Drawable** arr) {
    for (int i = 0; i < count; i++) {
        try {
            cout << "Drawing from: " << *(arr + i) << endl;
            (*(arr + i))->Draw();
            waitKey(4000);
        } catch (Exception e) { // I don't think this is the correct exception type
            cout << "Not an object";
        }
    }
}