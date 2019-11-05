//
// Created by Diya Shenoy on 2019-10-17.
//

#include <iostream>
#include "tax.h"


double calc_tax(double& tax_rate, double& current_value)
{
    double tax;

    tax = tax_rate*current_value;

    return tax;
}