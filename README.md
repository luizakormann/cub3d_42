*This project was created as part of the 42 curriculum by kaidda-s and lukorman.*

# cub3D 
> My First RayCaster with miniLibX

## 📖 Description

**cub3D** is a graphics programming project developed as part of the **42 curriculum**.

Inspired by the principles behind classic first-person games such as *Wolfenstein 3D*, the project's goal is to create a dynamic first-person view inside a maze using the principles of **ray-casting**.

The program renders a pseudo-3D environment from a 2D map, allowing the player to navigate through the maze while walls are displayed according to their position and orientation.

This project combines several important areas of low-level programming, including:

- Computer graphics
- Ray-casting
- Mathematical reasoning
- Binary and geometric logic
- Event handling
- Window management
- Parsing and validation
- Memory management

The project is implemented in **C** using the **MiniLibX** graphics library.

---

### Mandatory Features

| Feature | Description |
|---------|-------------|
| 🖥️ **MiniLibX** | Uses the MiniLibX library for window and graphics management. |
| 🧱 **Wall Textures** | Displays different textures depending on whether the wall faces North, South, East, or West. |
| 🎨 **Floor and Ceiling Colors** | Allows independent RGB color configuration for the floor and ceiling. |
| 🗺️ **Map Parsing** | Reads and validates a scene description provided through a `.cub` file. |
| 🎮 **Player Movement** | Supports movement using the `W`, `A`, `S`, and `D` keys. |
| 🔄 **Camera Rotation** | Allows the player to look left and right using the arrow keys. |
| 🚪 **Clean Exit** | Handles `ESC` and window-close events correctly. |
| 🔒 **Map Validation** | Ensures that the map is properly closed and follows the expected format. |
| 💥 **Error Handling** | Detects invalid configurations and exits cleanly with an appropriate error message. |

---

## Instructions

Use the `Makefile` to compile and manage the project:

| Command | Description |
|---------|-------------|
| `make` | Compiles the mandatory version of `cub3D`. |
| `make all` | Builds the complete mandatory project. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and the compiled executable. |
| `make re` | Removes all generated files and recompiles the project from scratch. |

### Running the Program

After compilation:

```bash
./cub3D path/to/map.cub
```

Example:

```bash
./cub3D assets/maps/example.cub
```

---

## Resources

- [Lode's Computer Graphics Tutorial – Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- 42 School cub3D subject

### AI Usage

AI tools were used as a **learning and support resource** throughout the development process.

They were used to:

- Clarify technical concepts.
- Explore mathematical and graphics-related topics.
- Discuss project architecture and implementation approaches.
- Review and improve documentation.
- Help formulate debugging strategies and testing ideas.

All implementation decisions and submitted code are reviewed, tested, and understood by the author.

