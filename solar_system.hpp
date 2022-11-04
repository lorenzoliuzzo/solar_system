#pragma once
#include "physim.hpp"


using namespace physics::objects;


template <size_t DIM>
class star : public mass<DIM> {


    public:

        explicit constexpr star(const std::string& name,
                                  const measurement& mass,
                                // shape shape = geometry::shapes::circle(0.0 * m),
                                  const position<DIM>& pos, 
                                  const uint& id = 0) noexcept : 

            mass<DIM>(mass, pos, id, name) {}


        constexpr ~star() noexcept = default;


}; // class star


template <size_t DIM>
class planet : public mass<DIM> {


    private:

        physics::tools::time orbit_period_;

        position<DIM> perihelion_position_;

        position<DIM> aphelion_position_;

        linear_velocity<DIM> perihelion_velocity_;

        linear_velocity<DIM> aphelion_velocity_;


    public:

        explicit constexpr planet(const std::string& name,
                                  const measurement& mass,
                                // shape shape = geometry::shapes::circle(0.0 * m),
                                  const position<DIM>& aphelion_pos, 
                                  const linear_velocity<DIM>& aphelion_vel,
                                  const position<DIM>& perihelion_pos, 
                                  const linear_velocity<DIM>& perihelion_vel,  
                                  const physics::tools::time& orbit_period = physics::tools::time(), 
                                  const uint& id = 0) noexcept : 

            mass<DIM>(mass, position<DIM>(), id, name),
            orbit_period_{orbit_period}, 
            perihelion_position_{perihelion_pos}, 
            aphelion_position_{aphelion_pos},
            perihelion_velocity_{perihelion_vel}, 
            aphelion_velocity_{aphelion_vel} {}


        constexpr planet(const planet& other) noexcept : 

            mass<DIM>(other), 
            orbit_period_{other.orbit_period_}, 
            perihelion_position_{other.perihelion_position_}, 
            aphelion_position_{other.aphelion_position_}, 
            perihelion_velocity_{other.perihelion_velocity_}, 
            aphelion_velocity_{other.aphelion_velocity_} {}


        constexpr planet(planet&& other) noexcept :

            mass<DIM>(std::move(other)), 
            orbit_period_{std::move(other.orbit_period_)}, 
            perihelion_position_{std::move(other.perihelion_position_)}, 
            aphelion_position_{std::move(other.aphelion_position_)}, 
            perihelion_velocity_{std::move(other.perihelion_velocity_)}, 
            aphelion_velocity_{std::move(other.aphelion_velocity_)} {}


        constexpr planet& operator=(const planet& other) noexcept {

            if (this != &other) {

                mass<DIM>::operator=(other); 
                orbit_period_ = other.orbit_period_; 
                perihelion_position_ = other.perihelion_position_; 
                aphelion_position_ = other.aphelion_position_; 
                perihelion_velocity_ = other.perihelion_velocity_; 
                aphelion_velocity_ = other.aphelion_velocity_; 

            }

            return *this; 

        }


        constexpr planet& operator=(planet&& other) noexcept {

            if (this != &other) {

                mass<DIM>::operator=(std::move(other)); 
                orbit_period_ = std::move(other.orbit_period_); 
                perihelion_position_ = std::move(other.perihelion_position_); 
                aphelion_position_ = std::move(other.aphelion_position_); 
                perihelion_velocity_ = std::move(other.perihelion_velocity_); 
                aphelion_velocity_ = std::move(other.aphelion_velocity_); 

            }

            return *this; 

        }


        constexpr ~planet() noexcept = default;


        constexpr void set_at_perihelion() noexcept {

            this->set_position(perihelion_position_); 
            this->set_linear_velocity(perihelion_velocity_); 

        }


        constexpr void set_at_aphelion() noexcept {

            this->set_position(aphelion_position_); 
            this->set_linear_velocity(aphelion_velocity_); 

        }


        constexpr physics::tools::time orbit_period() const noexcept {

            return orbit_period_; 

        }


        constexpr position<DIM> perihelion_position() const noexcept {

            return perihelion_position_; 

        }


        constexpr position<DIM> aphelion_position() const noexcept {

            return aphelion_position_; 

        }


        constexpr linear_velocity<DIM> perihelion_velocity() const noexcept {

            return perihelion_velocity_; 

        }   


        constexpr linear_velocity<DIM> aphelion_velocity() const noexcept {

            return aphelion_velocity_; 

        }


}; // class planet


namespace solar_system {


    star<2> Sun("Sun", 1.989e30 * kg, position<2>({0.0 * m, 0.0 * m}), 0);


    planet<2> Mercury("Mercury", 0.33010E24 * kg, 
                    position<2>({69.818E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, 38.86 * kmps}), 
                    position<2>({-46E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, -58.98 * kmps}),
                    87.969 * day);


    planet<2> Venus("Venus", 4.8673E24 * kg, 
                    position<2>({108.941E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, 34.79 * kmps}), 
                    position<2>({-107.480E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, -35.26 * kmps}),
                    224.701 * day);

        
    planet<2> Earth("Earth", 5.9722E24 * kg, 
                    position<2>({152.100E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, 29.2911 * kmps}), 
                    position<2>({-147.095E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, -30.2865 * kmps}),
                    365.256 * day);


    planet<2> Mars("Mars", 0.64169E24 * kg, 
                    position<2>({249.261E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, 21.97 * kmps}), 
                    position<2>({-206.650E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, -26.50 * kmps}),
                    686.980 * day);


    planet<2> Jupiter("Jupiter", 1898.13E24 * kg, 
                    position<2>({816.363E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, 12.44 * kmps}), 
                    position<2>({-740.595E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, -13.72 * kmps}),
                    4332.589 * day);


    planet<2> Saturn("Saturn", 568.32E24 * kg, 
                    position<2>({1506.527E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, 9.09 * kmps}), 
                    position<2>({-1357.554E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, -10.18 * kmps}),
                    10759.22 * day);


    planet<2> Uranus("Uranus", 86.811E24 * kg, 
                    position<2>({3001.390E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, 6.49 * kmps}), 
                    position<2>({-2732.696E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, -7.11 * kmps}),
                    30685.4 * day);


    planet<2> Neptune("Neptune", 102.409E24 * kg, 
                    position<2>({4558.857E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, 5.37  * kmps}), 
                    position<2>({-4471.050E6 * km, 0.0 * km}), linear_velocity<2>({0.0 * kmps, -5.50 * kmps}),
                    60189 * day);


} // namespace solar_system