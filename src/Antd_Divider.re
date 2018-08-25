[@bs.module] external reactClass : ReasonReact.reactClass = "antd/lib/divider";

[%bs.raw {|require("antd/lib/divider/style")|}];

[@bs.deriving jsConverter]
type dividerType = [ | `horizontal | `vertical];

[@bs.obj]
external makeProps :
  (
    ~_type: string=?,
    ~dash: bool=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make = (~_type=?, ~dash=?, ~id=?, ~className=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~_type=?Js.Option.map((. b) => dividerTypeToJs(b), _type),
        ~dash?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );