# dmlab-maze-generator

Python wrapper for [DMLab](https://github.com/deepmind/lab) C++ maze generator.

## Usage

```python
!pip install git+https://github.com/jurgisp/dmlab-maze-generator.git#egg=dmlab-maze-generator

from dmlab_maze_generator import create_random_maze
maze = create_random_maze(width=13, height=13, room_object_count=1, has_doors=True)
print(maze)

*************
***         *
***H******* *
*   I     * *
*   *O    * *
*   *     I *
*O  *H***** *
*   IO  I   *
*H***   ***H*
*   *   I   *
*** *   *   *
*** I   *O  *
*************
```