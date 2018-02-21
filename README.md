# Minimax tic-tac-toe implementation in ReasonML
*mostly a port from my [Haskell code](https://github.com/venil7/Programming-in-Haskell-exercises-/blob/master/tttoe/ttoe.hs)*

A tic-tac-toe engine for Browser, Node.js, Mobile or Native.

## Build
[![Build Status](https://travis-ci.org/venil7/ReasonML-TicTacToe.svg?branch=master)](https://travis-ci.org/venil7/ReasonML-TicTacToe)
```
npm install
npm run build
```

## Install
```
npm install reason-tttoe --save
```
### Update `bsconfig.json`
```
...
"bs-dependencies": [
    "reason-tttoe"
]
...
```

## Run [Example](./example/)
```
cd example
npm install
npm start
```
*this is how example it looks*

![example gameplay](https://user-images.githubusercontent.com/508022/36355005-4baa9e48-14d4-11e8-8ec8-dac0aee5c872.gif)


## Run Tests

```
npm run test
```