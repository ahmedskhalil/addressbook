#!/usr/bin/env bash
mkdir -p build_x && cd build_x && rm -rf * && cmake -G "Xcode" .. && open *.xcodeproj