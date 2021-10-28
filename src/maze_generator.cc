// Copyright (C) 2016-2018 Google Inc.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
////////////////////////////////////////////////////////////////////////////////

#include "maze_generator.h"

#include <random>

#include "algorithm.h"
#include "text_maze.h"

std::string createRandomMaze(int seed,
                             int width,
                             int height,
                             int max_rooms,
                             int room_max_size,
                             int room_min_size,
                             int room_spawn_count,
                             int room_object_count,
                             int retry_count,
                             double extra_connection_probability,
                             int max_variations,
                             bool simplify,
                             bool has_doors) {
    std::mt19937_64 prng(seed);
    TextMaze maze(Size{height, width});

    // Create random rooms.
    SeparateRectangleParams params{};
    params.min_size = Size{room_min_size, room_min_size};
    params.max_size = Size{room_max_size, room_max_size};
    params.retry_count = retry_count;
    params.max_rects = max_rooms;
    params.density = 1.0;
    const auto rects = MakeSeparateRectangles(maze.Area(), params, &prng);
    const auto num_rooms = rects.size();
    for (unsigned int r = 0; r < num_rooms; ++r) {
        maze.VisitMutableIntersection(TextMaze::kEntityLayer, rects[r],
                                      [&maze, r](int i, int j, char *cell) {
                                          *cell = ' ';
                                          maze.SetCellId({i, j}, r + 1);
                                      });
    }

    // Fill the vacant space with corridors.
    FillSpaceWithMaze(num_rooms + 1, 0, &maze, &prng);

    // Connect adjacent regions at least once.
    auto conns = RandomConnectRegions(-1, extra_connection_probability, &maze, &prng);

    // Add variations.
    maze.VisitMutable(TextMaze::kVariationsLayer,
                      [max_variations, &maze, num_rooms](int i, int j, char *cell) {
                          auto id = maze.GetCellId({i, j});
                          if (id > 0 && id <= num_rooms) {
                              *cell = 'A' + (id - 1) % max_variations;
                          }
                      });

    // Simplify the maze if requested.
    if (simplify) {
        RemoveDeadEnds(' ', '*', {}, &maze);
        RemoveAllHorseshoeBends('*', {}, &maze);
    }

    // Add entities and spawn points.
    AddNEntitiesToEachRoom(rects, room_spawn_count, 'S', ' ', &maze, &prng);
    AddNEntitiesToEachRoom(rects, room_object_count, 'O', ' ', &maze, &prng);

    // Set each connection cell connection type.
    for (const auto &conn : conns) {
        char connection_type;
        // Set to wall if connected to nowhere.
        if (maze.GetCell(TextMaze::kEntityLayer, conn.first + conn.second) == '*') {
            connection_type = '*';
        } else if (has_doors) {
            connection_type = (conn.second.d_col == 0) ? 'H' : 'I';
        } else {
            connection_type = ' ';
        }
        maze.SetCell(TextMaze::kEntityLayer, conn.first, connection_type);
    }

    // Convert to string representation
    return maze.Text(TextMaze::kEntityLayer);
}