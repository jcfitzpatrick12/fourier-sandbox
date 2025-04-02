#!/bin/bash

git clone https://github.com/jcfitzpatrick12/fourier-sandbox.git --no-checkout && cd fourier-sandbox
git sparse-checkout --no-cone
git sparse-checkout set cpp
git checkout
