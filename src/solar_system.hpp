    namespace solar_system {

        using objects::planet; 
        using objects::mass;
        using namespace measurements;

        planet Sun("Sun", mass(1.98844E30 * kg), 695700 * km, 0.0 * s); 
        
        planet Mercury("Mercury", mass(0.33010E24 * kg), 2440.5 * km, 87.969 * day,
                                    tools::position(69.818E6 * km, 0. * km, 0. * km), tools::position(-46E6 * km, 0. * km, 0. * km),
                                    tools::velocity(0 * kmps, 38.86 * kmps, 0. * kmps), tools::velocity(0. * kmps, -58.98 * kmps, 0. * kmps)); 

        planet Venus("Venus", mass(4.8673E24 * kg), 6051.8 * km, 224.701 * day,
                                    tools::position(108.941E6 * km, 0. * km, 0. * km), tools::position(-107.480E6 * km, 0. * km, 0. * km),
                                    tools::velocity(0 * kmps, 34.79 * kmps, 0. * kmps), tools::velocity(0. * kmps, -35.26 * kmps, 0. * kmps)); 

        planet Earth("Earth", mass(5.9722E24 * kg), 6378.137 * km, 365.256 * day,
                                    tools::position(152.100E6 * km, 0. * km, 0. * km), tools::position(-147.095E6 * km, 0. * km, 0. * km),
                                    tools::velocity(0 * kmps, 29.2911 * kmps, 0. * kmps), tools::velocity(0. * kmps, -30.2865 * kmps, 0. * kmps)); 
       
        planet Mars("Mars", mass(0.64169E24 * kg), 3396.2 * km, 686.980 * day,
                                    tools::position(249.261E6 * km, 0. * km, 0. * km), tools::position(-206.650E6 * km, 0. * km, 0. * km),
                                    tools::velocity(0 * kmps, 21.97 * kmps, 0. * kmps), tools::velocity(0. * kmps, -26.50 * kmps, 0. * kmps)); 

        planet Jupiter("Jupiter", mass(1898.13E24 * kg), 71492 * km, 4332.589 * day,
                                    tools::position(816.363E6 * km, 0. * km, 0. * km), tools::position(-740.595E6 * km, 0. * km, 0. * km),
                                    tools::velocity(0 * kmps, 12.44 * kmps, 0. * kmps), tools::velocity(0. * kmps, -13.72 * kmps, 0. * kmps)); 

        planet Saturn("Saturn", mass(568.32E24 * kg), 60268 * km, 10759.22 * day,
                                    tools::position(108.941E6 * km, 0. * km, 0. * km), tools::position(-107.480E6 * km, 0. * km, 0. * km),
                                    tools::velocity(0 * kmps, 9.09 * kmps, 0. * kmps), tools::velocity(0. * kmps, -10.18 * kmps, 0. * kmps)); 

        planet Uranus("Uranus", mass(86.811E24 * kg), 25559* km, 30685.4 * day,
                                    tools::position(3001.390E6 * km, 0. * km, 0. * km), tools::position(-2732.696E6 * km, 0. * km, 0. * km),
                                    tools::velocity(0 * kmps, 6.49 * kmps, 0. * kmps), tools::velocity(0. * kmps, -7.11 * kmps, 0. * kmps)); 
       
        planet Neptune("Neptune", mass(102.409E24 * kg), 24764 * km, 60189 * day,
                                    tools::position(4558.857E6 * km, 0. * km, 0. * km), tools::position(-4471.050E6 * km, 0. * km, 0. * km),
                                    tools::velocity(0 * kmps, 5.37 * kmps, 0. * kmps), tools::velocity(0. * kmps, -5.50 * kmps, 0. * kmps)); 


    } // namespace solar_system