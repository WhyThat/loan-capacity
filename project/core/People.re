type age =
  | More60Year
  | Less60Years;

type view = {
  name: string,
  firstname: string,
  age,
  income: Type.Income.t,
  credits: option(array(Type.Credit.t)),
};

type t = {
  name: option(string),
  firstname: option(string),
  income: option(Type.Income.t),
  credits: option(array(Type.Credit.t)),
  age: option(age),
};

open Relude.Option.Infix;
module Getter = {
  let getName = t => t.name |? "";
  let getFirstname = t => t.firstname |? "";
  let getAge = t => t.age |? Less60Years;
  let getIncome = t => t.income |? Type.Income.make(0.);
  let getIncomeInInt = t =>
    t.income <#> Type.Income.view <#> Relude.Float.toInt |? 0;
  let getCredits = t =>
    t.credits <#> Relude.Array.map(Type.Credit.view) |? [||];
};

module Setter = {
  let setName = (name, t) => {...t, name: Some(name)};
  let setFirstname = (firstname, t) => {...t, firstname: Some(firstname)};
  let setAge = (age, t) => {...t, age: Some(age)};
  let setIncome = (income, t) => {
    ...t,
    income: Type.Income.make(income) |> Relude.Option.pure,
  };
  let setAgeFromBool = (hasMoreThan60Years, t) => {
    ...t,
    age: Some(hasMoreThan60Years ? More60Year : Less60Years),
  };

  let setCredits = (credits, t) => {
    ...t,
    credits: credits <#> Relude.Array.map(Type.Credit.make),
  };
  let updateCreditAt = (index, amount, t) => {
    ...t,
    credits:
      t.credits
      <#> Relude.Array.updateAt(index, _ => Type.Credit.make(amount)),
  };
  let removeCreditAt = (index, t) => {
    ...t,
    credits: t.credits <#> Relude.Array.removeAt(index),
  };
};

let empty = () => {
  name: None,
  firstname: None,
  age: None,
  income: None,
  credits: None,
};

let make =
    (
      ~name: string,
      ~firstname: string,
      ~income: float,
      ~hasMoreThan60Years: bool,
      ~credits: option(array(float)),
    ) => {
  empty()
  |> Setter.setName(name)
  |> Setter.setFirstname(firstname)
  |> Setter.setIncome(income)
  |> Setter.setAgeFromBool(hasMoreThan60Years)
  |> Setter.setCredits(credits);
};

let view: t => view =
  t => {
    let {name, firstname, age, income, credits} = t;
    {
      name: name |? "",
      firstname: firstname |? "",
      age: age |? Less60Years,
      income: income |? Type.Income.make(0.),
      credits,
    };
  };
