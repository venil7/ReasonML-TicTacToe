open ReasonTttoe.Tttoe;

type state = {
  board,
  wins: int,
  losses: int,
  draws: int
};

type action =
  | Move(int)
  | Draw;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  reducer: (_action: action, _state: state) => ReasonReact.NoUpdate,
  initialState: () => (
    {board: new_board(3), wins: 0, losses: 0, draws: 0}: state
  ),
  render: self => <div className="App"> <Board board=self.state.board /> </div>
};