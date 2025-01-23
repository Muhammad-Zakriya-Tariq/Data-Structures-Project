# Haunted House Escape Game

An interactive console-based adventure game implemented in **C++**. In this game, players navigate through a mysterious haunted house, exploring various rooms, solving puzzles, collecting treasures, and avoiding traps to find the way out.

---

## Features

- **Room Navigation**: 
  - Explore a series of connected rooms, each with its own unique layout and challenges.
  - Navigate through doors (`D`), pathways (`P`), and walls (`#`).

- **Interactive Gameplay**: 
  - Engage with objects like:
    - Treasures (`T`) to collect.
    - Traps (`X`) to avoid.
    - The goal (`G`) to escape the haunted house.

- **Customizable Levels**: 
  - Room layouts are stored in external `.txt` files, allowing for easy customization or extension of game levels.

- **Save System**: 
  - Track progress dynamically as you move between rooms.

---

## File Structure

### Code Files:
- **`main.cpp`**: Contains the main game logic, user interaction, and room traversal mechanisms.

### Room Layout Files:
- **`room1.txt`, `room2.txt`, `room3.txt`, `room4.txt`, `room5.txt`**: Define the structure of each room, including:
  - **Walls (`#`)**: Impassable barriers.
  - **Treasures (`T`)**: Collectible items.
  - **Traps (`X`)**: Dangerous obstacles to avoid.
  - **Doors (`D`)**: Pathways connecting rooms.
  - **Goal (`G`)**: The objective to escape.

---

## How to Play

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/haunted-house-game.git
   ```

2. Navigate to the project directory:
   ```bash
   cd haunted-house-game
   ```

3. Compile the game using a C++ compiler, such as `g++`:
   ```bash
   g++ main.cpp -o hauntedhouse
   ```

4. Run the game:
   ```bash
   ./hauntedhouse
   ```

5. Follow the on-screen instructions to navigate through the haunted house and find your way out.

---

## Example Room Layout (`room1.txt`):
```
##########
#P  T   D#
#  ###   #
#X     G #
##########
```
- **P**: Player's starting position.
- **T**: Treasure.
- **X**: Trap.
- **D**: Door to the next room.
- **G**: Goal.

---

## Future Enhancements

- Add more complex puzzles and traps.
- Implement a scoring system based on time and treasures collected.
- Add graphical user interface (GUI).

---

## Contributions

Contributions are welcome! Feel free to fork this repository and submit pull requests for new features, bug fixes, or enhancements.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
