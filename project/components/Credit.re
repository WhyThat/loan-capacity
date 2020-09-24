module Line = {
  type kind =
    | Add
    | Remove;
  [@react.component]
  let make =
      (~kind, ~amount, ~month, ~onClick, ~onMonthChange, ~onAmountChange) => {
    let (buttonClass, buttonLabel) =
      switch (kind) {
      | Remove => ([%tw "hover:bg-red-500 text-red-700 border-red-500"], "-")
      | Add => (
          [%tw "hover:bg-green-500 text-green-700 border-green-500"],
          "+",
        )
      };
    let onClick = _ => {
      Js.log("onclick line");
      onClick();
    };
    <div>
      <Field.Number
        value={amount |> Relude.Int.toString}
        onChange=onAmountChange
        label={j| Montant restant |j}
      />
      <Field.Number
        value={month |> Relude.Int.toString}
        onChange=onMonthChange
        label={j| Temps restant en mois |j}
      />
      <button
        onClick
        className=Cn.(
          [%tw
            "bg-transparent  font-semibold
            hover:text-white py-2 px-4 border
            hover:border-transparent rounded mt-2"
          ]
          ++ buttonClass
        )>
        buttonLabel->React.string
      </button>
    </div>;
  };
};

type state = (int, int);
type action =
  | UpdateAmount(string)
  | UpdateMonth(string);

let reducer = (action, state) => {
  switch (action) {
  | UpdateAmount(amount) =>
    let (_, month) = state;
    let amount = amount |> Relude.String.toInt |> Relude.Option.getOrElse(0);
    ReactUpdate.Update((amount, month));
  | UpdateMonth(month) =>
    let (amount, _) = state;
    let month = month |> Relude.String.toInt |> Relude.Option.getOrElse(0);
    ReactUpdate.Update((amount, month));
  };
};
[@react.component]
let make =
    (~credits, ~addCredit, ~removeCredit, ~onMonthChange, ~onAmountChange) => {
  let (state, send) = ReactUpdate.useReducer((0, 0), reducer);

  let handleAddCredit = () => {
    addCredit(state);
  };
  let (amount, month) = state;
  <Container title="Credit">
    <Line
      amount
      month
      onClick=handleAddCredit
      kind=Line.Add
      onMonthChange={value => UpdateMonth(value)->send}
      onAmountChange={value => UpdateAmount(value)->send}
    />
    {Relude.Array.mapWithIndex(
       ((amount, month), index) =>
         <Line
           kind=Line.Remove
           amount
           month
           onClick={() => removeCredit(index)}
           key={index |> Relude.Int.toString}
           onMonthChange={onMonthChange(index)}
           onAmountChange={onAmountChange(index)}
         />,
       credits,
     )
     |> React.array}
  </Container>;
};
