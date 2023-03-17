#!/bin/bash

cd projections

cmake .

make

cd ../triangulation

make

cd ../comparison/build

cmake . ..
make

