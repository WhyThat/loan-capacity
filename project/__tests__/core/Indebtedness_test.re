open Type;
open Jest;
open Expect;
describe("Indebtedness", () => {
  test("Without any credits", () => {
    Indebtedness.make(Income.make(100.))
    |> Indebtedness.view
    |> expect
    |> toEqual(Indebtedness.Less33({rate: 0., sumCredit: Credit.make(0.)}))
  });
  test("1 credit under 33.", () => {
    Indebtedness.make(~credits=[|Credit.make(10.)|], Income.make(100.))
    |> Indebtedness.view
    |> expect
    |> toEqual(
         Indebtedness.Less33({rate: 10., sumCredit: Credit.make(10.)}),
       )
  });

  test("multiple credits under 33.", () => {
    Indebtedness.make(
      ~credits=[|Credit.make(10.), Credit.make(10.)|],
      Income.make(100.),
    )
    |> Indebtedness.view
    |> expect
    |> toEqual(
         Indebtedness.Less33({rate: 20., sumCredit: Credit.make(20.)}),
       )
  });

  test("one credit equals 33.", () => {
    Indebtedness.make(~credits=[|Credit.make(33.)|], Income.make(100.))
    |> Indebtedness.view
    |> expect
    |> toEqual(
         Indebtedness.More33({rate: 33., sumCredit: Credit.make(33.)}),
       )
  });
  test("one credit above 33.", () => {
    Indebtedness.make(~credits=[|Credit.make(34.)|], Income.make(100.))
    |> Indebtedness.view
    |> expect
    |> toEqual(
         Indebtedness.More33({rate: 34., sumCredit: Credit.make(34.)}),
       )
  });
  test("multiple credits above 33.", () => {
    Indebtedness.make(
      ~credits=[|Credit.make(20.), Credit.make(30.)|],
      Income.make(100.),
    )
    |> Indebtedness.view
    |> expect
    |> toEqual(
         Indebtedness.More33({rate: 50., sumCredit: Credit.make(50.)}),
       )
  });
});
