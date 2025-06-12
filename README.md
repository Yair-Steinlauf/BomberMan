בשמחה! הנה הגרסה עם אייקונים (באופן שמתאים ל־GitHub markdown):

---

# 🚀 BomberMan Game

This project is a C++ implementation of a classic BomberMan-style 2D game using SFML. It features inheritance, polymorphism, and a modular design.

## 🎮 Gameplay Overview

* **🎯 Objective:** Collect the key, unlock the door, and reach it before time runs out.
* **👮 Enemies:** Guards chase the player intelligently; their AI difficulty increases as the player eliminates more guards.
* **💣 Bombs:** Player can place bombs to eliminate guards and destroy obstacles.
* **🎁 Power-ups:** Collect gifts that grant extra lives, instant guard kills, extra time, or freeze guards temporarily.
* Combines strategy, time management, and dynamic enemy behavior.

## ⚙️ Key Features

* 🔄 Polymorphic game objects managed with `unique_ptr` vectors.
* 🧠 Smart guard AI with difficulty levels adjusting over time.
* 🔀 Double dispatch for collision handling.
* 📦 Resource management via singleton loaders (textures, sounds, fonts).
* 🖥️ Responsive UI with multiple screens (menu, pause, game over, help).

## 📂 Project Structure

* **Core Classes:**

  * 🕹️ `Master` – manages game states and input handling
  * 🗺️ `Board` – game level and object management
  * 🎮 `GameObject` – base class for all game objects
  * 🏃 `MovingObject` – abstract base for player and guards
  * 👤 `Player`, 👮 `Guard` – character classes with unique behaviors
  * 🧱 `StaticObject` – base for walls, stones, doors, bombs, keys, and power-ups

* **Screens:**

  * 📋 `Menu`, ⏸️ `PauseScreen`, 💀 `GameOverScreen`, ❓ `HelpScreen`, 🎲 `GameManager`

* **Utilities:**

  * 📁 `DataLoader`, 🔊 `SoundHandle` – singleton resource loaders
  * 🔣 `Types` – enums and constants used throughout the game

