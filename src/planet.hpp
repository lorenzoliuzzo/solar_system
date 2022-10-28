#include "celestial_body.hpp"


template <size_t DIM>
class planet : public celestial_body<DIM> {


    private:

        physics::tools::time orbit_period_;



    public:

        explicit constexpr planet(const measurement& mass,
                                // shape shape = geometry::shapes::circle(0.0 * m),
                                  const position<DIM>& pos, 
                                  const linear_velocity<DIM>& lin_vel = linear_velocity<DIM>(), 
                                  const linear_acceleration<DIM>& lin_acc = linear_acceleration<DIM>(),
                                  const physics::tools::time& orbit_period = physics::tools::time(), 
                                  const uint& id = 0,
                                  const std::string& name = "",
                                  const std::vector<celestial_body<DIM>>& satelites = std::vector<celestial_body<DIM>>()) noexcept : 

            celestial_body<DIM>(mass, pos, lin_vel, lin_acc, id, name, "planet", satelites), 
            orbit_period_{orbit_period} {}


        ~planet() noexcept = default;


}; // class planet



planet<2> sun(1.98844E30 * kg, position<2>({0.0 * km, 0.0 * km}), linear_velocity<2>(), linear_acceleration<2>(), physics::tools::time(0.0 * s), 0, "Sun");

planet<2> earth(5.9722E24 * kg, position<2>({152.100E6 * km, 0. * km}), linear_velocity<2>({0 * kmps, 29.2911 * kmps}), linear_acceleration<2>(), physics::tools::time(365.256 * day), 1, "Earth");
