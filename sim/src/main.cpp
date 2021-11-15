#include "kmint/graphics.hpp"      // kleuren en afbeeldingen
#include "kmint/main.hpp"          // voor de main loop
#include "kmint/math/vector2d.hpp" // voor window en app
#include "kmint/play.hpp"          // voor stage
#include "kmint/ui.hpp"            // voor window en app
#include "kmint/map/map.hpp"       // voor de map
#include "sim/cow.hpp"			   // voor de cow
#include "sim/hello_actor.hpp"     // voor actor op stage

using namespace kmint; // alles van libkmint bevindt zich in deze namespace

// let op de enter als tussen de declaratie en definitie (regel 22),
// gaat fout als er direct uit de pdf gekopieerd wordt.
static const char* map_description = R"graph(32 24 32
resources/firstmap.png
G 1 1
I 1 2
C 1 2
H 1 1
W 0 0
B 1 8

WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
WWWHGGGGGGGGGGGGGGGGGGGGGGGGHWWW
WWWGGGGGGGGGGGGGGGGGGGGGGGGGGWWW
WWWGGGGGGGGGGGGGBGGGGGGGGGGGGWWW
WWWGGGGGGWWWWWWWBWWWWWWGGGGGGWWW
WWWGGGGGGWWWWWWWBWWWWWWGGGGGGWWW
WWWGGGGGGWWWWWWWBWWWWWWGGGGGGWWW
WWWGGGGGGWWWWWIIBIWWWWWGGGGGGWWW
WWWGGGGGGWWWWWIIIIWWWWWGGGGGGWWW
WWWGGGGGGWWWWWIIIIWWWWWGGGGGGWWW
WWWGGGGGBBBBBBBICIIIIIIGGGGGGWWW
WWWGGGGGGWWWWWIIIIWWWWWGGGGGGWWW
WWWGGGGGGWWWWWIIBIWWWWWGGGGGGWWW
WWWGGGGGGWWWWWWWBWWWWWWGGGGGGWWW
WWWGGGGGGWWWWWWWBWWWWWWGGGGGGWWW
WWWGGGGGGWWWWWWWBWWWWWWGGGGGGWWW
WWWGGGGGGGGGGGGGBGGGGGGGGGGGGWWW
WWWGGGGGGGGGGGGGGGGGGGGGGGGGGWWW
WWWHGGGGGGGGGGGGGGGGGGGGGGGGHWWW
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
)graph";

map::map_node& find_cow_node(map::map_graph& graph) {
	for (std::size_t i = 0; i < graph.num_nodes(); ++i) {
		if (graph[i].node_info().kind == 'C') {
			return graph[i];
		}
	}
	throw "could not find starting point";
}

int main() {
	// een app object is nodig om
	ui::app app{};

	//  maak een venster aan
	ui::window window{ app.create_window({1024, 768}, "hello") };

	// maak een podium aan
	play::stage s{ {1024, 768 } };

	// laad een kaart
	map::map m{ map::read_map(map_description) };
	auto& graph = m.graph();
	for (std::size_t i = 0; i < graph.num_nodes(); ++i) {
		std::cout << "Knoop op: " << graph[i].location().x() << ", "
			<< graph[i].location().y() << "\n";
	}

	// maak de koe en de haas
	auto& cow_node = find_cow_node(m.graph());


	// Het aantal kanten aan een knoop vraag je op met 
	// map_node::num_edges en met de subscript operator kun je een van de kanten
	// opvragen:
	auto& node = graph[0];
	auto& neighbour = node[0];
	float weight = neighbour.weight();
	for (std::size_t i = 0; i < node.num_edges(); ++i) {
		auto& from = node[i].from();
		auto& to = node[i].to();
		std::cout << "Kant van: " << from.location().x() << ", "
			<< from.location().y() << " naar " << to.location().x() << ", "
			<< to.location().y() << "En het gewicht is: " << node[i].weight() << "\n";
	}


	// kaart / background image
	s.build_actor<play::background>(math::size(1024, 768), graphics::image{ m.background_image() });
	// graph, white lines and points
	s.build_actor<play::map_actor>(math::vector2d{ 0.0f, 0.0f }, m.graph());
	// plaats de koe op het podium
	s.build_actor<sim::cow>(cow_node);




	math::vector2d center{ 512.0, 384.0 };
	auto& my_actor = s.build_actor<sim::hello_actor>(center);

	// Maak een event_source aan (hieruit kun je alle events halen, zoals
	// toetsaanslagen)
	ui::events::event_source event_source{};

	// main_loop stuurt alle actors aan.
	main_loop(s, window, [&](delta_time dt, loop_controls& ctl) {
		// gebruik dt om te kijken hoeveel tijd versterken is
		// sinds de vorige keer dat deze lambda werd aangeroepen
		// loop controls is een object met eigenschappen die je kunt gebruiken om de
		// main-loop aan te sturen.

		for (ui::events::event& e : event_source) {
			// event heeft een methjode handle_quit die controleert
			// of de gebruiker de applicatie wilt sluiten, en zo ja
			// de meegegeven functie (of lambda) aanroept om met het
			// bijbehorende quit_event
			//
			e.handle_quit([&ctl](ui::events::quit_event qe) {
				ctl.quit = true;
				});
			e.handle_key_up([&my_actor](ui::events::key_event k) {
				switch (k.key) {
				case ui::events::key::up:
					my_actor.move({ 0, -5.0f });
					break;
				case ui::events::key::down:
					my_actor.move({ 0, 5.0f });
					break;
				case ui::events::key::left:
					my_actor.move({ -5.0f, 0 });
					break;
				case ui::events::key::right:
					my_actor.move({ 5.0f, 0 });
					break;
				default:
					break;
				}
				});
		}
		});
}
