#include <kmint/pigisland/shark.hpp>

namespace kmint::states::cow {
	class HuntPigState : public State<kmint::hare> {

	private:
		std::vector<int> _path;
	public:
		explicit HuntHareState(map::map_graph& g) : State<kmint::hare>(g) {};
		void start(kmint::hare* actor) override;
		void execute(kmint::hare* actor, kmint::delta_time dt) override;
	};
}