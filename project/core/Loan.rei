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
    ~duration: duration,
    ~monthlyPayment: Amount.t,
    ~rate: float,
    ~total: Amount.t
  ) =>
  t;
let view: t => view;
