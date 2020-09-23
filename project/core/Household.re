type view =
  | Single(People.t)
  | Couple(People.t, People.t);
type t =
  | Single(People.t)
  | Couple(People.t, People.t);

let make = (~people2=?, people1) => {
  switch (people2) {
  | Some(people2) => Couple(people1, people2)
  | None => Single(people1)
  };
};

let view: t => view =
  t => {
    switch (t) {
    | Couple(people1, people2) => Couple(people1, people2)
    | Single(people) => Single(people)
    };
  };

let getIncome = t => {
  switch (t) {
  | Single(people) => people |> People.Getter.getIncome
  | Couple(people1, people2) =>
    (people1 |> People.Getter.getIncome, people2 |> People.Getter.getIncome)
    |> Relude.Tuple.apply(Type.Income.add)
  };
};
