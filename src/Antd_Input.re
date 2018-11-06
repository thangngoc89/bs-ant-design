[@bs.module] external input: ReasonReact.reactClass = "antd/lib/input";

[%bs.raw {|require("antd/lib/input/style")|}];

[@bs.deriving abstract]
type jsProps = {
  [@bs.optional] [@bs.as "type"] htmlType: string,
  [@bs.optional] name: string,
  [@bs.optional] value: string,
  [@bs.optional] defaultValue: string,
  [@bs.optional] onChange: ReactEvent.Form.t => unit,
  [@bs.optional] onPressEnter: ReactEvent.Keyboard.t => unit,
  [@bs.optional] onBlur: ReactEvent.Focus.t => unit,
  [@bs.optional] className: string,
  [@bs.optional] style: ReactDOMRe.Style.t,
  [@bs.optional] placeholder: string,
};

let make =
    (
      ~htmlType=?,
      ~name=?,
      ~value=?,
      ~defaultValue=?,
      ~onChange=?,
      ~onPressEnter=?,
      ~onBlur=?,
      ~className=?,
      ~style=?,
      ~placeholder=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=input,
    ~props=
      jsProps(
        ~htmlType?,
        ~name?,
        ~value?,
        ~defaultValue?,
        ~onChange?,
        ~onPressEnter?,
        ~onBlur?,
        ~className?,
        ~style?,
        ~placeholder?,
        (),
      ),
    children,
  );

module TextArea = {
  [@bs.module "antd/lib/input"]
  external reactClass: ReasonReact.reactClass = "TextArea";
  let make =
      (
        ~htmlType=?,
        ~name=?,
        ~value=?,
        ~defaultValue=?,
        ~onChange=?,
        ~onPressEnter=?,
        ~onBlur=?,
        ~className=?,
        ~style=?,
        ~placeholder=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        jsProps(
          ~htmlType?,
          ~name?,
          ~value?,
          ~defaultValue?,
          ~onChange?,
          ~onPressEnter?,
          ~onBlur?,
          ~className?,
          ~style?,
          ~placeholder?,
          (),
        ),
      children,
    );
};
