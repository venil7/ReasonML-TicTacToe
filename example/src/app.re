open ReasonTttoe.Tttoe;

/* open State; */
type self =
  ReasonReact.self(State.state, ReasonReact.noRetainedProps, State.action);

let component = ReasonReact.reducerComponent("App");

let handleMove = (self: self, move: int) =>
  if (! self.state.game_over) {
    Js.Console.log("clicked " ++ string_of_int(move));
    self.send(PlayerMove(move));
  };

let make = _children => {
  ...component,
  reducer: State.reducer,
  initialState: () => (
    {board: new_board(3), cpu: 0, human: 0, draws: 0, game_over: false}: State.state
  ),
  render: self => {
    let onMove = handleMove(self);
    <div className="App">
      <Board onMove board=self.state.board />
      <Stats stats=self.state onNewGame=(() => self.send(State.NewGame)) />
    </div>;
  }
};