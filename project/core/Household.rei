type t;
type view =
  | Single(People.t)
  | Couple(People.t, People.t);
let make: (~people2: People.t=?, People.t) => t;
let view: t => view;
let getIncome: t => Type.Income.t;
