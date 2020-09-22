module People: {
  type age =
    | More60Year
    | Less60Years;
  type t;
  type view = {
    name: string,
    firstname: string,
    age,
    income: float,
    credits: option(array(float)),
  };

  let make:
    (
      ~name: string,
      ~firstname: string,
      ~income: float,
      ~hasMoreThan60Years: bool,
      ~credits: option(array(float))
    ) =>
    t;
  let view: t => view;
} = {
  type age =
    | More60Year
    | Less60Years;
  type view = {
    name: string,
    firstname: string,
    age,
    income: float,
    credits: option(array(float)),
  };

  type t = {
    name: string,
    firstname: string,
    age,
    income: float,
    credits: option(array(float)),
  };

  let make = (~name, ~firstname, ~income, ~hasMoreThan60Years, ~credits) => {
    name,
    firstname,
    income,
    age: hasMoreThan60Years ? More60Year : Less60Years,
    credits,
  };

  let view: t => view =
    t => {
      let {name, firstname, age, income, credits} = t;
      {name, firstname, age, income, credits};
    };
};

module Household: {
  type t;
  type view =
    | Single(People.t)
    | Couple(People.t, People.t);
  let make: (~people2: People.t=?, People.t) => t;
  let view: t => view;
} = {
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
};

module Indebtedness: {
  type indebtedness = {
    sumCredit: float,
    rate: float,
  };
  type t;
  type view =
    | More33(indebtedness)
    | Less33(indebtedness);

  let view: t => view;

  let make: (~credits: array(float)=?, float) => t;
} = {
  type indebtedness = {
    sumCredit: float,
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
        Relude.Array.foldLeft((acc, credit) => credit +. acc, 0., credits);
      let indebtednessRate = sumCredit *. 100. /. revenu;
      indebtednessRate >= 33.
        ? More33({rate: indebtednessRate, sumCredit})
        : Less33({rate: indebtednessRate, sumCredit});
    | None => Less33({rate: 0., sumCredit: 0.})
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
    monthlyPayment: float,
    rate: float,
    total: float,
  };
  let make:
    (
      ~duration: duration,
      ~monthlyPayment: float,
      ~rate: float,
      ~total: float
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
    monthlyPayment: float,
    rate: float,
    total: float,
  };
  type t = {
    duration,
    monthlyPayment: float,
    rate: float,
    total: float,
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
