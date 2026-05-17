# Space Shooter

A 2D arcade-style space shooter built in C++ using raylib.

The project focuses on clean game architecture, resource management, collision systems, and real-time gameplay programming.

---

## Download & Play

> Windows only

[![Download](https://img.shields.io/badge/Download-Play%20Now-blue)](https://github.com/san0502-jay/Space_Shooter/releases/latest/download/Space_Shooter.zip)

> If Windows shows a security warning, click **"More info"** → **"Run anyway"**. This is normal for unsigned executables.

---

## Features

- Smooth player movement
- Delta-time based movement
- Bullet shooting system
- Enemy spawning system
- Collision detection system
- Score tracking
- Lives and invulnerability system
- Game over system
- Entity cleanup system
- Centralized texture management
- Multi-file game architecture
- State-based game flow system

---

## Controls

| Key | Action |
|------|--------|
| W / ↑ | Move Up |
| S / ↓ | Move Down |
| A / ← | Move Left |
| D / → | Move Right |
| SPACE | Shoot |
| ESC | Exit Game |
| Mouse Left Click | UI Buttons |

---

## Technologies Used

- C++
- raylib
- CMake
- CLion

---

## Concepts Practiced

This project was built to practice core game programming concepts including:

- Game loops
- Delta-time movement
- Collision detection
- State machines
- Object-oriented programming
- Entity systems
- Dynamic spawning systems
- Resource management
- Texture lifetime management
- Real-time gameplay systems
- Rendering pipelines
- Multi-file project architecture

---

## Architecture Improvements

Recent refactors included:

- Fixed texture memory leaks by sharing textures across entities
- Removed global game state variables
- Moved gameplay logic out of `main.cpp`
- Added centralized constants system
- Standardized naming conventions
- Removed debug rendering from release build
- Added player lives and temporary damage invulnerability

---


## Future Improvements

Planned upgrades:

- Particle effects
- Audio system
- Enemy wave patterns
- High score saving
- Animation system
- Object pooling
- Better UI transitions
- Power-ups
## Build Instructions

```bash
mkdir build
cd build
cmake ..
cmake --build .
```