[@react.component]
let make = (~title, ~children) => {
  <div className=[%tw "mt-4"]>
    <span className=[%tw "text-gray-700 text-xl"]> title->React.string </span>
    <div className=[%tw "mt-2"]> children </div>
  </div>;
};
