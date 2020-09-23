open Jest;
open Expect;
describe("LoanCapacity", () => {
  let people1 =
    People.make(
      ~name="Mathieu",
      ~firstname="",
      ~income=100.,
      ~hasMoreThan60Years=false,
      ~credits=None,
    );

  let people2 =
    People.make(
      ~name="Mathieu",
      ~firstname="",
      ~income=100.,
      ~hasMoreThan60Years=false,
      ~credits=None,
    );

  let indebted =
    People.make(
      ~name="Mathieu",
      ~firstname="",
      ~income=100.,
      ~hasMoreThan60Years=false,
      ~credits=Some([|20.|]),
    );
  let indebted2 =
    People.make(
      ~name="Mathieu",
      ~firstname="",
      ~income=100.,
      ~hasMoreThan60Years=false,
      ~credits=Some([|50.|]),
    );
  ();
  test("Single with full capacity", () => {
    people1
    |> Household.make(_)
    |> LoanCapacity.compute(~rate=1.4)
    |> expect
    |> toMatchSnapshot
  });
  test("Single indebted", () => {
    indebted
    |> Household.make(_)
    |> LoanCapacity.compute(~rate=1.4)
    |> expect
    |> toMatchSnapshot
  });
  test("Single too much indebted", () => {
    indebted2
    |> Household.make(_)
    |> LoanCapacity.compute(~rate=1.4)
    |> expect
    |> toMatchSnapshot
  });
  test("Couple with full capacity", () => {
    Household.make(~people2, people1)
    |> LoanCapacity.compute(~rate=1.4)
    |> expect
    |> toMatchSnapshot
  });
  test("Couple indebted", () => {
    Household.make(~people2, indebted)
    |> LoanCapacity.compute(~rate=1.4)
    |> expect
    |> toMatchSnapshot
  });
  test("Couple to much indebted", () => {
    Household.make(~people2=indebted, indebted2)
    |> LoanCapacity.compute(~rate=1.4)
    |> expect
    |> toMatchSnapshot
  });
});
