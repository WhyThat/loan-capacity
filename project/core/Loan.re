open Type;
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
type t = {
  duration,
  monthlyPayment: Amount.t,
  rate: float,
  total: Amount.t,
};

let make = (~duration, ~monthlyPayment, ~rate, ~total) => {
  duration,
  monthlyPayment,
  rate,
  total,
};

let view: t => view =
  t => {
    let {duration, monthlyPayment, rate, total} = t;
    {duration, monthlyPayment, rate, total};
  };
