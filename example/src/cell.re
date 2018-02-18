let component = ReasonReact.statelessComponent("Cell");

open ReasonTttoe.Tttoe;

let cellToClassName = (cell: cell) =>
  switch cell {
  | Empty => ""
  | Occupied(X) => "x"
  | Occupied(O) => "o"
  };

let make = (~cell: cell, _children) => {
  ...component,
  render: _self => {
    let className = "cell " ++ cellToClassName(cell);
    <div className />;
  }
};