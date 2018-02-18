let i2s = string_of_int;

let toElement = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Stats");

let make = (~stats: State.state, ~onNewGame, _children) => {
  ...component,
  render: _self => {
    let game = stats.game_over ? "Game Over" : "Ongoing";
    let button =
      stats.game_over ?
        <button onClick=(_evt => onNewGame())>
          ("New Game" |> toElement)
        </button> :
        toElement("");
    <ul className="stats">
      <li className="header"> ("Game Stats:" |> toElement) </li>
      <li className="game"> (game |> toElement) </li>
      <li> ("CPU: " ++ i2s(stats.cpu) |> toElement) </li>
      <li> ("Human: " ++ i2s(stats.human) |> toElement) </li>
      <li> ("Draws: " ++ i2s(stats.draws) |> toElement) </li>
      <li> button </li>
    </ul>;
  }
};