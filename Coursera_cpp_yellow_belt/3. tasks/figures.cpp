#include <iostream>
#include <string>
#include <cmath>
#include <memory>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
    Triangle(const int& a, const int& b, const int& c) : a_(a), b_(b), c_(c) {}

    virtual string Name() const override { return name; }
    virtual double Perimeter() const override { return a_ + b_ + c_; }
    virtual double Area() const override {
        double p = (a_ + b_ + c_) / 2;
        return sqrt((p * (p - a_) * (p - b_) * (p - c_)));
    }

private:
    double a_, b_, c_;
    const string name = "TRIANGLE";
};

class Rect : public Figure {
public:
    Rect(const int& width, const int& height) : width_(width), height_(height) {}

    virtual string Name() const override { return name; }
    virtual double Perimeter() const override { return (width_ + height_) * 2; }
    virtual double Area() const override { return width_ * height_; }

private:
    int width_, height_;
    const string name = "RECT";
};

class Circle : public Figure {
public:
    Circle(const int& r) : r_(r) {}

    virtual string Name() const override { return name; };
    virtual double Perimeter() const override { return r_ * 2 * 3.14; }
    virtual double Area() const override { return r_ * r_* 3.14; }

private:
    int r_;
    const string name = "CIRCLE";
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    string typeStr;
    is >> typeStr;
    if (typeStr == "RECT") {
        double width, height;
        is >> width >> height;
        return make_shared<Rect>(width, height);
    } else if (typeStr == "TRIANGLE") {
        double a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    } else {
        double r;
        is >> r;
        return make_shared<Circle>(r);
    }
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}