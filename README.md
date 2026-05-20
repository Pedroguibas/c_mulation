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

### 1. Install MSYS2

Download and install from the [official MSYS2 page](https://www.msys2.org/), using the default directory:

```
C:\msys64
```

### 2. Update packages

Open the **MSYS2** terminal and run:

```bash
pacman -Syu
```

Close the terminal when prompted, reopen it, then run:

```bash
pacman -Su
```

### 3. Install the compiler and tools

In the MSYS2 terminal:

```bash
pacman -S --needed \
  mingw-w64-ucrt-x86_64-gcc \
  mingw-w64-ucrt-x86_64-make
```

This installs `g++`, `gcc`, and `make`.

### 4. Add MinGW to PATH

Add the following folder to your Windows PATH:

```
C:\msys64\ucrt64\bin
```

Restart the MSYS2 UCRT64 terminal, then verify the installation:

```bash
g++ --version
make --version
```

### 5. Build

In the MSYS2 terminal, navigate to the project root and run the make command:

```bash
cd /c/path/to/c_mulation
mingw32-make
```

This generates `c_mulation.exe`.

### 6. Run

From the MSYS2 terminal, in the project directory:

```bash
./c_mulation
```

From CMD, in the project directory:

```cmd
c_mulation
```

Or double-click `c_mulation.exe` in the project folder.

---

## Project Structure

```
c_mulation/
├── .vscode/
│   └── settings.json
├── include/
│   ├── components/
│   │   ├── center.h
│   │   ├── colMenu.h
│   │   ├── colorfulComponent.h
│   │   ├── column.h
│   │   ├── component.h
│   │   ├── flex.h
│   │   ├── hpDisplay.h
│   │   ├── menu.h
│   │   ├── row.h
│   │   ├── rowMenu.h
│   │   └── text.h
│   ├── game/
│   │   ├── camera.h
│   │   ├── gameController.h
│   │   ├── gui.h
│   │   ├── inputHandler.h
│   │   └── menuStack.h
│   ├── objects/
│   │   ├── boundry.h
│   │   ├── box.h
│   │   ├── color.h
│   │   ├── entity.h
│   │   ├── hitboxObject.h
│   │   ├── mob.h
│   │   ├── object.h
│   │   ├── scriptedMob.h
│   │   ├── triggerZone.h
│   │   ├── triggerZone.tpp
│   │   ├── triggerZoneBase.h
│   │   ├── visibleTriggerZone.h
│   │   └── visibleTriggerZone.tpp
│   └── window/
│       ├── renderer.h
│       └── windowController.h
├── src/
│   ├── components/
│   │   ├── center.cpp
│   │   ├── colMenu.cpp
│   │   ├── colorfulComponent.cpp
│   │   ├── column.cpp
│   │   ├── component.cpp
│   │   ├── flex.cpp
│   │   ├── hpDisplay.cpp
│   │   ├── menu.cpp
│   │   ├── row.cpp
│   │   ├── rowMenu.cpp
│   │   └── text.cpp
│   ├── game/
│   │   ├── camera.cpp
│   │   ├── gameController.cpp
│   │   ├── gui.cpp
│   │   ├── inputHandler.cpp
│   │   └── menuStack.cpp
│   ├── objects/
│   │   ├── boundry.cpp
│   │   ├── box.cpp
│   │   ├── color.cpp
│   │   ├── entity.cpp
│   │   ├── hitboxObject.cpp
│   │   ├── mob.cpp
│   │   ├── object.cpp
│   │   └── scriptedMob.cpp
│   ├── window/
│   │   ├── renderer.cpp
│   │   └── windowController.cpp
│   └── main.cpp
├── .clang-format
├── .gitignore
├── .prettierrc
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

_Built with C++ and the Windows API — no engines, no shortcuts._
