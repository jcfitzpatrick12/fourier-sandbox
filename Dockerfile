FROM ubuntu:20.04 AS base 

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \ 
    apt-get install -y \
    cmake g++ make vim git

WORKDIR /app

COPY --chmod=0755 ./scripts/bash/clone_latest.sh ./clone_latest.sh

RUN ./clone_latest.sh && rm clone_latest.sh

 
