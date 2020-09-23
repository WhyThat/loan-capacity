module type Float = {
  type t;
  type view = float;
  let make: float => t;
  let add: (t, t) => t;
  let sum: (t, t) => t;
  let div: (t, t) => option(t);
  let view: t => view;
};

module Float: Float = {
  type t = float;
  type view = float;
  let make: float => t = t => t;
  let add: (t, t) => t = (amount1, amount2) => amount1 +. amount2;
  let sum: (t, t) => t = (amount1, amount2) => amount1 *. amount2;
  let div: (t, t) => option(t) =
    (amount1, amount2) => amount2 != 0. ? Some(amount1 /. amount2) : None;
  let view = m => m;
};

module Amount: Float = {
  include Float;
  let make: float => t =
    amount => amount > 0. ? Float.make(amount) : Float.make(0.);
};

module Rate: Float = {
  include Float;
  let make = rate => Float.make(rate /. 100.);
};
module Income: Float = {
  include Amount;
};

module Credit: Float = {
  include Amount;
};

module Indebtedness: {
  type indebtedness = {
    sumCredit: Credit.t,
    rate: float,
  };
  type t;
  type view =
    | More33(indebtedness)
    | Less33(indebtedness);

  let view: t => view;

  let make: (~credits: array(Credit.t)=?, float) => t;
} = {
  type indebtedness = {
    sumCredit: Credit.t,
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
          (acc, credit) => Credit.add(credit, acc),
          Credit.make(0.),
          credits,
        );
      let indebtednessRate = Credit.view(sumCredit) *. 100. /. revenu;
      indebtednessRate >= 33.
        ? More33({rate: indebtednessRate, sumCredit})
        : Less33({rate: indebtednessRate, sumCredit});
    | None => Less33({rate: 0., sumCredit: Credit.make(0.)})
    };
  };
};

module Loan: {
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
} = {
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
};
