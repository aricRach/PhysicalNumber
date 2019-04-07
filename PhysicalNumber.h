namespace ariel{
    #include "Unit.h"
    
 class PhysicalNumber{
     

      public:
      double value;
      Unit type;
      
      PhysicalNumber(double value, Unit type);
  //     ~PhysicalNumber();
//friend std::string getType(int typeNum);
friend double covertToMin(const PhysicalNumber& a);
friend double convertToA(const PhysicalNumber& a, double val);
friend int returnUnit(const PhysicalNumber& a,const PhysicalNumber& b);
friend Unit StringToType(std::string);
friend void throwCheck(const PhysicalNumber& a,const PhysicalNumber& b);
friend PhysicalNumber operator+ (const PhysicalNumber& a, const PhysicalNumber& b);
friend PhysicalNumber operator+ (const PhysicalNumber& a); // unary
friend PhysicalNumber& operator+= (PhysicalNumber& a, const PhysicalNumber& b);

friend PhysicalNumber operator- (const PhysicalNumber& a, const PhysicalNumber& b);
friend PhysicalNumber operator- (const PhysicalNumber& a); // unary
friend PhysicalNumber& operator-= (PhysicalNumber& a, const PhysicalNumber& b);

friend PhysicalNumber& operator++ (PhysicalNumber& a); // prefix (++a)
friend PhysicalNumber operator++ (PhysicalNumber& a,int); // postfix (a++)

friend PhysicalNumber& operator-- (PhysicalNumber& a); // prefix (--a)
friend PhysicalNumber operator-- (PhysicalNumber& a,int); // postfix (a--)

friend bool operator<(const PhysicalNumber& a,const PhysicalNumber& b); // a<b
friend bool operator>(const PhysicalNumber& a,const PhysicalNumber& b); // a>b

friend bool operator<=(const PhysicalNumber& a,const PhysicalNumber& b); // a<=b
friend bool operator>=(const PhysicalNumber& a,const PhysicalNumber& b); // a>=b

// bool operator=(const PhysicalNumber& a){} // a=b
friend bool operator==(const PhysicalNumber& a,const PhysicalNumber& b); // a==b

friend std::ostream& operator<< (std::ostream& os, const PhysicalNumber& a); // Cout
friend std::istream& operator>> (std::istream& is, PhysicalNumber& a); // Cin

 };
}
