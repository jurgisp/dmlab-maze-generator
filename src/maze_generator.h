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

#ifndef DML_DEEPMIND_ENGINE_LUA_MAZE_GENERATION_H_
#define DML_DEEPMIND_ENGINE_LUA_MAZE_GENERATION_H_

#include "text_maze.h"

std::string createRandomMaze(int seed,
                             int width = 11,
                             int height = 11,
                             int max_rooms = 4,
                             int room_max_size = 5,
                             int room_min_size = 3,
                             int room_spawn_count = 0,
                             int room_object_count = 0,
                             int retry_count = 1000,
                             double extra_connection_probability = 0.0,
                             int max_variations = 1,
                             bool simplify = true,
                             bool has_doors = false);

#endif  // DML_DEEPMIND_ENGINE_LUA_MAZE_GENERATION_H_
