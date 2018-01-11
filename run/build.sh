#!/bin/bash

docker build -t localhost:30000/p2p/run .

docker push localhost:30000/p2p/run
