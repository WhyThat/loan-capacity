open Type;
open Relude.Option.Infix;

type capacity = Relude.Result.t(array(Loan.t), string);
let compute: (~rate: float, Household.t) => capacity =
  (~rate, household) => {
    switch (household |> Indebtedness.makeFromHousehold |> Indebtedness.view) {
    | More33(_) =>
      Relude.Result.Error(
        "Vous avez plus de 33% d'endettement, vous ne pouvez pas
                        emprunter pou le moment",
      )
    | indebtedness =>
      let householdIncome =
        Household.getIncome(household) |> Income.view |> Amount.make;

      let sumCredit =
        indebtedness |> Indebtedness.getSumCredit |> Credit.view |> Amount.make;
      let maxCapacity =
        Amount.sum(householdIncome, Indebtedness.maxIndebtedness);
      let capacityByMonth = Amount.div(maxCapacity, sumCredit) |? maxCapacity;

      let amountRate = 1. -. rate /. 100. |> Amount.make;
      let capacityByYear =
        capacityByMonth
        |> Amount.sum(amountRate)
        |> Amount.sum(Amount.make(12.));

      let createLoan =
        Loan.make(~monthlyPayment=capacityByMonth, ~rate, ~capacityByYear);
      [|Loan.FifteenYears, Loan.TwentyYears, Loan.TwentyFiveYears|]
      |> Relude.Array.map(createLoan)
      |> Relude.Result.ok;
    };
  };
