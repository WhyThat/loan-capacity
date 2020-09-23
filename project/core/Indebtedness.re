let maxIndebtedness = Type.Amount.make(0.33333);
type indebtedness = {
  sumCredit: Type.Credit.t,
  rate: float,
};
type view =
  | More33(indebtedness)
  | Less33(indebtedness);

type t =
  | More33(indebtedness)
  | Less33(indebtedness);

let view: t => view =
  t =>
    switch (t) {
    | More33(indebtedness) => More33(indebtedness)
    | Less33(indebtedness) => Less33(indebtedness)
    };

let make = (~credits=?, revenu): t => {
  switch (credits) {
  | Some(credits) =>
    let sumCredit =
      Relude.Array.foldLeft(
        (acc, credit) => Type.Credit.add(credit, acc),
        Type.Credit.make(0.),
        credits,
      );
    let indebtednessRate =
      Type.Credit.view(sumCredit) *. 100. /. Type.Income.view(revenu);
    indebtednessRate >= 33.
      ? More33({rate: indebtednessRate, sumCredit})
      : Less33({rate: indebtednessRate, sumCredit});
  | None => Less33({rate: 0., sumCredit: Type.Credit.make(0.)})
  };
};

let makeFromPeople = people => {
  switch (people->People.view) {
  | {credits: None} => Less33({rate: 0., sumCredit: Type.Credit.make(0.)})
  | {income, credits} => make(~credits?, income)
  };
};

let makeFromHousehold = (household): t => {
  switch (household->Household.view) {
  | Couple(first, second) =>
    let (income1, charge1) =
      switch (first->People.view) {
      | {income, credits} => (income, credits)
      };

    let (income2, charge2) =
      switch (second->People.view) {
      | {income, credits} => (income, credits)
      };

    let householdIncome = Type.Income.add(income1, income2);
    switch (charge1, charge2) {
    | (Some(charges1), Some(charges2)) =>
      make(householdIncome, ~credits=Relude.Array.concat(charges1, charges2))
    | (Some(charges), None)
    | (None, Some(charges)) => make(householdIncome, ~credits=charges)
    | (None, None) => make(householdIncome)
    };
  | Single(first) => makeFromPeople(first)
  };
};

let getRate = (t: view) =>
  switch (t) {
  | More33({rate})
  | Less33({rate}) => rate
  };
let getSumCredit = (t: view) =>
  switch (t) {
  | More33({sumCredit})
  | Less33({sumCredit}) => sumCredit
  };
