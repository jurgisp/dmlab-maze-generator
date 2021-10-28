import sys

from pybind11 import get_cmake_dir
from pybind11.setup_helpers import Pybind11Extension
from setuptools import setup

__version__ = "0.1.0"

ext_modules = [
    Pybind11Extension(
        "dmlab_maze_generator_cpp",
        [
            "src/pybind.cc",
            "src/algorithm.cc",
            "src/flood_fill.cc",
            "src/maze_generator.cc",
            "src/text_maze.cc",
        ],
        define_macros=[('VERSION_INFO', __version__)],
        cxx_std=11
    ),
]

setup(
    name="dmlab-maze-generator",
    packages=["dmlab_maze_generator"],
    version=__version__,
    author="Jurgis Pasukonis",
    author_email="jurgisp@gmail.com",
    url="https://github.com/jurgisp/dmlab-maze-generator",
    description="Python wrapper for DMLab maze generator",
    ext_modules=ext_modules,
    zip_safe=False,
    python_requires=">=3.6",
)
