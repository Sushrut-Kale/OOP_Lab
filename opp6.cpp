#include <iostream>
using namespace std;

// Single Inheritance
class Vehicle {
public:
    void start() {
        cout << "Vehicle starts" << endl;
    }
};

class Car : public Vehicle {
public:
    void drive() {
        cout << "Car is moving" << endl;
    }
};

// Multilevel Inheritance
class SportsCar : public Car {
public:
    void turbo() {
        cout << "Turbo mode activated" << endl;
    }
};

// Multiple Inheritance
class Camera {
public:
    void takePhoto() {
        cout << "Photo captured" << endl;
    }
};

class MusicPlayer {
public:
    void playMusic() {
        cout << "Music is playing" << endl;
    }
};

class SmartDevice : public Camera, public MusicPlayer {
};

// Hierarchical Inheritance
class Animal {
public:
    void category() {
        cout << "Animal category" << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "Cat says meow" << endl;
    }
};

class Cow : public Animal {
public:
    void moo() {
        cout << "Cow says moo" << endl;
    }
};

// Hybrid Inheritance
class Account {
public:
    void accountInfo() {
        cout << "Account information shown" << endl;
    }
};

class Teacher : virtual public Account {
};

class Researcher : virtual public Account {
};

class Professor : public Teacher, public Researcher {
};

int main() {
    cout << "Single Inheritance" << endl;
    Car c;
    c.start();
    c.drive();

    cout << "\nMultilevel Inheritance" << endl;
    SportsCar s;
    s.start();
    s.drive();
    s.turbo();

    cout << "\nMultiple Inheritance" << endl;
    SmartDevice d;
    d.takePhoto();
    d.playMusic();

    cout << "\nHierarchical Inheritance" << endl;
    Cat cat;
    Cow cow;

    cat.category();
    cat.meow();

    cow.category();
    cow.moo();

    cout << "\nHybrid Inheritance" << endl;
    Professor prof;
    prof.accountInfo();

    return 0;
}
