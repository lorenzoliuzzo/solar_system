#include "physim.hpp"


using namespace physics::objects;


template <size_t DIM>
class celestial_body : public mass<DIM> {


    private:

        std::vector<celestial_body<DIM>> satellites_;


    public: 


        explicit constexpr celestial_body(const measurement& mass,
                                        // shape shape = geometry::shapes::circle(0.0 * m),
                                          const position<DIM>& pos, 
                                          const linear_velocity<DIM>& lin_vel = linear_velocity<DIM>(), 
                                          const linear_acceleration<DIM>& lin_acc = linear_acceleration<DIM>(), 
                                          const uint& id = 0,
                                          const std::string& name = "",
                                          const std::string& type = "celestial_body",
                                          const std::vector<celestial_body<DIM>>& satelites = std::vector<celestial_body<DIM>>()) noexcept : 

            mass<DIM>(mass, pos, lin_vel, lin_acc, id, name, type),
            satellites_{satelites} {}


        constexpr celestial_body(const mass<DIM>& mass, const std::vector<celestial_body<DIM>>& satelites = std::vector<celestial_body<DIM>>()) noexcept : 

            mass<DIM>(mass), 
            satellites_{satelites} {}


        ~celestial_body() noexcept = default;



}; // class celestial_body

