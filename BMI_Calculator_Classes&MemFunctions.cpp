#include <iostream>
using namespace std;

class myBody{
    public:
    double height;
    double weight;
    double BMI;
    int cals;
    double getBMI(void);
    void setBMI(int input1, int input2);
    double resultant(double);
};

int main(){
    myBody calc;
    int x, y;
    cout << "print your height in cm"<< endl;
    cin >> x;
    cout << "now your weight in kg" << endl;
    cin >> y;
    calc.setBMI(x,y);
    cout << "your BMI is " << calc.getBMI();
    
    cout << "your daily caloric intake is" << endl;
    cout << calc.resultant(calc.getBMI()) << endl;

}


void me::setBMI( int input1, int input2){
    height = input1;
    weight = input2;
    BMI = height/weight;
}

double me::getBMI(void){
    return BMI;
}

double me::resultant(double BMI){
    cals = BMI * 24;
    return cals;
}








// class feedback{
//     public:
//     double inputNumber;
//      double numGetter(void);
//      void numSetter(double inp);
// };

// int main(){
//     feedback first;
//     first.numSetter(23.2);
//     cout << "the number inoyt is " << first.numGetter()<<endl;
//     first.inputNumber = 12;
//     cout<< "the number when used with class definition is:"<< first.inputNumber;
    
// }


// void feedback::numSetter(double inp){
//     inputNumber = inp;
// }

// double feedback::numGetter(){
//     return inputNumber;
// }
















// class replay{
//     public:
//     int number;
//     void setter(int inputlength);
//     int getter( void);
// };

// void replay::setter(int inputlength){
// number = inputlength;
// }
// // void refers to what it does and returns

// int replay::getter(void){
//     return number; 
// }
// // returns the assignment done for number, in which we set it to the input length


// int main(){
//     replay meow;
//     meow.setter(6993);
//     cout << meow.getter();

//     // setting length of line without a member function

//     meow.number = 10;
//     cout << meow.number;
// }
















// class Line {
//     public:
//     double length;
//     void setLength(double len); // member functions defined with their parameters  get length
//     double getLength(void); // member functions with parameters to getLength

// };

// // member function definitions
// // type class:: memberfunction(parameter) // returns double, access to the class

// void Line::setLength(double len){
//     length = len;
// }

// double Line::getLength(void){ 
//     return length;
// }



// int main(){
//     Line line;
//     // set line length
//     line.setLength(6.0);
//     cout <<"Length of line: "<<line.getLength() << endl;

//     line.length = 10.0; // 
//     cout << "Length of line: " << line.length << endl;

//     return 0;
    
// }





// class box{
//     public:
//     int height;
//     int length;
//     int width;
// };

// int main(){
//     box box1, box2, boxSq;
//     double volume1,volume2;
//     double vsq;
//     // box1 definition
//     box1.height = 5;
//     box1.length = 6;
//     box1.width = 4;
//     //box 2 definition
//     box2.height = 2;
//     box2.length = 3;
//     box2.width = 4;

//     // volume of box 1
//     volume1 = box1.height * box1.length * box1.width;
//     cout << "Volume of box 1 is: " << volume1 << endl;

//     volume2 = box2.height * box2.length * box2.width;
//     cout << "Volume of box2 is: " << volume2 << endl;

//     cout << "sq vol is: " << volume1 * volume2 << endl;

//     return 0;




// }

// Privae, public and protected sections within the class body;

/*

classs base{
    public:
    public members go here
    
    protected:
    protected members go here

    private:
    private members go here

};

*/
