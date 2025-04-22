#include <iostream>
using namespace std;

class Dish
{
protected:
    string name;
    double cost;

public:
    Dish(string name, double cost) : name(name), cost(cost) {}
    virtual void displayInfo() = 0;
    virtual void cook() = 0;
};

class Starter : public Dish
{
public:
    Starter(string name, double cost) : Dish(name, cost) {}
    
    void displayInfo()
    {
        cout << "Starter: " << name << ", Cost: $" << cost << endl;
    }
    
    void cook()
    {
        cout << "Cooking starter: " << name << endl;
    }
};

class MainDish : public Dish
{
public:
    MainDish(string name, double cost) : Dish(name, cost) {}
    
    void displayInfo()
    {
        cout << "Main Dish: " << name << ", Cost: $" << cost << endl;
    }
    
    void cook()
    {
        cout << "Cooking main dish: " << name << endl;
    }
};

int main()
{
    Dish *dish1 = new Starter("Garlic Bread", 5.50);
    Dish *dish2 = new MainDish("Steak with Mashed Potatoes", 22.75);
    
    dish1->displayInfo();
    dish1->cook();
    
    dish2->displayInfo();
    dish2->cook();
    
    delete dish1;
    delete dish2;

    return 0;
}
