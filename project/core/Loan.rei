open Type;
type t;
type duration =
  | FifteenYears
  | TwentyYears
  | TwentyFiveYears;
type view = {
  duration,
  monthlyPayment: Amount.t,
  rate: float,
  total: Amount.t,
};
let make:
  (
    ~capacityByYear: Amount.t,
    ~rate: float,
    ~monthlyPayment: Amount.t,
    duration
  ) =>
  t;
let view: t => view;
