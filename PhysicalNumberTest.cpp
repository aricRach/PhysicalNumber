/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
//using std::cout, std::endl, std::istringstream;
using namespace std;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber;
using ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);
 
    PhysicalNumber a2(2, Unit::KM);
    PhysicalNumber b2(300, Unit::KM);
    PhysicalNumber c2(2, Unit::HOUR);
    PhysicalNumber d2(30, Unit::MIN);
    PhysicalNumber e2(30, Unit::TON);
    PhysicalNumber k2(12, Unit::KG);
    PhysicalNumber f2(30, Unit::G);
    PhysicalNumber g2(7, Unit::HOUR);
    PhysicalNumber h2(7, Unit::M);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")      //300[M]+2[KM]
    .CHECK_OUTPUT((a+=b), "2.3[km]")   //300[M]+2[KM]
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")       //2.3[km]+2.3[km]
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")       // 30[Min]+2[Hour]

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c) // km+hours
    .CHECK_THROWS(a+d) // km+ min
    .CHECK_THROWS(b+c) // meter+hour
    .CHECK_THROWS(b+d)  // meter +min

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

    .setname("ourTest-Basic output")
    
    .CHECK_OUTPUT(a2,"2[km]")
    .CHECK_OUTPUT(b2,"300[km]")
    .CHECK_OUTPUT(h2, "7[m]")

    .CHECK_OUTPUT(c2,"2[hour]")
    .CHECK_OUTPUT(g2, "7[hour]")
    .CHECK_OUTPUT(d2,"30[min]")
    
    .CHECK_OUTPUT(e2, "30[ton]")
    .CHECK_OUTPUT(k2, "12[kg]")
    .CHECK_OUTPUT(f2, "30[g]")
    
    .setname("ourTest-Compatible dimensions")
    .CHECK_OUTPUT(b2+a2, "302[km]") // 300[KM]+2[KM]
    .CHECK_OUTPUT((a2+=b2), "302[km]") // a2= 2[Km]+300[Km]
    .CHECK_OUTPUT((a2-=b2), "2[km]") // a2=302[Km]-300[Km]
    .CHECK_OUTPUT((a2+=b2), "302[km]") // a2=2[Km]+300[Km]
    .CHECK_OUTPUT((a2--), "302[km]") // because we minus 1 after return a2
    .CHECK_OUTPUT(a2, "301[km]") // check if -- operation successed
    .CHECK_OUTPUT(a2+a2, "602[km]") // 301 km + 301 km
    .CHECK_OUTPUT(b2-b2, "0[km]")  // 300[Km]-300[Km]
    .CHECK_OUTPUT(d2+c2, "150[min]") // 2 [Hour] + 30 [Min]
      // comparations
    .CHECK_EQUAL(a2>=b2,true) // 301[Km] >= 300[Km]
    .CHECK_EQUAL(c2>=d2,true) // 2[Hour] > 30[Min] 
    .CHECK_EQUAL(k2<f2,false) // 12[Kg] < 30[G] 
    .CHECK_EQUAL(f2<k2,true)  //  30[G] < 12[Kg]
    .CHECK_EQUAL(d2>=g2,false)  // 30[Min] >= 7[Hour] 
    .CHECK_EQUAL(f2>=e2,false)  // 30[G] >= 30[Ton] 
    .CHECK_EQUAL(f2<=e2,true) //  30[G] <= 30[Ton] 
    .CHECK_EQUAL(a2>=a2,true) // 301[Km] >= 301[Km]
    .CHECK_EQUAL(a2>=a2,true) //  301[Km] == 301[Km]
     .CHECK_EQUAL(a2>=-a2,true) //  301[Km] >= -301[Km]


    // check true/ false ( bigger then and smaller)
    
     .setname("ourTest-Incompatible dimensions")
     // aritmetic 
    .CHECK_THROWS(a2+g2) // 2[Km] + 7[H]
    .CHECK_THROWS(e2+g2) // 30[Ton] + 7[H]
    .CHECK_THROWS(e2+h2) // 30[Ton] + 7[Min]
    .CHECK_THROWS(h2+g2) // 7[M] + 7[Hour] 
    .CHECK_THROWS(f2+g2) // 30[G] + 7[Hour]
    .CHECK_THROWS(c2+e2) // 2[Hour] + 30[Ton]
    .CHECK_THROWS(c2+f2) // 2[Hour] + 30[G]
    // comparations
    .CHECK_THROWS(a2>g2) // km>Hour
    .CHECK_THROWS(e2==g2) // Ton==Hour
    .CHECK_THROWS(e2<=h2) // Ton<=Meter
    .CHECK_THROWS(h2==g2) // Meter==Hour
    .CHECK_THROWS(f2<g2) // G<Hour
    .CHECK_THROWS(c2>e2) // Hour>Tom
    .CHECK_THROWS(c2>=f2) // H>=G
  
    // CIN
    
    .CHECK_OK(istringstream("700.[kg]") >> a)
    .CHECK_OK(istringstream("700.034[m]") >> b)
    .CHECK_OK(istringstream("700.111[sec]") >> c)



      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
