#include "physim.hpp"
#include "src/planet.hpp"


using namespace physics::tools;


int main(int argc, char** argv) {


    mass_system<2> system;
    physics::tools::time t, tmax(atoi(argv[1]) * s), dt(3600 * s);
    
/*
    system.add(sun); 
    system.add(earth);
    system.add(mars); 

    system.update(); 

    do {

        system[0].get_position().save("data/sun_position.txt", km); 
        system[1].get_position().save("data/earth_position.txt", km);
        system[2].get_position().save("data/mars_position.txt", km);
        system.move(dt);
        t += dt;
        
    } while (t < tmax);

    for (auto& i : system.objects()) i.print();
*/

    return 0; 

}