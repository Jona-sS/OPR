#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

class Shape
{
public:
    virtual double Area() const = 0; // virtual-> kann von abgeleiteten Klassen überschrieben werden
    virtual double Perimeter() const = 0;
    virtual ~Shape(){};
};

class Rectangle : public Shape
{
public:
    Rectangle(double a, double b) : mA{a}, mB{b}
    {
    }

    double Area() const override // override -> stellt sicher das die virtuelle Funktion der Basisklasse überschrieben wird
    {
        /// Ihre Code1 (anfang)
        ///
        ///  Bitte berechnen Sie die Fl�che des Rechtecks

        return mA * mB;

        /// Ihre Code1 (ende)
    }

    double Perimeter() const override
    {
        /// Ihre Code2 (anfang)
        ///
        /// Bitte berechnen Sie den Umfang des Rechtecks

        return mA * 2 + mB * 2;

        /// Ihre Code2 (ende)
    }

private:
    const double mA;
    const double mB;
};

class Circle : public Shape
{
public:
    Circle(double r) : mR{r}
    {
    }

    double Area() const override
    {
        /// Ihre Code3 (anfang)
        ///
        /// Bitte berechnen Sie die Fl�che des Kreises
        ///
        /// Tip: Konstante pi ist definiert mit macro M_PI

        return mR * mR * M_PI;

        /// Ihre Code3 (ende)
    }

    double Perimeter() const override
    {
        /// Ihre Code4 (anfang)
        ///
        ///  Bitte berechnen Sie den Umfang des Kreises
        ///
        /// Tip: Konstante pi ist definiert mit macro M_PI

        return 2 * M_PI * mR;

        /// Ihre Code4 (ende)
    }

private:
    const double mR;
};

/// Ihre Code5 (anfang)
///
/// Verwenden Sie die Vererbung, um das neue Klasse "Triangle" (Dreieck) zu implementieren. Definieren drei member Variablen
/// f�r jede Kante als double und verstechen im "private" breich.
///
/// Tip f�r Methode "Area" (Fl�che des Dreiecks): Man kann Heron's formula nutzen https://en.wikipedia.org/wiki/Heron%27s_formula
class Triangle : public Shape
{
public:
    Triangle(double a, double b, double c) : mA{a}, mB{b}, mC{c}
    {
    }

    double Area() const override
    {
        double s = Perimeter() / 2; //deklaration nötig da const -> read only
        return sqrt(s * (s - mA) * (s - mB) * abs(s - mC));
    }

    double Perimeter() const override
    {
        return mA + mB + mC;
    }

private:
    const double mA;
    const double mB;
    const double mC;
   //double s;         
};

/// Ihre Code5 (ende)

class Object3D
{
public:
    Object3D(const string &name, const Shape *baseArea, double height) : mName{name}, mBaseArea{baseArea}, mHeight{height}
    {
        if (mBaseArea != nullptr)
        {
            /// Ihre Code6 (anfang)
            ///
            /// Bitte berechnen Sie das Gesamtvolumen (mVolume) und die Oberfl�che (mSurfaceArea).
            /// Um dies zu berechnen, verwenden Sie Methoden der Grundfl�che mBaseArea->Area() und
            /// mBaseArea->Perimeter().
            /// Beachten Sie, dass dieser Algorithmus generisch ist und nicht vom konkreten Typ der Grundfl�che abh�ngt.
            ///
            /// Tip: Falls n�tig Weitere Hilfe finden Sie unter https://en.wikipedia.org/wiki/Prism_(geometry) Kapiteln: Volume/Surface area
            mVolume = baseArea->Area() * height;
            mSurfaceArea = baseArea->Perimeter() * height + baseArea->Area() * 2; // Mantel+2*Grundfläche
            /// Ihre Code6 (ende)
        }
    }

    ~Object3D()
    {
        delete mBaseArea;
    }

    double getVolume() const
    {
        return mVolume;
    }

    double getSurfaceArea() const
    {
        return mSurfaceArea;
    }

private:
    const string mName;
    const Shape *mBaseArea;
    const double mHeight;
    double mVolume = 0.0;
    double mSurfaceArea = 0.0;
};

void TestCube() // Quater
{
    const Object3D obj("cube0", new Rectangle(10, 10), 10);
    const bool ok = std::abs(obj.getVolume() - 1000.0) < 1e-7 && std::abs(obj.getSurfaceArea() - 600.0) < 1e-7;
    cout << " TestCube => " << (ok ? "OK" : "NOK") << endl;
}

void TestCuboid() // Rechteck
{
    const Object3D obj("cuboid0", new Rectangle(10, 20), 10);
    const bool ok = std::abs(obj.getVolume() - 2000.0) < 1e-7 && std::abs(obj.getSurfaceArea() - 1000.0) < 1e-7;
    cout << " TestCuboid => " << (ok ? "OK" : "NOK") << endl;
}

void TestCylinder()
{
    const Object3D obj("cylinder0", new Circle(13.38257185), 0.88867091);
    const bool ok = std::abs(obj.getVolume() - 500.0) < 1e-6 && std::abs(obj.getSurfaceArea() - 1200.0) < 1e-6;
    cout << " TestCylinder => " << (ok ? "OK" : "NOK") << endl;
}

void TestPrism()
{
    //bool ok = false;
    /// Ihre Code7 (anfang)
    ///
    /// Erstellen Sie eine Prisma als Instanz der Object3D-Klasse mit einer Dreiecksbasis.
    /// Berechnen Sie das Gesamtvolumen und die Oberfl�che, dann pr�fen ob beide Werte mit den
    /// tats�chlichen Werten �bereinstimmen.
    ///
    /// Tip: Eine m�glichkeit um runde Werte f�r Gesamtvolumen/Oberfl�che zu bekommen, nutzen Kanten 4, 13 und 15 und H�he 10
    ///
    const Object3D obj("prism0", new Triangle(4,5,13),10);
    //cout << "Voulemen= " << obj.getVolume() << "Oberfläche= " << obj.getSurfaceArea()<< endl;
    const bool ok = std::abs(obj.getVolume() - 303.973683) < 1e-6 && std::abs(obj.getSurfaceArea() - 280.794736) < 1e-6;//anpassen

    /// Ihre Code7 (ende)

    cout << " TestPrism => " << (ok ? "OK" : "NOK") << endl;
}

int main()
{
    TestCube();
    TestCuboid();
    TestPrism();
    TestCylinder();

    return 0;
}
