# Sleepy Barber Project 3 CSCI 4334

## Overview
This project implements the Sleepy Barber Problem, a classic synchronization problem, using semaphores and threads in C. The barbershop has a barber and a waiting room with a limited number of chairs. Customers arrive, take a chair if available, and get a haircut. If the barber is asleep, the customer wakes them. If all chairs are taken, the customer leaves.

## Features
- Implements synchronization using semaphores (`mutex`, `chair`, `waitingCustomer`).
- Uses pthreads for the barber and customer threads.
- Prints messages for actions (e.g., "Customer is taking a chair").

## Setup
1. Clone the repository: `git clone https://github.com/JosueAranday/sleepy-barber-Project3CSCI4334.git`
2. Compile the program: `gcc -o sleepybarber sleepybarber.c -lpthread`
3. Run the program: `./sleepybarber`

## Status
- [ ] Implement customer and barber threads.
- [ ] Test synchronization with semaphores.
- [ ] Submit a screenshot of the program running in Codespaces.