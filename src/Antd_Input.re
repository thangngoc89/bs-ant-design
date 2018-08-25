[@bs.module] external input : ReasonReact.reactClass = "antd/lib/input";

[%bs.raw {|require("antd/lib/input/style")|}];

[@bs.obj]
external makeProps :
  (
    ~value: string=?,
    ~defaultValue: string=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~onPressEnter: ReactEvent.Keyboard.t => unit=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~value=?,
      ~defaultValue=?,
      ~onChange=?,
      ~onPressEnter=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=input,
    ~props=
      makeProps(
        ~value?,
        ~defaultValue?,
        ~onChange?,
        ~onPressEnter?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );

module TextArea = {
  [@bs.module "antd/lib/input"]
  external reactClass : ReasonReact.reactClass = "TextArea";
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