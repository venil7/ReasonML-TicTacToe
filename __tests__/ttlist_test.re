open Jest;

open Ttlist;

open Expect;

describe("Take", () => {
  test("take 2", () =>
    expect(take(2, [1, 2, 3])) |> toEqual([1, 2])
  );
  test("take more", () =>
    expect(take(4, [1, 2, 3])) |> toEqual([1, 2, 3])
  );
  test("take zero", () =>
    expect(take(0, [1, 2, 3])) |> toEqual([])
  );
  test("take negative", () =>
    expect(take(-1, [1, 2, 3])) |> toEqual([])
  );
});

describe("Drop", () => {
  test("drop 2", () =>
    expect(drop(2, [1, 2, 3])) |> toEqual([3])
  );
  test("drop more", () =>
    expect(drop(4, [1, 2, 3])) |> toEqual([])
  );
  test("drop zero", () =>
    expect(drop(0, [1, 2, 3])) |> toEqual([1, 2, 3])
  );
  test("drop negative", () =>
    expect(drop(-1, [1, 2, 3])) |> toEqual([1, 2, 3])
  );
});

describe("Transpose", () => {
  let matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
  let matrix' = [[1, 4, 7], [2, 5, 8], [3, 6, 9]];
  test("transpose", () =>
    expect(transpose(matrix)) |> toEqual(matrix')
  );
});

describe("Chunks Of", () => {
  let list = [1, 2, 3, 4, 5, 6, 7, 8, 9];
  let chunks = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
  test("chunks of 3", () =>
    expect(chunks_of(3, list)) |> toEqual(chunks)
  );
});