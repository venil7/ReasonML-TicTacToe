open Jest;

open Tttoe;

describe("Board", () => {
  open Expect;
  test("new_board x3", () =>
    expect(new_board(3)) |> toEqual(Array.to_list(Array.init(9, _x => Empty)))
  );
  test("new_board x4", () =>
    expect(new_board(4)) |> toEqual(Array.to_list(Array.init(16, _x => Empty)))
  );
  test("make_move (valid move, left edge)", () =>
    expect(make_move(X, new_board(2), 0))
    |> toEqual([Occupied(X), Empty, Empty, Empty])
  );
  test("make_move (valid move, middle)", () =>
    expect(make_move(X, new_board(2), 2))
    |> toEqual([Empty, Empty, Occupied(X), Empty])
  );
  test("make_move (valid move, middle)", () =>
    expect(make_move(X, new_board(2), 3))
    |> toEqual([Empty, Empty, Empty, Occupied(X)])
  );
  test("make_move (invalid move, occupied)", () =>
    expect(() =>
      make_move(X, [Empty, Empty, Occupied(X), Empty], 2)
    )
    |> toThrow
  );
  test("possible_moves (all)", () =>
    expect(possible_moves(new_board(2))) |> toEqual([0, 1, 2, 3])
  );
  test("possible_moves (some)", () =>
    expect(possible_moves([Empty, Occupied(X), Occupied(O), Empty]))
    |> toEqual([0, 3])
  );
});