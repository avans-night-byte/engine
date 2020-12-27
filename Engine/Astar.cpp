#include "Astar.hpp"


void Astar::search(GridWithWeights graph, GridLocation start, GridLocation goal, std::unordered_map<GridLocation, GridLocation> &came_from,
                   std::unordered_map<GridLocation, double> &cost_so_far) {
    PriorityQueue<GridLocation, double> frontier;
    frontier.put(start, 0);

    came_from[start] = start;

    cost_so_far[start] = 0;

    while (!frontier.empty()) {
        GridLocation current = frontier.get();

        if (current == goal) {
            break;
        }

        for (GridLocation next : graph.neighbors(current)) {
            double new_cost = cost_so_far[current] + graph.cost(current, next, start, goal);
            if (cost_so_far.find(next) == cost_so_far.end()
                || new_cost < cost_so_far[next]) {
                cost_so_far[next] = new_cost;
                double priority = new_cost + heuristic(next, goal);
                frontier.put(next, priority);

                came_from[next] = current;
            }
        }
    }
}

void Astar::reconstruct_path(std::vector<GridLocation>& path, GridLocation start, GridLocation goal,
                             std::unordered_map<GridLocation, GridLocation> came_from) {
    GridLocation current = goal;
    std::queue<GridLocation> items;

    std::cout << start.x << " , " << goal.x << std::endl;
    std::cout << start.y << " , " << goal.y << std::endl;

    while (current != start) {
        path.push_back(current);
        current = came_from[current];
    }
    path.push_back(start); // optional
    std::reverse(path.begin(), path.end());
}

