[@bs.module] external input: ReasonReact.reactClass = "antd/lib/input-number";

[%bs.raw {|require("antd/lib/input-number/style")|}];

[@bs.deriving jsConverter]
type size = [ | `small | `default | `large];

[@bs.deriving abstract]
type jsProps = {
  [@bs.optional]
  prefixCls: string,
  [@bs.optional]
  min: int,
  [@bs.optional]
  max: int,
  [@bs.optional]
  value: int,
  [@bs.optional]
  step: [ | `Int(int) | `Str(string)],
  [@bs.optional]
  defaultValue: int,
  [@bs.optional]
  tabIndex: int,
  [@bs.optional]
  onChange: Js.Null_undefined.t(int) => unit,
  [@bs.optional]
  disabled: bool,
  [@bs.optional]
  size: string,
  [@bs.optional]
  formatter: 'a => string, 
  [@bs.optional]
  parser: 'a => int, 
  [@bs.optional]
  decimalSeparator: string,
  [@bs.optional]
  placeholder: string,
  [@bs.optional]
  style: ReactDOMRe.Style.t,
  [@bs.optional]
  className: string,
  [@bs.optional]
  name: string,
  [@bs.optional]
  id: string,
  [@bs.optional]
  precision: int,
};

let make =
    (
      ~prefixCls=?,
      ~min=?,
      ~max=?,
      ~value=?,
      ~step=?,
      ~defaultValue=?,
      ~tabIndex=?,
      ~onChange=?,
      ~disabled=?,
      ~size=?,
      ~formatter=?,
      ~parser=?,
      ~decimalSeparator=?,
      ~placeholder=?,
      ~style=?,
      ~className=?,
      ~name=?,
      ~id=?,
      ~precision=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=input,
    ~props=
      jsProps(
        ~prefixCls?,
        ~min?,
        ~max?,
        ~value?,
        ~step?,
        ~defaultValue?,
        ~tabIndex?,
        ~onChange?,
        ~disabled?,
        ~size=?Js.Option.map((. b) => sizeToJs(b), size),
        ~formatter=?,
        ~parser=?,
        ~decimalSeparator?,
        ~placeholder?,
        ~style?,
        ~className?,
        ~name?,
        ~id?,
        ~precision?,
        (),
      ),
    children,
  );