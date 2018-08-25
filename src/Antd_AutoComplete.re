[@bs.module]
external autoComplete: ReasonReact.reactClass = "antd/lib/auto-complete";

[%bs.raw {|require("antd/lib/auto-complete/style")|}];

[@bs.obj]
external makeProps:
  (
    ~dataSource: array(string)=?,
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
      ~dataSource=?,
      ~value=?,
      ~defaultValue=?,
      ~onChange=?,
      ~onPressEnter=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=autoComplete,
    ~props=
      makeProps(
        ~dataSource?,
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