
#include <iostream>
#include <string>
using namespace std;

class Student {
protected:

    string name;
    int age;
    int height;

public:
    Student() {
        name = "";
        age = 0;
    }

    Student(string name) {
        this->name = name;
    }

    Student(string name, int age) :Student(name)
    {
        this->age = age;
    }

    Student(string name, int age, int height) :Student(name)
    {
        this->height = height;
    }

    void setName(string name) {
        this->name = name;
    }


    void setAge(int age) {
        this->age = age;
    }


    void setHeight(int height) {
        this->height = height;
    }

    string getName() {
        return this->name;
    }

    int getAge() {
        return this->age;
    }

    int getHeight() {
        return this->height;
    }

    void print() {
        cout << "Student\nName:" << this->name << "\nAge:" << this->age << "\nHeight:" << this->height;
    }
};

class Aspirant : public Student
{
    string candidateWork;
public:
    Aspirant() :Student() {
        this->candidateWork = "";
    }
    Aspirant(string name, int age, int height, string candidateWork) :Student(name, age, height) {
        this->candidateWork = candidateWork;
    }
    void print() {
        Student::print();
        cout << "\nCandidate work: " << this->candidateWork;
    }
};


class Transport {
protected:
    string name;
    double speed, costPerKm, tankVolume;
public:
    Transport(string name, double speed, double costPerKm, double tankVolume) {
        this->name = name;
        this->speed = speed;
        this->costPerKm = costPerKm;
        this->tankVolume = tankVolume;
    }

    double calculateTime(double distance) {
        return distance / speed;
    }

    double calculateCost(double distance) {
        return distance * costPerKm;
    }

    double getTankVolume() const {
        return tankVolume;
    }
};

class Car : public Transport {
public:
    Car() : Transport("Electric Car", 120, 8, 60) {

    }
};

class Scooter : public Transport {
public:
    Scooter() : Transport("Electric Scooter", 25, 1.5, 2) {

    }
};

class Bus : public Transport {
public:
    Bus() : Transport("Double-Decker Bus", 50, 4, 200) {

    }
};
class Tram : public Transport {
public:
    Tram() : Transport("Modern Tram", 35, 2.5, 150) {

    }
};

class Trolleybus : public Transport {
public:
    Trolleybus() : Transport("Trolleybus", 30, 2.5, 100) {

    }
};

class Minibus : public Transport {
public:
    Minibus() : Transport("Minibus", 40, 3.5, 80) {

    }
};

class Bicycle : public Transport {
public:
    Bicycle() : Transport("Electric Bicycle", 20, 1, 1) {

    }
};

class Airplane : public Transport {
public:
    Airplane() : Transport("Jet Airplane", 900, 12, 50000) {

    }
};

class Train : public Transport {
public:
    Train() : Transport("High-Speed Train", 300, 10, 8000) {

    }
};

class Pen {
protected:
    string color, type;
    int width;
public:
    Pen() {
        color = type = "";
        width = 0;
    }
    void draw(string color, string type, int width) {
        this->color = color;
        this->type = type;
        this->width = width;
    }
};

class Brush :public Pen {
public:
    void fill(string color) {
        this->color = color;
    }
    Brush() {
        color = "";
    }
};

class SolidBrush :public Brush {
public:
};

class GradientBrush :public Brush {
    string* colorArr;
public:
    GradientBrush() {
        int color_len;
        cout << "Type colors amount: ";
        cin >> color_len;
        colorArr = new string[color_len];
        for (int i = 0; i < color_len; i++) {
            cout << "Type " << i + 1 << " color\n";
            cin >> colorArr[i];
        }
    }
};

class GradientBrush :public Brush {
    string* colorArr;
public:
    GradientBrush() {
        int color_len;
        cout << "Type colors amount: ";
        cin >> color_len;
        colorArr = new string[color_len];
        for (int i = 0; i < color_len; i++) {
            cout << "Type " << i + 1 << " color\n";
            cin >> colorArr[i];
        }
    }
};

class HatchBrush :public Brush {
    string color2, pattern;
public:
    HatchBrush() :Brush() {
        color2 = pattern = "";
    }
    HatchBrush(string color, string color2, string pattern) {
        fill(color);
        this->color2 = color2;
        this->pattern = pattern;
    }
};

class TextureBrush :public Brush {
    string imgSrc;
public:
    TextureBrush() {
        imgSrc = "";
    }
    TextureBrush(string src) {
        this->imgSrc = src;
    }
};

class VisualBrush :public Brush {
    string id;
public:
    VisualBrush() {
        id = "";
    }
    VisualBrush(string id) {
        this->id = id;
    }
};
class LinearGradientBrush : public GradientBrush {

};
class RadialGradientBrush : public GradientBrush {

};
class Geometry {
    Pen pen;
    Brush* brush;

public:
    Geometry() {
        brush = nullptr;
    }
    Geometry(string color, string type, int width) {
        pen.draw(color, type, width);
        if (brush == nullptr) {
            brush = new Brush();
        }
        brush->fill(color);
    }
    ~Geometry() {
        delete brush;
    }
    virtual void drawGeometry() const = 0;
};

class Ellipse : public Geometry {
    float radiusX, radiusY;
public:
    Ellipse(string color, string type, int width) : Geometry(color, type, width) {
    }
    Ellipse(string color, string type, int width, float radiusX, float radiusY) :Geometry(color, type, width) {
        this->radiusX = radiusX;
        this->radiusY = radiusY;
    }

    void drawGeometry() const override {
        cout << "Ellipse is being drawn\n";
    }
};

class Rectangle : public Geometry {
    float rectWidth, rectHeight;
public:
    Rectangle(string color, string type, int width) : Geometry(color, type, width) {
    }
    Rectangle(string color, string type, int width, float rectWidth, float rectHeight) : Geometry(color, type, width) {
        this->rectHeight = rectHeight;
        this->rectWidth = rectWidth;
    }

    void drawGeometry() const override {
        cout << "Rectangle is being drawn\n";
    }
};

class Point {
    int x, y;
public:
    Point() {
        x = y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Polyline : public Geometry {


    int size;
    Point* points;
public:
    Polyline(string color, string type, int width, Point* shape, int size) : Geometry(color, type, width) {
        points = new Point[size];
        for (int i = 0; i < size; i++) {
            points[i] = shape[i];
        }
    }
    ~Polyline() {
        delete[]points;
    }

    void drawGeometry() const override {
        cout << "Polyline is being drawn \n";
    }
};

class Font {
    float fontSize, boldness;
    string fontFamily, color;
    bool cursive, underline;
public:
    Font() {
        fontSize = boldness = cursive = underline = 0;
        fontFamily = color = "";
    }
    Font(float fontSize, float boldness, string fontFamily, string color, bool cursive, bool underline) {
        this->fontSize = fontSize;
        this->boldness = boldness;
        this->fontFamily = fontFamily;
        this->color = color;
        this->cursive = cursive;
        this->underline = underline;
    }
    void displayFont() const {
        cout << "Font: Size=" << fontSize << ", Boldness=" << boldness << ", Family=" << fontFamily
            << ", Color=" << color << ", Cursive=" << cursive << ", Underline=" << underline << endl;
    }
};

class Button : public Geometry, public Font {
public:
    Button(float fontSize, float boldness, string fontFamily, string color, bool cursive, bool underline, string geomColor, string geomType, int geomWidth) : Geometry(geomColor, geomType, geomWidth), Font(fontSize, boldness, fontFamily, color, cursive, underline) {}


    void displayButton() const {
        displayFont();
        drawGeometry();
    }
};

int main()
{

    Aspirant first("Eric", 23, 173, "Design");
    first.print();
    cout << "Age: " << first.getAge() << "\n";
    cout << "Name: " << first.getName() << "\n";
    cout << "Height: " << first.getHeight() << "\n";

    Car electricCar;
    Scooter electricScooter;
    Bus doubleDeckerBus;
    Tram modernTram;
    Trolleybus trolleybus;
    Minibus minibus;
    Bicycle electricBicycle;
    Airplane jetAirplane;
    Train highSpeedTrain;

    cout << "Electric Car Tank Volume: " << electricCar.getTankVolume() << " liters\n";
    cout << "Electric Scooter Tank Volume: " << electricScooter.getTankVolume() << " liters\n";
    cout << "Double-Decker Bus Tank Volume: " << doubleDeckerBus.getTankVolume() << " liters\n";
    cout << "Modern Tram Tank Volume: " << modernTram.getTankVolume() << " liters\n";
    cout << "Trolleybus Tank Volume: " << trolleybus.getTankVolume() << " liters\n";
    cout << "Minibus Tank Volume: " << minibus.getTankVolume() << " liters\n";
    cout << "Electric Bicycle Tank Volume: " << electricBicycle.getTankVolume() << " liters\n";
    cout << "Jet Airplane Tank Volume: " << jetAirplane.getTankVolume() << " liters\n";
    cout << "High-Speed Train Tank Volume: " << highSpeedTrain.getTankVolume() << " liters\n";


    Ellipse ellipse("Blue", "Pencil", 2, 10.0, 5.0);
    Rectangle rectangle("Red", "Marker", 3, 20.0, 15.0);

    ellipse.drawGeometry();
    rectangle.drawGeometry();

    Point points[3] = { Point(3, 5), Point(6, 8), Point(9, 12) };
    Polyline polyline("Green", "Pen", 1, points, 3);
    polyline.drawGeometry();


    return 0;

}