open Ttlist;

type player =
  | X
  | O;

type cell =
  | Occupied(player)
  | Empty;

type board = {
  dim: int,
  cells: list(cell)
};

type state = {
  possible_moves: list(int),
  winner: option(player)
};

type eval = {
  score: int,
  move: option(int)
};

let new_board = (dim: int) : board => {
  let rec aux = (n: int) => n > 0 ? [Empty, ...aux(n - 1)] : [];
  let cells = aux(dim * dim);
  {dim, cells};
};

exception InvalidMove(int);

let make_move = (player: player, n: int, board: board) : board => {
  let cells =
    board.cells
    |> List.mapi((i: int, cell: cell) =>
         switch cell {
         | Empty when i == n => Occupied(player)
         | _ when i == n => raise(InvalidMove(n))
         | c => c
         }
       );
  {...board, cells};
};

let possible_moves = (board: board) : list(int) =>
  board.cells
  |> List.mapi((i: int, c: cell) => (i, c))
  |> List.filter(((_, c)) => c == Empty)
  |> List.map(((i, _)) => i);

let occupied_cell = (player: player, cell: cell) : bool =>
  switch cell {
  | Occupied(p) => p == player
  | _ => false
  };

let occupied_row = (player: player, row: list(cell)) : bool =>
  row |> List.for_all(occupied_cell(player));

let has_winner = (player: player, board: board) : bool => {
  let horizontals = board.cells |> chunks_of(board.dim);
  let verticals = horizontals |> transpose;
  let diag1 = horizontals |> diag_left;
  let diag2 = horizontals |> diag_right;
  let exists = List.exists(occupied_row(player));
  exists(horizontals) || exists(verticals) || exists([diag1, diag2]);
};

let winner = (board: board) : option(player) =>
  if (has_winner(X, board)) {
    Some(X);
  } else if (has_winner(O, board)) {
    Some(O);
  } else {
    None;
  };

let get_state = (board: board) : state => {
  possible_moves: possible_moves(board),
  winner: winner(board)
};

let game_over = (board: board) : bool =>
  switch (board |> get_state) {
  | {winner: Some(X), _}
  | {winner: Some(O), _}
  | {possible_moves: [], _} => true
  | _ => false
  };

let opposite = (player: player) : player =>
  switch player {
  | X => O
  | O => X
  };

let eval_sort = (e1: eval, e2: eval) : int => e1.score - e2.score;

let best_for = (player: player, evals: list(eval)) : eval =>
  List.(
    switch player {
    | O => evals |> sort(eval_sort) |> hd
    | X => evals |> sort(eval_sort) |> rev |> hd
    }
  );

let rec minimax = (board: board, player: player, depth: int) : eval => {
  let evaluate_move = (move: int) : eval => {
    let {score} =
      minimax(make_move(player, move, board), opposite(player), depth + 1);
    {score, move: Some(move)};
  };
  switch (get_state(board)) {
  | {winner: Some(O), _} => {score: depth - 10, move: None}
  | {winner: Some(X), _} => {score: 10 - depth, move: None}
  | {winner: None, possible_moves: []} => {score: depth - 10, move: None}
  | {winner: None, possible_moves: moves} =>
    moves |> List.map(evaluate_move) |> best_for(player)
  };
};

let cpu = (board: board) : board => {
  let eval = minimax(board, O, 0);
  switch eval.move {
  | Some(move) => board |> make_move(O, move)
  | _ => board
  };
};