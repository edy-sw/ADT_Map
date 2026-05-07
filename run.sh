#!/bin/bash
g++ -Wall -g App.cpp Map.cpp MapIterator.cpp ShortTest.cpp ExtendedTest.cpp -o map_app

if [ $? -eq 0 ]; then
    echo "Compilation successful"
    ./map_app
else
    echo "Compilation failed. Please check the errors above."
fi
