type people;

module People = {
  type age =
    | More60Year
    | Less60Years;
  type t = {
    name: string,
    firstname: string,
    age,
    income: float,
    credits: option(array(float)),
  };
};

module Household = {
  type t =
    | Single(People.t)
    | Couple(People.t, People.t);
};

module Indebtedness = {
  type indebtedness = {
    sumCredit: float,
    rate: float,
  };

  type t =
    | More33(indebtedness)
    | Less33(indebtedness);
};

module Loan = {
  type duration =
    | FifteenYears
    | TwentyYears
    | TwentyFiveYears;
  type t = {
    duration,
    monthlyPayment: float,
    rate: float,
    total: float,
  };
};
