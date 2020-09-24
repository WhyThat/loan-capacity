open Relude.Option.Infix;
[@react.component]
let make = () => {
  <div>
    <div className=[%tw "container mx-auto p-2"]>
      <div className=[%tw "mt-2"]>
        <Container title="Situation familiale">
          <label className=[%tw "inline-flex items-center"]>
            <input
              onChange={_ => ()}
              type_="radio"
              className=[%tw "form-radio"]
              name="familalStatus"
            />
            <span className=[%tw "ml-2"]>
              {j|Célibataire|j}->React.string
            </span>
          </label>
          <label className=[%tw "inline-flex items-center ml-6"]>
            <input
              onChange={_ => ()}
              type_="radio"
              className=[%tw "form-radio "]
              name="familalStatus"
            />
            <span className=[%tw "ml-2"]> "En couple"->React.string </span>
          </label>
        </Container>
      </div>
      <Information
        name=""
        firstname=""
        age=People.More60Year
        onFirstnameChange={_ => ()}
        onNameChange={_ => ()}
        onAgeChange={_ => ()}
      />
      <Income title="" onIncomeChange={_ => ()} income=0 />
      <Credit
        addCredit={_ => ()}
        removeCredit={_ => ()}
        onMonthChange={(_, _) => ()}
        onAmountChange={(_, _) => ()}
        credits=[||]
      />
      <div
        className=[%tw "flex mx-auto mt-10 mb-5 border-t-2 border-gray-500"]>
        <button
          className=[%tw
            "bg-transparent font-semibold hover:bg-green-500
           text-green-700 border-green-500 hover:text-white py-2 px-4 border
           hover:border-transparent rounded mt-5 mx-auto"
          ]>
          {j|Calculer votre capacité d'emprunt |j}->React.string
        </button>
      </div>
    </div>
  </div>;
};
