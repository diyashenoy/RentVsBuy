//
// Created by Diya Shenoy on 2019-10-19.
//

#include "remaining_loan.h"

#include <iostream>

double loan_calc(double& monthly_mortgage, double& remaining_loan, double loan_rate)
{
    loan_rate = loan_rate/12;
    for(int i=0; i<12; i++)
    {
        remaining_loan = remaining_loan + (loan_rate*remaining_loan);
        remaining_loan = remaining_loan - monthly_mortgage;

    }

    return remaining_loan;
}
