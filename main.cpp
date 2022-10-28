#include "src/planet.hpp"
#include "physim.hpp"

using namespace physics::tools; 


int main() {



    celestial_body<2> c_body1(1.0 * kg, 
                            position<2>({1.0 * m, 1.0 * m}), 
                            linear_velocity<2>({1.0 * mps, 1.0 * mps}), 
                            linear_acceleration<2>({1.0 * mpss, 1.0 * mpss}),
                            1,
                            "Earth");
    
    c_body1.print(); 

    physics::tools::time dt(1.e-2 * s);
    c_body1.move(harmonic_oscillator<2>(10 * Hz), dt);
    c_body1.print();
    

    planet<2> earth(1.0 * kg, 
                            position<2>({1.0 * m, 1.0 * m}), 
                            linear_velocity<2>({1.0 * mps, 1.0 * mps}), 
                            linear_acceleration<2>({1.0 * mpss, 1.0 * mpss}),
                            physics::tools::time(365 * day),
                            1,
                            "Earth");
    
    earth.print();

    return 0; 

}