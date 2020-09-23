type age =
  | More60Year
  | Less60Years;
type t;

type view = {
  name: string,
  firstname: string,
  age,
  income: Type.Income.t,
  credits: option(array(Type.Credit.t)),
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
module Setter: {
  let setName: (string, t) => t;
  let setFirstname: (string, t) => t;
  let setAge: (age, t) => t;
  let setIncome: (float, t) => t;
  let setCredits: (option(array(float)), t) => t;
  let removeCreditAt: (int, t) => t;
  let updateCreditAt: (int, float, t) => t;
};
module Getter: {
  let getName: t => string;
  let getFirstname: t => string;
  let getAge: t => age;
  let getIncome: t => Type.Income.t;
  let getIncomeInInt: t => int;
  let getCredits: t => array(float);
};
