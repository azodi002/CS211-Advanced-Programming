#include <iostream>
#include <vector>
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


  virtual void display()
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

  virtual void display()
  {
    cout << "Trapezoid Side1 = " << side1 << endl;
    cout << "Trapezoid Side2 = " << side2 << endl;
    cout << "Trapezoid Side3 = " << side3 << endl;
    cout << "Trapezoid Side4 = " << side4 << endl;
  }



};

class Square: public Quadrilateral
{
public:
  Square(double side):Quadrilateral(side,side,side,side)
  {
    
  }

  virtual void display()
  {
    cout << "Square Side1 = " << side1 << endl;
    cout << "Square Side2 = " << side2 << endl;
    cout << "Square Side3 = " << side3 << endl;
    cout << "Square Side4 = " << side4 << endl;
  }


};


int main()
{

  Trapezoid FirstTrapezoid(3,5,5,2);
  Square FirstSquare(6);

  vector<Quadrilateral*> quads;
  
  quads.push_back(&FirstTrapezoid);
  quads.push_back(&FirstSquare);

  for(int i=0; i<quads.size();i++)
    {
      quads[i]->display();
    }



  cout << "*****************************" << endl;
  

  

  return 0;
}
