[@bs.module] external reactClass: ReasonReact.reactClass = "antd/lib/input";

[%bs.raw {|require("antd/lib/input/style")|}];

[@bs.deriving jsConverter]
type size = [ | `large | `default | `small];

[@bs.obj]
external makeProps:
  (
    ~prefixCls: string=?,
    ~size: string=?,
    ~onPressEnter: ReactEvent.Keyboard.t=?,
    ~addonBefore: ReasonReact.reactElement=?,
    ~addonAfter: ReasonReact.reactElement=?,
    ~prefix: ReasonReact.reactElement=?,
    ~suffix: ReasonReact.reactElement=?,
    ~value: string=?,
    ~defaultValue: string=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
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
      ~value=?,
      ~defaultValue=?,
      ~onChange=?,
      ~className=?,
      ~style=?,
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
        ~value?,
        ~defaultValue?,
        ~onChange?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );

module TextArea = {
  [@bs.module "antd/lib/input"]
  external reactClass: ReasonReact.reactClass = "TextArea";
  let make =
      (
        ~value=?,
        ~defaultValue=?,
        ~onChange=?,
        ~onPressEnter=?,
        ~onBlur=?,
        ~className=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~value?,
          ~defaultValue?,
          ~onChange?,
          ~onPressEnter?,
          ~onBlur?,
          ~className?,
          ~style?,
          (),
        ),
      children,
    );
};