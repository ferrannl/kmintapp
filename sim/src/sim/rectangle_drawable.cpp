// Ensure this file is mentioned in CMakeLists.txt
#include "sim/rectangle_drawable.hpp"
#include "kmint/ui.hpp"
#include "kmint/play.hpp"
namespace sim {
	void rectangle_drawable::draw(kmint::ui::frame& frame) const {
		frame.draw_rectangle(actor_->location(), { 10.0, 10.0 }, kmint::graphics::colors::white);
	}
}
