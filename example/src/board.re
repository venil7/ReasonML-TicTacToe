[%bs.raw {|require('./board.css')|}];

let component = ReasonReact.statelessComponent("Board");

open ReasonTttoe.Tttoe;

let cellToElement = (i: int, cell: cell) =>
  <Cell cell key=(string_of_int(i)) />;

let make = (~board: board, _children) => {
  ...component,
  render: _self => {
    let className = "board board-" ++ string_of_int(board.dim);
    <div className>
      (
        board.cells
        |> List.mapi(cellToElement)
        |> Array.of_list
        |> ReasonReact.arrayToElement
      )
    </div>;
  }
};