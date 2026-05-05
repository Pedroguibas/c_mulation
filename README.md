# c_mulation

> A basic game physics simulation built in C++ using the Windows API, demonstrating object-oriented design principles and low-level system interaction.

---

## Overview

**c_mulation** is a real-time physics simulation written in C++, built directly on top of the Windows API. It serves as a hands-on exploration of game engine fundamentals — from collision detection and rigid body dynamics to low-level window management and rendering — all without relying on third-party game frameworks.

---

## Features

- 🧱 **Object-Oriented Architecture** — Simulation entities modeled as clean, composable C++ classes
- ⚙️ **Physics Engine** — Basic rigid body dynamics including gravity, velocity, and collision response
- 🖥️ **Windows API Integration** — Native Win32 window creation, message loop handling, and GDI rendering
- 🔁 **Real-Time Update Loop** — Fixed-timestep game loop for deterministic simulation behavior
- 📐 **Collision Detection** — Axis-aligned bounding box (AABB) or similar primitive collision checks

---

## Getting Started

### Prerequisites

- Windows OS
- [MinGW](https://www.mingw-w64.org/)

### Build & Run

From **CMD** or the **MinGW terminal**, in the project root:

```bash
./c_mulation
```

---

## Project Structure

```
c_mulation/
├── include/
│   ├── game/
│   │   ├── camera.h
│   │   └── gameController.h
│   ├── objects/
│   │   ├── boundry.h
│   │   ├── color.h
│   │   ├── entity.h
│   │   ├── hitboxObject.h
│   │   └── object.h
│   └── window/
│       ├── inputHandler.h
│       └── windowController.h
├── src/
│   ├── game/
│   │   ├── camera.cpp
│   │   └── gameController.cpp
│   ├── objects/
│   │   ├── boundry.cpp
│   │   ├── color.cpp
│   │   ├── entity.cpp
│   │   ├── hitboxObject.cpp
│   │   └── object.cpp
│   ├── window/
│   │   └── windowController.cpp
│   └── main.cpp
├── makefile
└── README.md
```

---

## Design Highlights

### Pragmatic Win32 Abstraction
The `WindowController` wraps the noisier parts of the Windows API — window registration, the message loop, and lifecycle management — into a more approachable interface, scoped specifically to what this kind of simulation needs. It's not a general-purpose UI toolkit; just enough abstraction to keep simulation logic clean without losing sight of what's happening underneath.

### OOP-Driven Simulation
Physics entities are represented as objects with encapsulated state (position, velocity, mass) and behavior (update, collide, draw). This mirrors the architecture used in real game engines and makes the codebase easy to extend.

---

## Learning Goals

This project was built to demonstrate:

- Practical application of **OOP principles** in C++ (encapsulation, inheritance, polymorphism)
- How **game loops** and **fixed timesteps** work under the hood
- Direct usage of the **Windows API** without abstraction layers
- Fundamentals of **2D physics simulation**

---

## License

This project is open source. See [`LICENSE`](LICENSE) for details.

---

*Built with C++ and the Windows API — no engines, no shortcuts.*
