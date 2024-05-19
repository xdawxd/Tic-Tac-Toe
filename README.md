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
![image](https://github.com/xdawxd/Tic-Tac-Toe/assets/58686770/03f8387a-fe10-4824-a4e4-1bbfe077c08e)

### Local view

![Uploading image.png…]()

### Player win
![Uploading image.png…]()

## Design patterns used

* Factory Method - State handling
* Observer - Game state updating

## TODO

* ~~Refactor function definition order in .cpp files~~
* ~~Rearange public/protected/private methods and variables inside the classes to some unified order~~
* ~~Change #include <> to "" for local .hpp files~~
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
