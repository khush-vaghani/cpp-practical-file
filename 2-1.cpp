#include <iostream>
#include <vector>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l = 0.0, double w = 0.0) {
        length = l;
        width = w;
    }

    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }

    double getArea() const {
        return length * width;
    }

    double getPerimeter() const {
        return 2 * (length + width);
    }

    void display(int index) const {
        cout << "Rectangle " << index + 1 << ": "
             << "Length = " << length
             << ", Width = " << width
             << ", Area = " << getArea()
             << ", Perimeter = " << getPerimeter() << endl;
    }
};

class RectangleManager {
private:
    vector<Rectangle> rectangles;

public:
    void addRectangle(double length, double width) {
        Rectangle rect(length, width);
        rectangles.push_back(rect);
        cout << "Rectangle added successfully.\n";
    }

    void updateRectangle(int index, double length, double width) {
        if (index < 0 || index >= rectangles.size()) {
            cout << "Invalid rectangle index.\n";
            return;
        }
        rectangles[index].setDimensions(length, width);
        cout << "Rectangle updated successfully.\n";
    }

    void displayAll() const {
        if (rectangles.empty()) {
            cout << "No rectangles to display.\n";
            return;
        }
        cout << "\n--- Rectangles Summary ---\n";
        for (int i = 0; i < rectangles.size(); ++i) {
            rectangles[i].display(i);
        }
    }
};

int main() {
    RectangleManager manager;

    manager.addRectangle(10, 5);
    manager.addRectangle(8, 3.5);
    manager.addRectangle(6.2, 4.1);

    manager.displayAll();

    manager.updateRectangle(1, 9, 4.5);

    manager.displayAll();

    return 0;
}
