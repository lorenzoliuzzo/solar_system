#include "solar_system.hpp"

using namespace physics::potentials;


std::vector<std::string> solar_system_names = {"Sun", "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};


void simulate_solar_system(const time_measurement& tmax, const time_measurement& dt) {

    time_measurement t;

    Mercury.set_at_aphelion();
    Venus.set_at_perihelion();
    Earth.set_at_aphelion();
    Mars.set_at_perihelion();
    Jupiter.set_at_aphelion();
    Saturn.set_at_perihelion();
    Uranus.set_at_aphelion();
    Neptune.set_at_perihelion();

    system_of_masses<2> solar_system({Sun, Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune}); 


    do {

        solar_system.evolve(dt);

        for (size_t i{}; i < solar_system.count(); ++i) {
            solar_system[i].as_position().save("data/" + solar_system_names[i] + "_position.txt", km);
            solar_system[i].as_linear_velocity().save("data/" + solar_system_names[i] + "_velocity.txt", km_s);
        }
        t += dt;

    } while(t < tmax);

    solar_system.print();

}


// number of seconds in 1 year: 31536000 s
// number of seconds in 1 month: 2628000 s 
// number of seconds in 1 week: 604800 s
// number of seconds in 1 day: 86400 s  

int main() {


    simulate_solar_system(31536000 * 5 * s, 86400 * 2 * s);

    return 0; 
}