#include <iostream>

//1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы
//Parallelogram (параллелограмм) и Circle (круг). Класс Parallelogram — базовый для классов
//Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). Для всех классов создать
//конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь).
//Во всех остальных классах переопределить эту функцию, исходя из геометрических
//формул нахождения площади.

class Figure {
public:
    virtual int GetArea()=0;
};

class Parallelogram : public Figure
{
protected:
    int a;       
    int h;     
public:
    Parallelogram(int A, int H) :a(A), h(H) {}
    void GetParaArea() 
    { std::cout << a * h << std::endl; };
};

class Circle : public Figure {
    double r;
public:
    Circle(double R) : r(R) {}
    void GetCirclArea() 
    {
        std::cout << 3.1415 * (r * r) << std::endl;
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(int A, int H) : Parallelogram(A, H) {}
    void GetPhombusArea()
    {
        std::cout << a * h << std::endl;
    }
};

//2. Создать класс Car (автомобиль) с полями company (компания) и model (модель).
//Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов
//наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы
//они выводили данные о классах. Создать объекты для каждого из классов и посмотреть,
//в какой последовательности выполняются конструкторы. Обратить внимание на
//проблему «алмаз смерти».

class Car {
protected:
    int company;
    int model;
public:
    Car(int c_company, int c_model) : company(c_company), model(c_model) {}
    void GetCarInfo() { std::cout << company << " " << model << std::endl; };
};

class PassengerCar : public Car {
protected:
    int Speed;
public:
    PassengerCar (int c_company, int c_model,int p_speed) : 
        Car(c_company,c_model), Speed(p_speed) {
        std::cout << company << " " << model << " " << Speed << std::endl;};
};

class Bus : public Car {
protected:
    int QuantityOfPlaces;
public:
    Bus (int c_company, int c_model, int p_qof) :
        Car(c_company,c_model), QuantityOfPlaces(p_qof)
    { std::cout << company << " " << model << " " << QuantityOfPlaces << std::endl; };
};

class Minivan : public PassengerCar, public Bus, public Car {
public:
    Minivan(int c_company, int c_model, int p_speed, int p_qof) :
        PassengerCar(c_company, c_model, p_speed), Bus(c_company, c_model, p_qof), Car(c_company, c_model) {}
};

//3.Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7
//или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
//математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
//унарный оператор (-)
//логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
//Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте
//перегрузить один через другой.
//Продемонстрировать использование перегруженных операторов.

using namespace std;

class Fraction {
    protected:
    int a;
    int b;
public:
    Fraction(int A, int B): a(A),b(B)
    {
        if (b == 0)
            throw runtime_error("zero division error");
        this->a = a;
        this->b = b;
    }
    int getA() const
    {
        return a;
    };
    int getB() const
    {
        return b;
    };
    friend Fraction operator+ (const Fraction& f1, const Fraction& f2) 
    {
        return Fraction(f1.a * f2.b + f2.a * f1.b, f1.b * f2.b);
    }
    friend Fraction operator- (const Fraction& f1, const Fraction& f2)
    {
        return Fraction(f1.a * f2.b - f2.a * f1.b, f1.b * f2.b);
    }
};

//4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть
//три поля: масть, значение карты и положение карты (вверх лицом или рубашкой).
//Сделать поля масть и значение карты типом перечисления (enum). Положение карты -
//тип bool. Также в этом классе должно быть два метода:
//метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает
//лицом вверх, и наоборот.
//метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
//



enum class Suit
{
    Diamonds, Hearts, Clubs, Spades
};
enum class CardValue 
{
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};


class Card {
    Card();
    void SetCV();
};


int main()
{

};
