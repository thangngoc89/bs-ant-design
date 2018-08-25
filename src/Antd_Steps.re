[@bs.module] external reactClass : ReasonReact.reactClass = "antd/lib/steps";

[%bs.raw {|require("antd/lib/steps/style")|}];

[@bs.deriving jsConverter]
type status = [ | `wait | `process | `finish | `error];

[@bs.obj]
external makeProps :
  (~status: string=?, ~current: int=?, ~style: ReactDOMRe.Style.t=?, unit) => _ =
  "";

let make = (~status=?, ~current=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~status=?Js.Option.map((. b) => statusToJs(b), status),
        ~current?,
        ~style?,
        (),
      ),
    children,
  );

module Step = {
  [@bs.module "antd/lib/steps"]
  external reactClass : ReasonReact.reactClass = "Step";

  [@bs.obj]
  external makeProps : (~title: string, ~description: string=?, unit) => _ =
    "";
  let make = (~title, ~description=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~title, ~description?, ()),
      children,
    );
};