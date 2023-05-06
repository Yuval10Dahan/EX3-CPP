    // #include <string>
    // #include <limits>
    // #include "Fraction.hpp"
    // using namespace std;

    // // test
    // int main()
    // {
    //     cout << "##############################################################" << endl;
    //     // // // operator +
    //     // Fraction f1(1,4);
    //     // Fraction f2(5,-6);
    //     // Fraction result = f1 + f2;
    //     // cout << "result numerator: " << result.getNumerator() << endl; // -7
    //     // cout << "result denominator: " << result.getDenominator() << endl; // 12

    //     // Fraction f3(1,10);
    //     // Fraction f4(3,12);
    //     // Fraction result2 = f3 + f4;
    //     // cout << "result numerator: " << result2.getNumerator() << endl; // 7
    //     // cout << "result denominator: " << result2.getDenominator() << endl; // 20

    //     // float num = 2.45;
    //     // Fraction f6(2,9);
    //     // Fraction result3 = f6 + num;
    //     // Fraction result4 = num + f6;
    //     // cout << "result3 numerator: " << result3.getNumerator() << endl; 
    //     // cout << "result3 denominator: " << result3.getDenominator() << endl; 
    //     // cout << "result4 numerator: " << result4.getNumerator() << endl; 
    //     // cout << "result4 denominator: " << result4.getDenominator() << endl; 

    //     cout << "##############################################################" << endl;
    
    //     // // ctor (float)
    //     // Fraction f5(2.42356);
    //     // cout << "f5 numerator: " << f5.getNumerator() << endl; // 303
    //     // cout << "f5 denominator: " << f5.getDenominator() << endl; // 125

    //     cout << "##############################################################" << endl;

    //     // // operator -
    //     // Fraction ff1(1,4);
    //     // Fraction ff2(5,-6);
    //     // Fraction res = ff1 - ff2;
    //     // cout << "res numerator: " << res.getNumerator() << endl; // 13
    //     // cout << "res denominator: " << res.getDenominator() << endl; // 12

    //     // Fraction ff3(1,10);
    //     // Fraction ff4(3,12);
    //     // Fraction res2 = ff3 - ff4;
    //     // cout << "res2 numerator: " << res2.getNumerator() << endl; // -3
    //     // cout << "res2 denominator: " << res2.getDenominator() << endl; // 20

    //     // float numm = 2.42356;
    //     // Fraction ff6(2,9);
    //     // Fraction res3 = ff6 - numm;
    //     // Fraction res4 = numm - ff6;
    //     // cout << "res3 numerator: " << res3.getNumerator() << endl; 
    //     // cout << "res3 denominator: " << res3.getDenominator() << endl; 
    //     // cout << "res4 numerator: " << res4.getNumerator() << endl; 
    //     // cout << "res4 denominator: " << res4.getDenominator() << endl; 

    //     cout << "##############################################################" << endl;

    //     // // // operator *
    //     // Fraction f10(1,4);
    //     // Fraction f11(5,-6);
    //     // Fraction mul = f10 * f11;
    //     // cout << "mul numerator: " << mul.getNumerator() << endl; // -5
    //     // cout << "mul denominator: " << mul.getDenominator() << endl; // 24

    //     // Fraction f12(1,10);
    //     // Fraction f13(3,12);
    //     // Fraction mul2 = f12 * f13;
    //     // cout << "mul2 numerator: " << mul2.getNumerator() << endl; // 1
    //     // cout << "mul2 denominator: " << mul2.getDenominator() << endl; // 40

    //     cout << "##############################################################" << endl;

    //     // // // operator /

    //     // float num = 2.4343;
    //     // Fraction f6(2,9);
    //     // Fraction mul3 = f6 / num;
    //     // Fraction mul4 = num / f6;
    //     // cout << "mul3 numerator: " << mul3.getNumerator() << endl; 
    //     // cout << "mul3 denominator: " << mul3.getDenominator() << endl; 
    //     // cout << "mul4 numerator: " << mul4.getNumerator() << endl; 
    //     // cout << "mul4 denominator: " << mul4.getDenominator() << endl; 

    //     cout << "##############################################################" << endl;

    //     // // operator == and operator !=

    //     // Fraction test1(1,2);
    //     // Fraction test2(2,4);
    //     // Fraction test3(5,4);
    //     // Fraction test4(1253,1000);
    //     // float float1 = 1.2533;
    //     // float float2 = 1.25;
        
    //     // cout << "test1 == test2 ---> " << (test1 == test2) << endl; // 1
    //     // cout << "test1 == test3 ---> " << (test1 == test3) << endl; // 0

    //     // cout << "test1 != test2 ---> " << (test1 != test2) << endl; // 0
    //     // cout << "test1 != test3 ---> " << (test1 != test3) << endl; // 1

    //     // cout << "test4 == float1 ---> " << (test4 == float1) << endl; // 1
    //     // cout << "float2 == test3 ---> " << (float2 == test3) << endl; // 1

    //     // cout << "test4 != float1 ---> " << (test4 != float1) << endl; // 0
    //     // cout << "float2 != test3 ---> " << (float2 != test3) << endl; // 0


    //     cout << "##############################################################" << endl;

    //     // // // operator >

    //     // Fraction test10(2,3);
    //     // Fraction test20(7,8);
    //     // Fraction test30(8,12);
    //     // float a = 0.875;
    //     // cout << "test10 > test20 ---> " << (test10 > test20) << endl; // 0
    //     // cout << "test10 > test30 ---> " << (test10 > test30) << endl; // 0
    //     // cout << "test20 > test10 ---> " << (test20 > test10) << endl; // 1
    //     // cout << "test20 > a ---> " << (test20 > a) << endl; // 0
    //     // cout << "a > test30 ---> " << (a > test30) << endl; // 1

    //     cout << "##############################################################" << endl;

    //     // // // // operator <

    //     // Fraction test22(2,3);
    //     // Fraction test23(7,8);
    //     // Fraction test24(8,12);
    //     // float b = 0.875;
    //     // cout << "test22 < test23 ---> " << (test22 < test23) << endl; // 1
    //     // cout << "test22 < test24 ---> " << (test22 < test24) << endl; // 0
    //     // cout << "test23 < test22 ---> " << (test23 < test22) << endl; // 0
    //     // cout << "test22 < b ---> " << (test22 < b) << endl; // 1
    //     // cout << "b < test24 ---> " << (b < test24) << endl; // 0

    //     cout << "##############################################################" << endl;

    //     // // // // operator >=

    //     // Fraction g1(2,3);
    //     // Fraction g2(7,8);
    //     // Fraction g3(8,12);
    //     // float g4 = 0.875;
    //     // cout << "g1 >= g2 ---> " << (g1 >= g2) << endl; // 0
    //     // cout << "g1 >= g3 ---> " << (g1 >= g3) << endl; // 1
    //     // cout << "g2 >= g1 ---> " << (g2 >= g1) << endl; // 1
    //     // cout << "g1 >= g4 ---> " << (g1 >= g4) << endl; // 0
    //     // cout << "g4 >= g3 ---> " << (g4 >= g3) << endl; // 1

    //     cout << "##############################################################" << endl;

    //     // increment()

    //     // Fraction t(2,3);
    //     // t.increment();
    //     // cout << "t numerator: " << t.getNumerator() << endl; // 5
    //     // cout << "res7 denominator: " << t.getDenominator() << endl; // 3





    //     cout << "##############################################################" << endl;

    //     // postfix ++ and prefix ++

    //     // Fraction s(7,35);
    //     // Fraction s2 = s++;
    //     // Fraction d(4,36);
    //     // Fraction d2 = ++d;
    //     // cout << "s numerator: " << s.getNumerator() << endl; // 6
    //     // cout << "s denominator: " << s.getDenominator() << endl; // 5
    //     // cout << "s2 numerator: " << s2.getNumerator() << endl; // 1
    //     // cout << "s2 denominator: " << s2.getDenominator() << endl; // 5
    //     // cout << "d numerator: " << d.getNumerator() << endl; // 10
    //     // cout << "d denominator: " << d.getDenominator() << endl; // 9
    //     // cout << "d2 numerator: " << d2.getNumerator() << endl; // 10
    //     // cout << "d2 denominator: " << d2.getDenominator() << endl; // 9

    //     cout << "##############################################################" << endl;

    //     // cout

    //     // Fraction out(7,10);
    //     // cout << out << " + " << out << endl;

    //     cout << "##############################################################" << endl;

    //     // cin

    //     // Fraction in1;
    //     // cout << "1)Enter numerator" << endl;
    //     // cout << "2)press space" << endl;
    //     // cout << "3)enter denomirator" << endl;
    //     // cout << "4)press Enter" << endl;
    //     // cin >> in1;
    //     // cout << "The fraction is: " << in1 << endl;


    //     cout << "##############################################################" << endl;

    //     // other

    //     // Fraction sheesh(-17, -19);
    //     // cout << "sheesh num: " << sheesh.getNumerator() << endl;

    //     cout << "##############################################################" << endl;

    //     // int max_int = std::numeric_limits<int>::max();
    //     // int min_int = std::numeric_limits<int>::min();

    //     // Fraction max1(max_int, 1);
    //     // Fraction max2(1, max_int);
    //     // Fraction max3(max_int, max_int);
    //     // Fraction max4(max_int - 100, max_int);
    //     // Fraction t5(14, 29);

    //     // // float m1 = max1.fracToFloat();
    //     // // float m2 = max2.fracToFloat();
    //     // // float m3 = max3.fracToFloat();
    //     // // float m4 = max4.fracToFloat();
    //     // // float m5 = t5.fracToFloat();

    //     // cout << "max1: " << max1 << endl;
    //     // cout << "max2: " << max2 << endl;
    //     // cout << "max3: " << max3 << endl;
    //     // cout << "max4: " << max4 << endl;
    //     // // cout << "m5: " << t5 << endl;

    //     // float tes = 14/29;
    //     // // cout << "tes: " << tes << endl;

    //     // Fraction mult = max1 * max4;
    //     // cout << "mult= " << mult << endl;

    //     // Fraction ma(max_int);
    //     // cout << "ma= " << ma << endl;

    //     cout << "##############################################################" << endl;

    //     // overflow

    //     // int max_int1 = std::numeric_limits<int>::max();
    //     // int min_int1 = std::numeric_limits<int>::min();

    //     // cout << "max int = " <<  max_int1 << endl;
    //     // cout <<"max int+1 = " <<  max_int1 + 1 << endl; 
    //     // cout << "min int = " <<  min_int1 << endl;
    //     // cout <<"min int+1 = " <<  min_int1 - 1 << endl; 
        
    //     // int g = max_int1 + 1;
    //     // cout << (g > max_int1? "g\n" : "max_int1\n") << endl;

    //     // int num1 = max_int1;
    //     // int num2 = 2;
    //     // if(num1 > max_int1 - num2) cout << "overflow\n";

    //     int max = std::numeric_limits<int>::max();
    //     long long l1 = static_cast<long long>(max);
    //     long long l2 = static_cast<long long>(max+1);
    //     long long l3 = 2147483648 + 2;
    //     cout << "l1 = " <<  l1 << endl;
    //     cout << "l2= " <<  l2 << endl;
    //     cout << "l3= " <<  l3 << endl;
    // }