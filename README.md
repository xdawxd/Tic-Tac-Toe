# Tic Tac Toe

## Description

a Tic Tac Toe game implementation using C++ and SFML introducing local mode and multiplayer to play with your friends.

# Getting Started

## Required Dependencies

* C++ 18
* SFML

## Installing

<p style="color: red">TODO</p>

## Help

<p style="color: red">TODO</p>

## Screenshots

### Menu
![image](https://github.com/xdawxd/Tic-Tac-Toe/assets/58686770/5e96e0d6-83bd-44e3-aa9d-0ab7dcc7f2cc)

### Local view
![image](https://github.com/xdawxd/Tic-Tac-Toe/assets/58686770/09569edb-96a9-4356-a7fe-d5b3c31410a5)

### Player win

**Horizontal**
![image](https://github.com/xdawxd/Tic-Tac-Toe/assets/58686770/2114cc90-dc91-4395-b24a-39045faab6f2)

**Vertical**
![image](https://github.com/xdawxd/Tic-Tac-Toe/assets/58686770/57e85fbe-6a48-4cb9-8579-52a8f4075a7e)

**Diagonal**
![image](https://github.com/xdawxd/Tic-Tac-Toe/assets/58686770/004fd61c-e27a-4895-ba00-c99b0b7ce2d6)

## Design patterns used

* Factory Method - State handling
* Observer - Game state updating

## TODO

* ~~Refactor function definition order in .cpp files~~
* ~~Rearange public/protected/private methods and variables inside the classes to some unified order~~
* ~~Change #include <> to "" for local .hpp files~~
* ~~Create a Base Button Class (see TODO in src/states/LocalState.cpp)~~
* ~~X (close window) on navigation not working~~
* ~~Implement LocalState back to menu Button (fix a bug with placing a symbol after clicking "MENU")~~
* Display "X Wins!", "O Wins!" or "Draw!" in some way
* Tidy the Board and Field classes. Resolve other todo's
* Implement Multiplayer state
* Implement Singleplayer (AI)
  * Add difficulties (EASY, NORMAL, HARD) - new State after selecting Local e.g.
```
LOCAL
SINGLEPLAYER
  --> EASY
  --> NORMAL
  --> HARD
MULTIPLAYER
EXIT
```

## Authors

Contributors names and contact info

**xdawxd** 


## Version History

* 0.1
    * Initial Release
