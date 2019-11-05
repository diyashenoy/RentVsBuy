//
// Created by Diya Shenoy on 2019-10-20.
//

#include "investment.h"

double investment_calc(double& cost1, double& cost2, double return_rate)
{
    double dif, monthly_dif, final, rate;
    rate = return_rate/12;

    dif = cost1 - cost2;

    monthly_dif = dif/12;

    for(int i=0; i<12; i++)
    {
        monthly_dif = monthly_dif + (rate*monthly_dif);
    }

    final = dif + monthly_dif;

    return final;
}

double compounded_investment(double amount, double return_rate)
{
   double interest=0;
   double rate = return_rate/12;

   for(int i =0; i<12; i++)
   {
       interest = interest + (rate*amount);
   }

   return interest;
}
