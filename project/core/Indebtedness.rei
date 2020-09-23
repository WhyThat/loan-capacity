type indebtedness = {
  sumCredit: Type.Credit.t,
  rate: float,
};
type t;
type view =
  | More33(indebtedness)
  | Less33(indebtedness);

let view: t => view;

let make: (~credits: array(Type.Credit.t)=?, Type.Income.t) => t;
let makeFromHousehold: Household.t => t;

let getSumCredit: view => Type.Credit.t;
let getRate: view => float;

let maxIndebtedness: Type.Amount.t;
