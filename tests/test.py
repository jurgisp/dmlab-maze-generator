from dmlab_maze_generator import create_random_maze

for i in range(5):
    m = create_random_maze(width=13, height=13, room_object_count=1, has_doors=True)
    print(f'\n{m}')
    assert len(m.split('\n')) == 13