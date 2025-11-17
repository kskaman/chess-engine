> # 1 - Chess Engine

> ### What is an engine ?

An **engine** in computing is a core component of a software that performs essential processing or computations. It's like the "brain" or "powerhouse" that processes data, does heavy computations and produces results. It typically powers specific functionality, like:

- A **search engine** processes and ranks web pages
- A **game engine** handles graphics, physics, and game logic
- A **database engine** manages data storage and retrieval

In software, engine is a modular component that can be integrated into larger applications to provide specialized capabilities.

### What is a Chess Engine ?

A **chess engine** is a specialized software program designed to play chess autonomously. It uses algorithms and data structures to evaluate chess positions, generate possible moves, and determine the best course of action. It uses a combination of

- **Search algorithms** (like minimax with alpha-beta pruning) to explore possible future moves and outcomes.
- **Evaluation function**s to assess the strength of different positions on the chessboard.
- **Opening databases** to play strong early moves
- **Endgame tablebases** to play perfect endgames

Chess engines can analyze games, suggest moves, and even play against human players or other engines. Famous chess engines are **Stockfish**, **AlphaZero**, and **Leela Chess Zero**.

# Phase 1 - Foundations

## Step 1 - Understanding board representation

First, we need to represent the chessboard in a way that the engine can understand and manipulate. There are two main ways to represent a chessboard in a computer program:

1. `array-based representation` : An 8x8 array where each element represents a square on the chessboard. Each piece is represented by a specific value (e.g, `board[0] = WHITE_ROCK`, board[63] = `BLACK_ROCK`). This representation is simple to understand and debug , easy to debug. However, it can be slower for move generation and attack lookups and harder to perform parallel operations.

- `bitboard representation` : A more advanced method that uses `64-bit unsigned integer` to represent the chessboard. Each bit in the integer corresponds to a square on the chessboard. `1` indicates the presence of a piece, while `0` indicates an empty square.

Bitboard representations provide extremely fast bitwise operations to manipulate and query the board state. It is perfect for move generation and attack tables. It is used by all modern chess engines (Stockfish, Lc0, NNUE). The complication is that it is more abstract, harder to implement and debug for beginners.
