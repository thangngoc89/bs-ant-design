[@bs.module] external reactClass : ReasonReact.reactClass = "antd/lib/form";

[%bs.raw {|require("antd/lib/form/style")|}];

[@bs.deriving jsConverter]
type formLayout = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "inline"] `Inline
  | [@bs.as "vertical"] `Vertical
];

module Item = {
  [@bs.module]
  external reactClass : ReasonReact.reactClass = "antd/lib/form/FormItem";

  [@bs.deriving jsConverter]
  type validateStatus = [ | `success | `warning | `error | `validating];

  /* TODO: Add labelCol and wrapperCol props */
  [@bs.obj]
  external makeProps :
    (
      ~prefixCls: string=?,
      ~className: string=?,
      ~id: string=?,
      ~label: ReasonReact.reactElement=?,
      ~help: ReasonReact.reactElement=?,
      ~extra: ReasonReact.reactElement=?,
      ~validateStatus: string=?,
      ~hasFeedback: bool=?,
      ~required: bool=?,
      ~style: ReactDOMRe.Style.t=?,
      ~colon: bool=?,
      unit
    ) =>
    _ =
    "";

  let make =
      (
        ~prefixCls=?,
        ~className=?,
        ~id=?,
        ~label=?,
        ~help=?,
        ~extra=?,
        ~validateStatus=?,
        ~hasFeedback=?,
        ~required=?,
        ~style=?,
        ~colon=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~prefixCls?,
          ~className?,
          ~id?,
          ~label?,
          ~help?,
          ~extra?,
          ~validateStatus=?
            Js.Option.map((. b) => validateStatusToJs(b), validateStatus),
          ~hasFeedback?,
          ~required?,
          ~style?,
          ~colon?,
          (),
        ),
      children,
    );
};

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