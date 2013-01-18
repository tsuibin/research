#!/bin/bash

for i in `cat userlist`;
    do useradd $i -G sudo -p $i;
done
