#include <iostream>
using namespace std;

class Quadrilateral
{

protected:
  double side1, side2, side3, side4;
  
public:

  Quadrilateral(double s1, double s2, double s3, double s4)
  {
    side1 = s1;
    side2 = s2;
    side3 = s3;
    side4 = s4;
  }


  void display()
  {
    cout << "Quadrilateral Side1 = " << side1 << endl;
    cout << "Quadrilateral Side2 = " << side2 << endl;
    cout << "Quadrilateral Side3 = " << side3 << endl;
    cout << "Quadrilateral Side4 = " << side4 << endl;
  }

}; //End of class definition Quadrilateral


class Trapezoid: public Quadrilateral
{

public:
  Trapezoid(double s1, double s2, double s3, double s4):Quadrilateral(s1,s2,s3,s4)
  {

  }

};

class Square: public Quadrilateral
{
public:
  Square(double side):Quadrilateral(side,side,side,side)
  {
    
  }

};


int main()
{

  Trapezoid FirstTrapezoid(3,5,5,2);
  Square FirstSquare(6);

  FirstTrapezoid.display();
  cout << "*****************************" << endl;
  
  FirstSquare.display();
  

  return 0;
}
