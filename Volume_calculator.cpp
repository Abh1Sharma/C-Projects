#include <iostream>
using namespace std;


class Box{
public:
double length;
double width;
double height;

double getVolume(void){ // return type is double, input is variables
    return length*width*height; 
}
void setLength(double len);
void setWidth(double wid);
void setHeight(double hei);

};

// can also be written as double Box::getVolume(void){return length*width*height}

// member function definitions

void Box::setLength(double len){
    length = len;
}

void Box:: setWidth(double wid){
    width = wid;
}

void Box:: setHeight(double hei){
    height = hei;
}

int main(){
    Box box1, box2;
    double volume1, volume2;

    // Box specification
    int x1,y1,z1;
    int x2,y2,z2;
    cout << "enter the dimensions for Box1 in order of Length width and height, press enter after each one" << endl;
    cin >> x1;
    cin >> y1;
    cin >> z1;
    box1.setLength(x1);
    box1.setWidth(y1);
    box1.setHeight(z1);

    volume1 = box1.getVolume();
    cout << "Volume of Box1 is: " << volume1 << endl;

    cout << "enter the dimensions for Box2 in order of Length width and height" << endl;
    cin >> x2;
    cin >> y2;
    cin >> z2;
    box2.setLength(x2);
    box2.setWidth(y2);
    box2.setHeight(z2);

    volume2 = box2.getVolume();
    cout << "Volume of Box2 is: " << volume2 << endl;

    return 0;


}



