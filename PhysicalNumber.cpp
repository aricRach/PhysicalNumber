#include <iostream>
#include "PhysicalNumber.h"
#include "Unit.h"
#include <string>

using namespace std;

namespace ariel {

   std::string getType(int typeNum); // declaration
   
    // Constructor //
    PhysicalNumber::PhysicalNumber(double value, Unit type) {
      
      this->value = value;
      this->type = type;
   } 
   
   int returnUnit(const PhysicalNumber & a, const PhysicalNumber & b) {

      int typeA = (int) (a.type);
      int typeB = (int) (b.type);

      if ((typeA >= 0 && typeA <= 2) && (typeB >= 0 && typeB <= 2)) {

         return 0;
      }

      if ((typeA >= 3 && typeA <= 5) && (typeB >= 3 && typeB <= 5)) {

         return 3;
      }

      if ((typeA >= 6 && typeA <= 8) && (typeB >= 6 && typeB <= 8)) {

         return 6;
      }
      return -1;
   }

   void throwCheck(const PhysicalNumber & a, const PhysicalNumber & b) {
      
      if (returnUnit(a, b) == -1)
         throw(" Two differentche of Unit types ");
   }

   Unit StringToType(string str) { // Return type of str

      if (str == "km")
         return Unit::KM;
      else if (str == "m")
         return Unit::M;
      else if (str == "cm")
         return Unit::CM;
      else if (str == "hour")
         return Unit::HOUR;
      else if (str == "min")
         return Unit::MIN;
      else if (str == "sec")
         return Unit::SEC;
      else if (str == "ton")
         return Unit::TON;
      else if (str == "kg")
         return Unit::KG;
      else if (str == "g")
         return Unit::G;
      else {
         throw("not a valid type");
      }
   }

   double converterToMin(const PhysicalNumber & a) { // Convert to the lowest type of value

      double val = a.value;
      Unit t = a.type;

      switch (t) {
      case Unit::KM:
         return val * 100000;
         break;
      case Unit::M:
         return val * 100;
         break;
      case Unit::HOUR:
         return val * 3600;
         break;
      case Unit::MIN:
         return val * 60;
         break;
      case Unit::TON:
         return val * 1000000;
         break;
      case Unit::KG:
         return val * 1000;
         break;
      default:
         return val;
      }
   }

   double convertToA(const PhysicalNumber & a, double val) { // Convert the value to type a

      Unit t = a.type;

      switch (t) {
      case Unit::KM:
         return val / 100000;
         break;
      case Unit::M:
         return val / 100;
         break;
      case Unit::HOUR:
         return val / 3600;
         break;
      case Unit::MIN:
         return val / 60;
         break;
      case Unit::TON:
         return val / 1000000;
         break;
      case Unit::KG:
         return val / 1000;
         break;
      default:
         return val;
      }
   }

   PhysicalNumber operator+(const PhysicalNumber & a, const PhysicalNumber & b) {

      throwCheck(a, b);
      double sum = converterToMin(a) + converterToMin(b);
      sum = convertToA(a, sum);
      Unit type = a.type;
      PhysicalNumber afterSum(sum, type);
      return afterSum;
   }

   PhysicalNumber operator+(const PhysicalNumber & a) { // unary
      
      return PhysicalNumber(a.value, a.type);
      //return a;
   }

   PhysicalNumber & operator+=(PhysicalNumber & a, const PhysicalNumber & b) {
      // throwCheck(a,b);
      // double sum=converterToMin(a)+converterToMin(b);
      // sum=convertToA(a,sum);
      // a.value=sum;
      // return a;

      a = a + b; // doing throwCheck in operator +
      return a;
   }

   PhysicalNumber operator-(const PhysicalNumber & a, const PhysicalNumber & b) {

      throwCheck(a, b);
      double sum = converterToMin(a) - converterToMin(b); // maybe check if sum is lower than 0
      sum = convertToA(a, sum);
      //if(sum<0) throw (" the val is minus");
      Unit type = a.type;
      PhysicalNumber afterMinus(sum, type);
      return afterMinus;
   }

   PhysicalNumber operator-(const PhysicalNumber & a) { // unary
      
      double minusVal = -(a.value);
      return PhysicalNumber(minusVal, a.type);
   }

   PhysicalNumber & operator-=(PhysicalNumber & a, const PhysicalNumber & b) {
      // throwCheck(a,b);
      // double sum=converterToMin(a)-converterToMin(b); // maybe check if sum is lower than 0
      // sum=convertToA(a,sum);
      // //if(sum<0) throw (" the val is minus");
      // a.value=sum;
      // return a;

      a = a - b;
      return a;
   }

   PhysicalNumber & operator++(PhysicalNumber & a) { // prefix (++a)
     
      a.value++;
      return a;
   }

   PhysicalNumber operator++(PhysicalNumber & a, int) { // postfix (a++)
      
      PhysicalNumber beforChange(a.value, a.type);
      a.value++;
      return beforChange;
   }

   PhysicalNumber & operator--(PhysicalNumber & a) { // prefix (--a)
      
      a.value--;
      return a;
   }

   PhysicalNumber operator--(PhysicalNumber & a, int) { // postfix (a--)
      
      PhysicalNumber beforChange(a.value, a.type);
      a.value--;
      return beforChange;
   }

   bool operator<(const PhysicalNumber & a, const PhysicalNumber & b) { // a<b
      
      throwCheck(a, b);
      return (converterToMin(a) < converterToMin(b));
   }

   bool operator>(const PhysicalNumber & a, const PhysicalNumber & b) { // a>b
      
      throwCheck(a, b);
      return (converterToMin(a) > converterToMin(b));
   }

   bool operator<=(const PhysicalNumber & a, const PhysicalNumber & b) { // a<=b
      
      throwCheck(a, b);
      return (converterToMin(a) <= converterToMin(b));
   }

   bool operator>=(const PhysicalNumber & a, const PhysicalNumber & b) { // a>=b
      
      throwCheck(a, b);
      return (converterToMin(a) >= converterToMin(b));
   }

/*bool operator=(PhysicalNumber& a,const PhysicalNumber& b){ // a=b
    return true;
}*/

   bool operator==(const PhysicalNumber & a, const PhysicalNumber & b) { // a==b
      
      throwCheck(a, b);
      return (converterToMin(a) == converterToMin(b));
   }
   
    bool operator!=(const PhysicalNumber & a, const PhysicalNumber & b) { // a!=b
      
      throwCheck(a, b);
      return (converterToMin(a) != converterToMin(b));
   }

   ostream & operator<<(ostream & os, const PhysicalNumber & a) { // Cout
      
      return os << a.value << getType((int) a.type);
   }

   istream & operator>>(istream & is, PhysicalNumber & a) { // Cin
      
      // make PhysicalNumber c
      // check if the input is valid
      // if valid put the value on a 
      //else error
      double tempVal;
      char tmp; // Recieve "["
      string s = ""; // Recieve the rest of the input after the number (Unit"]")
      is >> tempVal >> tmp >> s;
      if(s.length()>0) s.resize(s.length() - 1);
      try{
                  
         Unit newType = StringToType(s); // Convert the string into type
          
         a.type = newType;
         a.value=tempVal;

      }
      catch(const exception& e){
         
         is.setstate(ios::failbit);
      }
     
       return is;
   }

   std::string getType(int typeNum) { // Recieve type as a number and return it as a string

      switch (typeNum) {
      case 0:
         return "[km]";
         break;
      case 1:
         return "[m]";
         break;
      case 2:
         return "[cm]";
         break;
      case 3:
         return "[hour]";
         break;
      case 4:
         return "[min]";
         break;
      case 5:
         return "[sec]";
         break;
      case 6:
         return "[ton]";
         break;
      case 7:
         return "[kg]";
         break;
      case 8:
         return "[g]";
         break;
      default:
         return "";
      }
   }
};
