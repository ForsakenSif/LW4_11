#include <iostream>
#include <string>

using namespace std;

// Абстрактный класс "Транспортное средство"
class Transport {
protected:
    string type; // тип транспортного средства

public:
    Transport(const string& t) : type(t) {}
    virtual ~Transport() {}

    virtual void displayState() const = 0; // виртуальный метод просмотра текущего состояния
    virtual void resetState(const string& s) = 0;         // виртуальный метод переустановки текущего состояния
};

// Класс "Автомобиль", наследуется от транспортного средства
class Car : public Transport {
private:
    string model; // модель автомобиля

public:
    Car(const string& t, const string& m) : Transport(t), model(m) {}

    void displayState() const override {
        cout << "Type: " << type << ", Model: " << model << endl;
    }

    void resetState(const string& s) override {
        model = s;
    }
};

// Класс "Поезд", наследуется от транспортного средства
class Train : public Transport {
private:
    string route; // маршрут поезда

public:
    Train(const string& t, const string& r) : Transport(t), route(r) {}

    void displayState() const override {
        cout << "Type: " << type << ", Route: " << route << endl;
    }

    void resetState(const string& s) override {
        route = s;
    }
};

// Класс "Экспресс", наследуется от транспортного средства
class Express : public Transport {
private:
    string destination; // пункт назначения экспресса

public:
    Express(const string& t, const string& d) : Transport(t), destination(d) {}

    void displayState() const override {
        cout << "Type: " << type << ", Destination: " << destination << endl;
    }

    void resetState(const string& s) override {
        destination = s;
    }
};

int main() {
    Car car("Car", "Toyota");
    Train train("Train", "Moscow - Saint Petersburg");
    Express express("Express", "New York");

    // Пример использования методов
    cout << "Current state:" << endl;
    car.displayState();
    train.displayState();

    express.displayState();

    express.resetState("Moscow");

    express.displayState();

    return 0;
}
