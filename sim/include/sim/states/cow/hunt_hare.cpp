#include <kmint/pigisland/state/state.hpp>
#include <kmint/astar/astar.hpp>
#include <kmint/pigisland/node_algorithm.hpp>
#include <kmint/random.hpp>
#include "hunt_hare.hpp"

namespace namespace kmint::states::cow {

	void HuntPigState::start(kmint::hare* actor)
	{
		auto& node = find_closest_node_to(_g, actor->smelledPos);
		Astar astar(_g, actor->node().node_id(), node.node_id());
		astar.search();

		_path = astar.construct_path();
		actor->smelledPos = vector2d(0, 0);
		actor->canEat = true;

		play::image_drawable& image = (kmint::play::image_drawable&)actor->drawable();
		image.set_tint(graphics::color(0, 100, 100));

	}
	void HuntPigState::execute(kmint::hare* actor, kmint::delta_time dt)
	{
	}
	void HuntHareState::execute(kmint::hare* actor, kmint::delta_time dt) {
		if (!_path.empty()) {
			actor->node(_g[_path.back()]);
			_path.pop_back();
		}

		if (_path.empty()) {
			actor->transitionTo(new WanderState(_g));
		}
	}
}