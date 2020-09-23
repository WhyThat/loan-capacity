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
