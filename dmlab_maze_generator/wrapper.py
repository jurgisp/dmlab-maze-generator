import random

import dmlab_maze_generator_cpp


def create_random_maze(seed=None,
                       width=11,
                       height=11,
                       max_rooms=4,
                       room_max_size=5,
                       room_min_size=3,
                       room_spawn_count=0,
                       room_object_count=0,
                       retry_count=1000,
                       extra_connection_probability=0.0,
                       max_variations=1,
                       simplify=True,
                       has_doors=False
                       ) -> str:
    """Generates a maze with a random layout of rooms and corridors..

    Args:
        seed (int, optional): Seed value for the random number generator. Defaults to None.
        width (int, optional): Width of maze. Defaults to 11.
        height (int, optional): Height of maze. Defaults to 11.
        max_rooms (int, optional): Maximum number of rooms. Defaults to 4.
        room_max_size (int, optional): Maximum room width or height. Defaults to 5.
        room_min_size (int, optional): Minimum room width or height. Defaults to 3.
        room_spawn_count (int, optional): The number of spawn locations per room. Defaults to 0.
        room_object_count (int, optional): The number of objects per room. Defaults to 0.
        retry_count (int, optional): Maximum number of attempts to layout rooms. Defaults to 1000.
        extra_connection_probability (float, optional): Probability of additional connections between adjacent rooms (1 is always added). Defaults to 0.0.
        max_variations (int, optional): Maximum number of variations. Defaults to 1.
        simplify (bool, optional): Remove dead ends and horseshoe bends. Defaults to True.
        has_doors (bool, optional): Whether to add doors to corridors between rooms. Defaults to False.

    Returns:
        str: Text representation of the maze (*=wall, S=spawn, O=object, I=horizontal door, H=vetrical door).
    """

    if seed is None:
        seed = random.randint(0, 123456789)
    maze = dmlab_maze_generator_cpp.create_random_maze(seed,
                                                       width,
                                                       height,
                                                       max_rooms,
                                                       room_max_size,
                                                       room_min_size,
                                                       room_spawn_count,
                                                       room_object_count,
                                                       retry_count,
                                                       extra_connection_probability,
                                                       max_variations,
                                                       simplify,
                                                       has_doors)
    maze = maze.rstrip()  # Remove trailing \n, so number of lines == height
    return maze
