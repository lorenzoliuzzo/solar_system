#include "solar_system.hpp"

using namespace physics::potentials;
using namespace solar_system; 



void simulate_solar_system(const physics::tools::time& tmax, const physics::tools::time& dt) {

    physics::tools::time t;
    mass_system<2> sys;

    Mercury.set_at_perihelion();
    Venus.set_at_aphelion();
    Earth.set_at_perihelion();
    Mars.set_at_aphelion();
    Jupiter.set_at_perihelion();
    Saturn.set_at_aphelion();
    Uranus.set_at_perihelion();
    Neptune.set_at_aphelion();

    sys.add(Sun);
    sys.add(Mercury);
    sys.add(Venus);
    sys.add(Earth);
    sys.add(Mars);
    sys.add(Jupiter);
    sys.add(Saturn);
    sys.add(Uranus);
    sys.add(Neptune);

    sys.print();

    do {

        sys.evolve(dt);
        for (auto& i : sys.objects()) {
            i.get_position().save("data/" + i.name() + "_position.txt", km);
            i.get_linear_velocity().save("data/" + i.name() + "_velocity.txt", kmps);
        }
        t += dt;

    } while(t < tmax);

    sys.print();

}


// number of seconds in 1 year: 31536000 s
// number of seconds in 1 month: 2628000 s 
// number of seconds in 1 week: 604800 s
// number of seconds in 1 day: 86400 s  

int main() {


    simulate_solar_system(31536000 * 10 * s, 86400 * 3.5 * s);

    return 0; 
}