#pragma once
#include "kmint/map/map.hpp"
#include <queue>
#include <map>
namespace kmint
{
	class astar
	{
		map::map_graph& graph_;
		std::queue<const map::map_node*> untag_queue_;

		std::queue<const map::map_node*> reconstruct_path(const map::map_node* start, const map::map_node* goal, std::map<const map::map_node*, const map::map_node*> came_from);
		double heuristic(const map::map_node& a, const map::map_node& b) const;

	public:
		astar(map::map_graph& graph) : graph_(graph)
		{
		}

		std::queue<const kmint::map::map_node*> astar::AstarSearch(const kmint::map::map_node& start,
			const kmint::map::map_node& goal);

		void astar::untag_nodes();
	};
}