open ReasonTttoe.Tttoe;

type state = {
  board,
  cpu: int,
  human: int,
  draws: int,
  game_over: bool
};

type action =
  | PlayerMove(int)
  | NewGame;

let initialState = () : state => {
  board: new_board(3),
  cpu: 0,
  human: 0,
  draws: 0,
  game_over: false
};

let reducer = (action: action, state: state) =>
  switch action {
  | PlayerMove(move) =>
    let board = state.board |> make_move(X, move) |> cpu;
    if (game_over(board)) {
      let winner = winner(board);
      let game_over = true;
      switch winner {
      | Some(player) when player == X =>
        ReasonReact.Update({
          ...state,
          board,
          game_over,
          human: state.human + 1
        })
      | Some(player) when player == O =>
        ReasonReact.Update({...state, board, game_over, cpu: state.cpu + 1})
      | _ =>
        ReasonReact.Update({
          ...state,
          board,
          game_over,
          draws: state.draws + 1
        })
      };
    } else {
      ReasonReact.Update({...state, board});
    };
  | NewGame =>
    ReasonReact.Update({...state, board: new_board(3), game_over: false})
  };