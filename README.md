<div align="center">

# Project Maze Runner

### A fast-paced first-person parkour prototype built in Unreal Engine 5

Navigate procedurally assembled 3D mazes using responsive movement abilities, dynamic traversal, and a modular level-generation system.

![Unreal Engine](https://img.shields.io/badge/Unreal_Engine_5-0E1128?style=for-the-badge&logo=unrealengine&logoColor=white)
![Blueprints](https://img.shields.io/badge/Blueprints-137CBD?style=for-the-badge&logo=unrealengine&logoColor=white)
![Blender](https://img.shields.io/badge/Blender-E87D0D?style=for-the-badge&logo=blender&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)

</div>

## Overview

**Project Maze Runner** is a single-player, first-person parkour game prototype focused on fluid traversal through procedurally generated 3D environments. The project combines modular maze construction with movement mechanics such as dashing, double jumping, and gravity-assisted wall running.

The game was developed primarily with Unreal Engine Blueprints, with a small amount of C++, and uses Blender for custom 3D assets.

## Key Features

- **Procedural maze generation** based on an iterative randomized Prim's algorithm
- **Modular level construction** using reusable path pieces, including straight, corner, T-shaped, and L-shaped sections
- **Fast-paced parkour movement** with dashing, double jumping, and wall running
- **First-person traversal** designed around responsive player and camera control
- **Dynamic lighting and day-night systems**
- **Custom visual effects** for entities and speed feedback
- **Gameplay UI and widget systems**
- **Custom assets and collision setup** created for the generated environment

## Maze Generation

The procedural-generation system adapts randomized Prim's algorithm for a modular 3D level:

1. Generation begins from an initial maze cell.
2. Neighboring cells are added to a frontier set.
3. A frontier cell is selected randomly and connected to the existing maze.
4. The process repeats until the required maze area has been generated.
5. Appropriate modular floor pieces and surrounding walls are placed from the resulting connectivity data.

This approach produces structured but unpredictable layouts, avoids recursive generation, and creates a connected maze with a unique route between cells.

## Controls

| Action | Input |
|---|---|
| Move | <kbd>W</kbd> <kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd> |
| Look | Mouse |
| Jump | <kbd>Space</kbd> |
| Double jump | Press <kbd>Space</kbd> twice |
| Dash | Movement key + <kbd>E</kbd> |
| Wall run | Move alongside a valid wall while airborne |

## Technology

| Area | Technology |
|---|---|
| Game engine | Unreal Engine 5 |
| Gameplay systems | Blueprints, limited C++ |
| 3D asset creation | Blender |
| Target platform | Windows |
| Version control | Git and GitHub |

## Getting Started

### Prerequisites

- Unreal Engine 5
- Git
- Visual Studio 2022 with the **Game development with C++** workload, if rebuilding C++ modules

### Setup

```bash
git clone https://github.com/DhruvJ12421/Project-Maze-Runner.git
cd Project-Maze-Runner
```

Open the project's `.uproject` file in Unreal Engine. If Unreal prompts you to rebuild project modules, allow it to generate and compile them using Visual Studio.

> This is an Unreal Engine development repository and may require a substantial download because it contains binary game assets.

## Project Structure

The project follows the standard Unreal Engine layout:

- `Config/` — engine, input, and project configuration
- `Content/` — Blueprints, maps, materials, meshes, effects, and UI assets
- `Source/` — C++ modules used by the project
- `*.uproject` — Unreal Engine project descriptor

## Team

Project Maze Runner was created by a four-person team:

- [Dhruv Jain](https://github.com/DhruvJ12421)
- Shalin Saju
- [Shubham Jain](https://github.com/ShubhamJain9674)
- Kishore V
  
My contributions included the day-night cycle, map creation, character-movement debugging, particle systems, widgets, procedural map generation, asset creation, mesh collision, and gameplay testing.

## Status

This repository contains a playable prototype and remains a learning and portfolio project. It is not currently presented as a production release.

## License

No license has been specified. Unless a license is added, all rights are reserved by the project contributors.
