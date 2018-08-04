[@bs.module] external reactClass : ReasonReact.reactClass = "antd/lib/input";

[%bs.raw {|require("antd/lib/input/style")|}];

[@bs.deriving jsConverter]
type size = [ | `large | `default | `small];

[@bs.obj]
external makeProps :
  (
    ~prefixCls: string=?,
    ~size: string=?,
    ~onPressEnter: ReactEventRe.Keyboard.t=?,
    ~addonBefore: ReasonReact.reactElement=?,
    ~addonAfter: ReasonReact.reactElement=?,
    ~prefix: ReasonReact.reactElement=?,
    ~suffix: ReasonReact.reactElement=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~prefixCls=?,
      ~size=?,
      ~onPressEnter=?,
      ~addonBefore=?,
      ~addonAfter=?,
      ~prefix=?,
      ~suffix=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~prefixCls?,
        ~size=?Js.Option.map((. b) => sizeToJs(b), size),
        ~onPressEnter?,
        ~addonBefore?,
        ~addonAfter?,
        ~prefix?,
        ~suffix?,
        (),
      ),
    children,
  );