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
![image](https://github.com/xdawxd/Tic-Tac-Toe/assets/58686770/433493ce-75ef-4094-9302-2c77d08e10b8)

### Player win

**Horizontal**
![image](https://github.com/xdawxd/Tic-Tac-Toe/assets/58686770/2b2d65c6-1388-4e7a-8d01-08e370d3499a)


**Vertical**
![image](https://github.com/xdawxd/Tic-Tac-Toe/assets/58686770/6cf6a859-08bb-46f6-9f29-9688181ca1dd)

**Diagonal**
![image](https://github.com/xdawxd/Tic-Tac-Toe/assets/58686770/ce03fc9e-1ffd-4074-974f-ea973b81cdad)

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
