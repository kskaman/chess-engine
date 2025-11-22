> **Files**: In chess, the vertical columns of the chessboard are called files. They are labeled from 'a' to 'h' starting from the left side of the board from White's perspective. For example, the leftmost column is the 'a' file, and the rightmost column is the 'h' file.

> **Ranks**: In chess, the horizontal rows of the chessboard are called ranks. They are numbered from 1 to 8 starting from White's side of the board. The rank closest to White is the 1st rank, and the rank closest to Black is the 8th rank. For example, White's pawns start on the 2nd rank, while Black's pawns start on the 7th rank.

> **Half-move**: A half-move is a single move made by one player. In chess notation, a full move consists of two half-moves: one by White and one by Black. For example, if White moves a pawn and then Black moves a knight, that counts as one full move (two half-moves). A half move is termed as **ply** in computer chess terminology.

> **Fifty-move rule**: The fifty-move rule in chess states that a player can claim a draw if no pawn has been moved and no capture has been made in the last fifty consecutive moves by each player (i.e., 100 half-moves or plies). This rule is designed to prevent games from dragging on indefinitely when neither player is making progress toward checkmate.

> ## Passed Pawn

A passed pawn is a pawn that has a clear path to promotion, because:

- there are no enemy pawns in front of it,
- and no enemy pawns on the next file to the left,
- and none on the next file to the right.

In simple words:
A passed pawn cannot be stopped by another pawn. Only pieces can stop it.

Why engines love passed pawns:

- They can promote into a queen.
- When a pawn advances, the opponent must spend resources to stop it.
- Passed pawns get stronger the closer they get to the promotion square.

Engines therefore give a big score bonus for passed pawns based on their rank:
rank 2 (starting rank) -> small bonus  
rank 5 -> large bonus  
rank 7 -> extremely large bonus (almost queen value)

> ## Pawn Score

Pawn score is the part of the engine's evaluation that comes only from pawns.

Pawns are the structure of the game. Their positions decide:

- how open or closed the board is,
- whether your pieces have space,
- whether your king is safe,
- whether you can create passed pawns,
- whether your opponent has weaknesses.

Because pawns cannot move backwards, any weakness in pawn structure stays weak forever.
So engines evaluate pawns very carefully.

Pawn score usually includes:

- bonuses for strong pawns (connected pawns, protected passed pawns),
- penalties for weak pawns (isolated, doubled, backward),
- bonuses for passed pawns,
- structure safety around the king.

This becomes part of the total evaluation:

**total_eval = pawn_score + piece_score + mobility + king_safety + threats**

> ## Flip the Board

Engines often use "piece-square tables" (PSTs).

A PST says: "This square is good or bad for a piece."

Example for white knight:

- knight in the center = good,
- knight on the edge = bad.

Instead of writing two tables:

- one for white knights
- one for black knights

Engines do something smarter:

They **flip the board vertically** when evaluating black.

This means:

- the black knight at square 0 is evaluated as if it were the white knight at square 63.

So we only need **ONE** PST for each piece type.

This saves:

- memory,
- code,
- bugs,
- effort.

"Flip the board" is basically mirroring the board so black's perspective becomes white's.

> ## Piece Value

Every chess engine uses numerical values for pieces.

Traditional values:

- Pawn = 1
- Knight = 3
- Bishop = 3
- Rook = 5
- Queen = 9

Engines multiply these by 100 for easier calculations:

- Pawn = 100
- Knight = 300
- Bishop = 330
- Rook = 500
- Queen = 900

Why multiply by 100?
Because:

- it avoids decimals,
- it's easier to tune,
- you get more precision in evaluation.

Material is the most important part of evaluation.
If one side has more material, that side is usually winning.

> ## Total Piece Value

Total piece value means the sum of all pieces a player has.

Example for White:

- 1 Queen = 900
- 2 Rooks = 1000
- 2 Bishops = 650
- 2 Knights = 600
- 8 Pawns = 800

Total = 3950

Engines compare:

**material_score = white_total - black_total**

If white's material score is positive -> white is ahead.
If negative -> black is winning.

> ## Total Pawn Value

This simply means:

**number_of_pawns x value_of_each_pawn**

If pawn value = 100 and you have 7 pawns:

total_pawn_value = 7 × 100 = 700

BUT modern engines also adjust pawn value based on:

- pawn structure,
- weaknesses,
- passed pawn bonuses,
- king safety.

So the real pawn contribution is:

pawn_score = (raw pawn material) + (structure bonuses/penalties)
