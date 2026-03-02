#include "matrix.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

// Function to create a 2D vector matrix
Matrix createVector(double x, double y) {
    Matrix vector(2, 1);
    vector.at(0, 0) = x;
    vector.at(1, 0) = y;
    return vector;
}

// Function to plot the position of the object on a grid
void plotTrajectory(const vector<Matrix>& trajectory, int gridWidth, int gridHeight) {
    vector<vector<char>> grid(gridHeight, vector<char>(gridWidth, ' '));

    // Plot each position in the trajectory
    for (const auto& position : trajectory) {
        int x = static_cast<int>(position.at(0, 0));
        int y = static_cast<int>(position.at(1, 0));

        // Ensure the coordinates are within the grid bounds
        if (x >= 0 && x < gridWidth && y >= 0 && y < gridHeight) {
            grid[gridHeight - 1 - y][x] = '*'; // Plot the object (inverted y-axis for display)
        }
    }

    // Print the grid
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

int main() {
    // Get the initial conditions
    double x,y,vx,vy;
    cout << "Position is in meters and velocity is in meters per second." << endl;
    cout << "Initial x position: ";
    cin >> x;
    cout << "Initial y position: ";
    cin >> y;
    cout << "Inital x velocity: ";
    cin >> vx;
    cout << "Inital y velocity: ";
    cin >> vy;

    // Initial position (x, y)
    Matrix position = createVector(x, y); // Start at height 10

    // Initial velocity (vx, vy)
    Matrix velocity = createVector(vx, vy); // 2 m/s horizontally

    // Acceleration due to gravity (ax, ay)
    Matrix gravity = createVector(0.0, -9.81); // m/s^2

    // Time step
    double deltaTime = 0.1; // seconds

    // Simulation duration
    double duration; // seconds
    cout << "Simulation Duration (seconds): ";
    cin >> duration;

    // Number of steps
    int steps = static_cast<int>(duration / deltaTime);

    // Grid dimensions for plotting
    int gridWidth = steps;
    int gridHeight = position.at(1,0)+1;

    // Store the trajectory
    vector<Matrix> trajectory;

    // Run the simulation
    for (int i = 0; i < steps; ++i) {
    position = position + velocity * deltaTime;
    velocity = velocity + gravity * deltaTime;

    if (position.at(1, 0) + 1 > gridHeight) {
        gridHeight = static_cast<int>(position.at(1, 0)) + 1;
    }

    trajectory.push_back(position);
}

    // Plot the trajectory
    plotTrajectory(trajectory, gridWidth, gridHeight);

    return 0;
}