#!/usr/bin/env bash
gcc -Wall -Wextra -pedantic -Wpedantic -o droitAuBut droitAuBut.c ../../src/track/track.c -lm && mv droitAuBut ./drivers/
