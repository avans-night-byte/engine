//
// Created by sascha on 12/20/20.
//

#ifndef NIGHTBYTE_ASTAR_HPP
#define NIGHTBYTE_ASTAR_HPP

#include <array>
#include <hash_map>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <iostream>

struct GridLocation {
    int x, y;


    bool operator==(const GridLocation& a) const
    {
        return x == a.x &&
               y == a.y;
    }

    bool operator<(const GridLocation& a) const
    {
        return x < a.x &&
               y < a.y;
    }


    bool operator!=(const GridLocation& a) const
    {
        return x != a.x || y != a.y;
    }

};



namespace std {
/* implement hash function so we can put GridLocation into an unordered_set */
    template <> struct hash<GridLocation> {
        typedef GridLocation argument_type;
        typedef std::size_t result_type;
        std::size_t operator()(const GridLocation& id) const noexcept {
            return std::hash<int>()(id.x ^ (id.y << 4));
        }
    };
}

template<typename T, typename priority_t>
struct PriorityQueue {
    typedef std::pair<priority_t, T> PQElement;
    std::priority_queue<PQElement, std::vector<PQElement>,
            std::greater<PQElement>> elements;

    inline bool empty() const {
        return elements.empty();
    }

    inline void put(T item, priority_t priority) {
        elements.emplace(priority, item);
    }

    T get() {
        T best_item = elements.top().second;
        elements.pop();
        return best_item;
    }
};

struct SquareGrid {
    constexpr static const std::array<GridLocation, 4> DIRS = {
            /* East, West, North, South */
            GridLocation{1, 0}, GridLocation{-1, 0},
            GridLocation{0, -1}, GridLocation{0, 1}
    };

    int width, height;
    std::unordered_set<GridLocation> walls = std::unordered_set<GridLocation>();

    SquareGrid(int width_, int height_)
            : width(width_), height(height_) {}

    bool in_bounds(GridLocation id) const {
        return 0 <= id.x && id.x < width
               && 0 <= id.y && id.y < height;
    }

    bool passable(GridLocation id) const {
        return walls.find(id) == walls.end();
    }


    virtual std::vector<GridLocation> neighbors(GridLocation id) const {
        std::vector<GridLocation> results;

        for (GridLocation dir : DIRS) {
            GridLocation next{id.x + dir.x, id.y + dir.y};
            if (in_bounds(next) && passable(next)) {
                results.push_back(next);
            }
        }

        if ((id.x + id.y) % 2 == 0) {
            // see "Ugly paths" section for an explanation:
            std::reverse(results.begin(), results.end());
        }

        return results;
    }
};


struct GridWithWeights: SquareGrid {
    GridWithWeights(int w, int h): SquareGrid(w, h) {}
    std::unordered_set<GridLocation> destructables;
    double cost(GridLocation from_node, GridLocation to_node, GridLocation start, GridLocation goal) const {

        return destructables.find(to_node) != destructables.end()? 2 : 1;
    }

    static GridWithWeights fromArray(int** weights) {
        GridWithWeights grid = GridWithWeights(30, 30);

        for(int y = 0; y < 30; y++){
            for (int x = 0; x < 30; x++) {
                if(weights[y][x] == 1){
                    grid.walls.emplace(GridLocation{x, y});

                }

                if(weights[y][x] == 2){
                    grid.destructables.emplace(GridLocation{x, y});
                }
            }
        }
        return grid;
    }

    std::vector<GridLocation> neighbors(GridLocation id) const override {
        std::vector<GridLocation> results;



        // This needs some checking things break when collider is on the end.
        for (GridLocation dir : DIRS) {
            GridLocation next{id.x + dir.x, id.y + dir.y};
            if (in_bounds(next) && passable(next)) {
                results.push_back(next);
            }
        }

        if ((id.x + id.y) % 2 == 0) {
            // see "Ugly paths" section for an explanation:
            std::reverse(results.begin(), results.end());
        }

        return results;
    }
};


class Astar {
public:
    static void search(GridWithWeights graph, GridLocation start, GridLocation goal,
                std::unordered_map<GridLocation, GridLocation>&came_from,
                std::unordered_map<GridLocation, double>& cost_so_far);

    static inline double heuristic(GridLocation a, GridLocation b) {
        return std::abs(a.x - b.x) + std::abs(a.y - b.y);
    }
    static void reconstruct_path(std::vector<GridLocation>& path, GridLocation start, GridLocation goal,
            std::unordered_map<GridLocation, GridLocation> came_from
    );
};











#endif //NIGHTBYTE_ASTAR_HPP
