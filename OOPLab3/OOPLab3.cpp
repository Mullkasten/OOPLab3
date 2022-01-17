#include <iostream>
#include <cstdlib>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "-- --\n";
    }
};
class Point : public Shape{
protected:
    int x, y;
public:
    Point() : Shape() {
        cout << "Конструктор Point по умолчанию\n";
        x = 0;
        y = 0;
    }
    Point(int a, int b=0) : Shape() {
        cout << "Конструктор Point с параметрами\n";
        x = a;
        y = b;
    }
    Point(Point* obj) : Shape() {
        cout << "Конструктор копирования Point\n";
        x = obj->getX();
        y = obj->getY();
    }
    ~Point() {
        cout << "Деструктор Point\n";
    }
    void draw() {
        cout << "draw Point--"<< x << "_" << y << "--\n";
    }
    void changeVar(int a = 0, int b = 0) {
        cout << "Изменено содержимое объекта класса Point\n";
        x = a;
        y = b;
    }
    int getX() {
        cout << "Вызван метод getX класса Point\n";
        return x;
    }
    int getY() {
        cout << "Вызван метод getY класса Point\n";
        return y;
    }
    int getVar() {
        cout << "Вызван метод getVar класса Point\n";
        return x, y;
    }

};
class Circle : public Shape {
protected:
    int x, y, rad;
public:
    Circle() : Shape() {
        cout << "Конструктор Circle по умолчанию\n";
        x = 0;
        y = 0;
        rad = 0;
    }
    Circle(int a, int b=0, int c=0) : Shape() {
        cout << "Конструктор Circle с параметрами\n";
        x = a;
        y = b;
        rad = c;
    }
    Circle(Circle* obj) : Shape() {
        cout << "Конструктор копирования Circle\n";
        x = obj->getX();
        y = obj->getY();
        rad = obj->getRad();
    }
    ~Circle() {
        cout << "Деструктор Circle\n";
    }
    void draw() {
        cout << "draw Circle--" << x << "_" << y << "_" << rad << "--\n";
    }
    void changeVar(int a = 0, int b = 0, int c = 0) {
        cout << "Изменено содержимое объекта класса Circle\n";
        x = a;
        y = b;
        rad = c;
    }
    int getX() {
        cout << "Вызван метод getX класса Point\n";
        return x;
    }
    int getY() {
        cout << "Вызван метод getY класса Point\n";
        return y;
    }
    int getRad() {
        cout << "Вызван метод getRad класса Point\n";
        return rad;
    }
    int getVar() {
        cout << "Вызван метод getVar класса Point\n";
        return x, y, rad;
    }
};
class Storage {
protected:
    int count, maxcount, cur;
    Shape **mas;
public:
    Storage(int _maxcount) {
        maxcount = _maxcount;
        mas = new Shape*[maxcount];
        count = 0;
        cur = 0;
        cout << "Конструктор Storage\n";
    }
    ~Storage() {
        for (int i = 0; i < count; i++) {
            cout << "Деструктор Storage\n";
        }
    }
    void addObj(Shape* _obj) {
        if(count<maxcount){
        mas[count] = _obj;
        count++;
        cur++;
        cout << "Добавлен "<<count<<" объект\n";
        }
    }
    
    void delObj(int ind) {
        if (count > ind) {
            for (int i = ind; i < count; i++) {
                mas[i] = mas[i + 1];
            }
            count--;
            cur--;
            cout << "Удален " << ind << " объект\n";
        }
        else {
            cout << "Передаваемое значение delObj больше количества элементов в хранилище\n";
        }
    }
    void SetCurrentObj(int ind) {
        cur = ind;
        cout << "Текущий объект " << cur<<"\n";
    }
    void SetNextObj() {
        if(cur<count) cur++;
        cout << "Текущий объект " << cur << "\n";
    }
    void SetPrevObj() {
        if (cur < count) cur--;
        cout << "Текущий объект " << cur << "\n";
    }
    
    int getCount() {
        return count;
    }
    int getCur() {
        return cur;
    }
    void draw(int ind) {
        if (ind > count) {
            cout << "Передаваемое значение draw больше количества элементов в хранилище\n";
            
        }
        else
        {
            mas[ind]->draw();
        }
        
    }
    void draw() {
        mas[cur]->draw();
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    int a, n=10;
    Point p1;
    Point p2(1, 2);
    Circle c1;
    Circle c2(3, 6);
    Storage s(n);
    srand(1235);
    for (int i = 0; i < n; i++) {
        a = rand();
        a = a % 7;
        switch (a)
        {
        case(0): {
            s.addObj(&p1);
            break;
        }
        case(1): {
            s.addObj(&p2);
            break;
        }
        case(2): {
            s.addObj(&c1);
            break;
        }
        case(3): {
            s.addObj(&c2);
            break;
        }
        case(4): {
            a = rand();
            a = a % n;
            s.delObj(a);
            break;
        }
        case(5): {
            s.draw();
            break;
        }
        case(6): {
            a = rand();
            a = a % n;
            s.draw(a);
            break;
        }
        default:
            break;
        }
    }
}
