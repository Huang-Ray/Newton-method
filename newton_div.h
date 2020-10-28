#include <iostream>
#include <math.h>

class NewtonDiv{
    private:
        // denoramlizing factor
        double mul;
    
    public:
        NewtonDiv(); 
        ~NewtonDiv();

        double norm(double d);
        double invD(double d0);
        double denorm(double invD0);
        void show();

};
