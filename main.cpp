
#include <iostream>
#include "newton_div.h"




int main()
{

    std::cout << "pekora" << std::endl;
    NewtonDiv div;
    double d;
    std::cout << "d: ";
    std::cin >> d;
    std::cout << "d: " << d << ", want 1/d\n";

    // normalize to 0.5 <= d <= 1
    double d0 = div.norm(d);
    std::cout << "normalized, d0: " << d0 << ", want 1/d0\n";
    // d0 now normalized
    double invD0 = div.invD(d0);
    // denoramlize: divide invD0 by mul
    double invD = div.denorm(invD0);

    std::cout << "1/" << d << " = " << invD;
    std::cout << "\ncheck answer: " << 1 / d << std::endl;
    std::cout << std::endl;

    system("pause");
    return 0;
}