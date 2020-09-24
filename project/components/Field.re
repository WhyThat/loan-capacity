let handleOnChange = (onChange, ev) => {
  let value = ReactEvent.Form.target(ev)##value;
  onChange(value);
};
let handleOnBlur = (onBlur, _ev) => {
  onBlur();
};

module Text = {
  [@react.component]
  let make = (~label, ~value, ~onChange) => {
    <label className=[%tw "block"]>
      <span className=[%tw "text-gray-700"]> label->React.string </span>
      <input
        value
        onChange={handleOnChange(onChange)}
        className=[%tw "form-input mt-1 block w-full"]
        placeholder=label
      />
    </label>;
  };
};
module Number = {
  [@react.component]
  let make = (~label, ~onChange, ~value) => {
    <label className=Cn.([%tw "inline-block mr-2"])>
      <span className=[%tw "text-gray-700"]> label->React.string </span>
      <input
        onChange={handleOnChange(onChange)}
        min="0"
        type_="number"
        value
        className=[%tw "form-input mt-1 block w-full"]
        placeholder=label
      />
    </label>;
  };
};
