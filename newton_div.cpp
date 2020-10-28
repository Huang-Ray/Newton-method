#include "newton_div.h"

NewtonDiv::NewtonDiv()
{}

NewtonDiv::~NewtonDiv()
{}

// normalize to 0.5 <= d <= 1
double NewtonDiv::norm(double d)
{
    // divide d by power of 2
    this->mul = 1.0; // power of 2
    double d0 = d;
    while(d0 > 1)
    {
        // divide by 2, will later divide by 2 again
        d0 = d0 / 2.0;
        mul = mul * 2.0;
    }
    while (d0 < 0.5)
    {
        d0 = d0 * 2.0;
        mul = mul / 2.0;
    }
    // d0 now normalized
    return d0;
}

// calculate 1/d0, 0.5 <= d0 <= 1
double NewtonDiv::invD(double d0)
{
    // initial approx: 48/17 - 32/17*d0
    double x0 = 2.82353 - 1.88235 * d0;
    // double x0 = 2.9166666666 - 2.0*d0;
    std::cout << "1st approx to 1/d0: " << x0;
    double x1;
    std::cout << "\n";
    for(;;)
    {
        x1 = x0 * (2 - d0 * x0);
        std::cout << x1 << std::endl;
        if (abs(x1 - x0) < 1.0e-7)
            break;
        x0 = x1;
    }
    return x1;
}

// denorm: reverse the normalization
double NewtonDiv::denorm(double invD0)
{
    return invD0 / mul;
}

void NewtonDiv::show()
{
    std::cout << "AME" << std::endl;
}
