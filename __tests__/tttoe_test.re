open Jest;

open Tttoe;

open Expect;

describe("Board", () => {
  /* new board */
  test("new_board x3", () =>
    expect(new_board(3).cells)
    |> toEqual(Array.to_list(Array.init(9, _x => Empty)))
  );
  test("new_board x4", () =>
    expect(new_board(4).cells)
    |> toEqual(Array.to_list(Array.init(16, _x => Empty)))
  );
  /* make move */
  test("make_move (valid move, left edge)", () => {
    let board = new_board(2) |> make_move(X, 0);
    expect(board.cells) |> toEqual([Occupied(X), Empty, Empty, Empty]);
  });
  test("make_move (valid move, middle)", () => {
    let board = new_board(2) |> make_move(X, 2);
    expect(board.cells) |> toEqual([Empty, Empty, Occupied(X), Empty]);
  });
  test("make_move (valid move, middle)", () => {
    let board = new_board(2) |> make_move(X, 3);
    expect(board.cells) |> toEqual([Empty, Empty, Empty, Occupied(X)]);
  });
  test("make_move (invalid move, occupied)", () => {
    let board = new_board(2) |> make_move(X, 2);
    expect(() =>
      make_move(X, 2, board)
    ) |> toThrow;
  });
  /* possible moves */
  test("possible_moves (all)", () =>
    expect(possible_moves(new_board(2))) |> toEqual([0, 1, 2, 3])
  );
  test("possible_moves (some)", () => {
    let board = new_board(2) |> make_move(X, 1) |> make_move(O, 2);
    expect(possible_moves(board)) |> toEqual([0, 3]);
  });
  /* occupied cell */
  test("occupied_cell X", () =>
    expect(occupied_cell(X, Occupied(X))) |> toEqual(true)
  );
  test("occupied_cell O", () =>
    expect(occupied_cell(O, Occupied(O))) |> toEqual(true)
  );
  test("occupied_cell empty", () =>
    expect(occupied_cell(X, Empty)) |> toEqual(false)
  );
  /* occupied row */
  test("occupied_row (empty)", () =>
    expect(occupied_row(X, [Empty, Empty, Empty])) |> toEqual(false)
  );
  test("occupied_row (partial)", () =>
    expect(occupied_row(X, [Empty, Occupied(X), Empty])) |> toEqual(false)
  );
  test("occupied_row (full)", () =>
    expect(occupied_row(X, [Occupied(X), Occupied(X), Occupied(X)]))
    |> toEqual(true)
  );
  /* has winner */
  test("has_winner (no)", () => {
    let board = new_board(2) |> make_move(X, 0) |> make_move(O, 3);
    expect(has_winner(X, board)) |> toEqual(false);
  });
  test("has_winner (vert)", () => {
    let board = new_board(2) |> make_move(X, 0) |> make_move(X, 1);
    expect(has_winner(X, board)) |> toEqual(true);
  });
  test("has_winner (hor)", () => {
    let board = new_board(2) |> make_move(X, 0) |> make_move(X, 2);
    expect(has_winner(X, board)) |> toEqual(true);
  });
  test("has_winner (diag left)", () => {
    let board = new_board(2) |> make_move(X, 0) |> make_move(X, 3);
    expect(has_winner(X, board)) |> toEqual(true);
  });
  test("has_winner (diag right)", () => {
    let board = new_board(2) |> make_move(X, 1) |> make_move(X, 2);
    expect(has_winner(X, board)) |> toEqual(true);
  });
  /* winner */
  test("winner (Some(X))", () => {
    let board = new_board(2) |> make_move(X, 1) |> make_move(X, 2);
    expect(winner(board)) |> toEqual(Some(X));
  });
  test("winner (None)", () => {
    let board = new_board(2);
    expect(winner(board)) |> toEqual(None);
  });
  /* game over */
  test("game_over (Winner X)", () => {
    let board = new_board(2) |> make_move(X, 1) |> make_move(X, 2);
    expect(game_over(board)) |> toEqual(true);
  });
  /* opposite */
  test("opposite (X->O)", () =>
    expect(opposite(X)) |> toEqual(O)
  );
  test("opposite (O->X)", () =>
    expect(opposite(O)) |> toEqual(X)
  );
});

describe("Eval", () => {
  let evals: list(eval) = [
    {score: 9, move: None},
    {score: 1, move: None},
    {score: 5, move: None},
    {score: (-4), move: None}
  ];
  test("best_for O", () =>
    expect(best_for(O, evals)) |> toEqual({score: (-4), move: None})
  );
  test("best_for X", () =>
    expect(best_for(X, evals)) |> toEqual({score: 9, move: None})
  );
});