#include "physim.hpp"


using namespace physics::objects;
using namespace math::equations; 


void bits() {

    std::cout << sizeof(base::metre) << std::endl;
    std::cout << sizeof(prefix::kilo) << std::endl;
    std::cout << sizeof(kg) << std::endl;
    std::cout << sizeof(measurement) << std::endl;

}

void gravity() {


    mass<2> sun(1.98844E30 * kg, position<2>({0.0 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, 0.0 * kmps}));
    mass<2> earth(5.9722E24 * kg, position<2>({152.100E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, 29.2911 * kmps}));
    mass<2> mars(0.64169E24 * kg, position<2>({- 206.650E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, -26.50 * kmps}));

    mass_system<2> sys; 
    sys.add(sun); 
    sys.add(earth);
    sys.add(mars);
    
    // number of seconds in 1 year: 31536000 s
    // number of seconds in 1 month: 2628000 s 
    // number of seconds in 1 week: 604800 s
    // number of seconds in 1 day: 86400 s  

    physics::tools::time t, dt(3600 * s), tmax(31536000 * s); 

    do {
        
        sys.evolve(dt); 
        sys[0].get_position().save("data/sun_position.txt", km); 
        sys[0].get_linear_velocity().save("data/sun_velocity.txt", kmps); 
        sys[1].get_position().save("data/earth_position.txt", km); 
        sys[1].get_linear_velocity().save("data/earth_velocity.txt", kmps);         
        sys[2].get_position().save("data/mars_position.txt", km); 
        sys[2].get_linear_velocity().save("data/mars_velocity.txt", kmps); 
        t += dt; 

    } while(t < tmax); 

    sys.print();
    

}


int main() {

    gravity(); 

    bits();

    return 0; 

}


/*
void spring() {


    mass<2> m1(0.5 * kg, position<2>({1 * m, 0 * m}), linear_velocity<2>({3 * mps, 0 * mps})); 
    m1.print(); 

    physics::tools::time t, tmax(20 * s), dt(1.e-3 * s);

    hamiltonian<2> hamiltonian(new spring_potential<2>(measurement(10, N / m))); 

    do {

        m1.set_state(hamiltonian.solve(m1.get_mass(), m1.get_position(), m1.get_linear_velocity(), dt)); 

        m1.get_position().save("data/position.txt", m);
        m1.get_linear_velocity().save("data/velocity.txt", mps);

        t += dt;
    
    } while (t < tmax);

    m1.print();

}




int main() {    

    harmonic_oscillator<2> oscill(3 * Hz); 

    position<2> pos({1 * m, 0 * m});
    linear_velocity<2> vel({0 * mps, 0 * mps});

    physics::tools::time t, dt(1.e-4 * s), tmax(10 * s);

    matrix<2, 2> state({pos.as_vector(), vel.as_vector()});
    state.print(); 



    do {
        state = oscill.solve(state, dt.as_measurement());
        t += dt;
    } while (t < tmax);

    state.print(); 


    ode_system<2, 2, matrix<2, 2>> system;
    system.add(new harmonic_oscillator<2>(3 * Hz));

    do {
        state = system.solve(state, dt.as_measurement());
        state[0].save("data/position.txt", m);
        state[1].save("data/velocity.txt", mps);
        t += dt;
    } while (t < tmax);

    state.print(); 


    return 0; 

}


*/