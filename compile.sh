#!/bin/bash
mkdir build
cd build || return
cmake ..
cp compile_commands.json ../
make
