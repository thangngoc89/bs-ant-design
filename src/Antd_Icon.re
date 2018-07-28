let component = ReasonReact.statelessComponent("Icon");

let make =
    (
      ~type_: Antd_IconName.t,
      ~className=?,
      ~title=?,
      ~onClick=?,
      ~spin=?,
      ~style=?,
      _children,
    ) => {
  ...component,
  render: _ => {
    let spin =
      switch (spin) {
      | Some(spin) => spin
      | None => false
      };
    let classString =
      Cn.make([
        "anticon",
        className |> Cn.unwrap,
        "anticon-" ++ Antd_IconName.toString(type_),
        "anticon-spin"
        |> Cn.ifTrue(
             spin || Antd_IconName.compare(Antd_IconName.loading, type_),
           ),
      ]);
    <i className=classString ?onClick ?style ?title />;
  },
};