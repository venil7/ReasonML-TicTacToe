let rec take = (n: int, xs: list('a)) =>
  n > 0 ?
    switch xs {
    | [x, ...xs] => [x, ...take(n - 1, xs)]
    | [] => []
    } :
    [];

let rec drop = (n: int, xs: list('a)) =>
  n > 0 ?
    switch xs {
    | [_, ...xs] => drop(n - 1, xs)
    | [] => []
    } :
    xs;

let rec transpose = list =>
  switch list {
  | [] => []
  | [[], ...xss] => transpose(xss)
  | [[x, ...xs], ...xss] => [
      [x, ...List.map(List.hd, xss)],
      ...transpose([xs, ...List.map(List.tl, xss)])
    ]
  };

let rec chunks_of = (size: int, xs: list('a)) : list(list('a)) =>
  switch xs {
  | [] => []
  | _ => [take(size, xs), ...chunks_of(size, drop(size, xs))]
  };