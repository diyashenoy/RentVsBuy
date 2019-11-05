//
// Created by Diya Shenoy on 2019-10-15.
//

#include <iostream>
#include <cmath>
#include <iomanip>

double mortgage_calculator(double& principle, double& term, double& rate)
{
    double discount_factor;
    double m=0;

    int t=term;
    double r = rate;
    double p = principle;

    t = 12*t; //to calculate for 12 months
    r = r/12; //to reduce the interest from annually to monthly

    discount_factor = (pow((1+r),t) -1)/(r*(pow((1+r),t)));

    m = (p/discount_factor)*12;

    return m;
}//
// Created by Diya Shenoy on 2019-10-16.
//

