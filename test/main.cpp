#include "physim.hpp"
#include "src/planet.hpp"


using namespace physics::tools;


int main() {


    mass_system<2> system;
    physics::tools::time t, tmax(365 * day), dt(1 * s);

    system.add(sun); 
    system.add(earth);

    system.update(); 

    for (auto i : system.objects()) {
        i.print();
    }





    return 0; 
}