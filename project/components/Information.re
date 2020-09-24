[@react.component]
let make =
    (~name, ~firstname, ~age, ~onNameChange, ~onAgeChange, ~onFirstnameChange) => {
  let handleOnChange = (fn, value) => fn(value);

  <Container title="Informations">
    <Field.Text
      value=name
      onChange={handleOnChange(onNameChange)}
      label={j| Prénom |j}
    />
    <Field.Text
      value=firstname
      onChange={handleOnChange(onFirstnameChange)}
      label={j| Nom |j}
    />
    <label className=[%tw "inline-flex items-center"]>
      <input
        onChange={_ => onAgeChange(People.Less60Years)}
        checked={
          switch (age) {
          | People.Less60Years => true
          | People.More60Year => false
          }
        }
        type_="radio"
        className=[%tw "form-radio"]
        name="age"
        value="lessThan60"
      />
      <span className=[%tw "ml-2"]>
        {j| Inférieur à 60 ans |j}->React.string
      </span>
    </label>
    <label className=[%tw "inline-flex items-center ml-6"]>
      <input
        checked={
          switch (age) {
          | People.Less60Years => false
          | People.More60Year => true
          }
        }
        onChange={_ => onAgeChange(People.More60Year)}
        type_="radio"
        className=[%tw "form-radio "]
        name="age"
        value="moreThan60"
      />
      <span className=[%tw "ml-2"]>
        {j| Supérieur à 60 ans |j}->React.string
      </span>
    </label>
  </Container>;
};
