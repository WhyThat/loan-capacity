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

let durationToAmount = duration =>
  (
    switch (duration) {
    | FifteenYears => 15.
    | TwentyYears => 20.
    | TwentyFiveYears => 25.
    }
  )
  |> Amount.make;
let make = (~capacityByYear, ~rate, ~monthlyPayment, duration) => {
  duration,
  monthlyPayment,
  rate,
  total: duration |> durationToAmount |> Amount.sum(capacityByYear),
};

let view: t => view =
  t => {
    let {duration, monthlyPayment, rate, total} = t;
    {duration, monthlyPayment, rate, total};
  };
