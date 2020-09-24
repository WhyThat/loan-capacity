type people = {
  name: string,
  income: int,
  onIncomeChange: int => unit,
};

[@react.component]
let make = (~title, ~income, ~onIncomeChange) => {
  <Container title={"Revenus " ++ title}>
    <Field.Number
      value={income |> Relude.Int.toString}
      onChange=onIncomeChange
      label="Revenus mensuel"
    />
  </Container>;
};
