kmintapp

A small educational app built around the KMINT assignment, focusing on simulations, pathfinding and object-oriented design.

---

Table of Contents

Overview

Features

Screenshots

Architecture

Getting Started

Prerequisites

Installation

Running the App


Configuration

Development

Testing

Known Issues & Limitations

Future Improvements

Contributing

License



---

Overview

kmintapp is an educational project that explores:

Simulations on a 2D map or grid.

Basic AI or pathfinding logic (e.g. moving agents, decision making).

Clean object-oriented design and separation of concerns.


Use this project as:

A reference for similar school assignments.

A playground for experimenting with new algorithms or features.

A base to compare different design or architecture approaches.


You can integrate your own description here, for example:

> “This app simulates entities moving on an island map, making decisions based on their surroundings.”




---

Features

Adapt/extend this list to match your actual functionality:

Map / World simulation

Load a predefined map or level.

Step through the simulation tick by tick.


Agents / Entities

Multiple entity types with different behaviours.

Configurable speed, vision, or decision rules.


Pathfinding / AI

Simple pathfinding or steering behaviour.

Rule-based or state-based decision making.


Visualization / UI

Graphical representation of the world.

Highlighted paths, active entities and states.


Configurable parameters

Tweak speeds, delays, map files, or other constants to experiment.




---

Screenshots

Add screenshots from your repo here (for example, in a docs/ or assets/ folder):

![kmintapp main screen](docs/screenshot-main.png)
![Simulation in progress](docs/screenshot-simulation.png)

If you don’t have screenshots yet, you can remove this section or keep it as a reminder.


---

Architecture

Below is a generic high-level structure you can adapt to your actual code:

Core / Domain

Entities and their state (e.g. Rabbit, Fox, Tile, GraphNode).

Simulation rules and time-stepping (World, Game, Simulation).


Infrastructure

Map loading / parsing (JSON, text, or custom format).

Asset loading (images, fonts, etc.).


Presentation / UI

Rendering of the world and entities.

Handling keyboard / mouse input.


Utilities

Math helpers, graph algorithms, pathfinding utilities.

Logging and debug helpers.



You can document your actual namespaces, packages, or directories here, for example:

src/
  core/
  ui/
  infrastructure/
  ...


---

Getting Started

Prerequisites

Adjust this section to your real tech stack. Typical examples:

A modern C++ compiler (e.g. g++ / clang++ with C++17 support)

Or: Java 8+

Or: .NET SDK

Or: Node.js / npm


You may also require:

A specific framework or library (e.g. SFML, SDL, JavaFX, Unity, etc.).

CMake or another build system.


Installation

Clone the repository:

git clone https://github.com/ferrannl/kmintapp.git
cd kmintapp

If you use a build system, document it here, for example:

# Example using CMake – adapt or replace with your actual commands
mkdir build
cd build
cmake ..
cmake --build .

or, for other stacks:

# Java / Gradle example
./gradlew build

# .NET example
dotnet restore
dotnet build

Running the App

Document the actual executable or command here, for example:

# Example
./kmintapp

or:

# Java example
java -jar build/libs/kmintapp.jar

# .NET example
dotnet run --project src/kmintapp

If your app takes arguments (e.g. map file, seed, speed), describe them here:

./kmintapp --map data/island.map --speed 1.5 --seed 42


---

Configuration

If your app supports configuration files or command-line flags, explain them here.

For example:

Config file: config.yml or config.json

Possible options:

map: path to the map file

tick_duration: delay between simulation ticks (in ms)

entity_count: number of entities of each type



{
  "map": "data/island.map",
  "tick_duration": 50,
  "entities": {
    "rabbits": 5,
    "foxes": 2
  }
}


---

Development

Add notes for people who want to work on the project:

Coding style: e.g. follow a particular style guide.

Branching model: e.g. main + feature branches.

Useful scripts: list any helper scripts or make targets.


Example (adapt to your real setup):

# Rebuild quickly
make

# Run with debug logging
./kmintapp --debug

If you have a preferred IDE setup (Visual Studio / CLion / VS Code), mention it here.


---

Testing

If you have automated tests, document how to run them. For example:

# CTest example
cd build
ctest

# Or, for other setups:
npm test
dotnet test
./gradlew test

Also describe what is covered by the tests:

Unit tests for core logic (pathfinding, rules, etc.).

Integration tests for larger simulation scenarios.

Visual or manual test scenarios (e.g. specific map files).



---

Known Issues & Limitations

Use this section to be honest about current constraints. Fill in what applies:

Some edge cases in pathfinding are not yet handled.

Performance may degrade with very large maps.

UI is optimized for desktop and may not scale well on very small screens.

No save/load functionality yet.



---

Future Improvements

Ideas for extending the app:

Additional entity types with unique behaviours.

More advanced AI (A*, state machines, behavior trees, etc.).

In-game UI controls to pause, step, or adjust speed.

Map editor to create or edit levels.

Export simulation stats (e.g. number of steps, survival times).



---

Contributing

Contributions, suggestions, or bug reports are welcome.

1. Fork the repository.


2. Create a feature branch:

git checkout -b feature/my-new-feature


3. Commit your changes with clear messages.


4. Push the branch and open a pull request.


> This repository is primarily for educational purposes and not actively maintained. Feel free to fork it for your own experiments.
