[%bs.raw {|require('./board.css')|}];

open ReasonTttoe.Tttoe;

type onMove = int => unit;

let cellToElement = (onMove: onMove, i: int, cell: cell) =>
  <Cell cell index=i key=(string_of_int(i)) onClick=(idx => onMove(idx)) />;

let component = ReasonReact.statelessComponent("Board");

let make = (~board: board, ~onMove: onMove, _children) => {
  ...component,
  render: _self => {
    let className = "board board-" ++ string_of_int(board.dim);
    <div className>
      (
        board.cells
        |> List.mapi(cellToElement(onMove))
        |> Array.of_list
        |> ReasonReact.arrayToElement
      )
    </div>;
  }
};