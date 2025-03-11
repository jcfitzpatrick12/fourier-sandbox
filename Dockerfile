FROM ubuntu:20.04 AS base 

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \ 
    apt-get install -y \
    cmake \
    g++ \
    make \
    vim \
    git

WORKDIR /app

 
