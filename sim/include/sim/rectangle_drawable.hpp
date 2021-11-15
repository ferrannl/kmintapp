#ifndef SIM_RECTANGLE_DRAWABLE_HPP
#define SIM_RECTANGLE_DRAWABLE_HPP
#include "kmint/ui/drawable.hpp"
// forward declarations
namespace kmint {
	namespace play {
		class actor;
	}
	namespace ui {
		class frame;
	}
}
namespace sim {
	class rectangle_drawable : public kmint::ui::drawable {
	public:
		rectangle_drawable(kmint::play::actor const& actor) : drawable{}, actor_{ &actor } {}
		void draw(kmint::ui::frame& f) const override;
	private:
		kmint::play::actor const* actor_;
	};
}
#endif
