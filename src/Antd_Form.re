[@bs.module] external reactClass : ReasonReact.reactClass = "antd/lib/form";

[%bs.raw {|require("antd/lib/form/style")|}];

[@bs.deriving jsConverter]
type formLayout = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "inline"] `Inline
  | [@bs.as "vertical"] `Vertical
];

[@bs.obj]
external makeProps :
  (
    ~layout: string=?,
    ~onSubmit: ReactEventRe.Form.t => unit=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~prefixCls: string=?,
    ~hideRequiredMark: bool=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~layout=?,
      ~onSubmit=?,
      ~style=?,
      ~className=?,
      ~prefixCls=?,
      ~hideRequiredMark=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~layout=?Js.Option.map((. b) => formLayoutToJs(b), layout),
        ~onSubmit?,
        ~style?,
        ~className?,
        ~prefixCls?,
        ~hideRequiredMark?,
        (),
      ),
    children,
  );