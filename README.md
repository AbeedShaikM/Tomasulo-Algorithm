# Tomasulo Algorithm Simulation

This repository contains a C++ implementation of the Tomasulo algorithm, a hardware algorithm used for dynamic instruction scheduling to achieve high levels of instruction-level parallelism.

## Table of Contents

- [Overview](#overview)
- [Installation and usage](#installation and usage)

## Overview

The Tomasulo algorithm is used in modern CPUs to dynamically schedule instructions to improve performance by exploiting instruction-level parallelism. This repository provides a simulation of the Tomasulo algorithm, including various components such as reservation stations, registers, and a scheduler.


### Key Components

- **Config**: Contains the `c_Config` class for storing and retrieving configuration parameters.
- **Instruction**: Contains classes for representing different types of instructions (`c_Instruction`, `c_RInstruction`, `c_LOADSTOREInstruction`).
- **Register**: Contains the `c_Register` class for representing processor registers.
- **Reservation_station**: Contains the `c_ReservationStation` class for representing reservation stations.
- **Scheduler**: Contains the `c_Scheduler` class for scheduling instructions and managing functional units.

## Installation

To compile and run the program, you need to have `g++` installed. You can compile the program using the provided `Makefile`.

```sh
cd src
make
./my_program
