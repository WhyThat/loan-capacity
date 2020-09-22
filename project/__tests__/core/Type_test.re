open Jest;
open Expect;

describe("Initial test", () => {
  test("1 == 1", () => {
    expect(1) |> toEqual(1)
  })
});
