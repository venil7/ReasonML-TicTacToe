type player =
  | X
  | O;

type cell =
  | Occupied(player)
  | Empty;

type board = list(cell);

let new_board = (side: int) : board => {
  let rec aux = (n: int) => n > 0 ? [Empty, ...aux(n - 1)] : [];
  aux(side * side);
};

exception InvalidMove;

let make_move = (player: player, board: board, n: int) : board => {
  let rec aux = (cell: cell, board: board, n: int, accum: board) : board =>
    switch board {
    | [] => accum
    | [Empty, ...xs] when n == 0 => accum @ [cell, ...xs]
    | [Empty as x, ...xs] => aux(cell, xs, n - 1, [x, ...accum])
    | _ => raise(InvalidMove)
    };
  aux(Occupied(player), board, n, []);
};

let possible_moves = (board: board) : list(int) =>
  board
  |> List.mapi((i: int, c: cell) => (i, c))
  |> List.filter(((_, c)) => c == Empty)
  |> List.map(((i, _)) => i);